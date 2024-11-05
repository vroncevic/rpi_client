/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_general_window.c
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
#include "settings_general_window.h"

SettingsGeneralWindow *new_settings_general_window(void)
{
    SettingsGeneralWindow *instance = g_malloc(sizeof(SettingsGeneralWindow));

    if (!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW);
        return NULL;
    }

    instance->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    if (!instance->window)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW);
        destroy_settings_general_window(instance);
        return NULL;
    }

    gtk_window_set_position(GTK_WINDOW(instance->window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(instance->window), WIDTH_SETTINGS_GENERAL_WINDOW, HEIGHT_SETTINGS_GENERAL_WINDOW);
    gtk_window_set_title(GTK_WINDOW(instance->window), TITLE_SETTINGS_GENERAL_WINDOW);
    const gchar *icon = get_resource_file(ICON_SETTINGS_GENERAL_WINDOW);

    if (icon)
    {
        GdkPixbuf *pixbuf = cpixbuf(icon);

        if (pixbuf)
        {
            gtk_window_set_icon(GTK_WINDOW(instance->window), pixbuf);
            g_object_unref(pixbuf);
        }
        else
        {
            g_warning(WARNING_LOG_FAILED_PIXBUF_SETTINGS_GENERAL_WINDOW);
        }

        g_free((gpointer)icon);
        icon = NULL;
    }
    else
    {
        g_warning(WARNING_LOG_FAILED_RESOURCE_SETTINGS_GENERAL_WINDOW);
        icon = NULL;
    }

    gtk_window_set_resizable(GTK_WINDOW(instance->window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(instance->window), CONTAINER_BORDER_WIDTH_SETTINGS_GENERAL_WINDOW);
    instance->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACING_VBOX_SETTINGS_GENERAL_WINDOW);

    if (!instance->vbox)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW);
        destroy_settings_general_window(instance);
        return NULL;
    }

    gtk_container_add(GTK_CONTAINER(instance->window), instance->vbox);
    instance->table = gtk_grid_new();

    if (!instance->table)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW);
        destroy_settings_general_window(instance);
        return NULL;
    }

    gtk_grid_set_row_spacing(GTK_GRID(instance->table), TABLE_ROW_SPACINGS_TABLE_SETTINGS_GENERAL_WINDOW);
    gtk_grid_set_column_spacing(GTK_GRID(instance->table), TABLE_COL_SPACINGS_TABLE_SETTINGS_GENERAL_WINDOW);
    gtk_box_pack_start(GTK_BOX(instance->vbox), instance->table, TRUE, TRUE, 0);
    instance->hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, SPACING_HBOX_SETTINGS_GENERAL_WINDOW);

    if (!instance->hbox)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW);
        destroy_settings_general_window(instance);
        return NULL;
    }

    instance->button_ok = gtk_button_new_with_label(TEXT_BUTTON_OK_HBOX_SETTINGS_GENERAL_WINDOW);

    if (!instance->button_ok)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW);
        destroy_settings_general_window(instance);
        return NULL;
    }

    instance->button_cancel = gtk_button_new_with_label(TEXT_BUTTON_CANCEL_HBOX_SETTINGS_GENERAL_WINDOW);

    if (!instance->button_cancel)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW);
        destroy_settings_general_window(instance);
        return NULL;
    }

    gtk_widget_set_size_request(instance->button_ok, WIDTH_BUTTON_HBOX_SETTINGS_GENERAL_WINDOW, HEIGHT_BUTTON_HBOX_SETTINGS_GENERAL_WINDOW);
    gtk_widget_set_size_request(instance->button_cancel, WIDTH_BUTTON_HBOX_SETTINGS_GENERAL_WINDOW, HEIGHT_BUTTON_HBOX_SETTINGS_GENERAL_WINDOW);
    gtk_container_add(GTK_CONTAINER(instance->hbox), instance->button_ok);
    gtk_container_add(GTK_CONTAINER(instance->hbox), instance->button_cancel);
    gtk_box_pack_start(GTK_BOX(instance->vbox), instance->hbox, FALSE, FALSE, 0);
    g_signal_connect_swapped(instance->window, "delete-event", G_CALLBACK(destroy_settings_general_window), instance);

    return instance;
}

void show_settings_general_window(SettingsGeneralWindow *instance)
{
    if (instance && instance->window && !gtk_widget_get_visible(instance->window))
    {
        gtk_widget_show_all(instance->window);
    }
}

void hide_settings_general_window(SettingsGeneralWindow *instance)
{
    if (instance && instance->window && gtk_widget_get_visible(instance->window))
    {
        gtk_widget_hide(instance->window);
    }
}

void destroy_settings_general_window(SettingsGeneralWindow *instance)
{
    if (instance)
    {
        if (instance->window)
        {
            gtk_widget_destroy(instance->window);
            instance->button_cancel = NULL;
            instance->button_ok = NULL;
            instance->hbox = NULL;
            instance->table = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }    
}
