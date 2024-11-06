/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_decrypt.c
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
#include "rpi_format.h"

static const gchar* WARNING_LOG_FAILED_MISSING_IN_SEQ_DEC_ENCRYPT = "Missing input sequence for decrypt\n";
static const gchar* WARNING_LOG_FAILED_MALLOC_DEC_ENCRYPT = "Failed to allocate memory for decrypt output\n";

gchar *rpi_decrypt(const gchar *in, guint shift)
{
    if (!in)
    {
        g_warning("%s", WARNING_LOG_FAILED_MISSING_IN_SEQ_DEC_ENCRYPT);
        return NULL;
    }

    gint input_length = strlen(in);
    gchar *out = malloc((input_length + 1) * sizeof(*out));

    if (!out)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_DEC_ENCRYPT);
        return NULL;
    }

    for (int i = 0; i < input_length; i++)
    {
        gchar character = in[i];

        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        {
            character = tolower(character);

            if ((character = character - 'a' - shift) < 0)
            {
                character += 26;
            }

            out[i] = character % 26 + 'a';
            out[i] = toupper(out[i]);
        }
        else
        {
            out[i] = in[i] - shift;
        }
    }

    out[input_length] = '\0';
    return out;
}
