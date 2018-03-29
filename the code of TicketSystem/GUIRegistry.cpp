//注册界面
#include "GUIRegistry.h"
GUIRegistry::GUIRegistry(QWidget *parent/* =0 */) :QDialog(parent)
{
    InitWidgets();
    InitWindowLayout();
    InitSignalSlot();

}
void GUIRegistry::InitWidgets()
{
    gBoxRegInfrom =		new QGroupBox(CN("注册信息"),this);//注册信息
    gBoxRegManage=		new QGroupBox(CN("请确认注册"),this);//确定注册

    labelUserName=		new QLabel(CN("用户名"),this);//用户名
    labelPassWord=		new QLabel(CN("密码"),this);//密码
    labelName=			new QLabel(CN("姓名"),this);//姓名
    labelSex=			new QLabel(CN("性别"),this);//性别
    labelNumType =		new QLabel(CN("证件类型"),this);//证件类型(可选身份证,学生证和护照）
    labelNumber=		new QLabel(CN("证件号码"),this);//证件号码
    labelConnection=	new QLabel(CN("联系方式"),this); //联系方式
    labelAddtion=		new QLabel(CN("附加信息"),this);//附加信息

    lEditUserName =		new QLineEdit(this);
    lEditPassWord=		new QLineEdit(this);
    lEditName=			new QLineEdit(this);
    comBoxSex=			new QComboBox(this);
    lEditNumber=		new QLineEdit(this);
    comBoxNumType=		new QComboBox(this);
    lEditConnection=	new QLineEdit(this);
    lEditAddtion=		new QLineEdit(this);

     btnEnter=			new QPushButton(CN("注册"),this);//注册
     btnReset=			new QPushButton(CN("重置"),this);//重置录入信息
     btnBack =			new QPushButton(CN("返回"),this);

     vBLayoutMain=		new QVBoxLayout(this);//主要布局管理器
     gLayoutGroupInfrom=new QGridLayout(this);//注册信息 布局管理器
     hBLayoutGroupButtons=new QHBoxLayout(this);//确定注册 垂直布局管理器


     this->setWindowFlags(this->windowFlags() &~(Qt::WindowCloseButtonHint));//使注册界面的关闭按钮无效化

     //下拉列表 可选择身份证,学生证和护照
     comBoxNumType->addItem(CN("身份证"),CN("身份证"));
     comBoxNumType->addItem(CN("学生证"),CN("学生证"));
     comBoxNumType->addItem(CN("护照"),CN("护照"));
     //性别选择
     comBoxSex->addItem(CN("男"),CN("男"));
     comBoxSex->addItem(CN("女"), CN("女"));
     setWindowOpacity(0.9);//设置透明度为0.9

     //lEditPassWord->setEchoMode(QLineEdit::Password);注册时还是显示密码吧

}

void GUIRegistry::InitWindowLayout()
{
    gLayoutGroupInfrom->addWidget(labelUserName,0,0);
    gLayoutGroupInfrom->addWidget(lEditUserName, 0, 1);
    gLayoutGroupInfrom->addWidget(labelPassWord,1,0);
    gLayoutGroupInfrom->addWidget(lEditPassWord,1,1);
    gLayoutGroupInfrom->addWidget(labelName,2,0);
    gLayoutGroupInfrom->addWidget(lEditName,2,1);
    gLayoutGroupInfrom->addWidget(labelSex,3,0);
    gLayoutGroupInfrom->addWidget(comBoxSex,3,1);
    gLayoutGroupInfrom->addWidget(labelNumType,4,0);
    gLayoutGroupInfrom->addWidget(comBoxNumType, 4, 1);
    gLayoutGroupInfrom->addWidget(labelNumber,5,0);
    gLayoutGroupInfrom->addWidget(lEditNumber,5,1);
    gLayoutGroupInfrom->addWidget(labelConnection,6,0);
    gLayoutGroupInfrom->addWidget(lEditConnection,6,1);
    gLayoutGroupInfrom->addWidget(labelAddtion,7,0);
    gLayoutGroupInfrom->addWidget(lEditAddtion,7,1);

    gBoxRegInfrom->setLayout(gLayoutGroupInfrom);

    hBLayoutGroupButtons->addStretch(1);//加弹簧
    hBLayoutGroupButtons->addWidget(btnEnter);
    hBLayoutGroupButtons->addWidget(btnReset);
    hBLayoutGroupButtons->addWidget(btnBack);

    gBoxRegManage->setLayout(hBLayoutGroupButtons);

    vBLayoutMain->addWidget(gBoxRegInfrom);
    vBLayoutMain->addWidget(gBoxRegManage);


    this->setLayout(vBLayoutMain);

}
void GUIRegistry::InitSignalSlot()
{
    connect(this->btnBack, SIGNAL(clicked()), this, SLOT(ShowParent()));
    connect(this->btnEnter, SIGNAL(clicked()), this, SLOT(BtnRegistryClicked()));
    connect(this->btnReset,SIGNAL(clicked()),this,SLOT(BtnClearClicked()));
}
void GUIRegistry::BtnClearClicked()
{
    this->lEditPassWord->clear();
    this->lEditUserName->clear();
    this->lEditPassWord->clear();
    this->lEditName->clear();
    this->lEditNumber->clear();
    this->lEditConnection->clear();
    this->lEditAddtion->clear();

}
void GUIRegistry::BtnRegistryClicked()
{
    //其中联系方式 附加信息 可以不填

    QString u_Id = lEditUserName->text();
    QString u_Password = lEditPassWord->text();
    QString u_Type="ordinary";//默认注册用户为普通用户
    QString u_Name = lEditName->text();
    QString u_Sex = comBoxSex->currentText();
    QString u_Number = lEditNumber->text();
    QString u_NumType = comBoxNumType->currentText();
    QString u_Connection = lEditConnection->text();
    QString u_Addtion = lEditAddtion->text();
    QString u_Balance="0";//新注册的用户 余额都为0
    QString u_Image="";


    //实例化工厂类
    Factory factory;

    //实例化用户模型
    ModelUser modelUser;
    modelUser.U_Id(u_Id);
    modelUser.U_Password(u_Password);
    modelUser.U_Type(u_Type);
    modelUser.U_Name(u_Name);
    modelUser.U_Sex(u_Sex);
    modelUser.U_Number(u_Number);
    modelUser.U_NumType(u_NumType);
    modelUser.U_Connection(u_Connection);
    modelUser.U_Addtion(u_Addtion);
    modelUser.U_Balance(u_Balance);
    modelUser.U_Image(u_Image);

    //插入到数据库
    if (factory.logicUser->Insert(modelUser))
    {
        QMessageBox msgBox;
        msgBox.setModal(true); //模态窗体
        msgBox.setWindowTitle(CN("注意"));
        msgBox.setText(CN("注册成功，您当前的余额为0，请登录并充值"));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setWindowFlags(msgBox.windowFlags() &~(Qt::WindowCloseButtonHint));
        msgBox.exec();
        ShowParent();

    }
    else
    {
        bool updateStatus = true;
    }

}
void GUIRegistry::ShowParent()
{
    //将父指针向下转型为QDialog
    QDialog *parentDialog = qobject_cast<QDialog*>(this->parent());
    this->hide();

    lEditUserName->clear();
    lEditPassWord->clear();
    lEditName->clear();
    lEditNumber->clear();
    lEditConnection->clear();
    lEditAddtion->clear();

    parentDialog->show();
}
GUIRegistry::~GUIRegistry()
{

}
