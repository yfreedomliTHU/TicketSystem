#ifndef LOGIC_TRAIN
#define LOGIC_TRAIN
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
#include "ModelTrain.h"


class LogicTrain :public QObject
{
	Q_OBJECT
public:
	LogicTrain(QSqlDatabase &DB);
	~LogicTrain();
	bool Insert(ModelTrain &modelTrain);
	bool Delete(QString T_Id);
	ModelTrain GetTrainInfromById(QString T_Id);
	QVector<ModelTrain> GetList();

private:
	QSqlDatabase DB;


};




#endif