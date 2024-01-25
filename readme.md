EXPLICACION DEL DESAROLLO DEL PROYECTO

- ESPECIFICACIONES:
    - Tu programa deberá ser ejecutado así:
        ./pipex file1 cmd1 cmd2 file2
            file1 & file2 son ficheros
            cmd1 & cmd2 son comandos de shell con sus agumentos

    - Tendrá que hacer exactamente lo mismo que el siguiente comando shell
        $> < file1 cmd1 | cmd2 > file2
            Echemos un ojo a esto en detalle con el ejemplo "< infile grep ejemplo | wc -w > outfile"
            - "infile":
                contiene "Hola esto es un ejemplo"
            - "<":
                Es un simbolo de "redireccion de entrada"
                Redirige el contenido del fichero a la entrada estandar para que cuando grep esté leyendo de la entrada estandar, tome el contenido del fichero infile
            
            - "|":
                La | (tuberia) redirige la salida del comando de la izquierda a la entrada del comando a la derecha.
                En ese caso, el simbolo | redirige la salida del comando grep a la entrada del comando wc
                Sin la tubería, la salida del comando grep se escribe directamente en la salida estandar.
                    "Hola esto es un ejemplo" // Nos devuelve la linea por salida estandar donde ha encontrado "ejemplo"
                Cuando introducimos el pipe (< infile grep ejemplo | wc -w) obtenemos:
                    5 //Que son las palabras que cuenta con el comando "wc -c"

            - ">":
                Es un simbolo de "redireccion de salida"
                Redirige el contenido del resultado del comando wc (tras el pipe) al fichero outfile
                
    - Tu programa no deberá dar leaks de memoria !

- OBJETIVO:
    - Desarrollar un programa que simule las tuberias en el shell

- FUNCIONES QUE UTILIZAREMOS
    - acces(): Acceder a ficheros y comprobar permisos
    - dup2(): Crear un nuevo fd asociado a un archivo ya existente
    - pipe(): Crea una tuberia para la comunicacion entre procesos
    - fork(): Crea un nuevo proceso duplicando el llamante
    - waitpid(): Espera hasta que el proceso especificado haya terminado
    - wait(): Espera hasta que algun proceso hijo haya terminado
    - execve(): Ejecuta un programa en un nuevo proceso
    - unlink(): Elimina un enlace a un archivo existente.

- ALGORITMO:
    1. Parsear:
        La entrada debe ser correcta. 5 argumenos con sus correspondientes permisos

    2. Generar la tuberia

    3. Una vez tenemos la tuberia con sus dos fds como extremos, creamos los procesos

    4. El proceso hijo ejecutará el primer comando
        - Entrada: infile
            - Redirigimos la entrada estandar al infile
            - Redirigimos la salida estandar a la entrada de la tuberia
            - Cerramos la salida de la tubería
            - Ejecutamos el primer comando
            - Cerramos el descriptor de infile porque no lo usaremos más
            - Cerrar el extremo de escritura del hijo
            - Salir después de ejecutar executeCmd
            - Eliminamos enlaces a archivos(?)
        - Salida: end[1] (tuberia)

    5. El proceso padre ejecutará el segundo comando
        - Entrada: end[0] (tuberia)
            - Esperamos a que el proceso hijo termine
            - Redirigimos la salida estandar al outfile
            - Redirigimos la entrada estandar a la salida de la tuberia
            - Cerramos la entrada de la tuberia
            - Ejecutamos el segundo comando
        - Salida: outfile

    6. Ejecutamos la funcion para ejecutar los comandos
        - Definimos la ruta al programa a ejecutar
        - Argumentos del programa (el último elemento debe ser NULL)
        - Ejecutamos

    7. Liberamos memoria y liberamos enlaces para evitar leaks 