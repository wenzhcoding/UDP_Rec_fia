#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QFile>
#include <QTextStream>
#include "qcustomplot.h"
#include <QTimer>
#include <QString>
#include "readini.h"
#include "controlparameter.h"
#include "loadconf_sqlit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const int PORT, const QString Name, const int CMD_PORT, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString WindowName;

    QUdpSocket *udp_skt;
    int UDP_PORT;

    QUdpSocket *udp_cmd_skt;
    int UDP_CMD_PORT;

    long rec_cnt;   //接收计数
    QFile *file;
    QTextStream* out;

    QByteArray datagram[2];
    bool selector;

    QTimer *timer;
    QTimer *timer_sendcommand;

    const int CHANNEL_NUM=4;
    const int  DRAW_WIDTH=1000;
    QVector<double> x;
    QVector<double>y[4]; // initialize with entries 0..100

    readIni *iniFile;

    void open_document();
    void QPB_graph_Init();

    bool should_draw=false;
    void draw_customplot(QCustomPlot *, QByteArray *draw_data);
    int current_yaxis=0;
    void Timer_Init();

    void sendCommand();

    ControlParameter *ctrlpara;
    QByteArray datagram_command;

    QString IniFilePath;

    QString saveSamplePath;    //保存采样数据路径

    bool userDefineFlag=false;
    float previous_ini=0;

    LoadConf_sqlit db_sql;

    float digi_to_pressure(int value);
    float digi_to_flux(int value);

    float previous_flux;

private slots:
    void processPendingDatagram();
    void processUDPCmd();

    void timerUpdate();
    void timerUpdate_sendcommand();
    void on_pushButton_timerctrl_clicked();
    void on_radioButton_10V_clicked();
    void on_radioButton_5V_clicked();
    void on_pushButton_set_range_clicked();
    void on_lineEdit_setrange_l_returnPressed();
    void on_lineEdit_setrange_h_returnPressed();

    void on_radioButton_Manual_toggled(bool checked);
    void on_checkBox_closeLoop_toggled(bool checked);
    void on_pushButton_load_auto_clicked();
    void on_pushButton_confirm_all_clicked();
    void on_comboBox_waveGen_activated(int index);
    void on_pushButton_save_config_clicked();
    void on_radioButton_Q_toggled(bool checked);
    void on_pushButton_swapValue_clicked();
    void on_pushButton_save_pid_clicked();
    void on_pushButton_chooseSavePath_clicked();
    void on_checkBox_output_toggled(bool checked);
    void on_pushButton_configAuto_clicked();
    void on_pushButton_genAuto_clicked();
    void on_pushButton_saveConfig_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
