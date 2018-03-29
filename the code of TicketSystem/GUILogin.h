#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>


#include "GUIRegistry.h"
#include "GUIAdmin.h"
#include "GUIUser.h"
#include "Factory.h"

#include "Definition.h"
class GUILogin : public QDialog
{
	Q_OBJECT

public:
	GUILogin(QWidget *parent = 0);
	~GUILogin();
protected:
	void InitWidgets();//初始化窗体控件
	void InitWindowLayout();//初始化窗体布局
	void InitSignalSlot();//初始化信号和槽连接

private slots:
	void ShowRegistry();
	void ShowLogin();
	void BtnClearClicked();


private:

	//窗体控件
	QGroupBox *gBoxLogin; //登录区域
	QLabel *labelUserName;//用户名标签
	QLabel *labelPassWord;//密码标签
	QLineEdit *lEditUserName;//用户名输入框
	QLineEdit *lEditPassWord;//密码输入框
	QPushButton *btnLogin;//登陆按钮
	QPushButton *btnReset;//重置按钮
	QPushButton *btnRegistry;//注册按钮

	//布局管理器
	QVBoxLayout *vBLayoutMain;//主要布局管理器
	QHBoxLayout *hBLayoutButtons;//按钮布局管理器
	QVBoxLayout *vBLayoutGroup;//注册信息布局管理器
	QGridLayout *gLayoutInfrom;//登陆信息布局管理器

	//子窗体
	GUIRegistry *guiRegistry;
	GUIAdmin *guiAdmin;
	GUIUser *guiUser;
		
	
};

#endif // LOGIN_H
