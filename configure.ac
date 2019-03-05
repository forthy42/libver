## ExampleLib Example: an example of using Automake to link with a library

AC_INIT([libver], [2.3], [bernd@net2o.de], [libver dummy library],
        [https://github.com/forthy42/libver])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.16 -Wall no-define])
AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CC
AM_PROG_AR
LT_INIT
AC_CHECK_PROGS(GNU_LIBTOOL,"glibtool --tag=CC" libtool)
AC_SUBST(LIBTOOL)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
