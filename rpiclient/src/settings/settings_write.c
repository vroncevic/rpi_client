/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_write.c
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

static const gchar* SET_NOPROMPT = "no-prompt:disable";
static const gchar* SET_PROMPT = "no-prompt:enable";
static const gchar* WARNING_LOG_FAILED_MISSING_SETTINGS_WRITE = "Missing setting parameter for write\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_WRITE = "Failed to get prompt config file path for write\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_WRITE = "Failed to get server address config file path for write\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_WRITE = "Failed to get server port config file path for write\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_WRITE = "Failed to open prompt config file for write\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_WRITE = "Failed to open server address config file for write\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_WRITE = "Failed to open server port config file for write\n";
static const gint SUCCESS_SETTINGS_CONFIGURATION = 0;
static const gint FAILED_SETTINGS_CONFIGURATION = 1;

gint settings_write(SettingsConfig* instance)
{
    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MISSING_SETTINGS_WRITE);
        return FAILED_SETTINGS_CONFIGURATION;
    }

    gchar *prompt_config = get_config_file(CONFIGURATION_FILE_PROMPT);

    if (!prompt_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_WRITE);
        return FAILED_SETTINGS_CONFIGURATION;
    }

    gchar *server_address_config = get_config_file(CONFIGURATION_FILE_SERVER_ADDRESS);

    if (!server_address_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_WRITE);
        g_free((gpointer)prompt_config);
        return FAILED_SETTINGS_CONFIGURATION;
    }

    gchar *server_port_config = get_config_file(CONFIGURATION_FILE_SERVER_PORT);

    if (!server_port_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_WRITE);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        return FAILED_SETTINGS_CONFIGURATION;
    }

    FILE *file_prompt_config = fopen(prompt_config, "wb");

    if (!file_prompt_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_WRITE);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        return FAILED_SETTINGS_CONFIGURATION;
    }

    FILE *file_server_address_config = fopen(server_address_config, "wb");

    if (!file_server_address_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_WRITE);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        return FAILED_SETTINGS_CONFIGURATION;
    }

    FILE *file_server_port_config = fopen(server_port_config, "wb");

    if (!file_server_port_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_WRITE);
        g_free((gpointer)prompt_config);
        g_free((gpointer)server_address_config);
        g_free((gpointer)server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        return FAILED_SETTINGS_CONFIGURATION;
    }

    fputs(instance->no_prompt, file_prompt_config);
    fflush(file_prompt_config);
    fputs(instance->ip_address, file_server_address_config);
    fflush(file_server_address_config);
    fputs(instance->port_number, file_server_port_config);
    fflush(file_server_port_config);
    fclose(file_prompt_config);
    fclose(file_server_address_config);
    fclose(file_server_port_config);

    return SUCCESS_SETTINGS_CONFIGURATION;
}
