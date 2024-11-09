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
#include "rpi_settings_user.h"
#include "rpi_settings_plain.h"

#define PROMPT_FILE_SETTINGS_PLAIN "/home/%s/.rpiclient/config/prompt.config"
#define SERVER_ADDRESS_FILE_SETTINGS_PLAIN "/home/%s/.rpiclient/config/server_address.config"
#define SERVER_PORT_FILE_SETTINGS_PLAIN "/home/%s/.rpiclient/config/server_port.config"

static const gchar* READ_MODE_SETTINGS_PLAIN = "rb";
static const gchar* WRITE_MODE_SETTINGS_PLAIN = "wb";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_PLAIN = "Failed to get prompt config file path.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_PLAIN = "Failed to get server address config file pat.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_PLAIN = "Failed to get server port config file path.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_PLAIN = "Failed to open prompt config file.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_READ_SETTINGS_PLAIN = "Failed to read prompt config file.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_PLAIN = "Failed to open server address config file.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_READ_SETTINGS_PLAIN = "Failed to read server address config file.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_PLAIN = "Failed to open server port config file.\n";
static const gchar* WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_READ_SETTINGS_PLAIN = "Failed to read server port config file.\n";

static FILE* rpi_open_prompt_settings_plain_file(const gchar* mode);
static void rpi_close_prompt_settings_plain_file(FILE* prompt_config_file);
static FILE* rpi_open_address_settings_plain_file(const gchar* mode);
static void rpi_close_address_settings_plain_file(FILE* file_server_address_config);
static FILE* rpi_open_port_settings_plain_file(const gchar* mode);
static void rpi_close_port_settings_plain_file(FILE* file_server_port_config);

static FILE* rpi_open_prompt_settings_plain_file(const gchar* mode)
{
    gchar* username = rpi_get_username_settings_user();

    if (!username)
    {
        return NULL;        
    }

    gchar *prompt_config_file_path = g_strdup_printf(PROMPT_FILE_SETTINGS_PLAIN, username);

    if (!prompt_config_file_path)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_SETTINGS_PLAIN);
        g_free((gpointer)username);
        return NULL;
    }

    g_free((gpointer)username);
    FILE *file_prompt_config = fopen(prompt_config_file_path, mode);

    if (!file_prompt_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_OPEN_SETTINGS_PLAIN);
        g_free((gpointer)prompt_config_file_path);
        return NULL;
    }

    g_free((gpointer)prompt_config_file_path);
    return file_prompt_config;
}

gchar* rpi_read_prompt_settings_plain_file(void)
{
    gchar* prompt_config = NULL;
    FILE* prompt_config_file = rpi_open_prompt_settings_plain_file(READ_MODE_SETTINGS_PLAIN);

    if (prompt_config_file)
    {
        prompt_config = g_malloc(17 * sizeof(gchar));

        if (fscanf(prompt_config_file, "%16s", prompt_config) != 1)
        {
            g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PROMPT_READ_SETTINGS_PLAIN);
            g_free((gpointer)prompt_config);
            return NULL;
        }

        rpi_close_prompt_settings_plain_file(prompt_config_file);
    }

    return prompt_config;
}

guint rpi_write_prompt_settings_plain_file(const gchar* prompt_config)
{
    FILE* prompt_config_file = rpi_open_prompt_settings_plain_file(WRITE_MODE_SETTINGS_PLAIN);

    if (!prompt_config_file || !prompt_config)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(prompt_config, prompt_config_file);
    gint status_flash = fflush(prompt_config_file);

    if (status_put < 0 || status_flash < 0)
    {
        rpi_close_prompt_settings_plain_file(prompt_config_file);
        return FAILED_SETTINGS_PLAIN;
    }

    rpi_close_prompt_settings_plain_file(prompt_config_file);
    return SUCCESS_SETTINGS_PLAIN;
}

static void rpi_close_prompt_settings_plain_file(FILE* file_prompt_config)
{
    if (file_prompt_config)
    {
        fclose(file_prompt_config);
    }
}

