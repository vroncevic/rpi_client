/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiframeset.c
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
#include "rpiframeset.h"

RPIFrameSet * new_rpiframeset() {
    RPIFrameSet *rpiframeset_ptr = g_malloc(sizeof(RPIFrameSet));
    rpiframeset_ptr->frame = gtk_frame_new(TEXT_FRAME_SET);
    rpiframeset_ptr->fixed_set = new_rpifixedset();
    gtk_frame_set_shadow_type(
        GTK_FRAME(rpiframeset_ptr->frame), GTK_SHADOW_IN
    );
    gtk_container_add(
        GTK_CONTAINER(rpiframeset_ptr->frame), rpiframeset_ptr->fixed_set->fixed
    );
    return rpiframeset_ptr;
}

void show_rpiframeset(RPIFrameSet *rpiframeset_ptr) {
    if(rpiframeset_ptr) {
        gtk_widget_show_all(rpiframeset_ptr->frame);
    }
}

void hide_rpiframeset(RPIFrameSet *rpiframeset_ptr) {
    if(rpiframeset_ptr) {
        gtk_widget_hide_all(rpiframeset_ptr->frame);
    }
}

void destroy_rpiframeset(RPIFrameSet *rpiframeset_ptr) {
    if(rpiframeset_ptr) {
        destroy_rpifixedset(rpiframeset_ptr->fixed_set);
        gtk_widget_destroy(rpiframeset_ptr->frame);
        g_free(rpiframeset_ptr->fixed_set);
        g_free(rpiframeset_ptr->frame);
        g_free(rpiframeset_ptr);
    }
}

