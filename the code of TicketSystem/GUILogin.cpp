//登录界面，可实现普通用户和管理员登录，跳转至相应的子界面，以及通过注册按钮打开注册界面

#include "GUILogin.h"
GUILogin::GUILogin(QWidget *parent) : QDialog(parent)
{
    InitWidgets();
    InitWindowLayout();
    InitSignalSlot();

}

void GUILogin::InitWidgets()
{

     gBoxLogin=			new QGroupBox(CN("欢迎使用火车订票系统"),this); //登录区域
     labelUserName =	new QLabel(CN("用户名:"),this);//用户名标签
     labelPassWord=		new QLabel(CN("密  码:"),this);//密码标签
     lEditUserName =	new QLineEdit(this);//用户名输入框
     lEditPassWord=		new QLineEdit(this);//密码输入框
     btnLogin=			new QPushButton(CN("登陆"),this);//登陆按钮
     btnReset=			new QPushButton(CN("重置"),this);//重置按钮
     btnRegistry=		new QPushButton(CN("注册"),this);//注册按钮

    //布局管理器
     vBLayoutMain=		new QVBoxLayout(this);//主要布局管理器
     hBLayoutButtons=	new QHBoxLayout(this);//按钮布局管理器
     vBLayoutGroup=		new QVBoxLayout(this);//注册信息布局管理器
     gLayoutInfrom=		new QGridLayout(this);//登陆信息布局管理器

     //子窗体
     guiRegistry = new GUIRegistry(this);
     guiAdmin = new GUIAdmin("Admin",this);
     guiUser = new GUIUser(this);

     //密码框，输入密码不可见
     lEditPassWord->setEchoMode(QLineEdit::Password);

     //设置背景颜色及界面大小,效果调试
     //this->setStyleSheet("background-color:rgb(156,192,237)");
     setStyleSheet ("background-color: rgb(156,192,237);color: rgb(80,80,80);");//设置背景颜色及字体对比色
     this->resize(400, 225);//设置大小
     //setAttribute(Qt::WA_TranslucentBackground,true);
     setWindowOpacity(0.9);//设置透明度为0.9


}

void GUILogin::InitWindowLayout()
{
    //登陆
    gLayoutInfrom->addWidget(labelUserName, 0, 0);
    gLayoutInfrom->addWidget(lEditUserName, 0, 1);
    gLayoutInfrom->addWidget(labelPassWord, 1, 0);
    gLayoutInfrom->addWidget(lEditPassWord, 1, 1);

    //按钮
    //hBLayoutButtons->addStretch(1);//添加一个弹簧
    hBLayoutButtons->addWidget(btnLogin);
    hBLayoutButtons->addWidget(btnReset);
    hBLayoutButtons->addWidget(btnRegistry);

    //登陆信息
    vBLayoutGroup->addLayout(gLayoutInfrom);
    vBLayoutGroup->addLayout(hBLayoutButtons);

    //设置登陆信息区域
    gBoxLogin->setLayout(vBLayoutGroup);

    //设置主要布局管理器
    vBLayoutMain->addWidget(gBoxLogin);

    this->setLayout(vBLayoutMain);


}
void GUILogin::InitSignalSlot()
{
    connect(this->btnRegistry, SIGNAL(clicked()), this, SLOT(ShowRegistry()));
    connect(this->btnLogin, SIGNAL(clicked()), this, SLOT(ShowLogin()));
    connect(this->btnReset, SIGNAL(clicked()), this, SLOT(BtnClearClicked()));

}
void GUILogin::BtnClearClicked()
{
    this->lEditPassWord->clear();
    this->lEditUserName->clear();

}
void GUILogin::ShowLogin()
{
    Factory factory;
    QString userName = this->lEditUserName->text();
    QString passWord = this->lEditPassWord->text();
    if (factory.logicUser->Login(userName,passWord)=="admin")
    {
        guiAdmin->show();
        this->hide();
        return;
    }
    if (factory.logicUser->Login(userName, passWord) == "ordinary")
    {
        guiUser->SetUserInfrom(userName, passWord);

        guiUser->show();
        this->hide();
    }
    else{
        //弹出警告消息框
        QMessageBox::warning(this, CN("温馨提示"),CN("对不起，您还未注册，请注册后登陆"),QMessageBox::Ok);
    }
}
void GUILogin::ShowRegistry()
{
    this->hide();
    guiRegistry->show();
}

GUILogin::~GUILogin()
{

}