static FILE* rpi_open_address_settings_plain_file(const gchar* mode)
{
    gchar* username = rpi_get_username_settings_user();

    if (!username)
    {
        return NULL;        
    }

    gchar *server_address_config_file_path = g_strdup_printf(SERVER_ADDRESS_FILE_SETTINGS_PLAIN, username);

    if (!server_address_config_file_path)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_SETTINGS_PLAIN);
        g_free((gpointer)username);
        return NULL;
    }

    g_free((gpointer)username);
    FILE *file_server_address_config = fopen(server_address_config_file_path, mode);

    if (!file_server_address_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_OPEN_SETTINGS_PLAIN);
        g_free((gpointer)server_address_config_file_path);
        return NULL;
    }

    g_free((gpointer)server_address_config_file_path);
    return file_server_address_config;
}

gchar* rpi_read_address_settings_plain_file(void)
{
    FILE* file_server_address_config = rpi_open_address_settings_plain_file(READ_MODE_SETTINGS_PLAIN);

    gchar* address_config = g_malloc(17 * sizeof(gchar));

    if (fscanf(file_server_address_config, "%16s", address_config) != 1)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_ADDRESS_READ_SETTINGS_PLAIN);
        g_free((gpointer)address_config);
        return NULL;
    }

    rpi_close_address_settings_plain_file(file_server_address_config);

    return address_config;
}

guint rpi_write_address_settings_plain_file(const gchar* address_config)
{
    FILE* file_server_address_config = rpi_open_address_settings_plain_file(WRITE_MODE_SETTINGS_PLAIN);

    if (!file_server_address_config || !address_config)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(address_config, file_server_address_config);
    gint status_flash = fflush(file_server_address_config);

    if (status_put < 0 || status_flash < 0)
    {
        rpi_close_address_settings_plain_file(file_server_address_config);
        return FAILED_SETTINGS_PLAIN;
    }

    rpi_close_address_settings_plain_file(file_server_address_config);
    return SUCCESS_SETTINGS_PLAIN;
}

static void rpi_close_address_settings_plain_file(FILE* file_server_address_config)
{
    if (file_server_address_config)
    {
        fclose(file_server_address_config);
    }
}

static FILE* rpi_open_port_settings_plain_file(const gchar* mode)
{
    gchar* username = rpi_get_username_settings_user();

    if (!username)
    {
        return NULL;        
    }

    gchar *server_port_config_file_path = g_strdup_printf(SERVER_PORT_FILE_SETTINGS_PLAIN, username);

    if (!server_port_config_file_path)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_SETTINGS_PLAIN);
        g_free((gpointer)username);
        return NULL;
    }

    g_free((gpointer)username);
    FILE *file_server_port_config = fopen(server_port_config_file_path, mode);

    if (!file_server_port_config)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_OPEN_SETTINGS_PLAIN);
        g_free((gpointer)server_port_config_file_path);
        return NULL;
    }

    g_free((gpointer)server_port_config_file_path);
    return file_server_port_config;
}

gchar* rpi_read_port_settings_plain_file(void)
{
    FILE* file_server_port_config = rpi_open_port_settings_plain_file(READ_MODE_SETTINGS_PLAIN);

    gchar* port_config = g_malloc(17 * sizeof(gchar));

    if (fscanf(file_server_port_config, "%16s", port_config) != 1)
    {
        g_warning("%s", WARNING_LOG_FAILED_CONFIGURATION_FILE_PORT_READ_SETTINGS_PLAIN);
        g_free((gpointer)port_config);
        return NULL;
    }

    rpi_close_port_settings_plain_file(file_server_port_config);

    return port_config;
}

guint rpi_write_port_settings_plain_file(const gchar* port_config)
{
    FILE* file_server_port_config = rpi_open_port_settings_plain_file(WRITE_MODE_SETTINGS_PLAIN);

    if (!file_server_port_config || !port_config)
    {
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(port_config, file_server_port_config);
    gint status_flash = fflush(file_server_port_config);

    if (status_put < 0 || status_flash < 0)
    {
        rpi_close_port_settings_plain_file(file_server_port_config);
        return FAILED_SETTINGS_PLAIN;
    }

    rpi_close_port_settings_plain_file(file_server_port_config);
    return SUCCESS_SETTINGS_PLAIN;
}

static void rpi_close_port_settings_plain_file(FILE* file_server_port_config)
{
    if (file_server_port_config)
    {
        fclose(file_server_port_config);
    }
}
