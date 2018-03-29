#ifndef GUI_USER
#define GUI_USER
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QInputDialog>

#include "GUITicket.h"
#include "GUITicketInfrom.h"
#include "GUIOther.h"
#include "Factory.h"

#include "ModelUser.h"

#include "Definition.h"
class GUIUser :public QDialog
{
	Q_OBJECT
public:
	GUIUser(QWidget *parent = 0);
	~GUIUser();
	void SetUserInfrom (QString userName, QString passWord);
protected:
	void InitWidgets();//初始化窗体控件
	void InitWindowLayout();//初始化窗体布局
	void InitSignalSlot();//初始化信号和槽连接

	void showEvent(QShowEvent *);
private slots:
	void ShowParent();
	void ShowTicketDialog();
	void ShowTicketInfromDialog();
	void ShowOtherDialog();
	void BtnRechargeClicked();
	
private:
	QString userName;
	QString passWord;



	QGroupBox *gBoxUserInfrom;
	QGroupBox *gBoxUserFunction;


	QLabel *labelUserName;
	QLabel *labelName;
	QLabel *labelSex;
	QLabel *labelNum;
	QLabel *labelNumType;
	QLabel *labelAddtion;


	QPushButton *btnBuyTicket;
	QPushButton *btnBuyTicketForOther;
	//QPushButton *btnUpdateInfrom;
	QPushButton *btnTrainNumInfrom;
	QPushButton *btnRecharge;
	QPushButton *btnBack;

	QVBoxLayout *vBLayoutBasicInfrom;
	QGridLayout *gLayoutUserFunction;
	QHBoxLayout *hBLayoutMain;


	GUITicket *guiTicket;
	GUITicketInfrom *guiTicketInfrom;
	GUIOther *guiOther;
};



#endif