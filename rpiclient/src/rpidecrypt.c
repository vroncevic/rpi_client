/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpidecrypt.c
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
#include "rpiformat.h"

gchar *rpi_decrypt(const gchar* in, gint shift) {
    gint i;
    gint input_length = strlen(in);
    gchar *out = malloc((input_length + 1) * sizeof(*out));
    for(i = 0; i < input_length; i++) {
        gchar c = in[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            c = tolower(c);
            if((c = c -'a' - shift) < 0) {
                c += 26;
            }
            out[i] = c % 26 + 'a';
            out[i] = toupper(out[i]);
        } else {
            out[i] = in[i] - shift;
        }
    }
    out[input_length] = '\0';
    return out;
}

