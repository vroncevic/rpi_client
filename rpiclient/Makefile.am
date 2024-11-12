##
## @info   gengtkpro ver.1.0
## @author Vladimir Roncevic <elektron.ronca@gmail.com>
## @brief  Process this file with automake to produce Makefile.in
##

# Sub dirs with sources and media
SUBDIRS = src po rc

# Documentation files
dist_doc_DATA = \
	README \
	COPYING \
	AUTHORS \
	ChangeLog \
	INSTALL \
	NEWS

# Files related to managing internationalization and translations
INTLTOOL_FILES = \
	intltool-extract.in \
	intltool-merge.in \
	intltool-update.in \
	autogen.sh

# Includes additional files in the distribution package
EXTRA_DIST = \
	$(INTLTOOL_FILES)

# Lists files to be cleaned up
DISTCLEANFILES = \
	intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache

# Custom uninstallation target
uninstall-local:
	-rm -r $(docdir)
