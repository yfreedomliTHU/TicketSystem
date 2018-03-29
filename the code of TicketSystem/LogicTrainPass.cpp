#include "LogicTrainPass.h"
LogicTrainPass::LogicTrainPass(QSqlDatabase &DB)
{
    this->DB = DB;
}
bool LogicTrainPass::Insert(ModelTrainPass &modelTrainPass)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("INSERT INTO TrainPass VALUES('%1','%2','%3','%4','%5','%6')")
        .arg(modelTrainPass.TP_Id())
        .arg(modelTrainPass.TN_Id())
        .arg(modelTrainPass.TP_SStation())
        .arg(modelTrainPass.TP_SName())
        .arg(modelTrainPass.TP_Distance())
        .arg(modelTrainPass.TP_Price())

        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
bool LogicTrainPass::Delete(QString TP_Id)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("DELETE FROM TrainPass WHERE TP_Id='%1'")
        .arg(TP_Id)
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;
}
QVector<ModelTrainPass> LogicTrainPass::GetListByTrainNum(QString TN_Id)
{
    QVector<ModelTrainPass> trainPassList;
    trainPassList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return trainPassList;
    }
    QString sql = CN("SELECT * FROM TrainPass WHERE TN_Id='%1'")
        .arg(TN_Id)
        ;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        ModelTrainPass modelTrainNum;
        modelTrainNum.TP_Id(query.value("TP_Id").toString());
        modelTrainNum.TN_Id(query.value("TN_Id").toString());
        modelTrainNum.TP_SStation(query.value("TP_SStation").toString());
        modelTrainNum.TP_SName(query.value("TP_SName").toString());
        modelTrainNum.TP_Distance(query.value("TP_Distance").toString());
        modelTrainNum.TP_Price(query.value("TP_Price").toString());

        trainPassList.append(modelTrainNum);
    }
    return trainPassList;




}


QVector<ModelTrainPass> LogicTrainPass::GetList()
{
    QVector<ModelTrainPass> trainPassList;
    trainPassList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return trainPassList;
    }
    QString sql = CN("SELECT * FROM TrainPass");

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        ModelTrainPass modelTrainNum;
        modelTrainNum.TP_Id(query.value("TP_Id").toString());
        modelTrainNum.TN_Id(query.value("TN_Id").toString());
        modelTrainNum.TP_SStation(query.value("TP_SStation").toString());
        modelTrainNum.TP_SName(query.value("TP_SName").toString());
        modelTrainNum.TP_Distance(query.value("TP_Distance").toString());
        modelTrainNum.TP_Price(query.value("TP_Price").toString());

        trainPassList.append(modelTrainNum);
    }
    return trainPassList;

}

LogicTrainPass::~LogicTrainPass()
{

}
