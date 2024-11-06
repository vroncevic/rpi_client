/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * home_frame.c
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
#include "channel_status.h"
#include "channel_control.h"
#include "home_frame.h"
#include <glib.h>

static const gchar* CONTROL_FRAME_LABEL_HOME_FRAME = "RPI Control";
static const gint START_X_POSITION_VERTICAL_BAR_CONTROL_HOME_FRAME = 0;
static const gint Y_POSITION_VERTICAL_BAR_CONTROL_HOME_FRAME = 20;
static const gint START_X_POSITION_SCALE_CONTROL_HOME_FRAME = 70;
static const gint Y_POSITION_SCALE_CONTROL_HOME_FRAME = 0;
static const gint START_X_POSITION_SPINER_BUTTON_CONTROL_HOME_FRAME = 0;
static const gint Y_POSITION_SPINER_BUTTON_CONTROL_HOME_FRAME = 220;
static const gint START_X_POSITION_ACTIVATE_GPIO_CONTROL_HOME_FRAME = 0;
static const gint Y_POSITION_ACTIVATE_GPIO_CONTROL_HOME_FRAME = 190;
static const gint SHIFT_X_POSITION_CONTROL_HOME_FRAME = 125;
static const gchar* STATUS_FRAME_LABEL_HOME_FRAME = "RPI Status";
static const gint START_X_POSITION_VERTICAL_BAR_STATUS_HOME_FRAME = 0;
static const gint Y_POSITION_VERTICAL_BAR_STATUS_HOME_FRAME = 0;
static const gint START_X_POSITION_ACTIVATE_CHANNEL_STATUS_HOME_FRAME = 0;
static const gint Y_POSITION_ACTIVATE_CHANNEL_STATUS_HOME_FRAME = 160;
static const gint START_X_POSITION_LABEL_STATUS_HOME_FRAME = 0;
static const gint Y_POSITION_LABEL_STATUS_HOME_FRAME = 200;
static const gint SHIFT_X_POSITION_STATUS_HOME_FRAME = 125;
static const gchar* WARNING_LOG_FAILED_MALLOC_HOME_FRAME = "Failed to allocate memory for home frame\n";

//////////////////////////////////////////////////////////////////////////////
/// @brief Home frame complex widget
///   frame_home - Gtk widget for home frame
///   vpanned - Gtk widget for vertical panned
///   frame_status - Gtk widget for status frame
///   fixed_status - Gtk widget for status fixed container
///   channel_status - Complex custom widget for channel status
///   frame_control - Gtk widget for control frame
///   fixed_control - Gtk widget for control fixed container
///   channel_control - Complex custom widget for channel control
struct _HomeFrame
{
    GtkWidget *frame_home;
    GtkWidget *vpaned;
    GtkWidget *frame_status;
    GtkWidget *fixed_status;
    ChannelStatus *channels_status[MAX_CHANNELS_STATUS_HOME_FRAME];
    GtkWidget *frame_control;
    GtkWidget *fixed_control;
    ChannelControl *channels_control[MAX_CHANNELS_CONTROL_HOME_FRAME];
};

