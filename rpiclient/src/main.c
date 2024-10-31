/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
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

#include "home/home.h"
#include "exit/exit_dialog.h"
#include "about/about_dialog.h"

/*ServerParameters *server_parameters;*/
/*GThreadParameters *gthread_parameters;*/
gchar *resource_dir_path = NULL;
gchar *config_dir_path = NULL;
Home *app = NULL;
ExitDialog *exit_dlg = NULL;
AboutDialog *about_dlg = NULL;

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    gint exit_code = show_exit_dialog(exit_dlg);

    if (exit_code == 0)
    {
        destroy_home(app);
        gtk_main_quit();
        return FALSE;
    }

    return TRUE;
}

void on_show_about(GtkWidget *widget, gpointer data)
{
    show_about_dialog(about_dlg);
}

int main(int argc, char *argv[])
{
    // g_thread_init(NULL);
    // gdk_threads_init();
    // gdk_threads_enter();

    gtk_init(&argc, &argv);
    resource_dir_path = get_resource_dir();
    config_dir_path = get_config_dir();
    app = new_home();
    exit_dlg = new_exit_dialog(app->window);
    about_dlg = new_about_dialog();
    show_home(app);
    g_signal_connect(G_OBJECT(app->window), "delete_event", G_CALLBACK(delete_event), NULL);

    // g_signal_connect(G_OBJECT(app->menu_bar->menu_help_submenu_about), "activate", G_CALLBACK(on_show_about), NULL);
    // yes_tid = g_thread_create(readSocket, NULL, FALSE, NULL);

    gtk_main();

    // gdk_threads_leave();

    return 0;
}
