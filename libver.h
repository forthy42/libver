/* libver header dummy */

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

extern void libver();
#if VER_MAJ > 0
extern void libver1();
extern void libver10();
#if VER_MIN > 0
extern void libver11();
#endif
#endif

#if VER_MAJ > 1
extern void libver2();
extern void libver20();
#if VER_MIN > 2
extern void libver23();
#endif
#endif
