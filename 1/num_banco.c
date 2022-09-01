/*Escrever um programa que cria duas threads, uma que deposita um valor num banco (conta) e outra que retira um valor desse mesmo banco (conta).
Observe que deve ser criada somente uma thread para depósito e outra para saque. Além disso, ambas compartilham a variável global ‘saldo’, que deve ser
inicializada com o valor 1000. A cada saque ou depósito, uma unidade deve ser incrementada ou decrementada da variável saldo. Ao final do main, escreva
o valor do saldo*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int SALDO = 1000;

void *Deposito(void *arg)
{
   SALDO++;
   printf("Saldo updated: %ld\n", SALDO);
   pthread_exit(NULL);
}

void *Saque(void *arg)
{
   SALDO--;
   printf("Saldo updated: %ld\n", SALDO);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[2];
  /* Manual Saque/Deposito */
  pthread_create(&threads[0], NULL, Deposito, NULL);
  pthread_create(&threads[1], NULL, Saque, NULL);

  pthread_create(&threads[1], NULL, Saque, NULL);
  pthread_create(&threads[1], NULL, Saque, NULL);
  pthread_create(&threads[1], NULL, Saque, NULL);

  pthread_create(&threads[0], NULL, Deposito, NULL);
  pthread_create(&threads[0], NULL, Deposito, NULL);

  pthread_create(&threads[0], NULL, Deposito, NULL);
  pthread_create(&threads[1], NULL, Saque, NULL);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  printf("Total SALDO %ld!\n", SALDO);

  pthread_exit(NULL);
}
