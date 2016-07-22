#include <iostream> 
#include <mpi.h> 
#include <unistd.h> 
 
int main(int argc, char* argv[]) { 
  MPI_Init(&argc, &argv); 
  int rank, size, reduce = 0; 
  char hostname[256]; 
  gethostname(hostname, 256); 
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
  MPI_Comm_size(MPI_COMM_WORLD, &size); 
  std::cout << "Hi, I'm host " << hostname << " and my rank is " << rank << std::endl; 
 
  MPI_Allreduce(&rank, &reduce, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD); 
  std::cout << "Rank " << rank << " received " << reduce << std::endl; 
 
  MPI_Finalize(); 
}
