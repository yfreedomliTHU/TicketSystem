//管理员管理界面，可实现对车次，途经站点等信息的维护和修改
#include "GUIAdmin.h"
GUIAdmin::GUIAdmin(QString userName,QWidget *parent/* =0 */):
userName(userName), QDialog(parent)
{
    InitWidgets();
    InitWindowLayout();
    InitSignalSlot();

    //自动
    GetTrainList();
    GetTrainNumList();

}
void GUIAdmin::InitWidgets()
{
    //车次信息
    gBoxTrainNum=new QGroupBox(CN("车次一览"),this);
    tabWTrainNum=new QTableWidget(this);
    hBLauyout=new QHBoxLayout();


    //经过站点
    gBoxTrainPass = new QGroupBox(CN("车次经过站点"));
    hBLayoutTrainPass = new QHBoxLayout();//经过站点区域主布局管理器
    gLayoutTrainPassInfrom=new QGridLayout();//经过站点信息网格布局管理器
    vBLayoutTrainPassManage=new QVBoxLayout();//经过站点信息管理布局管理器


    tabTrainPass = new QTableWidget(this);
    labelTrainPassName = new QLabel(CN("站点名称:"),this);
    labelTrainPassDistance = new QLabel(CN("站点里程:"),this);
    labelTrainPassPrice = new QLabel(CN("站点票价"),this);

    lEditTrainPassName = new QLineEdit(this);
    lEditTrainPassDistance = new QLineEdit(this);
    lEditTrainPassPrice = new QLineEdit(this);

    btnTrainPassAdd = new QPushButton(CN("增加站点"),this);
    btnTrainPassDelete = new QPushButton(CN("移除站点"),this);

    //火车信息
     gBoxTrainInfrom=new QGroupBox(CN("列车一览"));//区域
     hBLayoutTrainInfromMain = new QHBoxLayout();
     gLayoutTrainInfromUpdateTop = new QGridLayout();
     vBLayoutTrainInfromUpdate = new QVBoxLayout();


     tabTrainInfrom = new QTableWidget(this);
     labelTrainInfromId = new QLabel(CN("列车编号"),this);
     labelTrainInfromType = new QLabel(CN("列车类型:"), this);
     labelTrainInfromSeatType = new QLabel(CN("车座类型:"),this);

     lEdiTrainInfromId = new QLineEdit(this);
     comBoxTrainInfromType=new QComboBox(this);
     comBoxTrainInfromSeatType=new QComboBox(this);

     btnTrainInfromAdd = new QPushButton(CN("增设列车"),this);
     btnTrainInfromDelete = new QPushButton(CN("移除列车"),this);

     // 车次信息更新
      gBoxTrainNumUpdate=new QGroupBox(CN("信息更新"),this);
      gLayoutTrainNumInfrom=new QGridLayout();
      hBLayoutTrainNumButtons=new QHBoxLayout();
      vBLayoutTrainNumMain=new QVBoxLayout();

      labelTrainNumUpdateId = new QLabel(CN("车次编号:"), this);
      labelTrainNumUpdateTrain = new QLabel(CN("车次列车:"), this);
      labelTrainNumUpdateTicket = new QLabel(CN("总票数:"), this);
      labelTrainNumUpdatePrice = new QLabel(CN("票价:"), this);
      labelTrainNumUpdateDistance = new QLabel(CN("里程:"),this);

      labelTrainNumUpdateStart = new QLabel(CN("起始站点:"), this);//起始站点
      labelTrainNumUpdateEnd = new QLabel(CN("目的站点:"), this);//结束站点
      labelTrainNumUpdateSTime = new QLabel(CN("发车时间:"), this);//发车时间
      labelTrainNumUpdateETime = new QLabel(CN("预计到达:"), this);//预计到达


      lEditTrainNumUpdateId=new QLineEdit(this);
      comBoxNumUpdateTrain=new QComboBox(this);
      lEditTrainNumUpdateTicket=new QLineEdit(this);
      lEditTrainNumUpdatePrice=new QLineEdit(this);

      lEditTrainNumUpdateStart=new QLineEdit(this);
      lEditTrainNumUpdateEnd=new QLineEdit(this);

      timeEditTrainNumSTime=new QDateTimeEdit(this);
      timeEditTrainNumETime=new QDateTimeEdit(this);

      lEditTrainNumDistance = new QLineEdit(this);

      btnUpdate=new QPushButton(CN("更新信息"));
      btnDelete=new QPushButton(CN("移除车次"));
      btnAdd=new QPushButton(CN("增设车次"));
      btnBack = new QPushButton(CN("返回上级"));

      hBLayoutCentral = new QHBoxLayout();
      vBLayoutMain = new QVBoxLayout(this);

      //下拉列表数据
      comBoxTrainInfromType->addItem(CN("高铁"),CN("高铁"));
      comBoxTrainInfromType->addItem(CN("特快"), CN("特快"));
      comBoxTrainInfromType->addItem(CN("普快"), CN("普快"));

      comBoxTrainInfromSeatType->addItem(CN("坐铺车厢"), CN("120"));
      comBoxTrainInfromSeatType->addItem(CN("卧铺车厢"), CN("60"));

      //按钮自动拓展
      btnTrainInfromAdd->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
      btnTrainInfromDelete->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

      btnTrainPassAdd->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
      btnTrainPassDelete->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

      //时间格式

      timeEditTrainNumSTime->setDisplayFormat("yyyy/MM/dd hh:mm");
      timeEditTrainNumETime->setDisplayFormat("yyyy/MM/dd hh:mm");

      //表格设置
      //表头不获得焦点


      tabTrainInfrom->horizontalHeader()->setHighlightSections(false);
      //表头自适应大小
      tabTrainInfrom->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      //一次只能选择一行
      tabTrainInfrom->setSelectionBehavior(QAbstractItemView::SelectRows);
      //一次只能选择一个对象
      tabTrainInfrom->setSelectionMode(QAbstractItemView::SingleSelection);
      //单元格不能编辑
      tabTrainInfrom->setEditTriggers(QAbstractItemView::NoEditTriggers);



      tabTrainPass->horizontalHeader()->setHighlightSections(false);
      //表头自适应大小
      tabTrainPass->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      //一次只能选择一行
      tabTrainPass->setSelectionBehavior(QAbstractItemView::SelectRows);
      //一次只能选择一个对象
      tabTrainPass->setSelectionMode(QAbstractItemView::SingleSelection);
      //单元格不能编辑
      tabTrainPass->setEditTriggers(QAbstractItemView::NoEditTriggers);


      tabWTrainNum->horizontalHeader()->setHighlightSections(false);
      //表头自适应大小
      tabWTrainNum->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      //一次只能选择一行
      tabWTrainNum->setSelectionBehavior(QAbstractItemView::SelectRows);
      //一次只能选择一个对象
      tabWTrainNum->setSelectionMode(QAbstractItemView::SingleSelection);
      //单元格不能编辑
      tabWTrainNum->setEditTriggers(QAbstractItemView::NoEditTriggers);

      setWindowOpacity(0.9);//设置透明度为0.9
      this->resize(1200, 680);

      //数据校验 正则表达式,查资料所得

      QRegExp regExpName("^[\u4e00-\u9fa5]{2,5}$");//2-5位汉字

      QRegExp regExpNum("^[1-9]\\d{5}$");//5位数字

      QRegExp regExpDistance("^[1-9]\\d{10}$");//10位数字


      lEditTrainPassPrice->setValidator(new QRegExpValidator(regExpNum, lEditTrainPassPrice));
      lEditTrainNumUpdatePrice->setValidator(new QRegExpValidator(regExpNum, lEditTrainNumUpdatePrice));
      lEditTrainNumUpdateStart->setValidator(new QRegExpValidator(regExpName, lEditTrainNumUpdateStart));
      lEditTrainNumUpdateEnd->setValidator(new QRegExpValidator(regExpName, lEditTrainNumUpdateEnd));
      lEditTrainPassName->setValidator(new QRegExpValidator(regExpName, lEditTrainPassName));
      lEditTrainNumDistance->setValidator(new QRegExpValidator(regExpDistance, lEditTrainNumDistance));
      lEditTrainPassDistance->setValidator(new QRegExpValidator(regExpDistance, lEditTrainPassDistance));
}
void GUIAdmin::InitWindowLayout()//初始化窗体布局
{
    //车次信息
    hBLauyout->addWidget(tabWTrainNum);
    gBoxTrainNum->setLayout(hBLauyout);

    //座位信息
    //gBoxTrainSeat->setLayout(gLayoutSeats);

    //经过站点
    gLayoutTrainPassInfrom->addWidget(labelTrainPassName,0,0);
    gLayoutTrainPassInfrom->addWidget(lEditTrainPassName,0,1);
    gLayoutTrainPassInfrom->addWidget(labelTrainPassDistance,1,0);
    gLayoutTrainPassInfrom->addWidget(lEditTrainPassDistance,1,1);
    gLayoutTrainPassInfrom->addWidget(labelTrainPassPrice,2,0);
    gLayoutTrainPassInfrom->addWidget(lEditTrainPassPrice,2,1);

    vBLayoutTrainPassManage->addLayout(gLayoutTrainPassInfrom);
    vBLayoutTrainPassManage->addWidget(btnTrainPassAdd);
    vBLayoutTrainPassManage->addWidget(btnTrainPassDelete);

    hBLayoutTrainPass->addWidget(tabTrainPass);
    hBLayoutTrainPass->addLayout(vBLayoutTrainPassManage);

    gBoxTrainPass->setLayout(hBLayoutTrainPass);


    //火车信息
    gLayoutTrainInfromUpdateTop->addWidget(labelTrainInfromId, 0, 0);
    gLayoutTrainInfromUpdateTop->addWidget(lEdiTrainInfromId, 0, 1);
    gLayoutTrainInfromUpdateTop->addWidget(labelTrainInfromType,1,0);
    gLayoutTrainInfromUpdateTop->addWidget(comBoxTrainInfromType,1,1);
    gLayoutTrainInfromUpdateTop->addWidget(labelTrainInfromSeatType,2,0);
    gLayoutTrainInfromUpdateTop->addWidget(comBoxTrainInfromSeatType,2,1);

    vBLayoutTrainInfromUpdate->addLayout(gLayoutTrainInfromUpdateTop);
    vBLayoutTrainInfromUpdate->addWidget(btnTrainInfromAdd);
    vBLayoutTrainInfromUpdate->addWidget(btnTrainInfromDelete);

    hBLayoutTrainInfromMain->addWidget(tabTrainInfrom);
    hBLayoutTrainInfromMain->addLayout(vBLayoutTrainInfromUpdate);

    gBoxTrainInfrom->setLayout(hBLayoutTrainInfromMain);


    // 车次信息更新

    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateId, 0, 0);
    gLayoutTrainNumInfrom->addWidget(lEditTrainNumUpdateId, 0, 1);
    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateTrain, 0, 2);
    gLayoutTrainNumInfrom->addWidget(comBoxNumUpdateTrain, 0, 3);
    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateStart, 0, 4);
    gLayoutTrainNumInfrom->addWidget(lEditTrainNumUpdateStart, 0, 5);



    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateTicket, 1, 0);
    gLayoutTrainNumInfrom->addWidget(lEditTrainNumUpdateTicket, 1, 1);
    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdatePrice, 1, 2);
    gLayoutTrainNumInfrom->addWidget(lEditTrainNumUpdatePrice, 1, 3);
    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateEnd, 1, 4);
    gLayoutTrainNumInfrom->addWidget(lEditTrainNumUpdateEnd, 1, 5);




    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateSTime, 2, 0);
    gLayoutTrainNumInfrom->addWidget(timeEditTrainNumSTime, 2, 1);
    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateETime, 2, 2);
    gLayoutTrainNumInfrom->addWidget(timeEditTrainNumETime, 2, 3);
    gLayoutTrainNumInfrom->addWidget(labelTrainNumUpdateDistance, 2, 4);
    gLayoutTrainNumInfrom->addWidget(lEditTrainNumDistance, 2, 5);


    hBLayoutTrainNumButtons->addStretch(1);
    hBLayoutTrainNumButtons->addWidget(btnAdd);
    hBLayoutTrainNumButtons->addWidget(btnDelete);
    hBLayoutTrainNumButtons->addWidget(btnUpdate);
    hBLayoutTrainNumButtons->addWidget(btnBack);

    vBLayoutTrainNumMain->addLayout(gLayoutTrainNumInfrom);
    vBLayoutTrainNumMain->addLayout(hBLayoutTrainNumButtons);

    gBoxTrainNumUpdate->setLayout(vBLayoutTrainNumMain);


    this->hBLayoutCentral->addWidget(gBoxTrainPass);
    this->hBLayoutCentral->addWidget(gBoxTrainInfrom);
    //this->hBLayoutCentral->addWidget(gBoxTrainGuest);

    this->vBLayoutMain->addWidget(gBoxTrainNum);
    //this->vBLayoutMain->addWidget(gBoxTrainSeat);
    this->vBLayoutMain->addLayout(hBLayoutCentral);
    this->vBLayoutMain->addWidget(gBoxTrainNumUpdate);

}
void GUIAdmin::InitSignalSlot()
{
    connect(this->btnTrainInfromAdd, SIGNAL(clicked()), this, SLOT(AddTrainClicked()));
    connect(this->btnTrainInfromDelete, SIGNAL(clicked()), this, SLOT(DeleteTrainClicked()));

    connect(this->btnAdd, SIGNAL(clicked()), this, SLOT(AddTrainNumClicked()));
    connect(this->btnDelete, SIGNAL(clicked()), this, SLOT(DeleteTrainNumClicked()));
    connect(this->btnUpdate, SIGNAL(clicked()), this, SLOT(UpdateTrainNumClicked()));
    connect(this->btnBack, SIGNAL(clicked()),this,SLOT(ShowParent()));

    connect(this->btnTrainPassAdd, SIGNAL(clicked()), this, SLOT(AddTrainPassClicked()));
    connect(this->btnTrainPassDelete, SIGNAL(clicked()), this, SLOT(DeleteTrainPassClicked()));

    //表
    connect(this->tabWTrainNum, SIGNAL(cellClicked(int,int)),this,SLOT(TabTrainNumClicked(int,int)));
}
void GUIAdmin::AddTrainPassClicked()
{
    if (tabWTrainNum->rowCount() <= 0 || tabWTrainNum->currentRow()<0)
    {
        return;
    }

    QUuid newId = QUuid::createUuid();
    QString tP_Id = newId.toString();
    QString tN_Id = this->tabWTrainNum->item(this->tabWTrainNum->currentRow(), 0)->text();
    QString tP_SStation = this->tabWTrainNum->item(this->tabWTrainNum->currentRow(), 0)->text();;
    QString tP_SName = lEditTrainPassName->text();
    QString tP_Distance = lEditTrainPassDistance->text();
    QString tP_Price = lEditTrainPassPrice->text();



    ModelTrainPass modelTrainPass;
    modelTrainPass.TP_Id(tP_Id);
    modelTrainPass.TN_Id(tN_Id);
    modelTrainPass.TP_SStation(tP_SStation);
    modelTrainPass.TP_SName(tP_SName);
    modelTrainPass.TP_Distance(tP_Distance);
    modelTrainPass.TP_Price(tP_Price);


    Factory factory;
    if (factory.logicTrainPass->Insert(modelTrainPass))
    {
        GetTrainPassList(tabWTrainNum->item(tabWTrainNum->currentRow(), 0)->text());
    }

}
void GUIAdmin::ShowParent()
{
    //将父指针向下转型为QDialog
    QDialog *parentDialog = qobject_cast<QDialog*>(this->parent());
    this->hide();

    parentDialog->show();
}
void GUIAdmin::DeleteTrainPassClicked()
{

    QString currentT_Id = this->tabTrainPass->item(this->tabTrainPass->currentRow(), 0)->text();
    Factory factory;
    if (factory.logicTrainPass->Delete(currentT_Id))
    {
        GetTrainPassList(tabWTrainNum->item(tabWTrainNum->currentRow(), 0)->text());
    }

}
void GUIAdmin::GetTrainPassList(QString TN_Id)
{
    Factory factory;
    QVector<ModelTrainPass> trainPassList;
    trainPassList = factory.logicTrainPass->GetListByTrainNum(TN_Id);
    if (trainPassList.isEmpty())
    {
        tabTrainPass->clear();
        this->tabTrainPass->setColumnCount(0);
        this->tabTrainPass->setRowCount(0);
        return;
    }
    QStringList trainInfromHeader;
    trainInfromHeader << CN("TP_Id") << CN("车次") << CN("经过站点") << CN("里程")<<CN("票价");

    int  trainListRow = trainPassList.count();
    this->tabTrainPass->setColumnCount(5);
    this->tabTrainPass->setRowCount(trainListRow);
    this->tabTrainPass->setHorizontalHeaderLabels(trainInfromHeader);
    this->tabTrainPass->setColumnHidden(0, true);

    for (int i = 0; i < trainListRow; i++)
    {
        this->tabTrainPass->setItem(i, 0, new QTableWidgetItem());
        this->tabTrainPass->setItem(i, 1, new QTableWidgetItem());
        this->tabTrainPass->setItem(i, 2, new QTableWidgetItem());
        this->tabTrainPass->setItem(i, 3, new QTableWidgetItem());
        this->tabTrainPass->setItem(i, 4, new QTableWidgetItem());

        tabTrainPass->item(i, 0)->setText(trainPassList[i].TP_Id());
        tabTrainPass->item(i, 1)->setText(trainPassList[i].TN_Id());
        tabTrainPass->item(i, 2)->setText(trainPassList[i].TP_SName());
        tabTrainPass->item(i, 3)->setText(trainPassList[i].TP_Distance());
        tabTrainPass->item(i, 4)->setText(trainPassList[i].TP_Price());
    }
}

