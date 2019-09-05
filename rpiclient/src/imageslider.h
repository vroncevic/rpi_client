/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * imageslider.h
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
#ifndef __IMAGESLIDER_H
#define __IMAGESLIDER_H

#include "resource.h"

#define MAX_IMAGES_SLIDER				5
#define START_SLIDER_COUNT			   0
#define X_POSITION_IMAGE_SLIDER		  0
#define Y_POSITION_IMAGE_SLIDER		  0
#define WIDTH_IMAGE_SLIDER			   245
#define HEIGHT_IMAGE_SLIDER			  355
#define TEXT_BUTTON_LEFT_SLIDER		  "<<"
#define WIDTH_BUTTON_LEFT_SLIDER		 80
#define HEIGHT_BUTTON_LEFT_SLIDER		35
#define X_POSITION_BUTTON_LEFT_SLIDER	45
#define Y_POSITION_BUTTON_LEFT_SLIDER	355
#define TEXT_BUTTON_RIGHT_SLIDER		 ">>"
#define WIDTH_BUTTON_RIGHT_SLIDER		80
#define HEIGHT_BUTTON_RIGHT_SLIDER	   35
#define X_POSITION_BUTTON_RIGHT_SLIDER   125
#define Y_POSITION_BUTTON_RIGHT_SLIDER   355

typedef struct {
	GtkWidget *fixed;
	GtkWidget *image;
	GtkWidget *button_left;
	GtkWidget *button_right;
	guint slider_count;
} ImageSlider;

ImageSlider * new_image_slider();
void show_image_slider(ImageSlider *image_slider_ptr);
void hide_image_slider(ImageSlider *image_slider_ptr);
void destroy_image_slider(ImageSlider *image_slider_ptr);

#endif

