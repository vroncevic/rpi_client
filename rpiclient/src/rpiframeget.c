/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiframeget.c
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
#include "rpiframeget.h"

RPIFrameGet * new_rpiframeget() {
    RPIFrameGet *rpiframeget_ptr = g_malloc(sizeof(RPIFrameGet));
    rpiframeget_ptr->frame = gtk_frame_new(TEXT_FRAME_GET);
    rpiframeget_ptr->fixed_get = new_rpifixedget();
    gtk_frame_set_shadow_type(
        GTK_FRAME(rpiframeget_ptr->frame), GTK_SHADOW_IN
    );
    gtk_container_add(
        GTK_CONTAINER(rpiframeget_ptr->frame), rpiframeget_ptr->fixed_get->fixed
    );
    return rpiframeget_ptr;
}

void show_rpiframeget(RPIFrameGet *rpiframeget_ptr) {
    if(rpiframeget_ptr) {
        gtk_widget_show_all(rpiframeget_ptr->frame);
    }
}

void hide_rpiframeget(RPIFrameGet *rpiframeget_ptr) {
    if(rpiframeget_ptr) {
        gtk_widget_hide_all(rpiframeget_ptr->frame);
    }
}

void destroy_rpiframeget(RPIFrameGet *rpiframeget_ptr) {
    if(rpiframeget_ptr) {
        destroy_rpifixedget(rpiframeget_ptr->fixed_get);
        gtk_widget_destroy(rpiframeget_ptr->frame);
        g_free(rpiframeget_ptr->fixed_get);
        g_free(rpiframeget_ptr->frame);
        g_free(rpiframeget_ptr);
    }
}

