#ifndef LOGIC_USERTICKET
#define LOGIC_USERTICKET
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
#include "ModelUserTicket.h"


class LogicUserTicket :public QObject
{
	Q_OBJECT
public:
	LogicUserTicket(QSqlDatabase &DB);
	~LogicUserTicket();
	bool Insert(ModelUserTicket &modelUserTicket);
	bool Delete(QString UT_Id);
	QStringList GetUserTicket(QString userName);

	QVector<ModelUserTicket> GetListByUserName(QString U_Id);

private:
	QSqlDatabase DB;


};




#endif