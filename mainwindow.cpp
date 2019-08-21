#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QRadioButton>
#include <vector>
#include <QSignalMapper>
#include <cmath>
#include <QDebug>

#define USER_DEFINE_INDEX 3
#define EXPERIMENT_TAB    2
#define WAVEFORM_SLOPE    0

MainWindow::MainWindow(const int PORT, const QString Name, const int CMD_PORT, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    WindowName=Name;
    setWindowTitle(WindowName);
    IniFilePath="d:/"+WindowName+".auto";

    ctrlpara = new ControlParameter(ui->doubleSpinBox_p->value(),ui->doubleSpinBox_i->value(),ui->doubleSpinBox_d->value(),ui->radioButton_Q->isChecked(),0,ui->checkBox_closeLoop->isChecked());
    ctrlpara->setManual(ControlParameter::MANUAL);

    UDP_PORT=PORT;
    udp_skt=new QUdpSocket(this);
    udp_skt->bind(UDP_PORT,QUdpSocket::ShareAddress);
    connect(udp_skt,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
    ui->label_port->setText(QString::number(UDP_PORT,10));

    UDP_CMD_PORT=CMD_PORT;
    udp_cmd_skt=new QUdpSocket(this);
    udp_cmd_skt->bind(UDP_CMD_PORT,QUdpSocket::ShareAddress);
    connect(udp_cmd_skt,SIGNAL(readyRead()),this,SLOT(processUDPCmd()));

    rec_cnt=0;

    open_document();

    selector=false;

    QPB_graph_Init();
    ui->radioButton_5V->setChecked(true);
    Timer_Init();

    ui->label_timer_state->setText("running..");

    ui->radioButton_Manual->setChecked(true);

    ui->checkBox_closeLoop->setChecked(false);

    ui->tabWidget->setTabEnabled(EXPERIMENT_TAB,false);

    ///read database
    db_sql.creatConnectionByName(QString::number(UDP_PORT));    //打开数据库连接
    {
        float db_value=0;
        int value_cnt=0;
        ///cali
        if(db_sql.get_value("calibration","field","flux_gain",&db_value)){
            ui->doubleSpinBox_cali_Q_gain->setValue(db_value);
            value_cnt++;
        }
        if(db_sql.get_value("calibration","field","flux_bias",&db_value)){
            ui->doubleSpinBox_cali_Q_bias->setValue(db_value);
            value_cnt++;
        }
        if(db_sql.get_value("calibration","field","pressure_gain",&db_value)){
            ui->doubleSpinBox_cali_P_gain->setValue(db_value);
            value_cnt++;
        }
        if(db_sql.get_value("calibration","field","pressure_bias",&db_value)){
            ui->doubleSpinBox_cali_P_bias->setValue(db_value);
            value_cnt++;
        }
        ///pid
        if(db_sql.get_value("pid","field","pressure_p",&db_value)){
            ui->doubleSpinBox_save_pressure_p->setValue(db_value);
            value_cnt++;
        }
        if(db_sql.get_value("pid","field","pressure_i",&db_value)){
            ui->doubleSpinBox_save_pressure_i->setValue(db_value);
            value_cnt++;
        }
        if(db_sql.get_value("pid","field","flux_p",&db_value)){
            ui->doubleSpinBox_save_flux_p->setValue(db_value);
            value_cnt++;
        }
        if(db_sql.get_value("pid","field","flux_i",&db_value)){
            ui->doubleSpinBox_save_flux_i->setValue(db_value);
            value_cnt++;
        }

        if(value_cnt!=8){
            qDebug()<<"db read error.";
        }

    }

    emit on_radioButton_Manual_toggled(true);
    emit on_radioButton_Q_toggled(true);
    emit on_pushButton_confirm_all_clicked();

    qDebug()<<"construct done.";
}

void MainWindow::QPB_graph_Init()
{
    float range[2]={-3,50};

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setRange(22.0,0);
    //ui->customPlot->xAxis->setRange(0,31.5);
    ui->customPlot->xAxis->setLabel("s");
    ui->customPlot->yAxis->setRange(range[0],range[1]);
    //ui->customPlot->yAxis2->setRange(20*range[0]/65536,20*range[1]/65536);
    //ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis->setLabel("value");
    //ui->customPlot->yAxis2->setLabel("voltage(V)");
    ui->customPlot->graph(0)->setPen(QPen(QColor(255,0,0)));

    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(QColor(0,255,0)));

    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(QPen(QColor(180,80,255)));

    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setPen(QPen(QColor(0,0,255)));


    int i;
    for(i=0;i<4;i++)
    {
        y[i].resize(DRAW_WIDTH);
    }
    x.resize(DRAW_WIDTH);
    for(i=0;i<DRAW_WIDTH;i++)
    {
//        x[DRAW_WIDTH-1-i]=i*0.0315;     //横坐标
        x[i] = i*0.0220;
    }
}

