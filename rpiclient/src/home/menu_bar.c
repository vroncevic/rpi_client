/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * menu_bar.h
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
#include "menu_bar.h"

MenuBar *new_menu_bar(void)
{
    MenuBar *instance = g_malloc(sizeof(MenuBar));

    if(instance)
    {
        instance->menu_bar = gtk_menu_bar_new();
        instance->menu_file = gtk_menu_item_new_with_label(TEXT_MENU_FILE_MENU_BAR);
        instance->menu_file_submenu_exit = gtk_menu_item_new_with_label(TEXT_MENU_FILE_SUBMENU_EXIT_MENU_BAR);
        instance->menu_option = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_MENU_BAR);
        instance->menu_option_submenu_connect = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_SUBMENU_CONNECT_MENU_BAR);
        instance->menu_option_submenu_disconnect = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_SUBMENU_DISCONNECT_MENU_BAR);
        instance->menu_settings = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_MENU_BAR);
        instance->menu_settings_submenu_network = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_SUBMENU_NETWORK_MENU_BAR);
        instance->menu_help = gtk_menu_item_new_with_label(TEXT_MENU_HELP_MENU_BAR);
        instance->menu_help_submenu_help = gtk_menu_item_new_with_label(TEXT_MENU_HELP_SUBMENU_HELP_MENU_BAR);
        instance->menu_help_submenu_about = gtk_menu_item_new_with_label(TEXT_MENU_HELP_SUBMENU_ABOUT_MENU_BAR);
        gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_file);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_file), instance->menu_file_submenu_exit);
        gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_option);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_option), instance->menu_file_submenu_exit);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_option), instance->menu_option_submenu_disconnect);
        gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_settings);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_settings), instance->menu_settings_submenu_network);
        gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_help);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_help), instance->menu_help_submenu_help);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_help), instance->menu_help_submenu_about);
    }
    else
    {
        g_warning(WARNING_LOG_FAILED_MALLOC_MENU_BAR);
    }

    return instance;
}

void show_menu_bar(MenuBar *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->menu_bar)
    {
        gtk_widget_show(instance->menu_bar);
    }
}

void hide_menu_bar(MenuBar *instance)
{
    if (instance == NULL)
    {
        return;
    }

    if (instance->menu_bar)
    {
        gtk_widget_hide(instance->menu_bar);
    }
}

void destroy_menu_bar(MenuBar *instance)
{
    if (instance == NULL)
    {
        return;
    }

    gtk_widget_destroy(instance->menu_file);
    gtk_widget_destroy(instance->menu_file_submenu_exit);
    gtk_widget_destroy(instance->menu_option);
    gtk_widget_destroy(instance->menu_option_submenu_connect);
    gtk_widget_destroy(instance->menu_option_submenu_disconnect);
    gtk_widget_destroy(instance->menu_settings);
    gtk_widget_destroy(instance->menu_settings_submenu_network);
    gtk_widget_destroy(instance->menu_help);
    gtk_widget_destroy(instance->menu_help_submenu_help);
    gtk_widget_destroy(instance->menu_help_submenu_about);
    gtk_widget_destroy(instance->menu_bar);
    g_free(instance);
}
