/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpioption.c
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
#include "rpioption.h"

RPIOption * new_rpioption() {
    RPIOption *rpioption_ptr = g_malloc(sizeof(RPIOption));
    rpioption_ptr->option_menu = new_rpioptionmenu();
    rpioption_ptr->option = gtk_menu_item_new_with_label(MENU_ITEM_OPTION);
    gtk_menu_item_set_submenu(
        GTK_MENU_ITEM(rpioption_ptr->option), rpioption_ptr->option_menu->option_menu
    );
    return rpioption_ptr;
}

void show_rpioption(RPIOption *rpioption_ptr) {
    if(rpioption_ptr) {
        gtk_widget_show_all(rpioption_ptr->option);
    }
}

void hide_rpioption(RPIOption *rpioption_ptr) {
    if(rpioption_ptr) {
        gtk_widget_hide_all(rpioption_ptr->option);
    }
}

void destroy_rpioption(RPIOption *rpioption_ptr) {
    if(rpioption_ptr) {
        destroy_rpioptionmenu(rpioption_ptr->option_menu);
        gtk_widget_destroy(rpioption_ptr->option);
        g_free(rpioption_ptr->option_menu);
        g_free(rpioption_ptr->option);
        g_free(rpioption_ptr);
    }
}