void MainWindow::open_document()
{
    //save data
    //file = new QFile("D:/data_"+QString::number(UDP_PORT));
    saveSamplePath="D:/data_"+WindowName;
    file = new QFile(saveSamplePath);
    ui->label_curPath->setText(saveSamplePath);

    if(!file->open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"warning","cannot open",QMessageBox::Yes);
        this->close();
    }
    out = new QTextStream(file);

    //read config
    iniFile=new readIni(IniFilePath);
}

void MainWindow::Timer_Init()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this,SLOT(timerUpdate()));
    timer->start(0.1);
    //timer->setInterval(0.01);

    timer_sendcommand = new QTimer(this);
    connect(timer_sendcommand, SIGNAL(timeout()),
            this,SLOT(timerUpdate_sendcommand()));
    timer_sendcommand->setInterval(500);
    timer_sendcommand->start();
}

void MainWindow::timerUpdate()
{
    if(selector==true)
    {
        draw_customplot(ui->customPlot,&datagram[1]);
    }
    else
    {
        draw_customplot(ui->customPlot,&datagram[0]);
    }
}

void MainWindow::sendCommand()
{
    if(UDP_PORT==32768){
    QHostAddress ip_Tx=QHostAddress("192.168.0.2");
    int ip_txPort=UDP_PORT;
    udp_skt->writeDatagram(ctrlpara->datagram(),ip_Tx,ip_txPort);

//    int i;
//    char *p=ctrlpara->datagram().data();
//    char s[400]={0};
//    for(i=0;i<ctrlpara->datagram().length();i++){
//        sprintf(s+strlen(s),"i%d=%02x ",i,p[i]&0xff);
//    }
//    qDebug()<<s;
    }
       else if(UDP_PORT==32769){
       QHostAddress ip_Tx=QHostAddress("192.168.0.3");
       int ip_txPort=UDP_PORT;
       udp_skt->writeDatagram(ctrlpara->datagram(),ip_Tx,ip_txPort);

    }
}

void MainWindow::timerUpdate_sendcommand()
{
    if(ctrlpara->isManual()==ControlParameter::AUTO){
        float rtn;
        if(iniFile->getNextNumber(&rtn)){
            ctrlpara->setSv(rtn,ControlParameter::AUTO);
            //任意波形全靠这一句
            ctrlpara->setWaveform(WAVEFORM_SLOPE+'0',    //slope
                              previous_ini,
                              rtn,
                              0.3);
            previous_ini=rtn;
            ctrlpara->updatePkgId();
            qDebug("auto=%f",ctrlpara->sv());
        }
        else{
            ctrlpara->setManual(ControlParameter::MANUAL);
            ctrlpara->setSv(0,ControlParameter::MANUAL);
            if(iniFile->reopen()){
                qDebug()<<"reopen done.";
            }
            ui->radioButton_Manual->setChecked(true);
            ui->doubleSpinBox_manualCtrl->setValue(0);
        }
    }
    //qDebug("%s",ctrlpara->isManual()?"manual":"auto");
    sendCommand();
}

MainWindow::~MainWindow()
{
    file->close();
    udp_skt->close();
    iniFile->close();
    delete ui;
}

