/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiclient.c
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
#include "rpiclient.h"

RPIClient * new_rpiclient() {
    //RPI_INIT();
    gchar *res_dir = g_strjoin(NULL, g_get_current_dir(), RESOURCE_PATH, NULL);
    RPIClient *rpiclient_ptr = g_malloc(sizeof(RPIClient));
    rpiclient_ptr->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(
        GTK_WINDOW(rpiclient_ptr->window), GTK_WIN_POS_CENTER
    );
    gtk_window_set_default_size(
        GTK_WINDOW(rpiclient_ptr->window),
        WIDTH_RPICLIENT_WINDOW, HEIGHT_RPICLIENT_WINDOW
    );
    const gchar * icon = g_strjoin(NULL, res_dir, "icon.png", NULL);
    gtk_window_set_icon(GTK_WINDOW(rpiclient_ptr->window), cpixbuf(icon));
    gtk_window_set_title(
        GTK_WINDOW(rpiclient_ptr->window), TITLE_RPICLIENT_WINDOW
    );
    gtk_window_set_resizable(GTK_WINDOW(rpiclient_ptr->window), FALSE);
    gtk_container_set_border_width(
        GTK_CONTAINER(rpiclient_ptr->window),
        CONTAINER_BORDER_WIDTH_RPICLIENT_WINDOW
    );
    rpiclient_ptr->rpivbox_top = new_rpivbox();
    gtk_container_add(
        GTK_CONTAINER(rpiclient_ptr->window), rpiclient_ptr->rpivbox_top->vbox
    );
    return rpiclient_ptr;
}

void show_rpiclient(RPIClient *rpiclient_ptr) {
    if(rpiclient_ptr) {
        gtk_widget_show_all(rpiclient_ptr->window);
    }
}

void hide_rpiclient(RPIClient *rpiclient_ptr) {
    if(rpiclient_ptr) {
        gtk_widget_hide_all(rpiclient_ptr->window);
    }
}

void destroy_rpiclient(RPIClient *rpiclient_ptr) {
    if(rpiclient_ptr) {
        gtk_widget_destroy(rpiclient_ptr->window);
    }
}

