/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpifixedset.c
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
#include "rpifixedset.h"

RPIFixedSet * new_rpifixedset() {
    RPIFixedSet *rpifixedset_ptr = g_malloc(sizeof(RPIFixedSet));
    rpifixedset_ptr->fixed = gtk_fixed_new();
    gint i;
    gint x_pos_vbar = START_X_POSITION_VERTICAL_BAR_SET;
    gint x_pos_scale = START_X_POSITION_SCALE_SET;
    gint x_pos_spiner_button = START_X_POSITION_SPINER_BUTTON_SET;
    gint x_pos_activate_gpio = START_X_POSITION_ACTIVATE_GPIO_SET;
    for(i = 0; i < MAX_CHANNELS_SET; i++) {
        rpifixedset_ptr->rpichannel_set[i] = new_rpichannelset(i+1);
        gtk_fixed_put(
            GTK_FIXED(rpifixedset_ptr->fixed),
            rpifixedset_ptr->rpichannel_set[i]->vbar_set, x_pos_vbar,
            Y_POSITION_VERTICAL_BAR_SET
        );
        x_pos_vbar += SHIFT_X_POSITION_SET;
        gtk_fixed_put(
            GTK_FIXED(rpifixedset_ptr->fixed),
            rpifixedset_ptr->rpichannel_set[i]->scale, x_pos_scale,
            Y_POSITION_SCALE_SET
        );
        x_pos_scale += SHIFT_X_POSITION_SET;
        gtk_fixed_put(
            GTK_FIXED(rpifixedset_ptr->fixed),
            rpifixedset_ptr->rpichannel_set[i]->spinner_button,
            x_pos_spiner_button, Y_POSITION_SPINER_BUTTON_SET
        );
        x_pos_spiner_button += SHIFT_X_POSITION_SET;
        gtk_fixed_put(
            GTK_FIXED(rpifixedset_ptr->fixed),
            rpifixedset_ptr->rpichannel_set[i]->activate_gpio,
            x_pos_activate_gpio, Y_POSITION_ACTIVATE_GPIO_SET
        );
        x_pos_activate_gpio += SHIFT_X_POSITION_SET;
    }
    return rpifixedset_ptr;
}

void show_rpifixedset(RPIFixedSet *rpifixedset_ptr) {
    if(rpifixedset_ptr) {
        gtk_widget_show_all(rpifixedset_ptr->fixed);
    }
}

void hide_rpifixedset(RPIFixedSet *rpifixedset_ptr) {
    if(rpifixedset_ptr) {
        gtk_widget_hide_all(rpifixedset_ptr->fixed);
    }
}

void destroy_rpifixedset(RPIFixedSet *rpifixedset_ptr) {
    if(rpifixedset_ptr) {
        gint i;
        for(i = 0; i < MAX_CHANNELS_SET; i++) {
            destroy_rpichannelset(rpifixedset_ptr->rpichannel_set[i]);
            g_free(rpifixedset_ptr->rpichannel_set[i]);
        }
        gtk_widget_destroy(rpifixedset_ptr->fixed);
        g_free(rpifixedset_ptr->fixed);
        g_free(rpifixedset_ptr);
    }
}

