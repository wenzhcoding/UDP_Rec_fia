#ifndef CONTROLPARAMETER_H
#define CONTROLPARAMETER_H
#include <QDebug>
#include <QByteArray>


class PID{
public:
    PID(){
        p=0;i=0;d=0;
    }
    PID(float _p,float _i,float _d){
        p=_p;i=_i;d=_d;
    }
    void setPara(float _p,float _i,float _d){
        p=_p;i=_i;d=_d;
        qDebug()<<"set pid para:"<<p<<" "<<i<<" "<<d;
    }
    void setP(float _p){p=_p;}
    void setI(float _i){i=_i;}
    void setD(float _d){d=_d;}

protected:
    float p,i,d;

};

class ControlParameter : public PID{
protected:

    bool controlObject_Q;
    float sv_manual,sv_auto;
    bool manual;
    bool closeLoop;
//  PID pid_s;
    QByteArray datagram_command;
    char waveMode='0';
    float waveMin,waveMax,waveLength;

    char pkgId='0';
public:
    enum STATE{
        IDLE=1,
        STOP,
        RUN,
        EMERENCY_ZERO_OUTPUT,
        EMERENCY_THROAT_OPEN
    };
    enum MODE{
        AUTO=false,
        MANUAL=true
    };
    enum CTRL_OBJECT{
        Q=true,
        P=false
    };
    enum CALI_PARA{
        PRESSURE=0,
        FLUX=1,
        GAIN=0,
        BIAS=1
    };

    float cali_para[2][2];    //两个传感器,两个参数(Gain\Bias)

    ControlParameter(float _p,float _i,float _d,bool _controlObject_Q,float _sv,bool _closeLoop){
        PID::setPara(_p,_i,_d);
        controlObject_Q=_controlObject_Q;
        setSv(_sv,true);
        closeLoop=_closeLoop;
        datagram_command.fill(20,char(0));
    }
    void setPara(float _p,float _i,float _d,bool _controlObject_Q){
        PID::setPara(_p,_i,_d);
        controlObject_Q=_controlObject_Q;
    }
    //void setPara(int _p,int _i,int _d){pid_s.setPara(_p,_i,_d);}
    void setSv(float _sv, bool isManual){
        if(isManual==MANUAL) sv_manual=_sv;
        else sv_auto=_sv;
    }
    void setManual(bool _manual){manual=_manual;}
    void setObject(bool _controlObject_Q){controlObject_Q=_controlObject_Q;}
    void setCloseLoop(bool _closeLoop){closeLoop=_closeLoop;}
    void setWaveform(char mode, float min, float max, float length);

    float sv(){
        if(manual==MANUAL) return sv_manual;
        else return sv_auto;
    }
    bool isCloseLoop(){return closeLoop;}
    bool isManual(){return manual;}
    bool isControlQ(){return controlObject_Q;}
    char getWaveMode(){return waveMode;}

    char getPkgId();
    void updatePkgId();

    QByteArray datagram();

private:

};


#endif // CONTROLPARAMETER_H
