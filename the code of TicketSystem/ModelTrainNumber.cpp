#include "ModelTrainNumber.h"
ModelTrainNumber::ModelTrainNumber()
{

}
QString ModelTrainNumber::TN_Id() const
{
	return this->tN_Id;
}
QString ModelTrainNumber::TN_Distance()const
{
	return this->tN_Distance;
}
QString ModelTrainNumber::T_Id() const
{
	return this->t_Id;
}
QString ModelTrainNumber::TN_SStation() const
{
	return this->tN_SStation;
}
QString ModelTrainNumber::TN_EStation() const
{
	return this->tN_EStation;
}

QString ModelTrainNumber::TN_STime() const
{
	return this->tN_STime;
}
QString ModelTrainNumber::TN_ETime() const
{
	return this->tN_ETime;
}
QString ModelTrainNumber::TN_TicketNum() const
{
	return this->tN_TicketNum;
}
QString ModelTrainNumber::TN_TicketPrice() const
{
	return this->tN_TicketPrice;
}
void ModelTrainNumber::TN_Id(const QString & tN_Id)
{
	this->tN_Id = tN_Id;
}
void ModelTrainNumber::T_Id(const QString & t_Id)
{
	this->t_Id = t_Id;
}
void ModelTrainNumber::TN_SStation(const QString & tN_SStation)
{
	this->tN_SStation = tN_SStation;
}
void ModelTrainNumber::TN_EStation(const QString & tN_EStation)
{
	this->tN_EStation = tN_EStation;
}
void ModelTrainNumber::TN_STime(const QString & tN_STime)
{
	this->tN_STime = tN_STime;
}
void ModelTrainNumber::TN_ETime(const QString & tN_ETime)
{
	this->tN_ETime = tN_ETime;
}
void ModelTrainNumber::TN_TicketNum(const QString & tN_TicketNum)
{
	this->tN_TicketNum = tN_TicketNum;
}
void ModelTrainNumber::TN_Distance(const QString & tN_Distance)
{
	this->tN_Distance=tN_Distance;
}
void ModelTrainNumber::TN_TicketPrice(const QString & tN_TicketPrice)
{
	this->tN_TicketPrice = tN_TicketPrice;
}

ModelTrainNumber::~ModelTrainNumber()
{


}