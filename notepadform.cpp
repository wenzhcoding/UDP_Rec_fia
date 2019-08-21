#include "notepadform.h"
#include "ui_notepadform.h"
#include <QDebug>

#include <QFile>
#include <QTextStream>
#include <QTextBlock>

NotepadForm::NotepadForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotepadForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    LoadTxt(TxtFilePath);
}

NotepadForm::~NotepadForm()
{
    delete ui;
}

void NotepadForm::LoadTxt(QString filePath)
{
    QFile *file=new QFile(filePath);
    //QTextCodec *codec=QTextCodec::codecForName("GB2312");
    if(file->open(QIODevice::ReadOnly|QIODevice::Text))
    {
        //QTextStream floStream(file);
        //floStream.setCodec(codec);
        //QString data;
        //while(!floStream.atEnd())
        //{
        //    data+=codec->fromUnicode(floStream.readLine());;
        //}
        //ui->textEdit->setText(data);
        ui->textEdit->setText(QString::fromLocal8Bit(file->readAll()));
    }
    file->close();
    delete file;

}

void NotepadForm::WriteTxt(QString filePath)
{
    QFile *file=new QFile(filePath);
    if(file->open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream out(file);
        QTextDocument *document=Q_NULLPTR;
        QTextBlock textBlock;
        document=ui->textEdit->document();
        for(textBlock=document->begin();textBlock!=document->end();textBlock=textBlock.next()){
            qDebug()<<textBlock.text();
            out<<textBlock.text()<<"\n";
        }
        //delete document;
    }
    file->close();
    delete file;
}

void NotepadForm::on_pushButton_reload_ori_clicked()
{
    LoadTxt("./ori_note.txt");
}

void NotepadForm::on_pushButton_write_clicked()
{
    WriteTxt(TxtFilePath);
}
