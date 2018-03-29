#ifndef FACTORY
#define FACTORY


#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QDebug>
#include <QtWidgets/QWidget>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>


#include "LogicUser.h"
#include "LogicTrain.h"
#include "LogicTrainPass.h"
#include "LogicTrainNumber.h"
#include "LogicUserTicket.h"
#include "LogicTrainSeat.h"

#include "Definition.h"
class Factory :public QObject
{
	Q_OBJECT
public:
	Factory();
	~Factory();

	void ConnectDataBase();
	void CloseDataBase();

	//logic
	LogicUser *logicUser;
	LogicTrain *logicTrain;
	LogicTrainPass *logicTrainPass;
	LogicTrainNumber *logicTrainNumber;
	LogicUserTicket *logicUserTicket;
	LogicTrainSeat *logicTrainSeat;
private:

	//database
	QSqlDatabase DB;
};




#endif