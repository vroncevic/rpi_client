/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_user.c
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
#include <unistd.h>
#include <pwd.h>
#include "rpi_settings_user.h"

static const gchar* WARNING_LOG_FAILED_GET_USERNAME_SETTINGS_USER = "Unable to retrieve the username..\n";

gchar* rpi_get_username_settings_user(void)
{
    gchar* username = NULL;
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);

    if (!pw)
    {
        g_warning("%s", WARNING_LOG_FAILED_GET_USERNAME_SETTINGS_USER);
        return NULL;
    }

    if (pw && pw->pw_name)
    {
        username = g_strdup(pw->pw_name);
    }

    return username;
}
