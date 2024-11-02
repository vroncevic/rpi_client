/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * channel_control.c
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

ChannelControl *new_channel_control(gint channel_id)
{
    ChannelControl *instance = g_malloc(sizeof(ChannelControl));

    if (!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_CONTROL(channel_id, "channel control widget"));
        return NULL;
    }

    instance->control_channel_vertical_bar = GTK_VB(gtk_vb_new());

    if (!instance->control_channel_vertical_bar)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_CONTROL(channel_id, "channel control vertical bar widget"));
        destroy_channel_control(instance);
        return NULL;        
    }

    gchar tooltip_text_vbar[10] = {0};
    snprintf(tooltip_text_vbar, sizeof(tooltip_text_vbar), "Channel %d", channel_id);
    gtk_widget_set_tooltip_text(instance->control_channel_vertical_bar, tooltip_text_vbar);
    instance->control_channel_scale = gtk_scale_new_with_range(
        GTK_ORIENTATION_VERTICAL, MIN_VALUE_SCALE_CHANNEL_CONTROL, MAX_VALUE_SCALE_CHANNEL_CONTROL, STEP_VALUE_SCALE_CHANNEL_CONTROL
    );

    if (!instance->control_channel_scale)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_CONTROL(channel_id, "channel control scale widget"));
        destroy_channel_control(instance);
        return NULL;
    }

    gchar tooltip_text_scale[14] = {0};
    snprintf(tooltip_text_scale, sizeof(tooltip_text_scale), "Set Channel %d", channel_id);
    gtk_widget_set_tooltip_text(instance->control_channel_scale, tooltip_text_scale);
    gtk_range_set_inverted(GTK_RANGE(instance->control_channel_scale), TRUE);
    gtk_scale_set_value_pos(GTK_SCALE(instance->control_channel_scale), GTK_POS_TOP);
    gtk_widget_set_size_request(instance->control_channel_scale, WIDTH_SCALE_CHANNEL_CONTROL, HEIGHT_SCALE_CHANNEL_CONTROL);
    instance->control_channel_spinner_adjustment = (GtkAdjustment *) gtk_adjustment_new(
        VALUE_SPINNER_ADJUSTMENT_CHANNEL_CONTROL, LOWER_SPINNER_ADJUSTMENT_CHANNEL_CONTROL,
        UPPER_SPINNER_ADJUSTMENT_CHANNEL_CONTROL, STEP_INCREMENT_SPINNER_ADJUSTMENT_CHANNEL_CONTROL,
        PAGE_INCREMENT_SPINNER_ADJUSTMENT_CHANNEL_CONTROL, PAGE_SIZE_SPINNER_ADJUSTMENT_CHANNEL_CONTROL
    );

    if (!instance->control_channel_spinner_adjustment)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_CONTROL(channel_id, "channel control spinner adjustment widget"));
        destroy_channel_control(instance);
        return NULL;
    }

    instance->control_channel_spinner_button = gtk_spin_button_new(
        instance->control_channel_spinner_adjustment, CLIMB_RATE_SPINNER_BUTTON_CHANNEL_CONTROL, DIGITS_SPINNER_BUTTON_CHANNEL_CONTROL
    );

    if (!instance->control_channel_spinner_button)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_CONTROL(channel_id, "channel control spinner widget"));
        destroy_channel_control(instance);
        return NULL;
    }

    gchar tooltip_text_spinner[23] = {0};
    snprintf(tooltip_text_spinner, sizeof(tooltip_text_spinner), "Set level at channel %d", channel_id);
    gtk_widget_set_tooltip_text(instance->control_channel_spinner_button, tooltip_text_spinner);
    gchar text_check_box[7] = {0};
    snprintf(text_check_box, sizeof(text_check_box), "GPIO %d", channel_id);
    instance->control_channel_gpio_check_box = gtk_check_button_new_with_label(text_check_box);

    if (!instance->control_channel_gpio_check_box)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_CHANNEL_CONTROL(channel_id, "channel control checkbox widget"));
        destroy_channel_control(instance);
        return NULL;
    }

    gchar tooltip_text_check_box[14] = {0};
    snprintf(tooltip_text_check_box, sizeof(tooltip_text_check_box), "Active GPIO %d", channel_id);
    gtk_widget_set_tooltip_text(instance->control_channel_gpio_check_box, tooltip_text_check_box);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(instance->control_channel_gpio_check_box), FALSE);

    return instance;
}

void show_channel_control(ChannelControl *instance)
{
    if (instance && instance->control_channel_vertical_bar && !gtk_widget_get_visible(instance->control_channel_vertical_bar))
    {
        gtk_widget_show(instance->control_channel_vertical_bar);
    }

    if (instance && instance->control_channel_scale && !gtk_widget_get_visible(instance->control_channel_scale))
    {
        gtk_widget_show(instance->control_channel_scale);
    }

    if (instance && instance->control_channel_spinner_adjustment && !gtk_widget_get_visible(instance->control_channel_spinner_adjustment))
    {
        gtk_widget_show((GtkWidget*) instance->control_channel_spinner_adjustment);
    }

    if (instance && instance->control_channel_spinner_button && !gtk_widget_get_visible(instance->control_channel_spinner_button))
    {
        gtk_widget_show(instance->control_channel_spinner_button);
    }

    if (instance && instance->control_channel_gpio_check_box && !gtk_widget_get_visible(instance->control_channel_gpio_check_box))
    {
        gtk_widget_show(instance->control_channel_gpio_check_box);
    }
}

void hide_channel_control(ChannelControl *instance)
{
    if (instance && instance->control_channel_vertical_bar && gtk_widget_get_visible(instance->control_channel_vertical_bar))
    {
        gtk_widget_hide(instance->control_channel_vertical_bar);
    }

    if (instance && instance->control_channel_scale && gtk_widget_get_visible(instance->control_channel_scale))
    {
        gtk_widget_hide(instance->control_channel_scale);
    }

    if (instance && instance->control_channel_spinner_adjustment && gtk_widget_get_visible(instance->control_channel_spinner_adjustment))
    {
        gtk_widget_hide((GtkWidget*) instance->control_channel_spinner_adjustment);
    }

    if (instance && instance->control_channel_spinner_button && gtk_widget_get_visible(instance->control_channel_spinner_button))
    {
        gtk_widget_hide(instance->control_channel_spinner_button);
    }

    if (instance && instance->control_channel_gpio_check_box && gtk_widget_get_visible(instance->control_channel_gpio_check_box))
    {
        gtk_widget_hide(instance->control_channel_gpio_check_box);
    }
}

void destroy_channel_control(ChannelControl *instance)
{
    if (instance)
    {
        if (instance->control_channel_vertical_bar)
        {
            gtk_vb_destroy(instance->control_channel_vertical_bar);
            instance->control_channel_vertical_bar = NULL;
        }

        if (instance->control_channel_scale)
        {
            gtk_widget_destroy(instance->control_channel_scale);
            instance->control_channel_scale = NULL;
        }

        if (instance->control_channel_spinner_adjustment)
        {
            gtk_widget_destroy((GtkWidget*) instance->control_channel_spinner_adjustment);
            instance->control_channel_spinner_adjustment = NULL;
        }
        
        if (instance->control_channel_spinner_button)
        {
            gtk_widget_destroy(instance->control_channel_spinner_button);
            instance->control_channel_spinner_button = NULL;
        }

        if (instance->control_channel_gpio_check_box)
        {
            gtk_widget_destroy(instance->control_channel_gpio_check_box);
            instance->control_channel_gpio_check_box = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
