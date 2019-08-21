#include "mainwindow.h"
#include "switchwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwitchWindow *w_switch;
    MainWindow *w1,*w2,*w3;
    if(argc==1){
        w_switch = new SwitchWindow(QString(argv[0]));
        w_switch->show();
    }
    else if(argc==2){
        //QMessageBox::information(this,"info",argv[1][0]);
        if(argv[1][0]=='1'){
            w1 = new MainWindow(32768,"左系统",32869);
            w1->move(0,WINDOW_YPOS);
            w1->show();
        }
        else if(argv[1][0]=='2'){
            w2 = new MainWindow(32769,"右系统",32870);
            w2->move(WINDOW_WIDTH+20,WINDOW_YPOS);
            w2->show();
        }
        else if(argv[1][0]=='3'){
            w3 = new MainWindow(32770,"飞控系统",32871);
            w3->move(WINDOW_WIDTH*2+20,WINDOW_YPOS);
            w3->show();
        }
    }

    return a.exec();
}
