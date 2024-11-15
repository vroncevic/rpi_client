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
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "rpi_channel_control.h"

#define FAILED_MALLOC_CHANNEL_CONTROL "Failed to allocate memory for channel control.\n"

static const gint WIDTH_SCALE_CHANNEL_CONTROL = 50;
static const gint HEIGHT_SCALE_CHANNEL_CONTROL = 180;
static const gdouble MIN_VALUE_SCALE_CHANNEL_CONTROL = 0.0;
static const gdouble MAX_VALUE_SCALE_CHANNEL_CONTROL = 100.0;
static const gdouble STEP_VALUE_SCALE_CHANNEL_CONTROL = 1.0;
static const gdouble VALUE_SPINNER_ADJUSTMENT_CHANNEL_CONTROL = 0.0;
static const gdouble LOWER_SPINNER_ADJUSTMENT_CHANNEL_CONTROL = 0.0;
static const gdouble UPPER_SPINNER_ADJUSTMENT_CHANNEL_CONTROL = 100.0;
static const gdouble STEP_INCREMENT_SPINNER_ADJUSTMENT_CHANNEL_CONTROL = 1.0;
static const gdouble PAGE_INCREMENT_SPINNER_ADJUSTMENT_CHANNEL_CONTROL = 0.0;
static const gdouble PAGE_SIZE_SPINNER_ADJUSTMENT_CHANNEL_CONTROL = 0.0;
static const gdouble CLIMB_RATE_SPINNER_BUTTON_CHANNEL_CONTROL = 1.0;
static const gint DIGITS_SPINNER_BUTTON_CHANNEL_CONTROL = 0;

//////////////////////////////////////////////////////////////////////////////
/// @brief RPI channel control complex widget
///   control_channel_vertical_bar - Custom vertical bar widget for channel control
///   control_channel_scale - Gtk scale widget for channel control
///   control_channel_spinner_adjustment - Gtk adjustment widget for channel control
///   control_channel_spinner_button - Gtk spinner widget for channel control
///   control_channel_gpio_check_box - Gtk check box widget for channel control
struct _RPIChannelControl
{
    GtkVB *control_channel_vertical_bar;
    GtkWidget *control_channel_scale;
    GtkAdjustment *control_channel_spinner_adjustment;
    GtkWidget *control_channel_spinner_button;
    GtkWidget *control_channel_gpio_check_box;
};

