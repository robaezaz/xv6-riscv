# Informe de Instalación de xv6

## Pasos Seguidos para Instalar xv6

Seguí los pasos descritos en el enunciado de la tarea, por lo tanto el paso uno fue clonar el repositorio xv6-riscv y crear una nueva rama con mi nombre "mariabaeza".
Luego verificar tener instalado o descargar las dependencias necesarias para mi sistema operativo macOS: Homebrew y qemu riscv-gnu-toolchain. Realizado esto seguía compilar el xv6 para luego ejecutarlo, esto fue posible corriendo 'make' para la compilación y luego 'make qemu' para la ejecución.
Por último quedaba realizar la prueba de que xv6 se estuviera ejecutando correctamente en qemu.

## Problemas ocurridos en el proceso

La primera dificultad que se me presentó fue identificar que depedencias se necesitaban para el correcto desarrollo de la tarea, para esto consulte a algunas compañeras e investigue en internet para encontar los pasos necesarios para la intalación de xv6 en mac.

Luego no tuve ningún problema con la compilación de xv6 pero si con la ejecución, ya que no corría correctamente, para esto verifiqué haber instalado qemu, cosa que si fue así pero no tenía bien llamado el PATH por lo que tuve que agregarle una PATH adicional al que viene luego de la instalación. Esto lo hice a través de nano ~/.zshrc que desplegó la información necesaria y donde aguregué el PATH especifico que hacía referencia a Homebrew. De este modo se logró llamar bien a qemu para correr 'make qemu' y ejecutar xv6.

Posterior a aquello no tuve más problemas, solo la dificultad de estar realizando algo nuevo, por lo que era dificil identificar si estaba correcto o no.
