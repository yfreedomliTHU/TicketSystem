#ifndef MODEL_TRAINPASS
#define MODEL_TRAINPASS
#include <QtCore/QString>
#include <QtCore/QObject>

class ModelTrainPass 
{
	
public:
	ModelTrainPass();
	~ModelTrainPass();
	QString TP_Id() const;
	QString TN_Id() const;
	QString TP_SStation() const;
	QString TP_SName() const;
	QString TP_Distance() const;
	QString TP_Price() const;

	void TP_Id(const QString & tP_Id) ;
	void TN_Id(const QString & tN_Id) ;
	void TP_SStation(const QString & tP_SStation) ;
	void TP_SName(const QString & tP_SName) ;
	void TP_Distance(const QString & tP_Distance) ;
	void TP_Price(const QString & tP_Price) ;

private:
	QString tP_Id;
	QString tN_Id;
	QString tP_SStation;
	QString tP_SName;
	QString tP_Distance;
	QString tP_Price;


};


#endif