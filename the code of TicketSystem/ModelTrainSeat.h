#ifndef MODEL_TRAINSEAT
#define MODEL_TRAINSEAT
#include <QtCore/QString>
#include <QtCore/QObject>

class ModelTrainSeat 
{
	
public:
	ModelTrainSeat();
	~ModelTrainSeat();
	QString TS_Id() const;
	QString T_Id() const;
	QString TS_SellNum() const;
	void TS_Id(const QString & tS_Id);
	void T_Id(const QString & t_Id);
	void TS_SellNum(const QString & tS_SellNum);

private:
	QString tS_Id;
	QString t_Id;
	QString tS_SellNum;

};


#endif