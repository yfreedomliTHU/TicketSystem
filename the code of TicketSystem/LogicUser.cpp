#include "LogicUser.h"
LogicUser::LogicUser(QSqlDatabase &DB)
{
    this->DB = DB;
}
QString LogicUser::Login(QString userName, QString passWord)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return "NULL";
    }
    QString sql =
        CN("SELECT U_Type FROM User WHERE U_Id='%1' AND U_Password='%2'")
        .arg(userName)
        .arg(passWord)

        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    while (query.next())
    {
        return query.value("U_Type").toString();
    }
    return "NULL";



}

ModelUser LogicUser::GetUserInfrom(QString userName)
{
    ModelUser modelUser;//用户

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return modelUser;
    }
    QString sql =CN("SELECT * FROM User WHERE U_Id='%1'").arg(userName);
    QSqlQuery query;/*新建一个QSqlQuery对象query，使用其exec()方法读取执行要执行的SQL语句，执行成功后的query就表示查询的结果集，query指向一条一条的结果集，每一条结果集就是数据库中的一条记录，每一条记录的属性（也就是列）是从0开始的，使用query.value(n).toString()，来选择需要的信息并且转化为字符串，然后就可以将这个信息赋给一个字符串变量了，
                     其中，在判断结果集中是否有数据时使用query.next()方法，若返回不为假，则说明查询有结果。*/
    query.exec(sql);
    while (query.next())
     {
         modelUser.U_Id(query.value("U_Id").toString());
         modelUser.U_Password(query.value("U_Password").toString());
         modelUser.U_Type(query.value("U_Type").toString());
         modelUser.U_Name(query.value("U_Name").toString());
         modelUser.U_Sex(query.value("U_Sex").toString());
         modelUser.U_Number(query.value("U_Number").toString());
         modelUser.U_NumType(query.value("U_NumType").toString());
         modelUser.U_Connection(query.value("U_Connection").toString());
         modelUser.U_Addtion(query.value("U_Addtion").toString());
         modelUser.U_Balance(query.value("U_Balance").toString());
         modelUser.U_Image(query.value("U_Image").toString());
         break;
     }

     return modelUser;




}
bool LogicUser::Update(ModelUser &modelUser)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("UPDATE User SET U_Password='%1' , U_Type='%2' , U_Name='%3' , U_Sex='%4' , U_Number='%5' , U_NumType='%6' , U_Connection='%7',U_Addtion='%8',U_Balance='%9',U_Image='%10' WHERE U_Id='%11'")
        .arg(modelUser.U_Password())
        .arg(modelUser.U_Type())
        .arg(modelUser.U_Name())
        .arg(modelUser.U_Sex())
        .arg(modelUser.U_Number())
        .arg(modelUser.U_NumType())
        .arg(modelUser.U_Connection())
        .arg(modelUser.U_Addtion())
        .arg(modelUser.U_Balance())
        .arg(modelUser.U_Image())
        .arg(modelUser.U_Id())
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;



}
QVector<ModelUser> LogicUser::GetOtherUserInfrom(QString mainUser)
{
    QVector<ModelUser> otherUserList;
    otherUserList.clear();

    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return otherUserList;
    }
    QString sql = CN("SELECT * FROM User WHERE U_Id!='%1' AND U_Type='ordinary'")
        .arg(mainUser)
        ;

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        ModelUser modelUser;
        modelUser.U_Id(query.value("U_Id").toString());
        modelUser.U_Password(query.value("U_Password").toString());
        modelUser.U_Type(query.value("U_Type").toString());
        modelUser.U_Name(query.value("U_Name").toString());
        modelUser.U_Sex(query.value("U_Sex").toString());
        modelUser.U_Number(query.value("U_Number").toString());
        modelUser.U_NumType(query.value("U_NumType").toString());
        modelUser.U_Connection(query.value("U_Connection").toString());
        modelUser.U_Addtion(query.value("U_Addtion").toString());
        modelUser.U_Balance(query.value("U_Balance").toString());
        modelUser.U_Image(query.value("U_Image").toString());

        otherUserList.append(modelUser);
    }
    return otherUserList;
}
bool LogicUser::Insert(ModelUser &modelUser)
{
    //判断是否创建数据库连接
    if (!this->DB.isOpen())
    {
        return false;
    }
    QString sql =
        CN("INSERT INTO User VALUES('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11')")
        .arg(modelUser.U_Id())
        .arg(modelUser.U_Password())
        .arg(modelUser.U_Type())
        .arg(modelUser.U_Name())
        .arg(modelUser.U_Sex())
        .arg(modelUser.U_Number())
        .arg(modelUser.U_NumType())
        .arg(modelUser.U_Connection())
        .arg(modelUser.U_Addtion())
        .arg(modelUser.U_Balance())
        .arg(modelUser.U_Image())
        ;
    bool status = false;
    QSqlQuery query;
    status = query.exec(sql);
    return status;

}
LogicUser::~LogicUser()
{

}
