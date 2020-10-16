#include <mpi.h>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

int i;
int nodo,numnodos;
int tam=32;
int pedazo=0;
int inicio=0;
int final=0;

int main(int argc,char **argv)
{ MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&nodo);
  MPI_Comm_size(MPI_COMM_WORLD,&numnodos);

  MPI_Bcast(&tam, 1, MPI_INT, 0, MPI_COMM_WORLD);

// Esta cuenta la hace cada uno
//
  pedazo=tam/numnodos;
  inicio=nodo * pedazo;
  final=inicio + pedazo;
    

  printf(" Soy el nodo %d y voy a trabajar desde %d hasta %d \n",nodo,inicio,final);

#pragma omp parallel for
 for (i=inicio;i<final;i++)
      { printf(" Hilo %d, nodo %d y proceso i=%d\n",omp_get_thread_num(),nodo,i);  
      }


//printf(" Soy el hilo %d de %d hilos dentro del procesador %d de %d procesadores\n",omp_get_thread_num(),omp_get_num_threads(),nodo,numnodos);

  MPI_Finalize();
}


