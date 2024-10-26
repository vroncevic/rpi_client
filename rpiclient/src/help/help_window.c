/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * help_window.c
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
#include "help_window.h"

HelpWindow *new_help_window(void)
{
    HelpWindow *instance = g_malloc(sizeof(HelpWindow));

    if (!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_HELP_WINDOW);
        return NULL;
    }

    instance->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    if (!instance->window)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_HELP_WINDOW);
        destroy_help_window(instance);
        return NULL;
    }

    instance->image_slider = new_image_slider();

    if (!instance->image_slider)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_HELP_WINDOW);
        destroy_help_window(instance);
        return NULL;
    }

    gtk_window_set_position(GTK_WINDOW(instance->window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(instance->window), WIDTH_HELP_WINDOW, HEIGHT_HELP_WINDOW);
    gtk_window_set_title(GTK_WINDOW(instance->window), TITLE_HELP_WINDOW);

    const gchar *icon = get_resource_file(ICON_HELP_WINDOW);

    if (icon)
    {
        GdkPixbuf *pixbuf = cpixbuf(icon);

        if (pixbuf)
        {
            gtk_window_set_icon(GTK_WINDOW(instance->window), pixbuf);
            g_object_unref(pixbuf);
        }
        else
        {
            g_warning(WARNING_LOG_FAILED_PIXBUF_HELP_WINDOW);
        }
            
        g_free(icon);
    }
    else
    {
        g_warning(WARNING_LOG_FAILED_RESOURCE_HELP_WINDOW);
    }

    gtk_window_set_resizable(GTK_WINDOW(instance->window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(instance->window), BORDER_WIDTH_HELP_WINDOW);
    gtk_container_add(GTK_CONTAINER(instance->window), instance->image_slider);

    return instance;
}

void show_help_window(HelpWindow *instance)
{
    if (instance && instance->window && !gtk_widget_get_visible(instance->window))
    {
        gtk_widget_show(instance->window);
    }
}

void hide_help_window(HelpWindow *instance)
{
    if (instance && instance->window && gtk_widget_get_visible(instance->window))
    {
        gtk_widget_hide(instance->window);
    }
}

void destroy_help_window(HelpWindow *instance)
{
    if (instance)
    {
        if (instance->image_slider)
        {
            destroy_image_slider(instance->image_slider);
        }

        if (instance->window)
        {
            gtk_widget_destroy(instance->window);
        }

        g_free(instance);
    }
}
