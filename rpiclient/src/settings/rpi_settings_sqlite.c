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
#include "rpi_settings_user.h"
#include "rpi_settings_sqlite.h"

#define CONFIGURATION_SQLITE3_FILE_SETTINGS_SQLITE "/home/%s/.rpiclient/config/rpiclient.db"
#define SQL_SELECT_SETTINGS_SQLITE "SELECT"
#define SQL_SELECT_NO_PROMPT_SETTINGS_SQLITE "SELECT no_prompt FROM settings WHERE id = 1;"
#define SQL_SELECT_IP_ADDRESS_SETTINGS_SQLITE "SELECT ip_address FROM settings WHERE id = 1;"
#define SQL_SELECT_PORT_NUMBER_SETTINGS_SQLITE "SELECT port_number FROM settings WHERE id = 1;"
#define SQL_SELECT_NO_EXIT_SETTINGS_SQLITE "SELECT no_exit FROM settings WHERE id = 1;"
#define SQL_UPDATE_NO_PROMPT_SETTINGS_SQLITE "UPDATE settings SET no_prompt = '%s' WHERE id = 1;"
#define SQL_UPDATE_IP_ADDRESS_SETTINGS_SQLITE "UPDATE settings SET ip_address = '%s' WHERE id = 1;"
#define SQL_UPDATE_PORT_NUMBER_SETTINGS_SQLITE "UPDATE settings SET port_number = '%s' WHERE id = 1;"
#define SQL_UPDATE_NO_EXIT_SETTINGS_SQLITE "UPDATE settings SET no_exit = '%s' WHERE id = 1;"

static sqlite3 *db = NULL;
static const gchar* WARNING_LOG_FAILED_UPDATE_NO_PROMPT_SETTINGS_SQLITE = "Can't update no_prompt parameter.\n";
static const gchar* WARNING_LOG_FAILED_UPDATE_IP_ADDRESS_SETTINGS_SQLITE = "Can't update ip_address parameter.\n";
static const gchar* WARNING_LOG_FAILED_UPDATE_PORT_NUMBER_SETTINGS_SQLITE = "Can't update port_number parameter.\n";
static const gchar* WARNING_LOG_FAILED_UPDATE_NO_EXIT_SETTINGS_SQLITE = "Can't update no_exit parameter.\n";
static const gchar* WARNING_LOG_FAILED_OPEN_DB_MISSING_NAME_SETTINGS_SQLITE = "Can't open database, missing name.\n";
static const gchar* WARNING_LOG_FAILED_EXEC_DB_MISSING_QUERY_SETTINGS_SQLITE = "Missing query for sqlite exec.\n";
static const gchar* WARNING_LOG_FAILED_EXEC_DB_PATH_SETTINGS_SQLITE = "Can't prepare database path.\n";
static const gchar* WARNING_LOG_FAILED_CLOSE_DB2_SETTINGS_SQLITE = "Database is already closed or was never opened.";

static void rpi_settings_sqlite_open(const gchar* db_name);
static gint rpi_settings_sqlite_exec(const gchar* querry, gchar** result);
static void rpi_settings_sqlite_close(void);

static void rpi_settings_sqlite_open(const gchar* db_name)
{
    if(!db_name)
    {
        g_warning("%s", WARNING_LOG_FAILED_OPEN_DB_MISSING_NAME_SETTINGS_SQLITE);
        return;
    }

    gint status = sqlite3_open(db_name, &db);

    if (status != SQLITE_OK)
    {
        g_warning("%s", sqlite3_errmsg(db));
    }
}

