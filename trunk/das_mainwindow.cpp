#include "das_mainwindow.h"

das_mainwindow::das_mainwindow(QWidget *parent = NULL)
{
	setupUi(this);
	das_Workspace = new QWorkspace();
	setCentralWidget(das_Workspace);
}

das_mainwindow::~das_mainwindow()
{

}


//-------------------------------
//  the slots
//  -----------------------------

void das_mainwindow::on_actionConnect_to_triggered()
{
	dlg_newConnection *dlgC;
	str_ConnectData ConnectionData;

	dlgC = new dlg_newConnection((QStringList)NULL, ConnectionData);
	if(dlgC->exec() == QDialog::Accepted){
		ConnectionData = dlgC->getConnectionData();
	} else {
		QMessageBox::warning(this,tr("Warning"), tr("Connecting process cancelled!"),tr("OK"),0,0,0);
	}
	delete dlgC;

// Case 1: The user gave a database-name
	if((ConnectionData.Database != "") && (ConnectionData.ShowDatabases == false)){

	  // Connect to Database-Server
	  theDatabase = QSqlDatabase::addDatabase("QMYSQL");
	  theDatabase.setHostName(ConnectionData.Hostname.toAscii());
	  theDatabase.setDatabaseName(ConnectionData.Database.toAscii());
	  theDatabase.setUserName(ConnectionData.Username.toAscii());
	  theDatabase.setPassword(ConnectionData.Password.toAscii());
	  if(!theDatabase.open()){
		  theDatabase.close();
		  QMessageBox::warning(this,tr("Warning"), tr("Connection failed."),tr("OK"),0,0,0);
		  return;
	  }
	}

// Case 2: The user did not give a database-name
// and/or SHOW DATABASES selected...
	if((ConnectionData.ShowDatabases == true) || (ConnectionData.Database == "")){

	  // Connect to Database-Server
	  theDatabase = QSqlDatabase::addDatabase("QMYSQL");
	  theDatabase.setHostName(ConnectionData.Hostname.toAscii());
	  //theDatabase.setDatabaseName(ConnectionData.Database.toAscii());
	  theDatabase.setUserName(ConnectionData.Username.toAscii());
	  theDatabase.setPassword(ConnectionData.Password.toAscii());
	  if(!theDatabase.open()){
		  theDatabase.close();
		  QMessageBox::warning(this,tr("Warning"), tr("Connection failed."),tr("OK"),0,0,0);
		  return;
	  }
	
	  // SHOW DATABASES
	  das_Model = new QSqlQueryModel();
	  das_Model->setQuery("SHOW DATABASES;");
	  QStringList l;
	  QString c;
	  for(int i = 0; i < das_Model->rowCount(); ++i){
		l.insert(i-1, das_Model->record(i).value("Database").toString());
	  }
	  // Close Connection for now...
	  theDatabase.close();
	  theDatabase.removeDatabase("QMYSQL");
	
	  // Reopen the Dialog with received DB-names
	  dlgC = new dlg_newConnection(l, ConnectionData);
	  if(dlgC->exec() == QDialog::Accepted){
		ConnectionData = dlgC->getConnectionData();
	  } else {
		QMessageBox::warning(this,tr("Warning"), tr("Connecting process cancelled!"),tr("OK"),0,0,0);
	  }
	  delete dlgC;
	  // We have everything. Reconnect to Database-Server
	  theDatabase = QSqlDatabase::addDatabase("QMYSQL");
	  theDatabase.setHostName(ConnectionData.Hostname.toAscii());
	  theDatabase.setDatabaseName(ConnectionData.Database.toAscii());
	  theDatabase.setUserName(ConnectionData.Username.toAscii());
	  theDatabase.setPassword(ConnectionData.Password.toAscii());
	  if(!theDatabase.open()){
		  theDatabase.close();
		  QMessageBox::warning(this,tr("Warning"), tr("Connection failed."),tr("OK"),0,0,0);
		  return;
	  }

	}

//
//  TODO: Anzeigen lassen, welche Tabellen vorhanden sind! TODO
//
	theTableModel = new QSqlTableModel();
	theTableModel->setTable("Mailadressen");
	if(!theTableModel->select()){
		delete theTableModel;
		theDatabase.close();
		QMessageBox::warning(this,"Warning", "Couldn't open table.","OK",0,0,0);
		return;
	}

	QTableView *v = new QTableView();
	das_Workspace->addWindow(v);
	v->setModel(theTableModel);
	v->setWindowTitle("just a test");
	v->show();

}



void das_mainwindow::on_actionChoose_triggered()
{
	qDebug("Nothing to choose from...");
}

