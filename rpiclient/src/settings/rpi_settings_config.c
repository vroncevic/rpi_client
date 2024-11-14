/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_config.c
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
#include "rpi_client_config.h"

#if (RPI_USE_SETTINGS_PLAIN_CONFIG == 1) && (RPI_USE_SETTINGS_SQLITE3 == 1)
#error "You cannot use both RPI_USE_SETTINGS_PLAIN_CONFIG and RPI_USE_SETTINGS_SQLITE3 at the same time!"
#endif

#if (RPI_USE_SETTINGS_PLAIN_CONFIG == 1) && (RPI_USE_SETTINGS_SQLITE3 == 0)
#include "rpi_settings_plain.h"
#endif

#if (RPI_USE_SETTINGS_PLAIN_CONFIG == 0) && (RPI_USE_SETTINGS_SQLITE3 == 1)
#include "rpi_settings_sqlite.h"
#endif

#include "rpi_settings_config.h"

#if RPI_VERBOSE == 1
#define READ_SUCCESS_SETTINGS_CONFIG "Successfully read settings.\n"
#define WRITE_SUCCESS_SETTINGS_CONFIG "Successfully write settings.\n"
#endif

#define MISSING_PARAMETER_SETTINGS_CONFIG "Missing settings parameter for write settings configuration.\n"
#define MISSING_IP_ADDRESS_PARAMETER_SETTINGS_CONFIG "Missing server IP address parameter.\n"
#define MISSING_PORT_NUMBER_PARAMETER_SETTINGS_CONFIG "Missing server port number parameter.\n"

#define FAILED_MALLOC_READ_SETTINGS_CONFIG "Failed to allocate memory for read settings configuration.\n"
#define FAILED_READ_SETTINGS_CONFIG "Failed to read settings configuration.\n"
#define FAILED_WRITE_SETTINGS_CONFIG "Failed to write settings configuration.\n"

static const gchar* TRUE_SETTINGS_CONFIG = "true";
static const gchar* FALSE_SETTINGS_CONFIG = "false";

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings configuration structure
///   no_prompt - Configuration point for prompt
///   ip_address - Configuration point for server ip address
///   port_number - Configuration point for server port number
///   no_exit - Configuration point for exit
struct _SettingsConfig
{
    gchar *no_prompt;
    gchar *ip_address;
    gchar *port_number;
    gchar *no_exit;
};

