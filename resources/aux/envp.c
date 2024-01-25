#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[], char *envp[]) {
    int i = 0;
    char *env_variable = envp[0];
    while (env_variable != NULL)
    {
        printf("%s\n", env_variable);
        i++;
        env_variable = envp[i];
    }
    
    return 0;
}