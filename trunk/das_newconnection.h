#include "ui_newconnection.h"
#include "das_datatypes.h"

class dlg_newConnection : public QDialog, Ui_Dialog
{
	Q_OBJECT;
	public:
	  dlg_newConnection(QStringList, str_ConnectData);
	public: 
	  str_ConnectData getConnectionData();
	private slots:
	  void boxShowDatabases_changed(int);
};

