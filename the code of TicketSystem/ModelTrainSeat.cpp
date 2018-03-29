#include "ModelTrainSeat.h"
ModelTrainSeat::ModelTrainSeat()
{


}
ModelTrainSeat::~ModelTrainSeat()
{


}
QString ModelTrainSeat::TS_Id() const
{
	return this->tS_Id;
}
QString ModelTrainSeat::T_Id() const
{
	return this->t_Id;
}
QString ModelTrainSeat::TS_SellNum() const
{
	return this->tS_SellNum;
}
void ModelTrainSeat::TS_Id(const QString & tS_Id)
{
	this->tS_Id = tS_Id;
}
void ModelTrainSeat::T_Id(const QString & t_Id)
{
	this->t_Id = t_Id;
}
void ModelTrainSeat::TS_SellNum(const QString & tS_SellNum)
{
	this->tS_SellNum = tS_SellNum;
}