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
#include <stdio.h>
#include "rpi_client_config.h"
#include "../resource/rpi_resource.h"
#include "rpi_settings_user.h"
#include "rpi_settings_plain.h"

#if RPI_VERBOSE == 1
#define DIR_SETTINGS_PLAIN "Used configuration directory path: %s.\n"
#define OPEN_FILE_SETTINGS_PLAIN "Successfully opened configuration file: %s with mode: %s.\n"
#define READ_FILE_PARAMETER_SETTINGS_PLAIN "Read from file: %s parameter: %s.\n"
#define WRITE_FILE_PARAMETER_SETTINGS_PLAIN "Write to file: %s parameter: %s.\n"
#define CLOSE_FILE_SETTINGS_PLAIN "Successfully closed file: %s.\n"
#endif

#define MISSING_FILE_PARAMETERS_SETTINGS_PLAIN "Missing parameters for opening file.\n"
#define MISSING_FILE_NAME_SETTINGS_PLAIN "Missing name for opening file.\n"
#define MISSING_FILE_MODE_SETTINGS_PLAIN "Missing mode for opening file.\n"
#define MISSING_FILE_CONTENT_SETTINGS_PLAIN "Missing default configuration content in case of missing file.\n"
#define MISSING_PARAMETER_SETTINGS_PLAIN "Missing configuration parameter for write operation to file.\n"

#define FAILED_GET_CONFIGURATION_DIR_SETTINGS_PLAIN "Failed to get configuration directory path.\n"
#define FAILED_FILE_PATH_SETTINGS_PLAIN "Failed to get path for file.\n"
#define FAILED_FILE_OPEN_SETTINGS_PLAIN "Failed to open file.\n"
#define FAILED_FILE_READ_SETTINGS_PLAIN "Failed to read file.\n"
#define FAILED_FILE_WRITE_SETTINGS_PLAIN "Failed to write to file.\n"
#define FAILED_FILE_CLOSE_SETTINGS_PLAIN "Failed to close file.\n"

static const gchar* PROMPT_FILE_NAME_SETTINGS_PLAIN = "prompt.config";
static const gchar* SERVER_ADDRESS_FILE_NAME_SETTINGS_PLAIN = "server_address.config";
static const gchar* SERVER_PORT_FILE_NAME_SETTINGS_PLAIN = "server_port.config";
static const gchar* EXIT_FILE_NAME_SETTINGS_PLAIN = "exit.config";
static const gchar* DEFAULT_PROMPT_PARAMETER_SETTINGS_PLAIN = "false";
static const gchar* DEFAULT_SERVER_ADDRESS_PARAMETER_SETTINGS_PLAIN = "192.168.1.100";
static const gchar* DEFAULT_SERVER_PORT_PARAMETER_SETTINGS_PLAIN = "8888";
static const gchar* DEFAULT_EXIT_PARAMETER_SETTINGS_PLAIN = "true";
static const gchar* READ_MODE_SETTINGS_PLAIN = "rb";
static const gchar* WRITE_MODE_SETTINGS_PLAIN = "wb";

//////////////////////////////////////////////////////////////////////////////
/// @brief Configuration file complex structure
///   name - File name (*.config file name)
///   mode - File mode (rb | wb mode)
///   content - Default content for file
typedef struct
{
    gchar* name;
    gchar* mode;
    gchar* content;
} ConfigFile;

static FILE* rpi_open_settings_plain_file(const ConfigFile* config);
static void rpi_close_settings_plain_file(const ConfigFile* config, FILE* config_file);
static void rpi_free_settings_plain_file(ConfigFile* config);

gchar* rpi_read_prompt_settings_plain_file(void)
{
    ConfigFile prompt_setup =
    {
        .name = g_strdup(PROMPT_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(READ_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_PROMPT_PARAMETER_SETTINGS_PLAIN)
    };

    gchar* prompt_config = NULL;
    FILE* config_file = rpi_open_settings_plain_file(&prompt_setup);

    if (config_file)
    {
        prompt_config = g_malloc(17 * sizeof(gchar));

        if (!prompt_config)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            rpi_close_settings_plain_file(&prompt_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&prompt_setup);
            return NULL;
        }

        if (fscanf(config_file, "%16s", prompt_config) != 1)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            g_free(prompt_config);
            prompt_config = NULL;
            rpi_close_settings_plain_file(&prompt_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&prompt_setup);
            return NULL;
        }

#if RPI_VERBOSE == 1
        g_debug(READ_FILE_PARAMETER_SETTINGS_PLAIN, PROMPT_FILE_NAME_SETTINGS_PLAIN, prompt_config);
#endif

        rpi_close_settings_plain_file(&prompt_setup, config_file);
        config_file = NULL;
    }

    rpi_free_settings_plain_file(&prompt_setup);
    return prompt_config;
}

