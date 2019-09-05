dnl
dnl @info   gengtkpro ver.1.0
dnl @author Vladimir Roncevic <elektron.ronca@gmail.com>
dnl @brief  Process this file with autoconf to produce a configure script.
dnl
AC_INIT(rpiclient, 0.1)
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.11])
AM_SILENT_RULES([yes])
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX

dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])
GETTEXT_PACKAGE=rpiclient
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
AM_GLIB_GNU_GETTEXT
LT_INIT
PKG_CHECK_MODULES(RPICLIENT, [gtk+-2.0 ])
GTK_DOC_CHECK([1.0])
AC_OUTPUT([
Makefile
src/Makefile
po/Makefile.in])


