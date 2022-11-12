#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

/*
Cree un processus fils executant un nouveau programme.
PROGRAM est le nom du programme a executer, le programme est recherche
dans le path. ARG_LIST est une liste terminee par NULL de chaines
de caracteres a passer au programme comme liste d'arguments. Renvoie id
du processus nouvellement cree.
*/

int swapn(char* program, char** arg_list){
  pid_t child_pid;
  child_pid=fork();
  /*Duplique ce processus.*/
  if(child_pid!=0)
    return child_pid;
  /*Nous sommes dans le processus parent.*/
  else{
    /*Execute PROGRAM en le recherchant dans le path.*/
    execvp(program, arg_list);
    /*On ne sort de la fonction execvp(ou execve(variante)) uniquement si
une erreur survient(ça copie pas tous les signaux mais seulement
ceux bloquant le père et les handlers*/
    fprintf(stderr,"une erreur est survenue au sein de execvp variante de execve\n");
    abort();
  }
}

int main(){
  char* arg_list[]={"ls",/*argv[0], le nom du programme.*/
		    "-l",
		    "/",
		    NULL/*La liste d'arguments soit se terminer par NULL*/
  };
  /*Liste d'arguments à passer à la commande "ls".*/
  swapn("ls",arg_list);
  /*Crée un nouveau processus fils exécutant la commande "ls". Ignore l'id
    du processus fils renvoyé.*/
  printf("Fin du programme principal\n");
  return 0;
}
