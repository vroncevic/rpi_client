/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpifixedget.c
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
#include "rpifixedget.h"

RPIFixedGet * new_rpifixedget() {
    RPIFixedGet *rpifixedget_ptr = g_malloc(sizeof(RPIFixedGet));
    rpifixedget_ptr->fixed = gtk_fixed_new();
    gint i;
    gint x_pos_vbar = START_X_POSITION_VERTICAL_BAR_GET;
    gint x_pos_activate_channel = START_X_POSITION_ACTIVATE_CHANNEL_GET;
    gint x_pos_label = START_X_POSITION_LABEL_GET;
    for(i = 0; i < MAX_CHANNELS_GET; i++) {
        rpifixedget_ptr->rpichannel_get[i] = new_rpichannelget(i);
        gtk_fixed_put(
            GTK_FIXED(rpifixedget_ptr->fixed),
            rpifixedget_ptr->rpichannel_get[i]->vbar_get,
            x_pos_vbar, Y_POSITION_VERTICAL_BAR_GET
        );
        x_pos_vbar += SHIFT_X_POSITION_GET;
        gtk_fixed_put(
            GTK_FIXED(rpifixedget_ptr->fixed),
            rpifixedget_ptr->rpichannel_get[i]->activate_channel,
            x_pos_activate_channel, Y_POSITION_ACTIVATE_CHANNEL_GET
        );
        x_pos_activate_channel += SHIFT_X_POSITION_GET;
        gtk_fixed_put(
            GTK_FIXED(rpifixedget_ptr->fixed),
            rpifixedget_ptr->rpichannel_get[i]->label,
            x_pos_label, Y_POSITION_LABEL_GET
        );
        x_pos_label += SHIFT_X_POSITION_GET;
    }
    return rpifixedget_ptr;
}

void show_rpifixedget(RPIFixedGet *rpifixedget_ptr) {
    if(rpifixedget_ptr) {
        gtk_widget_show_all(rpifixedget_ptr->fixed);
    }
}

void hide_rpifixedget(RPIFixedGet *rpifixedget_ptr) {
    if(rpifixedget_ptr) {
        gtk_widget_hide_all(rpifixedget_ptr->fixed);
    }
}

void destroy_rpifixedget(RPIFixedGet *rpifixedget_ptr) {
    if(rpifixedget_ptr) {
        gint i;
        for(i = 0; i < MAX_CHANNELS_GET; i++) {
            destroy_rpichannelget(rpifixedget_ptr->rpichannel_get[i]);
            g_free(rpifixedget_ptr->rpichannel_get[i]);
        }
        gtk_widget_destroy(rpifixedget_ptr->fixed);
        g_free(rpifixedget_ptr->fixed);
        g_free(rpifixedget_ptr);
    }
}

