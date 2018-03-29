#include "LogicTrainNumber.h"
LogicTrainNumber::LogicTrainNumber(QSqlDatabase &DB)
{
    this->DB = DB;
}
bool LogicTrainNumber::Insert(ModelTrainNumber &modelTrainNum)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("INSERT INTO TrainNumber VALUES('%1','%2','%3','%4','%5','%6','%7','%8','%9')")
        .arg(modelTrainNum.TN_Id())
        .arg(modelTrainNum.T_Id())
        .arg(modelTrainNum.TN_SStation())
        .arg(modelTrainNum.TN_EStation())
        .arg(modelTrainNum.TN_STime())
        .arg(modelTrainNum.TN_ETime())
        .arg(modelTrainNum.TN_TicketNum())
        .arg(modelTrainNum.TN_TicketPrice())
        .arg(modelTrainNum.TN_Distance())
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
bool LogicTrainNumber::Update(ModelTrainNumber &modelTrainNum)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("UPDATE TrainNumber SET T_Id='%1' , TN_SStation='%2' , TN_EStation='%3' , TN_STime='%4' , TN_ETime='%5' , TN_TicketNum='%6' , TN_TicketPrice='%7',TN_Distance='%8' WHERE TN_Id='%9'")
        .arg(modelTrainNum.T_Id())
        .arg(modelTrainNum.TN_SStation())
        .arg(modelTrainNum.TN_EStation())
        .arg(modelTrainNum.TN_STime())
        .arg(modelTrainNum.TN_ETime())
        .arg(modelTrainNum.TN_TicketNum())
        .arg(modelTrainNum.TN_TicketPrice())
        .arg(modelTrainNum.TN_Distance())
        .arg(modelTrainNum.TN_Id())
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;


}
bool LogicTrainNumber::Delete(QString TN_Id)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("DELETE FROM TrainNumber WHERE TN_Id='%1'")
        .arg(TN_Id)
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}

ModelTrainNumber LogicTrainNumber::GetTrainNumInfrom(QString TN_Id)
{
    ModelTrainNumber modelTrainNum;

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return modelTrainNum;
    }
    QString sql = CN("SELECT * FROM TrainNumber WHERE TN_Id='%1'")
                .arg(TN_Id)
                ;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {

        modelTrainNum.TN_Id(query.value("TN_Id").toString());
        modelTrainNum.T_Id(query.value("T_Id").toString());
        modelTrainNum.TN_SStation(query.value("TN_SStation").toString());
        modelTrainNum.TN_EStation(query.value("TN_EStation").toString());
        modelTrainNum.TN_STime(query.value("TN_STime").toString());
        modelTrainNum.TN_ETime(query.value("TN_ETime").toString());
        modelTrainNum.TN_TicketNum(query.value("TN_TicketNum").toString());
        modelTrainNum.TN_TicketPrice(query.value("TN_TicketPrice").toString());
        modelTrainNum.TN_Distance(query.value("TN_Distance").toString());

    }
    return modelTrainNum;


}
QVector<ModelTrainNumber> LogicTrainNumber::GetListByCondition(QString condition)//实现条件查询
{

    QVector<ModelTrainNumber> trainList;
    trainList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return trainList;
    }
    QString sql = CN("SELECT * FROM TrainNumber WHERE ")+condition;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        ModelTrainNumber modelTrainNum;
        modelTrainNum.TN_Id(query.value("TN_Id").toString());
        modelTrainNum.T_Id(query.value("T_Id").toString());
        modelTrainNum.TN_SStation(query.value("TN_SStation").toString());
        modelTrainNum.TN_EStation(query.value("TN_EStation").toString());
        modelTrainNum.TN_STime(query.value("TN_STime").toString());
        modelTrainNum.TN_ETime(query.value("TN_ETime").toString());
        modelTrainNum.TN_TicketNum(query.value("TN_TicketNum").toString());
        modelTrainNum.TN_TicketPrice(query.value("TN_TicketPrice").toString());
        modelTrainNum.TN_Distance(query.value("TN_Distance").toString());
        trainList.append(modelTrainNum);
    }
    return trainList;


}
QVector<ModelTrainNumber> LogicTrainNumber::GetList()
{
    QVector<ModelTrainNumber> trainList;
    trainList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return trainList;
    }
    QString sql = CN("SELECT * FROM TrainNumber");

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        ModelTrainNumber modelTrainNum;
        modelTrainNum.TN_Id(query.value("TN_Id").toString());
        modelTrainNum.T_Id(query.value("T_Id").toString());
        modelTrainNum.TN_SStation(query.value("TN_SStation").toString());
        modelTrainNum.TN_EStation(query.value("TN_EStation").toString());
        modelTrainNum.TN_STime(query.value("TN_STime").toString());
        modelTrainNum.TN_ETime(query.value("TN_ETime").toString());
        modelTrainNum.TN_TicketNum(query.value("TN_TicketNum").toString());
        modelTrainNum.TN_TicketPrice(query.value("TN_TicketPrice").toString());
        modelTrainNum.TN_Distance(query.value("TN_Distance").toString());
        trainList.append(modelTrainNum);
    }
    return trainList;

}

LogicTrainNumber::~LogicTrainNumber()
{

}
