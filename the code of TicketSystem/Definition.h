//全部代码已经保存为UTF-8

#ifndef TICKETSYSTEM_QT5
#define TICKETSYSTEM_QT5
#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QString>




//Qt5字符集定义：

#ifndef QT5_TEXTCODE_VS
#define QT5_TEXTCODE_VS
#define CN(QString) QStringLiteral(QString)
#endif


//数据库定义 使用SQLite3
#ifndef TICKETSYSTEM_DATABASE
#define TICKETSYSTEM_DATABASE
//SQLite3数据库文件地址
#define DATABASE_ADDRESS CN("C:/TicketSystemDB.db")

#endif


#endif
