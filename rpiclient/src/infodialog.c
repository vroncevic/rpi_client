/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * infodialog.c
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
#include "infodialog.h"

InfoDialog * new_info_dialog(GtkWidget *parent, const gchar *msg) {
    InfoDialog *info_dialog_ptr = g_malloc(sizeof(InfoDialog));
    info_dialog_ptr->dialog = gtk_message_dialog_new(
        GTK_WINDOW(parent), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
        GTK_BUTTONS_CLOSE, msg
    );
    return info_dialog_ptr;
}

void show_info_dialog(InfoDialog *info_dialog_ptr) {
    if(info_dialog_ptr->dialog) {
        gtk_widget_show_all(info_dialog_ptr->dialog);
        gint result = gtk_dialog_run(GTK_DIALOG(info_dialog_ptr->dialog));
        if(result == GTK_RESPONSE_CLOSE) {
            hide_info_dialog(info_dialog_ptr);
        }
    }
}

void hide_info_dialog(InfoDialog *info_dialog_ptr) {
    if(info_dialog_ptr->dialog) {
        gtk_widget_hide_all(info_dialog_ptr->dialog);
    }
}

void destroy_info_dialog(InfoDialog *info_dialog_ptr) {
    if(info_dialog_ptr->dialog) {
        gtk_widget_destroy(info_dialog_ptr->dialog);
        g_free(info_dialog_ptr->dialog);
        g_free(info_dialog_ptr);
    }
}

