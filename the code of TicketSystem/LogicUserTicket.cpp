#include "LogicUserTicket.h"
LogicUserTicket::LogicUserTicket(QSqlDatabase &DB)
{
    this->DB = DB;
}
bool LogicUserTicket::Insert(ModelUserTicket &modelUserTicket)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("INSERT INTO UserTicket VALUES('%1','%2','%3','%4','%5','%6','%7','%8')")
        .arg(modelUserTicket.UT_Id())
        .arg(modelUserTicket.U_Id())
        .arg(modelUserTicket.TN_Id())
        .arg(modelUserTicket.UT_SStation())
        .arg(modelUserTicket.UT_EStation())
        .arg(modelUserTicket.UT_Type())
        .arg(modelUserTicket.UT_Price())
        .arg(modelUserTicket.UT_SeatNum())
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
bool LogicUserTicket::Delete(QString UT_Id)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("DELETE FROM UserTicket WHERE UT_Id='%1'")
        .arg(UT_Id)
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
QVector<ModelUserTicket> LogicUserTicket::GetListByUserName(QString U_Id)
{

    QVector<ModelUserTicket> userTicketList;

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return userTicketList;
    }
    QString sql = CN("SELECT * FROM UserTicket WHERE U_Id='%1'").arg(U_Id);
    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        ModelUserTicket modelUserTicket;
        modelUserTicket.UT_Id(query.value("UT_Id").toString());
        modelUserTicket.U_Id(query.value("U_Id").toString());
        modelUserTicket.TN_Id(query.value("TN_Id").toString());
        modelUserTicket.UT_SStation(query.value("UT_SStation").toString());
        modelUserTicket.UT_EStation(query.value("UT_EStation").toString());
        modelUserTicket.UT_Type(query.value("UT_Type").toString());
        modelUserTicket.UT_Price(query.value("UT_Price").toString());
        modelUserTicket.UT_SeatNum(query.value("UT_SeatNum").toString());

        userTicketList.append(modelUserTicket);
    }

    return userTicketList;

}
QStringList LogicUserTicket::GetUserTicket(QString userName)
{
    QStringList userTicketList;
    userTicketList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return userTicketList;
    }
    QString sql = CN("SELECT TN_Id FROM UserTicket WHERE U_Id='%1'")
        .arg(userName)
        ;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        userTicketList << query.value("TN_Id").toString();

    }
    return userTicketList;

}

LogicUserTicket::~LogicUserTicket()
{

}
