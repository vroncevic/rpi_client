/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_image_slider.c
 * Copyright (C) 2016 - 2025 Vladimir Roncevic <elektron.ronca@gmail.com>
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
#include "../resource/rpi_resource.h"
#include "rpi_image_slider.h"

static const gint MAX_IMAGES_IMAGE_SLIDER = 5;
static const gint START_COUNT_IMAGE_SLIDER = 0;
static const gint X_POSITION_IMAGE_SLIDER = 0;
static const gint Y_POSITION_IMAGE_SLIDER = 0;
static const gint WIDTH_IMAGE_SLIDER = 245;
static const gint HEIGHT_IMAGE_SLIDER = 355;
static const gchar* TEXT_BUTTON_LEFT_IMAGE_SLIDER = "<<";
static const gint WIDTH_BUTTON_LEFT_IMAGE_SLIDER = 80;
static const gint HEIGHT_BUTTON_LEFT_IMAGE_SLIDER = 35;
static const gint X_POSITION_BUTTON_LEFT_IMAGE_SLIDER = 45;
static const gint Y_POSITION_BUTTON_LEFT_IMAGE_SLIDER = 355;
static const gchar* TEXT_BUTTON_RIGHT_IMAGE_SLIDER = ">>";
static const gint WIDTH_BUTTON_RIGHT_IMAGE_SLIDER = 80;
static const gint HEIGHT_BUTTON_RIGHT_IMAGE_SLIDER = 35;
static const gint X_POSITION_BUTTON_RIGHT_IMAGE_SLIDER = 125;
static const gint Y_POSITION_BUTTON_RIGHT_IMAGE_SLIDER = 355;
static const gchar* FIRST_IMAGE_HELP_IMAGE_SLIDER = "1.png";
static const gchar* WARNING_LOG_FAILED_MALLOC_IMAGE_SLIDER = "Failed to allocate memory for image slider.\n";
static const gchar* WARNING_LOG_FAILED_RESOURCE_IMAGE_SLIDER = "Failed to get resource path for image slider.\n";

//////////////////////////////////////////////////////////////////////////////
/// @brief Image slider complex widget
///   fixed - Gtk fixed container widget
///   image - Gtk image widget
///   button_left - Gtk button widget for left action
///   button_right - Gtk button widget for right action
///   slider_count - Slider count (count position)
struct _ImageSlider
{
    GtkWidget *fixed;
    GtkWidget *image;
    GtkWidget *button_left;
    GtkWidget *button_right;
    guint slider_count;
};

ImageSlider *new_image_slider(void)
{
    ImageSlider *instance = g_malloc(sizeof(ImageSlider));

    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_IMAGE_SLIDER);
        return NULL;
    }

    instance->slider_count = START_COUNT_IMAGE_SLIDER;
    instance->fixed = gtk_fixed_new();

    if (!GTK_IS_FIXED(instance->fixed))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_IMAGE_SLIDER);
        destroy_image_slider(instance);
        return NULL;
    }

    const gchar *image = rpi_get_resource_file(FIRST_IMAGE_HELP_IMAGE_SLIDER);

    if (!image)
    {
        g_warning("%s", WARNING_LOG_FAILED_RESOURCE_IMAGE_SLIDER);
        destroy_image_slider(instance);
        return NULL;
    }

    instance->image = gtk_image_new_from_file(image);

    if (!GTK_IS_IMAGE(instance->image))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_IMAGE_SLIDER);
        g_free((gpointer)image);
        destroy_image_slider(instance);
        return NULL;
    }

    g_free((gpointer)image);
    gtk_fixed_put(
        GTK_FIXED(instance->fixed),
        GTK_WIDGET(instance->image),
        X_POSITION_IMAGE_SLIDER,
        Y_POSITION_IMAGE_SLIDER
    );
    gtk_widget_set_size_request(
        GTK_WIDGET(instance->image),
        WIDTH_IMAGE_SLIDER,
        HEIGHT_IMAGE_SLIDER
    );
    instance->button_left = gtk_button_new_with_label(TEXT_BUTTON_LEFT_IMAGE_SLIDER);

    if (!GTK_IS_BUTTON(instance->button_left))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_IMAGE_SLIDER);
        destroy_image_slider(instance);
        return NULL;
    }

    gtk_widget_set_size_request(
        GTK_WIDGET(instance->button_left),
        WIDTH_BUTTON_LEFT_IMAGE_SLIDER,
        HEIGHT_BUTTON_LEFT_IMAGE_SLIDER
    );
    gtk_fixed_put(
        GTK_FIXED(instance->fixed),
        GTK_WIDGET(instance->button_left),
        X_POSITION_BUTTON_LEFT_IMAGE_SLIDER,
        Y_POSITION_BUTTON_LEFT_IMAGE_SLIDER
    );
    instance->button_right = gtk_button_new_with_label(TEXT_BUTTON_RIGHT_IMAGE_SLIDER);

    if (!GTK_IS_BUTTON(instance->button_right))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_IMAGE_SLIDER);
        destroy_image_slider(instance);
        return NULL;
    }

    gtk_widget_set_size_request(
        GTK_WIDGET(instance->button_right),
        WIDTH_BUTTON_RIGHT_IMAGE_SLIDER,
        HEIGHT_BUTTON_RIGHT_IMAGE_SLIDER
    );
    gtk_fixed_put(
        GTK_FIXED(instance->fixed),
        GTK_WIDGET(instance->button_right),
        X_POSITION_BUTTON_RIGHT_IMAGE_SLIDER,
        Y_POSITION_BUTTON_RIGHT_IMAGE_SLIDER
    );

    return instance;
}

void show_image_slider(ImageSlider *instance)
{
    if (instance)
    {
        gboolean is_fixed = GTK_IS_FIXED(instance->fixed);
        gboolean is_fixed_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->fixed));

        if (is_fixed && is_fixed_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->fixed));
        }
    }
}

void hide_image_slider(ImageSlider *instance)
{
    if (instance)
    {
        gboolean is_fixed = GTK_IS_FIXED(instance->fixed);
        gboolean is_fixed_visible = gtk_widget_get_visible(GTK_WIDGET(instance->fixed));

        if (is_fixed && is_fixed_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->fixed));
        }
    }
}

GtkWidget *get_fixed_image_slider(ImageSlider *instance)
{
    return instance && GTK_IS_FIXED(instance->fixed) ? instance->fixed : NULL;
}

void destroy_image_slider(ImageSlider *instance)
{
    if (instance)
    {
        if (GTK_IS_FIXED(instance->fixed))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->fixed));
            instance->fixed = NULL;
            instance->image = NULL;
            instance->button_left = NULL;
            instance->button_right = NULL;
        }

        g_free((gpointer)instance);
    }
}
