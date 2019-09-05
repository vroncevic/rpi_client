/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * aboutdialog.c
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
#include "aboutdialog.h"

AboutDialog * new_about_dialog() {
    gchar * res_dir = g_strjoin(NULL, g_get_current_dir(), RESOURCE_PATH, NULL);
    AboutDialog *about_dialog_ptr = g_malloc(sizeof(AboutDialog));
    about_dialog_ptr->dialog = gtk_about_dialog_new();
    gtk_about_dialog_set_name(
        GTK_ABOUT_DIALOG(about_dialog_ptr->dialog), NAME_ABOUT
    );
    gtk_about_dialog_set_version(
        GTK_ABOUT_DIALOG(about_dialog_ptr->dialog), VERSION_ABOUT
    );
    gtk_about_dialog_set_copyright(
        GTK_ABOUT_DIALOG(about_dialog_ptr->dialog), COPYRIGHT_ABOUT
    );
    gtk_about_dialog_set_comments(
        GTK_ABOUT_DIALOG(about_dialog_ptr->dialog), COMMENTS_ABOUT
    );
    gtk_about_dialog_set_website(
        GTK_ABOUT_DIALOG(about_dialog_ptr->dialog), WEBSITE_ABOUT
    );
    const gchar * logo_img = g_strjoin(NULL, res_dir, "logo.png", NULL);
    gtk_about_dialog_set_logo(
        GTK_ABOUT_DIALOG(about_dialog_ptr->dialog), cpixbuf(logo_img)
    );
    g_signal_connect_swapped(
        about_dialog_ptr->dialog, "response",
        G_CALLBACK(gtk_widget_hide), about_dialog_ptr->dialog
    );
    return about_dialog_ptr;
}

void show_about_dialog(AboutDialog *about_dialog_ptr) {
    if(about_dialog_ptr->dialog) {
        gtk_widget_show_all(about_dialog_ptr->dialog);
    }
}

void hide_about_dialog(AboutDialog *about_dialog_ptr) {
    if(about_dialog_ptr->dialog) {
        gtk_widget_hide_all(about_dialog_ptr->dialog);
    }
}

void destroy_about_dialog(AboutDialog *about_dialog_ptr) {
    if(about_dialog_ptr->dialog) {
        gtk_widget_destroy(about_dialog_ptr->dialog);
        g_free(about_dialog_ptr->dialog);
        g_free(about_dialog_ptr);
    }
}

