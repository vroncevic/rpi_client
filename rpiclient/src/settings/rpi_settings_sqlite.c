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
#include <sqlite3.h>
#include "rpi_settings.h"
#include "rpi_settings_user.h"
#include "rpi_settings_sqlite.h"

#if RPI_VERBOSE == 1
#define NO_PROMPT_READ_SETTINGS_SQLITE "Read from database no_prompt: %s.\n"
#define NO_PROMPT_WRITE_SETTINGS_SQLITE "Write to database no_prompt: %s.\n"
#define IP_ADDRESS_READ_SETTINGS_SQLITE "Read from database IP server address: %s.\n"
#define IP_ADDRESS_WRITE_SETTINGS_SQLITE "Write to database IP server address: %s.\n"
#define PORT_NUMBER_READ_SETTINGS_SQLITE "Read from database server port number: %s.\n"
#define PORT_NUMBER_WRITE_SETTINGS_SQLITE "Write to database server port number: %s.\n"
#define NO_EXIT_READ_SETTINGS_SQLITE "Read from database no_exit: %s.\n"
#define NO_EXIT_WRITE_SETTINGS_SQLITE "Write to database no_exit: %s.\n"
#define OPEN_DB_SETTINGS_SQLITE "Successfully opened database: %s.\n"
#define CLOSE_DB_SETTINGS_SQLITE "Successfully closed database.\n"
#define SQL_DB_SETTINGS_SQLITE "SQL query: %s.\n"
#endif

#define CONFIGURATION_FILE_SETTINGS_SQLITE "/home/%s/.rpiclient/config/rpiclient.db"
#define SQL_SELECT_SETTINGS_SQLITE "SELECT"
#define SQL_SELECT_NO_PROMPT_SETTINGS_SQLITE "SELECT no_prompt FROM settings WHERE id = 1;"
#define SQL_SELECT_IP_ADDRESS_SETTINGS_SQLITE "SELECT ip_address FROM settings WHERE id = 1;"
#define SQL_SELECT_PORT_NUMBER_SETTINGS_SQLITE "SELECT port_number FROM settings WHERE id = 1;"
#define SQL_SELECT_NO_EXIT_SETTINGS_SQLITE "SELECT no_exit FROM settings WHERE id = 1;"
#define SQL_UPDATE_NO_PROMPT_SETTINGS_SQLITE "UPDATE settings SET no_prompt = '%s' WHERE id = 1;"
#define SQL_UPDATE_IP_ADDRESS_SETTINGS_SQLITE "UPDATE settings SET ip_address = '%s' WHERE id = 1;"
#define SQL_UPDATE_PORT_NUMBER_SETTINGS_SQLITE "UPDATE settings SET port_number = '%s' WHERE id = 1;"
#define SQL_UPDATE_NO_EXIT_SETTINGS_SQLITE "UPDATE settings SET no_exit = '%s' WHERE id = 1;"

#define MISSING_NO_PROMPT_PARAMETER_SETTINGS_SQLITE "Missing prompt parameter.\n"
#define MISSING_IP_ADDRESS_PARAMETER_SETTINGS_SQLITE "Missing server IP address parameter.\n"
#define MISSING_PORT_NUMBER_PARAMETER_SETTINGS_SQLITE "Missing server port number parameter.\n"
#define MISSING_EXIT_PARAMETER_SETTINGS_SQLITE "Missing exit parameter.\n"

#define FAILED_UPDATE_NO_PROMPT_SETTINGS_SQLITE "Can't update no_prompt parameter.\n"
#define FAILED_UPDATE_IP_ADDRESS_SETTINGS_SQLITE "Can't update ip_address parameter.\n"
#define FAILED_UPDATE_PORT_NUMBER_SETTINGS_SQLITE "Can't update port_number parameter.\n"
#define FAILED_UPDATE_NO_EXIT_SETTINGS_SQLITE "Can't update no_exit parameter.\n"
#define FAILED_OPEN_DB_MISSING_NAME_SETTINGS_SQLITE "Can't open database, missing name.\n"
#define FAILED_EXEC_DB_MISSING_QUERY_SETTINGS_SQLITE "Missing query for sqlite exec.\n"
#define FAILED_EXEC_DB_PATH_SETTINGS_SQLITE "Can't prepare database path.\n"
#define FAILED_CLOSE_DB_SETTINGS_SQLITE "Database is already closed or was never opened.\n"
#define FAILED_SQL_ERROR_SETTINGS_SQLITE "SQL error: %s.\n"

