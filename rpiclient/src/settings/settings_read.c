/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_read.c
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
#include "settings_config.h"

static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_READ = "Failed to get prompt config file path for read\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_READ = "Failed to get server address config file path for read\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_READ = "Failed to get server port config file path for read\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_READ = "Failed to open prompt config file for read\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_READ = "Failed to open server address config file for read\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_READ = "Failed to open server port config file for read\n";
static const gchar* WARNING_LOG_FAILED_MALLOC_SETTINGS_READ = "Failed to allocate memory for settings configuration for read\n";

SettingsConfig* settings_read(void)
{
    gchar *prompt_config = get_config_file(CONFIGURATION_FILE_PROMPT);

    if (!prompt_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_READ);
        return NULL;
    }

    gchar *server_address_config = get_config_file(CONFIGURATION_FILE_SERVER_ADDRESS);

    if (!server_address_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        return NULL;
    }

    gchar *server_port_config = get_config_file(CONFIGURATION_FILE_SERVER_PORT);

    if (!server_port_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        return NULL;
    }

    FILE *file_prompt_config = fopen(prompt_config, "rb");

    if (!file_prompt_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        return NULL;
    }

    FILE *file_server_address_config = fopen(server_address_config, "rb");

    if (!file_server_address_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        return NULL;
    }

    FILE *file_server_port_config = fopen(server_port_config, "rb");

    if (!file_server_port_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        return NULL;
    }

    SettingsConfig* instance = g_malloc(sizeof(SettingsConfig));

    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        fclose(file_server_port_config);
        return NULL;
    }

    gchar tmp[17];

    if (fscanf(file_prompt_config, "%16s", tmp) == EOF)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        fclose(file_server_port_config);
        return NULL;
    }

    instance->no_prompt = g_strdup(tmp);

    if (fscanf(file_server_address_config, "%16s", tmp) == EOF)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        fclose(file_server_port_config);
        return NULL;
    }

    instance->ip_address = g_strdup(tmp);

    if (fscanf(file_server_port_config, "%16s", tmp) == EOF)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_SETTINGS_READ);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        fclose(file_server_port_config);
        return NULL;
    }

    instance->port_number = g_strdup(tmp);

    g_free((gpointer)prompt_config);
    g_free((gpointer)server_address_config);
    g_free((gpointer)server_port_config);
    fclose(file_prompt_config);
    fclose(file_server_address_config);
    fclose(file_server_port_config);

    return instance;
}
