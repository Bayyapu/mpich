
# mpi_sources includes only the routines that are MPI function entry points
# The code for the MPI operations (e.g., MPI_SUM) is not included in 
# mpi_sources
mpi_sources +=                     		\
	src/mpi/coll/allreduce/allreduce.c

mpi_core_sources +=											\
	src/mpi/coll/allreduce/allreduce_nb.c	\
	src/mpi/coll/allreduce/allreduce_intra_recursive_doubling.c	\
	src/mpi/coll/allreduce/allreduce_intra_reduce_scatter_allgather.c	\
	src/mpi/coll/allreduce/allreduce_intra_smp.c	\
	src/mpi/coll/allreduce/allreduce_inter_generic.c

