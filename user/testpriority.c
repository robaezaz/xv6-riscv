#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void)
{
    int n;
    int pid;
    for (n = 0; n < 20; n++) // Crear 20 procesos
    {
        pid = fork();
        if (pid < 0)
        {
            printf("Error al hacer fork\n");
            exit(1);
        }
        if (pid == 0)
        {
            sleep(5 * (n + 1));

            // Establecer prioridad y boost para cada proceso hijo
            setpriority(getpid(), 20 - n);           // Prioridade decreciente
            setboost(getpid(), n % 2 == 0 ? 1 : -1); // Boost alternante

            // información sobre el proceso hijo
            printf("Ejecutando proceso %d con PID %d, prioridad %d, boost %d\n",
                   n, getpid(), 20 - n, n % 2 == 0 ? 1 : -1);
            exit(0);
        }
    }
    for (n = 0; n < 20; n++)
    {
        wait(0); // Espera a que terminen los procesos hijo
    }
    exit(0);
}
