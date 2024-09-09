#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0; // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if (n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (killed(myproc()))
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// creación funciones getppid y getancestor
uint64
sys_getppid(void)
{
  struct proc *p = myproc();
  return p->parent->pid;
}

uint64
sys_getancestor(void)
{
  int n = 0;
  // obtiene el valor de n desde la llamada al sistema
  argint(0, &n);

  // proceso actual
  struct proc *p = myproc();

  // si no hay proceso actual, devolver -1 como error
  if (p == 0)
  {
    return -1;
  }

  // Verifica el valor de n para determinar el ancestro que se está solicitando
  switch (n)
  {
  case 0:
    // Si n es 0, devuelve el ID del proceso actual
    return p->pid;
  case 1:
    // Si n es 1, devolver el ID del proceso padre
    if (p->parent)
      return p->parent->pid;
    else
      // Si no hay padre, retorna -1, para indicar que no se encontró el ancestro
      return -1;
  case 2:
    // Si n es 2, devolver el ID del proceso abuelo
    if (p->parent && p->parent->parent)
      return p->parent->parent->pid;
    else
      // Si no hay abuelo, retorna -1.
      return -1;
  default:
    // Para cualquier otro valor de n, retorna -1 ya que no hay tantos ancestros
    return -1;
  }
}
