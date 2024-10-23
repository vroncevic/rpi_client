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
#include "rpiclient.h"

void rpiclient_send_signal_connect(Home *rpiclient_ptr)
{
    if (rpiclient_ptr)
    {
        g_signal_connect(
            G_OBJECT(rpiclient_ptr->send2), "activate",
            G_CALLBACK(SendCommand), NULL);
    }
}

void SendCommand(GtkWidget *widget)
{
    /*    gint i;*/
    /*    for(i = 0; i < USED_PINS; i++) {*/
    /*        cmd_req = g_strjoin(NULL, cmd_req, rpi.pins[i], NULL);*/
    /*        if(i != 7) cmd_req = g_strjoin(NULL, cmd_req, SEPARATOR, NULL);*/
    /*    }*/
    /*    for(i = 0; i < USED_CHANNELS; i++) {*/
    /*        gchar buffer[4];*/
    /*        sprintf(buffer, "%d", rpi.channel_data[i]);*/
    /*        cmd_req = g_strjoin(NULL, cmd_req, SEPARATOR, NULL);*/
    /*        cmd_req = g_strjoin(NULL, cmd_req, buffer, NULL);*/
    /*    }*/
    /*    cmd_req  = g_strjoin(NULL, cmd_req, END_REQ, NULL);*/
    /*    gchar* server_data = rpi_encrypt(cmd_req, 3);*/
    /*    write(sockfd,server_data,strlen(server_data));*/
    /*    cmd_req = START_REQ;*/
}
