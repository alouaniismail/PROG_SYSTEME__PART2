all: allocation print_pid creation_fail fork_exec sigusr1 fork_exec2 zombie sigchld

clean:
	rm -f Makefile~ *.o *.c~ a.out allocation print_pid creation_fail fork_exec sigusr1 fork_exec2 zombie sigchld

allocation: allocation.c
	gcc -o $@ $<
	./$@
print_pid: print_pid.c
	gcc -o $@ $<
	./$@
creation_fail: creation_fail.c
	gcc -o $@ $<
	./$@
fork_exec: fork_exec.c
	gcc -o $@ $<
	./$@
sigusr1: sigusr1.c
	gcc -o $@ $^
	./$@
fork_exec2: fork_exec2.c
	gcc -o $@ $^
	./$@
zombie: zombie.c
	gcc -o $@ $^
	./$@
sigchld: sigchld.c
	gcc -o $@ $^
	./$@ #ne donne rien ; c'est normal.
