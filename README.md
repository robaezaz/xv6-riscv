# Informe tarea 4

El objetivo de la tarea fue implementar un sistema de permisos básicos en xv6. Este sistema permite definir si un archivo es solo para lectura, solo escritura, ambos o inmutable. También se incorporó una llamada al sistema para modificar los permisos de los archivos.

## Funcionamiento y lógica.

la función chmod permite modificar los permisos de un archivo, estos se aplican mediante la variable permissions que se define en la estructuro de inode del sistema de archivos.

Cuando se cambian los permisos acceso para saber si es a modo de lectura, escritura, ambos o inmutable, se verifica el valor de permissions antes de ejecutarse, así se asegura de no estar permitiendo una operación no autorizada.

Cuando un archivo queda marcado como inmutable, no se puede volver a cambiar su permiso, de esta forma se refuerza la segurodad del archivo y se evita modificaciones no deseadas. La implementación de la función chmod y el sistema básico le añade más control al manejo de archivos.

## Explicación de las modificaciones realizadas.

Las modificaciones necesarias fueron en gran medida de llamar y definir a las funciones en los lugares necesarios, debían ser mencionadas en distintos archivos para que cuando el usuario las solicitara el llamado al sistema resultara correcto. En particupar se editaron los archivos: proc.c, proc.h, syscall.c, sysproc.c, user.h, usys.pl y makefile para incluir el ejecutable de prueba. En este caso, también fue necesario editar documentos que manejan los archivos, como file.c, file.h, fs.c y sysfile.c para la gestión de los permisos en operaciones de archivos, y cambiar la estructura de inode para incluir la variable permissions.
También fue necesario crear un programa de prueba para poder comprobar el correcto funcionamiento de los cambios de permiso y seguir lo solicitado en el enunciado de la tarea.

## Dificultades encontradas y soluciones implementadas.

Como ya ha sido recurrente en otras tareas, una de las pincipales dificultades es la compreción de los documentos a modificar, en su mayoría estos archivos se repiten y eso lo hace más sencillo de entender a esta altura del semestre, pero un pequeño error en un archivo puede repercutir en el funcionamiento de otros y puede ser difícil de identifcar. Otra dificultad, que va de mano con la anterior, fue el trabajo en los documentos nuevos, con los cuales no había revisado previamente.