static sqlite3 *db = NULL;
static void rpi_settings_sqlite_open(const gchar* db_name);
static gint rpi_settings_sqlite_exec(const gchar* querry, gchar** result);
static void rpi_settings_sqlite_close(void);

gchar* rpi_read_no_prompt_settings_sqlite(void)
{
    gchar* no_prompt = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_NO_PROMPT_SETTINGS_SQLITE, &no_prompt);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

#if RPI_VERBOSE == 1
    g_debug(NO_PROMPT_READ_SETTINGS_SQLITE, no_prompt);
#endif

    return ok_status ? no_prompt : NULL;
}

gint rpi_write_no_prompt_settings_sqlite(const gchar* no_prompt)
{
    if (!no_prompt)
    {
        g_critical(MISSING_NO_PROMPT_PARAMETER_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_no_prompt = g_strdup_printf(SQL_UPDATE_NO_PROMPT_SETTINGS_SQLITE, no_prompt);

    if (!sql_update_no_prompt)
    {
        g_critical(FAILED_UPDATE_NO_PROMPT_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_no_prompt, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_no_prompt);
    sql_update_no_prompt = NULL;

#if RPI_VERBOSE == 1
    g_debug(NO_PROMPT_WRITE_SETTINGS_SQLITE, no_prompt);
#endif

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

gchar* rpi_read_ip_address_settings_sqlite(void)
{
    gchar* ip_address = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_IP_ADDRESS_SETTINGS_SQLITE, &ip_address);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

#if RPI_VERBOSE == 1
    g_debug(IP_ADDRESS_READ_SETTINGS_SQLITE, ip_address);
#endif

    return ok_status ? ip_address : NULL;
}

gint rpi_write_ip_address_settings_sqlite(const gchar* ip_address)
{
    if (!ip_address)
    {
        g_critical(MISSING_IP_ADDRESS_PARAMETER_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_ip_address = g_strdup_printf(SQL_UPDATE_IP_ADDRESS_SETTINGS_SQLITE, ip_address);

    if (!sql_update_ip_address)
    {
        g_critical(FAILED_UPDATE_IP_ADDRESS_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_ip_address, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_ip_address);
    sql_update_ip_address = NULL;

#if RPI_VERBOSE == 1
    g_debug(IP_ADDRESS_WRITE_SETTINGS_SQLITE, ip_address);
#endif

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

gchar* rpi_read_port_number_settings_sqlite(void)
{
    gchar* port_number = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_PORT_NUMBER_SETTINGS_SQLITE, &port_number);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

#if RPI_VERBOSE == 1
    g_debug(PORT_NUMBER_READ_SETTINGS_SQLITE, port_number);
#endif

    return ok_status ? port_number : NULL;
}

gint rpi_write_port_number_settings_sqlite(const gchar* port_number)
{
    if (!port_number)
    {
        g_critical(MISSING_PORT_NUMBER_PARAMETER_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_port_number = g_strdup_printf(SQL_UPDATE_PORT_NUMBER_SETTINGS_SQLITE, port_number);

    if (!sql_update_port_number)
    {
        g_critical(FAILED_UPDATE_PORT_NUMBER_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_port_number, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_port_number);
    sql_update_port_number = NULL;

#if RPI_VERBOSE == 1
    g_debug(PORT_NUMBER_WRITE_SETTINGS_SQLITE, port_number);
#endif

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

gchar* rpi_read_no_exit_settings_sqlite(void)
{
    gchar* no_exit = NULL;
    gint status = rpi_settings_sqlite_exec(SQL_SELECT_NO_EXIT_SETTINGS_SQLITE, &no_exit);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);

#if RPI_VERBOSE == 1
    g_debug(NO_EXIT_READ_SETTINGS_SQLITE, no_exit);
#endif

    return ok_status ? no_exit : NULL;
}

gint rpi_write_no_exit_settings_sqlite(const gchar* no_exit)
{
    if (!no_exit)
    {
        g_critical(MISSING_EXIT_PARAMETER_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gchar *sql_update_no_exit = g_strdup_printf(SQL_UPDATE_NO_EXIT_SETTINGS_SQLITE, no_exit);

    if (!sql_update_no_exit)
    {
        g_critical(FAILED_UPDATE_NO_EXIT_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gint status = rpi_settings_sqlite_exec(sql_update_no_exit, NULL);
    gboolean ok_status = (status == SQLITE_DONE || status == SUCCESS_SETTINGS_SQLITE);
    g_free(sql_update_no_exit);
    sql_update_no_exit = NULL;

#if RPI_VERBOSE == 1
    g_debug(NO_EXIT_WRITE_SETTINGS_SQLITE, no_exit);
#endif

    return ok_status ? SUCCESS_SETTINGS_SQLITE : FAILED_SETTINGS_SQLITE;
}

static void rpi_settings_sqlite_open(const gchar* db_name)
{
    if(!db_name)
    {
        g_critical(FAILED_OPEN_DB_MISSING_NAME_SETTINGS_SQLITE);
        return;
    }

    gint status = sqlite3_open(db_name, &db);

    if (status != SQLITE_OK)
    {
        g_critical(FAILED_SQL_ERROR_SETTINGS_SQLITE, sqlite3_errmsg(db));
        db = NULL;
        return;
    }

#if RPI_VERBOSE == 1
    g_debug(OPEN_DB_SETTINGS_SQLITE, db_name);
#endif
}

static gint rpi_settings_sqlite_exec(const gchar* query, gchar** result)
{
    if(!query)
    {
        g_critical(FAILED_EXEC_DB_MISSING_QUERY_SETTINGS_SQLITE);
        return FAILED_SETTINGS_SQLITE;
    }

    gchar* username = rpi_get_username_settings_user();

    if (!username)
    {
        return FAILED_SETTINGS_SQLITE;
    }

    gchar* db_name = g_strdup_printf(CONFIGURATION_FILE_SETTINGS_SQLITE, username);

    if (!db_name)
    {
        g_critical(FAILED_EXEC_DB_PATH_SETTINGS_SQLITE);
        g_free(username);
        username = NULL;
        return FAILED_SETTINGS_SQLITE;
    }

    g_free(username);
    username = NULL;
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
                g_critical(FAILED_SQL_ERROR_SETTINGS_SQLITE, error_message);
            }

            rpi_settings_sqlite_close();
            g_free(error_message);
            error_message = NULL;
            g_free(db_name);
            db_name = NULL;
            return status;
        }

        //////////////////////////////////////////////////////////////////////
        /// Insert default values if table is empty
        const char *sql_insert_default =
            "INSERT INTO settings (no_prompt, ip_address, port_number, no_exit) "
            "SELECT 'false', '192.168.1.100', '8888', 'true' "
            "WHERE NOT EXISTS (SELECT 1 FROM settings);";
        status = sqlite3_exec(db, sql_insert_default, 0, 0, &error_message);

        if (status != SQLITE_OK)
        {
            if (error_message)
            {
                g_critical(FAILED_SQL_ERROR_SETTINGS_SQLITE, error_message);
            }

            rpi_settings_sqlite_close();
            g_free(error_message);
            error_message = NULL;
            g_free(db_name);
            db_name = NULL;
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
                g_critical(FAILED_SQL_ERROR_SETTINGS_SQLITE, sqlite3_errmsg(db));
                rpi_settings_sqlite_close();
                g_free(db_name);
                db_name = NULL;
                return status;
            }

#if RPI_VERBOSE == 1
            g_debug(SQL_DB_SETTINGS_SQLITE, query);
#endif

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
                g_critical(FAILED_SQL_ERROR_SETTINGS_SQLITE, sqlite3_errmsg(db));
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
                    g_critical(FAILED_SQL_ERROR_SETTINGS_SQLITE, error_message);
                }

                rpi_settings_sqlite_close();
                g_free(error_message);
                error_message = NULL;
                g_free(db_name);
                db_name = NULL;
                return status;
            }

#if RPI_VERBOSE == 1
            g_debug(SQL_DB_SETTINGS_SQLITE, query);
#endif

        }

        status = SUCCESS_SETTINGS_SQLITE;
    }

    rpi_settings_sqlite_close();
    g_free(db_name);
    db_name = NULL;
    return status;
}

static void rpi_settings_sqlite_close(void)
{
    if (!db)
    {
        g_critical(FAILED_CLOSE_DB_SETTINGS_SQLITE);
        return;
    }

    gint status = sqlite3_close(db);

    if (status != SQLITE_OK)
    {
        g_critical(FAILED_SQL_ERROR_SETTINGS_SQLITE, sqlite3_errmsg(db));
        return;
    }

    db = NULL;

#if RPI_VERBOSE == 1
    g_debug(CLOSE_DB_SETTINGS_SQLITE);
#endif
}
