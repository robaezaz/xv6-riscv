#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "sleeplock.d"
#include "file.h"
#include "fs.h"

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

// Incorporar la función sys_chmod
uint64
sys_chmod(void)
{
  char path[MAXPATH]; // ruta del archivo que se quiere modificar
  int mode;
  struct inode *ip;

  if (argstr(0, path, MAXPATH) < 0)
    return -1;

  argint(1, &mode);
  // Verificar el valor de mode, cada número tiene un significado
  if (mode < 0 || mode > 5)
    return -1;

  begin_op();
  if ((ip = namei(path)) == 0)
  {
    end_op();
    return -1; // No se encontró el archivo
  }
  ilock(ip);

  // Verifica si es inmutable
  if (ip->permissions == 5)
  {
    iunlockput(ip);
    end_op();
    return -1; // No se puede cambiar el permiso
  }

  // Actualizar los permisos del archivo
  ip->permissions = mode;
  iupdate(ip);
  iunlockput(ip); // liberar el inode
  end_op();
  return 0;
}
