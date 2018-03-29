#ifndef GUI_TICKETINFROM
#define GUI_TICKETINFROM

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



#include "Factory.h"

#include "Definition.h"
class GUITicketInfrom : public QDialog
{
	Q_OBJECT

public:
	GUITicketInfrom(QWidget *parent = 0);
	~GUITicketInfrom();
	void SetUserName(QString userName);
protected:
	void InitWidgets();//初始化窗体控件
	void InitWindowLayout();//初始化窗体布局
	void InitSignalSlot();//初始化信号和槽连接


private slots:
	void BtnAntiOrderClicked();
	void BtnBackToParent();

private:
	void GetUserTicket();
	QGroupBox *gBoxTicket;
	QGroupBox *gBoxTicketManage;
	QTableWidget *tabTicket;
	QPushButton *btnBack;
	QPushButton *btnAntiOrder;
	
	QHBoxLayout *hBLayoutTicket;
	QHBoxLayout *hBLayoutButtons;
	QVBoxLayout *vBLayoutMain;


	QString userName;



};

#endif // 
