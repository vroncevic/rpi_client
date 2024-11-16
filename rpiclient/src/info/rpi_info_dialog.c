/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_info_dialog.c
 * Copyright (C) 2016 - 2025 Vladimir Roncevic <elektron.ronca@gmail.com>
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
#include "../rpi_config.h"
#include "rpi_info_dialog.h"

#if RPI_VERBOSE == 1
#define CLOSE_INFO_DIALOG "Close info dialog.\n"
#endif

#define MISSING_PARENT_INFO_DIALOG "Missing parent widget parameter.\n"
#define MISSING_MESSAGE_INFO_DIALOG "Missing message parameter.\n"

#define FAILED_MALLOC_INFO_DIALOG "Failed to allocate memory for info dialog.\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Info dialog complex widget
///   dialog - Gtk dialog widget
struct _InfoDialog
{
    GtkWidget *dialog;
};

InfoDialog *new_info_dialog(GtkWidget *parent, const gchar *msg)
{
    if (!parent)
    {
        g_critical(MISSING_PARENT_INFO_DIALOG);
        return NULL;
    }

    if (!msg)
    {
        g_critical(MISSING_MESSAGE_INFO_DIALOG);
        return NULL;
    }

    InfoDialog *instance = g_malloc(sizeof(InfoDialog));

    if (!instance)
    {
        g_critical(FAILED_MALLOC_INFO_DIALOG);
        return NULL;
    }

    instance->dialog = gtk_message_dialog_new(
        GTK_WINDOW(parent),
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_CLOSE,
        "%s",
        msg
    );

    if (!GTK_IS_MESSAGE_DIALOG(instance->dialog))
    {
        g_critical(FAILED_MALLOC_INFO_DIALOG);
        destroy_info_dialog(instance);
        return NULL;
    }

    g_signal_connect_swapped(
        G_OBJECT(instance->dialog), "response", G_CALLBACK(destroy_info_dialog), instance
    );

    return instance;
}

void show_info_dialog(InfoDialog *instance)
{
    if (instance)
    {
        gboolean is_message_dialog = GTK_IS_MESSAGE_DIALOG(instance->dialog);
        gboolean is_message_dialog_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->dialog));

        if (is_message_dialog && is_message_dialog_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->dialog));
            gint result = gtk_dialog_run(GTK_DIALOG(instance->dialog));

            if (result == GTK_RESPONSE_CLOSE)
            {
                hide_info_dialog(instance);

#if RPI_VERBOSE == 1
                g_debug(CLOSE_INFO_DIALOG);
#endif

            }
        }
    }
}

void hide_info_dialog(InfoDialog *instance)
{
    if (instance)
    {
        gboolean is_message_dialog = GTK_IS_MESSAGE_DIALOG(instance->dialog);
        gboolean is_message_dialog_visible = gtk_widget_get_visible(GTK_WIDGET(instance->dialog));

        if (is_message_dialog && is_message_dialog_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->dialog));
        }
    }
}

void destroy_info_dialog(InfoDialog *instance)
{
    if (instance)
    {
        if (GTK_IS_MESSAGE_DIALOG(instance->dialog))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->dialog));
            instance->dialog = NULL;
        }

        g_free(instance);
    }
}
