#include "ModelTrainPass.h"
ModelTrainPass::ModelTrainPass()
{

}

QString ModelTrainPass::TP_Id() const
{
	return this->tP_Id;
}
QString ModelTrainPass::TN_Id() const
{
	return this->tN_Id;
}
QString ModelTrainPass::TP_SStation() const
{
	return this->tP_SStation;
}
QString ModelTrainPass::TP_SName() const
{
	return this->tP_SName;
}
QString ModelTrainPass::TP_Distance() const
{
	return this->tP_Distance;
}
QString ModelTrainPass::TP_Price() const
{
	return this->tP_Price;
}
void ModelTrainPass::TP_Id(const QString & tP_Id)
{
	this->tP_Id = tP_Id; 
}
void ModelTrainPass::TN_Id(const QString & tN_Id)
{
	this->tN_Id = tN_Id;
}
void ModelTrainPass::TP_SStation(const QString & tP_SStation)
{
	this->tP_SStation = tP_SStation;
}
void ModelTrainPass::TP_SName(const QString & tP_SName)
{
	this->tP_SName = tP_SName;
}
void ModelTrainPass::TP_Distance(const QString & tP_Distance)
{
	this->tP_Distance = tP_Distance;
}
void ModelTrainPass::TP_Price(const QString & tP_Price)
{
	this->tP_Price = tP_Price;
}
ModelTrainPass::~ModelTrainPass()
{


}