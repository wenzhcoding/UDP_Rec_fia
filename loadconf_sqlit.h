#ifndef LOADCONF_SQLIT_H
#define LOADCONF_SQLIT_H

#include <QtSql>

class LoadConf_sqlit{
public:
    ~LoadConf_sqlit();

    void creatConnectionByName(const QString &connectionName);
    //QSqlDatabase getConnectionByName(const QString &connectionName)
    //{
    //    return QSqlDatabase::database(connectionName);
    //}
    QSqlDatabase getConnection();

    bool get_value(QString table, QString column, QString name, float *rtn);
    void set_value(QString table, QString column, QString name, float value);
    void set_table(QString table);

    bool check()
    {
        //QSqlDatabase db=getConnection(sql_name);
        //db.
        return true;
    }

private:
    QString sql_name;
    QString table,column,name;
    void creat_table();

};

#endif // LOADCONF_SQLIT_H