void MainWindow::processPendingDatagram()//处理UDP接收
{
    QByteArray *read_buf;
    read_buf=(selector==true)?&datagram[0]:&datagram[1];     //write [0] when true

    while(udp_skt->hasPendingDatagrams())
    {
        read_buf->resize(udp_skt->pendingDatagramSize());
        udp_skt->readDatagram(read_buf->data(),read_buf->size());

        ui->label->setText("接收帧数：\n" + QString::number(rec_cnt++));

        selector=!selector;
        should_draw=true;
    }
}

void MainWindow::processUDPCmd()
{
    QByteArray command;

    while(udp_cmd_skt->hasPendingDatagrams())
    {
        command.resize(udp_cmd_skt->pendingDatagramSize());
        udp_cmd_skt->readDatagram(command.data(),command.size());
        if(command.at(0)==0x56){
            qDebug()<<"Go processUDPCmd 0x56";
            emit on_pushButton_confirm_all_clicked();
        }
    }
}

void MainWindow::draw_customplot(QCustomPlot *customPlot, QByteArray *draw_data)    //画图
{
    if(draw_data->size()<1000)
    {
        //static int err_pkg_cnt=0;
        //qDebug()<<draw_data->size()<<"  cnt="<<err_pkg_cnt++;
        return ;
    }

    if(should_draw==false) return;
    else should_draw=false;

    //const int size = 1000;//draw_data->size();   996=(6channel*2byte)*(83data)
    int i,x_cord=0;
    QVector<double> y_local[CHANNEL_NUM]; // initialize with entries 0..100
    float channel[4];

    for(i=0;i<CHANNEL_NUM;i++)
    {
        //y_local[i].resize(size/CHANNEL_NUM/2);
        y_local[i].resize(1);
    }
    //for(i=0;i<size;i+=8)
    for(i=0;i<1;i+=8)
    {
        channel[0]=digi_to_flux((qint32)((draw_data->at(i+0)&0xff)|((draw_data->at(i+1)<<8)&0xff00)));    //流量计脉宽->流量(L/min)
        channel[1]=(float)((qint16)((draw_data->at(i+2)&0xff)|((draw_data->at(i+3)<<8)&0xff00)))/50.f;    //sv  //channel[1]=s((qint16)((draw_data->at(i+2)&0xff)|((draw_data->at(i+3)<<8)&0xff00)))
        channel[2]=digi_to_pressure((qint16)((draw_data->at(i+4)&0xff)|((draw_data->at(i+5)<<8)&0xff00)));//压力滤波 //channel[2]=(qint16)((draw_data->at(i+4)&0xff)|((draw_data->at(i+5)<<8)&0xff00));
        channel[3]=(float)((qint32)((draw_data->at(i+6)&0xff)|((draw_data->at(i+7)<<8)&0xff00)))*5/65536.f;    //PID结果(Volt)
        y_local[0][x_cord]=channel[0];
        y_local[1][x_cord]=channel[1];
        y_local[2][x_cord]=channel[2];
        y_local[3][x_cord]=channel[3];
        x_cord++;

        if(ui->checkBox_output->isChecked())
        {
            for(int j=0;j<4;j++)
            {
                (*out)<<QString::number(channel[j])<<"\t";
            }
            (*out)<<"\n";
            out->flush();
        }
    }

    for(i=0;i<CHANNEL_NUM;i++)
    {
        //y[i].remove(0,size/CHANNEL_NUM/2);
        y[i].remove(0,1);
        y[i].append(y_local[i]);
    }

    /////////////////////丢帧处理//////////////////////////
    if(y[0].length()>100){
        if(fabs(y[0].at(y[0].length()-1)*2-y[0].at(y[0].length()-2))<0.9){
            y[0][y[0].length()-1]=y[0].at(y[0].length()-2);
        }
    }
    /////////////////////end//////////////////////////

    if(ui->checkBox->isChecked()){
        customPlot->graph(0)->setData(x, y[0]);
        customPlot->graph(0)->setVisible(true);
    }else{
        customPlot->graph(0)->setVisible(false);
    }
    if(ui->checkBox_2->isChecked()){
        customPlot->graph(1)->setData(x, y[1]);
        customPlot->graph(1)->setVisible(true);
    }else{
        customPlot->graph(1)->setVisible(false);
    }
    if(ui->checkBox_3->isChecked()){
        customPlot->graph(2)->setData(x, y[2]);
        customPlot->graph(2)->setVisible(true);
    }else{
        customPlot->graph(2)->setVisible(false);
    }
    if(ui->checkBox_4->isChecked()){
        customPlot->graph(3)->setData(x, y[3]);
        customPlot->graph(3)->setVisible(true);
    }else{
        customPlot->graph(3)->setVisible(false);
    }
    //customPlot->rescaleAxes();
    customPlot->replot();

    //ui->label_2->setText("当前帧数据量(Bytes):\n" + QString::number(draw_data->size()));
    ui->label_Q->setText(channel[0]<600?(QString::number(channel[0])):"---");
    //ui->label_P->setText(QString::number((channel[2]*10.f/32768.f*1.1111f-2)*35/8) + "\n" + QString::number(channel[2]*10.f/32768.f*1.11111f) + 'v');
    ui->label_P->setText(QString::number(channel[2]));//+ "\n" + QString::number(channel[2]*10.f/32768.f*1.11111f) + 'v');
}