void GUIAdmin::TabTrainNumClicked(int row, int column)
{
    if (this->tabWTrainNum->rowCount()<=0)
    {
        return;
    }
    this->lEditTrainNumUpdateId->setText(tabWTrainNum->item(row,0)->text());
    this->comBoxNumUpdateTrain->setCurrentText(tabWTrainNum->item(row, 1)->text());

    this->lEditTrainNumUpdateStart->setText(tabWTrainNum->item(row, 2)->text());
    this->lEditTrainNumUpdateEnd->setText(tabWTrainNum->item(row, 3)->text());

    this->timeEditTrainNumSTime->setDateTime(QDateTime::fromString(tabWTrainNum->item(row, 4)->text(), "yyyy/MM/dd hh:mm"));
    this->timeEditTrainNumETime->setDateTime(QDateTime::fromString(tabWTrainNum->item(row, 5)->text(), "yyyy/MM/dd hh:mm"));

    this->lEditTrainNumUpdateTicket->setText(tabWTrainNum->item(row, 6)->text());
    this->lEditTrainNumUpdatePrice->setText(tabWTrainNum->item(row, 7)->text());
    this->lEditTrainNumDistance->setText(tabWTrainNum->item(row, 8)->text());

    GetTrainPassList(tabWTrainNum->item(row, 0)->text());
}
void GUIAdmin::GetTrainNumList()
{
    Factory factory;
    QVector<ModelTrainNumber> trainList;
    trainList = factory.logicTrainNumber->GetList();
    if (trainList.isEmpty())
    {
        tabWTrainNum->clear();
        this->tabWTrainNum->setColumnCount(0);
        this->tabWTrainNum->setRowCount(0);
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
        ;

    int  trainListRow = trainList.count();
    this->tabWTrainNum->setColumnCount(9);
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

        tabWTrainNum->item(i, 0)->setText(trainList[i].TN_Id());
        tabWTrainNum->item(i, 1)->setText(trainList[i].T_Id());
        tabWTrainNum->item(i, 2)->setText(trainList[i].TN_SStation());
        tabWTrainNum->item(i, 3)->setText(trainList[i].TN_EStation());
        tabWTrainNum->item(i, 4)->setText(trainList[i].TN_STime());
        tabWTrainNum->item(i, 5)->setText(trainList[i].TN_ETime());
        tabWTrainNum->item(i, 6)->setText(trainList[i].TN_TicketNum());
        tabWTrainNum->item(i, 7)->setText(trainList[i].TN_TicketPrice());
        tabWTrainNum->item(i, 8)->setText(trainList[i].TN_Distance());

    }
    if (tabWTrainNum->rowCount()>=1)
    {
        tabWTrainNum->selectRow(0);
        this->TabTrainNumClicked(0,0);


    }


}
void GUIAdmin::AddTrainNumClicked()
{
    QString tN_Id = lEditTrainNumUpdateId->text();
    QString t_Id = comBoxNumUpdateTrain->currentText();
    QString tN_SStation = lEditTrainNumUpdateStart->text();
    QString tN_EStation = lEditTrainNumUpdateEnd->text();
    QString tN_STime = timeEditTrainNumSTime->text();
    QString tN_ETime = timeEditTrainNumETime->text();
    QString tN_TicketNum = lEditTrainNumUpdateTicket->text();
    QString tN_TicketPrice = lEditTrainNumUpdatePrice->text();
    QString tN_Distance = lEditTrainNumDistance->text();

    int ticketNum = tN_TicketNum.toInt();

    if (!(ticketNum == 60 || ticketNum == 120))
    {
        QMessageBox::information(this, CN("提示"), CN("卧铺车车票数需为60，坐铺车车票数需为120"), QMessageBox::Ok);
        return;
    }


    if (tN_Id.isEmpty()
        || t_Id.isEmpty()
        || tN_SStation.isEmpty()
        || tN_EStation.isEmpty()
        || tN_TicketNum.isEmpty()
        || tN_TicketPrice.isEmpty()
        || tN_Distance.isEmpty()
        )
    {
        //弹出警告消息框
        QMessageBox::warning(this, CN("注意"),CN("开通车次请输入完整信息！"),QMessageBox::Ok);
    }


    ModelTrainNumber modelTrainNumber;
    modelTrainNumber.TN_Id(tN_Id);
    modelTrainNumber.T_Id(t_Id);
    modelTrainNumber.TN_SStation(tN_SStation);
    modelTrainNumber.TN_EStation(tN_EStation);
    modelTrainNumber.TN_STime(tN_STime);
    modelTrainNumber.TN_ETime(tN_ETime);
    modelTrainNumber.TN_TicketNum(tN_TicketNum);
    modelTrainNumber.TN_TicketPrice(tN_TicketPrice);
    modelTrainNumber.TN_Distance(tN_Distance);

    Factory factory;
    if (factory.logicTrainNumber->Insert(modelTrainNumber))
    {
        GetTrainNumList();
    }


}

