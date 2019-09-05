/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * exitdialog.c
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
#include "exitdialog.h"

ExitDialog * new_exit_dialog(GtkWidget *widget) {
    ExitDialog *exit_dialog_ptr = g_malloc(sizeof(ExitDialog));
    exit_dialog_ptr->dialog = gtk_dialog_new_with_buttons(
        TITLE_EXIT_DIALOG, GTK_WINDOW(widget), GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL,
        GTK_RESPONSE_REJECT, NULL
    );
    exit_dialog_ptr->content_area = gtk_dialog_get_content_area(
        GTK_DIALOG(exit_dialog_ptr->dialog)
    );
    exit_dialog_ptr->label = gtk_label_new(TEXT_EXIT_LABEL);
    gtk_container_add(
        GTK_CONTAINER(exit_dialog_ptr->content_area), exit_dialog_ptr->label
    );
    return exit_dialog_ptr;
}

gint show_exit_dialog(ExitDialog *exit_dialog_ptr) {
    if(exit_dialog_ptr->dialog) {
        gtk_widget_show_all(exit_dialog_ptr->dialog);
        gint result = gtk_dialog_run(GTK_DIALOG(exit_dialog_ptr->dialog));
        if(result == GTK_RESPONSE_ACCEPT) {
            destroy_exit_dialog(exit_dialog_ptr);
            return (0);
        }
        gtk_widget_hide_all(exit_dialog_ptr->dialog);
    }
    return (-1);
}

void hide_exit_dialog(ExitDialog *exit_dialog_ptr) {
    if(exit_dialog_ptr->dialog) {
        gtk_widget_hide_all(exit_dialog_ptr->dialog);
    }
}

void destroy_exit_dialog(ExitDialog *exit_dialog_ptr) {
    if(exit_dialog_ptr->dialog) {
        gtk_widget_destroy(exit_dialog_ptr->label);
        gtk_widget_destroy(exit_dialog_ptr->content_area);
        gtk_widget_destroy(exit_dialog_ptr->dialog);
        g_free(exit_dialog_ptr->label);
        g_free(exit_dialog_ptr->content_area);
        g_free(exit_dialog_ptr->dialog);
        g_free(exit_dialog_ptr);
    }
}

