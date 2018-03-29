#include "LogicTrain.h"
LogicTrain::LogicTrain(QSqlDatabase &DB)
{
    this->DB = DB;
}
bool LogicTrain::Insert(ModelTrain &modelTrain)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("INSERT INTO Train VALUES('%1','%2','%3')")
        .arg(modelTrain.T_Id())
        .arg(modelTrain.T_Type())
        .arg(modelTrain.T_SeatType())
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
bool LogicTrain::Delete(QString T_Id)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("DELETE FROM Train WHERE T_Id='%1'")
        .arg(T_Id)
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
ModelTrain LogicTrain::GetTrainInfromById(QString T_Id)
{

    ModelTrain trainList;

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return trainList;
    }
    QString sql = CN("SELECT * FROM Train WHERE T_Id='%1'")
        .arg(T_Id)
        ;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        trainList.T_Id(query.value("T_Id").toString());
        trainList.T_Type(query.value("T_Type").toString());
        trainList.T_SeatType(query.value("T_SeatType").toString());
        break;
    }
    return trainList;
}
QVector<ModelTrain> LogicTrain::GetList()
{
    QVector<ModelTrain> trainList;
    trainList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return trainList;
    }
    QString sql = CN("SELECT * FROM Train");

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        ModelTrain modelTrain;
        modelTrain.T_Id(query.value("T_Id").toString());
        modelTrain.T_Type(query.value("T_Type").toString());
        modelTrain.T_SeatType(query.value("T_SeatType").toString());

        trainList.append(modelTrain);
    }
    return trainList;

}

LogicTrain::~LogicTrain()
{

}
