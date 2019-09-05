/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * entryport.c
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
#include "entryport.h"

EntryPort * new_entry_port() {
    EntryPort *entry_port_ptr = g_malloc(sizeof(EntryPort));
    entry_port_ptr->frame = gtk_frame_new(TEXT_FRAME_ENTRY_PORT);
    gtk_frame_set_shadow_type(GTK_FRAME(entry_port_ptr->frame), GTK_SHADOW_IN);
    entry_port_ptr->entry = gtk_entry_new();
    gtk_entry_set_max_length(
        GTK_ENTRY(entry_port_ptr->entry), MAX_LENGTH_ENTRY_PORT
    );
    gint len = GTK_ENTRY(entry_port_ptr->entry)->text_length;
    entry_port_ptr->cur_pos_port = len;
    gtk_editable_insert_text(
        GTK_EDITABLE(entry_port_ptr->entry),
        TEXT_EXAMPLE_ENTRY_PORT, NEW_TEXT_LENGTH_ENTRY_PORT,
        &(entry_port_ptr->cur_pos_port)
    );
    gtk_editable_select_region(
        GTK_EDITABLE(entry_port_ptr->entry), START_POSITION_ENTRY_PORT,
        GTK_ENTRY(entry_port_ptr->entry)->text_length
    );
    gtk_container_add(
        GTK_CONTAINER(entry_port_ptr->frame), entry_port_ptr->entry
    );
    return entry_port_ptr;
}

void show_entry_port(EntryPort *entry_port_ptr) {
    if(entry_port_ptr) {
        gtk_widget_show_all(entry_port_ptr->frame);
    }
}

void hide_entry_port(EntryPort *entry_port_ptr) {
    if(entry_port_ptr) {
        gtk_widget_hide_all(entry_port_ptr->frame);
    }
}

void destroy_entry_port(EntryPort *entry_port_ptr) {
    if(entry_port_ptr) {
        gtk_widget_destroy(entry_port_ptr->entry);
        gtk_widget_destroy(entry_port_ptr->frame);
        g_free(entry_port_ptr->entry);
        g_free(entry_port_ptr->frame);
        g_free(entry_port_ptr);
    }
}

