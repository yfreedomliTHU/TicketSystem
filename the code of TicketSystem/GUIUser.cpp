//用户信息界面
#include "GUIUser.h"
GUIUser::GUIUser(QWidget *parent /* = 0 */) :QDialog(parent)
{


    InitWidgets();
    InitWindowLayout();
    InitSignalSlot();
}
void GUIUser::InitWidgets()
{

     gBoxUserInfrom=new QGroupBox(CN("个人信息"),this);
     gBoxUserFunction=new QGroupBox(CN("票务功能"),this);

     labelUserName = new QLabel(CN("用户名:"), this);
     labelName = new QLabel(CN("姓名:"), this);
     labelSex = new QLabel(CN("性别:"), this);
     labelNum = new QLabel(CN("证件号码:"), this);
     labelNumType = new QLabel(CN("证件类型"), this);
     labelAddtion = new QLabel(CN("账户余额"), this);


     btnBuyTicket = new QPushButton(CN("个人购票"), this);
     btnBuyTicketForOther = new QPushButton(CN("帮人购票"), this);
    // btnUpdateInfrom = new QPushButton(CN("修改信息"), this);
     btnTrainNumInfrom = new QPushButton(CN("已购车票"), this);
     btnRecharge = new QPushButton(CN("账户充值"), this);
     btnBack = new QPushButton(CN("返回上级"), this);

      hBLayoutMain = new QHBoxLayout(this);
      vBLayoutBasicInfrom = new QVBoxLayout();
      gLayoutUserFunction=new QGridLayout();

      //子窗体
      guiTicket = new GUITicket(this);
      guiTicketInfrom = new GUITicketInfrom(this);
      guiOther = new GUIOther(this);

      setWindowOpacity(0.9);//设置透明度为0.9

      //按钮自动拓展
      btnBuyTicket->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
      btnBuyTicketForOther->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

     // btnUpdateInfrom->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
      btnTrainNumInfrom->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

      btnRecharge->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
      btnBack->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
}
void GUIUser::InitWindowLayout()
{
    vBLayoutBasicInfrom->addWidget(labelUserName);
    vBLayoutBasicInfrom->addWidget(labelName);
    vBLayoutBasicInfrom->addWidget(labelSex);
    vBLayoutBasicInfrom->addWidget(labelNum);
    vBLayoutBasicInfrom->addWidget(labelNumType);
    vBLayoutBasicInfrom->addWidget(labelAddtion);

    gBoxUserInfrom->setLayout(vBLayoutBasicInfrom);

    gLayoutUserFunction->addWidget(btnBuyTicket,0,0);
    gLayoutUserFunction->addWidget(btnBuyTicketForOther,0,1);

    //gLayoutUserFunction->addWidget(btnUpdateInfrom,1,0);
    gLayoutUserFunction->addWidget(btnTrainNumInfrom,1,0);

    gLayoutUserFunction->addWidget(btnRecharge,1,1);

    gLayoutUserFunction->addWidget(btnBack,2,0,1,2);

    gBoxUserFunction->setLayout(gLayoutUserFunction);

    hBLayoutMain->addWidget(gBoxUserInfrom);
    hBLayoutMain->addWidget(gBoxUserFunction);

    this->setLayout(hBLayoutMain);
}
void GUIUser::InitSignalSlot()
{
    connect(this->btnBuyTicketForOther, SIGNAL(clicked()), this, SLOT(ShowOtherDialog()));
    connect(this->btnBack, SIGNAL(clicked()), this, SLOT(ShowParent()));
    connect(this->btnBuyTicket, SIGNAL(clicked()), this, SLOT(ShowTicketDialog()));
    connect(this->btnTrainNumInfrom, SIGNAL(clicked()), this, SLOT(ShowTicketInfromDialog()));

    connect(this->btnRecharge, SIGNAL(clicked()), this, SLOT(BtnRechargeClicked()));

}
void GUIUser::ShowOtherDialog()
{
    guiOther->SetMainUser(this->userName);
    this->guiOther->show();
    this->hide();


}
void GUIUser::ShowTicketInfromDialog()
{
    guiTicketInfrom->SetUserName(this->userName);
    this->guiTicketInfrom->show();
    this->hide();

}
void GUIUser::BtnRechargeClicked()
{
    int recharge=QInputDialog::getInt(this, CN("充值"),CN("请输入您要充值的金额O(∩_∩)O~"),0,0,100000,1);

    Factory factory;
    ModelUser modelUser;
    modelUser = factory.logicUser->GetUserInfrom(userName);

    QString currentMoney = QString("%1").arg(modelUser.U_Balance().toInt() + recharge);
    modelUser.U_Balance(currentMoney);
    factory.logicUser->Update(modelUser);

    labelUserName->setText(CN("用户名:") + modelUser.U_Id());
    labelName->setText(CN("姓名:") + modelUser.U_Name());
    labelSex->setText(CN("性别:") + modelUser.U_Sex());
    labelNum->setText(CN("证件号码:") + modelUser.U_Number());
    labelNumType->setText(CN("证件类型:") + modelUser.U_NumType());
    labelAddtion->setText(CN("账户余额:") + modelUser.U_Balance());


}
void GUIUser::ShowTicketDialog()
{
    this->guiTicket->SetCurrentUser(this->userName,CN("NULL"));
    this->guiTicket->show();
    this->hide();

}
void GUIUser::showEvent(QShowEvent *e)
{
    if (!this->userName.isEmpty())
    {
        Factory factory;
        ModelUser modelUser;
        modelUser = factory.logicUser->GetUserInfrom(userName);


        labelUserName->setText(CN("用户名:") + modelUser.U_Id());
        labelName->setText(CN("姓名:") + modelUser.U_Name());
        labelSex->setText(CN("性别:") + modelUser.U_Sex());
        labelNum->setText(CN("证件号码:") + modelUser.U_Number());
        labelNumType->setText(CN("证件类型:") + modelUser.U_NumType());
        labelAddtion->setText(CN("账户余额:") + modelUser.U_Balance());

    }

    QDialog::showEvent(e);
}

void GUIUser::ShowParent()
{


    QDialog *parentDialog = qobject_cast<QDialog*>(this->parent());
    this->hide();


    parentDialog->show();
}
void GUIUser::SetUserInfrom(QString userName, QString passWord)
{
    this->userName = userName;
    this->passWord = passWord;

    Factory factory;
    ModelUser modelUser;
    modelUser = factory.logicUser->GetUserInfrom(userName);


    labelUserName->setText(CN("用户名:") + modelUser.U_Id());
    labelName->setText(CN("姓名:") + modelUser.U_Name());
    labelSex->setText(CN("性别:")+modelUser.U_Sex());
    labelNum->setText(CN("证件号码:") + modelUser.U_Number());
    labelNumType->setText(CN("证件类型:") + modelUser.U_NumType());
    labelAddtion->setText(CN("账户余额:")+modelUser.U_Balance());

}
GUIUser::~GUIUser(){}
