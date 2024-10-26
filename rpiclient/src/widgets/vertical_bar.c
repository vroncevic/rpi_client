/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * vertical_bar.c
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
#include "vertical_bar.h"

static void gtk_vb_class_init(GtkVBClass *klass);
static void gtk_vb_init(GtkVB *cpu);
static void gtk_vb_size_request(GtkWidget *widget, GtkRequisition *req);
static void gtk_vb_size_allocate(GtkWidget *widget, GtkAllocation *allocation);
static void gtk_vb_realize(GtkWidget *widget);
static gboolean gtk_vb_expose(GtkWidget *widget, GdkEventExpose *event);
static void gtk_vb_paint(GtkWidget *widget);

GtkType gtk_vb_get_type(void)
{
    static GtkType gtk_vb_type = 0;

    if (!gtk_vb_type)
    {
        static const GtkTypeInfo gtk_vb_info =
        {
            "GtkVB",
            sizeof(GtkVB),
            sizeof(GtkVBClass),
            (GtkClassInitFunc) gtk_vb_class_init,
            (GtkObjectInitFunc) gtk_vb_init,
            NULL,
            NULL,
            (GtkClassInitFunc) NULL
        };

        gtk_vb_type = gtk_type_unique(GTK_TYPE_WIDGET, &gtk_vb_info);
    }

    return gtk_vb_type;
}

void gtk_vb_set_state(GtkVB *vb, gint num)
{
    vb->sel = num;
    gtk_vb_paint(GTK_WIDGET(vb));
}

GtkWidget *gtk_vb_new(void)
{
    return GTK_WIDGET(gtk_type_new(gtk_vb_get_type()));
}

static void gtk_vb_class_init(GtkVBClass *klass)
{
    GtkWidgetClass *widget_class;
    GtkObjectClass *object_class;
    widget_class = (GtkWidgetClass *)klass;
    object_class = (GtkObjectClass *)klass;
    widget_class->realize = gtk_vb_realize;
    widget_class->size_request = gtk_vb_size_request;
    widget_class->size_allocate = gtk_vb_size_allocate;
    widget_class->expose_event = gtk_vb_expose;
    object_class->destroy = gtk_vb_destroy;
}

static void gtk_vb_init(GtkVB *vb)
{
    vb->sel = 0;
}

static void gtk_vb_size_request(GtkWidget *widget, GtkRequisition *req)
{
    g_return_if_fail(widget != NULL);
    g_return_if_fail(GTK_IS_VB(widget));
    g_return_if_fail(req != NULL);
    req->width = 80;
    req->height = 100;
}

static void gtk_vb_size_allocate(GtkWidget *widget, GtkAllocation *allocation)
{
    g_return_if_fail(widget != NULL);
    g_return_if_fail(GTK_IS_VB(widget));
    g_return_if_fail(allocation != NULL);
    widget->allocation = *allocation;

    if (GTK_WIDGET_REALIZED(widget))
    {
        gdk_window_move_resize(widget->window, allocation->x, allocation->y, allocation->width, allocation->height);
    }
}

static void gtk_vb_realize(GtkWidget *widget)
{
    GdkWindowAttr attributes;
    guint attributes_mask;
    g_return_if_fail(widget != NULL);
    g_return_if_fail(GTK_IS_VB(widget));
    GTK_WIDGET_SET_FLAGS(widget, GTK_REALIZED);
    attributes.window_type = GDK_WINDOW_CHILD;
    attributes.x = widget->allocation.x;
    attributes.y = widget->allocation.y;
    attributes.width = 80;
    attributes.height = 100;
    attributes.wclass = GDK_INPUT_OUTPUT;
    attributes.event_mask = gtk_widget_get_events(widget) | GDK_EXPOSURE_MASK;
    attributes_mask = GDK_WA_X | GDK_WA_Y;
    widget->window = gdk_window_new(gtk_widget_get_parent_window(widget), &attributes, attributes_mask);
    gdk_window_set_user_data(widget->window, widget);
    widget->style = gtk_style_attach(widget->style, widget->window);
    gtk_style_set_background(widget->style, widget->window, GTK_STATE_NORMAL);
}

static gboolean gtk_vb_expose(GtkWidget *widget, GdkEventExpose *event)
{
    g_return_val_if_fail(widget != NULL, FALSE);
    g_return_val_if_fail(GTK_IS_VB(widget), FALSE);
    g_return_val_if_fail(event != NULL, FALSE);
    gtk_vb_paint(widget);
    return FALSE;
}

static void gtk_vb_paint(GtkWidget *widget)
{
    cairo_t *cr = gdk_cairo_create(widget->window);
    cairo_translate(cr, 0, 7);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_paint(cr);
    gint pos = GTK_VB(widget)->sel;
    gint rect = pos / 5;
    cairo_set_source_rgb(cr, 0.2, 0.4, 0);
    gint i;

    for (i = 1; i <= 20; i++)
    {
        if (i > 20 - rect)
        {
            cairo_set_source_rgb(cr, 0.6, 1.0, 0);
        }
        else
        {
            cairo_set_source_rgb(cr, 0.2, 0.4, 0);
        }

        cairo_rectangle(cr, 8, i * 4, 30, 3);
        cairo_rectangle(cr, 42, i * 4, 30, 3);
        cairo_fill(cr);
    }

    cairo_destroy(cr);
}

void gtk_vb_destroy(GtkObject *instance)
{ 
    if (instance && GTK_IS_VB(instance))
    {
        GtkVB *vb = GTK_VB(instance);
        GtkVBClass *klass = gtk_type_class(gtk_widget_get_type());

        if (GTK_OBJECT_CLASS(klass)->destroy)
        {
            (*GTK_OBJECT_CLASS(klass)->destroy)(instance);
        }
    }
}
