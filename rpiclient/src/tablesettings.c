/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * tablesettings.c
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
#include "tablesettings.h"

TableSettings * new_table_settings() {
    TableSettings *table_settings_ptr = g_malloc(sizeof(TableSettings));
    table_settings_ptr->table = gtk_table_new(
        TABLE_ROWS_TABLESETTINGS, TABLE_COLS_TABLESETTINGS, TRUE
    );
    gtk_table_set_row_spacings(
        GTK_TABLE(table_settings_ptr->table), TABLE_ROW_SPACINGS_TABLESETTINGS
    );
    gtk_table_set_col_spacings(
        GTK_TABLE(table_settings_ptr->table), TABLE_COL_SPACINGS_TABLESETTINGS
    );
    table_settings_ptr->check_exit = new_control_exit();
    table_settings_ptr->entry_ip_address = new_entry_address();
    table_settings_ptr->entry_port_number = new_entry_port();
    gtk_table_attach_defaults(
        GTK_TABLE(table_settings_ptr->table),
        table_settings_ptr->check_exit->frame, 0, 1, 0, 1
    );
    gtk_table_attach_defaults(
        GTK_TABLE(table_settings_ptr->table),
        table_settings_ptr->entry_ip_address->frame, 0, 1, 1, 2
    );
    gtk_table_attach_defaults(
        GTK_TABLE(table_settings_ptr->table),
        table_settings_ptr->entry_port_number->frame, 0, 1, 2, 3
    );
    return table_settings_ptr;
}

void show_table_settings(TableSettings *table_settings_ptr) {
    if(table_settings_ptr) {
        gtk_widget_show_all(table_settings_ptr->table);
    }
}

void hide_table_settings(TableSettings *table_settings_ptr) {
    if(table_settings_ptr) {
        gtk_widget_hide_all(table_settings_ptr->table);
    }
}

void destroy_table_settings(TableSettings *table_settings_ptr) {
    if(table_settings_ptr) {
        destroy_control_exit(table_settings_ptr->check_exit);
        destroy_entry_address(table_settings_ptr->entry_ip_address);
        destroy_entry_port(table_settings_ptr->entry_port_number);
        gtk_widget_destroy(table_settings_ptr->table);
        g_free(table_settings_ptr->check_exit);
        g_free(table_settings_ptr->entry_ip_address);
        g_free(table_settings_ptr->entry_port_number);
        g_free(table_settings_ptr->table);
        g_free(table_settings_ptr);
    }
}

