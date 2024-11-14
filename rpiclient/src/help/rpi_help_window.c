/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_help_window.c
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
#include "rpi_help_window.h"

#define FAILED_MALLOC_HELP_WINDOW "Failed to allocate memory for help window.\n"
#define FAILED_PIXBUF_HELP_WINDOW "Failed to create pixbuf from help icon.\n"
#define FAILED_RESOURCE_HELP_WINDOW "Failed to get resource path for help icon.\n"

static const gchar* TITLE_HELP_WINDOW = "Help";
static const gint BORDER_WIDTH_HELP_WINDOW = 10;
static const gint WIDTH_HELP_WINDOW = 300;
static const gint HEIGHT_HELP_WINDOW = 200;
static const gchar* ICON_HELP_WINDOW = "icon.png";

//////////////////////////////////////////////////////////////////////////////
/// @brief Help window complex widget
///   window - Gtk window widget
///   image_slider - Complex image slider widget
struct _HelpWindow
{
    GtkWidget *window;
    ImageSlider *image_slider;
};

HelpWindow *new_help_window(void)
{
    HelpWindow *instance = g_malloc(sizeof(HelpWindow));

    if (!instance)
    {
        g_critical(FAILED_MALLOC_HELP_WINDOW);
        return NULL;
    }

    instance->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    if (!GTK_IS_WINDOW(instance->window))
    {
        g_critical(FAILED_MALLOC_HELP_WINDOW);
        destroy_help_window(instance);
        return NULL;
    }

    instance->image_slider = new_image_slider();

    if (!instance->image_slider)
    {
        g_critical(FAILED_MALLOC_HELP_WINDOW);
        destroy_help_window(instance);
        return NULL;
    }

    gtk_window_set_position(GTK_WINDOW(instance->window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(instance->window), WIDTH_HELP_WINDOW, HEIGHT_HELP_WINDOW);
    gtk_window_set_title(GTK_WINDOW(instance->window), TITLE_HELP_WINDOW);
    gchar *icon_file_path = rpi_get_resource_file_path(ICON_HELP_WINDOW);

    if (icon_file_path)
    {
        GdkPixbuf *pixbuf = rpi_cpixbuf(icon_file_path);

        if (GDK_IS_PIXBUF(pixbuf))
        {
            gtk_window_set_icon(GTK_WINDOW(instance->window), pixbuf);
            g_object_unref(pixbuf);
            pixbuf = NULL;
        }
        else
        {
            g_critical(FAILED_PIXBUF_HELP_WINDOW);
            pixbuf = NULL;
        }
            
        g_free(icon_file_path);
        icon_file_path = NULL;
    }
    else
    {
        g_critical(FAILED_RESOURCE_HELP_WINDOW);
        icon_file_path = NULL;
    }

    gtk_window_set_resizable(GTK_WINDOW(instance->window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(instance->window), BORDER_WIDTH_HELP_WINDOW);
    gtk_container_add(
        GTK_CONTAINER(instance->window), GTK_WIDGET(get_fixed_image_slider(instance->image_slider))
    );
    g_signal_connect_swapped(
        G_OBJECT(instance->window), "delete-event", G_CALLBACK(destroy_help_window), instance
    );

    return instance;
}

void show_help_window(HelpWindow *instance)
{
    if (instance)
    {
        gboolean is_window = GTK_IS_WINDOW(instance->window);
        gboolean is_window_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->window));

        if (is_window && is_window_hidden)
        {
            gtk_widget_show_all(GTK_WIDGET(instance->window));
        }
    }
}

void hide_help_window(HelpWindow *instance)
{
    if (instance)
    {
        gboolean is_window = GTK_IS_WINDOW(instance->window);
        gboolean is_window_visible = gtk_widget_get_visible(GTK_WIDGET(instance->window));

        if (is_window && is_window_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->window));
        }
    }
}

void destroy_help_window(HelpWindow *instance)
{
    if (instance)
    {
        if (instance->image_slider)
        {
            destroy_image_slider(instance->image_slider);
            instance->image_slider = NULL;
        }

        if (GTK_IS_WINDOW(instance->window))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->window));
            instance->window = NULL;
        }

        g_free(instance);
    }
}