SettingsConfig* settings_read(void)
{
    SettingsConfig* instance = g_malloc(sizeof(SettingsConfig));

    if (!instance)
    {
        g_critical(FAILED_MALLOC_READ_SETTINGS_CONFIG);
        return NULL;
    }

#if (RPI_USE_SETTINGS_PLAIN_CONFIG == 1) && (RPI_USE_SETTINGS_SQLITE3 == 0)
    gchar* prompt_config = rpi_read_prompt_settings_plain_file();
    gchar* address_config = rpi_read_address_settings_plain_file();
    gchar* port_config = rpi_read_port_settings_plain_file();
    gchar* exit_config = rpi_read_exit_settings_plain_file();
    gboolean nok_settings = (!prompt_config || !address_config || !port_config || !exit_config);

    if (nok_settings)
    {
        g_critical(FAILED_READ_SETTINGS_CONFIG);

        if (prompt_config)
        {
            g_free(prompt_config);
            prompt_config = NULL;
        }

        if (address_config)
        {
            g_free(address_config);
            address_config = NULL;
        }

        if (port_config)
        {
            g_free(port_config);
            port_config = NULL;
        }

        if (exit_config)
        {
            g_free(exit_config);
            exit_config = NULL;
        }

        return NULL;
    }

    instance->no_prompt = g_strdup(prompt_config);
    instance->ip_address = g_strdup(address_config);
    instance->port_number = g_strdup(port_config);
    instance->no_exit = g_strdup(exit_config);

    if (prompt_config)
    {
        g_free(prompt_config);
        prompt_config = NULL;
    }

    if (address_config)
    {
        g_free(address_config);
        address_config = NULL;
    }

    if (port_config)
    {
        g_free(port_config);
        port_config = NULL;
    }

    if (exit_config)
    {
        g_free(exit_config);
        exit_config = NULL;
    }
#endif

#if (RPI_USE_SETTINGS_PLAIN_CONFIG == 0) && (RPI_USE_SETTINGS_SQLITE3 == 1)
    gchar* prompt_config = rpi_read_no_prompt_settings_sqlite();
    gchar* address_config = rpi_read_ip_address_settings_sqlite();
    gchar* port_config = rpi_read_port_number_settings_sqlite();
    gchar* exit_config = rpi_read_no_exit_settings_sqlite();
    gboolean nok_settings = (!prompt_config || !address_config || !port_config || !exit_config);

    if (nok_settings)
    {
        g_critical(FAILED_READ_SETTINGS_CONFIG);

        if (prompt_config)
        {
            g_free(prompt_config);
            prompt_config = NULL;
        }

        if (address_config)
        {
            g_free(address_config);
            address_config = NULL;
        }

        if (port_config)
        {
            g_free(port_config);
            port_config = NULL;
        }

        if (exit_config)
        {
            g_free(exit_config);
            exit_config = NULL;
        }

        return NULL;
    }

    instance->no_prompt = g_strdup(prompt_config);
    instance->ip_address = g_strdup(address_config);
    instance->port_number = g_strdup(port_config);
    instance->no_exit = g_strdup(exit_config);

    if (prompt_config)
    {
        g_free(prompt_config);
        prompt_config = NULL;
    }

    if (address_config)
    {
        g_free(address_config);
        address_config = NULL;
    }

    if (port_config)
    {
        g_free(port_config);
        port_config = NULL;
    }

    if (exit_config)
    {
        g_free(exit_config);
        exit_config = NULL;
    }
#endif

#if RPI_VERBOSE == 1
    g_debug(READ_SUCCESS_SETTINGS_CONFIG);
#endif

    return instance;
}

guint settings_write(const SettingsConfig* instance)
{
    if (!instance)
    {
        g_critical(MISSING_PARAMETER_SETTINGS_CONFIG);
        return FAILED_IO_SETTINGS_CONFIGURATION;
    }

#if (RPI_USE_SETTINGS_PLAIN_CONFIG == 1) && (RPI_USE_SETTINGS_SQLITE3 == 0)
    guint prompt_status = rpi_write_prompt_settings_plain_file(instance->no_prompt);
    guint address_status = rpi_write_address_settings_plain_file(instance->ip_address);
    guint port_status = rpi_write_port_settings_plain_file(instance->port_number);
    guint exit_status = rpi_write_exit_settings_plain_file(instance->no_exit);
    gboolean nok_write_status = (
        prompt_status == FAILED_SETTINGS_PLAIN ||
        address_status == FAILED_SETTINGS_PLAIN ||
        port_status == FAILED_SETTINGS_PLAIN ||
        exit_status == FAILED_SETTINGS_PLAIN
    );

    if (nok_write_status)
    {
        g_critical(FAILED_WRITE_SETTINGS_CONFIG);
        return FAILED_IO_SETTINGS_CONFIGURATION;
    }
#endif

#if (RPI_USE_SETTINGS_PLAIN_CONFIG == 0) && (RPI_USE_SETTINGS_SQLITE3 == 1)
    guint prompt_status = rpi_write_no_prompt_settings_sqlite(instance->no_prompt);
    guint address_status = rpi_write_ip_address_settings_sqlite(instance->ip_address);
    guint port_status = rpi_write_port_number_settings_sqlite(instance->port_number);
    guint exit_status = rpi_write_no_exit_settings_sqlite(instance->no_exit);
    gboolean nok_write_status = (
        prompt_status == FAILED_SETTINGS_SQLITE ||
        address_status == FAILED_SETTINGS_SQLITE ||
        port_status == FAILED_SETTINGS_SQLITE ||
        exit_status == FAILED_SETTINGS_SQLITE
    );

    if (nok_write_status)
    {
        g_critical(FAILED_WRITE_SETTINGS_CONFIG);
        return FAILED_IO_SETTINGS_CONFIGURATION;
    }
#endif

#if RPI_VERBOSE == 1
    g_debug(WRITE_SUCCESS_SETTINGS_CONFIG);
#endif

    return SUCCESS_IO_SETTINGS_CONFIGURATION;
}

