# GTK TCP/IP RPI Client

<img align="right" src="https://raw.githubusercontent.com/vroncevic/rpi_client_gtk/dev/docs/rpi_client_gtk_logo.png" width="25%">

**rpi_client_gtk** is application for controlling RPI node.

Developed in **[C](https://en.wikipedia.org/wiki/C_(programming_language))** code.

The README is used to introduce the modules and provide instructions on
how to install the modules, any machine dependencies it may have and any
other information that should be provided before the modules are installed.

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [Installation](#installation)
    - [Autogeneration](#autogeneration)
    - [Compile](#compile)
    - [Install](#install)
- [Dependencies](#dependencies)
- [Docs](#docs)
- [Contributing](#contributing)
- [Copyright and Licence](#copyright-and-licence)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

[![GitHub issues open](https://img.shields.io/github/issues/vroncevic/rpi_client_gtk.svg)](https://github.com/vroncevic/rpi_client_gtk/issues) [![GitHub contributors](https://img.shields.io/github/contributors/vroncevic/rpi_client_gtk.svg)](https://github.com/vroncevic/rpi_client_gtk/graphs/contributors)

### Installation

![Debian Linux OS](https://raw.githubusercontent.com/vroncevic/rpi_client_gtk/master/docs/debtux.png)

To install this App type the following:

#### Autogeneration

```bash
./autogen.sh
```

output

```
**Warning**: I am going to run `configure' with no arguments.
If you wish to pass any to it, please specify them on the
`./autogen.sh' command line.

processing .
Running intltoolize...
Running libtoolize...
libtoolize: putting auxiliary files in '.'.
libtoolize: copying file './ltmain.sh'
libtoolize: putting macros in AC_CONFIG_MACRO_DIRS, 'm4'.
libtoolize: copying file 'm4/libtool.m4'
libtoolize: copying file 'm4/ltoptions.m4'
libtoolize: copying file 'm4/ltsugar.m4'
libtoolize: copying file 'm4/ltversion.m4'
libtoolize: copying file 'm4/lt~obsolete.m4'
libtoolize: Consider adding '-I m4' to ACLOCAL_AMFLAGS in Makefile.am.
Running aclocal  ...
Running autoheader...
Running automake --gnu  ...
configure.ac:11: installing './compile'
configure.ac:18: installing './config.guess'
configure.ac:18: installing './config.sub'
configure.ac:9: installing './install-sh'
configure.ac:9: installing './missing'
src/Makefile.am: installing './depcomp'
Running autoconf ...
configure.ac:17: warning: The macro `GLIB_GNU_GETTEXT' is obsolete.
configure.ac:17: You should run autoupdate.
aclocal.m4:388: GLIB_GNU_GETTEXT is expanded from...
configure.ac:17: the top level
configure.ac:17: warning: The macro `AC_TRY_LINK' is obsolete.
configure.ac:17: You should run autoupdate.
./lib/autoconf/general.m4:2920: AC_TRY_LINK is expanded from...
lib/m4sugar/m4sh.m4:692: _AS_IF_ELSE is expanded from...
lib/m4sugar/m4sh.m4:699: AS_IF is expanded from...
./lib/autoconf/general.m4:2249: AC_CACHE_VAL is expanded from...
./lib/autoconf/general.m4:2270: AC_CACHE_CHECK is expanded from...
aclocal.m4:73: GLIB_LC_MESSAGES is expanded from...
aclocal.m4:388: GLIB_GNU_GETTEXT is expanded from...
configure.ac:17: the top level
configure.ac:17: warning: The macro `AC_TRY_LINK' is obsolete.
configure.ac:17: You should run autoupdate.
./lib/autoconf/general.m4:2920: AC_TRY_LINK is expanded from...
lib/m4sugar/m4sh.m4:692: _AS_IF_ELSE is expanded from...
lib/m4sugar/m4sh.m4:699: AS_IF is expanded from...
./lib/autoconf/general.m4:2249: AC_CACHE_VAL is expanded from...
./lib/autoconf/general.m4:2270: AC_CACHE_CHECK is expanded from...
lib/m4sugar/m4sh.m4:699: AS_IF is expanded from...
./lib/autoconf/headers.m4:89: _AC_CHECK_HEADER_COMPILE is expanded from...
./lib/autoconf/headers.m4:56: AC_CHECK_HEADER is expanded from...
aclocal.m4:172: GLIB_WITH_NLS is expanded from...
aclocal.m4:388: GLIB_GNU_GETTEXT is expanded from...
configure.ac:17: the top level
configure.ac:17: warning: The macro `AC_TRY_LINK' is obsolete.
configure.ac:17: You should run autoupdate.
./lib/autoconf/general.m4:2920: AC_TRY_LINK is expanded from...
lib/m4sugar/m4sh.m4:699: AS_IF is expanded from...
./lib/autoconf/headers.m4:89: _AC_CHECK_HEADER_COMPILE is expanded from...
./lib/autoconf/headers.m4:56: AC_CHECK_HEADER is expanded from...
aclocal.m4:172: GLIB_WITH_NLS is expanded from...
aclocal.m4:388: GLIB_GNU_GETTEXT is expanded from...
configure.ac:17: the top level
configure.ac:17: warning: The macro `AC_OUTPUT_COMMANDS' is obsolete.
configure.ac:17: You should run autoupdate.
./lib/autoconf/status.m4:1025: AC_OUTPUT_COMMANDS is expanded from...
aclocal.m4:172: GLIB_WITH_NLS is expanded from...
aclocal.m4:388: GLIB_GNU_GETTEXT is expanded from...
configure.ac:17: the top level
configure.ac:18: warning: The macro `AM_PROG_LIBTOOL' is obsolete.
configure.ac:18: You should run autoupdate.
m4/libtool.m4:101: AM_PROG_LIBTOOL is expanded from...
configure.ac:18: the top level
configure.ac:33: warning: AC_OUTPUT should be used without arguments.
configure.ac:33: You should run autoupdate.
Running ./configure ...
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for a race-free mkdir -p... /usr/bin/mkdir -p
checking for gawk... gawk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking whether make supports nested variables... (cached) yes
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether the compiler supports GNU C... yes
checking whether gcc accepts -g... yes
checking for gcc option to enable C11 features... none needed
checking whether gcc understands -c and -o together... yes
checking whether make supports the include directive... yes (GNU style)
checking dependency style of gcc... gcc3
checking whether NLS is requested... yes
checking for intltool >= 0.51.0... 0.51.0 found
checking for intltool-update... /usr/bin/intltool-update
checking for intltool-merge... /usr/bin/intltool-merge
checking for intltool-extract... /usr/bin/intltool-extract
checking for xgettext... /usr/bin/xgettext
checking for msgmerge... /usr/bin/msgmerge
checking for msgfmt... /usr/bin/msgfmt
checking for gmsgfmt... /usr/bin/msgfmt
checking for perl... /usr/bin/perl
checking for perl >= 5.8.1... 5.38.2
checking for XML::Parser... ok
checking for stdio.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for strings.h... yes
checking for sys/stat.h... yes
checking for sys/types.h... yes
checking for unistd.h... yes
checking for locale.h... yes
checking for LC_MESSAGES... yes
checking for CFPreferencesCopyAppValue... no
checking for CFLocaleCopyCurrent... no
checking for libintl.h... yes
checking for ngettext in libc... yes
checking for dgettext in libc... yes
checking for bind_textdomain_codeset... yes
checking for msgfmt... (cached) /usr/bin/msgfmt
checking for dcgettext... yes
checking if msgfmt accepts -c... yes
checking for gmsgfmt... (cached) /usr/bin/msgfmt
checking for xgettext... (cached) /usr/bin/xgettext
checking build system type... x86_64-pc-linux-gnu
checking host system type... x86_64-pc-linux-gnu
checking how to print strings... printf
checking for a sed that does not truncate output... /usr/bin/sed
checking for grep that handles long lines and -e... /usr/bin/grep
checking for egrep... /usr/bin/grep -E
checking for fgrep... /usr/bin/grep -F
checking for ld used by gcc... /usr/bin/ld
checking if the linker (/usr/bin/ld) is GNU ld... yes
checking for BSD- or MS-compatible name lister (nm)... /usr/bin/nm -B
checking the name lister (/usr/bin/nm -B) interface... BSD nm
checking whether ln -s works... yes
checking the maximum length of command line arguments... 1572864
checking how to convert x86_64-pc-linux-gnu file names to x86_64-pc-linux-gnu format... func_convert_file_noop
checking how to convert x86_64-pc-linux-gnu file names to toolchain format... func_convert_file_noop
checking for /usr/bin/ld option to reload object files... -r
checking for file... file
checking for objdump... objdump
checking how to recognize dependent libraries... pass_all
checking for dlltool... no
checking how to associate runtime and link libraries... printf %s\n
checking for ar... ar
checking for archiver @FILE support... @
checking for strip... strip
checking for ranlib... ranlib
checking command to parse /usr/bin/nm -B output from gcc object... ok
checking for sysroot... no
checking for a working dd... /usr/bin/dd
checking how to truncate binary pipes... /usr/bin/dd bs=4096 count=1
checking for mt... mt
checking if mt is a manifest tool... no
checking for dlfcn.h... yes
checking for objdir... .libs
checking if gcc supports -fno-rtti -fno-exceptions... no
checking for gcc option to produce PIC... -fPIC -DPIC
checking if gcc PIC flag -fPIC -DPIC works... yes
checking if gcc static flag -static works... yes
checking if gcc supports -c -o file.o... yes
checking if gcc supports -c -o file.o... (cached) yes
checking whether the gcc linker (/usr/bin/ld -m elf_x86_64) supports shared libraries... yes
checking whether -lc should be explicitly linked in... no
checking dynamic linker characteristics... GNU/Linux ld.so
checking how to hardcode library paths into programs... immediate
checking whether stripping libraries is possible... yes
checking if libtool supports shared libraries... yes
checking whether to build shared libraries... yes
checking whether to build static libraries... yes
checking for pkg-config... /usr/bin/pkg-config
checking pkg-config is at least version 0.9.0... yes
checking for gtk+-3.0... yes
checking for sqlite3... yes
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: creating po/Makefile.in
config.status: creating src/Makefile
config.status: creating rc/Makefile
config.status: creating config.h
config.status: executing depfiles commands
config.status: executing default-1 commands
config.status: executing libtool commands
config.status: executing po/stamp-it commands
Now type `make' to compile.
```

#### Compile

```bash
make
```

output

```
make  all-recursive
make[1]: Entering directory '/home/jenkins/Downloads/rpiclient'
Making all in src
make[2]: Entering directory '/home/jenkins/Downloads/rpiclient/src'
  CC       main.o
  CC       home/rpi_home.o
  CC       home/rpi_home_frame.o
  CC       home/rpi_menu.o
  CC       home/rpi_channel_status.o
  CC       home/rpi_channel_control.o
  CC       about/rpi_about_dialog.o
  CC       format/rpi_format.o
  CC       exit/rpi_exit_dialog.o
  CC       help/rpi_help_window.o
  CC       help/rpi_image_slider.o
  CC       info/rpi_info_dialog.o
  CC       resource/rpi_cpixbuf.o
  CC       resource/rpi_get_resource_dir.o
  CC       resource/rpi_get_resource_file_path.o
  CC       resource/rpi_get_config_dir.o
  CC       resource/rpi_get_config_file_path.o
  CC       settings/rpi_settings_network_window.o
  CC       settings/rpi_settings_general_window.o
  CC       settings/rpi_settings_config.o
  CC       settings/rpi_settings_user.o
  CC       settings/rpi_settings_plain.o
  CC       settings/rpi_settings_sqlite.o
  CC       warning/rpi_warning_dialog.o
  CC       widgets/rpi_vertical_bar.o
  CCLD     rpiclient
make[2]: Leaving directory '/home/jenkins/Downloads/rpiclient/src'
Making all in po
make[2]: Entering directory '/home/jenkins/Downloads/rpiclient/po'
make[2]: Nothing to be done for 'all'.
make[2]: Leaving directory '/home/jenkins/Downloads/rpiclient/po'
Making all in rc
make[2]: Entering directory '/home/jenkins/Downloads/rpiclient/rc'
make[2]: Nothing to be done for 'all'.
make[2]: Leaving directory '/home/jenkins/Downloads/rpiclient/rc'
make[2]: Entering directory '/home/jenkins/Downloads/rpiclient'
make[2]: Leaving directory '/home/jenkins/Downloads/rpiclient'
make[1]: Leaving directory '/home/jenkins/Downloads/rpiclient'
```

#### Install

```bash
sudo make install  
```

output

```
Making install in src
make[1]: Entering directory '/home/jenkins/Downloads/rpiclient/src'
make[2]: Entering directory '/home/jenkins/Downloads/rpiclient/src'
 /usr/bin/mkdir -p '/usr/local/bin'
  /bin/bash ../libtool   --mode=install /usr/bin/install -c rpiclient '/usr/local/bin'
libtool: install: /usr/bin/install -c rpiclient /usr/local/bin/rpiclient
make  install-exec-hook
make[3]: Entering directory '/home/jenkins/Downloads/rpiclient/src'
Installing binary to /usr/local/bin
make[3]: Leaving directory '/home/jenkins/Downloads/rpiclient/src'
make[2]: Nothing to be done for 'install-data-am'.
make[2]: Leaving directory '/home/jenkins/Downloads/rpiclient/src'
make[1]: Leaving directory '/home/jenkins/Downloads/rpiclient/src'
Making install in po
make[1]: Entering directory '/home/jenkins/Downloads/rpiclient/po'
linguas=""; \
for lang in $linguas; do \
  dir=/usr/local/share/locale/$lang/LC_MESSAGES; \
  /bin/bash /home/jenkins/Downloads/rpiclient/install-sh -d $dir; \
  if test -r $lang.gmo; then \
    /usr/bin/install -c -m 644 $lang.gmo $dir/rpiclient.mo; \
    echo "installing $lang.gmo as $dir/rpiclient.mo"; \
  else \
    /usr/bin/install -c -m 644 ./$lang.gmo $dir/rpiclient.mo; \
    echo "installing ./$lang.gmo as" \
	 "$dir/rpiclient.mo"; \
  fi; \
  if test -r $lang.gmo.m; then \
    /usr/bin/install -c -m 644 $lang.gmo.m $dir/rpiclient.mo.m; \
    echo "installing $lang.gmo.m as $dir/rpiclient.mo.m"; \
  else \
    if test -r ./$lang.gmo.m ; then \
      /usr/bin/install -c -m 644 ./$lang.gmo.m \
	$dir/rpiclient.mo.m; \
      echo "installing ./$lang.gmo.m as" \
	   "$dir/rpiclient.mo.m"; \
    else \
      true; \
    fi; \
  fi; \
done
make[1]: Leaving directory '/home/jenkins/Downloads/rpiclient/po'
Making install in rc
make[1]: Entering directory '/home/jenkins/Downloads/rpiclient/rc'
make[2]: Entering directory '/home/jenkins/Downloads/rpiclient/rc'
make  install-exec-hook
make[3]: Entering directory '/home/jenkins/Downloads/rpiclient/rc'
Installing system-wide images to /usr/local/share/rpiclient/images
make[3]: Leaving directory '/home/jenkins/Downloads/rpiclient/rc'
 /usr/bin/mkdir -p '/usr/local/share/rpiclient/images'
 /usr/bin/install -c -m 644 images/1.png images/2.png images/3.png images/4.png images/5.png images/blanko.png images/icon.png images/logo.png '/usr/local/share/rpiclient/images'
 /usr/bin/mkdir -p '/usr/local/share/rpiclient/images'
 /usr/bin/install -c -m 644 images/1.png images/2.png images/3.png images/4.png images/5.png images/blanko.png images/icon.png images/logo.png '/usr/local/share/rpiclient/images'
make[2]: Leaving directory '/home/jenkins/Downloads/rpiclient/rc'
make[1]: Leaving directory '/home/jenkins/Downloads/rpiclient/rc'
make[1]: Entering directory '/home/jenkins/Downloads/rpiclient'
make[2]: Entering directory '/home/jenkins/Downloads/rpiclient'
make[2]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/local/share/doc/rpiclient'
 /usr/bin/install -c -m 644 README COPYING AUTHORS ChangeLog INSTALL NEWS '/usr/local/share/doc/rpiclient'
make[2]: Leaving directory '/home/jenkins/Downloads/rpiclient'
make[1]: Leaving directory '/home/jenkins/Downloads/rpiclient'
```

### Dependencies

This module requires these other modules and libraries

* [gtk+ - docs.gtk.org/gtk3](https://docs.gtk.org/gtk3/)
* [sqlite - www.sqlite.org](https://www.sqlite.org/)

### Docs

[![Documentation Status](https://readthedocs.org/projects/rpi-client-gtk/badge/?version=master)](https://rpi-client-gtk.readthedocs.io/?badge=master)

More documentation and info at

* [rpi-client-gtk.readthedocs.io](https://rpi-client-gtk.readthedocs.io/)
* [gtk+ - docs.gtk.org/gtk3](https://docs.gtk.org/gtk3/)
* [sqlite - www.sqlite.org](https://www.sqlite.org/)

### Contributing

[Contributing to rpi_client_gtk](CONTRIBUTING.md)

### Copyright and Licence

Copyright (C) 2016 - 2025 by https://github.com/vroncevic/rpi_client_gtk

**rpiclient** is free software; you can redistribute it and/or modify it.

Lets help and support Raspberry PI && GNOME.

<p align="center">
  <a href="https://www.raspberrypi.org/donate/">
    <img src="https://raw.githubusercontent.com/vroncevic/rpi-client-gtk/master/docs/fondations.png" alt="GNOME&&RPi" width="381" height="221">
  </a>
</p>
