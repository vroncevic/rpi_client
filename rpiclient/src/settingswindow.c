/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settingswindow.c
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
#include "settingswindow.h"

SettingsWindow * new_settings_window() {
    gchar * res_dir = g_strjoin(NULL, g_get_current_dir(), RESOURCE_PATH, NULL);
    SettingsWindow *settings_window_ptr = g_malloc(sizeof(SettingsWindow));
    settings_window_ptr->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(
        GTK_WINDOW(settings_window_ptr->window), GTK_WIN_POS_CENTER
    );
    gtk_window_set_default_size(
        GTK_WINDOW(settings_window_ptr->window),
        WIDTH_SETTINGS_WINDOW, HEIGHT_SETTINGS_WINDOW
    );
    gtk_window_set_title(
        GTK_WINDOW(settings_window_ptr->window), TITLE_SETTINGS_WINDOW
    );
    const gchar *icon = g_strjoin(NULL, res_dir, "icon.png", NULL);
    gtk_window_set_icon(GTK_WINDOW(settings_window_ptr->window), cpixbuf(icon));
    gtk_window_set_resizable(GTK_WINDOW(settings_window_ptr->window),FALSE);
    gtk_container_set_border_width(
        GTK_CONTAINER(settings_window_ptr->window),
        CONTAINER_BORDER_WIDTH_SETTINGS_WINDOW
    );
    settings_window_ptr->vbox_settings = new_vbox_settings();
    gtk_container_add(
        GTK_CONTAINER(settings_window_ptr->window),
        settings_window_ptr->vbox_settings->vbox
    );
    return settings_window_ptr;
}

void show_settings_window(SettingsWindow *settings_window_ptr) {
    if(settings_window_ptr) {
        gtk_widget_show_all(settings_window_ptr->window);
    }
}

void hide_settings_window(SettingsWindow *settings_window_ptr) {
    if(settings_window_ptr) {
        gtk_widget_hide_all(settings_window_ptr->window);
    }
}

void destroy_settings_window(SettingsWindow *settings_window_ptr) {
    if(settings_window_ptr) {
        destroy_vbox_settings(settings_window_ptr->vbox_settings);
        gtk_widget_destroy(settings_window_ptr->window);
        g_free(settings_window_ptr->vbox_settings);
        g_free(settings_window_ptr->window);
        g_free(settings_window_ptr);
    }
}

