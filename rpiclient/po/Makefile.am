##
## @info   gengtkpro ver.1.0
## @author Vladimir Roncevic <elektron.ronca@gmail.com>
## @brief  Process this file with automake to produce Makefile.in
##

# Defines the text domain for translations
DOMAIN = rpiclient

# Using locale codes supports en language
LINGUAS = en

# Package for which translations are generated and loaded
GETTEXT_PACKAGE = $(DOMAIN)

# List of files which are included in source distribution
DISTFILES = \
	ChangeLog \
	LINGUAS \
	POTFILES.in \
	$(LINGUAS:=.po)

# Includes macros required by gettext
include $(top_srcdir)/gettext.m4