void GUIAdmin::UpdateTrainNumClicked()//更新车次表中具体某一栏的信息
{
    QString tN_Id = lEditTrainNumUpdateId->text();
    QString t_Id = comBoxNumUpdateTrain->currentText();
    QString tN_SStation = lEditTrainNumUpdateStart->text();
    QString tN_EStation = lEditTrainNumUpdateEnd->text();
    QString tN_STime = timeEditTrainNumSTime->text();
    QString tN_ETime = timeEditTrainNumETime->text();
    QString tN_TicketNum = lEditTrainNumUpdateTicket->text();
    QString tN_TicketPrice = lEditTrainNumUpdatePrice->text();
    QString tN_Distance = lEditTrainNumDistance->text();


    int ticketNum = tN_TicketNum.toInt();

    if (!(ticketNum == 60 || ticketNum == 120))
    {
        QMessageBox::information(this, CN("提示"), CN("卧铺车车票数需为60，坐铺车车票数需为120"), QMessageBox::Ok);
        return;
    }
    if (tN_Id.isEmpty()
        || t_Id.isEmpty()
        || tN_SStation.isEmpty()
        || tN_EStation.isEmpty()
        || tN_TicketNum.isEmpty()
        || tN_TicketPrice.isEmpty()
        || tN_Distance.isEmpty()
        )
    {
        //弹出警告消息框
        QMessageBox::warning(this, CN("注意"),CN("开通车次请输入完整信息"),QMessageBox::Ok);
        return;
    }


    ModelTrainNumber modelTrainNumber;
    modelTrainNumber.TN_Id(tN_Id);
    modelTrainNumber.T_Id(t_Id);
    modelTrainNumber.TN_SStation(tN_SStation);
    modelTrainNumber.TN_EStation(tN_EStation);
    modelTrainNumber.TN_STime(tN_STime);
    modelTrainNumber.TN_ETime(tN_ETime);
    modelTrainNumber.TN_TicketNum(tN_TicketNum);
    modelTrainNumber.TN_TicketPrice(tN_TicketPrice);
    modelTrainNumber.TN_Distance(tN_Distance);


    Factory factory;
    if (factory.logicTrainNumber->Update(modelTrainNumber))
    {
        GetTrainNumList();
    }
}

