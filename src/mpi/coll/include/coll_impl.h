/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2006 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 *
 *  Portions of this code were written by Intel Corporation.
 *  Copyright (C) 2011-2017 Intel Corporation.  Intel provides this material
 *  to Argonne National Laboratory subject to Software Grant and Corporate
 *  Contributor License Agreement dated February 8, 2012.
 */

#ifndef MPIR_COLL_IMPL_H_INCLUDED
#define MPIR_COLL_IMPL_H_INCLUDED

/* Enumerate the list of algorithms */
typedef enum MPIR_Allgather_alg_intra_t {
    MPIR_ALLGATHER_ALG_INTRA_AUTO,
    MPIR_ALLGATHER_ALG_INTRA_BRUCKS,
    MPIR_ALLGATHER_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_ALLGATHER_ALG_INTRA_RING
} MPIR_Allgather_alg_intra_t;
/* Have an easy way of finding the algorithm choice later without doing string
 * comparisons */
int MPIR_Allgather_alg_intra_choice;

typedef enum MPIR_Allgather_alg_inter_t {
    MPIR_ALLGATHER_ALG_INTER_AUTO
} MPIR_Allgather_alg_inter_t;
int MPIR_Allgather_alg_inter_choice;

typedef enum MPIR_Allgatherv_alg_intra_t {
    MPIR_ALLGATHERV_ALG_INTRA_AUTO,
    MPIR_ALLGATHERV_ALG_INTRA_BRUCKS,
    MPIR_ALLGATHERV_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_ALLGATHERV_ALG_INTRA_RING
} MPIR_Allgatherv_alg_intra_t;
int MPIR_Allgatherv_alg_intra_choice;

typedef enum MPIR_Allgatherv_alg_inter_t {
    MPIR_ALLGATHERV_ALG_INTER_AUTO
} MPIR_Allgatherv_alg_inter_t;
int MPIR_Allgatherv_alg_inter_choice;

typedef enum MPIR_Allreduce_alg_intra_t {
    MPIR_ALLREDUCE_ALG_INTRA_AUTO,
    MPIR_ALLREDUCE_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_ALLREDUCE_ALG_INTRA_REDSCAT_ALLGATHER
} MPIR_Allreduce_alg_intra_t;
int MPIR_Allreduce_alg_intra_choice;

typedef enum MPIR_Allreduce_alg_inter_t {
    MPIR_ALLREDUCE_ALG_INTER_AUTO
} MPIR_Allreduce_alg_inter_t;
int MPIR_Allreduce_alg_inter_choice;

typedef enum MPIR_Alltoall_alg_intra_t {
    MPIR_ALLTOALL_ALG_INTRA_AUTO,
    MPIR_ALLTOALL_ALG_INTRA_BRUCKS,
    MPIR_ALLTOALL_ALG_INTRA_PAIRWISE,
    MPIR_ALLTOALL_ALG_INTRA_PAIRWISE_SENDRECV_REPLACE,
    MPIR_ALLTOALL_ALG_INTRA_SCATTERED
} MPIR_Alltoall_alg_intra_t;
int MPIR_Alltoall_alg_intra_choice;

typedef enum MPIR_Alltoall_alg_inter_t {
    MPIR_ALLTOALL_ALG_INTER_AUTO
} MPIR_Alltoall_alg_inter_t;
int MPIR_Alltoall_alg_inter_choice;

typedef enum MPIR_Alltoallv_alg_intra_t {
    MPIR_ALLTOALLV_ALG_INTRA_AUTO,
    MPIR_ALLTOALLV_ALG_INTRA_PAIRWISE_SENDRECV_REPLACE,
    MPIR_ALLTOALLV_ALG_INTRA_SCATTERED
} MPIR_Alltoallv_alg_intra_t;
int MPIR_Alltoallv_alg_intra_choice;

typedef enum MPIR_Alltoallv_alg_inter_t {
    MPIR_ALLTOALLV_ALG_INTER_AUTO
} MPIR_Alltoallv_alg_inter_t;
int MPIR_Alltoallv_alg_inter_choice;

typedef enum MPIR_Alltoallw_alg_intra_t {
    MPIR_ALLTOALLW_ALG_INTRA_AUTO,
    MPIR_ALLTOALLW_ALG_INTRA_PAIRWISE_SENDRECV_REPLACE,
    MPIR_ALLTOALLW_ALG_INTRA_SCATTERED
} MPIR_Alltoallw_alg_intra_t;
int MPIR_Alltoallw_alg_intra_choice;

typedef enum MPIR_Alltoallw_alg_inter_t {
    MPIR_ALLTOALLW_ALG_INTER_AUTO
} MPIR_Alltoallw_alg_inter_t;
int MPIR_Alltoallw_alg_inter_choice;

