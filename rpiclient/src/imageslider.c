/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * imageslider.c
 * Copyright (C) 2016 Vladimir Roncevic <elektron.ronca@gmail.com>
 * 
 * rpiclient-gtk is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * rpiclient-gtk is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "imageslider.h"

ImageSlider * new_image_slider() {
    gchar * res_dir = g_strjoin(NULL, g_get_current_dir(), RESOURCE_PATH, NULL);
    ImageSlider *image_slider_ptr = g_malloc(sizeof(ImageSlider));
    image_slider_ptr->slider_count = START_SLIDER_COUNT;
    image_slider_ptr->fixed = gtk_fixed_new();
    image_slider_ptr->image = gtk_image_new_from_file(
        g_strjoin(NULL, res_dir, "1.png", NULL)
    );
    gtk_fixed_put(
        GTK_FIXED(image_slider_ptr->fixed), image_slider_ptr->image,
        X_POSITION_IMAGE_SLIDER, Y_POSITION_IMAGE_SLIDER
    );
    gtk_widget_set_size_request(
        image_slider_ptr->image, WIDTH_IMAGE_SLIDER, HEIGHT_IMAGE_SLIDER
    );
    image_slider_ptr->button_left = gtk_button_new_with_label(
        TEXT_BUTTON_LEFT_SLIDER
    );
    gtk_widget_set_size_request(
        image_slider_ptr->button_left,
        WIDTH_BUTTON_LEFT_SLIDER, HEIGHT_BUTTON_LEFT_SLIDER
    );
    gtk_fixed_put(
        GTK_FIXED(image_slider_ptr->fixed),
        image_slider_ptr->button_left,
        X_POSITION_BUTTON_LEFT_SLIDER,
        Y_POSITION_BUTTON_LEFT_SLIDER
    );
    image_slider_ptr->button_right = gtk_button_new_with_label(
        TEXT_BUTTON_RIGHT_SLIDER
    );
    gtk_widget_set_size_request(
        image_slider_ptr->button_right,
        WIDTH_BUTTON_RIGHT_SLIDER, HEIGHT_BUTTON_RIGHT_SLIDER
    );
    gtk_fixed_put(
        GTK_FIXED(image_slider_ptr->fixed), image_slider_ptr->button_right,
        X_POSITION_BUTTON_RIGHT_SLIDER, Y_POSITION_BUTTON_RIGHT_SLIDER
    );
    return image_slider_ptr;
}

void show_image_slider(ImageSlider *image_slider_ptr) {
    if(image_slider_ptr->fixed) {
        gtk_widget_show_all(image_slider_ptr->fixed);
    }
}

void hide_image_slider(ImageSlider *image_slider_ptr) {
    if(image_slider_ptr->fixed) {
        gtk_widget_hide_all(image_slider_ptr->fixed);
    }
}

void destroy_image_slider(ImageSlider *image_slider_ptr) {
    if(image_slider_ptr->fixed) {
        gtk_widget_destroy(image_slider_ptr->button_left);
        gtk_widget_destroy(image_slider_ptr->button_right);
        gtk_widget_destroy(image_slider_ptr->image);
        gtk_widget_destroy(image_slider_ptr->fixed);
        g_free(image_slider_ptr->button_left);
        g_free(image_slider_ptr->button_right);
        g_free(image_slider_ptr->image);
        g_free(image_slider_ptr->fixed);
        g_free(image_slider_ptr);
    }
}

