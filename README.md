# Informe tarea 2

## Funcionamiento y lógica del sistema de prioridades

El sistema de prioridades permite cambiar el esquema tradicional de turnos equitativos para los procesos. El kernel de xv6 utiliza las prioridades, que son valores númericos donde mientras menor sea el número, mayor es la prioridad; para determinar el orden de ejecución de dichos procesos. A la estructura de los porcesos se le agregó el campo de prioridad, el cual almacena el número de prioridad del proceso, el cual puede cambiar durante su ejecución, mediante la llamada al sistema setpriority.

También se implementó setboost que es otra llamada al sistema, la cual modifica dinámicamente la prioridad de un proceso, aumentandola si el boost es positivo o disminuyendola cuando el boost es negativo. Esto resulta importante ya que evita que los procesos de baja prioridad queden olvidados y nunca se ejecuten.

Este sistema mejora la eficiencia de la CPU, ya que permite que procesos más importantes la utilicen por más tiempo. Y gracias a las llamadas de sistema setpriority y setboost, el sistema se vuelve flexible, ya que no se decide una única vez que prioridad tiene cada proceso, sino que esto se actualiza luego de las distintas ejecuciones de procesos.

## Explicación de las modificaciones realizadas

Al igual que en tareas pasadas las modificaciones necesarias fueron en gran medida de llamar y definir a las funciones en los lugares necesarios, debían ser mencionadas en distintos archivos para que cuando el usuario las solicitara el llamado al sistema resultara correcto.

En particupar se editaron los archivos: proc.c, proc.h, syscall.c, sysproc.c, user.h, usys.pl y makefile para incluir el ejecutable de prueba. De los cuales sysproc.c y proc.c son quienes contienen la mayor parte de código de definición de las funciones, mientras que los demás archivos cumplen la tarea del llamado y definición de vía de comunicación para que resulte bien el llamado.

Para ejemplificar, fue importante la modificación del scheduler ya que, este es quien determina que proceso debe ejecutarse en cada momento, por lo que aquí fue donde se cambió la estructura para que trabaje con prioridades y no con turnos tradicionales.

## Dificultades encontradas y soluciones implementadas

Conceptualmente no fue difícil entender cual era la idea tras las modificaciones, ya que recientemente había estudiado para la prueba del curso, pero nuevamente me costó conocer y entender los archivos que debían ser modificados para lograr el llamado de las funciones, esto principalmente por ser muchos, lo cual hacía fácil olvidar alguno.

Otra dificultad fue resolver un problema que se me precentó al compilar xv6, ya que no se presentaba como un error en los códigos, sino que en lo señalado en el terminal tras ejecutar make qemu, por lo que fue intensa la revisión de lo que aparecía y la investigación en internet. Pero poco a poco mejoré la interpretación del error y en particular entendí los segmentos que se generan para así poder solucionar el inconveniente en partes.
