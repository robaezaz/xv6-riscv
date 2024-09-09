#include "syscall.h"

int getancestor(int n)
{
    // envía la solicitud al kemel para obtener el ancestro n
    return syscall(SYS_getancestor, n);
}