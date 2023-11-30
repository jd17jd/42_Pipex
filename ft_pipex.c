/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:10:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/11/30 20:39:40 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/*

1. Parsear
La entrada debe ser correcta. Necesitamos manejar datos inesperados.
Debemos abrir "infile" y "outfile" y si es necesario, salir del programa.

2. Main
Tiene que tener una pinta como esta:
main()
{
	ft_init_pipex()
	ft_check_args()
	ft_parse_cmds()
	ft_parse_args()
	while (cmds)
		ft_exec()
	ft_cleanup()
}


3. ft_init_pipex
Se usa para llenar su estructura con algunos datos predeterminados
ya que probablemente checkaras las propiedades de tu struct in tu funcion cleanup()

4. ft_check_args

4. ft_check_args
Opens all files needed and handles here_doc as well as /dev/urandom.

* It's recommended having two functions to parse and store the commands:
one: will find the correct path using envp and store it in an array,
the other: will contain the arguments to the program.
This will help to build the required arguments for execve()

5.1. ft_parse_cmds will create an array like this:
["/bin/cat", "/usr/bin/head", "/usr/bin/wc"], and
5.2.  ft_parse_args will use ft_split to yield a 2D array like this one:
[["cat"], ["head", "-n", "5"], ["wc", "-l"]] (remember to NULL terminate your arrays!).

Really recomended using a struct and storing all the data within it

6. The execution: The core idea of this program is to mimic the data flow between programs.
Running the below scripts in your terminal should output the same data
(you need to use double quotes for commands with arguments):

7. ft_exec()
ft_exec()
{
	pipe()
	fork()
	if (child)
	{
		dup2()
		execve()
	}
	else
	{
		close()
	}
}

After creating the pipe and creating the child process,
the child runs the command and redirects the stdout
from the command into the write end of the pipe using dup2(2).

The parent then ‘catches’ the output from the read end of the pipe,
and outputs it back to the stdin. This is the main mechanism behind
the relationship between parent and child process.


*/

// ft_init_pipex()

/* <infile ls -l | wc -l >outfile */
/* infile "ls -l" "wc -l" outfile */

/* <infile grep a1 | wc -w >outfile */
/* infile "grep a1" "wc -w" outfile */


/**
 * Checkear si los argumentos son correctos
 * @return 0 en caso de que no haya ningun error, otro numero en caso contrario
*/
int ft_check_args(int argc, char *argumentos[]) {

    //Num de argumentos
    if (argc != 5) {
        perror("Error. Numero introducido incorrecto de parámetros\n");
        return 1;
    }

    //Ficheros de lectura y escritura
    if (access(argumentos[1], F_OK | R_OK) == -1 && (access(argumentos[4], F_OK | W_OK) == -1)) {
        perror("Error. Tanto el primer fichero como el segundo no existe o no tiene accesos de lectura\n");
        return 2;
    }
    
    if (access(argumentos[1], F_OK | R_OK) == -1) {
        perror("Error. El primer fichero no existe o no tiene accesos de lectura\n");
        return 3;
    }
    if (access(argumentos[4], F_OK | W_OK) == -1) {
        perror("Error. El segundo fichero no existe o no tiene accesos de escritura\n");
        return 4;
    }

    //Comandos para ejecutar
    char *segundo_arg = argumentos[2];
    char *tercero_arg = argumentos[3];

    execve(argumentos[1], args, env);
    
    
    return (0);
}

int main(int argc, char *argv[])
{
    
    // ft_init_pipex();
	ft_check_args(argc, argv);
	// ft_parse_cmds();
	// ft_parse_args();
	// while (cmds)
	// 	ft_exec();
	// ft_cleanup();
    return (0);
}