typedef enum MPIR_Barrier_alg_intra_t {
    MPIR_BARRIER_ALG_INTRA_AUTO,
    MPIR_BARRIER_ALG_INTRA_RECURSIVE_DOUBLING
} MPIR_Barrier_alg_intra_t;
int MPIR_Barrier_alg_intra_choice;

typedef enum MPIR_Barrier_alg_inter_t {
    MPIR_BARRIER_ALG_INTER_AUTO
} MPIR_Barrier_alg_inter_t;
int MPIR_Barrier_alg_inter_choice;

typedef enum MPIR_Bcast_alg_intra_t {
    MPIR_BCAST_ALG_INTRA_AUTO,
    MPIR_BCAST_ALG_INTRA_BINOMIAL,
    MPIR_BCAST_ALG_INTRA_SCATTER_DOUBLING_ALLGATHER,
    MPIR_BCAST_ALG_INTRA_SCATTER_RING_ALLGATHER
} MPIR_Bcast_alg_intra_t;
int MPIR_Bcast_alg_intra_choice;

typedef enum MPIR_Bcast_alg_inter_t {
    MPIR_BCAST_ALG_INTER_AUTO
} MPIR_Bcast_alg_inter_t;
int MPIR_Bcast_alg_inter_choice;

typedef enum MPIR_Gather_alg_intra_t {
    MPIR_GATHER_ALG_INTRA_AUTO,
    MPIR_GATHER_ALG_INTRA_BINOMIAL
} MPIR_Gather_alg_intra_t;
int MPIR_Gather_alg_intra_choice;

typedef enum MPIR_Gather_alg_inter_t {
    MPIR_GATHER_ALG_INTER_AUTO
} MPIR_Gather_alg_inter_t;
int MPIR_Gather_alg_inter_choice;

typedef enum MPIR_Iallgather_alg_intra_t {
    MPIR_IALLGATHER_ALG_INTRA_AUTO,
    MPIR_IALLGATHER_ALG_INTRA_BRUCKS,
    MPIR_IALLGATHER_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_IALLGATHER_ALG_INTRA_RING
} MPIR_Iallgather_alg_intra_t;
int MPIR_Iallgather_alg_intra_choice;

typedef enum MPIR_Iallgather_alg_inter_t {
    MPIR_IALLGATHER_ALG_INTER_AUTO
} MPIR_Iallgather_alg_inter_t;
int MPIR_Iallgather_alg_inter_choice;

typedef enum MPIR_Iallgatherv_alg_intra_t {
    MPIR_IALLGATHERV_ALG_INTRA_AUTO,
    MPIR_IALLGATHERV_ALG_INTRA_BRUCKS,
    MPIR_IALLGATHERV_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_IALLGATHERV_ALG_INTRA_RING
} MPIR_Iallgatherv_alg_intra_t;
int MPIR_Iallgatherv_alg_intra_choice;

typedef enum MPIR_Iallgatherv_alg_inter_t {
    MPIR_IALLGATHERV_ALG_INTER_AUTO
} MPIR_Iallgatherv_alg_inter_t;
int MPIR_Iallgatherv_alg_inter_choice;

typedef enum MPIR_Iallreduce_alg_intra_t {
    MPIR_IALLREDUCE_ALG_INTRA_AUTO,
    MPIR_IALLREDUCE_ALG_INTRA_NAIVE,
    MPIR_IALLREDUCE_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_IALLREDUCE_ALG_INTRA_REDSCAT_ALLGATHER
} MPIR_Iallreduce_alg_intra_t;
int MPIR_Iallreduce_alg_intra_choice;

typedef enum MPIR_Iallreduce_alg_inter_t {
    MPIR_Iallreduce_ALG_INTER_AUTO
} MPIR_Iallreduce_alg_inter_t;
int MPIR_Iallreduce_alg_inter_choice;

typedef enum MPIR_Ialltoall_alg_intra_t {
    MPIR_IALLTOALL_ALG_INTRA_AUTO,
    MPIR_IALLTOALL_ALG_INTRA_BRUCKS,
    MPIR_IALLTOALL_ALG_INTRA_INPLACE,
    MPIR_IALLTOALL_ALG_INTRA_PAIRWISE,
    MPIR_IALLTOALL_ALG_INTRA_PERM_SR
} MPIR_Ialltoall_alg_intra_t;
int MPIR_Ialltoall_alg_intra_choice;

typedef enum MPIR_Ialltoall_alg_inter_t {
    MPIR_IALLTOALL_ALG_INTER_AUTO
} MPIR_Ialltoall_alg_inter_t;
int MPIR_Ialltoall_alg_inter_choice;

typedef enum MPIR_Ialltoallv_alg_intra_t {
    MPIR_IALLTOALLV_ALG_INTRA_AUTO,
    MPIR_IALLTOALLV_ALG_INTRA_BLOCKED,
    MPIR_IALLTOALLV_ALG_INTRA_INPLACE
} MPIR_Ialltoallv_alg_intra_t;
int MPIR_Ialltoallv_alg_intra_choice;

