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

SettingsConfig* settings_read(void)
{
    gchar *prompt_config = get_config_file(CONFIGURATION_FILE_PROMPT);

    if (!prompt_config)
    {
        g_warning(WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_READ);
        return NULL;
    }

    gchar *server_address_config = get_config_file(CONFIGURATION_FILE_SERVER_ADDRESS);

    if (!server_address_config)
    {
        g_warning(WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_READ);
        g_free(prompt_config);
        return NULL;
    }

    gchar *server_port_config = get_config_file(CONFIGURATION_FILE_SERVER_PORT);

    if (!server_port_config)
    {
        g_warning(WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_READ);
        g_free(prompt_config);
        g_free(server_address_config);
        return NULL;
    }

    FILE *file_prompt_config = fopen(prompt_config, "rb");

    if (!file_prompt_config)
    {
        g_warning(WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_READ);
        g_free(prompt_config);
        g_free(server_address_config);
        g_free(server_port_config);
        return NULL;
    }

    FILE *file_server_address_config = fopen(server_address_config, "rb");

    if (!file_server_address_config)
    {
        g_warning(WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_READ);
        g_free(prompt_config);
        g_free(server_address_config);
        g_free(server_port_config);
        fclose(file_prompt_config);
        return NULL;
    }

    FILE *file_server_port_config = fopen(server_port_config, "rb");

    if (!file_server_port_config)
    {
        g_warning(WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_READ);
        g_free(prompt_config);
        g_free(server_address_config);
        g_free(server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        return NULL;
    }

    SettingsConfig* instance = g_malloc(sizeof(SettingsConfig));

    if (!instance)
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_SETTINGS_READ);
        g_free(prompt_config);
        g_free(server_address_config);
        g_free(server_port_config);
        fclose(file_prompt_config);
        fclose(file_server_address_config);
        fclose(file_server_port_config);
        return NULL;
    }

    gchar tmp[17];
    fscanf(file_prompt_config, "%16s", tmp);
    instance->no_prompt = g_strdup(tmp);
    fscanf(file_server_address_config, "%16s", tmp);
    instance->ip_address = g_strdup(tmp);
    fscanf(file_server_port_config, "%16s", tmp);
    instance->port_number = g_strdup(tmp);

    g_free(prompt_config);
    g_free(server_address_config);
    g_free(server_port_config);
    fclose(file_prompt_config);
    fclose(file_server_address_config);
    fclose(file_server_port_config);

    return instance;
}
