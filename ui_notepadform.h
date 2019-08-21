/********************************************************************************
** Form generated from reading UI file 'notepadform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPADFORM_H
#define UI_NOTEPADFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotepadForm
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton_reload_ori;
    QPushButton *pushButton_write;

    void setupUi(QWidget *NotepadForm)
    {
        if (NotepadForm->objectName().isEmpty())
            NotepadForm->setObjectName(QStringLiteral("NotepadForm"));
        NotepadForm->resize(342, 726);
        textEdit = new QTextEdit(NotepadForm);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 321, 661));
        pushButton_reload_ori = new QPushButton(NotepadForm);
        pushButton_reload_ori->setObjectName(QStringLiteral("pushButton_reload_ori"));
        pushButton_reload_ori->setGeometry(QRect(10, 680, 141, 41));
        pushButton_write = new QPushButton(NotepadForm);
        pushButton_write->setObjectName(QStringLiteral("pushButton_write"));
        pushButton_write->setGeometry(QRect(190, 680, 141, 41));

        retranslateUi(NotepadForm);

        QMetaObject::connectSlotsByName(NotepadForm);
    } // setupUi

    void retranslateUi(QWidget *NotepadForm)
    {
        NotepadForm->setWindowTitle(QApplication::translate("NotepadForm", "\346\217\220\347\244\272\346\235\277", Q_NULLPTR));
        pushButton_reload_ori->setText(QApplication::translate("NotepadForm", "\350\257\273\345\217\226\345\216\237\345\247\213\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_write->setText(QApplication::translate("NotepadForm", "\345\206\231\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NotepadForm: public Ui_NotepadForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPADFORM_H
