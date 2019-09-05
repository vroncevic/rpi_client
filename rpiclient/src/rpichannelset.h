/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpichannelset.h
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
#ifndef __RPICHANNELSET_H
#define __RPICHANNELSET_H

#include "verticalbar.h"

#define TOOLTIP_VERTICAL_BAR(num)		   "Channel " #num
#define TOOLTIP_SCALE(num)				  "Set Channel " #num
#define TOOLTIP_SPINNER_BUTTON(num)		 "Set level at channel " #num
#define TOOLTIP_CHECK_BOX_GPIO(num)		 "Active GPIO " #num
#define WIDTH_SCALE						 50
#define HEIGHT_SCALE						180
#define MIN_VALUE_SCALE					 0.0
#define MAX_VALUE_SCALE					 100.0
#define STEP_VALUE_SCALE					1.0
#define VALUE_SPINNER_ADJUSTMENT			0.0
#define LOWER_SPINNER_ADJUSTMENT			0.0
#define UPPER_SPINNER_ADJUSTMENT			100.0
#define STEP_INCREMENT_SPINNER_ADJUSTMENT   1.0
#define PAGE_INCREMENT_SPINNER_ADJUSTMENT   0.0
#define PAGE_SIZE_SPINNER_ADJUSTMENT		0.0
#define CLIMB_RATE_SPINNER_BUTTON		   1.0
#define DIGITS_SPINNER_BUTTON			   0
#define TEXT_CHECK_BOX_GPIO(num)			"GPIO " #num

typedef struct {
	GtkWidget *vbar_set;
	GtkWidget *scale;
	GtkAdjustment *spinner_adj;
	GtkWidget *spinner_button;
	GtkWidget *activate_gpio;
} RPIChannelSet;

RPIChannelSet * new_rpichannelset(gint channel_id);
void show_rpichannelset(RPIChannelSet *rpichannelset_ptr);
void hide_rpichannelset(RPIChannelSet *rpichannelset_ptr);
void destroy_rpichannelset(RPIChannelSet *rpichannelset_ptr);

#endif

