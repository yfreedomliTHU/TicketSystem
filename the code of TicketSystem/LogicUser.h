#ifndef LOGIC_USER
#define LOGIC_USER
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtCore/QVector>
#include <QtWidgets/QWidget>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

//define
#include "Definition.h"

//model
#include "ModelUser.h"


class LogicUser:public QObject
{
	Q_OBJECT
public:
	LogicUser(QSqlDatabase &DB);
	~LogicUser();
	bool Insert(ModelUser &modelUser);
	bool Update(ModelUser &modelUser);
	ModelUser GetUserInfrom(QString userName);
	
	QString Login(QString userName,QString passWord);
	QVector<ModelUser> GetOtherUserInfrom(QString mainUser);

private:
	QSqlDatabase DB;


};




#endif