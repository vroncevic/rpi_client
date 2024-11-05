/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_network_window.c
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
#include "settings_network_window.h"

SettingsNetworkWindow *new_settings_network_window(void)
{
    SettingsNetworkWindow *instance = g_malloc(sizeof(SettingsNetworkWindow));

    if (!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        return NULL;
    }

    instance->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    if (!instance->window)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_window_set_position(GTK_WINDOW(instance->window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(instance->window),WIDTH_SETTINGS_NETWORK_WINDOW, HEIGHT_SETTINGS_NETWORK_WINDOW);
    gtk_window_set_title(GTK_WINDOW(instance->window), TITLE_SETTINGS_NETWORK_WINDOW);
    const gchar *icon = get_resource_file(ICON_SETTINGS_NETWORK_WINDOW);

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
            g_warning(WARNING_LOG_FAILED_PIXBUF_SETTINGS_NETWORK_WINDOW);
        }

        g_free((gpointer)icon);
        icon = NULL;
    }
    else
    {
        g_warning(WARNING_LOG_FAILED_RESOURCE_SETTINGS_NETWORK_WINDOW);
        icon = NULL;
    }

    gtk_window_set_resizable(GTK_WINDOW(instance->window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(instance->window), CONTAINER_BORDER_WIDTH_SETTINGS_NETWORK_WINDOW);
    instance->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACING_VBOX_SETTINGS_NETWORK_WINDOW);

    if (!instance->vbox)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_container_add(GTK_CONTAINER(instance->window), instance->vbox);
    instance->table = gtk_grid_new();

    if (!instance->table)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_grid_set_row_spacing(GTK_GRID(instance->table), TABLE_ROW_SPACINGS_TABLE_SETTINGS_NETWORK_WINDOW);
    gtk_grid_set_column_spacing(GTK_GRID(instance->table), TABLE_COL_SPACINGS_TABLE_SETTINGS_NETWORK_WINDOW);
    instance->frame_control_exit = gtk_frame_new(TEXT_FRAME_CONTORL_EXIT_SETTINGS_NETWORK_WINDOW);

    if (!instance->frame_control_exit)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_control_exit), GTK_SHADOW_IN);
    instance->check_button = gtk_check_button_new_with_label(TEXT_CHECK_BUTTON_CONTROL_EXIT_SETTINGS_NETWORK_WINDOW);

    if (!instance->check_button)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(instance->check_button), TRUE);
    gtk_container_add(GTK_CONTAINER(instance->frame_control_exit), instance->check_button);
    instance->frame_entry_address = gtk_frame_new(TEXT_FRAME_ENTRY_ADDRESS_SETTINGS_NETWORK_WINDOW);

    if (!instance->frame_entry_address)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_entry_address), GTK_SHADOW_IN);
    instance->entry_address = gtk_entry_new();

    if (!instance->entry_address)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_entry_set_max_length(GTK_ENTRY(instance->entry_address), MAX_LENGTH_ENTRY_ADDRESS_SETTINGS_NETWORK_WINDOW);
    gint len_address = g_utf8_strlen(gtk_entry_get_text(GTK_ENTRY(instance->entry_address)), -1);
    instance->cur_pos_address = len_address;
    gtk_editable_insert_text(
        GTK_EDITABLE(instance->entry_address), TEXT_EXAMPLE_ENTRY_ADDRESS_SETTINGS_NETWORK_WINDOW,
        NEW_TEXT_LENGTH_ENTRY_ADDRESS_SETTINGS_NETWORK_WINDOW, &(instance->cur_pos_address)
    );
    gtk_editable_select_region(GTK_EDITABLE(instance->entry_address), START_POSITION_ENTRY_ADDRESS_SETTINGS_NETWORK_WINDOW, len_address);
    gtk_container_add(GTK_CONTAINER(instance->frame_entry_address), instance->entry_address);
    instance->frame_entry_port = gtk_frame_new(TEXT_FRAME_ENTRY_PORT_SETTINGS_NETWORK_WINDOW);

    if (!instance->frame_entry_port)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_entry_port), GTK_SHADOW_IN);
    instance->entry_port = gtk_entry_new();

    if (!instance->entry_port)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_entry_set_max_length(GTK_ENTRY(instance->entry_port), MAX_LENGTH_ENTRY_PORT_SETTINGS_NETWORK_WINDOW);
    gint len_port = g_utf8_strlen(gtk_entry_get_text(GTK_ENTRY(instance->entry_port)), -1);
    instance->cur_pos_port = len_port;
    gtk_editable_insert_text(
        GTK_EDITABLE(instance->entry_port), TEXT_EXAMPLE_ENTRY_PORT_SETTINGS_NETWORK_WINDOW,
        NEW_TEXT_LENGTH_ENTRY_PORT_SETTINGS_NETWORK_WINDOW, &(instance->cur_pos_port)
    );
    gtk_editable_select_region(GTK_EDITABLE(instance->entry_port), START_POSITION_ENTRY_PORT_SETTINGS_NETWORK_WINDOW, len_port);
    gtk_container_add(GTK_CONTAINER(instance->frame_entry_port), instance->entry_port);
    gtk_grid_attach(GTK_GRID(instance->table), instance->frame_control_exit, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(instance->table), instance->frame_entry_address, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(instance->table), instance->frame_entry_port, 0, 2, 1, 1);
    gtk_box_pack_start(GTK_BOX(instance->vbox), instance->table, TRUE, TRUE, 0);
    instance->hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, SPACING_HBOX_SETTINGS_NETWORK_WINDOW);

    if (!instance->hbox)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    instance->button_ok = gtk_button_new_with_label(TEXT_BUTTON_OK_HBOX_SETTINGS_NETWORK_WINDOW);

    if (!instance->button_ok)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    instance->button_cancel = gtk_button_new_with_label(TEXT_BUTTON_CANCEL_HBOX_SETTINGS_NETWORK_WINDOW);

    if (!instance->button_cancel)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_NETWORK_WINDOW);
        destroy_settings_network_window(instance);
        return NULL;
    }

    gtk_widget_set_size_request(instance->button_ok, WIDTH_BUTTON_HBOX_SETTINGS_NETWORK_WINDOW, HEIGHT_BUTTON_HBOX_SETTINGS_NETWORK_WINDOW);
    gtk_widget_set_size_request(instance->button_cancel, WIDTH_BUTTON_HBOX_SETTINGS_NETWORK_WINDOW, HEIGHT_BUTTON_HBOX_SETTINGS_NETWORK_WINDOW);
    gtk_container_add(GTK_CONTAINER(instance->hbox), instance->button_ok);
    gtk_container_add(GTK_CONTAINER(instance->hbox), instance->button_cancel);
    gtk_box_pack_start(GTK_BOX(instance->vbox), instance->hbox, FALSE, FALSE, 0);
    g_signal_connect_swapped(instance->window, "delete-event", G_CALLBACK(destroy_settings_network_window), instance);

    return instance;
}

void show_settings_network_window(SettingsNetworkWindow *instance)
{
    if (instance && instance->window && !gtk_widget_get_visible(instance->window))
    {
        gtk_widget_show_all(instance->window);
    }
}

void hide_settings_network_window(SettingsNetworkWindow *instance)
{
    if (instance && instance->window && gtk_widget_get_visible(instance->window))
    {
        gtk_widget_hide(instance->window);
    }
}

void destroy_settings_network_window(SettingsNetworkWindow *instance)
{
    if (instance)
    {
        if (instance->window)
        {
            gtk_widget_destroy(instance->window);
            instance->button_cancel = NULL;
            instance->button_ok = NULL;
            instance->hbox = NULL;
            instance->check_button = NULL;
            instance->entry_address = NULL;
            instance->entry_port = NULL;
            instance->frame_control_exit = NULL;
            instance->frame_entry_address = NULL;
            instance->frame_entry_port = NULL;
            instance->table = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }    
}
