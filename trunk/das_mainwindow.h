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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QtGui/QWorkspace>
#include <QtGui/QDialog>
#include <QtGui/QPushButton>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QFrame>
#include <QtGui/QLineEdit>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtGui/QTableView>
#include <QtGui/QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include "das_datatypes.h"
#include "das_newconnection.h"

class das_mainwindow : public QMainWindow, Ui_MainWindow
{
	Q_OBJECT;

	public:
	  das_mainwindow(QWidget *);
	  ~das_mainwindow();

	private:
	  QWorkspace *das_Workspace;
	  QSqlDatabase theDatabase; // :-)
	  QSqlTableModel *theTableModel;
	  QSqlQueryModel *das_Model; // I like Kraftwerk :-)


	private slots:
	  void on_actionConnect_to_triggered();
	  void on_actionChoose_triggered();


};

#endif
