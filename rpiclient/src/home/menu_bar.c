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

//////////////////////////////////////////////////////////////////////////////
/// @brief Menu bar complex widget
///   menu_bar - Gtk menu bar widget
///   menu_file - Gtk menu item widget for file
///   menu_file_submenu_quit - Gtk menu item widget for submenu exit
///   menu_option - Gtk menu item widget for option
///   menu_option_submenu_connect - Gtk menu item widget for submenu connect
///   menu_option_submenu_disconnect - Gtk menu item widget for submenu disconnect
///   menu_settings - Gtk menu item widget for settings
///   menu_settings_submenu_network - Gtk menu item widget for submenu network
///   menu_help - Gtk menu item widget for help 
///   menu_help_submenu_help - Gtk menu item widget for submenu help
///   menu_help_submenu_about - Gtk menu item widget for submenu about
struct _MenuBar
{
	GtkWidget *menu_bar;
	GtkWidget *menu_file;
	GtkWidget *menu_file_item;
	GtkWidget *menu_file_submenu_exit;
	GtkWidget *menu_option;
	GtkWidget *menu_option_item;
	GtkWidget *menu_option_submenu_connect;
	GtkWidget *menu_option_submenu_disconnect;
	GtkWidget *menu_settings;
	GtkWidget *menu_settings_item;
	GtkWidget *menu_settings_submenu_general;
	GtkWidget *menu_settings_submenu_network;
	GtkWidget *menu_help;
	GtkWidget *menu_help_item;
	GtkWidget *menu_help_submenu_help;
	GtkWidget *menu_help_submenu_about;
};

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

    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_file), GTK_WIDGET(instance->menu_file_submenu_exit));
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_file_item), GTK_WIDGET(instance->menu_file));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), GTK_WIDGET(instance->menu_file_item));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_option), GTK_WIDGET(instance->menu_option_submenu_connect));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_option), GTK_WIDGET(instance->menu_option_submenu_disconnect));
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_option_item), GTK_WIDGET(instance->menu_option));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), GTK_WIDGET(instance->menu_option_item));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_settings), GTK_WIDGET(instance->menu_settings_submenu_general));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_settings), GTK_WIDGET(instance->menu_settings_submenu_network));
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_settings_item), GTK_WIDGET(instance->menu_settings));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), GTK_WIDGET(instance->menu_settings_item));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_help), GTK_WIDGET(instance->menu_help_submenu_help));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_help), GTK_WIDGET(instance->menu_help_submenu_about));
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(instance->menu_help_item), GTK_WIDGET(instance->menu_help));
    gtk_menu_shell_append(GTK_MENU_SHELL(instance->menu_bar), GTK_WIDGET(instance->menu_help_item));

    return instance;
}

void show_menu_bar(MenuBar *instance)
{
    if (instance)
    {
        gboolean is_menu_bar = GTK_IS_MENU_BAR(instance->menu_bar);
        gboolean is_menu_bar_hidden = !gtk_widget_get_visible(GTK_WIDGET(instance->menu_bar));

        if (is_menu_bar && is_menu_bar_hidden)
        {
            gtk_widget_show(GTK_WIDGET(instance->menu_bar));
        }
    }
}

void hide_menu_bar(MenuBar *instance)
{
    if (instance)
    {
        gboolean is_menu_bar = GTK_IS_MENU_BAR(instance->menu_bar);
        gboolean is_menu_bar_visible = !gtk_widget_get_visible(GTK_WIDGET(instance->menu_bar));

        if (is_menu_bar && is_menu_bar_visible)
        {
            gtk_widget_hide(GTK_WIDGET(instance->menu_bar));
        }
    }
}

GtkWidget *get_bar_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) ? instance->menu_bar : NULL;
}

GtkWidget* get_exit_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) && GTK_IS_MENU_ITEM(instance->menu_file_submenu_exit) ? instance->menu_file_submenu_exit : NULL;
}

GtkWidget* get_connect_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) && GTK_IS_MENU_ITEM(instance->menu_option_submenu_connect) ? instance->menu_option_submenu_connect : NULL;
}

GtkWidget* get_disconnect_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) && GTK_IS_MENU_ITEM(instance->menu_option_submenu_disconnect) ? instance->menu_option_submenu_disconnect : NULL;
}

GtkWidget* get_general_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) && GTK_IS_MENU_ITEM(instance->menu_settings_submenu_general) ? instance->menu_settings_submenu_general : NULL;
}

GtkWidget* get_network_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) && GTK_IS_MENU_ITEM(instance->menu_settings_submenu_network) ? instance->menu_settings_submenu_network : NULL;
}

GtkWidget* get_help_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) && GTK_IS_MENU_ITEM(instance->menu_help_submenu_help) ? instance->menu_help_submenu_help : NULL;
}

GtkWidget* get_about_menu_bar(MenuBar *instance)
{
    return instance && GTK_IS_MENU_BAR(instance->menu_bar) && GTK_IS_MENU_ITEM(instance->menu_help_submenu_about) ? instance->menu_help_submenu_about : NULL;
}

void destroy_menu_bar(MenuBar *instance)
{
    if (instance) 
    {
        if (GTK_IS_MENU_ITEM(instance->menu_file_submenu_exit))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_file_submenu_exit));
            instance->menu_file_submenu_exit = NULL;
        }

        if (GTK_IS_MENU(instance->menu_file))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_file));
            instance->menu_file = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_file_item))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_file_item));
            instance->menu_file_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_submenu_connect))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_option_submenu_connect));
            instance->menu_option_submenu_connect = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_submenu_disconnect))
        {
            gtk_widget_destroy(instance->menu_option_submenu_disconnect);
            instance->menu_option_submenu_disconnect = NULL;
        }

        if (GTK_IS_MENU(instance->menu_option))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_option));
            instance->menu_option = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_item))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_option_item));
            instance->menu_option_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_submenu_general))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_settings_submenu_general));
            instance->menu_settings_submenu_general = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_submenu_network))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_settings_submenu_network));
            instance->menu_settings_submenu_network = NULL;
        }

        if (GTK_IS_MENU(instance->menu_settings))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_settings));
            instance->menu_settings = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_item))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_settings_item));
            instance->menu_settings_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_submenu_help))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_help_submenu_help));
            instance->menu_help_submenu_help = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_submenu_about))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_help_submenu_about));
            instance->menu_help_submenu_about = NULL;
        }

        if (GTK_IS_MENU(instance->menu_help))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_help));
            instance->menu_help = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_item))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_help_item));
            instance->menu_help_item = NULL;
        }

        if (GTK_IS_MENU_BAR(instance->menu_bar))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_bar));
            instance->menu_bar = NULL;
        }

        g_free((gpointer)instance);
        instance = NULL;
    }
}