HomeFrame *new_home_frame(void)
{
    HomeFrame *instance = g_malloc(sizeof(HomeFrame));

    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME);
        return NULL;
    }

    instance->frame_home = gtk_frame_new("");

    if (!GTK_IS_FRAME(instance->frame_home))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME);
        destroy_home_frame(instance);
        return NULL;
    }

    instance->vpaned = gtk_paned_new(GTK_ORIENTATION_VERTICAL);

    if (!GTK_IS_PANED(instance->vpaned))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME);
        destroy_home_frame(instance);
        return NULL;
    }

    gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_home), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER(instance->frame_home), instance->vpaned);
    instance->frame_control = gtk_frame_new(CONTROL_FRAME_LABEL_HOME_FRAME);

    if (!GTK_IS_FRAME(instance->frame_control))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME);
        destroy_home_frame(instance);
        return NULL;
    }

    instance->fixed_control = gtk_fixed_new();

    if (!GTK_IS_FIXED(instance->fixed_control))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME);
        destroy_home_frame(instance);
        return NULL;
    }

    gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_control), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER(instance->frame_control), instance->fixed_control);
    instance->frame_status = gtk_frame_new(STATUS_FRAME_LABEL_HOME_FRAME);

    if (!GTK_IS_FRAME(instance->frame_status))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME);
        destroy_home_frame(instance);
        return NULL;
    }

    instance->fixed_status = gtk_fixed_new();

    if (!GTK_IS_FIXED(instance->fixed_status))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_HOME_FRAME);
        destroy_home_frame(instance);
        return NULL;
    }

    gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_status), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER(instance->frame_status), GTK_WIDGET(instance->fixed_status));
    gint x_pos_vbar = START_X_POSITION_VERTICAL_BAR_STATUS_HOME_FRAME;
    gint x_pos_activate_channel = START_X_POSITION_ACTIVATE_CHANNEL_STATUS_HOME_FRAME;
    gint x_pos_label = START_X_POSITION_LABEL_STATUS_HOME_FRAME;

    for (guint i = 0; i < MAX_CHANNELS_STATUS_HOME_FRAME; i++)
    {
        instance->channels_status[i] = new_channel_status(i);
        gtk_fixed_put(
            GTK_FIXED(instance->fixed_status),
            GTK_WIDGET(get_bar_channel_status(instance->channels_status[i])),
            x_pos_vbar,
            Y_POSITION_VERTICAL_BAR_STATUS_HOME_FRAME
        );
        x_pos_vbar += SHIFT_X_POSITION_STATUS_HOME_FRAME;
        gtk_fixed_put(
            GTK_FIXED(instance->fixed_status),
            GTK_WIDGET(get_check_box_channel_status(instance->channels_status[i])),
            x_pos_activate_channel,
            Y_POSITION_ACTIVATE_CHANNEL_STATUS_HOME_FRAME
        );
        x_pos_activate_channel += SHIFT_X_POSITION_STATUS_HOME_FRAME;
        gtk_fixed_put(
            GTK_FIXED(instance->fixed_status),
            GTK_WIDGET(get_label_channel_status(instance->channels_status[i])),
            x_pos_label,
            Y_POSITION_LABEL_STATUS_HOME_FRAME
        );
        x_pos_label += SHIFT_X_POSITION_STATUS_HOME_FRAME;
    }

    x_pos_vbar = START_X_POSITION_VERTICAL_BAR_CONTROL_HOME_FRAME;
    gint x_pos_control_channel_scale = START_X_POSITION_SCALE_CONTROL_HOME_FRAME;
    gint x_pos_spiner_button = START_X_POSITION_SPINER_BUTTON_CONTROL_HOME_FRAME;
    gint x_pos_control_channel_gpio_check_box = START_X_POSITION_ACTIVATE_GPIO_CONTROL_HOME_FRAME;

    for (guint i = 0; i < MAX_CHANNELS_CONTROL_HOME_FRAME; i++)
    {
        instance->channels_control[i] = new_channel_control(i + 1);
        gtk_fixed_put(
            GTK_FIXED(instance->fixed_control),
            GTK_WIDGET(get_bar_channel_control(instance->channels_control[i])),
            x_pos_vbar,
            Y_POSITION_VERTICAL_BAR_CONTROL_HOME_FRAME
        );
        x_pos_vbar += SHIFT_X_POSITION_CONTROL_HOME_FRAME;
        gtk_fixed_put(
            GTK_FIXED(instance->fixed_control),
            GTK_WIDGET(get_scale_channel_control(instance->channels_control[i])),
            x_pos_control_channel_scale,
            Y_POSITION_SCALE_CONTROL_HOME_FRAME
        );
        x_pos_control_channel_scale += SHIFT_X_POSITION_CONTROL_HOME_FRAME;
        gtk_fixed_put(
            GTK_FIXED(instance->fixed_control),
            GTK_WIDGET(get_spinner_button_channel_control(instance->channels_control[i])),
            x_pos_spiner_button,
            Y_POSITION_SPINER_BUTTON_CONTROL_HOME_FRAME
        );
        x_pos_spiner_button += SHIFT_X_POSITION_CONTROL_HOME_FRAME;
        gtk_fixed_put(
            GTK_FIXED(instance->fixed_control),
            GTK_WIDGET(get_check_box_channel_control(instance->channels_control[i])),
            x_pos_control_channel_gpio_check_box,
            Y_POSITION_ACTIVATE_GPIO_CONTROL_HOME_FRAME
        );
        x_pos_control_channel_gpio_check_box += SHIFT_X_POSITION_CONTROL_HOME_FRAME;
    }

    gtk_paned_add1(GTK_PANED(instance->vpaned), GTK_WIDGET(instance->frame_control));
    gtk_paned_add2(GTK_PANED(instance->vpaned), GTK_WIDGET(instance->frame_status));

    return instance;
}

void show_home_frame(HomeFrame *instance)
{
    if (instance)
    {
        gboolean is_frame = GTK_IS_FRAME(instance->frame_home);
        gboolean is_frame_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->frame_home));

        if (is_frame && is_frame_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->frame_home));
        }
    }
}

void hide_home_frame(HomeFrame *instance)
{
    if (instance)
    {
        gboolean is_frame = GTK_IS_FRAME(instance->frame_home);
        gboolean is_frame_visible = gtk_widget_get_visible(GTK_WIDGET(instance->frame_home));

        if (is_frame && is_frame_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->frame_home));
        }
    }
}

GtkWidget* get_frame_home_frame(HomeFrame *instance)
{
    return instance && GTK_IS_FRAME(instance->frame_home) ? instance->frame_home : NULL;
}

void destroy_home_frame(HomeFrame *instance)
{
    if (instance)
    {
        if (GTK_IS_FRAME(instance->frame_home))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->frame_home));
            instance->frame_home = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
