/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * hboxsettings.c
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
#include "hboxsettings.h"

HBoxSettings * new_hbox_settings() {
    HBoxSettings *hbox_settings_ptr = g_malloc(sizeof(HBoxSettings));
    hbox_settings_ptr->hbox = gtk_hbox_new(TRUE, 3);
    hbox_settings_ptr->button_ok = gtk_button_new_with_label(
        TEXT_HBOXSETTINGS_BUTTON_OK
    );
    gtk_widget_set_size_request(
        hbox_settings_ptr->button_ok,
        WIDTH_HBOXSETTINGS_BUTTON_OK, HEIGHT_HBOXSETTINGS_BUTTON_OK
    );
    hbox_settings_ptr->button_cancel = gtk_button_new_with_label(
        TEXT_HBOXSETTINGS_BUTTON_CANCEL
    );
    gtk_container_add(
        GTK_CONTAINER(hbox_settings_ptr->hbox), hbox_settings_ptr->button_ok
    );
    gtk_container_add(
        GTK_CONTAINER(hbox_settings_ptr->hbox), hbox_settings_ptr->button_cancel
    );
    return hbox_settings_ptr;
}

void show_hbox_settings(HBoxSettings *hbox_settings_ptr) {
    if(hbox_settings_ptr) {
        gtk_widget_show_all(hbox_settings_ptr->hbox);
    }
}

void hide_hbox_settings(HBoxSettings *hbox_settings_ptr) {
    if(hbox_settings_ptr) {
        gtk_widget_hide_all(hbox_settings_ptr->hbox);
    }
}

void destroy_hbox_settings(HBoxSettings *hbox_settings_ptr) {
    if(hbox_settings_ptr) {
        gtk_widget_destroy(hbox_settings_ptr->button_ok);
        gtk_widget_destroy(hbox_settings_ptr->button_cancel);
        gtk_widget_destroy(hbox_settings_ptr->hbox);
        g_free(hbox_settings_ptr->button_ok);
        g_free(hbox_settings_ptr->button_cancel);
        g_free(hbox_settings_ptr->hbox);
        g_free(hbox_settings_ptr);
    }
}

