Symbol versioning with multiple .so files
=========================================

The current way to deal with symbol versioning in glibc works fine when
programs link to old glibcs, and someone replaces the glibc with a newer one.
It however breaks the program when someone links to a newer glibc, ships the
binary and it then doesn't work anymore.

Requirements
------------

1. We can't avoid introducing ABI changes that are not compatible with old
   libraries. That's only a minority of the changes, like new functions
   (e.g. getentropy()), or changes in structs (e.g. expanding some field from
   2 to 4 bytes, because it turned out that 2 bytes are not enough). Most of
   glibc's functions will stay the same ABI for a long time.
2. Sometimes we need to be careful with bug fixes, because it has been shown
   that programs depend on bugs (e.g. memcpy).  The biggest obstacle here is
   if half of your old programs will break when you fix the bug, and the other
   half break, when you push them to trigger the bug, and you might need
   workarounds using e.g. LD_PRELOAD for programs which you can't recompile.
3. We developers want to build against the newest library (yes, we do!).
4. We want to make sure distributions, even long-term stable ones, can install
   the newest ABI, at least from a third party repository, without disturbing
   the system.
5. We want to be able to build for old libraries without jumping through
   hoops.  Note that everything, including the build system itself, depends on
   glibc, so when you create a chroot jail with the old glibc, you also need a
   build system that has been compiled for that old glibc, other libraries you
   depend upon that are compiled for that old glibc, etc..  That's why
   building in a VM or container is the way to go now.
6. We don't want multiple copies of glibc mapped into memory (only one per
   ABI).
7. It should be easy enough so that other libraries can use the same approach,
   because they do have those requirements, too.

What we have: Linker scripts and symbol versions.  Symbol versions work well
one way, but not the other way.

Suggestion
----------

What I would suggest: Have separate .so files for each version of the api.
Use a linker script that lists all of those .so files in order to link to them
(with a GROUP statement); the linker will go through the .so files one by one,
search for the symbol, and link when it finds one, and stop when there are no
unresolved references left.  Installing new ABIs alongside the current ones is
easy, just install the .so file with the new ABI. All the old ABI is still
there, not touched, and the programs using the old ABI only link to those;
they don't link to the new file.  When I ship a binary compiled to glibc-2.29,
I just ship a libc-part-2.29.so, which *only* contains the 2.29 version
ABIs. All the other ABIs are in other files, these files don't get updates (or
if they do, it does not change the ABI), and nobody has to worry about
incompatible changes.

When I want to compile for an older glibc, to avoid shipping that addition, I
can just use a different linker script.  It would be helpful to provide easy
ways to access the corresponding header files and linker scripts, without
resorting to -nostdinc and -nostdlib.  Some switch like `--glibc-abi=2.29`
that knows how to select the right linker script and set macros so that the
correct ABI is chosen in the header files would be nice, and not difficult to
do.  Other libraries can ship linker scripts with versions and have a default
symlink without version for the same purpose, so `-lxx3.5` will link to
library version 3.5, or `-lxx3` to the most recent 3.x, or `-lxx` to the most
recent, and you can use `-DXX_VERSION=3.5` to get the header files to select
the correct stuff for that version.

The GCC of a LTS distribution would not use the newest version by default (the
symlink of the unversioned linker script still points to the same version),
but could be made to use it, once it is installed side-by-side with the
default system version of glibc.
