/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpichannelset.h
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
#include "channel_control.h"
#include "../widgets/vertical_bar.h"

ChannelControl *new_channel_control(gint channel_id)
{
    ChannelControl *instance = g_malloc(sizeof(ChannelControl));

    if (instance)
    {
        instance->control_channel_vertical_bar = gtk_vb_new();
        gtk_widget_set_tooltip_text(instance->control_channel_vertical_bar, TOOLTIP_VERTICAL_BAR(channel_id));
        // instance->control_channel_scale = gtk_vcontrol_channel_scale_new_with_range(MIN_VALUE_SCALE, MAX_VALUE_SCALE, STEP_VALUE_SCALE);
        gtk_widget_set_tooltip_text(instance->control_channel_scale, TOOLTIP_SCALE(channel_id));
        gtk_range_set_inverted(GTK_RANGE(instance->control_channel_scale), TRUE);
        // gtk_control_channel_scale_set_value_pos(GTK_SCALE(instance->control_channel_scale), GTK_POS_TOP);
        gtk_widget_set_size_request(instance->control_channel_scale, WIDTH_SCALE, HEIGHT_SCALE);
        instance->control_channel_spinner_adjustment = (GtkAdjustment *) gtk_adjustment_new(
            VALUE_SPINNER_ADJUSTMENT, LOWER_SPINNER_ADJUSTMENT,
            UPPER_SPINNER_ADJUSTMENT, STEP_INCREMENT_SPINNER_ADJUSTMENT,
            PAGE_INCREMENT_SPINNER_ADJUSTMENT, PAGE_SIZE_SPINNER_ADJUSTMENT
        );
        instance->control_channel_spinner_button = gtk_spin_button_new(
            instance->control_channel_spinner_adjustment, CLIMB_RATE_SPINNER_BUTTON, DIGITS_SPINNER_BUTTON
        );
        gtk_widget_set_tooltip_text(instance->control_channel_spinner_button, TOOLTIP_SPINNER_BUTTON(channel_id));
        instance->control_channel_gpio_check_box = gtk_check_button_new_with_label(TEXT_CHECK_BOX_GPIO(channel_id));
        gtk_widget_set_tooltip_text(instance->control_channel_gpio_check_box, TOOLTIP_CHECK_BOX_GPIO(channel_id));
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(instance->control_channel_gpio_check_box), FALSE);
    }
    else
    {
        g_warning("");
    }

    return instance;
}

void show_channel_control(ChannelControl *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->control_channel_vertical_bar)
    {
        gtk_widget_show(instance->control_channel_vertical_bar);
    }

    if (instance->control_channel_scale)
    {
        gtk_widget_show(instance->control_channel_scale);
    }

    if (instance->control_channel_spinner_adjustment)
    {
        gtk_widget_show((GtkWidget*) instance->control_channel_spinner_adjustment);
    }

    if (instance->control_channel_spinner_button)
    {
        gtk_widget_show(instance->control_channel_spinner_button);
    }

    if (instance->control_channel_gpio_check_box)
    {
        gtk_widget_show(instance->control_channel_gpio_check_box);
    }
}

void hide_channel_control(ChannelControl *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->control_channel_vertical_bar)
    {
        gtk_widget_hide(instance->control_channel_vertical_bar);
    }

    if (instance->control_channel_scale)
    {
        gtk_widget_hide(instance->control_channel_scale);
    }

    if (instance->control_channel_spinner_adjustment)
    {
        gtk_widget_hide((GtkWidget*) instance->control_channel_spinner_adjustment);
    }

    if (instance->control_channel_spinner_button)
    {
        gtk_widget_hide(instance->control_channel_spinner_button);
    }

    if (instance->control_channel_gpio_check_box)
    {
        gtk_widget_hide(instance->control_channel_gpio_check_box);
    }
}

void destroy_channel_control(ChannelControl *instance)
{
    if (instance == NULL)
    {
        return;
    }

    gtk_vb_destroy((GtkObject*) instance->control_channel_vertical_bar);
    gtk_widget_destroy(instance->control_channel_scale);
    gtk_widget_destroy((GtkWidget*) instance->control_channel_spinner_adjustment);
    gtk_widget_destroy(instance->control_channel_spinner_button);
    gtk_widget_destroy(instance->control_channel_gpio_check_box);
    g_free(instance);
}
