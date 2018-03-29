#ifndef GUI_OTHER
#define GUI_OTHER

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

#include "GUITicket.h"

#include "Factory.h"

#include "Definition.h"
class GUIOther : public QDialog
{
	Q_OBJECT

public:
	GUIOther(QWidget *parent = 0);
	~GUIOther();
	void SetMainUser(QString userName);
protected:
	void InitWidgets();//初始化窗体控件
	void InitWindowLayout();//初始化窗体布局
	void InitSignalSlot();//初始化信号和槽连接

private slots:
	void ShowParent();
	void ShowOrder();

private:
	void GetUserList();

	QGroupBox *gBoxOther;
	QTableWidget *tabUserList;
	QPushButton *btnBack;
	QPushButton *btnOrder;

	QVBoxLayout *vBLayoutButtons;
	QHBoxLayout *hBLayoutMain;
	QHBoxLayout *hBLayoutAll;

	QString mainUser;

	GUITicket *guiTicket;
};

#endif 