typedef enum MPIR_Ialltoallv_alg_inter_t {
    MPIR_IALLTOALLV_ALG_INTER_AUTO,
    MPIR_IALLTOALLV_ALG_PAIRWISE_XCHG
} MPIR_Ialltoallv_alg_inter_t;
int MPIR_Ialltoallv_alg_inter_choice;

typedef enum MPIR_Ialltoallw_alg_intra_t {
    MPIR_IALLTOALLW_ALG_INTRA_AUTO,
    MPIR_IALLTOALLW_ALG_INTRA_BLOCKED,
    MPIR_IALLTOALLW_ALG_INTRA_INPLACE
} MPIR_Ialltoallw_alg_intra_t;
int MPIR_Ialltoallw_alg_intra_choice;

typedef enum MPIR_Ialltoallw_alg_inter_t {
    MPIR_IALLTOALLW_ALG_INTER_AUTO,
    MPIR_IALLTOALLW_ALG_PAIRWISE_XCHG
} MPIR_Ialltoallw_alg_inter_t;
int MPIR_Ialltoallw_alg_inter_choice;

typedef enum MPIR_Ibarrier_alg_intra_t {
    MPIR_IBARRIER_ALG_INTRA_AUTO,
    MPIR_IBARRIER_ALG_INTRA_RECURSIVE_DOUBLIING
} MPIR_Ibarrier_alg_intra_t;
int MPIR_Ibarrier_alg_intra_choice;

typedef enum MPIR_Ibarrier_alg_inter_t {
    MPIR_IBARRIER_ALG_INTER_AUTO,
    MPIR_IBARRIER_ALG_BCAST
} MPIR_Ibarrier_alg_inter_t;
int MPIR_Ibarrier_alg_inter_choice;

typedef enum MPIR_Ibcast_alg_intra_t {
    MPIR_IBCAST_ALG_INTRA_AUTO,
    MPIR_IBCAST_ALG_INTRA_BINOMIAL
} MPIR_Ibcast_alg_intra_t;
int MPIR_Ibcast_alg_intra_choice;

typedef enum MPIR_Ibcast_alg_inter_t {
    MPIR_IBCAST_ALG_INTER_AUTO,
    MPIR_IBCAST_ALG_FLAT
} MPIR_Ibcast_alg_inter_t;
int MPIR_Ibcast_alg_inter_choice;

typedef enum MPIR_Igather_alg_intra_t {
    MPIR_IGATHER_ALG_INTRA_AUTO,
    MPIR_IGATHER_ALG_INTRA_BINOMIAL
} MPIR_Igather_alg_intra_t;
int MPIR_Igather_alg_intra_choice;

typedef enum MPIR_Igather_alg_inter_t {
    MPIR_IGATHER_ALG_INTER_AUTO,
    MPIR_IGATHER_ALG_LONG_INTER,
    MPIR_IGATHER_ALG_SHORT_INTER
} MPIR_Igather_alg_inter_t;
int MPIR_Igather_alg_inter_choice;

typedef enum MPIR_Ireduce_scatter_alg_intra_t {
    MPIR_IREDUCE_SCATTER_ALG_INTRA_AUTO,
    MPIR_IREDUCE_SCATTER_ALG_INTRA_NONCOMM,
    MPIR_IREDUCE_SCATTER_ALG_INTRA_PAIRWISE,
    MPIR_IREDUCE_SCATTER_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_IREDUCE_SCATTER_ALG_INTRA_RECURSIVE_HALVING
} MPIR_Ireduce_scatter_alg_intra_t;
int MPIR_Ireduce_scatter_alg_intra_choice;

typedef enum MPIR_Ireduce_scatter_alg_inter_t {
    MPIR_IREDUCE_SCATTER_ALG_INTER_AUTO,
    MPIR_IREDUCE_SCATTER_ALG_DEFAULT_INTER
} MPIR_Ireduce_scatter_alg_inter_t;
int MPIR_Ireduce_scatter_alg_inter_choice;

typedef enum MPIR_Ireduce_scatter_block_alg_intra_t {
    MPIR_IREDUCE_SCATTER_BLOCK_ALG_INTRA_AUTO,
    MPIR_IREDUCE_SCATTER_BLOCK_ALG_INTRA_NONCOMM,
    MPIR_IREDUCE_SCATTER_BLOCK_ALG_INTRA_PAIRWISE,
    MPIR_IREDUCE_SCATTER_BLOCK_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_IREDUCE_SCATTER_BLOCK_ALG_INTRA_RECURSIVE_HALVING
} MPIR_Ireduce_scatter_block_alg_intra_t;
int MPIR_Ireduce_scatter_block_alg_intra_choice;

