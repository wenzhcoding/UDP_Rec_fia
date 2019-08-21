#include "loadconf_sqlit.h"
#include <QDebug>
#include <QFileInfo>

void LoadConf_sqlit::creatConnectionByName(const QString &connectionName)
{
    bool exist_flag=true;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",connectionName); //添加数据库驱动
    QFileInfo db_file("./"+connectionName+".db");

    if(!db_file.exists()){  //数据库不存在,则创建
        qDebug()<<db_file.path();
        exist_flag=false;
    }

    db.setDatabaseName("./"+connectionName+".db");  //设置数据库路径
    if(!db.open()){
        qDebug()<<"failed to open.";
    }
    sql_name=connectionName;

    if(exist_flag==false){
        this->creat_table();      //创建数据库
        qDebug()<<"creat database and table.";
    }
}

QSqlDatabase LoadConf_sqlit::getConnection()
{
    return QSqlDatabase::database(this->sql_name);
}

bool LoadConf_sqlit::get_value(QString table, QString column, QString name, float *rtn)
{
    QSqlQuery query(getConnection());
    QString find="select "+ column +",value from " + table +" where " + column + "=='"+name+"'";
    //qDebug()<<find;
    query.exec(find);
    if(query.next()){
        float value = query.value(1).toDouble();
        *rtn=value;
        return true;
    }
    else{
        qDebug()<<"db no data.";
        return false;
    }
}

void LoadConf_sqlit::set_table(QString table)
{
    this->table=table;
}

void LoadConf_sqlit::creat_table()
{
    QSqlQuery query(getConnection());
    ///calibration
    query.exec("create table calibration(field varchar primary key,value double)");
    query.exec("insert into calibration values('flux_gain',600)");
    query.exec("insert into calibration values('flux_bias',0)");
    query.exec("insert into calibration values('pressure_gain',35)");
    query.exec("insert into calibration values('pressure_bias',0)");
    ///pid
    query.exec("create table pid(field varchar primary key,value double)");
    query.exec("insert into pid values('flux_p',0.05)");
    query.exec("insert into pid values('flux_i',0.9)");
    query.exec("insert into pid values('pressure_p',0.3)");
    query.exec("insert into pid values('pressure_i',1.0)");
}

void LoadConf_sqlit::set_value(QString table, QString column, QString name, float value)
{
    QSqlQuery query(getConnection());
    QString update="update "+ table + " set value=" + QString::number(value) +" where "+column+"=='"+name+"'";
    qDebug()<<update;
    query.exec(update);
}

LoadConf_sqlit::~LoadConf_sqlit()
{
    ;
}
