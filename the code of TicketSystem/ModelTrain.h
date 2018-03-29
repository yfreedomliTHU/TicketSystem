#ifndef MODEL_TRAIN
#define MODEL_TRAIN
#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtCore/QObject>

class ModelTrain
{
	
public:
	ModelTrain();
	~ModelTrain();
	QString T_Id() const;
	QString T_Type() const;
	QString T_SeatType() const;
	void T_Id(const QString & t_Id);
	void T_Type(const QString & t_Type);
	void T_SeatType(const QString & t_SeatType);

private:
	QString t_Id;
	QString t_Type;
	QString t_SeatType;

};


#endif