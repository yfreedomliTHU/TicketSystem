#ifndef GUI_ADMIN
#define GUI_ADMIN
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>

#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <QtCore/QVector>
#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtCore/QUuid>

#include <QtCore/QRegExp>

//model
#include "ModelTrain.h"
#include "ModelTrainPass.h"
#include "ModelTrainNumber.h"

#include "Factory.h"

#include "Definition.h"

class GUIAdmin :public QDialog
{
	Q_OBJECT
public:
	GUIAdmin(QString userName,QWidget *parent=0);
	~GUIAdmin();


protected:
	void InitWidgets();
	void InitWindowLayout();
	void InitSignalSlot();


private slots:
	void AddTrainClicked();
	void DeleteTrainClicked();
	void UpdateTrainComBox();
	
	void AddTrainNumClicked();
	void UpdateTrainNumClicked();
	void DeleteTrainNumClicked();

	void AddTrainPassClicked();
	void DeleteTrainPassClicked();

	void ShowParent();

	//表
	void TabTrainNumClicked(int ,int);



private:
	void GetTrainList();
	void GetTrainNumList();
	void GetTrainPassList(QString TN_Id);


	//管理员账号
	QString userName;

	//全体布局
	QVBoxLayout *vBLayoutMain;
	QHBoxLayout *hBLayoutCentral;//中心信息

	//车次信息
	QGroupBox *gBoxTrainNum;//区域
	QTableWidget *tabWTrainNum;//车次表
	QHBoxLayout *hBLauyout;//车次布局管理器
	
	/*//座位信息
	QGroupBox *gBoxTrainSeat;//区域
	QPushButton *btnSeats;//座位指针序列
	QGridLayout *gLayoutSeats;//座位网格布局管理器
	*/
	//经过站点
	QGroupBox *gBoxTrainPass;
	QHBoxLayout *hBLayoutTrainPass;//经过站点区域主布局管理器
	QGridLayout *gLayoutTrainPassInfrom;//经过站点信息网格布局管理器
	QVBoxLayout *vBLayoutTrainPassManage;//经过站点信息管理布局管理器


	QTableWidget *tabTrainPass;//经过的站点表
	QLabel *labelTrainPassName;//经过的站点名称标签
	QLabel *labelTrainPassDistance;//经过的站点的里程标签
	QLabel *labelTrainPassPrice;//到该站点的价格标签

	QLineEdit *lEditTrainPassName;//经过的站点名称输入框
	QLineEdit *lEditTrainPassDistance;//经过的站点的里程输入框
	QLineEdit *lEditTrainPassPrice;//到该站点的价格输入框

	QPushButton *btnTrainPassAdd;//增加新的站点
	QPushButton *btnTrainPassDelete;//删除当前选中的站点
	


	//火车信息
	QGroupBox  *gBoxTrainInfrom;//区域
	QHBoxLayout *hBLayoutTrainInfromMain;//火车信息主布局管理器
	QGridLayout *gLayoutTrainInfromUpdateTop;//火车信心修改上方布局管理器
	QVBoxLayout *vBLayoutTrainInfromUpdate;// 火车信心整体修改布局管理器

	QTableWidget *tabTrainInfrom;//当前火车公司的所有火车一览表
	QLabel *labelTrainInfromId;
	QLabel *labelTrainInfromType;//火车类型：动车 特快 普快
	QLabel *labelTrainInfromSeatType;//火车座位类型

	QLineEdit *lEdiTrainInfromId;
	QComboBox *comBoxTrainInfromType;
	QComboBox *comBoxTrainInfromSeatType;


	QPushButton *btnTrainInfromAdd;//删除列车
	QPushButton *btnTrainInfromDelete;//增加列车

	/*
	//乘客一览
	QGroupBox *gBoxTrainGuest;
	QTableWidget *tabWTrainGuest;//乘客一览表
	QHBoxLayout *hBLayoutTrainGuest;//乘客主要布局管理器
	*/

	// 车次信息更新
	QGroupBox *gBoxTrainNumUpdate;
	QGridLayout *gLayoutTrainNumInfrom;
	QHBoxLayout *hBLayoutTrainNumButtons;
	QVBoxLayout *vBLayoutTrainNumMain;

	QLabel *labelTrainNumUpdateId;//车次编号
	QLabel *labelTrainNumUpdateTrain;//车次列车
	QLabel *labelTrainNumUpdateTicket;//总票数
	QLabel *labelTrainNumUpdatePrice; //票价

	QLabel *labelTrainNumUpdateStart;//起始站点
	QLabel *labelTrainNumUpdateEnd;//结束站点
	QLabel *labelTrainNumUpdateSTime;//发车时间
	QLabel *labelTrainNumUpdateETime;//预计到达
	QLabel *labelTrainNumUpdateDistance;//总里程

	QLineEdit *lEditTrainNumUpdateId;
	QComboBox *comBoxNumUpdateTrain;
	QLineEdit *lEditTrainNumUpdateTicket;
	QLineEdit *lEditTrainNumUpdatePrice;

	QLineEdit *lEditTrainNumUpdateStart;
	QLineEdit *lEditTrainNumUpdateEnd;

	QDateTimeEdit *timeEditTrainNumSTime;
	QDateTimeEdit *timeEditTrainNumETime;

	QLineEdit *lEditTrainNumDistance;

	QPushButton *btnUpdate; 
	QPushButton *btnDelete;
	QPushButton *btnAdd;
	QPushButton *btnBack;



};

#endif