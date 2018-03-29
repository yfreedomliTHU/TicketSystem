#ifndef GUI_TICKET
#define GUI_TICKET
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>

#include <QtCore/QMap>
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <QtCore/QUuid>
#include <QtCore/QVariant>

#include "Factory.h"

#include "ModelUser.h"
#include "ModelUserTicket.h"
#include "ModelTrainNumber.h"
#include "ModelUserTicket.h"
#include "ModelTrainSeat.h"

#include "Definition.h"
class GUITicket :public QDialog
{
	Q_OBJECT
public:
	GUITicket(QWidget *parent = 0);
	~GUITicket();
	void SetCurrentUser(QString userName,QString orderUserName);
protected:
	void InitWidgets();//初始化窗体控件
	void InitWindowLayout();//初始化窗体布局
	void InitSignalSlot();//初始化信号和槽连接



private slots:
	void TableTrainNumRowClicked(int, int);
	void SelectSeatNum();
	void UserChoseEStation(int);
	void BtnOrderClicked();//购票
	void BtnBackClicked();
	void BtnSearchClicked();
private:
	void TrainNumList();//获得所有选择的车次
	void UserTrainNumList(QString currentUser);//当前用户购票列表


	QString userName;
	QString orderUserName;

	QVBoxLayout *vBLayoutMain;

	QGroupBox *gBoxSearch;//搜索区域

	QHBoxLayout *hBLayoutSearch;
	QLabel *labelSearch;//搜索
	QLineEdit *lEditSearch;
	QComboBox *comBoxSearch;
	QPushButton *btnSearch;
	QPushButton *btnBack;//返回上级

	QGroupBox *gBoxTrainNum;
	QHBoxLayout *hBLayoutTrainNum;
	QTableWidget *tabWTrainNum;

	QGroupBox *gBoxTrainSeats;
	QPushButton btnSeats[120]; //120个按钮 位置指针
	QGridLayout *gLayoutSeats;


	QGroupBox *gBoxTicketInfrom;
	QGridLayout *gLayoutTicketInfrom;
	QHBoxLayout *hBLayoutTicketInfrom;

	QLabel *labelTrainNumTime;//出发时间
	QLabel *labelTrainName;//列车编号
	QLabel *labelTrainSeat;//座位号

	QLabel *labelTrainNumId;//车次
	QLabel *labelTrainSStation;//起点站
	QLabel *labelTrainEStation;//终点站

	QLineEdit *lEditTrainNumTime;
	QLineEdit *lEditTrainName;
	QLineEdit *lEditTrainSeat; 

	QLineEdit *lEditTrainNumId;
	QLineEdit *lEditTrainSStation;
	QComboBox *comBoxTrainEStation; 

	QPushButton *btnOrder;//结账
	

	QString currentTrainType;//当前车型
	QString currentTrainSeat;//当前车厢类型
	QString currentSeatNum;//当前车座号

};

#endif