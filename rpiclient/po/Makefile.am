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
