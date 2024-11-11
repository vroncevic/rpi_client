##
## @info   gengtkpro ver.1.0
## @brief  Process this file with automake to produce Makefile.in
##

# Define installation paths
imagesdir = $(prefix)/share/rpiclient/images

# Media images
dist_images_DATA = \
	images/1.png \
	images/2.png \
	images/3.png \
	images/4.png \
	images/5.png \
	images/blanko.png \
	images/icon.png \
	images/logo.png

# Use Automake's DATA primary for installing images
nodist_images_DATA = $(dist_images_DATA)
dist_imagesdir = $(imagesdir)

# Custom command for system-wide images installation (requires sudo)
install-images:
	@echo "Installing system-wide images to $(imagesdir)"
	@mkdir -p $(imagesdir)
	@cp $(nodist_images_DATA) $(imagesdir)

# Ensure images are installed with sudo make install
install-exec-hook: install-images
