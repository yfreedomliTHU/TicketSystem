//其他乘客信息界面，可供选择为谁订票
#include "GUIOther.h"
GUIOther::GUIOther(QWidget *parent /* = 0 */) :QDialog(parent)
{
    InitWidgets();
    InitWindowLayout();
    InitSignalSlot();

}
void GUIOther::InitWidgets()//窗体器件设置
{
     gBoxOther=new QGroupBox(CN("用户列表"),this);
     tabUserList=new QTableWidget(this);
     btnBack=new QPushButton(CN("返回上级"),this);
     btnOrder=new QPushButton(CN("为他订票"),this);

     hBLayoutAll = new QHBoxLayout(this);
     hBLayoutMain = new QHBoxLayout();
     vBLayoutButtons=new QVBoxLayout();

     guiTicket = new GUITicket(this);
     setWindowOpacity(0.9);//设置透明度为0.9

     tabUserList->horizontalHeader()->setHighlightSections(false);
     //表头自适应大小
     tabUserList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     //一次只能选择一行
     tabUserList->setSelectionBehavior(QAbstractItemView::SelectRows);
     //一次只能选择一个对象
     tabUserList->setSelectionMode(QAbstractItemView::SingleSelection);
     //禁止单元格编辑
     tabUserList->setEditTriggers(QAbstractItemView::NoEditTriggers);
     //设置自适应大小
     btnOrder->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
     btnBack->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

}
void GUIOther::InitWindowLayout()//布局
{
    vBLayoutButtons->addWidget(btnOrder);
    vBLayoutButtons->addWidget(btnBack);

    hBLayoutMain->addWidget(tabUserList);
    hBLayoutMain->addLayout(vBLayoutButtons);
    hBLayoutMain->setStretch(0,3);
    hBLayoutMain->setStretch(1, 1);

    gBoxOther->setLayout(hBLayoutMain);
    hBLayoutAll->addWidget(gBoxOther);
    this->setLayout(hBLayoutAll);

}

void GUIOther::InitSignalSlot()//建立信号与槽的联系
{
    connect(this->btnBack, SIGNAL(clicked()), this, SLOT(ShowParent()));//返回上级
    connect(this->btnOrder, SIGNAL(clicked()), this, SLOT(ShowOrder()));//进入订票界面
}
void GUIOther::GetUserList()//读取并显示用户名和姓名
{

    Factory factory;
    QVector<ModelUser> userList;
    userList = factory.logicUser->GetOtherUserInfrom(this->mainUser);
    if (userList.isEmpty())
    {
        this->tabUserList->clear();
        this->tabUserList->setColumnCount(0);
        this->tabUserList->setRowCount(0);
        return;
    }

    QStringList trainInfromHeader;
    trainInfromHeader << CN("用户名")
        << CN("姓名");

    int  trainListRow = userList.count();
    this->tabUserList->setColumnCount(2);
    this->tabUserList->setRowCount(trainListRow);
    this->tabUserList->setHorizontalHeaderLabels(trainInfromHeader);

    for (int i = 0; i < trainListRow; i++)//实现显示用户名和姓名
    {
        this->tabUserList->setItem(i, 0, new QTableWidgetItem());
        this->tabUserList->setItem(i, 1, new QTableWidgetItem());

        this->tabUserList->item(i, 0)->setText(userList[i].U_Id());
        this->tabUserList->item(i, 1)->setText(userList[i].U_Name());
    }
}

void GUIOther::ShowOrder()//实现打开订票界面
{
    QString currentUser = this->tabUserList->item(this->tabUserList->currentRow(), 0)->text();

    this->guiTicket->SetCurrentUser(currentUser, this->mainUser);
    this->guiTicket->show();
    this->hide();

}
void GUIOther::ShowParent()//实现返回上一界面
{
    //将父指针向下转型为QDialog
    QDialog *parentDialog = qobject_cast<QDialog*>(this->parent());
    this->hide();

    parentDialog->show();

}
void GUIOther::SetMainUser(QString userName)
{
    this->mainUser = userName;
    GetUserList();
}
GUIOther::~GUIOther()
{

}
