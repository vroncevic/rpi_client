/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * tablesettings.h
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
#ifndef __TABLESETTINGS_H
#define __TABLESETTINGS_H

#include "controlexit.h"
#include "entryaddress.h"
#include "entryport.h"

#define TABLE_ROWS_TABLESETTINGS		   2
#define TABLE_COLS_TABLESETTINGS		   1
#define TABLE_ROW_SPACINGS_TABLESETTINGS   10
#define TABLE_COL_SPACINGS_TABLESETTINGS   10

typedef struct {
	GtkWidget *table;
	ControlExit *check_exit;
	EntryAddress *entry_ip_address;
	EntryPort *entry_port_number;
} TableSettings;

TableSettings * new_table_settings();
void show_table_settings(TableSettings *table_settings_ptr);
void hide_table_settings(TableSettings *table_settings_ptr);
void destroy_table_settings(TableSettings *table_settings_ptr);

#endif