void MainWindow::on_radioButton_10V_clicked()           //设置plot范围
{
    ui->customPlot->yAxis->setRange(-3, 26);
    //ui->customPlot->yAxis2->setRange(-10,+10);
}

void MainWindow::on_radioButton_5V_clicked()            //设置plot范围
{
    ui->customPlot->yAxis->setRange(-1, 5);
    //ui->customPlot->yAxis2->setRange(-5,+5);
}

void MainWindow::on_pushButton_set_range_clicked()      //设置plot范围
{
    float range[2]={ui->lineEdit_setrange_l->text().toFloat(),ui->lineEdit_setrange_h->text().toFloat()};
    ui->customPlot->yAxis->setRange(range[0],range[1]);
    //ui->customPlot->yAxis2->setRange(20*range[0]/65536,20*range[1]/65536);
}

void MainWindow::on_lineEdit_setrange_l_returnPressed() //设置plot范围
{
    float range[2]={ui->lineEdit_setrange_l->text().toFloat(),ui->lineEdit_setrange_h->text().toFloat()};
    ui->customPlot->yAxis->setRange(range[0],range[1]);
    //ui->customPlot->yAxis2->setRange(20*range[0]/65536,20*range[1]/65536);
    qDebug()<<"set range L";
}

void MainWindow::on_lineEdit_setrange_h_returnPressed() //设置plot范围
{
    float range[2]={ui->lineEdit_setrange_l->text().toFloat(),ui->lineEdit_setrange_h->text().toFloat()};
    ui->customPlot->yAxis->setRange(range[0],range[1]);
    //ui->customPlot->yAxis2->setRange(20*range[0]/65536,20*range[1]/65536);
    qDebug()<<"set range H";
}

void MainWindow::on_pushButton_timerctrl_clicked()  //定时器控制  先不管
{
    if(timer->isActive()){
        timer->stop();
        ui->label_timer_state->setText("stopped.");
    }
    else{
        timer->start();
        ui->label_timer_state->setText("running..");
    }
}

void MainWindow::on_radioButton_Manual_toggled(bool checked)
{
    ui->doubleSpinBox_manualCtrl->setEnabled(checked);//如果手动，则设置输入框可用
    ui->tabWidget->setTabEnabled(EXPERIMENT_TAB,!checked);
}

void MainWindow::on_checkBox_closeLoop_toggled(bool checked)
{
    //下面一行移动到了 confirm_all 按钮
    //ctrlpara->setCloseLoop(checked);    //设置闭环标志
    ui->doubleSpinBox_outputVolt->setEnabled(!checked); //闭环状态下，手动输出电压不可用

    ui->groupBox_Mode->setEnabled(checked); //闭环状态下启用手自动设置。
    ui->groupBox_Object->setEnabled(checked); //闭环状态下启用控制对象设置。

    if(checked==false){
        ui->tabWidget->setTabEnabled(EXPERIMENT_TAB,false);
    }
    else if(ui->radioButton_Auto->isChecked()){
        ui->tabWidget->setTabEnabled(EXPERIMENT_TAB,true);
    }
}

