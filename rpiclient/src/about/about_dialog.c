/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * about_dialog.c
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
#include "about_dialog.h"

AboutDialog *new_about_dialog(void)
{
    AboutDialog *instance = g_malloc(sizeof(AboutDialog));

    if(!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_ABOUT_DIALOG);
        return NULL;
    }

    instance->dialog = gtk_about_dialog_new();

    if (!instance->dialog)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_ABOUT_DIALOG);
        g_free(instance);
        return NULL;
    }

    gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(instance->dialog), TEXT_NAME_ABOUT_DIALOG);
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(instance->dialog), TEXT_VERSION_ABOUT_DIALOG);
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(instance->dialog), TEXT_COPYRIGHT_ABOUT_DIALOG);
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(instance->dialog), TEXT_COMMENTS_ABOUT_DIALOG);
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(instance->dialog), TEXT_WEBSITE_ABOUT_DIALOG);

    const gchar *logo = get_resource_file(LOGO_FILE_NAME_ABOUT_DIALOG);

    if (logo)
    {
        GdkPixbuf *pixbuf = cpixbuf(logo);

        if (pixbuf)
        {
            gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(instance->dialog), pixbuf);
            g_object_unref(pixbuf);
        }
        else
        {
            g_warning(WARNING_LOG_FAILED_PIXBUF_ABOUT_DIALOG);
        }

        g_free(logo);
    }
    else
    {
        g_warning(WARNING_LOG_FAILED_RESOURCE_ABOUT_DIALOG);
    }

    g_signal_connect_swapped(instance->dialog, "response", G_CALLBACK(gtk_widget_hide), instance->dialog);

    return instance;
}

void show_about_dialog(AboutDialog *instance)
{
    if (instance && instance->dialog && !gtk_widget_get_visible(instance->dialog))
    {
        gtk_widget_show(instance->dialog);
    }
}

void hide_about_dialog(AboutDialog *instance)
{
    if (instance && instance->dialog && gtk_widget_get_visible(instance->dialog))
    {
        gtk_widget_hide(instance->dialog);
    }
}

void destroy_about_dialog(AboutDialog *instance)
{
    if (instance)
    {
        if (instance->dialog)
        {
            gtk_widget_destroy(instance->dialog);
            instance->dialog = NULL;
        }

        g_free(instance);
        instance = NULL;
    }
}
