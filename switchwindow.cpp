#include "switchwindow.h"
#include "ui_switchwindow.h"
#include <QFileInfo>
#include <QMessageBox>


SwitchWindow::SwitchWindow(QString appname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SwitchWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowTitleHint);
    this->move(0,10);
    this->setFixedSize(this->size());
    ui->pushButton_3->setVisible(false);

    qp[0] = new QProcess();
    connect(qp[0],SIGNAL(finished(int)),this,SLOT(subsystem_finished_0(int)));
    qp[1] = new QProcess();
    connect(qp[1],SIGNAL(finished(int)),this,SLOT(subsystem_finished_1(int)));
    qp[2] = new QProcess();
    connect(qp[2],SIGNAL(finished(int)),this,SLOT(subsystem_finished_2(int)));

    udp_skt=new QUdpSocket(this);

    if(appname!="")
    {
        AppName = appname;
        fileInfo.setFile(AppName);

        //打开所有的窗口
        emit on_pushButton_clicked();
        emit on_pushButton_2_clicked();
        emit on_pushButton_5_clicked();

    }
}

SwitchWindow::~SwitchWindow()
{
    notepad.close();
    delete ui;
}

void SwitchWindow::on_pushButton_clicked()
{

    //QMessageBox::information(this,"path",fileInfo.fileName() + " 1");
    qp[0]->start( fileInfo.fileName() + " 1");
    ui->pushButton->setEnabled(false);
}


void SwitchWindow::on_pushButton_2_clicked()
{
    qp[1]->start(fileInfo.fileName() + " 2");
    ui->pushButton_2->setEnabled(false);
}

void SwitchWindow::on_pushButton_3_clicked()
{
    qp[2]->start(fileInfo.fileName() + " 3");
    ui->pushButton_3->setEnabled(false);
}

void SwitchWindow::subsystem_finished_0(int)
{
    ui->pushButton->setEnabled(true);
}
void SwitchWindow::subsystem_finished_1(int)
{
    ui->pushButton_2->setEnabled(true);
}
void SwitchWindow::subsystem_finished_2(int)
{
    ui->pushButton_3->setEnabled(true);
}

void SwitchWindow::on_pushButton_4_clicked()
{
    delete qp[0];
    delete qp[1];
    delete qp[2];
    notepad.close();
    this->close();
}


void SwitchWindow::on_pushButton_5_clicked()
{
    notepad.show();
    notepad.move(WINDOW_WIDTH*2+30,WINDOW_YPOS);
}

void SwitchWindow::on_pushButton_Sync_clicked()
{
    const char START_CODE[1]={0x56};
    QHostAddress ip_Tx=QHostAddress("127.0.0.1");
    int ip_txPort=32869;
    udp_skt->writeDatagram(QByteArray(START_CODE),ip_Tx,ip_txPort);
    ip_txPort=32870;
    udp_skt->writeDatagram(QByteArray(START_CODE),ip_Tx,ip_txPort);
}
