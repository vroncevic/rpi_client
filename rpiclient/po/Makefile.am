##
## @info   gengtkpro ver.1.0
## @author Vladimir Roncevic <elektron.ronca@gmail.com>
## @brief  Process this file with automake to produce Makefile.in
##

# GNU gettext setup
SUBDIRS = .

# Language files
DOMAIN = rpiclient
LINGUAS = en
GETTEXT_PACKAGE = $(DOMAIN)

# Define `DISTFILES` to distribute .po files
DISTFILES = \
    ChangeLog \
    LINGUAS \
    POTFILES.in \
    $(LINGUAS:=.po)

# Include gettext macros
include $(top_srcdir)/gettext.m4