guint rpi_write_prompt_settings_plain_file(const gchar* prompt_config)
{
    if (!prompt_config)
    {
        g_critical(MISSING_PARAMETER_SETTINGS_PLAIN);
        return FAILED_SETTINGS_PLAIN;
    }

    ConfigFile prompt_setup =
    {
        .name = g_strdup(PROMPT_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(WRITE_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_PROMPT_PARAMETER_SETTINGS_PLAIN)
    };
    FILE* config_file = rpi_open_settings_plain_file(&prompt_setup);

    if (!config_file)
    {
        rpi_free_settings_plain_file(&prompt_setup);
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(prompt_config, config_file);
    gint status_flash = fflush(config_file);

    if (status_put < 0 || status_flash < 0)
    {
        g_critical(FAILED_FILE_WRITE_SETTINGS_PLAIN);
        rpi_close_settings_plain_file(&prompt_setup, config_file);
        config_file = NULL;
        rpi_free_settings_plain_file(&prompt_setup);
        return FAILED_SETTINGS_PLAIN;
    }

#if RPI_VERBOSE == 1
    g_debug(WRITE_FILE_PARAMETER_SETTINGS_PLAIN, PROMPT_FILE_NAME_SETTINGS_PLAIN, prompt_config);
#endif

    rpi_close_settings_plain_file(&prompt_setup, config_file);
    config_file = NULL;
    rpi_free_settings_plain_file(&prompt_setup);
    return SUCCESS_SETTINGS_PLAIN;
}

gchar* rpi_read_address_settings_plain_file(void)
{
    gchar* address_config = NULL;
    ConfigFile address_setup =
    {
        .name = g_strdup(SERVER_ADDRESS_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(READ_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_SERVER_ADDRESS_PARAMETER_SETTINGS_PLAIN)
    };
    FILE* config_file = rpi_open_settings_plain_file(&address_setup);

    if (config_file)
    {
        address_config = g_malloc(17 * sizeof(gchar));

        if (!address_config)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            rpi_close_settings_plain_file(&address_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&address_setup);
            return NULL;
        }

        if (fscanf(config_file, "%16s", address_config) != 1)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            g_free(address_config);
            address_config = NULL;
            rpi_close_settings_plain_file(&address_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&address_setup);
            return NULL;
        }

#if RPI_VERBOSE == 1
        g_debug(READ_FILE_PARAMETER_SETTINGS_PLAIN, SERVER_ADDRESS_FILE_NAME_SETTINGS_PLAIN, address_config);
#endif

        rpi_close_settings_plain_file(&address_setup, config_file);
        config_file = NULL;
    }

    rpi_free_settings_plain_file(&address_setup);
    return address_config;
}

guint rpi_write_address_settings_plain_file(const gchar* address_config)
{
    if (!address_config)
    {
        g_critical(MISSING_PARAMETER_SETTINGS_PLAIN);
        return FAILED_SETTINGS_PLAIN;
    }

    ConfigFile address_setup =
    {
        .name = g_strdup(SERVER_ADDRESS_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(WRITE_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_SERVER_ADDRESS_PARAMETER_SETTINGS_PLAIN)
    };
    FILE* config_file = rpi_open_settings_plain_file(&address_setup);

    if (!config_file)
    {
        rpi_free_settings_plain_file(&address_setup);
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(address_config, config_file);
    gint status_flash = fflush(config_file);

    if (status_put < 0 || status_flash < 0)
    {
        g_critical(FAILED_FILE_WRITE_SETTINGS_PLAIN);
        rpi_close_settings_plain_file(&address_setup, config_file);
        config_file = NULL;
        rpi_free_settings_plain_file(&address_setup);
        return FAILED_SETTINGS_PLAIN;
    }

#if RPI_VERBOSE == 1
    g_debug(WRITE_FILE_PARAMETER_SETTINGS_PLAIN, SERVER_ADDRESS_FILE_NAME_SETTINGS_PLAIN, address_config);
#endif

    rpi_close_settings_plain_file(&address_setup, config_file);
    config_file = NULL;
    rpi_free_settings_plain_file(&address_setup);
    return SUCCESS_SETTINGS_PLAIN;
}

gchar* rpi_read_port_settings_plain_file(void)
{
    gchar* port_config = NULL;
    ConfigFile port_setup =
    {
        .name = g_strdup(SERVER_PORT_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(READ_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_SERVER_PORT_PARAMETER_SETTINGS_PLAIN)
    };
    FILE* config_file = rpi_open_settings_plain_file(&port_setup);

    if (config_file)
    {
        port_config = g_malloc(17 * sizeof(gchar));

        if (!port_config)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            rpi_close_settings_plain_file(&port_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&port_setup);
            return NULL;
        }

        if (fscanf(config_file, "%16s", port_config) != 1)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            g_free(port_config);
            port_config = NULL;
            rpi_close_settings_plain_file(&port_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&port_setup);
            return NULL;
        }

#if RPI_VERBOSE == 1
    g_debug(READ_FILE_PARAMETER_SETTINGS_PLAIN, SERVER_PORT_FILE_NAME_SETTINGS_PLAIN, port_config);
#endif

        rpi_close_settings_plain_file(&port_setup, config_file);
        config_file = NULL;
    }

    rpi_free_settings_plain_file(&port_setup);
    return port_config;
}

guint rpi_write_port_settings_plain_file(const gchar* port_config)
{
    if (!port_config)
    {
        g_critical(MISSING_PARAMETER_SETTINGS_PLAIN);
        return FAILED_SETTINGS_PLAIN;
    }

    ConfigFile port_setup =
    {
        .name = g_strdup(SERVER_PORT_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(WRITE_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_SERVER_PORT_PARAMETER_SETTINGS_PLAIN)
    };
    FILE* config_file = rpi_open_settings_plain_file(&port_setup);

    if (!config_file)
    {
        rpi_free_settings_plain_file(&port_setup);
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(port_config, config_file);
    gint status_flash = fflush(config_file);

    if (status_put < 0 || status_flash < 0)
    {
        g_critical(FAILED_FILE_WRITE_SETTINGS_PLAIN);
        rpi_close_settings_plain_file(&port_setup, config_file);
        config_file = NULL;
        rpi_free_settings_plain_file(&port_setup);
        return FAILED_SETTINGS_PLAIN;
    }

#if RPI_VERBOSE == 1
    g_debug(WRITE_FILE_PARAMETER_SETTINGS_PLAIN, SERVER_PORT_FILE_NAME_SETTINGS_PLAIN, port_config);
#endif

    rpi_close_settings_plain_file(&port_setup, config_file);
    config_file = NULL;
    rpi_free_settings_plain_file(&port_setup);
    return SUCCESS_SETTINGS_PLAIN;
}

gchar* rpi_read_exit_settings_plain_file(void)
{
    gchar* exit_config = NULL;
    ConfigFile exit_setup =
    {
        .name = g_strdup(EXIT_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(READ_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_EXIT_PARAMETER_SETTINGS_PLAIN)
    };
    FILE* config_file = rpi_open_settings_plain_file(&exit_setup);

    if (config_file)
    {
        exit_config = g_malloc(17 * sizeof(gchar));

        if (!exit_config)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            rpi_close_settings_plain_file(&exit_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&exit_setup);
            return NULL;
        }

        if (fscanf(config_file, "%16s", exit_config) != 1)
        {
            g_critical(FAILED_FILE_READ_SETTINGS_PLAIN);
            g_free(exit_config);
            exit_config = NULL;
            rpi_close_settings_plain_file(&exit_setup, config_file);
            config_file = NULL;
            rpi_free_settings_plain_file(&exit_setup);
            return NULL;
        }

#if RPI_VERBOSE == 1
    g_debug(READ_FILE_PARAMETER_SETTINGS_PLAIN, EXIT_FILE_NAME_SETTINGS_PLAIN, exit_config);
#endif

        rpi_close_settings_plain_file(&exit_setup, config_file);
        config_file = NULL;
    }

    rpi_free_settings_plain_file(&exit_setup);
    return exit_config;
}

guint rpi_write_exit_settings_plain_file(const gchar* exit_config)
{
    if (!exit_config)
    {
        g_critical(MISSING_PARAMETER_SETTINGS_PLAIN);
        return FAILED_SETTINGS_PLAIN;
    }

    ConfigFile exit_setup =
    {
        .name = g_strdup(EXIT_FILE_NAME_SETTINGS_PLAIN),
        .mode = g_strdup(WRITE_MODE_SETTINGS_PLAIN),
        .content = g_strdup(DEFAULT_EXIT_PARAMETER_SETTINGS_PLAIN)
    };
    FILE* config_file = rpi_open_settings_plain_file(&exit_setup);

    if (!config_file)
    {
        rpi_free_settings_plain_file(&exit_setup);
        return FAILED_SETTINGS_PLAIN;
    }

    gint status_put = fputs(exit_config, config_file);
    gint status_flash = fflush(config_file);

    if (status_put < 0 || status_flash < 0)
    {
        g_critical(FAILED_FILE_WRITE_SETTINGS_PLAIN);
        rpi_close_settings_plain_file(&exit_setup, config_file);
        config_file = NULL;
        rpi_free_settings_plain_file(&exit_setup);
        return FAILED_SETTINGS_PLAIN;
    }

#if RPI_VERBOSE == 1
    g_debug(WRITE_FILE_PARAMETER_SETTINGS_PLAIN, EXIT_FILE_NAME_SETTINGS_PLAIN, exit_config);
#endif

    rpi_close_settings_plain_file(&exit_setup, config_file);
    config_file = NULL;
    rpi_free_settings_plain_file(&exit_setup);
    return SUCCESS_SETTINGS_PLAIN;
}

static FILE* rpi_open_settings_plain_file(const ConfigFile* config)
{
    if (!config)
    {
        g_critical(MISSING_FILE_PARAMETERS_SETTINGS_PLAIN);
        return NULL;
    }

    if (!config->name)
    {
        g_critical(MISSING_FILE_NAME_SETTINGS_PLAIN);
        return NULL;
    }

    if (!config->mode)
    {
        g_critical(MISSING_FILE_MODE_SETTINGS_PLAIN);
        return NULL;
    }

    if (!config->content)
    {
        g_critical(MISSING_FILE_CONTENT_SETTINGS_PLAIN);
        return NULL;
    }

    config_dir_path = rpi_get_config_dir();

    if (!config_dir_path)
    {
        g_critical(FAILED_GET_CONFIGURATION_DIR_SETTINGS_PLAIN);
        return NULL;
    }

#if RPI_VERBOSE == 1
    g_debug(DIR_SETTINGS_PLAIN, config_dir_path);
#endif

    gchar *config_file_path = rpi_get_config_file_path(config->name, config->content);

    if (!config_file_path)
    {
        g_critical(FAILED_FILE_PATH_SETTINGS_PLAIN);
        return NULL;
    }

    FILE *config_file = fopen(config_file_path, config->mode);

    if (!config_file)
    {
        g_critical(FAILED_FILE_OPEN_SETTINGS_PLAIN);
        g_free(config_file_path);
        config_file_path = NULL;
        return NULL;
    }

#if RPI_VERBOSE == 1
    g_debug(OPEN_FILE_SETTINGS_PLAIN, config_file_path, config->mode);
#endif

    g_free(config_file_path);
    config_file_path = NULL;
    return config_file;
}

static void rpi_close_settings_plain_file(const ConfigFile* config, FILE* config_file)
{
    if (config_file)
    {
        gint status = fclose(config_file);

        if (status != 0)
        {
            g_critical(FAILED_FILE_CLOSE_SETTINGS_PLAIN);
        }

#if RPI_VERBOSE == 1
        if (config && config->name && status == 0)
        {
            g_debug(CLOSE_FILE_SETTINGS_PLAIN, config->name);
        }
#endif

    }
}

static void rpi_free_settings_plain_file(ConfigFile* config)
{
    if (config)
    {
        if (config->name)
        {
            g_free(config->name);
            config->name = NULL;
        }

        if (config->mode)
        {
            g_free(config->mode);
            config->mode = NULL;
        }

        if (config->content)
        {
            g_free(config->content);
            config->content = NULL;
        }
    }
}
