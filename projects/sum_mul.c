#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long sum = 0;
long mul = 1;


void *SumIterator(void *arg)
{
   long n;
   n = (long)arg;
   long iterator;
   for( iterator = 0;iterator <= n;iterator++){
    sum+=iterator;
    // printf("Iterator sum %ld!\n", sum);

   }
   pthread_exit(NULL);
}

void *MulIterator(void *arg)
{
   long m;
   m = (long)arg;
   long iterator;
   for( iterator = 1;iterator <= m;iterator++){
    mul*=iterator;
    // printf("Iterator mul %ld!\n", mul);

   }
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[2];
  int rc;
  long t;
  long n = 5;
  long m = 6;

  pthread_create(&threads[0], NULL, SumIterator, (void *)n);
  pthread_create(&threads[1], NULL, MulIterator, (void *)m);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  printf("Total sum %ld!\n", sum);
  printf("Total mul %ld!\n", mul);

  pthread_exit(NULL);
}
