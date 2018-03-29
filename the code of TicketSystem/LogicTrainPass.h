#ifndef LOGIC_TRAINPASS
#define LOGIC_TRAINPASS
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
#include "ModelTrainPass.h"


class LogicTrainPass :public QObject
{
	Q_OBJECT
public:
	LogicTrainPass(QSqlDatabase &DB);
	~LogicTrainPass();
	bool Insert(ModelTrainPass &modelTrainPass);
	bool Delete(QString T_Id);
	QVector<ModelTrainPass> GetList();
	QVector<ModelTrainPass> GetListByTrainNum(QString TN_Id);
private:
	QSqlDatabase DB;


};




#endif