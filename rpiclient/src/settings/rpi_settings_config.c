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
#if defined(USE_SETTINGS_PLAIN_CONFIG) && defined(USE_SETTINGS_SQLITE3)
#error "You cannot use both USE_SETTINGS_PLAIN_CONFIG and USE_SETTINGS_SQLITE3 at the same time!"
#endif

#if defined(USE_SETTINGS_PLAIN_CONFIG) && ! defined(USE_SETTINGS_SQLITE3)
#include "rpi_settings_plain.h"
#endif

#if ! defined(USE_SETTINGS_PLAIN_CONFIG) && defined(USE_SETTINGS_SQLITE3)
#include "rpi_settings_sqlite.h"
#endif

#include "../resource/rpi_resource.h"
#include "rpi_settings_config.h"

static const gchar* SET_NOPROMPT = "no-prompt:disable";
static const gchar* SET_PROMPT = "no-prompt:enable";

#if defined(USE_SETTINGS_PLAIN_CONFIG) || defined(USE_SETTINGS_SQLITE3)
static const gchar* WARNING_LOG_FAILED_READ_SETTINGS_CONFIG = "Failed to read settings configuration.\n";
static const gchar* WARNING_LOG_FAILED_WRITE_SETTINGS_CONFIG = "Failed to write settings configuration.\n";
#endif

static const gchar* WARNING_LOG_FAILED_MALLOC_READ_SETTINGS_CONFIG = "Failed to allocate memory for read settings configuration.\n";
static const gchar* WARNING_LOG_FAILED_MISSING_PARAMETER_SETTINGS_CONFIG = "Missing settings parameter for write settings configuration.\n";

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings configuration structure
///   no_prompt - Configuration point for prompt
///   ip_address - Configuration point for server ip address
///   port_number - Configuration point for server port number
struct _SettingsConfig
{
    gchar *no_prompt;
    gchar *ip_address;
    gchar *port_number;
};

SettingsConfig* settings_read(void)
{
    SettingsConfig* instance = g_malloc(sizeof(SettingsConfig));

    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_READ_SETTINGS_CONFIG);
        return NULL;
    }

#if defined(USE_SETTINGS_PLAIN_CONFIG) && ! defined(USE_SETTINGS_SQLITE3)
    gchar* prompt_config = rpi_read_prompt_settings_plain_file();
    gchar* address_config = rpi_read_address_settings_plain_file();
    gchar* port_config = rpi_read_port_settings_plain_file();
    gboolean nok_settings = (!prompt_config || !address_config || !port_config);

    if (nok_settings)
    {
        g_warning("%s", WARNING_LOG_FAILED_READ_SETTINGS_CONFIG);
        g_free((gpointer)prompt_config);
        g_free((gpointer)address_config);
        g_free((gpointer)port_config);
        return NULL;
    }

    instance->no_prompt = g_strdup(prompt_config);
    instance->ip_address = g_strdup(address_config);
    instance->port_number = g_strdup(port_config);
    g_free((gpointer)prompt_config);
    g_free((gpointer)address_config);
    g_free((gpointer)port_config);
#endif

#if ! defined(USE_SETTINGS_PLAIN_CONFIG) && defined(USE_SETTINGS_SQLITE3)
    gchar* prompt_config = rpi_read_no_prompt_settings_sqlite();
    gchar* address_config = rpi_read_ip_address_settings_sqlite();
    gchar* port_config = rpi_read_port_number_settings_sqlite();
    gboolean nok_settings = (!prompt_config || !address_config || !port_config);

    if (nok_settings)
    {
        g_warning("%s", WARNING_LOG_FAILED_READ_SETTINGS_CONFIG);
        g_free((gpointer)prompt_config);
        g_free((gpointer)address_config);
        g_free((gpointer)port_config);
        return NULL;
    }

    instance->no_prompt = g_strdup(prompt_config);
    instance->ip_address = g_strdup(address_config);
    instance->port_number = g_strdup(port_config);
    g_free((pointer)prompt_config);
    g_free((pointer)address_config);
    g_free((pointer)port_config);
#endif

    return instance;
}

guint settings_write(const SettingsConfig* instance)
{
    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MISSING_PARAMETER_SETTINGS_CONFIG);
        return FAILED_IO_SETTINGS_CONFIGURATION;
    }

#if defined(USE_SETTINGS_PLAIN_CONFIG) && ! defined(USE_SETTINGS_SQLITE3)
    guint prompt_status = rpi_write_prompt_settings_plain_file(instance->no_prompt);
    guint address_status = rpi_write_address_settings_plain_file(instance->ip_address);
    guint port_status = rpi_write_port_settings_plain_file(instance->port_number);
    gboolean nok_write_status = (
        prompt_status == FAILED_SETTINGS_PLAIN ||
        address_status == FAILED_SETTINGS_PLAIN ||
        port_status == FAILED_SETTINGS_PLAIN
    );

    if (nok_write_status)
    {
        g_warning("%s", WARNING_LOG_FAILED_WRITE_SETTINGS_CONFIG);
        return FAILED_IO_SETTINGS_CONFIGURATION;
    }
#endif

#if ! defined(USE_SETTINGS_PLAIN_CONFIG) && defined(USE_SETTINGS_SQLITE3)
    guint prompt_status = rpi_write_no_prompt_settings_sqlite(instance->no_prompt);
    guint address_status = rpi_write_ip_address_settings_sqlite(instance->ip_address);
    guint port_status = rpi_write_port_number_settings_sqlite(instance->port_number);
    gboolean nok_write_status = (
        prompt_status == FAILED_SETTINGS_SQLITE ||
        address_status == FAILED_SETTINGS_SQLITE ||
        port_status == FAILED_SETTINGS_SQLITE
    );

    if (nok_write_status)
    {
        g_warning("%s", WARNING_LOG_FAILED_WRITE_SETTINGS_CONFIG);
        return FAILED_IO_SETTINGS_CONFIGURATION;
    }
#endif

    return SUCCESS_IO_SETTINGS_CONFIGURATION;
}


void settings_free(SettingsConfig *instance)
{
    if (instance)
    {
        if (instance->no_prompt)
        {
            g_free((gpointer)instance->no_prompt);
            instance->no_prompt = NULL;
        }

        if (instance->ip_address)
        {
            g_free((gpointer)instance->ip_address);
            instance->ip_address = NULL;
        }

        if (instance->port_number)
        {
            g_free((gpointer)instance->port_number);
            instance->port_number = NULL;
        }

        g_free((gpointer)instance);
    }
}
