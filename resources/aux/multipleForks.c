/* 
	Explanation of processes parents and children
	More info here:
		https://youtu.be/94URLRsjqMQ?si=_f6mOSJSbjcUXrPt
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main (int argc, char*argv[])
{
	/*
	Nunca hacer esto porque en lugar de crear 4 procesos creamos 2^10 procesos
	
	for (int i = 0; i < 10; i++) {
		fork();
	}
	
	*/

	//Con esto creamos 4 procesos
	int id1 = fork();
	int id2 = fork();

	if (id1 == 0)
	{
		if (id2 == 0)
		{
			pid_t pidY = getpid();
			pid_t pidParentY = getppid();
			printf("We are process y\n");
			printf("Our process id is %d\n", (int) pidY);
			printf("Our parent procces id is %d\n", (int) pidParentY);
		}
		else 
		{
			pid_t pidX = getpid();
			pid_t pidParentX = getppid();
			printf("We are process x\n");
			printf("Our process id is %d\n", (int) pidX);
			printf("Our parent procces id is %d\n", (int) pidParentX);
		}
	}
	else
	{
		if (id2 == 0)
		{
			pid_t pidZ = getpid();
			pid_t pidParentZ = getppid();
			printf("We are process z\n");
			printf("Our process id is %d\n", (int) pidZ);
			printf("Our parent procces id is %d\n", (int) pidParentZ);
		}
		else
		{
			pid_t pidMain = getpid();
			pid_t pidParentMain = getppid();
			printf("We are the parent process (Main)\n");
			printf("Our process id is %d\n", (int) pidMain);
			printf("Our parent procces id is %d\n", (int) pidParentMain);
		}
	}

	/* Espera a que todos los procesos hijos acaben */
	while (wait(NULL) != -1 || errno != ECHILD)
	{
		printf("Waited for a child to finish\n");
	}
	
	return (0);
}