##
## @info   gengtkpro ver.1.0
## @author Vladimir Roncevic <elektron.ronca@gmail.com>
## @brief  Process this file with automake to produce Makefile.in
##

# Specify files for distribution
dist_config_DATA = \
	config/prompt.config \
	config/server_address.config \
	config/server_port.config

dist_images_DATA = \
	images/1.png \
	images/2.png \
	images/3.png \
	images/4.png \
	images/5.png \
	images/blanko.png \
	images/icon.png \
	images/logo.png

# Install paths
rcdir = $(pkgdatadir)/rc
configdir = $(rcdir)/config
imagesdir = $(rcdir)/images

# Rules for installation
config_DATA = $(dist_config_DATA)
nodist_images_DATA = $(dist_images_DATA)

# Define the all target
all: install-data-local install-images

install-images:
	mkdir -p $(DESTDIR)$(imagesdir)
	cp $(nodist_images_DATA) $(DESTDIR)$(imagesdir)

install-data-local:
	mkdir -p $(DESTDIR)$(configdir)
	cp $(config_DATA) $(DESTDIR)$(configdir)