RPIChannelControl *new_rpi_channel_control(gint channel_id)
{
    RPIChannelControl *instance = g_malloc(sizeof(RPIChannelControl));

    if (!instance)
    {
        g_critical(FAILED_MALLOC_CHANNEL_CONTROL);
        return NULL;
    }

    instance->control_channel_vertical_bar = GTK_VB(gtk_vb_new());

    if (!GTK_IS_VB(instance->control_channel_vertical_bar))
    {
        g_critical(FAILED_MALLOC_CHANNEL_CONTROL);
        destroy_rpi_channel_control(instance);
        return NULL;        
    }

    gchar tooltip_text_vbar[10] = {0};
    g_snprintf(tooltip_text_vbar, sizeof(tooltip_text_vbar), "Channel %d", channel_id);
    gtk_widget_set_tooltip_text(GTK_WIDGET(instance->control_channel_vertical_bar), tooltip_text_vbar);
    instance->control_channel_scale = gtk_scale_new_with_range(
        GTK_ORIENTATION_VERTICAL,
        MIN_VALUE_SCALE_CHANNEL_CONTROL,
        MAX_VALUE_SCALE_CHANNEL_CONTROL,
        STEP_VALUE_SCALE_CHANNEL_CONTROL
    );

    if (!GTK_IS_SCALE(instance->control_channel_scale))
    {
        g_critical(FAILED_MALLOC_CHANNEL_CONTROL);
        destroy_rpi_channel_control(instance);
        return NULL;
    }

    gchar tooltip_text_scale[14] = {0};
    g_snprintf(tooltip_text_scale, sizeof(tooltip_text_scale), "Set Channel %d", channel_id);
    gtk_widget_set_tooltip_text(GTK_WIDGET(instance->control_channel_scale), tooltip_text_scale);
    gtk_range_set_inverted(GTK_RANGE(instance->control_channel_scale), TRUE);
    gtk_scale_set_value_pos(GTK_SCALE(instance->control_channel_scale), GTK_POS_TOP);
    gtk_widget_set_size_request(
        instance->control_channel_scale,
        WIDTH_SCALE_CHANNEL_CONTROL,
        HEIGHT_SCALE_CHANNEL_CONTROL
    );
    instance->control_channel_spinner_adjustment = (GtkAdjustment *) gtk_adjustment_new(
        VALUE_SPINNER_ADJUSTMENT_CHANNEL_CONTROL,
        LOWER_SPINNER_ADJUSTMENT_CHANNEL_CONTROL,
        UPPER_SPINNER_ADJUSTMENT_CHANNEL_CONTROL,
        STEP_INCREMENT_SPINNER_ADJUSTMENT_CHANNEL_CONTROL,
        PAGE_INCREMENT_SPINNER_ADJUSTMENT_CHANNEL_CONTROL,
        PAGE_SIZE_SPINNER_ADJUSTMENT_CHANNEL_CONTROL
    );

    if (!GTK_IS_ADJUSTMENT(instance->control_channel_spinner_adjustment))
    {
        g_critical(FAILED_MALLOC_CHANNEL_CONTROL);
        destroy_rpi_channel_control(instance);
        return NULL;
    }

    instance->control_channel_spinner_button = gtk_spin_button_new(
        GTK_ADJUSTMENT(instance->control_channel_spinner_adjustment),
        CLIMB_RATE_SPINNER_BUTTON_CHANNEL_CONTROL,
        DIGITS_SPINNER_BUTTON_CHANNEL_CONTROL
    );

    if (!GTK_IS_SPIN_BUTTON(instance->control_channel_spinner_button))
    {
        g_critical(FAILED_MALLOC_CHANNEL_CONTROL);
        destroy_rpi_channel_control(instance);
        return NULL;
    }

    gchar tooltip_text_spinner[23] = {0};
    g_snprintf(tooltip_text_spinner, sizeof(tooltip_text_spinner), "Set level at channel %d", channel_id);
    gtk_widget_set_tooltip_text(GTK_WIDGET(instance->control_channel_spinner_button), tooltip_text_spinner);
    gchar text_check_box[7] = {0};
    g_snprintf(text_check_box, sizeof(text_check_box), "GPIO %d", channel_id);
    instance->control_channel_gpio_check_box = gtk_check_button_new_with_label(text_check_box);

    if (!GTK_IS_CHECK_BUTTON(instance->control_channel_gpio_check_box))
    {
        g_critical(FAILED_MALLOC_CHANNEL_CONTROL);
        destroy_rpi_channel_control(instance);
        return NULL;
    }

    gchar tooltip_text_check_box[14] = {0};
    g_snprintf(tooltip_text_check_box, sizeof(tooltip_text_check_box), "Active GPIO %d", channel_id);
    gtk_widget_set_tooltip_text(GTK_WIDGET(instance->control_channel_gpio_check_box), tooltip_text_check_box);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(instance->control_channel_gpio_check_box), FALSE);

    return instance;
}

void show_rpi_channel_control(RPIChannelControl *instance)
{
    if (instance)
    {
        gboolean is_vertical_bar = GTK_IS_VB(instance->control_channel_vertical_bar);
        gboolean is_vertical_bar_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_vertical_bar));
        
        if (is_vertical_bar && is_vertical_bar_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->control_channel_vertical_bar));
        }

        gboolean is_scale = GTK_IS_SCALE(instance->control_channel_scale);
        gboolean is_scale_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_scale));

        if (is_scale && is_scale_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->control_channel_scale));
        }

        gboolean is_adjustment = GTK_IS_ADJUSTMENT(instance->control_channel_spinner_adjustment);
        gboolean is_adjustment_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_spinner_adjustment));

        if (is_adjustment && is_adjustment_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->control_channel_spinner_adjustment));
        }

        gboolean is_spin_button = GTK_IS_SPIN_BUTTON(instance->control_channel_spinner_button);
        gboolean is_spin_button_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_spinner_button));

        if (is_spin_button && is_spin_button_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->control_channel_spinner_button));
        }

        gboolean is_check_button = GTK_IS_CHECK_BUTTON(instance->control_channel_gpio_check_box);
        gboolean is_check_button_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_gpio_check_box));

        if (is_check_button && is_check_button_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->control_channel_gpio_check_box));
        }
    }
}

