#ifndef MODEL_USER
#define MODEL_USER
#include <QtCore/QString>
#include <QtCore/QObject>

class ModelUser
{
	
public:
	ModelUser();
	~ModelUser();
	QString U_Id() const;
	QString U_Password() const;
	QString U_Type() const;
	QString U_Name() const;
	QString U_Sex() const;
	QString U_Number() const;
	QString U_NumType() const;
	QString U_Connection() const;
	QString U_Addtion() const;
	QString U_Balance() const;
	QString U_Image() const;

	void U_Id(const QString & u_Id);
	void U_Password(const QString & u_Password);
	void U_Type(const QString & u_Type);
	void U_Name(const QString & u_Name);
	void U_Sex(const QString & u_Sex);
	void U_Number(const QString & u_Number);
	void U_NumType(const QString & u_NumType);
	void U_Connection(const QString & u_Connection);
	void U_Addtion(const QString & u_Addtion);
	void U_Balance(const QString & u_Balance);
	void U_Image(const QString & u_Image);

private:
	QString u_Id;
	QString u_Password;
	QString u_Type;
	QString u_Name;
	QString u_Sex;
	QString u_Number;
	QString u_NumType;
	QString u_Connection;
	QString u_Addtion;
	QString u_Balance;
	QString u_Image;

};


#endif