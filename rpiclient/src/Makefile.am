##
## @info   gengtkpro ver.1.0
## @author Vladimir Roncevic <elektron.ronca@gmail.com>
## @brief  Process this file with automake to produce Makefile.in
##

AM_SUBDIRS = home about encrypt exit help info resource settings warning

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS = \
	-Wall \
	-g \
	-pedantic \
	-Wall \
	-Wextra \
	-Wcast-align \
	-Wno-cast-qual \
	-Wdisabled-optimization \
	-Wformat=2 \
	-Winit-self \
	-Wlogical-op \
	-Wmissing-declarations \
	-Wmissing-include-dirs \
	-Wshadow \
	-Wstrict-overflow=5 \
	-Wundef \
	-Werror \
	-Wno-unused \
	-mtune=native \
	-std=c11 \
	$(GTK_CFLAGS)

rpiclient_LDFLAGS = \
	-Wl, \
	-export-dynamic

rpiclient_LDADD = $(GTK_LIBS)

bin_PROGRAMS = rpiclient

rpiclient_SOURCES = \
	main.c \
	home/home.c \
	home/home_frame.c \
	home/menu_bar.c \
	home/channel_status.c \
	home/channel_control.c \
	about/about_dialog.c \
	encrypt/rpi_encrypt.c \
	encrypt/rpi_decrypt.c \
	exit/exit_dialog.c \
	help/help_window.c \
	help/image_slider.c \
	info/info_dialog.c \
	resource/cpixbuf.c \
	resource/get_resource_dir.c \
	resource/get_resource_file.c \
	resource/get_config_dir.c \
	resource/get_config_file.c \
	settings/settings_window.c \
	settings/settings_read.c \
	settings/settings_write.c \
	settings/settings_free.c \
	warning/warning_dialog.c \
	widgets/vertical_bar.h \
	widgets/vertical_bar.c

uninstall-local:
	-rm -r $(pkgdatadir)

