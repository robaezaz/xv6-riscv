# Informe tarea 4

El objetivo de la tarea fue implementar un sistema de permisos básicos en xv6. Este sistema permite definir si un archivo es solo para lectura, solo escritura, ambos o inmutable. También se incorporó una llamada al sistema para modificar los permisos de los archivos.

## Funcionamiento y lógica.

la función chmod permite modificar los permisos de un archivo, estos se aplican mediante la variable permissions que se define en la estructuro de inode del sistema de archivos.
Cuando se cambian los permisos acceso para saber si es a modo de lectura, escritura, ambos o inmutable, se verifica el valor de permissions antes de ejecutarse, así se asegura de no estar permitiendo una operación no autorizada.
Cuando un archivo queda marcado como inmutable, no se puede volver a cambiar su permiso, de esta forma se refuerza la segurodad del archivo y se evita modificaciones no deseadas.

## Explicación de las modificaciones realizadas.

Las modificaciones necesarias fueron en gran medida de llamar y definir a las funciones en los lugares necesarios, debían ser mencionadas en distintos archivos para que cuando el usuario las solicitara el llamado al sistema resultara correcto. En particupar se editaron los archivos: proc.c, proc.h, syscall.c, sysproc.c, user.h, usys.pl y makefile para incluir el ejecutable de prueba. En este caso, también fue necesario editar documentos que manejan los archivos, como file.c, file.h, fs.c y sysfile.c para la gestión de los permisos en operaciones de archivos, y cambiar la estructura de inode para incluir la variable permissions.

## Dificultades encontradas y soluciones implementadas.
