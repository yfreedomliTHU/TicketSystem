#ifndef LOGIC_TRAINSEAT
#define LOGIC_TRAINSEAT
#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtWidgets/QWidget>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

//define
#include "Definition.h"

//model
#include "ModelTrainSeat.h"


class LogicTrainSeat :public QObject
{
	Q_OBJECT
public:
	LogicTrainSeat(QSqlDatabase &DB);
	~LogicTrainSeat();
	bool Insert(ModelTrainSeat &modelTrainSeat);
	bool DeleteByTrainSeat(QString T_Id,QString TS_SellNum);
	QStringList SellTicketListByTrain(QString T_Id);
	QStringList GetSellSeatListByTrain(QString T_Id,QString TN_Id);

private:
	QSqlDatabase DB;


};




#endif