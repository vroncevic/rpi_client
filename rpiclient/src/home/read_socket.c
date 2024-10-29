/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * readsocket.c
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
#include "../resource/resource.h"

gpointer read_socket(gpointer args)
{
    /*    portno = atoi(RPI_PORT_NUMBER_SERVER);*/
    /*    sockfd = socket(AF_INET, SOCK_STREAM, 0);*/
    /*    if(sockfd < 0) {*/
    /*        errormsg("ERROR opening socket");*/
    /*    }*/
    /*    server = gethostbyname(RPI_SERVER_ADDRESS);*/
    /*    if(server == NULL) {*/
    /*        errormsg("ERROR, no such host");*/
    /*    }*/
    /*    bzero((gchar* ) &serv_addr, sizeof(serv_addr));*/
    /*    serv_addr.sin_family = AF_INET;*/
    /*    bcopy((gchar* )server->h_addr, (gchar* )&serv_addr.sin_addr.s_addr, server->h_length);*/
    /*    serv_addr.sin_port = htons(portno);*/
    /*    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {*/
    /*        errormsg("ERROR connecting");*/
    /*    }*/
    /*    */
    /*    //  static int current_number = 0;*/
    /*    //  int ret_val;*/
    /*    //  gchar buffer[255];*/
    /*    //  static GStaticMutex mutex = G_STATIC_MUTEX_INIT;*/
    /*    while(1) {*/

    /*        gdk_threads_enter();*/
    /*        //    g_static_mutex_lock (&mutex);*/
    /*        //    read(sockfd, buffer, sizeof(buffer));*/
    /*        //    FILE *op;*/
    /*        //    op = fopen("/home/quake/workspace/projects/Home/Debug/data", "wb");*/
    /*        //    fputs(buffer, op);*/
    /*        //    fflush(op);*/
    /*        //    fclose(op);*/
    /*        //    g_static_mutex_unlock (&mutex);*/

    /*        gdk_threads_leave();*/
    /*    }*/
    return NULL;
}
