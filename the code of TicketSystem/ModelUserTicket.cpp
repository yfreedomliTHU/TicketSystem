#include "ModelUserTicket.h"
ModelUserTicket::ModelUserTicket()
{


}
ModelUserTicket::~ModelUserTicket()
{


}
QString ModelUserTicket::UT_Id() const
{
	return uT_Id;
}
QString ModelUserTicket::U_Id() const
{
	return u_Id;
}
QString ModelUserTicket::TN_Id() const
{
	return tN_Id;
}

QString ModelUserTicket::UT_SStation() const
{
	return uT_SStation;
}
QString ModelUserTicket::UT_EStation() const
{
	return uT_EStation;
}
QString ModelUserTicket::UT_Type() const
{
	return uT_Type;
}
QString ModelUserTicket::UT_Price() const
{
	return uT_Price;
}
QString ModelUserTicket::UT_SeatNum() const
{
	return uT_SeatNum;
}

void ModelUserTicket::UT_Id(const QString & uT_Id)
{
	this->uT_Id = uT_Id;
}
void ModelUserTicket::U_Id(const QString & u_Id)
{
	this->u_Id = u_Id;
}
void ModelUserTicket::TN_Id(const QString & tN_Id)
{
	this->tN_Id = tN_Id;
}

void ModelUserTicket::UT_SStation(const QString & uT_SStation)
{
	this->uT_SStation = uT_SStation;
}

void ModelUserTicket::UT_EStation(const QString & uT_EStation)
{
	this->uT_EStation = uT_EStation;
}

void ModelUserTicket::UT_Type(const QString & uT_Type)
{
	this->uT_Type = uT_Type;
}

void ModelUserTicket::UT_Price(const QString & uT_Price)
{
	this->uT_Price = uT_Price;
}

void ModelUserTicket::UT_SeatNum(const QString & uT_SeatNum)
{
	this->uT_SeatNum = uT_SeatNum;
}
