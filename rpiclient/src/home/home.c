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

Home *new_home(void)
{
    // RPI_INIT();
    Home *instance = NULL;
    const gchar *icon = get_resource_file("icon.png");
    instance = g_malloc(sizeof(Home));
    
    if(instance)
    {
        instance->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(instance->window), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(instance->window), WIDTH_RPICLIENT_WINDOW, HEIGHT_RPICLIENT_WINDOW);
        gtk_window_set_icon(GTK_WINDOW(instance->window), cpixbuf(icon));
        gtk_window_set_title(GTK_WINDOW(instance->window), TITLE_RPICLIENT_WINDOW);
        gtk_window_set_resizable(GTK_WINDOW(instance->window), FALSE);
        gtk_container_set_border_width(GTK_CONTAINER(instance->window), CONTAINER_BORDER_WIDTH_RPICLIENT_WINDOW);
        instance->vbox = gtk_vbox_new(FALSE, 0);
        instance->menu_bar = new_menu_bar();
        instance->frame_home = new_home_frame();
        gtk_box_pack_start(GTK_BOX(instance->vbox), instance->menu_bar, FALSE, FALSE, 3);
        gtk_box_pack_start(GTK_BOX(instance->vbox), instance->frame_home, FALSE, FALSE, 0);
        gtk_container_add(GTK_CONTAINER(instance->window), instance->vbox);
    }

    if(icon)
    {
        g_free(icon);
    }

    return instance;
}

void show_home(Home *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->window)
    {
        gtk_widget_show(instance->window);
    }
}

void hide_home(Home *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->window)
    {
        gtk_widget_hide(instance->window);
    }
}

void destroy_home(Home *instance)
{
    if (instance == NULL)
    {
        return;
    }

    destroy_home_frame(instance->frame_home);
    gtk_widget_destroy(instance->menu_bar);
    gtk_widget_destroy(instance->vbox);
    gtk_widget_destroy(instance->window);
    g_free(instance);
}
