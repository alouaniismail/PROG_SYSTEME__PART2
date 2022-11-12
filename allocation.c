#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int t[10];


void zones(){
  int s=0;
  void* p=malloc(10);
  printf("Code:%p, Data:%p, Heap:%p;%p, Stack: %p\n",zones,t,sbrk(0),p,&s);
  return;
}

int main(void){
  zones();
  return EXIT_SUCCESS;
}
  
