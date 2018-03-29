#include "LogicTrainSeat.h"
LogicTrainSeat::LogicTrainSeat(QSqlDatabase &DB)
{
    this->DB = DB;
}
bool LogicTrainSeat::Insert(ModelTrainSeat &modelTrainSeat)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("INSERT INTO TrainSeat VALUES('%1','%2','%3')")
        .arg(modelTrainSeat.TS_Id())
        .arg(modelTrainSeat.T_Id())
        .arg(modelTrainSeat.TS_SellNum())
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
bool LogicTrainSeat::DeleteByTrainSeat(QString T_Id,QString TS_SellNum)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("DELETE FROM TrainSeat WHERE TS_SellNum='%1' AND T_Id='%2'")
        .arg(TS_SellNum)
        .arg(T_Id)
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
QStringList LogicTrainSeat::GetSellSeatListByTrain(QString T_Id,QString TN_Id)
{
    QStringList userSeatList;
    userSeatList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return userSeatList;
    }
    QString sql = CN("SELECT TS_SellNum FROM TrainSeat,TrainNumber,Train WHERE TrainSeat.T_Id=Train.T_Id AND Train.T_Id=TrainNumber.T_Id AND TrainNumber.T_Id='%1' AND TrainNumber.TN_Id='%2'")
        .arg(T_Id)
        .arg(TN_Id)
        ;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        userSeatList << query.value("TS_SellNum").toString();

    }
    return userSeatList;




}
QStringList LogicTrainSeat::SellTicketListByTrain(QString T_Id)
{
    QStringList userSeatList;
    userSeatList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return userSeatList;
    }
    QString sql = CN("SELECT * FROM TrainSeat WHERE T_Id='%1'")
        .arg(T_Id)
        ;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        userSeatList << query.value("TN_Id").toString();

    }
    return userSeatList;

}
LogicTrainSeat::~LogicTrainSeat()
{

}
