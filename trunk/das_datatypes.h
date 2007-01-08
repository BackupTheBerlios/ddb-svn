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

