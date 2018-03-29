#include "Factory.h"
Factory::Factory()
{
	//初始化数据库
	//装载SQLite驱动程序
	this->DB = QSqlDatabase::addDatabase("QSQLITE");
	this->DB.setDatabaseName(DATABASE_ADDRESS);//Definition文件
	if (!this->DB.open())
	{
		qDebug() << "Database connect faild!";
		
	}
	
	logicUser = new LogicUser(this->DB);
	logicTrain = new LogicTrain(this->DB);
	logicTrainNumber = new LogicTrainNumber(this->DB);
	logicTrainPass = new LogicTrainPass(this->DB);
	logicUserTicket = new LogicUserTicket(this->DB);
	logicTrainSeat = new LogicTrainSeat(this->DB);
}
void Factory::ConnectDataBase()
{
	if (!this->DB.isOpen())
	{
		this->DB.open();
	}
}
void Factory::CloseDataBase()
{
	if (this->DB.isOpen())
	{
		this->DB.close();
	}
}
Factory::~Factory()
{
	CloseDataBase();
}