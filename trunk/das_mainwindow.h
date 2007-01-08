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
