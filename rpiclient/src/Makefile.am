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
	-g \
	$(GTK_CFLAGS)

rpiclient_LDFLAGS = \
	-Wl,--export-dynamic \
	$(GTK_LIBS)

rpiclient_LDADD = $(RPICLIENT_LIBS)

bin_PROGRAMS = rpiclient

rpiclient_SOURCES = \
    main.c \
    home/home.c \
    home/home_frame.c \
    home/menu_bar.c \
    home/read_socket.c \
    home/rpiclient_about_signal_connect.c \
    home/rpiclient_channel_signal_connect.c \
    home/rpiclient_connect_signal_connect.c \
    home/rpiclient_diconnect_signal_connect.c \
    home/rpiclient_gpio_signal_connect.c \
    home/rpiclient_help_signal_connect.c \
    home/rpiclient_scale_signal_connect.c \
    home/rpiclient_send_signal_connect.c \
    home/rpiclient_settings_signal_connect.c \
    home/rpiclient_spinbutton_signal_connect.c \
    home/rpiclient_vbar_signal_connect.c \
    about/about_dialog.c \
    encrypt/rpiencrypt.c \
    encrypt/rpidecrypt.c \
    exit/exit_dialog.c \
    help/help_window.c \
    help/image_slider.c \
    info/info_dialog.c \
    resource/cpixbuf.c \
    resource/get_resource_dir.c \
    resource/get_resource_file.c \
    settings/settings_window.c \
    settings/settings_read.c \
    settings/settings_write.c \
    warning/warning_dialog.c \
    widgets/vertical_bar.c

GTK_CFLAGS = $(shell pkg-config --cflags gtk+-2.0)
GTK_LIBS = $(shell pkg-config --libs gtk+-2.0)

rpiclient_DATA = \
    resource/images/1.png \
    resource/images/2.png \
    resource/images/3.png \
    resource/images/4.png \
    resource/images/5.png \
    resource/images/blanko.png \
    resource/images/icon.png \
    resource/images/logo.png

# Remove pkg directory on uninstall
uninstall-local:
	-rm -r $(pkgdatadir)

