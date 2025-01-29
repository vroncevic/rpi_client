/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_menu.h
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
#include "../rpi_config.h"
#include "../misc/rpi_misc.h"
#include "rpi_menu.h"

#if RPI_VERBOSE == 1
#define CONNECT_SIGNAL_RPI_MENU "Connect signal to submenu: %s.\n"
#endif

#define FAILED_MALLOC_RPI_MENU "Failed to allocate memory for menu bar.\n"

static const gchar* TEXT_MENU_FILE_RPI_MENU = "File";
static const gchar* TEXT_MENU_FILE_SUBMENU_EXIT_RPI_MENU = "Exit";
static const gchar* TEXT_MENU_OPTION_RPI_MENU = "Option";
static const gchar* TEXT_MENU_OPTION_SUBMENU_CONNECT_RPI_MENU = "Connect";
static const gchar* TEXT_MENU_OPTION_SUBMENU_DISCONNECT_RPI_MENU = "Disconnect";
static const gchar* TEXT_MENU_SETTINGS_RPI_MENU = "Settings";
static const gchar* TEXT_MENU_SETTINGS_SUBMENU_GENERAL_RPI_MENU = "General";
static const gchar* TEXT_MENU_SETTINGS_SUBMENU_NETWORK_RPI_MENU = "Network";
static const gchar* TEXT_MENU_HELP_RPI_MENU = "Help";
static const gchar* TEXT_MENU_HELP_SUBMENU_HELP_RPI_MENU = "Help";
static const gchar* TEXT_MENU_HELP_SUBMENU_ABOUT_RPI_MENU = "About";

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
struct _RPIMenu
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

