/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiclient_spinbutton_signal_connect.c
 * Copyright (C) 2016 - 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
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
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
// #include "rpiclient.h"

// enum
// {
//     CHECK_1 = 0,
//     CHECK_2,
//     CHECK_3,
//     CHECK_4,
//     CHECK_5,
//     CHECK_6,
//     CHECK_7,
//     CHECK_8,
//     CHECKCH_1,
//     CHECKCH_2,
//     CHECKCH_3,
//     CHECKCH_4,
//     CHECKCH_5,
//     CHECKCH_6,
//     CHECKCH_7,
//     CHECKCH_8
// };

// void rpiclient_channel_signal_connect(Home *rpiclient_ptr)
// {
//     if (rpiclient_ptr)
//     {
//         g_signal_connect(
//             G_OBJECT(rpiclient_ptr->About), "button-press-event",
//             G_CALLBACK(rpi_about), NULL);
//     }
// }

// void CheckCH(GtkToggleButton *button, gpointer data)
// {
//     gint control = (gint)data;
//     if (control == CHECKCH_1)
//     {
//         if (button->active)
//             rpi.channels[0] = ACTIVE_CHANNEL_1;
//         if (!(button->active))
//             rpi.channels[0] = DEACTIVE_CHANNEL_1;
//     }
//     if (control == CHECKCH_2)
//     {
//         if (button->active)
//             rpi.channels[1] = ACTIVE_CHANNEL_2;
//         if (!(button->active))
//             rpi.channels[1] = DEACTIVE_CHANNEL_2;
//     }
//     if (control == CHECKCH_3)
//     {
//         if (button->active)
//             rpi.channels[2] = ACTIVE_CHANNEL_3;
//         if (!(button->active))
//             rpi.channels[2] = DEACTIVE_CHANNEL_3;
//     }
//     if (control == CHECKCH_4)
//     {
//         if (button->active)
//             rpi.channels[3] = ACTIVE_CHANNEL_4;
//         if (!(button->active))
//             rpi.channels[3] = DEACTIVE_CHANNEL_4;
//     }
//     if (control == CHECKCH_5)
//     {
//         if (button->active)
//             rpi.channels[4] = ACTIVE_CHANNEL_5;
//         if (!(button->active))
//             rpi.channels[4] = DEACTIVE_CHANNEL_5;
//     }
//     if (control == CHECKCH_6)
//     {
//         if (button->active)
//             rpi.channels[5] = ACTIVE_CHANNEL_6;
//         if (!(button->active))
//             rpi.channels[5] = DEACTIVE_CHANNEL_6;
//     }
//     if (control == CHECKCH_7)
//     {
//         if (button->active)
//             rpi.channels[6] = ACTIVE_CHANNEL_7;
//         if (!(button->active))
//             rpi.channels[6] = DEACTIVE_CHANNEL_7;
//     }
//     if (control == CHECKCH_8)
//     {
//         if (button->active)
//             rpi.channels[7] = ACTIVE_CHANNEL_8;
//         if (!(button->active))
//             rpi.channels[7] = DEACTIVE_CHANNEL_8;
//     }
// }