gboolean is_prompt_enabled_settings(const SettingsConfig* instance)
{
    return instance && (g_strstr_len(instance->no_prompt, -1, TRUE_SETTINGS_CONFIG) != NULL) ? TRUE : FALSE;
}

void set_prompt_enabled_settings(SettingsConfig* instance, const gboolean no_prompt_state)
{
    if (instance)
    {
        if (no_prompt_state)
        {
            g_strlcpy(instance->no_prompt, TRUE_SETTINGS_CONFIG, g_utf8_strlen(TRUE_SETTINGS_CONFIG, -1) + 1);
        }
        else
        {
            g_strlcpy(instance->no_prompt, FALSE_SETTINGS_CONFIG, g_utf8_strlen(FALSE_SETTINGS_CONFIG, -1) + 1);
        }
    }
    else
    {
        g_critical(MISSING_PARAMETER_SETTINGS_CONFIG);
    }
}

gchar* get_server_ip_address_from_settings(const SettingsConfig* instance)
{
    return instance ? g_strdup(instance->ip_address) : NULL;
}

void set_server_ip_address_settings(SettingsConfig* instance, const gchar* ip_address)
{
    if (instance)
    {
        if (ip_address)
        {
            g_strlcpy(instance->ip_address, ip_address, g_utf8_strlen(ip_address, -1) + 1);
        }
        else
        {
            g_critical(MISSING_IP_ADDRESS_PARAMETER_SETTINGS_CONFIG);
        }
    }
    else
    {
        g_critical(MISSING_PARAMETER_SETTINGS_CONFIG);
    }
}

gchar* get_server_port_number_from_settings(const SettingsConfig* instance)
{
    return instance ? g_strdup(instance->port_number) : NULL;
}

void set_server_port_number_settings(SettingsConfig* instance, const gchar* port_number)
{
    if (instance)
    {
        if (port_number)
        {
            g_strlcpy(instance->port_number, port_number, g_utf8_strlen(port_number, -1) + 1);
        }
        else
        {
            g_critical(MISSING_PORT_NUMBER_PARAMETER_SETTINGS_CONFIG);
        }   
    }
    else
    {
        g_critical(MISSING_PARAMETER_SETTINGS_CONFIG);
    }
}

gboolean is_exit_enabled_settings(const SettingsConfig* instance)
{
    return instance && (g_strstr_len(instance->no_exit, -1, TRUE_SETTINGS_CONFIG) != NULL) ? TRUE : FALSE;
}

void set_exit_enabled_settings(SettingsConfig* instance, const gboolean no_exit_state)
{
    if (instance)
    {
        if (no_exit_state)
        {
            g_strlcpy(instance->no_exit, TRUE_SETTINGS_CONFIG, g_utf8_strlen(TRUE_SETTINGS_CONFIG, -1) + 1);
        }
        else
        {
            g_strlcpy(instance->no_exit, FALSE_SETTINGS_CONFIG, g_utf8_strlen(FALSE_SETTINGS_CONFIG, -1) + 1);
        }
    }
    else
    {
        g_critical(MISSING_PARAMETER_SETTINGS_CONFIG);
    }
}

void settings_free(SettingsConfig *instance)
{
    if (instance)
    {
        if (instance->no_prompt)
        {
            g_free(instance->no_prompt);
            instance->no_prompt = NULL;
        }

        if (instance->ip_address)
        {
            g_free(instance->ip_address);
            instance->ip_address = NULL;
        }

        if (instance->port_number)
        {
            g_free(instance->port_number);
            instance->port_number = NULL;
        }

        if (instance->no_exit)
        {
            g_free(instance->no_exit);
            instance->no_exit = NULL;
        }

        g_free(instance);
    }
}
