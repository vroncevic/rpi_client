/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * exit_dialog.c
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
#include "exit_dialog.h"

ExitDialog *new_exit_dialog(GtkWidget *parent)
{
    if (!parent)
    {
        g_warning(WARNING_LOG_FAILED_PARENT_EXIT_DIALOG);
        return NULL;
    }

    ExitDialog *instance = g_malloc(sizeof(ExitDialog));

    if (!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_EXIT_DIALOG);
        return NULL;
    }

    instance->dialog = gtk_dialog_new_with_buttons(
        TITLE_EXIT_DIALOG, GTK_WINDOW(parent), GTK_DIALOG_DESTROY_WITH_PARENT,
        "OK", GTK_RESPONSE_ACCEPT, "Cancel", GTK_RESPONSE_REJECT, NULL
    );

    if (!instance->dialog)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_EXIT_DIALOG);
        g_free((gpointer)instance);
        return NULL;
    }

    instance->content_area = gtk_dialog_get_content_area(GTK_DIALOG(instance->dialog));

    if (!instance->content_area)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_EXIT_DIALOG);
        destroy_exit_dialog(instance);
        return NULL;
    }

    instance->label = gtk_label_new(TEXT_LABEL_EXIT_DIALOG);

    if (!instance->label)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_EXIT_DIALOG);
        destroy_exit_dialog(instance);
        return NULL;
    }

    gtk_container_add(GTK_CONTAINER(instance->content_area), instance->label);

    return instance;
}

gint show_exit_dialog(ExitDialog *instance)
{
    if (instance && GTK_IS_DIALOG(instance->dialog) && !gtk_widget_get_visible(instance->dialog))
    {
        gtk_widget_show(instance->dialog);
        gint result = gtk_dialog_run(GTK_DIALOG(instance->dialog));

        if (result == GTK_RESPONSE_ACCEPT)
        {
            destroy_exit_dialog(instance);
            return (0);
        }

        hide_exit_dialog(instance);
    }

    return (-1);
}

void hide_exit_dialog(ExitDialog *instance)
{
    if (instance && GTK_IS_DIALOG(instance->dialog) && gtk_widget_get_visible(instance->dialog))
    {
        gtk_widget_hide(instance->dialog);
    }
}

void destroy_exit_dialog(ExitDialog *instance)
{
    if (instance)
    {
        if (GTK_IS_DIALOG(instance->dialog))
        {
            gtk_widget_destroy(instance->dialog);
            instance->dialog = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
