/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpidisconnect.c
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
#include "rpidisconnect.h"

RPIDisconnect * new_rpidisconnect() {
    RPIDisconnect *rpidisconnect_ptr = g_malloc(sizeof(RPIDisconnect));
    rpidisconnect_ptr->disconnect_subitem = gtk_menu_item_new_with_label(
        MENU_ITEM_DISCONNECT
    );
    return rpidisconnect_ptr;
}

void show_rpidisconnect(RPIDisconnect *rpidisconnect_ptr) {
    if(rpidisconnect_ptr) {
        gtk_widget_show(rpidisconnect_ptr->disconnect_subitem);
    }
}

void hide_rpidisconnect(RPIDisconnect *rpidisconnect_ptr) {
    if(rpidisconnect_ptr) {
        gtk_widget_hide(rpidisconnect_ptr->disconnect_subitem);
    }
}

void destroy_rpidisconnect(RPIDisconnect *rpidisconnect_ptr) {
    if(rpidisconnect_ptr) {
        gtk_widget_destroy(rpidisconnect_ptr->disconnect_subitem);
        g_free(rpidisconnect_ptr->disconnect_subitem);
        g_free(rpidisconnect_ptr);
    }
}

