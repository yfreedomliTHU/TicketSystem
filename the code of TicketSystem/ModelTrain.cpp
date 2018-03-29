#include "ModelTrain.h"
ModelTrain::ModelTrain()
{

}
QString ModelTrain::T_Id() const
{
	return this->t_Id;
}
QString ModelTrain::T_Type() const
{
	return this->t_Type;
}
QString ModelTrain::T_SeatType() const
{
	return this->t_SeatType;
}
void ModelTrain::T_Id(const QString & t_Id)
{
	this->t_Id = t_Id;
}
void ModelTrain::T_SeatType(const QString & t_SeatType)
{
	this->t_SeatType = t_SeatType;
}
void ModelTrain::T_Type(const QString & t_Type)
{
	this->t_Type = t_Type;
}
ModelTrain::~ModelTrain()
{



}