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

SettingsConfig* settings_read()
{
    SettingsConfig* configuration = NULL;
    FILE *pf1 = NULL;
    FILE *pf2 = NULL;
    FILE *pf3 = NULL;
    gint status = 0;

    gchar *res_dir = g_strjoin(NULL, g_get_current_dir(), RPIC_RES_CONFIG, NULL);
    pf1 = fopen(g_strjoin(NULL, res_dir, CONFIG_FILE_1, NULL), "rb");
    pf2 = fopen(g_strjoin(NULL, res_dir, CONFIG_FILE_2, NULL), "rb");
    pf3 = fopen(g_strjoin(NULL, res_dir, CONFIG_FILE_3, NULL), "rb");

    if (pf1 == NULL || pf2 == NULL || pf3 == NULL)
    {
        fclose(pf1);
        fclose(pf2);
        fclose(pf3);
        status = 1;
    }

    if (status == 0)
    {
        gchar tmp[17];
        fscanf(pf1, "%s", (gchar *)&tmp);
        g_print("%s\n", tmp);
        configuration->no_prompt = (gchar *) malloc(strlen(tmp));
        strcpy(configuration->no_prompt, tmp);
        fclose(pf1);
        fscanf(pf2, "%s", (gchar *)&tmp);
        g_print("%s\n", tmp);
        configuration->ip_address = (gchar *) malloc(strlen(tmp));
        strcpy(configuration->ip_address, tmp);
        fclose(pf2);
        fscanf(pf3, "%s", (gchar *)&tmp);
        g_print("%s\n", tmp);
        configuration->port_number = (gchar *) malloc(strlen(tmp));
        strcpy(configuration->port_number, tmp);
        fclose(pf3);

        return configuration;
    }

    configuration->no_prompt = SET_PROMPT;
    configuration->ip_address = "127.0.0.1";
    configuration->port_number = "8000";

    return configuration;
}
