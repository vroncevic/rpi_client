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
#include "home_frame.h"

HomeFrame *new_home_frame(void)
{
    HomeFrame *instance = g_malloc(sizeof(HomeFrame));

    if (instance)
    {
        instance->frame_home = gtk_frame_new("");
        instance->vpaned = gtk_vpaned_new();
        gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_home), GTK_SHADOW_IN);
        gtk_container_add(GTK_CONTAINER(instance->frame_home), instance->vpaned);

        instance->frame_control = gtk_frame_new("");
        instance->fixed_control = gtk_fixed_new();
        gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_control), GTK_SHADOW_IN);
        gtk_container_add(GTK_CONTAINER(instance->frame_control), instance->fixed_control);

        instance->frame_status = gtk_frame_new("");
        instance->fixed_status = gtk_fixed_new();
        gtk_frame_set_shadow_type(GTK_FRAME(instance->frame_status), GTK_SHADOW_IN);
        gtk_container_add(GTK_CONTAINER(instance->frame_status), instance->fixed_status);

        gint i;
        gint x_pos_vbar = START_X_POSITION_VERTICAL_BAR_GET;
        gint x_pos_activate_channel = START_X_POSITION_ACTIVATE_CHANNEL_GET;
        gint x_pos_label = START_X_POSITION_LABEL_GET;

        for (i = 0; i < MAX_CHANNELS_STATUS; i++)
        {
            instance->channels_status[i] = new_channel_status(i);
            gtk_fixed_put(
                GTK_FIXED(instance->fixed_status),
                instance->channels_status[i]->status_channel_vertical_bar,
                x_pos_vbar, Y_POSITION_VERTICAL_BAR_GET
            );
            x_pos_vbar += SHIFT_X_POSITION_GET;
            gtk_fixed_put(
                GTK_FIXED(instance->fixed_status),
                instance->channels_status[i]->activate_channel_check_box,
                x_pos_activate_channel, Y_POSITION_ACTIVATE_CHANNEL_GET
            );
            x_pos_activate_channel += SHIFT_X_POSITION_GET;
            gtk_fixed_put(
                GTK_FIXED(instance->fixed_status),
                instance->channels_status[i]->status_channel_label,
                x_pos_label, Y_POSITION_LABEL_GET
            );
            x_pos_label += SHIFT_X_POSITION_GET;
        }

        gint i;
        gint x_pos_vbar = START_X_POSITION_VERTICAL_BAR_SET;
        gint x_pos_control_channel_scale = START_X_POSITION_SCALE_SET;
        gint x_pos_spiner_button = START_X_POSITION_SPINER_BUTTON_SET;
        gint x_pos_control_channel_gpio_check_box = START_X_POSITION_ACTIVATE_GPIO_SET;

        for (i = 0; i < MAX_CHANNELS_CONTROL; i++)
        {
            instance->channels_control[i] = new_channel_control(i + 1);
            gtk_fixed_put(
                GTK_FIXED(instance->fixed_control),
                instance->channels_control[i]->control_channel_vertical_bar, x_pos_vbar,
                Y_POSITION_VERTICAL_BAR_SET
            );
            x_pos_vbar += SHIFT_X_POSITION_SET;
            gtk_fixed_put(
                GTK_FIXED(instance->fixed_control),
                instance->channels_control[i]->control_channel_scale, x_pos_control_channel_scale,
                Y_POSITION_SCALE_SET
            );
            x_pos_control_channel_scale += SHIFT_X_POSITION_SET;
            gtk_fixed_put(
                GTK_FIXED(instance->fixed_control),
                instance->channels_control[i]->control_channel_spinner_button,
                x_pos_spiner_button, Y_POSITION_SPINER_BUTTON_SET
            );
            x_pos_spiner_button += SHIFT_X_POSITION_SET;
            gtk_fixed_put(
                GTK_FIXED(instance->fixed_control),
                instance->channels_control[i]->control_channel_gpio_check_box,
                x_pos_control_channel_gpio_check_box, Y_POSITION_ACTIVATE_GPIO_SET
            );
            x_pos_control_channel_gpio_check_box += SHIFT_X_POSITION_SET;
        }

        gtk_paned_add1(GTK_PANED(instance->vpaned), instance->frame_control);
        gtk_paned_add2(GTK_PANED(instance->vpaned), instance->frame_status);
    }
    else
    {
        g_warning("");
    }

    return instance;
}

void show_home_frame(HomeFrame *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->frame_home)
    {
        gtk_widget_show(instance->frame_home);
    }
}

void hide_home_frame(HomeFrame *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->frame_home)
    {
        gtk_widget_hide(instance->frame_home);
    }
}

void destroy_home_frame(HomeFrame *instance)
{
    if (instance == NULL)
    {
        return;
    }

    gtk_widget_destroy(instance->frame_home);
    g_free(instance);
}
