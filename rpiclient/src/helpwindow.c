/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * helpwindow.c
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
#include "helpwindow.h"

HelpWindow * new_help_window() {
    gchar *res_dir = g_strjoin(NULL, g_get_current_dir(), RESOURCE_PATH, NULL);
    HelpWindow *help_window_ptr = g_malloc(sizeof(HelpWindow));
    help_window_ptr->image_slider = new_image_slider();
    help_window_ptr->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(
        GTK_WINDOW(help_window_ptr->window), GTK_WIN_POS_CENTER
    );
    gtk_window_set_default_size(
        GTK_WINDOW(help_window_ptr->window),
        WIDTH_HELP_WINDOW, HEIGHT_HELP_WINDOW
    );
    gtk_window_set_title(
        GTK_WINDOW(help_window_ptr->window), TITLE_HELP_WINDOW
    );
    const gchar *icon = g_strjoin(NULL, res_dir, "icon.png", NULL);
    gtk_window_set_icon(GTK_WINDOW(help_window_ptr->window), cpixbuf(icon));
    gtk_window_set_resizable(GTK_WINDOW(help_window_ptr->window), FALSE);
    gtk_container_set_border_width(
        GTK_CONTAINER(help_window_ptr->window),
        CONTAINER_BORDER_WIDTH_HELP_WINDOW
    );
    gtk_container_add(
        GTK_CONTAINER(help_window_ptr->window),
        help_window_ptr->image_slider->fixed
    );
    return help_window_ptr;
}

void show_help_window(HelpWindow *help_window_ptr) {
    if(help_window_ptr->window) {
        gtk_widget_show_all(help_window_ptr->window);
    }
}

void hide_help_window(HelpWindow *help_window_ptr) {
    if(help_window_ptr->window) {
        gtk_widget_hide_all(help_window_ptr->window);
    }
}

void destroy_help_window(HelpWindow *help_window_ptr) {
    if(help_window_ptr->window) {
        destroy_image_slider(help_window_ptr->image_slider);
        gtk_widget_destroy(help_window_ptr->window);
        g_free(help_window_ptr->image_slider);
        g_free(help_window_ptr);
    }
}

