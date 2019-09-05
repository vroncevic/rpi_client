/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpichannelget.h
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
#include "rpichannelget.h"

RPIChannelGet * new_rpichannelget(gint channel_id) {
    RPIChannelGet *rpichannelget_ptr = g_malloc(sizeof(RPIChannelGet));
    rpichannelget_ptr->activate_channel = gtk_check_button_new_with_label(
        TEXT_CHECK_BOX_CHANNEL(channel_id)
    );
    gtk_widget_set_tooltip_text(
        rpichannelget_ptr->activate_channel,
        TOOLTIP_CHECK_BOX_CHANNEL(channel_id)
    );
    gtk_toggle_button_set_active(
        GTK_TOGGLE_BUTTON(rpichannelget_ptr->activate_channel), FALSE
    );
    rpichannelget_ptr->vbar_get = gtk_vb_new();
    rpichannelget_ptr->label = gtk_label_new(TEXT_LABEL(channel_id));
    gtk_widget_set_tooltip_text(
        rpichannelget_ptr->vbar_get, TOOLTIP_VERTICAL_BAR(channel_id)
    );
    return rpichannelget_ptr;
}

void show_rpichannelget(RPIChannelGet *rpichannelget_ptr) {
    if(rpichannelget_ptr) {
        gtk_widget_show(rpichannelget_ptr->activate_channel);
        gtk_widget_show(rpichannelget_ptr->label);
        gtk_widget_show(rpichannelget_ptr->vbar_get);
    }
}

void hide_rpichannelget(RPIChannelGet *rpichannelget_ptr) {
    if(rpichannelget_ptr) {
        gtk_widget_hide(rpichannelget_ptr->activate_channel);
        gtk_widget_hide(rpichannelget_ptr->label);
        gtk_widget_hide(rpichannelget_ptr->vbar_get);
    }
}

void destroy_rpichannelget(RPIChannelGet *rpichannelget_ptr) {
    if(rpichannelget_ptr) {
        gtk_widget_destroy(rpichannelget_ptr->activate_channel);
        gtk_widget_destroy(rpichannelget_ptr->label);
        gtk_vb_destroy((GtkObject *)rpichannelget_ptr->vbar_get);
        g_free(rpichannelget_ptr->label);
        g_free(rpichannelget_ptr->activate_channel);
        g_free(rpichannelget_ptr->vbar_get);
        g_free(rpichannelget_ptr);
    }
}

