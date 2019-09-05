/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpisend.c
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
#include "rpisend.h"

RPISend * new_rpisend() {
    RPISend *rpisend_ptr = g_malloc(sizeof(RPISend));
    rpisend_ptr->send_subitem = gtk_menu_item_new_with_label(MENU_ITEM_SEND);
    return rpisend_ptr;
}

void show_rpisend(RPISend *rpisend_ptr) {
    if(rpisend_ptr) {
        gtk_widget_show(rpisend_ptr->send_subitem);
    }
}

void hide_rpisend(RPISend *rpisend_ptr) {
    if(rpisend_ptr) {
        gtk_widget_hide(rpisend_ptr->send_subitem);
    }
}

void destroy_rpisend(RPISend *rpisend_ptr) {
    if(rpisend_ptr) {
        gtk_widget_destroy(rpisend_ptr->send_subitem);
        g_free(rpisend_ptr->send_subitem);
        g_free(rpisend_ptr);
    }
}

