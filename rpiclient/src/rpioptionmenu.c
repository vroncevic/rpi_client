/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpioptionmenu.c
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
#include "rpioptionmenu.h"

RPIOptionMenu * new_rpioptionmenu() {
    RPIOptionMenu *rpioptionmenu_ptr = g_malloc(sizeof(RPIOptionMenu));
    rpioptionmenu_ptr->option_menu = gtk_menu_new();
    rpioptionmenu_ptr->connect = new_rpiconnect();
    rpioptionmenu_ptr->disconnect = new_rpidisconnect();
    rpioptionmenu_ptr->send = new_rpisend();
    rpioptionmenu_ptr->settings = new_rpisettings();
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpioptionmenu_ptr->option_menu),
        rpioptionmenu_ptr->connect->connect_subitem
    );
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpioptionmenu_ptr->option_menu),
        rpioptionmenu_ptr->disconnect->disconnect_subitem
    );
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpioptionmenu_ptr->option_menu),
        rpioptionmenu_ptr->send->send_subitem
    );
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpioptionmenu_ptr->option_menu),
        rpioptionmenu_ptr->settings->settings_subitem
    );
    return rpioptionmenu_ptr;
}

void show_rpioptionmenu(RPIOptionMenu *rpioptionmenu_ptr) {
    if(rpioptionmenu_ptr) {
        gtk_widget_show_all(rpioptionmenu_ptr->option_menu);
    }
}

void hide_rpioptionmenu(RPIOptionMenu *rpioptionmenu_ptr) {
    if(rpioptionmenu_ptr) {
        gtk_widget_hide_all(rpioptionmenu_ptr->option_menu);
    }
}

void destroy_rpioptionmenu(RPIOptionMenu *rpioptionmenu_ptr) {
    if(rpioptionmenu_ptr) {
        destroy_rpiconnect(rpioptionmenu_ptr->connect);
        destroy_rpidisconnect(rpioptionmenu_ptr->disconnect);
        destroy_rpisend(rpioptionmenu_ptr->send);
        destroy_rpisettings(rpioptionmenu_ptr->settings);
        gtk_widget_destroy(rpioptionmenu_ptr->option_menu);
        g_free(rpioptionmenu_ptr->connect);
        g_free(rpioptionmenu_ptr->disconnect);
        g_free(rpioptionmenu_ptr->send);
        g_free(rpioptionmenu_ptr->settings);
        g_free(rpioptionmenu_ptr->option_menu);
        g_free(rpioptionmenu_ptr);
    }
}

