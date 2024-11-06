/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * home.c
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
#include "home.h"

static const gchar* TITLE_WINDOW_HOME = "RPIClient v1.0";
static const gint WIDTH_WINDOW_HOME = 900;
static const gint HEIGHT_WINDOW_HOME = 400;
static const gint CONTAINER_BORDER_WIDTH_WINDOW_HOME = 2;
static const gint VERTICAL_BOX_SPACING_WINDOW_HOME = 0;
static const gchar* WARNING_LOG_FAILED_MALLOC_HOME = "Failed to allocate memory for home\n";
static const gchar* WARNING_LOG_FAILED_MALLOC_WINDOW_HOME = "Failed to allocate memory for home window\n";
static const gchar* WARNING_LOG_FAILED_PIXBUF_HOME = "Failed to create pixbuf from home icon.\n";
static const gchar* WARNING_LOG_FAILED_RESOURCE_HOME = "Failed to get resource path for home icon\n";
static const gchar* WARNING_LOG_FAILED_MALLOC_VBOX_HOME = "Failed to allocate memory for vertial box home\n";
static const gchar* WARNING_LOG_FAILED_MALLOC_MENU_BAR_HOME = "Failed to allocate memory for menu bar home\n";
static const gchar* WARNING_LOG_FAILED_MALLOC_HOME_FRAME_HOME = "Failed to allocate memory for frame home\n";

Home *new_home(void)
{
    // RPI_INIT();
    Home *instance = g_malloc(sizeof(Home));

    if(!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME);
        return NULL;
    }

    instance->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    if (!GTK_IS_WINDOW(instance->window))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_WINDOW_HOME);
        destroy_home(instance);
        return NULL;
    }

    gtk_window_set_position(GTK_WINDOW(instance->window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(instance->window), WIDTH_WINDOW_HOME, HEIGHT_WINDOW_HOME);
    const gchar *icon = get_resource_file("icon.png");

    if (icon)
    {
        GdkPixbuf *pixbuf = cpixbuf(icon);

        if (GDK_IS_PIXBUF(pixbuf))
        {
            gtk_window_set_icon(GTK_WINDOW(instance->window), pixbuf);
            g_object_unref(pixbuf);
        }
        else
        {
            g_warning("%s", WARNING_LOG_FAILED_PIXBUF_HOME);
        }

        g_free((gpointer)icon);
        icon = NULL;
    }
    else
    {
        g_warning("%s", WARNING_LOG_FAILED_RESOURCE_HOME);
        icon = NULL;
    }

    gtk_window_set_title(GTK_WINDOW(instance->window), TITLE_WINDOW_HOME);
    gtk_window_set_resizable(GTK_WINDOW(instance->window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(instance->window), CONTAINER_BORDER_WIDTH_WINDOW_HOME);
    instance->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, VERTICAL_BOX_SPACING_WINDOW_HOME);

    if (!GTK_IS_BOX(instance->vbox))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_VBOX_HOME);
        destroy_home(instance);
        return NULL;
    }

    instance->menu_bar = new_menu_bar();

    if (!instance->menu_bar)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR_HOME);
        destroy_home(instance);
        return NULL;
    }

    instance->frame_home = new_home_frame();

    if (!instance->frame_home)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME_HOME);
        destroy_home(instance);
        return NULL;
    }

    gtk_box_pack_start(GTK_BOX(instance->vbox), GTK_WIDGET(instance->menu_bar->menu_bar), FALSE, FALSE, 3);
    gtk_box_pack_start(GTK_BOX(instance->vbox), GTK_WIDGET(instance->frame_home->frame_home), FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(instance->window), instance->vbox);

    return instance;
}

void show_home(Home *instance)
{
    if (instance && GTK_IS_WINDOW(instance->window) && !gtk_widget_get_visible(instance->window))
    {
        gtk_widget_show_all(instance->window);
    }
}

void hide_home(Home *instance)
{
    if (instance && GTK_IS_WINDOW(instance->window) && gtk_widget_get_visible(instance->window))
    {
        gtk_widget_hide(instance->window);
    }
}

void destroy_home(Home *instance)
{
    if (instance)
    {
        if (instance->frame_home)
        {
            destroy_home_frame(instance->frame_home);
            instance->frame_home = NULL;
        }

        if (instance->menu_bar)
        {
            destroy_menu_bar(instance->menu_bar);
            instance->menu_bar = NULL;
        }

        if (GTK_IS_WINDOW(instance->window))
        {
            gtk_widget_destroy(instance->window);
            instance->window = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
