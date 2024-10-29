/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_free.c
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

        g_free(instance);
        instance = NULL;
    }
}
