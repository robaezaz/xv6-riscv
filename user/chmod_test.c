#include "../kernel/fs.h"
#include "../kernel/fcntl.h"
#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

int main()
{
    // Crear un archivo con permido de escritura y lectura
    int fd = open("testfile", O_CREATE | O_RDWR);
    if (fd < 0)
    {
        printf("Error creando archivo\n");
        exit(1);
    }
    write(fd, "Prueba", 6);
    close(fd);

    // Cambiar el permiso a solo lectura =1
    if (chmod("testfile", 1) < 0)
    {
        printf("Error cambiando a solo lectura\n");
        exit(1);
    }

    // Intentar escribir, cuando el archivo es solo lectura
    fd = open("testfile", O_WRONLY);
    if (fd >= 0)
    {
        printf("Error: debería fallar al abrir en modo escritura\n");
        close(fd);
    }

    // Cambiar el permiso a inmutable
    if (chmod("testfile", 5) < 0)
    {
        printf("Error cambiando a inmutable\n");
        exit(1);
    }

    // Intentar cambiar los permisos del archivo inmutable
    if (chmod("testfile", 3) == 0)
    {
        printf("Error: debería fallar al cambiar permisos de inmutable\n");
    }

    printf("Pruebas completadas\n");
    exit(0);
}