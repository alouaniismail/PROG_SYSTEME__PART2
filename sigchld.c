#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number)
{
  int status;
  while(waitpid(-1,&status,WNOHANG));
  child_exit_status=status;
}

int main()
{
  struct sigaction sigchld_action;
  memset(&sigchld_action,0,sizeof(struct sigaction));
  sigchld_action.sa_handler=clean_up_child_process;
  sigaction(SIGCHLD,&sigchld_action,NULL);
  /*Faire diverses choses, entre autres créer un processus fils. */
  /* ... */
  return 0;
}