void MainWindow::on_pushButton_load_auto_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
       this,
       "Open Document",
       QDir::currentPath(),
       "auto files (*.auto *.aut);;All files(*.*)");
    if (!filename.isNull()) { //用户选择了文件
       // 处理文件
       QMessageBox::information(this, "Document", "Has document", QMessageBox::Ok | QMessageBox::Cancel);

       iniFile->changePath(filename);   ////iniFile 更新

    } else // 用户取消选择
       QMessageBox::information(this, "Document", "No document", QMessageBox::Ok | QMessageBox::Cancel);
    qDebug()<<"load_auto_path:"<<filename;
}

void MainWindow::on_pushButton_confirm_all_clicked()
{
    //设置PID参数
    ctrlpara->PID::setPara(ui->doubleSpinBox_p->value(),ui->doubleSpinBox_i->value(),ui->doubleSpinBox_d->value());

    //设置标定参数
    ctrlpara->cali_para[ControlParameter::CALI_PARA::PRESSURE]
                    [ControlParameter::CALI_PARA::GAIN]=ui->doubleSpinBox_cali_P_gain->value();   //gain
    ctrlpara->cali_para[ControlParameter::CALI_PARA::PRESSURE]
                    [ControlParameter::CALI_PARA::BIAS]=ui->doubleSpinBox_cali_P_bias->value();   //bias
    ctrlpara->cali_para[ControlParameter::CALI_PARA::FLUX]
                    [ControlParameter::CALI_PARA::GAIN]=ui->doubleSpinBox_cali_Q_gain->value();   //gain
    ctrlpara->cali_para[ControlParameter::CALI_PARA::FLUX]
                    [ControlParameter::CALI_PARA::BIAS]=ui->doubleSpinBox_cali_Q_bias->value();   //bias

    //设置控制对象
    //下面两行来自于 radioButton_Q_toggled 事件
    if(ui->radioButton_Q->isChecked()) ctrlpara->setObject(ControlParameter::Q);   //设置控制对象
    else  ctrlpara->setObject(ControlParameter::P); //设置控制对象

    //设置闭环标志
    //下面一行来自于 closeLoop_toggled 事件
    ctrlpara->setCloseLoop(ui->checkBox_closeLoop->isChecked());    //设置闭环标志

    //选择手动设置值
    if(ctrlpara->isCloseLoop()){   //开环输出电压，闭环输出控制期望值
        //下面两行来自 doubleSpinBox_manualCtrl_editingFinished 事件
        float value=ui->doubleSpinBox_manualCtrl->value();  //获得手动设定值
        ctrlpara->setSv(value,ControlParameter::MANUAL);    //设置手动设定值
    }
    else{
        float value=ui->doubleSpinBox_outputVolt->value();  //获得电压设定值
        ctrlpara->setSv(value,ControlParameter::MANUAL);    //设置电压设定值
    }

    //手自动模式设置
    //只有标签栏2可用且选择了用户定义曲线时,设置为自动
    if(ui->tabWidget->isTabEnabled(EXPERIMENT_TAB)
            && ui->comboBox_waveGen->currentIndex()==USER_DEFINE_INDEX
            && ctrlpara->isCloseLoop()){
        ctrlpara->setManual(ControlParameter::AUTO);
    }
    else{
        ctrlpara->setManual(ControlParameter::MANUAL);
    }
    qDebug("%s",ctrlpara->isManual()?"manual":"auto");

    if(!ctrlpara->isCloseLoop()){   //开环，直接输出电压
        ctrlpara->setWaveform(WAVEFORM_SLOPE+'0',    //slope
                          ui->doubleSpinBox_outputVolt->value(),
                          ui->doubleSpinBox_outputVolt->value(),
                          100);
        qDebug()<<"output voltage read.";
    }
    else{   //闭环
        if(ui->radioButton_Auto->isChecked()){  //启用信号发生器
            ctrlpara->setWaveform((ui->comboBox_waveGen->currentIndex())+'0',
                          ui->doubleSpinBox_min->value(),
                          ui->doubleSpinBox_max->value(),
                          ui->doubleSpinBox_length->value());
        }
        else{   //手动设置控制期望值
            ctrlpara->setWaveform(WAVEFORM_SLOPE+'0',    //slope
                              ui->doubleSpinBox_manualCtrl->value(),
                              ui->doubleSpinBox_manualCtrl->value(),
                              100);
        }
    }
    qDebug()<<"waveMode:"<<ctrlpara->getWaveMode();

    //查找表 LUT
    if(ui->checkBox_closeLoop->isChecked() && ui->checkBox_LUT->isChecked()) ctrlpara->setCloseLoop(false);

    ctrlpara->updatePkgId();
}

