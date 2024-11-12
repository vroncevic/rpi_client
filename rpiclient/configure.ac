dnl ***************************************************************************
dnl @info   gengtkpro ver.1.0
dnl @author Vladimir Roncevic <elektron.ronca@gmail.com>
dnl @brief  Process this file with autoconf to produce a configure script.
dnl ***************************************************************************
AC_INIT(rpiclient, 1.0.0)
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([subdir-objects])
AM_SILENT_RULES([yes])
AC_PROG_CC
IT_PROG_INTLTOOL([0.51.0])

GETTEXT_PACKAGE=rpiclient
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
GLIB_GNU_GETTEXT
AM_PROG_LIBTOOL
LT_INIT

PKG_CHECK_MODULES([GTK], [gtk+-3.0])
AC_SUBST([GTK_CFLAGS])
AC_SUBST([GTK_LIBS])

PKG_CHECK_MODULES([SQLITE3], [sqlite3])
AC_SUBST([SQLITE3_CFLAGS])
AC_SUBST([SQLITE3_LIBS])

AC_CONFIG_COMMANDS_PRE([
  sed -i 's/#define USE_SETTINGS_PLAIN_CONFIG 0/#define USE_SETTINGS_PLAIN_CONFIG 1/' src/settings/rpi_client_config.h
])

AC_OUTPUT([
    Makefile
    po/Makefile.in
    src/Makefile
    rc/Makefile
])