static gint rpi_settings_sqlite_exec(const gchar* query, gchar** result)
{
    if(!query)
    {
        g_warning("%s", WARNING_LOG_FAILED_EXEC_DB_MISSING_QUERY_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gchar* username = rpi_get_username_settings_user();

    if (!username)
    {
        return FAILED_SETTINGS_SQLITE;
    }

    gchar* db_name = g_strdup_printf(CONFIGURATION_SQLITE3_FILE_SETTINGS_SQLITE, username);

    if (!db_name)
    {
        g_warning("%s", WARNING_LOG_FAILED_EXEC_DB_PATH_SETTINGS_SQLITE);
        g_free(username);
        return FAILED_SETTINGS_SQLITE;
    }

    g_free(username);
    rpi_settings_sqlite_open(db_name);
    gint status = FAILED_SETTINGS_SQLITE;

    if (db)
    {
        //////////////////////////////////////////////////////////////////////
        /// Create table if not exists
        const char *sql_create_table =
            "CREATE TABLE IF NOT EXISTS settings ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "no_prompt TEXT, "
            "ip_address TEXT, "
            "port_number TEXT,"
            "no_exit TEXT);";
        gchar *error_message = NULL;
        status = sqlite3_exec(db, sql_create_table, 0, 0, &error_message);

        if (status != SQLITE_OK)
        {
            if (error_message)
            {
                g_warning("%s\n", error_message);
            }

            rpi_settings_sqlite_close();
            g_free(error_message);
            g_free(db_name);
            return status;
        }

        if (g_str_has_prefix(query, SQL_SELECT_SETTINGS_SQLITE))
        {
            //////////////////////////////////////////////////////////////////
            /// Execute SELECT queries
            sqlite3_stmt* statement;
            status = sqlite3_prepare_v2(db, query, -1, &statement, NULL);

            if (status != SQLITE_OK)
            {
                g_warning("%s\n", sqlite3_errmsg(db));
                rpi_settings_sqlite_close();
                g_free(db_name);
                return status;
            }

            status = sqlite3_step(statement);

            if (status == SQLITE_ROW)
            {
                const char* value = (const char*)sqlite3_column_text(statement, 0);

                if (result)
                {
                    *result = g_strdup(value);
                }
            }
            else
            {
                g_warning("%s\n", sqlite3_errmsg(db));
            }

            sqlite3_finalize(statement);
        }
        else
        {
            //////////////////////////////////////////////////////////////////
            /// Execute non-SELECT queries
            status = sqlite3_exec(db, query, 0, 0, &error_message);

            if (status != SQLITE_OK)
            {
                if (error_message)
                {
                    g_warning("%s\n", error_message);
                }

                rpi_settings_sqlite_close();
                g_free(error_message);
                g_free(db_name);
                return status;
            }
        }

        status = SUCCESS_SETTINGS_SQLITE;
    }

    rpi_settings_sqlite_close();
    g_free(db_name);
    return status;
}

gchar* rpi_read_no_prompt_settings_sqlite(void)
{
    gchar* no_prompt = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_NO_PROMPT_SETTINGS_SQLITE, &no_prompt);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

    return ok_status ? no_prompt : NULL;
}

gint rpi_write_no_prompt_settings_sqlite(const gchar* no_prompt)
{
    if (!no_prompt)
    {
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_no_prompt = g_strdup_printf(SQL_UPDATE_NO_PROMPT_SETTINGS_SQLITE, no_prompt);

    if (!sql_update_no_prompt)
    {
        g_warning("%s", WARNING_LOG_FAILED_UPDATE_NO_PROMPT_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_no_prompt, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_no_prompt);

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

gchar* rpi_read_ip_address_settings_sqlite(void)
{
    gchar* ip_address = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_IP_ADDRESS_SETTINGS_SQLITE, &ip_address);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

    return ok_status ? ip_address : NULL;
}

gint rpi_write_ip_address_settings_sqlite(const gchar* ip_address)
{
    if (!ip_address)
    {
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_ip_address = g_strdup_printf(SQL_UPDATE_IP_ADDRESS_SETTINGS_SQLITE, ip_address);

    if (!sql_update_ip_address)
    {
        g_warning("%s", WARNING_LOG_FAILED_UPDATE_IP_ADDRESS_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_ip_address, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_ip_address);

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

gchar* rpi_read_port_number_settings_sqlite(void)
{
    gchar* port_number = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_PORT_NUMBER_SETTINGS_SQLITE, &port_number);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

    return ok_status ? port_number : NULL;
}

gint rpi_write_port_number_settings_sqlite(const gchar* port_number)
{
    if (!port_number)
    {
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_port_number = g_strdup_printf(SQL_UPDATE_PORT_NUMBER_SETTINGS_SQLITE, port_number);

    if (!sql_update_port_number)
    {
        g_warning("%s", WARNING_LOG_FAILED_UPDATE_PORT_NUMBER_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_port_number, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_port_number);

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

gchar* rpi_read_no_exit_settings_sqlite(void)
{
    gchar* no_exit = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_NO_EXIT_SETTINGS_SQLITE, &no_exit);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

    return ok_status ? no_exit : NULL;
}

gint rpi_write_no_exit_settings_sqlite(const gchar* no_exit)
{
    if (!no_exit)
    {
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_no_exit = g_strdup_printf(SQL_UPDATE_NO_EXIT_SETTINGS_SQLITE, no_exit);

    if (!sql_update_no_exit)
    {
        g_warning("%s", WARNING_LOG_FAILED_UPDATE_NO_EXIT_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_no_exit, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_no_exit);

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

static void rpi_settings_sqlite_close(void)
{
    if (!db)
    {
        g_warning("%s", WARNING_LOG_FAILED_CLOSE_DB2_SETTINGS_SQLITE);
        return;
    }

    gint status = sqlite3_close(db);

    if (status != SQLITE_OK)
    {
        g_warning("%s\n", sqlite3_errmsg(db));
        return;
    }

    db = NULL;
}
