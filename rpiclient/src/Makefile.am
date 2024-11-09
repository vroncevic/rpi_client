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
	$(GTK_CFLAGS) \
	$(SQLITE3_CFLAGS)

rpiclient_LDFLAGS = \
	-Wl, \
	-export-dynamic

rpiclient_LDADD = \
	$(GTK_LIBS) \
	$(SQLITE3_LIBS)

bin_PROGRAMS = rpiclient

rpiclient_SOURCES = \
	main.c \
	home/rpi_home.c \
	home/rpi_home_frame.c \
	home/rpi_menu.c \
	home/rpi_channel_status.c \
	home/rpi_channel_control.c \
	about/rpi_about_dialog.c \
	rpi_format/rpi_format.c \
	exit/rpi_exit_dialog.c \
	help/rpi_help_window.c \
	help/rpi_image_slider.c \
	info/rpi_info_dialog.c \
	resource/rpi_cpixbuf.c \
	resource/rpi_get_resource_dir.c \
	resource/rpi_get_resource_file.c \
	resource/rpi_get_config_dir.c \
	resource/rpi_get_config_file.c \
	settings/rpi_settings_network_window.c \
	settings/rpi_settings_general_window.c \
	settings/rpi_settings_config.c \
	settings/rpi_settings_user.c \
	settings/rpi_settings_plain.c \
	settings/rpi_settings_sqlite.c \
	warning/rpi_warning_dialog.c \
	widgets/rpi_vertical_bar.c

uninstall-local:
	-rm -r $(pkgdatadir)

