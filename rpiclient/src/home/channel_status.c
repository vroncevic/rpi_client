/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * channel_status.c
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
#include "channel_status.h"

ChannelStatus *new_channel_status(gint channel_id)
{
    ChannelStatus *instance = g_malloc(sizeof(ChannelStatus));

    if (!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS(channel_id, "channel status widget"));
        return NULL;
    }

    gchar status_checkbox[10] = {0};
    snprintf(status_checkbox, sizeof(status_checkbox), "Channel %d", channel_id);
    instance->activate_channel_check_box = gtk_check_button_new_with_label(status_checkbox);

    if (!instance->activate_channel_check_box)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS(channel_id, "channel status check box widget"));
        destroy_channel_status(instance);
        return NULL;
    }

    gchar tooltip_text_checkbox[19] = {0};
    snprintf(tooltip_text_checkbox, sizeof(tooltip_text_checkbox), "Activate Channel %d", channel_id);
    gtk_widget_set_tooltip_text(instance->activate_channel_check_box, tooltip_text_checkbox);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(instance->activate_channel_check_box), FALSE);
    instance->status_channel_vertical_bar = GTK_VB(gtk_vb_new());

    if (!instance->status_channel_vertical_bar)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS(channel_id, "channel status vertical bar widget"));
        destroy_channel_status(instance);
        return NULL;
    }

    gchar tooltip_text_vbar[10] = {0};
    snprintf(tooltip_text_vbar, sizeof(tooltip_text_vbar), "Channel  %d", channel_id);
    gtk_widget_set_tooltip_text(instance->status_channel_vertical_bar, tooltip_text_vbar);
    gchar status_label[14] = {0};
    snprintf(status_label, sizeof(status_label), "CH%d Status: 0", channel_id);
    instance->status_channel_label = gtk_label_new(status_label);

    if (!instance->status_channel_label)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS(channel_id, "channel status label widget"));
        destroy_channel_status(instance);
        return NULL;
    }

    return instance;
}

void show_channel_status(ChannelStatus *instance)
{
    if (instance && instance->activate_channel_check_box && !gtk_widget_get_visible(instance->activate_channel_check_box))
    {
        gtk_widget_show(instance->activate_channel_check_box);
    }

    if (instance && instance->status_channel_label && !gtk_widget_get_visible(instance->status_channel_label))
    {
        gtk_widget_show(instance->status_channel_label);
    }

    if (instance && instance->status_channel_vertical_bar)
    {
        gtk_widget_show(instance->status_channel_vertical_bar);
    }
}

void hide_channel_status(ChannelStatus *instance)
{

    if (instance && instance->activate_channel_check_box && gtk_widget_get_visible(instance->activate_channel_check_box))
    {
        gtk_widget_hide(instance->activate_channel_check_box);
    }

    if (instance && instance->status_channel_label && gtk_widget_get_visible(instance->status_channel_label))
    {
        gtk_widget_hide(instance->status_channel_label);
    }

    if (instance->status_channel_vertical_bar)
    {
        gtk_widget_hide(instance->status_channel_vertical_bar);
    }
}

void destroy_channel_status(ChannelStatus *instance)
{
    if (instance)
    {
        if (instance->status_channel_label)
        {
            gtk_widget_destroy(instance->status_channel_label);
            instance->status_channel_label = NULL;
        }

        if (instance->activate_channel_check_box)
        {
            gtk_widget_destroy(instance->activate_channel_check_box);
            instance->activate_channel_check_box = NULL;
        }

        if (instance->status_channel_vertical_bar)
        {
            gtk_vb_destroy(instance->status_channel_vertical_bar);
            instance->status_channel_vertical_bar = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
