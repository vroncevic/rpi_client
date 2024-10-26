/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * vertical_bar.h
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
#pragma once

#include "../resource/resource.h"

G_BEGIN_DECLS

#define GTK_VB(obj) GTK_CHECK_CAST(obj, gtk_vb_get_type(), GtkVB)
#define GTK_VB_CLASS(klass) GTK_CHECK_CLASS_CAST(klass, gtk_vb_get_type(), GtkVBClass)
#define GTK_IS_VB(obj) GTK_CHECK_TYPE(obj, gtk_vb_get_type())

//////////////////////////////////////////////////////////////////////////////
/// @brief Vertical bar complex widget
///   widget - Gtk about dialog widget
///   sel - 
typedef struct
{
    GtkWidget widget;
    gint sel;
} GtkVB;

//////////////////////////////////////////////////////////////////////////////
/// @brief Vertical bar complex widget class
///   parent_class - Gtk widget parent class
typedef struct
{
    GtkWidgetClass parent_class;
} GtkVBClass;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget vertical bar
/// @return Vertical bar complex widget pointer
GtkWidget *gtk_vb_new(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Set state to vertical bar complex widget
/// @param vb is pointer to complex widget vertical bar
/// @param num is 
void gtk_vb_set_state(GtkVB *vb, gint num);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy vertical bar complex widget
/// @param instance is pointer to complex widget vertical bar
void gtk_vb_destroy(GtkObject *instance);

G_END_DECLS
