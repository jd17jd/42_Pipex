#include <stdio.h>
#include <unistd.h>
 
int main()
{
	if (unlink("example.txt") == 0)
		printf("File successfully deleted");
	else
		printf("Error deleting file");
 
	return (0);
}