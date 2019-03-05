/* test of libver system */

#ifndef VER_MAJ
#define VER_MAJ 2
#endif
#ifndef VER_MIN
#if VER_MAJ > 1
#define VER_MIN 3
#else
#define VER_MIN 1
#endif
#endif

#include "libver.h"

int main(char**argv, int argc)
{
  libver();
#if VER_MAJ > 0
  libver1();
  libver10();
#if VER_MIN > 0
  libver11();
#endif
#endif
#if VER_MAJ > 1
  libver2();
  libver20();
#if VER_MIN > 2
  libver23();
#endif
#endif
  return 0;
}