typedef enum MPIR_Ireduce_scatter_block_alg_inter_t {
    MPIR_IREDUCE_SCATTER_BLOCK_ALG_INTER_AUTO,
    MPIR_IREDUCE_SCATTER_BLOCK_ALG_DEFAULT_INTER
} MPIR_Ireduce_scatter_block_alg_inter_t;
int MPIR_Ireduce_scatter_block_alg_inter_choice;

typedef enum MPIR_Ireduce_alg_intra_t {
    MPIR_IREDUCE_ALG_INTRA_AUTO,
    MPIR_IREDUCE_ALG_INTRA_BINOMIAL,
    MPIR_IREDUCE_ALG_INTRA_REDSCAT_GATHER
} MPIR_Ireduce_alg_intra_t;
int MPIR_Ireduce_alg_intra_choice;

typedef enum MPIR_Ireduce_alg_inter_t {
    MPIR_IREDUCE_ALG_INTER_AUTO
} MPIR_Ireduce_alg_inter_t;
int MPIR_Ireduce_alg_inter_choice;

typedef enum MPIR_Iscatter_alg_intra_t {
    MPIR_ISCATTER_ALG_INTRA_AUTO,
    MPIR_ISCATTER_ALG_INTRA_BINOMIAL
} MPIR_Iscatter_alg_intra_t;
int MPIR_Iscatter_alg_intra_choice;

typedef enum MPIR_Iscatter_alg_inter_t {
    MPIR_ISCATTER_ALG_INTER_AUTO
} MPIR_Iscatter_alg_inter_t;
int MPIR_Iscatter_alg_inter_choice;

typedef enum MPIR_Reduce_scatter_alg_intra_t {
    MPIR_REDUCE_SCATTER_ALG_INTRA_AUTO,
    MPIR_REDUCE_SCATTER_ALG_INTRA_NONCOMM,
    MPIR_REDUCE_SCATTER_ALG_INTRA_PAIRWISE,
    MPIR_REDUCE_SCATTER_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_REDUCE_SCATTER_ALG_INTRA_RECURSIVE_HALVING
} MPIR_Reduce_scatter_alg_intra_t;
int MPIR_Reduce_scatter_alg_intra_choice;

typedef enum MPIR_Reduce_scatter_alg_inter_t {
    MPIR_REDUCE_SCATTER_ALG_INTER_AUTO
} MPIR_Reduce_scatter_alg_inter_t;
int MPIR_Reduce_scatter_alg_inter_choice;

typedef enum MPIR_Reduce_scatter_block_alg_intra_t {
    MPIR_REDUCE_SCATTER_BLOCK_ALG_INTRA_AUTO,
    MPIR_REDUCE_SCATTER_BLOCK_ALG_INTRA_NONCOMM,
    MPIR_REDUCE_SCATTER_BLOCK_ALG_INTRA_PAIRWISE,
    MPIR_REDUCE_SCATTER_BLOCK_ALG_INTRA_RECURSIVE_DOUBLING,
    MPIR_REDUCE_SCATTER_BLOCK_ALG_INTRA_RECURSIVE_HALVING
} MPIR_Reduce_scatter_block_alg_intra_t;
int MPIR_Reduce_scatter_block_alg_intra_choice;

typedef enum MPIR_Reduce_scatter_block_alg_inter_t {
    MPIR_REDUCE_SCATTER_BLOCK_ALG_INTER_AUTO
} MPIR_Reduce_scatter_block_alg_inter_t;
int MPIR_Reduce_scatter_block_alg_inter_choice;

typedef enum MPIR_Reduce_alg_intra_t {
    MPIR_REDUCE_ALG_INTRA_AUTO,
    MPIR_REDUCE_ALG_INTRA_BINOMIAL,
    MPIR_REDUCE_ALG_INTRA_REDSCAT_GATHER
} MPIR_Reduce_alg_intra_t;
int MPIR_Reduce_alg_intra_choice;

typedef enum MPIR_Reduce_alg_inter_t {
    MPIR_REDUCE_ALG_INTER_AUTO
} MPIR_Reduce_alg_inter_t;
int MPIR_Reduce_alg_inter_choice;

typedef enum MPIR_Scatter_alg_intra_t {
    MPIR_SCATTER_ALG_INTRA_AUTO,
    MPIR_SCATTER_ALG_INTRA_BINOMIAL
} MPIR_Scatter_alg_intra_t;
int MPIR_Scatter_alg_intra_choice;

typedef enum MPIR_Scatter_alg_inter_t {
    MPIR_SCATTER_ALG_INTER_AUTO
} MPIR_Scatter_alg_inter_t;
int MPIR_Scatter_alg_inter_choice;

int MPIR_COLL_init(void);

#endif /* MPIR_COLL_IMPL_H_INCLUDED */
