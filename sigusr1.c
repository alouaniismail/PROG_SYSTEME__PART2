#include<signal.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

sig_atomic_t sigusr1_count=0;

void handler(int signal_number)
{
  ++sigusr1_count;
}

int main()
{
  struct sigaction sa;
  memset(&sa,0,sizeof(sa));
  sa.sa_handler=handler;
  sigaction(SIGUSR1,&sa,NULL);
  /*Faire quelque chose de long ici. */
  /* ... */
  printf("SIGUSR1 a été reçu %d fois\n",sigusr1_count);
  return 0;
}
