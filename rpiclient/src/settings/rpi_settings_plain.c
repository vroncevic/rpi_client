/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_plain.c
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
#include "rpi_settings_plain.h"

static const gchar* PROMPT_FILE_SETTINGS_PLAIN = "/home/%s/.rpiclient/config/prompt.config";
static const gchar* SERVER_ADDRESS_FILE_SETTINGS_PLAIN = "/home/%s/.rpiclient/config/server_address.config";
static const gchar* SERVER_PORT_FILE_SETTINGS_PLAIN = "/home/%s/.rpiclient/config/server_port.config";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_PLAIN = "Failed to get prompt config file path\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_PLAIN = "Failed to get server address config file pat\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_PLAIN = "Failed to get server port config file path\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_PLAIN = "Failed to open prompt config file\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_READ_SETTINGS_PLAIN = "Failed to read prompt config file\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_PLAIN = "Failed to open server address config file\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_READ_SETTINGS_PLAIN = "Failed to read server address config file\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_PLAIN = "Failed to open server port config file\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_READ_SETTINGS_PLAIN = "Failed to read server port config file\n";

FILE* rpi_get_prompt_settings_plain_file(const gchar* mode)
{
    gchar *prompt_config = rpi_get_config_file(PROMPT_FILE_SETTINGS_PLAIN);

    if (!prompt_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_PLAIN);
        return NULL;
    }

    FILE *file_prompt_config = fopen(prompt_config, mode);

    if (!file_prompt_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_PLAIN);
        g_free((gpointer)prompt_config);
        return NULL;
    }

    g_free((gpointer)prompt_config);
    return file_prompt_config;
}

gchar* rpi_read_prompt_settings_plain_file(FILE* prompt_config_file)
{
    gchar* prompt_config = g_malloc(17 * sizeof(gchar));

    if (fscanf(prompt_config_file, "%16s", prompt_config) != 1)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_READ_SETTINGS_PLAIN);
        g_free((gpointer)prompt_config);
        return NULL;
    }

    return prompt_config;
}

guint rpi_write_prompt_settings_plain_file(FILE* prompt_config_file, const gchar* prompt_config)
{
    if (!prompt_config_file || !prompt_config)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(prompt_config, prompt_config_file);
    gint status_flash = fflush(prompt_config_file);

    if (status_put < 0 || status_flash < 0)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    return SUCCESS_SETTINGS_PLAIN;
}

void rpi_close_prompt_settings_plain_file(FILE* file_prompt_config)
{
    if (file_prompt_config)
    {
        fclose(file_prompt_config);
    }
}

FILE* rpi_get_address_settings_plain_file(const gchar* mode)
{
    gchar *server_address_config = rpi_get_config_file(SERVER_ADDRESS_FILE_SETTINGS_PLAIN);

    if (!server_address_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_PLAIN);
        return NULL;
    }

    FILE *file_server_address_config = fopen(server_address_config, mode);

    if (!file_server_address_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_PLAIN);
        g_free((gpointer)server_address_config);
        return NULL;
    }

    g_free((gpointer)server_address_config);
    return file_server_address_config;
}

gchar* rpi_read_address_settings_plain_file(FILE* file_server_address_config)
{
    gchar* address_config = g_malloc(17 * sizeof(gchar));

    if (fscanf(file_server_address_config, "%16s", address_config) != 1)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_READ_SETTINGS_PLAIN);
        g_free((gpointer)address_config);
        return NULL;
    }

    return address_config;
}

guint rpi_write_address_settings_plain_file(FILE* file_server_address_config, const gchar* address_config)
{
    if (!file_server_address_config || !address_config)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(address_config, file_server_address_config);
    gint status_flash = fflush(file_server_address_config);

    if (status_put < 0 || status_flash < 0)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    return SUCCESS_SETTINGS_PLAIN;
}

void rpi_close_address_settings_plain_file(FILE* file_server_address_config)
{
    if (file_server_address_config)
    {
        fclose(file_server_address_config);
    }
}

FILE* rpi_get_port_settings_plain_file(const gchar* mode)
{
    gchar *server_port_config = rpi_get_config_file(SERVER_PORT_FILE_SETTINGS_PLAIN);

    if (!server_port_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_PLAIN);
        return NULL;
    }

    FILE *file_server_port_config = fopen(server_port_config, mode);

    if (!file_server_port_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_PLAIN);
        g_free((gpointer)server_port_config);
        return NULL;
    }

    g_free((gpointer)server_port_config);
    return file_server_port_config;
}

gchar* rpi_read_port_settings_plain_file(FILE* file_server_port_config)
{
    gchar* port_config = g_malloc(17 * sizeof(gchar));

    if (fscanf(file_server_port_config, "%16s", port_config) != 1)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_READ_SETTINGS_PLAIN);
        g_free((gpointer)port_config);
        return NULL;
    }

    return port_config;
}

guint rpi_write_port_settings_plain_file(FILE* file_server_port_config, const gchar* port_config)
{
    if (!file_server_port_config || !port_config)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(port_config, file_server_port_config);
    gint status_flash = fflush(file_server_port_config);

    if (status_put < 0 || status_flash < 0)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    return SUCCESS_SETTINGS_PLAIN;
}

void rpi_close_port_settings_plain_file(FILE* file_server_port_config)
{
    if (file_server_port_config)
    {
        fclose(file_server_port_config);
    }
}
