#include "controlparameter.h"

void ControlParameter::setWaveform(char mode, float min, float max, float length)
{
    waveMode=mode;
    waveMin=min;
    waveMax=max;
    waveLength=length;
    qDebug()<<"set wave:"<<mode<<" min:"<<min<<" max:"<<max<<" length:"<<length;
}

char ControlParameter::getPkgId()
{
    return this->pkgId;
}

void ControlParameter::updatePkgId()
{
    pkgId++;
    if(pkgId>'z'){
        pkgId='0';
    }

    //以下协议来自于史前CVI上位机。
    datagram_command.clear();
    datagram_command.append(QString("%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15%16%17")
                .arg(QString::number(this->p),9,'0')
                .arg(QString::number(this->i),9,'0')
                .arg(QString::number(this->d),9,'0')
                .arg(QString::number(this->waveMin),9,'0')
                .arg(QString::number(this->waveMax),9,'0')
                .arg(QString::number(this->waveLength),9,'0')
                .arg(QString::number(this->cali_para[ControlParameter::CALI_PARA::PRESSURE][1]),9,'0')   //bias
                .arg(QString::number(this->cali_para[ControlParameter::CALI_PARA::PRESSURE][0]),9,'0')   //gain
                .arg(QString::number(this->cali_para[ControlParameter::CALI_PARA::FLUX][1]),9,'0')   //bias
                .arg(QString::number(this->cali_para[ControlParameter::CALI_PARA::FLUX][0]),9,'0')   //gain
                .arg(QString::number(0),9,'0')
                .arg(QString::number(0),9,'0')
                .arg(getWaveMode())
                .arg(isControlQ()?'1':'0')
                .arg('1')   //run system
                .arg(isCloseLoop()?'0':'1')
                .arg(getPkgId())
               );
}

QByteArray ControlParameter::datagram(){
    //qDebug()<<datagram_command;
    return datagram_command;
}

/*
///打印bytearray
//    int i;
//    char *p=ctrlpara->datagram().data();
//    char s[100]={0};
//    for(i=0;i<ctrlpara->datagram().length();i++){
//        sprintf(s+strlen(s),"i%d=%02x ",i,p[i]&0xff);
//    }
//    qDebug()<<s;

///新协议
//    datagram_command[pos++]=0x99;   //帧头                             0
//    datagram_command[pos++]=0x02;   //帧类型                           1
//    datagram_command[pos++]=RUN;   //状态控制                           2
//    datagram_command[pos++]=controlObject_Q;    //对象                  3
//        datagram_command[pos++]=((quint8)(sv()>>8&0xff));   //目标高八位     4
//        datagram_command[pos++]=((quint8)(sv()&0xff));      //目标低八位     5
//        datagram_command[pos++]=((quint8)(p>>8&0xff));//P高八位             6
//        datagram_command[pos++]=((quint8)(p&0xff));   //P低八位             7
//        datagram_command[pos++]=((quint8)(i>>8&0xff));//I高八位             8
//        datagram_command[pos++]=((quint8)(i&0xff));   //I低八位             9
//        datagram_command[pos++]=((quint8)(d>>8&0xff));//D高八位             10
//        datagram_command[pos++]=((quint8)(d&0xff));  //D低八位              11
//    datagram_command[pos++]=isCloseLoop();         //开闭环               12
*/
