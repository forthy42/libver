/* libver header dummy */

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
