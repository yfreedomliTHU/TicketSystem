//已购车票信息界面
#include "GUITicketInfrom.h"
GUITicketInfrom::GUITicketInfrom(QWidget *parent /* = 0 */) :QDialog(parent)
{
    InitWidgets();
    InitWindowLayout();
    InitSignalSlot();
}
void GUITicketInfrom::InitWidgets()
{
     gBoxTicket=new QGroupBox(CN("已购车票"),this);
     gBoxTicketManage=new QGroupBox(CN("车票管理"),this);
     tabTicket=new QTableWidget(this);
     btnBack=new QPushButton(CN("返回上级"),this);
     btnAntiOrder=new QPushButton(CN("退订车票"),this);

     vBLayoutMain = new QVBoxLayout(this);
     hBLayoutTicket=new QHBoxLayout();
     hBLayoutButtons=new QHBoxLayout();


    tabTicket->horizontalHeader()->setHighlightSections(false);
     //表头自适应大小
    tabTicket->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     //一次只能选择一行
    tabTicket->setSelectionBehavior(QAbstractItemView::SelectRows);
     //一次只能选择一个对象
    tabTicket->setSelectionMode(QAbstractItemView::SingleSelection);
     //单元格不能编辑
    tabTicket->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->resize(1000, 618);
    setWindowOpacity(0.9);//设置透明度为0.9

}

void GUITicketInfrom::InitWindowLayout()
{
    hBLayoutTicket->addWidget(tabTicket);
    gBoxTicket->setLayout(hBLayoutTicket);

    hBLayoutButtons->addStretch(1);
    hBLayoutButtons->addWidget(btnAntiOrder);
    hBLayoutButtons->addWidget(btnBack);
    gBoxTicketManage->setLayout(hBLayoutButtons);

    vBLayoutMain->addWidget(gBoxTicket);
    vBLayoutMain->addWidget(gBoxTicketManage);


}
void GUITicketInfrom::InitSignalSlot()
{

    connect(this->btnAntiOrder, SIGNAL(clicked()), this, SLOT(BtnAntiOrderClicked()));

    connect(this->btnBack, SIGNAL(clicked()), this, SLOT(BtnBackToParent()));

}
void GUITicketInfrom::BtnBackToParent()
{
    QDialog *parentDialog = qobject_cast<QDialog*>(this->parent());
    this->hide();


    parentDialog->show();
}
void GUITicketInfrom::BtnAntiOrderClicked()
{
    if (tabTicket->rowCount()<1)
    {
        return;
    }



    //更新user
    Factory factory;
    ModelUser newModelUser = factory.logicUser->GetUserInfrom(this->userName);
    //退钱
    int backMoney = newModelUser.U_Balance().toInt() + tabTicket->item(tabTicket->currentRow(), 5)->text().toInt()*0.8;
    newModelUser.U_Balance(QString("%1").arg(backMoney));
    factory.logicUser->Update(newModelUser);

    //退票

    QString currentTN_Id = tabTicket->item(tabTicket->currentRow(), 2)->text();
    ModelTrainNumber newModelTrainNum = factory.logicTrainNumber->GetTrainNumInfrom(currentTN_Id);
    int ticketNumPuls = newModelTrainNum.TN_TicketNum().toInt() + 1;
    newModelTrainNum.TN_TicketNum(QString("%1").arg(ticketNumPuls));
    factory.logicTrainNumber->Update(newModelTrainNum);

    factory.logicUserTicket->Delete(tabTicket->item(tabTicket->currentRow(), 0)->text());

    //退座位
    factory.logicTrainSeat->DeleteByTrainSeat(tabTicket->item(tabTicket->currentRow(), 6)->text(), tabTicket->item(tabTicket->currentRow(), 7)->text());


    //更新数据
    GetUserTicket();
}
void GUITicketInfrom::GetUserTicket()
{
    Factory factory;
    QVector<ModelUserTicket> userTicketList;
    userTicketList = factory.logicUserTicket->GetListByUserName(this->userName);
    if (userTicketList.isEmpty())
    {
        tabTicket->clear();
        this->tabTicket->setColumnCount(0);
        this->tabTicket->setRowCount(0);
        return;
    }

    QStringList trainInfromHeader;
    trainInfromHeader
        << CN("票号")
        << CN("票主")
        << CN("车次")
        << CN("起始站点")
        << CN("目的站点")
        << CN("票价")
        << CN("列车")
        << CN("座位")
        ;
    int  trainListRow = userTicketList.count();
    this->tabTicket->setColumnCount(8);
    this->tabTicket->setRowCount(trainListRow);
    this->tabTicket->setHorizontalHeaderLabels(trainInfromHeader);
    //this->tabWTrainNum->setColumnHidden(1, true);

    for (int i = 0; i < trainListRow; i++)
    {
        this->tabTicket->setItem(i, 0, new QTableWidgetItem());
        this->tabTicket->setItem(i, 1, new QTableWidgetItem());
        this->tabTicket->setItem(i, 2, new QTableWidgetItem());
        this->tabTicket->setItem(i, 3, new QTableWidgetItem());
        this->tabTicket->setItem(i, 4, new QTableWidgetItem());
        this->tabTicket->setItem(i, 5, new QTableWidgetItem());
        this->tabTicket->setItem(i, 6, new QTableWidgetItem());
        this->tabTicket->setItem(i, 7, new QTableWidgetItem());

        tabTicket->item(i, 0)->setText(userTicketList[i].UT_Id());
        tabTicket->item(i, 1)->setText(userTicketList[i].U_Id());
        tabTicket->item(i, 2)->setText(userTicketList[i].TN_Id());
        tabTicket->item(i, 3)->setText(userTicketList[i].UT_SStation());
        tabTicket->item(i, 4)->setText(userTicketList[i].UT_EStation());
        tabTicket->item(i, 5)->setText(userTicketList[i].UT_Price());
        tabTicket->item(i, 6)->setText(userTicketList[i].UT_Type());
        tabTicket->item(i, 7)->setText(userTicketList[i].UT_SeatNum());
    }
}
void GUITicketInfrom::SetUserName(QString userName)
{
    this->userName = userName;
    GetUserTicket();
}
GUITicketInfrom::~GUITicketInfrom()
{

}
