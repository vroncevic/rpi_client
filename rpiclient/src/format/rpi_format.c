/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_format.c
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
#include "rpi_format.h"

#define USED_CHANNELS (8)

// TODO: move to functions and variables
#define CHECK_TYPE(typeOne, typeTwo) {#typeOne == #typeTwo ? 0 : 1}
#define START_REQ "start:"
#define END_REQ ":end"
#define SEPARATOR ":"

#define MISSING_IN_SEQ_ENC_ENCRYPT "Missing input sequence for encrypt.\n"
#define MISSING_IN_SEQ_DEC_ENCRYPT "Missing input sequence for decrypt.\n"

#define FAILED_MALLOC_ENC_ENCRYPT "Failed to allocate memory for encrypt output.\n"
#define FAILED_MALLOC_DEC_ENCRYPT "Failed to allocate memory for decrypt output.\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief RPI channels complex structure
///   pins - TODO
///   channels - TODO
///   channel_data - TODO
struct _RPIChannels
{
	gchar *pins[USED_CHANNELS];
	gchar *channels[USED_CHANNELS];
	gchar channel_data[USED_CHANNELS];
};

void rpi_format_init(RPIChannels *instance)
{
    for (guint i = 0; i < USED_CHANNELS; i++) 
    {
        instance->pins[i] = pin_operation("DP", i);
        instance->channels[i] = channel_operation("DC", i);
        instance->channel_data[i] = 0; 
    }
}

gchar* pin_operation(const gchar* op, guint pin_id)
{
    if (!op || pin_id > USED_CHANNELS)
    {
        return NULL;
    }

    gchar* operation = g_malloc(g_utf8_strlen(op, -1) + 2);
    snprintf(operation, g_utf8_strlen(op, -1) + 2, "%s%d", op, pin_id);
    return operation; 
}

gchar* channel_operation(const gchar* op, guint channel_id)
{
    if (!op || channel_id > USED_CHANNELS)
    {
        return NULL;
    }

    gchar* operation = g_malloc(g_utf8_strlen(op, -1) + 2);
    snprintf(operation, g_utf8_strlen(op, -1) + 2, "%s%d", op, channel_id);
    return operation; 
}

gchar *rpi_format_encrypt(const gchar *in, guint shift)
{
    if (!in)
    {
        g_critical(MISSING_IN_SEQ_ENC_ENCRYPT);
        return NULL;
    }

    glong input_length = g_utf8_strlen(in, -1);
    gchar *out = g_malloc((input_length + 1) * sizeof(*out));

    if (!out)
    {
        g_critical(FAILED_MALLOC_ENC_ENCRYPT);
        return NULL;
    }

    for (glong i = 0; i < input_length; i++)
    {
        gchar character = in[i];

        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        {
            character = g_ascii_toupper(character);
            out[i] = ((character - 'a') + shift) % 26 + 'a';
        }
        else
        {
            out[i] = in[i] + shift;
        }
    }

    out[input_length] = '\0';
    return out;
}

gchar *rpi_format_decrypt(const gchar *in, guint shift)
{
    if (!in)
    {
        g_critical(MISSING_IN_SEQ_DEC_ENCRYPT);
        return NULL;
    }

    glong input_length = g_utf8_strlen(in, -1);
    gchar *out = g_malloc((input_length + 1) * sizeof(*out));

    if (!out)
    {
        g_critical(FAILED_MALLOC_DEC_ENCRYPT);
        return NULL;
    }

    for (glong i = 0; i < input_length; i++)
    {
        gchar character = in[i];

        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        {
            character = g_ascii_tolower(character);

            if ((character = character - 'a' - shift) < 0)
            {
                character += 26;
            }

            out[i] = character % 26 + 'a';
            out[i] = g_ascii_toupper(out[i]);
        }
        else
        {
            out[i] = in[i] - shift;
        }
    }

    out[input_length] = '\0';
    return out;
}
