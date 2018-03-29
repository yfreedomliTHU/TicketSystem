
#ifndef LOGIC_TRAINNUM
#define LOGIC_TRAINNUM
#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtCore/QVector>
#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

//define
#include "Definition.h"

//model
#include "ModelTrainNumber.h"


class LogicTrainNumber :public QObject
{
	Q_OBJECT
public:
	LogicTrainNumber(QSqlDatabase &DB);
	~LogicTrainNumber();
	bool Insert(ModelTrainNumber &modelTrainNum);
	bool Update(ModelTrainNumber &modelTrainNum);
	bool Delete(QString TN_Id);
	
	QVector<ModelTrainNumber> GetList();
	QVector<ModelTrainNumber> GetListByCondition(QString condition);
	//QVector<ModelTrainNumber> GetListNoCurrentUser(QString u_Id);

	ModelTrainNumber GetTrainNumInfrom(QString TN_Id);
private:
	QSqlDatabase DB;


};




#endif