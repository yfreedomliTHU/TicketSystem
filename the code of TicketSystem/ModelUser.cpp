#include "ModelUser.h"
ModelUser::ModelUser()
{

}
ModelUser::~ModelUser()
{


}
QString ModelUser::U_Id() const
{
	return this->u_Id;
}
QString ModelUser::U_Password() const
{
	return this->u_Password;
}
QString ModelUser::U_Balance() const
{
	return this->u_Balance;
}
QString ModelUser::U_Type() const
{
	return this->u_Type;
}
QString ModelUser::U_Name() const
{
	return this->u_Name;
}
QString ModelUser::U_Sex() const
{
	return this->u_Sex;
}
QString ModelUser::U_Number() const
{
	return this->u_Number;
}
QString ModelUser::U_NumType() const
{
	return this->u_NumType;
}
QString ModelUser::U_Connection() const
{
	return this->u_Connection;
}
QString ModelUser::U_Addtion() const
{
	return this->u_Addtion;
}
QString ModelUser::	U_Image() const
{
	return this->u_Image;
}

void ModelUser::U_Id(const QString & u_Id)
{
	this->u_Id = u_Id;
}
void ModelUser::U_Password(const QString & u_Password)
{
	this->u_Password = u_Password;
}
void ModelUser::U_Type(const QString & u_Type)
{
	this->u_Type = u_Type;
}
void ModelUser::U_Name(const QString & u_Name)
{
	this->u_Name = u_Name;
}
void ModelUser::U_Sex(const QString & u_Sex)
{
	this->u_Sex = u_Sex;
}
void ModelUser::U_Number(const QString & u_Number)
{
	this->u_Number = u_Number;
}
void ModelUser::U_NumType(const QString & u_NumType)
{
	this->u_NumType = u_NumType;
}
void ModelUser::U_Connection(const QString & u_Connection)
{
	this->u_Connection = u_Connection;
}
void ModelUser::U_Addtion(const QString & u_Addtion)
{
	this->u_Addtion = u_Addtion;
}
void ModelUser::U_Balance(const QString & u_Balance)
{
	this->u_Balance = u_Balance;
}
void ModelUser::U_Image(const QString & u_Image)
{
	this->u_Image = u_Image;
}