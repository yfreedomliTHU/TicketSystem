//购票界面
#include "GUITicket.h"
GUITicket::GUITicket(QWidget *parent /* = 0 */) :QDialog(parent)
{
    InitWidgets();
    InitWindowLayout();
    InitSignalSlot();

    TrainNumList();
}
void GUITicket::InitWidgets()
{
    //搜索区域
     gBoxSearch=new QGroupBox(CN("车次搜索"),this);//搜索区域

     hBLayoutSearch=new QHBoxLayout();//搜索区域水平布局管理器
     labelSearch=new QLabel(CN("请搜索:"),this);//搜索
     lEditSearch=new QLineEdit(this);
     comBoxSearch=new QComboBox(this);
     btnSearch=new QPushButton(CN("搜索"),this);
     btnBack=new QPushButton(CN("返回上级"),this);//返回上级

     //车次信息
      gBoxTrainNum=new QGroupBox(CN("车次信息"),this);
      hBLayoutTrainNum = new QHBoxLayout();
      tabWTrainNum=new QTableWidget(this);//车次表

      //车座信息
       gBoxTrainSeats=new QGroupBox(CN("车座选择"),this);

       //座位的父对象由布局时设置

       gLayoutSeats=new QGridLayout();


       //所选车次信息信息

        gBoxTicketInfrom=new QGroupBox(CN("所选车次信息"),this);
        gLayoutTicketInfrom=new QGridLayout();
        hBLayoutTicketInfrom=new QHBoxLayout();

        labelTrainNumTime=new QLabel(CN("时间:"),this);//出发时间
        labelTrainName=new QLabel(CN("列车:"),this);//列车编号

        labelTrainSeat=new QLabel(CN("车座"),this);//座位号
        //动态初始化

        labelTrainNumId=new QLabel(CN("车次:"),this);//车次
        labelTrainSStation=new QLabel(CN("起点站:"),this);//起点站
        labelTrainEStation=new QLabel(CN("终点站:"),this);//终点站

        lEditTrainNumTime=new QLineEdit(this);
        lEditTrainName=new QLineEdit(this);
        lEditTrainSeat=new QLineEdit(this);

        lEditTrainNumId=new QLineEdit(this);
        lEditTrainSStation=new QLineEdit(this);
        comBoxTrainEStation=new QComboBox(this);

        btnOrder=new QPushButton(this);//结算车费


        vBLayoutMain = new QVBoxLayout(this);//垂直布局


        //禁用所选车次信息输入框，仅显示
        this->lEditTrainName->setEnabled(false);
        this->lEditTrainNumId->setEnabled(false);
        this->lEditTrainNumTime->setEnabled(false);
        this->lEditTrainSeat->setEnabled(false);
        this->lEditTrainSStation->setEnabled(false);

        //按钮垂直方向拓展
        btnOrder->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);


        tabWTrainNum->horizontalHeader()->setHighlightSections(false);
        //表头自适应大小
        tabWTrainNum->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //一次只能选择一行
        tabWTrainNum->setSelectionBehavior(QAbstractItemView::SelectRows);
        //一次只能选择一个对象
        tabWTrainNum->setSelectionMode(QAbstractItemView::SingleSelection);
        //单元格不能编辑
        tabWTrainNum->setEditTriggers(QAbstractItemView::NoEditTriggers);


        //搜索
        comBoxSearch->addItem(CN("按车次"),CN("TN_Id"));
        comBoxSearch->addItem(CN("按起点"), CN("TN_SStation"));

        this->resize(1200,680);
        setWindowOpacity(0.9);//设置透明度为0.9


}
void GUITicket::InitWindowLayout()
{
    hBLayoutSearch->addWidget(labelSearch);
    hBLayoutSearch->addWidget(lEditSearch);
    hBLayoutSearch->addWidget(comBoxSearch);
    hBLayoutSearch->addWidget(btnSearch);
    hBLayoutSearch->addStretch(1);
    hBLayoutSearch->addWidget(btnBack);

    this->gBoxSearch->setLayout(hBLayoutSearch);

    hBLayoutTrainNum->addWidget(tabWTrainNum);
    this->gBoxTrainNum->setLayout(hBLayoutTrainNum);

    //15*4
    //15*8，实现通过界面查看是否还有空位
    int btnIndex = 0;
    for (int i = 0; i < 8;i++)
    {
        for (int j = 0; j < 15;j++)
        {
            //120个按钮 信号和槽连接
            connect(&btnSeats[btnIndex], SIGNAL(clicked()), this, SLOT(SelectSeatNum()));
            btnSeats[btnIndex].setParent(this);
            gLayoutSeats->addWidget(&btnSeats[btnIndex],i, j);
            btnIndex = btnIndex+1;
        }
    }

    this->gBoxTrainSeats->setLayout(gLayoutSeats);

    //3*2网格布局
    gLayoutTicketInfrom->addWidget(labelTrainNumTime,0,0);
    gLayoutTicketInfrom->addWidget(lEditTrainNumTime, 0, 1);
    gLayoutTicketInfrom->addWidget(labelTrainName, 0, 2);
    gLayoutTicketInfrom->addWidget(lEditTrainName, 0, 3);
    gLayoutTicketInfrom->addWidget(labelTrainSeat, 0, 4);
    gLayoutTicketInfrom->addWidget(lEditTrainSeat, 0, 5);

    gLayoutTicketInfrom->addWidget(labelTrainNumId, 1, 0);
    gLayoutTicketInfrom->addWidget(lEditTrainNumId, 1, 1);
    gLayoutTicketInfrom->addWidget(labelTrainSStation, 1, 2);
    gLayoutTicketInfrom->addWidget(lEditTrainSStation, 1, 3);
    gLayoutTicketInfrom->addWidget(labelTrainEStation, 1, 4);
    gLayoutTicketInfrom->addWidget(comBoxTrainEStation, 1, 5);

    hBLayoutTicketInfrom->addLayout(gLayoutTicketInfrom);
    hBLayoutTicketInfrom->addWidget(btnOrder);
    //结账按和 车票信息 比例
    hBLayoutTicketInfrom->setStretch(0, 5);
    hBLayoutTicketInfrom->setStretch(1, 1);

    this->gBoxTicketInfrom->setLayout(hBLayoutTicketInfrom);

    vBLayoutMain->addWidget(gBoxSearch);
    vBLayoutMain->addWidget(gBoxTrainNum);
    vBLayoutMain->addWidget(gBoxTrainSeats);
    vBLayoutMain->addWidget(gBoxTicketInfrom);

    this->setLayout(vBLayoutMain);


}
void GUITicket::InitSignalSlot()
{
    connect(this->tabWTrainNum, SIGNAL(cellClicked(int, int)), this, SLOT(TableTrainNumRowClicked(int, int)));
    connect(this->comBoxTrainEStation, SIGNAL(currentIndexChanged(int)), this, SLOT(UserChoseEStation(int)));

    connect(this->btnOrder, SIGNAL(clicked()), this, SLOT(BtnOrderClicked()));
    connect(this->btnBack,SIGNAL(clicked()),this,SLOT(BtnBackClicked()));

    connect(this->btnSearch, SIGNAL(clicked()), this, SLOT(BtnSearchClicked()));
}
void GUITicket::BtnSearchClicked()
{

    //搜索

    QString currentConditon = comBoxSearch->currentData().toString();
    Factory factory;
    QVector<ModelTrainNumber> trainList;
    trainList = factory.logicTrainNumber->GetListByCondition(" "+currentConditon+"="+"'"+this->lEditSearch->text()+"'");
    if (trainList.isEmpty())
    {
        tabWTrainNum->clear();
        this->tabWTrainNum->setColumnCount(0);
        this->tabWTrainNum->setRowCount(0);

        for (int i = 0; i < 120; i++)
        {
            //如果没有数据 禁用所有座位图标
            btnSeats[i].setEnabled(false);
            btnSeats[i].setText("");
            btnOrder->setEnabled(false);
            btnOrder->setText("");
        }

        return;
    }

    QStringList trainInfromHeader;
    trainInfromHeader << CN("车次")
        << CN("列车")
        << CN("起始站点")
        << CN("目的站点")
        << CN("发车时间")
        << CN("预计到达")
        << CN("总票数")
        << CN("票价")
        << CN("里程")
        << CN("购票状态")
        ;
    int  trainListRow = trainList.count();//获取行数信息
    this->tabWTrainNum->setColumnCount(10);
    this->tabWTrainNum->setRowCount(trainListRow);
    this->tabWTrainNum->setHorizontalHeaderLabels(trainInfromHeader);
    //this->tabWTrainNum->setColumnHidden(1, true);

    for (int i = 0; i < trainListRow; i++)//显示对应车次的信息
    {
        this->tabWTrainNum->setItem(i, 0, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 1, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 2, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 3, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 4, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 5, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 6, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 7, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 8, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 9, new QTableWidgetItem());

        tabWTrainNum->item(i, 0)->setText(trainList[i].TN_Id());
        tabWTrainNum->item(i, 1)->setText(trainList[i].T_Id());
        tabWTrainNum->item(i, 2)->setText(trainList[i].TN_SStation());
        tabWTrainNum->item(i, 3)->setText(trainList[i].TN_EStation());
        tabWTrainNum->item(i, 4)->setText(trainList[i].TN_STime());
        tabWTrainNum->item(i, 5)->setText(trainList[i].TN_ETime());
        tabWTrainNum->item(i, 6)->setText(trainList[i].TN_TicketNum());
        tabWTrainNum->item(i, 7)->setText(trainList[i].TN_TicketPrice());
        tabWTrainNum->item(i, 8)->setText(trainList[i].TN_Distance());
        tabWTrainNum->item(i, 9)->setText(CN("未购票"));
    }
    if (tabWTrainNum->rowCount() >= 1)
    {
        tabWTrainNum->selectRow(0);
        TableTrainNumRowClicked(0, 0);
    }



}
void GUITicket::BtnOrderClicked()
{

    QString  trainTimeString = tabWTrainNum->item(tabWTrainNum->currentRow(), 4)->text();//得到当前车次的发车时间
    QDateTime dataTimeTrain = QDateTime::fromString(trainTimeString, "yyyy/MM/dd hh:mm");
    QDateTime dataTimeNow = QDateTime::currentDateTime();
    dataTimeNow=dataTimeNow.addSecs(-1800);
    int secondSub = dataTimeTrain.secsTo(dataTimeNow);//实现禁止开车前半小时买票
    if (secondSub > 0)
    {
        QMessageBox::information(this,CN("抱歉"),CN("请在列车出发30分钟以前订票"),QMessageBox::Ok);
        return;
    }




    //维护表Ticket和表Seat 表user 表TrainNum
    QString ticketTrainId = this->lEditTrainName->text();
    QString ticketTrainNum = this->lEditTrainNumId->text();
    QString ticketSStation = this->lEditTrainSStation->text();
    QString ticketEStation = this->comBoxTrainEStation->currentText();
    QString ticketPrice = this->comBoxTrainEStation->currentData().toString();
    QString ticketSeatNum = this->currentSeatNum;

    if (ticketSeatNum.isEmpty())//对未选座就付钱的错误行为的回应
    {
        QMessageBox::information(this, CN("抱歉"), CN("请选择座位"), QMessageBox::Ok);
        return;
    }


    //判断账户余额
    Factory factory;
    ModelUser currentUser = factory.logicUser->GetUserInfrom(this->userName);//获取当期User的全部信息
    int userMoneyint = 0;
    int ticketPriceint = 1;
    try
    {
         userMoneyint = currentUser.U_Balance().toInt();
         ticketPriceint = ticketPrice.toInt();
    }
    catch (double)
    {

    }

    bool updateStatus = true;
    if (this->orderUserName!=CN("NULL"))
    {
        ModelUser orderUserModel = factory.logicUser->GetUserInfrom(this->orderUserName);
        int orderUserMoney = orderUserModel.U_Balance().toInt();//调用Modeluser的函数得到当前余额
        if (orderUserMoney >= ticketPriceint)
        {
            orderUserModel.U_Balance(QString("%1").arg(orderUserMoney - ticketPriceint));
            updateStatus = factory.logicUser->Update(orderUserModel);
        }
        else
        {
            QMessageBox::information(this, CN("注意"), CN("您当前的余额不足，无法为他人购票"), QMessageBox::Ok);
            return;
        }
    }
    else
    {
        if (userMoneyint < ticketPriceint)
        {
            QMessageBox::information(this, CN("注意"), CN("您当前的余额不足，现在将使用其他方式购票"), QMessageBox::Ok);
        }

        //user
        if (userMoneyint >= ticketPriceint)
        {
            //更新账户余额

            currentUser.U_Balance(QString("%1").arg(userMoneyint - ticketPriceint));
            updateStatus = factory.logicUser->Update(currentUser);
        }
    }



    //userTicket 创建一张新的车票
    //创建机打号码,实现票号唯一性

    QUuid ticketId = QUuid::createUuid();

    ModelUserTicket newTicketModel;//创建车票模型类
    newTicketModel.UT_Id(ticketId.toString());
    newTicketModel.U_Id(this->userName);
    newTicketModel.TN_Id(ticketTrainNum);
    newTicketModel.UT_SStation(ticketSStation);
    newTicketModel.UT_EStation(ticketEStation);
    newTicketModel.UT_Type(ticketTrainId);
    newTicketModel.UT_Price(ticketPrice);
    newTicketModel.UT_SeatNum(ticketSeatNum);

    updateStatus=factory.logicUserTicket->Insert(newTicketModel);

    //更新车次信息
    ModelTrainNumber newTrainNum;
    newTrainNum.TN_Id(tabWTrainNum->item(tabWTrainNum->currentRow(), 0)->text());
    newTrainNum.T_Id(tabWTrainNum->item(tabWTrainNum->currentRow(), 1)->text());
    newTrainNum.TN_SStation(tabWTrainNum->item(tabWTrainNum->currentRow(), 2)->text());
    newTrainNum.TN_EStation(tabWTrainNum->item(tabWTrainNum->currentRow(), 3)->text());
    newTrainNum.TN_STime(tabWTrainNum->item(tabWTrainNum->currentRow(), 4)->text());
    newTrainNum.TN_ETime(tabWTrainNum->item(tabWTrainNum->currentRow(), 5)->text());
    newTrainNum.TN_TicketPrice(tabWTrainNum->item(tabWTrainNum->currentRow(), 7)->text());
    newTrainNum.TN_Distance(tabWTrainNum->item(tabWTrainNum->currentRow(), 8)->text());

    QString currentTicketCount = tabWTrainNum->item(tabWTrainNum->currentRow(), 6)->text();
    newTrainNum.TN_TicketNum(QString("%1").arg(currentTicketCount.toInt() - 1));

    updateStatus = factory.logicTrainNumber->Update(newTrainNum);


    //更新座位

    QUuid seatId = QUuid::createUuid();
    ModelTrainSeat newTrainSeat;
    newTrainSeat.TS_Id(seatId.toString());
    newTrainSeat.T_Id(ticketTrainId);
    newTrainSeat.TS_SellNum(this->currentSeatNum);

    updateStatus = factory.logicTrainSeat->Insert(newTrainSeat);
    if (updateStatus)
    {
        QMessageBox::information(this, CN("温馨提示"),CN("恭喜，购票成功"),QMessageBox::Ok);
    }

    TrainNumList();
    UserTrainNumList(this->userName);
    if (tabWTrainNum->rowCount() >= 1)
    {
        TableTrainNumRowClicked(0, 0);
    }

}
void GUITicket::UserChoseEStation(int index)
{
    QString currentTrainNumSatatus = tabWTrainNum->item(tabWTrainNum->currentRow(), 9)->text();//检查目前该车次的购票状态
    if (currentTrainNumSatatus==CN("已购票"))//已购票后不能再购票
    {
        this->btnOrder->setText(CN("您已购票"));
        return;
    }

    QString currentEStationName =  comBoxTrainEStation->currentText();
    QString currentEStationPrice = comBoxTrainEStation->currentData().toString();
    this->btnOrder->setText(CN("购票:共%1元").arg(currentEStationPrice));


}
void GUITicket::TableTrainNumRowClicked(int row,int column)
{

    Factory factory;
    this->btnOrder->setEnabled(true);

    //判断时间范围

    //判断是否有票

    QString currentTrainNumTicket = tabWTrainNum->item(row, 6)->text();
    int currentTicketCount = 0;
    try
    {
        currentTicketCount = currentTrainNumTicket.toInt();
    }
    catch (double)
    {
        return;
    }

    if (currentTicketCount < 1)
    {
        this->btnOrder->setEnabled(false);
    }


    //限定一个用户单个车次只能购买一张
    QString currentTrainNumSatatus = tabWTrainNum->item(row, 9)->text();//获取当前车次的购票状态
    if (CN("已购票") == currentTrainNumSatatus)
    {
        this->btnOrder->setEnabled(false);
    }

    //填充数据
    //时间
    this->lEditTrainNumTime->setText(tabWTrainNum->item(row, 4)->text() + "--"+tabWTrainNum->item(row, 5)->text());
    //列车
    this->lEditTrainName->setText(tabWTrainNum->item(row, 1)->text());
    //车次
    this->lEditTrainNumId->setText(tabWTrainNum->item(row, 0)->text());

    //起点
    this->lEditTrainSStation->setText(tabWTrainNum->item(row, 2)->text());


    //填充当前车次所有经过站点
    QVector<ModelTrainPass> currentTrainNumPass = factory.logicTrainPass->GetListByTrainNum(tabWTrainNum->item(row, 0)->text());
    //首先填充终点
    //清空列表
    this->comBoxTrainEStation->clear();
    //填写 里程-价格键值对
    this->comBoxTrainEStation->addItem(tabWTrainNum->item(row, 3)->text(), tabWTrainNum->item(row, 7)->text());
    for (int i = 0; i < currentTrainNumPass.count();i++)
    {
        this->comBoxTrainEStation->addItem(currentTrainNumPass[i].TP_SName(), currentTrainNumPass[i].TP_Price());
    }

    ModelTrain currentTrainInfrom = factory.logicTrain->GetTrainInfromById(tabWTrainNum->item(row, 1)->text());
    this->currentTrainType = currentTrainInfrom.T_Type();
    this->currentTrainSeat = currentTrainInfrom.T_SeatType();
    //车座

    QMap<int, QString> seatMap;
    seatMap.insert(1, CN("上"));
    seatMap.insert(2, CN("中"));
    seatMap.insert(0, CN("下"));

    if (CN("坐铺车厢") == currentTrainSeat)
    {
        //1-120编号
        for (int i = 0; i < 120;i++)
        {
            this->btnSeats[i].setEnabled(true);
            this->btnSeats[i].setObjectName(QString("%1").arg(i+1));
            this->btnSeats[i].setText(QString("%1").arg(i+1)+CN("号"));
        }
    }
    else
    {
        if (CN("卧铺车厢") == currentTrainSeat)
        {
            //1-60
            //前60显示
            int currentKey = 1;
            for (int i = 0; i < 60; i++)
            {
                this->btnSeats[i].setEnabled(true);
                this->btnSeats[i].setObjectName(QString("%1").arg(i+1));
                this->btnSeats[i].setText(QString("%1").arg(currentKey) + seatMap[(i+1)%3]);
                if ((i+1)%3==0)
                {
                    currentKey++;
                }
            }
            //后60禁止
            for (int i = 60; i < 120; i++)
            {
                this->btnSeats[i].setEnabled(false);
                this->btnSeats[i].setText(CN(""));
            }
        }
    }
    //复写已经占据的位置
    QStringList currentTrainUsedSeat = factory.logicTrainSeat->GetSellSeatListByTrain(this->lEditTrainName->text(),this->lEditTrainNumId->text());
    for (int i = 0; i < currentTrainUsedSeat.count();i++)
    {
        int currentUserSeat = currentTrainUsedSeat[i].toInt()-1;
        if (currentUserSeat>=0 && currentUserSeat<120)
        {
            btnSeats[currentUserSeat].setEnabled(false);
            btnSeats[currentUserSeat].setText(CN("已售"));
        }
    }




    //清空当前座位
    this->lEditTrainSeat->clear();

}
void GUITicket::SelectSeatNum()
{
    //将信号源向下转型为QPushButton
    QPushButton *currentSeat = qobject_cast<QPushButton*>(this->sender());
    this->currentSeatNum = currentSeat->objectName();
    this->lEditTrainSeat->setText(currentSeat->text());

}
void GUITicket::BtnBackClicked()
{
    QDialog *parentDialog = qobject_cast<QDialog*>(this->parent());
    this->hide();

    parentDialog->show();


}
void GUITicket::UserTrainNumList(QString currentUser)
{

    Factory factory;
    QStringList userTrainNumList;
    userTrainNumList = factory.logicUserTicket->GetUserTicket(currentUser);
    if (userTrainNumList.count()<1)
    {
        return;
    }
    for (int i = 0; i < userTrainNumList.count();i++)
    {
        for (int j = 0; j < tabWTrainNum->rowCount(); j++)
        {
            QString currentTN_Id = tabWTrainNum->item(j, 0)->text();
            if (currentTN_Id == userTrainNumList[i])
            {
                tabWTrainNum->item(j, 9)->setText(CN("已购票"));
            }

        }
    }


}

