#ifndef GUI_REGISTRY
#define GUI_REGISTRY
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


#include <QtCore/QRegExp>
#include "Factory.h"

#include "ModelUser.h"

#include "Definition.h"
class GUIRegistry :public QDialog
{
    Q_OBJECT
public:
    GUIRegistry(QWidget *parent=0);
    ~GUIRegistry();

protected:
    void InitWidgets();//初始化窗体控件
    void InitWindowLayout();//初始化窗体布局
    void InitSignalSlot();//初始化信号和槽连接

private slots:
    void ShowParent();
    void BtnRegistryClicked();
    void BtnClearClicked();

private:
    QGroupBox *gBoxRegInfrom;//注册信息
    QGroupBox *gBoxRegManage;//注册管理

    QLabel *labelUserName;//用户名
    QLabel *labelPassWord;//密码
    QLabel *labelName;//姓名
    QLabel *labelSex;//性别
    QLabel *labelNumber;//证件号码
    QLabel *labelNumType;//证件类型
    QLabel *labelConnection; //联系方式
    QLabel *labelAddtion;//附加信息

    QLineEdit *lEditUserName;
    QLineEdit *lEditPassWord;
    QLineEdit *lEditName;
    QComboBox *comBoxSex;
    QLineEdit *lEditNumber;
    QComboBox *comBoxNumType;
    QLineEdit *lEditConnection;
    QLineEdit *lEditAddtion;

    QPushButton *btnEnter;//注册
    QPushButton *btnReset;//重置
    QPushButton *btnBack;//返回上级

    QVBoxLayout *vBLayoutMain;//主要布局管理器
    QGridLayout *gLayoutGroupInfrom;//注册信息 布局管理器
    QHBoxLayout *hBLayoutGroupButtons;//确认注册 布局管理器

};

#endif
