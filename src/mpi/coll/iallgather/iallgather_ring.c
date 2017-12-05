/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"

#undef FUNCNAME
#define FUNCNAME MPIR_Iallgather_ring_sched
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Iallgather_ring_sched(const void *sendbuf, int sendcount, MPI_Datatype
        sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype,
        MPIR_Comm *comm_ptr, MPIR_Sched_t s)
{
    int mpi_errno = MPI_SUCCESS;
    int rank, comm_size;
    int i, j, jnext, left, right;
    MPI_Aint recvtype_extent;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    MPIR_Datatype_get_extent_macro(recvtype, recvtype_extent);

    /* This is the largest offset we add to recvbuf */
    MPIR_Ensure_Aint_fits_in_pointer(MPIR_VOID_PTR_CAST_TO_MPI_AINT recvbuf +
                                     (comm_size * recvcount * recvtype_extent));

    /* First, load the "local" version in the recvbuf. */
    if (sendbuf != MPI_IN_PLACE) {
        mpi_errno = MPIR_Sched_copy(sendbuf, sendcount, sendtype,
                                    ((char *)recvbuf + rank*recvcount*recvtype_extent),
                                    recvcount, recvtype, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPIR_SCHED_BARRIER(s);
    }

    /* Now, send left to right.  This fills in the receive area in
     * reverse order. */
    left  = (comm_size + rank - 1) % comm_size;
    right = (rank + 1) % comm_size;

    j     = rank;
    jnext = left;
    for (i=1; i<comm_size; i++) {
        mpi_errno = MPIR_Sched_send(((char *)recvbuf + j*recvcount*recvtype_extent),
                                     recvcount, recvtype, right, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        /* concurrent, no barrier here */
        mpi_errno = MPIR_Sched_recv(((char *)recvbuf + jnext*recvcount*recvtype_extent),
                                     recvcount, recvtype, left, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPIR_SCHED_BARRIER(s);

        j = jnext;
        jnext = (comm_size + jnext - 1) % comm_size;
    }

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

