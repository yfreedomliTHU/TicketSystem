#ifndef MODEL_TRAINNUMBER
#define MODEL_TRAINNUMBER
#include <QtCore/QString>
#include <QtCore/QObject>

class ModelTrainNumber
{
	
public:
	ModelTrainNumber();
	~ModelTrainNumber();

	QString TN_Id() const;
	QString T_Id() const;
	QString TN_SStation() const;
	QString TN_EStation() const;
	QString TN_STime() const;
	QString TN_ETime() const;
	QString TN_TicketNum() const;
	QString TN_TicketPrice() const;
	QString TN_Distance() const;

	void TN_Id(const QString & tN_Id);
	void T_Id(const QString & t_Id);
	void TN_SStation(const QString & tN_SStation);
	void TN_EStation(const QString & tN_EStation);
	void TN_STime(const QString & tN_STime);
	void TN_ETime(const QString & tN_ETime);
	void TN_TicketNum(const QString & tN_TicketNum);
	void TN_TicketPrice(const QString & tN_TicketPrice);
	void TN_Distance(const QString & tN_Distance);

private:
	QString tN_Id;
	QString t_Id;
	QString tN_SStation;
	QString tN_EStation;
	QString tN_STime;
	QString tN_ETime;
	QString tN_TicketNum;
	QString tN_TicketPrice;
	QString tN_Distance;

};


#endif