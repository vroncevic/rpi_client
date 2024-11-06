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

static const gchar* TEXT_MENU_FILE_MENU_BAR = "File";
static const gchar* TEXT_MENU_FILE_SUBMENU_EXIT_MENU_BAR = "Exit";
static const gchar* TEXT_MENU_OPTION_MENU_BAR = "Option";
static const gchar* TEXT_MENU_OPTION_SUBMENU_CONNECT_MENU_BAR = "Connect";
static const gchar* TEXT_MENU_OPTION_SUBMENU_DISCONNECT_MENU_BAR = "Disconnect";
static const gchar* TEXT_MENU_SETTINGS_MENU_BAR = "Settings";
static const gchar* TEXT_MENU_SETTINGS_SUBMENU_GENERAL_MENU_BAR = "General";
static const gchar* TEXT_MENU_SETTINGS_SUBMENU_NETWORK_MENU_BAR = "Network";
static const gchar* TEXT_MENU_HELP_MENU_BAR = "Help";
static const gchar* TEXT_MENU_HELP_SUBMENU_HELP_MENU_BAR = "Help";
static const gchar* TEXT_MENU_HELP_SUBMENU_ABOUT_MENU_BAR = "About";
static const gchar* WARNING_LOG_FAILED_MALLOC_MENU_BAR = "Failed to allocate memory for menu bar\n";

MenuBar *new_menu_bar(void)
{
    MenuBar *instance = g_malloc(sizeof(MenuBar));

    if (!instance)
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        return NULL;
    }

    instance->menu_bar = gtk_menu_bar_new();

    if (!GTK_IS_MENU_BAR(instance->menu_bar))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_file = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_file))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_file_item = gtk_menu_item_new_with_label(TEXT_MENU_FILE_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_file_item))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_file_submenu_exit = gtk_menu_item_new_with_label(TEXT_MENU_FILE_SUBMENU_EXIT_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_file_submenu_exit))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_option = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_option))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_option_item = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_option_item))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_option_submenu_connect = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_SUBMENU_CONNECT_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_option_submenu_connect))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_option_submenu_disconnect = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_SUBMENU_DISCONNECT_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_option_submenu_disconnect))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_settings = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_settings))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_settings_item = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_settings_item))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_settings_submenu_general = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_SUBMENU_GENERAL_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_settings_submenu_general))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_settings_submenu_network = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_SUBMENU_NETWORK_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_settings_submenu_network))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_help = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_help))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_help_item = gtk_menu_item_new_with_label(TEXT_MENU_HELP_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_help_item))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_help_submenu_help = gtk_menu_item_new_with_label(TEXT_MENU_HELP_SUBMENU_HELP_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_help_submenu_help))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    instance->menu_help_submenu_about = gtk_menu_item_new_with_label(TEXT_MENU_HELP_SUBMENU_ABOUT_MENU_BAR);

    if (!GTK_IS_MENU_ITEM(instance->menu_help_submenu_about))
    {
        g_warning("%s", WARNING_LOG_FAILED_MALLOC_MENU_BAR);
        destroy_menu_bar(instance);
        return NULL;
    }

    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_file), instance->menu_file_submenu_exit);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_file_item), instance->menu_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_file_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_option), instance->menu_option_submenu_connect);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_option), instance->menu_option_submenu_disconnect);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_option_item), instance->menu_option);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_option_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_settings), instance->menu_settings_submenu_general);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_settings), instance->menu_settings_submenu_network);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_settings_item), instance->menu_settings);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_settings_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_help), instance->menu_help_submenu_help);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_help), instance->menu_help_submenu_about);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_help_item), instance->menu_help);
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), instance->menu_help_item);

    return instance;
}

void show_menu_bar(MenuBar *instance)
{
    if (instance && GTK_IS_MENU_BAR(instance->menu_bar) && !gtk_widget_get_visible(instance->menu_bar))
    {
        gtk_widget_show(instance->menu_bar);
    }
}

void hide_menu_bar(MenuBar *instance)
{
    if (instance && GTK_IS_MENU_BAR(instance->menu_bar) && gtk_widget_get_visible(instance->menu_bar))
    {
        gtk_widget_hide(instance->menu_bar);
    }
}

void destroy_menu_bar(MenuBar *instance)
{
    if (instance) 
    {
        if (GTK_IS_MENU_ITEM(instance->menu_file_submenu_exit))
        {
            gtk_widget_destroy(instance->menu_file_submenu_exit);
            instance->menu_file_submenu_exit = NULL;
        }

        if (GTK_IS_MENU(instance->menu_file))
        {
            gtk_widget_destroy(instance->menu_file);
            instance->menu_file = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_file_item))
        {
            gtk_widget_destroy(instance->menu_file_item);
            instance->menu_file_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_submenu_connect))
        {
            gtk_widget_destroy(instance->menu_option_submenu_connect);
            instance->menu_option_submenu_connect = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_submenu_disconnect))
        {
            gtk_widget_destroy(instance->menu_option_submenu_disconnect);
            instance->menu_option_submenu_disconnect = NULL;
        }

        if (GTK_IS_MENU(instance->menu_option))
        {
            gtk_widget_destroy(instance->menu_option);
            instance->menu_option = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_item))
        {
            gtk_widget_destroy(instance->menu_option_item);
            instance->menu_option_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_submenu_general))
        {
            gtk_widget_destroy(instance->menu_settings_submenu_general);
            instance->menu_settings_submenu_general = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_submenu_network))
        {
            gtk_widget_destroy(instance->menu_settings_submenu_network);
            instance->menu_settings_submenu_network = NULL;
        }

        if (GTK_IS_MENU(instance->menu_settings))
        {
            gtk_widget_destroy(instance->menu_settings);
            instance->menu_settings = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_item))
        {
            gtk_widget_destroy(instance->menu_settings_item);
            instance->menu_settings_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_submenu_help))
        {
            gtk_widget_destroy(instance->menu_help_submenu_help);
            instance->menu_help_submenu_help = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_submenu_about))
        {
            gtk_widget_destroy(instance->menu_help_submenu_about);
            instance->menu_help_submenu_about = NULL;
        }

        if (GTK_IS_MENU(instance->menu_help))
        {
            gtk_widget_destroy(instance->menu_help);
            instance->menu_help = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_item))
        {
            gtk_widget_destroy(instance->menu_help_item);
            instance->menu_help_item = NULL;
        }

        if (GTK_IS_MENU_BAR(instance->menu_bar))
        {
            gtk_widget_destroy(instance->menu_bar);
            instance->menu_bar = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
