/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpifile.c
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
#include "rpifile.h"

RPIFile * new_rpifile() {
    RPIFile *rpifile_ptr = g_malloc(sizeof(RPIFile));
    rpifile_ptr->file = gtk_menu_item_new_with_label(MENU_ITEM_FILE);
    rpifile_ptr->file_menu = new_rpifilemenu();
    gtk_menu_item_set_submenu(
        GTK_MENU_ITEM(rpifile_ptr->file), rpifile_ptr->file_menu->file_menu
    );
    return rpifile_ptr;
}

void show_rpifile(RPIFile *rpifile_ptr) {
    if(rpifile_ptr) {
        gtk_widget_show_all(rpifile_ptr->file);
    }
}

void hide_rpifile(RPIFile *rpifile_ptr) {
    if(rpifile_ptr) {
        gtk_widget_show_all(rpifile_ptr->file);
    }
}

void destroy_rpifile(RPIFile *rpifile_ptr) {
    if(rpifile_ptr) {
        destroy_rpifilemenu(rpifile_ptr->file_menu);
        gtk_widget_destroy(rpifile_ptr->file);
        g_free(rpifile_ptr->file_menu);
        g_free(rpifile_ptr->file);
        g_free(rpifile_ptr);
    }
}

