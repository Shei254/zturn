/*
 * Copyright (c) 2021 Paul-Louis Ageneau
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
 */

#include <juice/juice.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct zturn_options {
	juice_log_level_t log_level;
	juice_server_config_t config;
	const char *log_filename;
	bool daemon;
	bool stun_only;
} zturn_options_t;

void zturn_options_init(zturn_options_t *vopts);
void zturn_options_destroy(zturn_options_t *vopts);
int zturn_options_from_file(FILE *file, zturn_options_t *vopts);
int zturn_options_from_arg(int argc, char *argv[], zturn_options_t *vopts);
