/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiclient_spinbutton_signal_connect.c
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
#include "rpiclient.h"

enum {
    CHECK_1 = 0,
    CHECK_2,
    CHECK_3,
    CHECK_4,
    CHECK_5,
    CHECK_6,
    CHECK_7,
    CHECK_8,
    CHECKCH_1,
    CHECKCH_2,
    CHECKCH_3,
    CHECKCH_4,
    CHECKCH_5,
    CHECKCH_6,
    CHECKCH_7,
    CHECKCH_8
};

void rpiclient_gpio_signal_connect(RPIClient *rpiclient_ptr) {
    if(rpiclient_ptr) {
        g_signal_connect(
            G_OBJECT(rpiclient_ptr->About), "button-press-event",
            G_CALLBACK(rpi_about), NULL
        );
    }
}

void Check(GtkToggleButton *button, gpointer data) {
    gint control = (gint) data;
    if(control == CHECK_1) {
         if(button->active)  rpi.pins[0] = ACT_PIN_1;
         if(!(button->active))  rpi.pins[0] = DEACT_PIN_1;
    }
    if(control == CHECK_2) {
        if(button->active)  rpi.pins[1] = ACT_PIN_2;
        if(!(button->active))  rpi.pins[1] = DEACT_PIN_2;
    }
    if(control == CHECK_3) {
        if(button->active)  rpi.pins[2] = ACT_PIN_3;
        if(!(button->active))  rpi.pins[2] = DEACT_PIN_3;
    }
    if(control == CHECK_4) {
        if(button->active)  rpi.pins[3] = ACT_PIN_4;
        if(!(button->active))  rpi.pins[3] = DEACT_PIN_4;
    }
    if(control == CHECK_5) {
        if(button->active)  rpi.pins[4] = ACT_PIN_5;
        if(!(button->active))  rpi.pins[4] = DEACT_PIN_5;
    }
    if(control == CHECK_6) {
        if(button->active)  rpi.pins[5] = ACT_PIN_6;
        if(!(button->active))  rpi.pins[5] = DEACT_PIN_6;
    }
    if(control == CHECK_7) {
        if(button->active)  rpi.pins[6] = ACT_PIN_7;
        if(!(button->active))  rpi.pins[6] = DEACT_PIN_7;
    }
    if(control == CHECK_8) {
        if(button->active)  rpi.pins[7] = ACT_PIN_8;
        if(!(button->active))  rpi.pins[7] = DEACT_PIN_8;
    }
}

