#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 100000

long count = 0;

void *increment()
{
   count+=1;
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  long maxThread = NUM_THREADS;
  for(t=0;t< NUM_THREADS;t++){
    rc = pthread_create(&threads[t], NULL, increment, NULL);
    if (rc){
      maxThread = t;
      break;
      }
    }
    for(t=0;t< maxThread;t++){
    pthread_join(threads[t], NULL);
    }
  printf("threads created: %ld\n", count);

  pthread_exit(NULL);
}
