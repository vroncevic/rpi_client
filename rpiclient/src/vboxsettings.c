/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * vboxsettings.c
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
#include "vboxsettings.h"

VBoxSettings * new_vbox_settings() {
    VBoxSettings *vbox_settings_ptr = g_malloc(sizeof(VBoxSettings));
    vbox_settings_ptr->vbox = gtk_vbox_new(FALSE, SPACING_VBOX_SETTINGS);
    vbox_settings_ptr->halign = gtk_alignment_new(1, 0, 0, 0);
    vbox_settings_ptr->table_settings = new_table_settings();
    vbox_settings_ptr->hbox_settings = new_hbox_settings();
    gtk_container_add(
        GTK_CONTAINER(vbox_settings_ptr->halign),
        vbox_settings_ptr->hbox_settings->hbox
    );
    gtk_container_add(
        GTK_CONTAINER(vbox_settings_ptr->vbox),
        vbox_settings_ptr->table_settings->table
    );
    gtk_box_pack_start(
        GTK_BOX(vbox_settings_ptr->vbox),
        vbox_settings_ptr->halign, FALSE, FALSE, 0
    );
    return vbox_settings_ptr;
}

void show_vbox_settings(VBoxSettings *vbox_settings_ptr) {
    if(vbox_settings_ptr) {
        gtk_widget_show_all(vbox_settings_ptr->vbox);
    }
}

void hide_vbox_settings(VBoxSettings *vbox_settings_ptr) {
    if(vbox_settings_ptr) {
        gtk_widget_hide_all(vbox_settings_ptr->vbox);
    }
}

void destroy_vbox_settings(VBoxSettings *vbox_settings_ptr) {
    if(vbox_settings_ptr) {
        destroy_hbox_settings(vbox_settings_ptr->hbox_settings);
        destroy_table_settings(vbox_settings_ptr->table_settings);
        gtk_widget_destroy(vbox_settings_ptr->halign);
        gtk_widget_destroy(vbox_settings_ptr->vbox);
        g_free(vbox_settings_ptr->hbox_settings);
        g_free(vbox_settings_ptr->table_settings);
        g_free(vbox_settings_ptr->halign);
        g_free(vbox_settings_ptr->vbox);
        g_free(vbox_settings_ptr);
    }
}