void GUIAdmin::DeleteTrainNumClicked()//移除车次
{
    QString removeTN_Id=this->tabWTrainNum->item(this->tabWTrainNum->currentRow(),0)->text();
    Factory factory;
    if (factory.logicTrainNumber->Delete(removeTN_Id))
    {
        GetTrainNumList();
    }

}
void GUIAdmin::UpdateTrainComBox()//更新车表数据
{
    comBoxNumUpdateTrain->clear();
    for (int i = 0; i < this->tabTrainInfrom->rowCount();i++)
    {
        comBoxNumUpdateTrain->addItem(tabTrainInfrom->item(i,0)->text());
    }
}
void GUIAdmin::GetTrainList()//显示列车表
{

    Factory factory;
    QVector<ModelTrain> trainList;//ModelTrain类的对象数组
    trainList = factory.logicTrain->GetList();
    if (trainList.isEmpty())
    {
        tabTrainInfrom->clear();
        this->tabTrainInfrom->setColumnCount(0);
        this->tabTrainInfrom->setRowCount(0);
        return;
    }
    QStringList trainInfromHeader;
    trainInfromHeader << CN("列车编号") << CN("列车类型") << CN("车座类型");

    int  trainListRow = trainList.count();
    this->tabTrainInfrom->setColumnCount(3);
    this->tabTrainInfrom->setRowCount(trainListRow);
    this->tabTrainInfrom->setHorizontalHeaderLabels(trainInfromHeader);

    for (int i = 0; i < trainListRow;i++)
    {
        this->tabTrainInfrom->setItem(i, 0, new QTableWidgetItem());
        this->tabTrainInfrom->setItem(i, 1, new QTableWidgetItem());
        this->tabTrainInfrom->setItem(i, 2, new QTableWidgetItem());

        tabTrainInfrom->item(i, 0)->setText(trainList[i].T_Id());
        tabTrainInfrom->item(i, 1)->setText(trainList[i].T_Type());
        tabTrainInfrom->item(i, 2)->setText(trainList[i].T_SeatType());

    }
    UpdateTrainComBox();

}
void GUIAdmin::AddTrainClicked()
{
    QString newTrainId = this->lEdiTrainInfromId->text();
    if (newTrainId.isEmpty())
    {
        return;
    }

    ModelTrain modelTrain;
    modelTrain.T_Id(newTrainId);
    modelTrain.T_Type(comBoxTrainInfromType->currentText());
    modelTrain.T_SeatType(comBoxTrainInfromSeatType->currentText());

    Factory factory;
    if (factory.logicTrain->Insert(modelTrain))
    {
        GetTrainList();
    }
}
void GUIAdmin::DeleteTrainClicked()
{
    QString currentT_Id = this->tabTrainInfrom->item(this->tabTrainInfrom->currentRow(),0)->text();
    Factory factory;
    if (factory.logicTrain->Delete(currentT_Id))
    {
        GetTrainList();
    }
}
GUIAdmin::~GUIAdmin(){}
