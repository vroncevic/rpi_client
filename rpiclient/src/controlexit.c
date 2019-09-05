/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * controlexit.c
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
#include "controlexit.h"

ControlExit * new_control_exit() {
    ControlExit *control_exit_ptr = g_malloc(sizeof(ControlExit));
    control_exit_ptr->frame = gtk_frame_new(TEXT_FRAME_EXIT);
    gtk_frame_set_shadow_type(
        GTK_FRAME(control_exit_ptr->frame), GTK_SHADOW_IN
    );
    control_exit_ptr->control_exit = gtk_check_button_new_with_label(
        TEXT_CHECK_BUTTON_EXIT
    );
    gtk_toggle_button_set_active(
        GTK_TOGGLE_BUTTON(control_exit_ptr->control_exit), TRUE
    );
    gtk_container_add(
        GTK_CONTAINER(control_exit_ptr->frame), control_exit_ptr->control_exit
    );
    return control_exit_ptr;
}

void show_control_exit(ControlExit *control_exit_ptr) {
    if(control_exit_ptr) {
        gtk_widget_show_all(control_exit_ptr->frame);
    }
}

void hide_control_exit(ControlExit *control_exit_ptr) {
    if(control_exit_ptr) {
        gtk_widget_hide_all(control_exit_ptr->frame);
    }
}

void destroy_control_exit(ControlExit *control_exit_ptr) {
    if(control_exit_ptr) {
        gtk_widget_destroy(control_exit_ptr->control_exit);
        gtk_widget_destroy(control_exit_ptr->frame);
        g_free(control_exit_ptr->control_exit);
        g_free(control_exit_ptr->frame);
        g_free(control_exit_ptr);
    }
}

