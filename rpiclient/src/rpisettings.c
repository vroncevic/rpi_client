/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpisettings.c
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
#include "rpisettings.h"

RPISettings * new_rpisettings() {
    RPISettings *rpisettings_ptr = g_malloc(sizeof(RPISettings));
    rpisettings_ptr->settings_subitem = gtk_menu_item_new_with_label(
        MENU_ITEM_SETTINGS
    );
    return rpisettings_ptr;
}

void show_rpisettings(RPISettings *rpisettings_ptr) {
    if(rpisettings_ptr) {
        gtk_widget_show(rpisettings_ptr->settings_subitem);
    }
}

void hide_rpisettings(RPISettings *rpisettings_ptr) {
    if(rpisettings_ptr) {
        gtk_widget_hide(rpisettings_ptr->settings_subitem);
    }
}

void destroy_rpisettings(RPISettings *rpisettings_ptr) {
    if(rpisettings_ptr) {
        gtk_widget_destroy(rpisettings_ptr->settings_subitem);
        g_free(rpisettings_ptr->settings_subitem);
        g_free(rpisettings_ptr);
    }
}

