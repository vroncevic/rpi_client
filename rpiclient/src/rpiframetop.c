/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiframetop.c
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
#include "rpiframetop.h"

RPIFrameTop * new_rpiframetop() {
    RPIFrameTop *rpiframetop_ptr = g_malloc(sizeof(RPIFrameTop));
    rpiframetop_ptr->frame = gtk_frame_new("");
    rpiframetop_ptr->vpaned = gtk_vpaned_new();
    gtk_frame_set_shadow_type(GTK_FRAME(rpiframetop_ptr->frame), GTK_SHADOW_IN);
    gtk_container_add(
        GTK_CONTAINER(rpiframetop_ptr->frame), rpiframetop_ptr->vpaned
    );
    rpiframetop_ptr->frame_get = new_rpiframeget();
    gtk_paned_add1(
        GTK_PANED(rpiframetop_ptr->vpaned), rpiframetop_ptr->frame_get->frame
    );
    rpiframetop_ptr->frame_set = new_rpiframeset();
    gtk_paned_add2(
        GTK_PANED(rpiframetop_ptr->vpaned), rpiframetop_ptr->frame_set->frame
    );
    return rpiframetop_ptr;
}

void show_rpiframetop(RPIFrameTop *rpiframetop_ptr) {
    if(rpiframetop_ptr) {
        gtk_widget_show_all(rpiframetop_ptr->frame);
    }
}

void hide_rpiframetop(RPIFrameTop *rpiframetop_ptr) {
    if(rpiframetop_ptr) {
        gtk_widget_hide_all(rpiframetop_ptr->frame);
    }
}

void destroy_rpiframetop(RPIFrameTop *rpiframetop_ptr) {
    if(rpiframetop_ptr) {
        destroy_rpiframeget(rpiframetop_ptr->frame_get);
        destroy_rpiframeset(rpiframetop_ptr->frame_set);
        gtk_widget_destroy(rpiframetop_ptr->frame);
        g_free(rpiframetop_ptr->frame_get);
        g_free(rpiframetop_ptr->frame_set);
        g_free(rpiframetop_ptr->frame);
        g_free(rpiframetop_ptr);
    }
}

