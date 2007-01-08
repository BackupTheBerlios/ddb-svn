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

#include "das_newconnection.h"
#include "ui_newconnection.h"

dlg_newConnection::dlg_newConnection(QStringList db_list, str_ConnectData ConnectionData)
{
	setupUi(this);
	connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(boxShowDatabases_changed(int)));
	comboBox->addItem("localhost");
	// did we get a stringlist?
	if(!db_list.isEmpty()){
		comboBox_3->addItems(db_list);
		comboBox->addItem(ConnectionData.Hostname);
		comboBox_2->addItem(ConnectionData.Username);
		lineEdit->insert(ConnectionData.Password);
	}
}

str_ConnectData dlg_newConnection::getConnectionData()
{
	str_ConnectData dt;
	dt.Hostname = comboBox->currentText();
	dt.Username = comboBox_2->currentText();
	dt.Password = lineEdit->text();
	dt.Database = comboBox_3->currentText();
	dt.ShowDatabases = checkBox->isChecked();
return dt;
}

void dlg_newConnection::boxShowDatabases_changed(int state)
{
	if(state == Qt::Checked){
	  comboBox_3->setEnabled(false);
	  comboBox_3->clearEditText();
	}
	else 
	  comboBox_3->setEnabled(true);
}

