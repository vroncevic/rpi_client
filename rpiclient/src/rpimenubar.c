/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpimenubar.h
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
#include "rpimenubar.h"

RPIMenuBar * new_rpimenubar() {
    RPIMenuBar *rpimenubar_ptr = g_malloc(sizeof(RPIMenuBar));
    rpimenubar_ptr->menubar = gtk_menu_bar_new();
    rpimenubar_ptr->file_item = new_rpifile();
    rpimenubar_ptr->option_item = new_rpioption();
    rpimenubar_ptr->help_item = new_rpihelp();
    rpimenubar_ptr->about_item = new_rpiabout();
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpimenubar_ptr->menubar), rpimenubar_ptr->file_item->file
    );
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpimenubar_ptr->menubar),
        rpimenubar_ptr->option_item->option
    );
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpimenubar_ptr->menubar),
        rpimenubar_ptr->help_item->help_subitem
    );
    gtk_menu_shell_append(
        GTK_MENU_SHELL(rpimenubar_ptr->menubar),
        rpimenubar_ptr->about_item->about_subitem
    );
    return rpimenubar_ptr;
}

void show_rpimenubar(RPIMenuBar *rpimenubar_ptr) {
    if(rpimenubar_ptr) {
        gtk_widget_show_all(rpimenubar_ptr->menubar);
    }
}

void hide_rpimenubar(RPIMenuBar *rpimenubar_ptr) {
    if(rpimenubar_ptr) {
        gtk_widget_hide_all(rpimenubar_ptr->menubar);
    }
}

void destroy_rpimenubar(RPIMenuBar *rpimenubar_ptr) {
    if(rpimenubar_ptr) {
        destroy_rpifile(rpimenubar_ptr->file_item);
        destroy_rpioption(rpimenubar_ptr->option_item);
        destroy_rpihelp(rpimenubar_ptr->help_item);
        destroy_rpiabout(rpimenubar_ptr->about_item);
        gtk_widget_destroy(rpimenubar_ptr->menubar);
        g_free(rpimenubar_ptr->menubar);
    }
}

