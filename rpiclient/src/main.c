/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
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
#include "exitdialog.h"
#include "aboutdialog.h"

/*ServerParameters *server_parameters;*/
/*GThreadParameters *gthread_parameters;*/

RPIClient *app;
ExitDialog *exit_dlg;
AboutDialog *about_dlg;

void ExitCall(GtkWidget *widget, gpointer data) {
    gint exit_code = show_exit_dialog(exit_dlg);
    if(exit_code == 0) {
        destroy_rpiclient(app);
        gtk_main_quit();
    }
}

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    gint exit_code = show_exit_dialog(exit_dlg);
    if(exit_code == 0) {
        return (FALSE);
    }
    return(TRUE);
}

void showAbout(GtkWidget *widget, gpointer data) {
    show_about_dialog(about_dlg);
}

int main(int argc, char *argv[]) {
    //g_thread_init(NULL);
    //gdk_threads_init();
    //gdk_threads_enter();
    gtk_init(&argc, &argv);
    app = new_rpiclient();
    exit_dlg = new_exit_dialog(app->window);
    about_dlg = new_about_dialog();
    show_rpiclient(app);
/*    g_signal_connect(*/
/*        G_OBJECT(rpiclient_ptr->quit), "button-press-event",*/
/*        G_CALLBACK(destroy), NULL*/
/*    );*/
    gtk_signal_connect(
        GTK_OBJECT(app->window), "delete_event",
        GTK_SIGNAL_FUNC(delete_event), NULL
    );
    g_signal_connect(
        G_OBJECT(app->rpivbox_top->menu_bar->about_item->about_subitem), "activate",
        G_CALLBACK(showAbout), NULL
    );
    g_signal_connect(
        G_OBJECT(app->window), "destroy",
        G_CALLBACK(ExitCall), NULL
    );
    //yes_tid = g_thread_create(readSocket, NULL, FALSE, NULL);
    gtk_main();
    //gdk_threads_leave();
    return 0;
}