void hide_rpi_channel_control(RPIChannelControl *instance)
{
    if (instance)
    {
        gboolean is_vertical_bar = GTK_IS_VB(instance->control_channel_vertical_bar);
        gboolean is_vertical_bar_visible = gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_vertical_bar));
        
        if (is_vertical_bar && is_vertical_bar_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->control_channel_vertical_bar));
        }

        gboolean is_scale = GTK_IS_SCALE(instance->control_channel_scale);
        gboolean is_scale_visible = gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_scale));

        if (is_scale && is_scale_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->control_channel_scale));
        }

        gboolean is_adjustment = GTK_IS_ADJUSTMENT(instance->control_channel_spinner_adjustment);
        gboolean is_adjustment_visible = gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_spinner_adjustment));

        if (is_adjustment && is_adjustment_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->control_channel_spinner_adjustment));
        }

        gboolean is_spin_button = GTK_IS_SPIN_BUTTON(instance->control_channel_spinner_button);
        gboolean is_spin_button_visible = gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_spinner_button));

        if (is_spin_button && is_spin_button_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->control_channel_spinner_button));
        }

        gboolean is_check_button = GTK_IS_CHECK_BUTTON(instance->control_channel_gpio_check_box);
        gboolean is_check_button_visible = gtk_widget_get_visible(GTK_WIDGET(instance->control_channel_gpio_check_box));

        if (is_check_button && is_check_button_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->control_channel_gpio_check_box));
        }
    }
}

GtkVB* get_vertical_bar_from_rpi_channel_control(RPIChannelControl *instance)
{
    if (instance)
    {
        gboolean is_vertical_bar = GTK_IS_VB(instance->control_channel_vertical_bar);

        if (is_vertical_bar)
        {
            return instance->control_channel_vertical_bar;
        }
    }

    return NULL;
}

GtkWidget* get_scale_from_rpi_channel_control(RPIChannelControl *instance)
{
    if (instance)
    {
        gboolean is_scale = GTK_IS_SCALE(instance->control_channel_scale);

        if (is_scale)
        {
            return instance->control_channel_scale;
        }
    }

    return NULL;
}

GtkWidget* get_spinner_button_from_rpi_channel_control(RPIChannelControl *instance)
{
    if (instance)
    {
        gboolean is_spinner_button = GTK_IS_SPIN_BUTTON(instance->control_channel_spinner_button);

        if (is_spinner_button)
        {
            return instance->control_channel_spinner_button;
        }
    }

    return NULL;
}

GtkWidget* get_check_box_from_rpi_channel_control(RPIChannelControl *instance)
{
    if (instance)
    {
        gboolean is_check_box = GTK_IS_CHECK_BUTTON(instance->control_channel_gpio_check_box);

        if (is_check_box)
        {
            return instance->control_channel_gpio_check_box;
        }
    }

    return NULL;
}

void destroy_rpi_channel_control(RPIChannelControl *instance)
{
    if (instance)
    {
        if (GTK_IS_VB(instance->control_channel_vertical_bar))
        {
            gtk_vb_destroy(instance->control_channel_vertical_bar);
            instance->control_channel_vertical_bar = NULL;
        }

        if (GTK_IS_SCALE(instance->control_channel_scale))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->control_channel_scale));
            instance->control_channel_scale = NULL;
        }

        if (GTK_IS_ADJUSTMENT(instance->control_channel_spinner_adjustment))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->control_channel_spinner_adjustment));
            instance->control_channel_spinner_adjustment = NULL;
        }
        
        if (GTK_IS_SPIN_BUTTON(instance->control_channel_spinner_button))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->control_channel_spinner_button));
            instance->control_channel_spinner_button = NULL;
        }

        if (GTK_IS_CHECK_BUTTON(instance->control_channel_gpio_check_box))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->control_channel_gpio_check_box));
            instance->control_channel_gpio_check_box = NULL;
        }

        g_free(instance);
    }
}