RPIMenu *new_rpi_menu(void)
{
    RPIMenu *instance = g_malloc(sizeof(RPIMenu));

    if (!instance)
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        return NULL;
    }

    instance->menu_bar = gtk_menu_bar_new();

    if (!GTK_IS_MENU_BAR(instance->menu_bar))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_file = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_file))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_file_item = gtk_menu_item_new_with_label(TEXT_MENU_FILE_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_file_item))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_file_submenu_exit = gtk_menu_item_new_with_label(TEXT_MENU_FILE_SUBMENU_EXIT_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_file_submenu_exit))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_option = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_option))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_option_item = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_option_item))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_option_submenu_connect = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_SUBMENU_CONNECT_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_option_submenu_connect))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_option_submenu_disconnect = gtk_menu_item_new_with_label(TEXT_MENU_OPTION_SUBMENU_DISCONNECT_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_option_submenu_disconnect))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_settings = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_settings))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_settings_item = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_settings_item))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_settings_submenu_general = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_SUBMENU_GENERAL_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_settings_submenu_general))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_settings_submenu_network = gtk_menu_item_new_with_label(TEXT_MENU_SETTINGS_SUBMENU_NETWORK_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_settings_submenu_network))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_help = gtk_menu_new();

    if (!GTK_IS_MENU(instance->menu_help))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_help_item = gtk_menu_item_new_with_label(TEXT_MENU_HELP_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_help_item))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_help_submenu_help = gtk_menu_item_new_with_label(TEXT_MENU_HELP_SUBMENU_HELP_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_help_submenu_help))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
        return NULL;
    }

    instance->menu_help_submenu_about = gtk_menu_item_new_with_label(TEXT_MENU_HELP_SUBMENU_ABOUT_RPI_MENU);

    if (!GTK_IS_MENU_ITEM(instance->menu_help_submenu_about))
    {
        g_critical(FAILED_MALLOC_RPI_MENU);
        destroy_rpi_menu(instance);
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

void show_rpi_menu(RPIMenu *instance)
{
    if (instance)
    {
        gboolean is_rpi_menu = GTK_IS_MENU_BAR(instance->menu_bar);
        gboolean is_rpi_menu_visible = rpi_is_widget_visible_misc(GTK_WIDGET(instance->menu_bar));

        if (is_rpi_menu && !is_rpi_menu_visible)
        {
            rpi_set_visible_widget_misc(GTK_WIDGET(instance->menu_bar), !is_rpi_menu_visible);
        }
    }
}

void hide_rpi_menu(RPIMenu *instance)
{
    if (instance)
    {
        gboolean is_rpi_menu = GTK_IS_MENU_BAR(instance->menu_bar);
        gboolean is_rpi_menu_visible = rpi_is_widget_visible_misc(GTK_WIDGET(instance->menu_bar));

        if (is_rpi_menu && is_rpi_menu_visible)
        {
            rpi_set_visible_widget_misc(GTK_WIDGET(instance->menu_bar), !is_rpi_menu_visible);
        }
    }
}

GtkWidget *get_menu_bar_from_rpi_menu(RPIMenu *instance)
{
    if (instance)
    {
        gboolean is_menu_bar = GTK_IS_MENU_BAR(instance->menu_bar);

        if (is_menu_bar)
        {
            return instance->menu_bar;
        }
    }

    return NULL;
}

void rpi_menu_connect_signal(RPIMenu *instance, void (*on_callback)(GtkWidget *, gpointer), const gchar* submenu)
{
    if (g_strcmp0(TEXT_MENU_FILE_SUBMENU_EXIT_RPI_MENU, submenu) == 0)
    {
        g_signal_connect(G_OBJECT(instance->menu_file_submenu_exit), "activate", G_CALLBACK(on_callback), NULL);
    }

    if (g_strcmp0(TEXT_MENU_OPTION_SUBMENU_CONNECT_RPI_MENU, submenu) == 0)
    {
        g_signal_connect(G_OBJECT(instance->menu_option_submenu_connect), "activate", G_CALLBACK(on_callback), NULL);
    }

    if (g_strcmp0(TEXT_MENU_OPTION_SUBMENU_DISCONNECT_RPI_MENU, submenu) == 0)
    {
        g_signal_connect(G_OBJECT(instance->menu_option_submenu_disconnect), "activate", G_CALLBACK(on_callback), NULL);
    }

    if (g_strcmp0(TEXT_MENU_SETTINGS_SUBMENU_GENERAL_RPI_MENU, submenu) == 0)
    {
        g_signal_connect(G_OBJECT(instance->menu_settings_submenu_general), "activate", G_CALLBACK(on_callback), NULL);
    }

    if (g_strcmp0(TEXT_MENU_SETTINGS_SUBMENU_NETWORK_RPI_MENU, submenu) == 0)
    {
        g_signal_connect(G_OBJECT(instance->menu_settings_submenu_network), "activate", G_CALLBACK(on_callback), NULL);
    }

    if (g_strcmp0(TEXT_MENU_HELP_SUBMENU_HELP_RPI_MENU, submenu) == 0)
    {
        g_signal_connect(G_OBJECT(instance->menu_help_submenu_help), "activate", G_CALLBACK(on_callback), NULL);
    }

    if (g_strcmp0(TEXT_MENU_HELP_SUBMENU_ABOUT_RPI_MENU, submenu) == 0)
    {
        g_signal_connect(G_OBJECT(instance->menu_help_submenu_about), "activate", G_CALLBACK(on_callback), NULL);
    }

#if RPI_VERBOSE == 1
    g_debug(CONNECT_SIGNAL_RPI_MENU, submenu);
#endif
}

void destroy_rpi_menu(RPIMenu *instance)
{
    if (instance) 
    {
        if (GTK_IS_MENU_ITEM(instance->menu_file_submenu_exit))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_file_submenu_exit));
            instance->menu_file_submenu_exit = NULL;
        }

        if (GTK_IS_MENU(instance->menu_file))
        {
            gtk_widget_destroy(GTK_WIDGET(instance->menu_file));
            instance->menu_file = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_file_item))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_file_item));
            instance->menu_file_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_submenu_connect))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_option_submenu_connect));
            instance->menu_option_submenu_connect = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_submenu_disconnect))
        {
            rpi_destroy_widget_misc(instance->menu_option_submenu_disconnect);
            instance->menu_option_submenu_disconnect = NULL;
        }

        if (GTK_IS_MENU(instance->menu_option))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_option));
            instance->menu_option = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_option_item))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_option_item));
            instance->menu_option_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_submenu_general))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_settings_submenu_general));
            instance->menu_settings_submenu_general = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_submenu_network))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_settings_submenu_network));
            instance->menu_settings_submenu_network = NULL;
        }

        if (GTK_IS_MENU(instance->menu_settings))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_settings));
            instance->menu_settings = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_settings_item))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_settings_item));
            instance->menu_settings_item = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_submenu_help))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_help_submenu_help));
            instance->menu_help_submenu_help = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_submenu_about))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_help_submenu_about));
            instance->menu_help_submenu_about = NULL;
        }

        if (GTK_IS_MENU(instance->menu_help))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_help));
            instance->menu_help = NULL;
        }

        if (GTK_IS_MENU_ITEM(instance->menu_help_item))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_help_item));
            instance->menu_help_item = NULL;
        }

        if (GTK_IS_MENU_BAR(instance->menu_bar))
        {
            rpi_destroy_widget_misc(GTK_WIDGET(instance->menu_bar));
            instance->menu_bar = NULL;
        }

        g_free(instance);
    }
}
