#ifndef SWITCHWINDOW_H
#define SWITCHWINDOW_H

#include <QMainWindow>
#include <QProcess>
//#include <QCloseEvent>
#include <QFileInfo>
#include "notepadform.h"
#include <QtNetwork>

#define WINDOW_WIDTH (658)
#define WINDOW_YPOS (220)

namespace Ui {
class SwitchWindow;
}

class SwitchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SwitchWindow(QString appname, QWidget *parent = 0);
    ~SwitchWindow();

    QString AppName;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void subsystem_finished_0(int);
    void subsystem_finished_1(int);
    void subsystem_finished_2(int);

    void on_pushButton_5_clicked();

    void on_pushButton_Sync_clicked();

private:
    QFileInfo fileInfo;
    Ui::SwitchWindow *ui;
    QProcess *qp[3];

    NotepadForm notepad;

    QUdpSocket *udp_skt;
};

#endif // SWITCHWINDOW_H
