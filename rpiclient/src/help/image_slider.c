/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * image_slider.c
 * Copyright (C) 2016 - 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
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
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "image_slider.h"

ImageSlider *new_image_slider(void)
{
    ImageSlider *instance = g_malloc(sizeof(ImageSlider));

    if (!instance)
    {
        g_warning(WARNING_MSG_IMAGE_SLIDER);
        return NULL;
    }

    instance->slider_count = START_COUNT_IMAGE_SLIDER;
    instance->fixed = gtk_fixed_new();

    if (!instance->fixed)
    {
        g_warning(WARNING_MSG_IMAGE_SLIDER);
        g_free((gpointer)instance);
        return NULL;
    }

    const gchar *image = get_resource_file(FIRST_IMAGE_HELP_IMAGE_SLIDER);

    if (!image)
    {
        g_warning(WARNING_LOG_FAILED_RESOURCE_IMAGE_SLIDER);
        destroy_image_slider(instance);
        return NULL;
    }

    instance->image = gtk_image_new_from_file(image);

    if (!instance->image)
    {
        g_warning(WARNING_MSG_IMAGE_SLIDER);
        g_free((gpointer)image);
        destroy_image_slider(instance);
        return NULL;
    }

    g_free((gpointer)image);
    gtk_fixed_put(GTK_FIXED(instance->fixed), instance->image, X_POSITION_IMAGE_SLIDER, Y_POSITION_IMAGE_SLIDER);
    gtk_widget_set_size_request(instance->image, WIDTH_IMAGE_SLIDER, HEIGHT_IMAGE_SLIDER);
    instance->button_left = gtk_button_new_with_label(TEXT_BUTTON_LEFT_IMAGE_SLIDER);

    if (!instance->button_left)
    {
        g_warning(WARNING_MSG_IMAGE_SLIDER);
        destroy_image_slider(instance);
        return NULL;
    }

    gtk_widget_set_size_request(instance->button_left, WIDTH_BUTTON_LEFT_IMAGE_SLIDER, HEIGHT_BUTTON_LEFT_IMAGE_SLIDER);
    gtk_fixed_put(GTK_FIXED(instance->fixed), instance->button_left, X_POSITION_BUTTON_LEFT_IMAGE_SLIDER, Y_POSITION_BUTTON_LEFT_IMAGE_SLIDER);
    instance->button_right = gtk_button_new_with_label(TEXT_BUTTON_RIGHT_IMAGE_SLIDER);

    if (!instance->button_right)
    {
        g_warning(WARNING_MSG_IMAGE_SLIDER);
        destroy_image_slider(instance);
        return NULL;
    }

    gtk_widget_set_size_request(instance->button_right, WIDTH_BUTTON_RIGHT_IMAGE_SLIDER, HEIGHT_BUTTON_RIGHT_IMAGE_SLIDER);
    gtk_fixed_put(GTK_FIXED(instance->fixed), instance->button_right, X_POSITION_BUTTON_RIGHT_IMAGE_SLIDER, Y_POSITION_BUTTON_RIGHT_IMAGE_SLIDER);

    return instance;
}

void show_image_slider(ImageSlider *instance)
{
    if (instance && instance->fixed && !gtk_widget_get_visible(instance->fixed))
    {
        gtk_widget_show(instance->fixed);
    }
}

void hide_image_slider(ImageSlider *instance)
{
    if (instance && instance->fixed && gtk_widget_get_visible(instance->fixed))
    {
        gtk_widget_hide(instance->fixed);
    }
}

void destroy_image_slider(ImageSlider *instance)
{
    if (instance)
    {
        if (instance->fixed)
        {
            gtk_widget_destroy(instance->fixed);
            instance->fixed = NULL;
            instance->image = NULL;
            instance->button_left = NULL;
            instance->button_right = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
