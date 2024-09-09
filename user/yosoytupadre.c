#include "kernel/types.h"
#include "user/user.h"

/*  int main() {
     int ppid = getppid();
     printf("El PID del proceso padre es: %d\n", ppid);
     exit(0);
  };
*/

int main(int argc, char *argv[])
{

    // convertir el argumento ingresado a un número entero.
    int n = atoi(argv[1]);

    // llamar a la función getancestor con n para obtener el ID del ancestro del proceso actual.
    int pid = getancestor(n);

    // Si la función devuelve un número negativo, es porque no hay ancestro para ese nivel.
    if (pid < 0)
    {
        printf("No hay ancestro para n = %d.\n", n);
    }
    else
    {
        // Dependiendo del valor de n, se despliega un mensaje distinto.
        switch (n)
        {
        case 0:
            // Si n es 0, se muestra el ID del proceso actual.
            printf("El ID del proceso actual es %d.\n", pid);
            break;
        case 1:
            // Si n es 1, se muestra el ID del proceso padre.
            printf("El ID del proceso padre es %d.\n", pid);
            break;
        case 2:
            // Si n es 2, se muestra el ID del proceso abuelo.
            printf("El ID del proceso abuelo es %d.\n", pid);
            break;
        default:
            // Para cualquier otro valor de n, se muestra el ID del ancestro correspondiente.
            printf("El ID del ancestro %d es %d.\n", n, pid);
            break;
        }
    }

    exit(0);
};