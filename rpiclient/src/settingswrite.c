/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settingswrite.c
 * Copyright (C) 2016 Vladimir Roncevic <elektron.ronca@gmail.com>
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
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "config.h"

gint settings_write(config config_settings) {
    FILE *pf1;
    FILE *pf2;
    FILE *pf3;
    gchar * res_dir = g_strjoin(NULL, g_get_current_dir(), RESOURCE_PATH, NULL);
    pf1 = fopen(g_strjoin(NULL, res_dir, CONFIG_FILE_1, NULL), "wb");
    pf2 = fopen(g_strjoin(NULL, res_dir, CONFIG_FILE_2, NULL), "wb");
    pf3 = fopen(g_strjoin(NULL, res_dir, CONFIG_FILE_3, NULL), "wb");
    if(pf1 == NULL || pf2 == NULL || pf3 == NULL) {
        fclose(pf1);
        fclose(pf2);
        fclose(pf3);
        return -1;
    }
    fputs(config_settings.no_prompt, pf1);
    fflush(pf1);
    fclose(pf1);
    fputs(config_settings.ip_address, pf2);
    fflush(pf2);
    fclose(pf2);
    fputs(config_settings.port_number, pf3);
    fflush(pf3);
    fclose(pf3);
    return 0;
}

