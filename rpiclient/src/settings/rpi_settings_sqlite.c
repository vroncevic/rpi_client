/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_sqlite.c
 * Copyright (C) 2016 - 2025 Vladimir Roncevic <elektron.ronca@gmail.com>
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
#include <stdio.h>
#include <sqlite3.h>
#include "rpi_settings_sqlite.h"

static sqlite3 *db = NULL;
static const gchar* CONFIGURATION_SQLITE3_FILE = "/home/%s/.rpiclient/config/rpiclient.db";

static gint rpi_settings_sqlite_exec(const gchar* query);

gint rpi_settings_sqlite_open(const gchar* db_name)
{
    gint res = sqlite3_open(db_name, &db);

    if (res != SQLITE_OK)
    {
        g_error("ERROR opening SQLite DB in memory: %s\n", sqlite3_errmsg(db));
        return res;
    }

    return res;
}

static gint rpi_settings_sqlite_exec(const gchar* query)
{
    const gchar* error_msg;
    sqlite3_stmt* stmt; 
    gint res = sqlite3_prepare_v2(db, query, -1, &stmt, &error_msg);
    printf("Statement: %s\n", query);
    printf("Result: ");

    if (res != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_close(db);
        return res;
    }
    else
    {
        if (strchr(query, '?') != NULL)
        {
            sqlite3_bind_int(stmt, 1, sqlite3_last_insert_rowid(db));
        }
    }

    while ((res = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        printf("%d\t%s\t%d\n",
            sqlite3_column_int(stmt, 0),
            sqlite3_column_text(stmt, 1),
            sqlite3_column_int(stmt, 2));
    }

    printf("\n");
    sqlite3_finalize(stmt);
    return res;
}

gint rpi_settings_sqlite_close()
{
    gint res = sqlite3_close(db);

    if (res != SQLITE_OK)
    {
        g_error("Error closing database\n");
        return res;
    }

    return res;
}
