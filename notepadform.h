#ifndef NOTEPADFORM_H
#define NOTEPADFORM_H

#include <QWidget>

namespace Ui {
class NotepadForm;
}

class NotepadForm : public QWidget
{
    Q_OBJECT

public:
    explicit NotepadForm(QWidget *parent = 0);
    ~NotepadForm();

    const QString TxtFilePath="./notepad.txt";

private slots:
    void on_pushButton_reload_ori_clicked();

    void on_pushButton_write_clicked();

private:
    Ui::NotepadForm *ui;
    void LoadTxt(QString filePath);
    void WriteTxt(QString filePath);
};

#endif // NOTEPADFORM_H