void MainWindow::on_comboBox_waveGen_activated(int index)
{
    if(index==USER_DEFINE_INDEX){
        ui->doubleSpinBox_length->setEnabled(false);    //波形发生器长度设置无效
        ui->doubleSpinBox_max->setEnabled(false);       //波形发生器最大值设置无效
        ui->doubleSpinBox_min->setEnabled(false);       //波形发生器最小值设置无效
        ui->pushButton_load_auto->setEnabled(true);     //波形发生器载入预定文件使能
    }
    else{
        ui->doubleSpinBox_length->setEnabled(true);     //波形发生器长度设置使能
        ui->doubleSpinBox_max->setEnabled(true);        //波形发生器最大值设置使能
        ui->doubleSpinBox_min->setEnabled(true);        //波形发生器最小值设置使能
        ui->pushButton_load_auto->setEnabled(false);     //波形发生器载入预定文件无效
    }

    //显示贴心小图像
    QImage img;
    QString img_path="img/"+ui->comboBox_waveGen->currentText()+".png";
    if(ui->comboBox_waveGen->currentText()=="User Define"){img_path="./img/User Define"+QString::number(UDP_PORT)+".png";}
    if(!(img.load(img_path))) //加载图像
    {
        qDebug()<<"img open failed:"<<img_path;
        return;
    }
    else{
        ui->label_wavegen->setPixmap(QPixmap::fromImage(img).scaled(ui->label_wavegen->width(),ui->label_wavegen->height()));
    }
}

void MainWindow::on_pushButton_save_config_clicked()
{
    db_sql.set_value("calibration","field","flux_gain",ui->doubleSpinBox_cali_Q_gain->value());
    db_sql.set_value("calibration","field","flux_bias",ui->doubleSpinBox_cali_Q_bias->value());
    db_sql.set_value("calibration","field","pressure_gain",ui->doubleSpinBox_cali_P_gain->value());
    db_sql.set_value("calibration","field","pressure_bias",ui->doubleSpinBox_cali_P_bias->value());
}

void MainWindow::on_pushButton_save_pid_clicked()
{
    db_sql.set_value("pid","field","flux_p",ui->doubleSpinBox_save_flux_p->value());
    db_sql.set_value("pid","field","flux_i",ui->doubleSpinBox_save_flux_i->value());
    db_sql.set_value("pid","field","pressure_p",ui->doubleSpinBox_save_pressure_p->value());
    db_sql.set_value("pid","field","pressure_i",ui->doubleSpinBox_save_pressure_i->value());
}

float MainWindow::digi_to_pressure(int value)
{
    float voltage=(float)value/3276.7f; //32767.f*10;
    float rtn=(voltage-ctrlpara->cali_para[ControlParameter::CALI_PARA::PRESSURE]
                    [ControlParameter::CALI_PARA::BIAS])*
                       ctrlpara->cali_para[ControlParameter::CALI_PARA::PRESSURE]
                    [ControlParameter::CALI_PARA::GAIN];
    //printf("v=%f b=%f g=%f digi_P=%f\n",voltage,bias,gain,rtn);
    return rtn;
}

float MainWindow::digi_to_flux(int value)
{
    return value/100.f;
}

