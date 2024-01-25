#include "ft_pipex.h"

char *find(char *cmd, char *paths[]) {
    int i;
    char *res;
    char *almostPath;
    char *accessable;

    i = 0;
    res = 0;
    while(paths[i] != NULL) {
        almostPath = ft_strjoin(paths[i], "/");
        // printf("%s\n", almostPath);
        accessable = ft_strjoin(almostPath, cmd);
        // printf("%s\n", accessable);
        free(almostPath);
        if (access(accessable, F_OK | X_OK) == 0)
            return(accessable);
		free(accessable);
        i++;
    }
    return (res);
}

char    *getPath(char *cmd, char *envp[]) {
    int i;
    char *res;
    char **envp_divided;
    char **envp_right;

    i = 0;
    while (envp[i] != NULL && i != -1) {
        envp_divided = ft_split(envp[i], '=');
        i++;
        if (ft_strncmp(envp_divided[0], "PATH", 4) == 0) { 
            envp_right = ft_split(envp_divided[1], ':');
            i = -1;
        }
        //free_split(envp_divided);
    }
    res = find(cmd, envp_right);
    //free_split(envp_right);
    return (res);
}

int main(int argc, char *argv[], char *envp[]) {
    printf("%s\n", getPath("ls", envp));
    return (0);
}