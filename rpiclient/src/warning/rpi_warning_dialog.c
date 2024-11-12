/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_warning_dialog.c
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
#include "rpi_warning_dialog.h"

static const gchar* TEXT_TITLE_WARNING_DIALOG = "Warning!";
static const gchar* TEXT_SETUP_CONNECTION_SETTINGS_WARNING_DIALOG = "Please set ip address, port of server !";
static const gchar* TEXT_SETUP_CONNECTION_WARNING_DIALOG = "Please make connection\nGo to Option > Connection";
static const gchar* TEXT_ERROR_WARNING_DIALOG = "There was an error !";
static const gchar* WARNING_LOG_FAILED_PARENT_WARNINGS_DIALOG = "Missing parent widget parameter.\n";
static const gchar* WARNING_LOG_FAILED_MESSAGE_WARNINGS_DIALOG = "Missing message parameter.\n";
static const gchar* WARNING_LOG_FAILED_MALLOC_WARNINGS_DIALOG = "Failed to allocate memory for warning dialog.\n";

//////////////////////////////////////////////////////////////////////////////
/// @brief Warning dialog complex widget
///   dialog - Gtk warning dialog widget
struct _WarningDialog
{
    GtkWidget *dialog;
};

WarningDialog *new_warning_dialog(GtkWidget *parent, const gchar *msg)
{
    if (!parent)
    {
        g_warning("%s", WARNING_LOG_FAILED_PARENT_WARNINGS_DIALOG);
        return NULL;
    }

    if (!msg)
    {
        g_warning("%s", WARNING_LOG_FAILED_MESSAGE_WARNINGS_DIALOG);
        return NULL;
    }

    WarningDialog *instance = g_malloc(sizeof(WarningDialog));

    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_WARNINGS_DIALOG);
        return NULL;
    }

    instance->dialog = gtk_message_dialog_new(
        GTK_WINDOW(parent),
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_ERROR,
        GTK_BUTTONS_CLOSE,
        "%s",
        msg
    );

    if (!GTK_IS_MESSAGE_DIALOG(instance->dialog))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_WARNINGS_DIALOG);
        destroy_warning_dialog(instance);
        return NULL;
    }

    g_signal_connect_swapped(
        G_OBJECT(instance->dialog),
        "response",
        G_CALLBACK(destroy_warning_dialog),
        instance
    );

    return instance;
}

void show_warning_dialog(WarningDialog *instance)
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
                hide_warning_dialog(instance);
            }
        }
    }
}

void hide_warning_dialog(WarningDialog *instance)
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

void destroy_warning_dialog(WarningDialog *instance)
{
    if (instance)
    {
        if (GTK_IS_MESSAGE_DIALOG(instance->dialog))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->dialog));
            instance->dialog = NULL;
        }

        g_free(instance);
        instance = NULL;
    }
}
