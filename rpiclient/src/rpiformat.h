/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiformat.c
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
#ifndef __RPIFORMAT_H
#define __RPIFORMAT_H

#include "resource.h"

#define CHECK_TYPE(typeOne, typeTwo) { \
		#typeOne == #typeTwo ? 0 : 1 \
	}

#define START_REQ				 "start:"
#define END_REQ				   ":end"
#define SEPARATOR				 ":"
#define ACTIVATE_PIN(num)		 "AP"#num
#define DEACTIVATE_PIN(num)	   "DP"#num
#define ACTIVATE_CHANNEL(num)	 "AC"#num
#define DEACTIVATE_CHANNEL(num)   "DC"#num
#define USED_CHANNELS			 8

#define RPI_INIT() {\
			int i;\
			for(i = 0; i < USED_CHANNELS; i++) {\
				rpi.channel_data[i] = 0;\
				rpi.pins[0] = DEACT_PIN_1;\
				rpi.channels[0] = DEACTIVE_CHANNEL_1;\
			}\
		}

typedef struct {
	gchar *pins[USED_CHANNELS];
	gchar *channels[USED_CHANNELS];
	gchar channel_data[USED_CHANNELS];
} RPIFormat;

/*gchar *rpi_encrypt(const gchar* in, gint shift);*/
/*gchar *rpi_decrypt(const gchar* in, gint shift);*/

#endif

