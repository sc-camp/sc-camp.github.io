#include <stdlib.h>
#include <stdio.h>

static long num_steps=1000000000; double step, pi;

void main()
{  long int i;	
   double x, sum = 0.0;

   step = 1.0/(double) num_steps;

   #pragma omp parallel for private(x) reduction(+:sum)
   for (i=0; i< num_steps; i++){
      x = (i+0.5)*step;
      sum = sum + 4.0/(1.0 + x*x);
   }
   pi = step * sum;
   printf(" Pi= %f\n",pi);
}
