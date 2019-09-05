##
## @info   gengtkpro ver.1.0
## @author Vladimir Roncevic <elektron.ronca@gmail.com>
## @brief  Process this file with automake to produce Makefile.in
##

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(RPICLIENT_CFLAGS)

AM_CFLAGS = \
	-Wall \
	-g

bin_PROGRAMS = rpiclient

rpiclient_SOURCES = \
	resource.h \
	config.h \
	rpiformat.h \
	cpixbuf.c \
	settingsread.c \
	settingswrite.c \
	readsocket.c \
	rpiencrypt.c \
	rpidecrypt.c \
	aboutdialog.c \
	aboutdialog.h \
	exitdialog.c \
	exidialog.h \
	imageslider.c \
	imageslider.h \
	helpwindow.c \
	helpwindow.h \
	infodialog.c \
	infodialog.h \
	controlexit.h \
	controlexit.c \
	entryaddress.c \
	entryaddress.h \
	entryport.c \
	entryport.h \
	tablesettings.c \
	tablesettings.h \
	hboxsettings.c \
	hboxsettings.h \
	vboxsettings.c \
	vboxsettings.h \
	settingswindow.c \
	settingswindow.h \
	warningdialog.c \
	warningdialog.h \
	verticalbar.c \
	verticalbar.h \
	rpiquit.c \
	rpiquit.h \
	rpifilemenu.c \
	rpifilemenu.h \
	rpifile.c \
	rpifile.h \
	rpiconnect.c \
	rpiconnect.h \
	rpidisconnect.c \
	rpidisconnect.h \
	rpisend.c \
	rpisend.h \
	rpisettings.c \
	rpisettings.h \
	rpioptionmenu.c \
	rpioptionmenu.h \
	rpioption.c \
	rpioption.h \
	rpihelp.c \
	rpihelp.h \
	rpiabout.c \
	rpiabout.h \
	rpimenubar.c \
	rpimenubar.h \
	rpichannelget.c \
	rpichannelget.h \
	rpifixedget.c \
	rpifixedget.h \
	rpiframeget.c \
	rpiframeget.h\
	rpichannelset.c \
	rpichannelset.h \
	rpifixedset.c \
	rpifixedset.h \
	rpiframeset.c \
	rpiframeset.h \
	rpiframetop.c \
	rpiframetop.h \
	rpivbox.c \
	rpivbox.h \
	rpiclient.c \
	rpiclient.h \
	main.c

rpiclient_LDFLAGS = \
	-Wl,--export-dynamic

rpiclient_LDADD = $(RPICLIENT_LIBS)

# Remove pkg directory on uninstall
uninstall-local:
	-rm -r $(pkgdatadir)

