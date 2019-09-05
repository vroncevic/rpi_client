/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * verticalbar.h
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
#ifndef __VERTICALBAR_H
#define __VERTICALBAR_H

#include "resource.h"

G_BEGIN_DECLS

#define GTK_VB(obj) GTK_CHECK_CAST(obj, gtk_vb_get_type (), GtkVB)
#define GTK_VB_CLASS(klass) GTK_CHECK_CLASS_CAST(klass, gtk_vb_get_type(), GtkVBClass)
#define GTK_IS_VB(obj) GTK_CHECK_TYPE(obj, gtk_vb_get_type())

typedef struct _GtkVB GtkVB;
typedef struct _GtkVBClass GtkVBClass;

struct _GtkVB {
	GtkWidget widget;
	gint sel;
};

struct _GtkVBClass {
	GtkWidgetClass parent_class;
};

GtkWidget * gtk_vb_new();
void gtk_vb_set_state(GtkVB *vb, gint num);
void gtk_vb_set_sel(GtkVB *vb, gint sel);
void gtk_vb_destroy(GtkObject *object);

G_END_DECLS

#endif

