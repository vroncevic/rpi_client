/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_format.h
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
#pragma once

#include <glib.h>

//////////////////////////////////////////////////////////////////////////////
/// @brief Number of RPI channels
#define USED_CHANNELS_FORMAT (8)

//////////////////////////////////////////////////////////////////////////////
/// @brief RPI channels complex structure
typedef struct _RPIChannels RPIChannels;

//////////////////////////////////////////////////////////////////////////////
/// @brief Init RPI channels complex structure
/// @param instance is pointer to RPI channels structure
void rpi_format_init(RPIChannels *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Prepares PIN operation in string format
/// @param op is PIN operation
/// @param pin_id is PIN ID
/// @return PIN operation in string format | NULL
gchar* pin_operation(const gchar* op, guint pin_id);

//////////////////////////////////////////////////////////////////////////////
/// @brief Prepares channel operation in string format
/// @param op is channel operation
/// @param channel_id is channel ID
/// @return Channel operation in string format | NULL
gchar* channel_operation(const gchar* op, guint channel_id);

//////////////////////////////////////////////////////////////////////////////
/// @brief Encrypt input data sequence
/// @param in is pointer to input data sequence for encrypt operation
/// @param shift is shift value
/// @return encrypted data sequence | NULL
gchar* rpi_format_encrypt(const gchar* in, guint shift);

//////////////////////////////////////////////////////////////////////////////
/// @brief Decrypt input data sequence
/// @param in is pointer to input data sequence for decrypt operation
/// @param shift is shift value
/// @return decrypted data sequence | NULL
gchar* rpi_format_decrypt(const gchar* in, guint shift);

//////////////////////////////////////////////////////////////////////////////
/// @brief Free allocated memory for RPI channels structure
/// @param instance is pointer to RPI channels structure
void rpi_format_free(RPIChannels *instance);