/* 
	Explanation of communication between parents and children using pipes
	More info here:
		https://youtu.be/Mqb2dVRe0uo?si=FbiGc-nsz5_TMDdW
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd[2];
    
    if (pipe(fd) == -1)
    {
		fprintf(stderr, "An error ocurred creating the pipe\n");
		return 1;
    }

	int id = fork();
	if (id == -1)
	{
		fprintf(stderr, "An error ocurred creating the process\n");
		return 2;
	}
	/* Proceso hijo */
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);

		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			fprintf(stderr, "An error ocurred with writing to the pipe\n");
			return 3;
		}
		close(fd[1]);
	}
	/* Proceso padre */
	else
	{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			fprintf(stderr, "An error ocurred with reading from the pipe\n");
			return 4;
		}
		y *= 3;
		close(fd[0]);
		printf("Got from the child process: %d\n", y);
		
	}

    return (0);
}