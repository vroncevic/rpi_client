/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * image_slider.h
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
#pragma once

#include "../resource/resource.h"

#define MAX_IMAGES_IMAGE_SLIDER (5)
#define START_COUNT_IMAGE_SLIDER (0)
#define X_POSITION_IMAGE_SLIDER (0)
#define Y_POSITION_IMAGE_SLIDER (0)
#define WIDTH_IMAGE_SLIDER (245)
#define HEIGHT_IMAGE_SLIDER (355)
#define TEXT_BUTTON_LEFT_IMAGE_SLIDER "<<"
#define WIDTH_BUTTON_LEFT_IMAGE_SLIDER (80)
#define HEIGHT_BUTTON_LEFT_IMAGE_SLIDER (35)
#define X_POSITION_BUTTON_LEFT_IMAGE_SLIDER (45)
#define Y_POSITION_BUTTON_LEFT_IMAGE_SLIDER (355)
#define TEXT_BUTTON_RIGHT_IMAGE_SLIDER ">>"
#define WIDTH_BUTTON_RIGHT_IMAGE_SLIDER (80)
#define HEIGHT_BUTTON_RIGHT_IMAGE_SLIDER (35)
#define X_POSITION_BUTTON_RIGHT_IMAGE_SLIDER (125)
#define Y_POSITION_BUTTON_RIGHT_IMAGE_SLIDER (355)
#define FIRST_IMAGE_HELP_IMAGE_SLIDER "1.png"
#define WARNING_MSG_IMAGE_SLIDER "Failed to allocate memory for image slider\n"
#define WARNING_LOG_FAILED_RESOURCE_IMAGE_SLIDER "Failed to get resource path for image slider\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Image slider complex widget
///   fixed - Gtk fixed container widget
///   image - Gtk image widget
///   button_left - Gtk button widget for left action
///   button_right - Gtk button widget for right action
///   slider_count - Slider count
typedef struct
{
    GtkWidget *fixed;
    GtkWidget *image;
    GtkWidget *button_left;
    GtkWidget *button_right;
    guint slider_count;
} ImageSlider;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget image slider
/// @return Image slider complex widget pointer
ImageSlider *new_image_slider(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show image slider complex widget
/// @param instance is pointer to complex widget image slider
void show_image_slider(ImageSlider *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide image slider complex widget
/// @param instance is pointer to complex widget image slider
void hide_image_slider(ImageSlider *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy image slider complex widget
/// @param instance is pointer to complex widget image slider
void destroy_image_slider(ImageSlider *instance);