void GUITicket::TrainNumList()
{
    Factory factory;
    QVector<ModelTrainNumber> trainList;
    trainList = factory.logicTrainNumber->GetList();
    if (trainList.isEmpty())
    {
        tabWTrainNum->clear();
        this->tabWTrainNum->setColumnCount(0);
        this->tabWTrainNum->setRowCount(0);

        for (int i = 0; i < 120; i++)
        {
            //如果没有数据 禁用所有
            btnSeats[i].setEnabled(false);
            btnSeats[i].setText("");
            btnOrder->setEnabled(false);
            btnOrder->setText("");
        }

        return;
    }

    QStringList trainInfromHeader;
    trainInfromHeader << CN("车次")
        << CN("列车")
        << CN("起始站点")
        << CN("目的站点")
        << CN("发车时间")
        << CN("预计到达")
        << CN("总票数")
        << CN("票价")
        << CN("里程")
        << CN("购票状态")
        ;
    int  trainListRow = trainList.count();
    this->tabWTrainNum->setColumnCount(10);
    this->tabWTrainNum->setRowCount(trainListRow);
    this->tabWTrainNum->setHorizontalHeaderLabels(trainInfromHeader);
    //this->tabWTrainNum->setColumnHidden(1, true);

    for (int i = 0; i < trainListRow; i++)
    {
        this->tabWTrainNum->setItem(i, 0, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 1, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 2, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 3, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 4, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 5, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 6, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 7, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 8, new QTableWidgetItem());
        this->tabWTrainNum->setItem(i, 9, new QTableWidgetItem());

        tabWTrainNum->item(i, 0)->setText(trainList[i].TN_Id());
        tabWTrainNum->item(i, 1)->setText(trainList[i].T_Id());
        tabWTrainNum->item(i, 2)->setText(trainList[i].TN_SStation());
        tabWTrainNum->item(i, 3)->setText(trainList[i].TN_EStation());
        tabWTrainNum->item(i, 4)->setText(trainList[i].TN_STime());
        tabWTrainNum->item(i, 5)->setText(trainList[i].TN_ETime());
        tabWTrainNum->item(i, 6)->setText(trainList[i].TN_TicketNum());
        tabWTrainNum->item(i, 7)->setText(trainList[i].TN_TicketPrice());
        tabWTrainNum->item(i, 8)->setText(trainList[i].TN_Distance());
        tabWTrainNum->item(i, 9)->setText(CN("未购票"));
    }
    if (tabWTrainNum->rowCount() >= 1)
    {
        tabWTrainNum->selectRow(0);
        TableTrainNumRowClicked(0,0);
    }
}

void GUITicket::SetCurrentUser(QString userName,QString orderUserName)
{
    this->userName = userName;
    this->orderUserName = orderUserName;

    TrainNumList();
    UserTrainNumList(userName);

}
GUITicket::~GUITicket()
{

}
