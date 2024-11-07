/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_channel_status.c
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
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "rpi_channel_status.h"

static const gchar* WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS = "Failed to allocate memory for channel status\n";

//////////////////////////////////////////////////////////////////////////////
/// @brief RPI channel status complex widget
///   activate_channel_check_box - Gtk check box widget for channel status
///   status_channel_label - Gtk label widget for channel mark
///   status_channel_vertical_bar - Custom vertical bar widget for channel status
struct _RPIChannelStatus
{
    GtkWidget *activate_channel_check_box;
    GtkWidget *status_channel_label;
    GtkVB *status_channel_vertical_bar;
};

RPIChannelStatus *new_rpi_channel_status(gint channel_id)
{
    RPIChannelStatus *instance = g_malloc(sizeof(RPIChannelStatus));

    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS);
        return NULL;
    }

    gchar status_checkbox[10] = {0};
    snprintf(status_checkbox, sizeof(status_checkbox), "Channel %d", channel_id);
    instance->activate_channel_check_box = gtk_check_button_new_with_label(status_checkbox);

    if (!GTK_IS_CHECK_BUTTON(instance->activate_channel_check_box))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS);
        destroy_rpi_channel_status(instance);
        return NULL;
    }

    gchar tooltip_text_checkbox[19] = {0};
    snprintf(tooltip_text_checkbox, sizeof(tooltip_text_checkbox), "Activate Channel %d", channel_id);
    gtk_widget_set_tooltip_text(instance->activate_channel_check_box, tooltip_text_checkbox);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(instance->activate_channel_check_box), FALSE);
    instance->status_channel_vertical_bar = GTK_VB(gtk_vb_new());

    if (!GTK_IS_VB(instance->status_channel_vertical_bar))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS);
        destroy_rpi_channel_status(instance);
        return NULL;
    }

    gchar tooltip_text_vbar[10] = {0};
    snprintf(tooltip_text_vbar, sizeof(tooltip_text_vbar), "Channel %d", channel_id);
    gtk_widget_set_tooltip_text(GTK_WIDGET(instance->status_channel_vertical_bar), tooltip_text_vbar);
    gchar status_label[14] = {0};
    snprintf(status_label, sizeof(status_label), "CH%d Status: 0", channel_id);
    instance->status_channel_label = gtk_label_new(status_label);

    if (!GTK_IS_LABEL(instance->status_channel_label))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS);
        destroy_rpi_channel_status(instance);
        return NULL;
    }

    return instance;
}

void show_rpi_channel_status(RPIChannelStatus *instance)
{
    if (instance)
    {
        gboolean is_check_button = GTK_IS_CHECK_BUTTON(instance->activate_channel_check_box);
        gboolean is_check_button_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->activate_channel_check_box));

        if (is_check_button && is_check_button_hidden)
        {
            gtk_widget_show(instance->activate_channel_check_box);
        }

        gboolean is_check_label = GTK_IS_LABEL(instance->status_channel_label);
        gboolean is_check_label_hidden = !gtk_widget_get_visible(instance->status_channel_label);

        if (is_check_label && is_check_label_hidden)
        {
            gtk_widget_show(instance->status_channel_label);
        }

        gboolean is_verical_bar = GTK_IS_VB(instance->status_channel_vertical_bar);
        gboolean is_verical_bar_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->status_channel_vertical_bar));

        if (is_verical_bar && is_verical_bar_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->status_channel_vertical_bar));
        }
    }
}

void hide_rpi_channel_status(RPIChannelStatus *instance)
{
    if (instance)
    {
        gboolean is_check_button = GTK_IS_CHECK_BUTTON(instance->activate_channel_check_box);
        gboolean is_check_button_visible = gtk_widget_get_visible(GTK_WIDGET(instance->activate_channel_check_box));

        if (is_check_button && is_check_button_visible)
        {
            gtk_widget_hide(instance->activate_channel_check_box);
        }

        gboolean is_check_label = GTK_IS_LABEL(instance->status_channel_label);
        gboolean is_check_label_visible = gtk_widget_get_visible(instance->status_channel_label);

        if (is_check_label && is_check_label_visible)
        {
            gtk_widget_hide(instance->status_channel_label);
        }

        gboolean is_verical_bar = GTK_IS_VB(instance->status_channel_vertical_bar);
        gboolean is_verical_bar_visible = gtk_widget_get_visible(GTK_WIDGET(instance->status_channel_vertical_bar));

        if (is_verical_bar && is_verical_bar_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->status_channel_vertical_bar));
        }
    }
}

GtkWidget* get_check_box_from_rpi_channel_status(RPIChannelStatus *instance)
{
    if (instance)
    {
        gboolean is_check_box = GTK_IS_CHECK_BUTTON(instance->activate_channel_check_box);

        if (is_check_box)
        {
            return instance->activate_channel_check_box;        
        }
    }

    return NULL;
}

GtkWidget* get_label_from_rpi_channel_status(RPIChannelStatus *instance)
{
    if (instance)
    {
        gboolean is_label = GTK_IS_LABEL(instance->status_channel_label);

        if (is_label)
        {
            return instance->status_channel_label;
        }
    }

    return NULL;
}

GtkVB* get_vertical_bar_from_rpi_channel_status(RPIChannelStatus *instance)
{
    if (instance)
    {
        gboolean is_vertical_bar = GTK_IS_VB(instance->status_channel_vertical_bar);

        if (is_vertical_bar)
        {
            return instance->status_channel_vertical_bar;
        }
    }

    return NULL;
}

void destroy_rpi_channel_status(RPIChannelStatus *instance)
{
    if (instance)
    {
        if (GTK_IS_LABEL(instance->status_channel_label))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->status_channel_label));
            instance->status_channel_label = NULL;
        }

        if (GTK_IS_CHECK_BUTTON(instance->activate_channel_check_box))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->activate_channel_check_box));
            instance->activate_channel_check_box = NULL;
        }

        if (GTK_IS_VB(instance->status_channel_vertical_bar))
        {
            gtk_vb_destroy(instance->status_channel_vertical_bar);
            instance->status_channel_vertical_bar = NULL;
        }

        g_free((gpointer)instance);
    }
}
