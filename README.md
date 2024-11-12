# Informe tarea 3

El objetivo de la tarea fue implementar un sistema de protección de memoria en el kernel XV6. A través de las funciones mprotect y munprotect, se introdujo un mecanismo para proteger ciertas áreas de la memoria, asegurando que no escriba en secciones de memoria no autorizadas. De esta forma la seguridad del sistema operativo mejora, ya que controla los accesos a la memoria, evitando fallos causados por accesos ilegales o manipulaciones indebidas de la memoria.

## Funcionamiento y lógica de la protección de memoria

La función mprotect se implemento particularmente para poder marcar áreas específicos de la memoria, como solo de lectura, y así impedir que los proceoss escriban sobre estas áreas. Esto lo hace modificando la tabla de páginas del kernel. Cuando se intenta acceder a un área protegida el sistema genera una exepción que luego detalla el error. En el caso de que un proceso intente escribir en alguna página no habilitada para ello, el proceso termina su ejecución.

Mientras que la función munproduct revierte lo realizado por la función anterior, esta vuelve a habilitar espacios que anteriormente estaban protegidos, y los regresa a su estado de lectura/escritura.

## Explicación de las modificaciones realizadas

Las modificaciones necesarias fueron en gran medida de llamar y definir a las funciones en los lugares necesarios, debían ser mencionadas en distintos archivos para que cuando el usuario las solicitara el llamado al sistema resultara correcto. En particupar se editaron los archivos: proc.c, proc.h, syscall.c, sysproc.c, user.h, usys.pl y makefile para incluir el ejecutable de prueba. Es primera tarea donde también se debió modificar trap.c para el manejo de las excepciones, con los detalles e interpretación en palabras del intento de escritura en espacios portegidos. Adicionalmente al programa de prueba que se creo para evaluar el funcionamiento de los cambios realizados, también se creo un documento fs.img que resultó útil para la ejecución del programa.

## Dificultades encontradas y soluciones implementadas

Como ya ha sido recurrente en otras tareas, una de las pincipales dificultades es la compreción de los documentos a modificar, en general esto se repiten y eso lo hace más sencillo de entender, pero un pequeño error en un archivo puede repercutir en el funcionamiento de otros y puede ser difícil de identifcar. Otra dificultad, que va de la mano con la anterior, fue el trabajo en el documento trap.c que era un espacio núevo de trabajo, que no había revisado previamente. Además de aquello, me costó entender que el programa estaba duncionando bien pero no se entendía claramente por la salida en el terminal que estrebaja, por lo que tuve que investigar para poder hacer la interpretación adecuada y así modificar la manera en que se exponía.
