#ifndef MODEL_USERTICKET
#define MODEL_USERTICKET
#include <QtCore/QString>
#include <QtCore/QObject>

class ModelUserTicket
{
	
public:
	ModelUserTicket();
	~ModelUserTicket();
	QString UT_Id() const;
	QString U_Id() const;
	QString TN_Id() const;


	QString UT_SStation() const;
	QString UT_EStation() const;
	QString UT_Type() const;
	QString UT_Price() const;
	QString UT_SeatNum() const;

	void UT_Id(const QString & uT_Id);
	void U_Id(const QString & u_Id);
	void TN_Id(const QString & tN_Id);
	void UT_SStation(const QString & uT_SStation);
	void UT_EStation(const QString & uT_EStation);
	void UT_Type(const QString & uT_Type);
	void UT_Price(const QString & uT_Price);
	void UT_SeatNum(const QString & uT_SeatNum);

private:

	QString uT_Id;
	QString u_Id;
	QString tN_Id;
	QString uT_SStation;
	QString uT_EStation;
	QString uT_Type;
	QString uT_Price;
	QString uT_SeatNum;

};


#endif