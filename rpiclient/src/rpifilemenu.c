/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpifilemenu.c
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
#include "rpifilemenu.h"

RPIFileMenu * new_rpifilemenu() {
    RPIFileMenu *rpifilemenu_ptr = g_malloc(sizeof(RPIFileMenu));
    rpifilemenu_ptr->file_menu = gtk_menu_new();
    rpifilemenu_ptr->quit = new_rpiquit();
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpifilemenu_ptr->file_menu),
        rpifilemenu_ptr->quit->quit_subitem
    );
    return rpifilemenu_ptr;
}

void show_rpifilemenu(RPIFileMenu *rpifilemenu_ptr) {
    if(rpifilemenu_ptr) {
        gtk_widget_show_all(rpifilemenu_ptr->file_menu);
    }
}

void hide_rpifilemenu(RPIFileMenu *rpifilemenu_ptr) {
    if(rpifilemenu_ptr) {
        gtk_widget_hide_all(rpifilemenu_ptr->file_menu);
    }
}

void destroy_rpifilemenu(RPIFileMenu *rpifilemenu_ptr) {
    if(rpifilemenu_ptr) {
        destroy_rpiquit(rpifilemenu_ptr->quit);
        gtk_widget_destroy(rpifilemenu_ptr->file_menu);
        g_free(rpifilemenu_ptr->quit);
        g_free(rpifilemenu_ptr->file_menu);
        g_free(rpifilemenu_ptr);
    }
}

