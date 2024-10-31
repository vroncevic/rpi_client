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

#define GTK_VB(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), gtk_vb_get_type(), GtkVB))
#define GTK_IS_VB(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), gtk_vb_get_type()))

typedef struct
{
    GtkDrawingArea parent_instance;
    gint sel;
} GtkVB;

typedef struct
{
    GtkDrawingAreaClass parent_class;
} GtkVBClass;

G_DEFINE_TYPE(GtkVB, gtk_vb, GTK_TYPE_DRAWING_AREA)

GtkWidget *gtk_vb_new(void);
void gtk_vb_set_state(GtkVB *vb, gint num);

G_END_DECLS
