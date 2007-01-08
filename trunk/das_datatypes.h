/*    This file is part of das_database.
 *
 *   das_database is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   das_database is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef DATATYPES_H
#define DATATYPES_H

//#include <cstdlib>
#include <QtCore/QString>

struct str_ConnectData{
	QString Hostname;
	QString Username;
	QString Password;
	QString Database;
	bool ShowDatabases;
};


#endif

