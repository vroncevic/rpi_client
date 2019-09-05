/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpihelp.c
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
#include "rpihelp.h"

RPIHelp * new_rpihelp() {
    RPIHelp *rpihelp_ptr = g_malloc(sizeof(RPIHelp));
    rpihelp_ptr->help_subitem = gtk_menu_item_new_with_label(MENU_ITEM_HELP);
    return rpihelp_ptr;
}

void show_rpihelp(RPIHelp *rpihelp_ptr) {
    if(rpihelp_ptr) {
        gtk_widget_show(rpihelp_ptr->help_subitem);
    }
}

void hide_rpihelp(RPIHelp *rpihelp_ptr) {
    if(rpihelp_ptr) {
        gtk_widget_hide(rpihelp_ptr->help_subitem);
    }
}

void destroy_rpihelp(RPIHelp *rpihelp_ptr) {
    if(rpihelp_ptr) {
        gtk_widget_destroy(rpihelp_ptr->help_subitem);
        g_free(rpihelp_ptr->help_subitem);
        g_free(rpihelp_ptr);
    }
}