void MainWindow::on_radioButton_Q_toggled(bool checked) //设置PQ控制的PID参数
{
    float db_value;
    if(checked){    //flux
        if(db_sql.get_value("pid","field","flux_p",&db_value)){
            ui->doubleSpinBox_p->setValue(db_value);
        }
        if(db_sql.get_value("pid","field","flux_i",&db_value)){
            ui->doubleSpinBox_i->setValue(db_value);
        }
        ui->doubleSpinBox_d->setValue(0);
    }
    else{   //pressure
        if(db_sql.get_value("pid","field","pressure_p",&db_value)){
            ui->doubleSpinBox_p->setValue(db_value);
        }
        if(db_sql.get_value("pid","field","pressure_i",&db_value)){
            ui->doubleSpinBox_i->setValue(db_value);
        }
        ui->doubleSpinBox_d->setValue(0);
    }
}

void MainWindow::on_pushButton_swapValue_clicked()
{
    float swap_tmp=ui->doubleSpinBox_min->value();
    ui->doubleSpinBox_min->setValue(ui->doubleSpinBox_max->value());
    ui->doubleSpinBox_max->setValue(swap_tmp);

}

void MainWindow::on_pushButton_chooseSavePath_clicked()
{
    QString filename = QFileDialog::getSaveFileName(
       this,
       "Save Document",
       QDir::currentPath(),
       "auto files (*.auto *.aut);;All files(*.*)");
    if (!filename.isNull()) { //用户选择了文件
       // 处理文件
       QMessageBox::information(this, "Document", "Has document", QMessageBox::Ok | QMessageBox::Cancel);

       //重新打开文件
       if(file->isOpen()){
           file->close();
       }
       delete file;
       file = new QFile(filename);
       if(!file->open(QFile::WriteOnly|QFile::Text))
       {
           QMessageBox::warning(this,"warning","cannot open",QMessageBox::Yes);
           this->close();
           return;
       }
       delete out;
       out = new QTextStream(file);

       saveSamplePath=filename;     //save path 更新
       ui->label_curPath->setText(saveSamplePath);
       qDebug()<<"chooseSavePath:"<<filename;
    } else // 用户取消选择
       QMessageBox::information(this, "Document", "No document", QMessageBox::Ok | QMessageBox::Cancel);
}

void MainWindow::on_checkBox_output_toggled(bool checked)
{
    ui->pushButton_chooseSavePath->setEnabled(!checked);//正在保存的时候不能更改路径
}

void MainWindow::on_pushButton_configAuto_clicked()
{
    //system(QString("notepad D:/auto_"+QString::number(UDP_PORT)).toLatin1());
    system(QString("notepad D:/generator.txt").toLatin1());
}

void MainWindow::on_pushButton_genAuto_clicked()
{
    system("d:/generator.bat"); //执行Matlab文件
}

void MainWindow::on_pushButton_saveConfig_clicked()
{
    QString filename = QFileDialog::getSaveFileName(
       this,
       "Save Document",
       QDir::currentPath(),
       "auto files (*.auto *.aut);;All files(*.*)");
    if (!filename.isNull()) { //用户选择了文件
       // 处理文件
       QMessageBox::information(this, "Document", "Has document", QMessageBox::Ok | QMessageBox::Cancel);
    } else{ // 用户取消选择
       QMessageBox::information(this, "Document", "No document", QMessageBox::Ok | QMessageBox::Cancel);
       return ; //退出
    }

    QDir *creatfile = new QDir;
    bool exist=creatfile->exists(filename);
    if(exist){
        creatfile->remove(filename);
    }
    if(!QFile::copy("D:/data.auto",filename)){
       qDebug()<<"failed to copy auto file.";
    }
    else{
        QString img_path="./img/User Define"+QString::number(UDP_PORT)+".png";
        if(QFile::exists(img_path)){
            QDir rm;
            rm.remove(img_path);
        }
        QFile::copy("D:/user.png",img_path);
        emit on_comboBox_waveGen_activated(ui->comboBox_waveGen->currentIndex());
        qDebug()<<"auto file gen done.";
    }
}

void MainWindow::on_pushButton_clicked()
{
    emit on_checkBox_closeLoop_toggled(false);
    ui->checkBox_closeLoop->setChecked(false);
    ui->doubleSpinBox_outputVolt->setValue(0);
    emit on_pushButton_confirm_all_clicked();
}
