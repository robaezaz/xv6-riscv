#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

int main()
{
    char *start_addr = sbrk(0); // Obtener la dirección inicial del heap

    sbrk(4096); // Reservar una página de memoria con tamaño de página de 4096 bytes

    // Proteger la nueva página como solo lectura
    if (mprotect(start_addr, 1) == -1)
    {
        printf("Error al aplicar mprotect\n");
    }

    // Intentar escribir en la página protegida
    char *mem_ptr = start_addr;

    // Intentar escribir en la página protegida
    // Esto debería fallar si la protección es exitosa
    *mem_ptr = 'B'; // Esto debería lanzar un error de protección de memoria

    // Si llegamos a este punto, significa que la escritura no fue bloqueada, lo que es incorrecto
    printf("Escritura permitida, lo que no debería ocurrir.\n");

    return 0;
}
