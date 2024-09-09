# Informe tarea 1

## Funcionamiento de las llamadas al sistema

Se definieron las funciones getppid y getancestor, ambas funciones entregan los ID de algún ancestro en particular. En el caso del getppid entrega el ID del proceso padre, mientras que getancestor es una función que te entrega el ID del ancestro solicitado por el usuario, ya que realiza el llamado de la función con el nivel del ancestro en particular. Por lo tanto, getancestor responde a la solicitud de getppid pero se necesita mayor información entregada por parte del usuario.

## Explicación de las modificaciones realizadas

Las modificaciones necesarias fueron en gran medida de llamar y definir a las funciones en los lugares necesarios, debían ser mencionadas en distintos archivos para que cuando el usuario las solicitara el llamado al sistema resultara correcto.
En particupar se editaron los archivos: proc.c, proc.h, syscall.c, sysproc.c, user.h, usys.pl y makefile para incluir el ejecutable de prueba. De los cuales sysproc.c y proc.c son quienes contienen la mayor parte de código de definición de las funciones, mientras que los demás archivos cumplen la tarea del llamado y definición de vía de comunicación para que resulte bien el llamado.

También se creo el programa user.c y yosoytupadre.c para verificar el funcionamiento de los programas.

## Dificultades encontradas y cómo se resolvieron

La mayor dificultad de esta tarea fue conocer y entender todos los archivos que debían ser modificados para lograr el llamado de las funciones, al contar con multiples carpetas y varios archivos en su interior era necesario ir viendo uno a uno, junto con verificar que otros archivos se llamaban dentro del mismo, y el chequeo de documentación.

Otra dificultad fue el trabajo con Git, ya que aunque lo he utilizado en distintas ocaciones el trabajo con varias ramas se me complicó un poco, debido a que trabaje desde la carpeta guardada en el computador, pero luego no pude encontrarla para subirla desde GitHub Desktop. Para resolver este problema tuve que hacer un commit de prueba para luego agregar los cambios realizados para esta tarea. Aunque no comprendí en su totalidad como se me generó ese enredo, logré solucionarlo para terminar la tarea a tiempo y lo mejor posible.
