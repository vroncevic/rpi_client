/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpivbox.c
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
#include "rpivbox.h"

RPIVBox * new_rpivbox() {
    RPIVBox *rpivbox_ptr = g_malloc(sizeof(RPIVBox));
    rpivbox_ptr->vbox = gtk_vbox_new(FALSE, 0);
    rpivbox_ptr->menu_bar = new_rpimenubar();
    rpivbox_ptr->frame_top = new_rpiframetop();
    gtk_box_pack_start(
        GTK_BOX(rpivbox_ptr->vbox), rpivbox_ptr->menu_bar->menubar,
        FALSE, FALSE, 3
    );
    gtk_box_pack_start(
        GTK_BOX(rpivbox_ptr->vbox), rpivbox_ptr->frame_top->frame, FALSE, FALSE, 0
    );
    return rpivbox_ptr;
}

void show_rpivbox(RPIVBox *rpivbox_ptr) {
    if(rpivbox_ptr) {
        gtk_widget_show_all(rpivbox_ptr->vbox);
    }
}

void hide_rpivbox(RPIVBox *rpivbox_ptr) {
    if(rpivbox_ptr) {
        gtk_widget_hide_all(rpivbox_ptr->vbox);
    }
}

void destroy_rpivbox(RPIVBox *rpivbox_ptr) {
    if(rpivbox_ptr) {
        destroy_rpiframetop(rpivbox_ptr->frame_top);
        destroy_rpimenubar(rpivbox_ptr->menu_bar);
        gtk_widget_destroy(rpivbox_ptr->vbox);
        g_free(rpivbox_ptr->frame_top);
        g_free(rpivbox_ptr->menu_bar);
        g_free(rpivbox_ptr->vbox);
        g_free(rpivbox_ptr);
    }
}

