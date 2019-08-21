/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab_mainPannel;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_Object;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_Q;
    QRadioButton *radioButton_P;
    QCheckBox *checkBox_LUT;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_closeLoop;
    QDoubleSpinBox *doubleSpinBox_outputVolt;
    QLabel *label_9;
    QCustomPlot *customPlot;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_i;
    QDoubleSpinBox *doubleSpinBox_d;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_p;
    QGroupBox *groupBox_7;
    QLabel *label_7;
    QLabel *label_Q;
    QLabel *label_P;
    QLabel *label_8;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_12;
    QLabel *label_timer_state;
    QPushButton *pushButton_timerctrl;
    QLabel *label;
    QPushButton *pushButton_confirm_all;
    QLabel *label_port;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_5V;
    QRadioButton *radioButton_10V;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_setrange_l;
    QLineEdit *lineEdit_setrange_h;
    QPushButton *pushButton_set_range;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_18;
    QCheckBox *checkBox_output;
    QGroupBox *groupBox_Mode;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Manual;
    QRadioButton *radioButton_Auto;
    QDoubleSpinBox *doubleSpinBox_manualCtrl;
    QWidget *tab_sensors;
    QGridLayout *gridLayout_14;
    QLabel *label_24;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_19;
    QPushButton *pushButton_chooseSavePath;
    QLabel *label_curPath;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_15;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_17;
    QDoubleSpinBox *doubleSpinBox_save_flux_i;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_save_flux_p;
    QLabel *label_21;
    QLabel *label_18;
    QLabel *label_22;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_16;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_save_pressure_p;
    QDoubleSpinBox *doubleSpinBox_save_pressure_i;
    QDoubleSpinBox *doubleSpinBox_save_pressure_d;
    QLabel *label_2;
    QLabel *label_20;
    QPushButton *pushButton_save_pid;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_6;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_cali_P_gain;
    QDoubleSpinBox *doubleSpinBox_cali_P_bias;
    QLabel *label_11;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_7;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_cali_Q_bias;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_cali_Q_gain;
    QPushButton *pushButton_save_config;
    QLabel *label_logo_4;
    QLabel *label_17;
    QLabel *label_23;
    QSpacerItem *verticalSpacer;
    QWidget *tab_experiment;
    QGridLayout *gridLayout_13;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_logo_2;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_min;
    QPushButton *pushButton_swapValue;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_max;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBox_length;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_waveGen;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_load_auto;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_20;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_21;
    QPushButton *pushButton_configAuto;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_22;
    QPushButton *pushButton_genAuto;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_23;
    QPushButton *pushButton_saveConfig;
    QLabel *label_wavegen;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(664, 726);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(12);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab_mainPannel = new QWidget();
        tab_mainPannel->setObjectName(QStringLiteral("tab_mainPannel"));
        gridLayout_11 = new QGridLayout(tab_mainPannel);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupBox_Object = new QGroupBox(tab_mainPannel);
        groupBox_Object->setObjectName(QStringLiteral("groupBox_Object"));
        gridLayout_2 = new QGridLayout(groupBox_Object);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton_Q = new QRadioButton(groupBox_Object);
        radioButton_Q->setObjectName(QStringLiteral("radioButton_Q"));
        radioButton_Q->setChecked(true);

        gridLayout_2->addWidget(radioButton_Q, 0, 0, 1, 1);

        radioButton_P = new QRadioButton(groupBox_Object);
        radioButton_P->setObjectName(QStringLiteral("radioButton_P"));

        gridLayout_2->addWidget(radioButton_P, 0, 1, 1, 1);

        checkBox_LUT = new QCheckBox(groupBox_Object);
        checkBox_LUT->setObjectName(QStringLiteral("checkBox_LUT"));

        gridLayout_2->addWidget(checkBox_LUT, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_Object, 3, 3, 1, 1);

        groupBox_6 = new QGroupBox(tab_mainPannel);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBox_closeLoop = new QCheckBox(groupBox_6);
        checkBox_closeLoop->setObjectName(QStringLiteral("checkBox_closeLoop"));
        checkBox_closeLoop->setChecked(true);

        gridLayout_3->addWidget(checkBox_closeLoop, 0, 0, 1, 1);

        doubleSpinBox_outputVolt = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_outputVolt->setObjectName(QStringLiteral("doubleSpinBox_outputVolt"));
        doubleSpinBox_outputVolt->setDecimals(3);
        doubleSpinBox_outputVolt->setMaximum(5);
        doubleSpinBox_outputVolt->setSingleStep(0.05);

        gridLayout_3->addWidget(doubleSpinBox_outputVolt, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 1, 1, 1, 1);


        gridLayout_11->addWidget(groupBox_6, 3, 4, 1, 1);

        customPlot = new QCustomPlot(tab_mainPannel);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);
        customPlot->setMinimumSize(QSize(100, 0));

        gridLayout_11->addWidget(customPlot, 1, 0, 1, 8);

        groupBox_2 = new QGroupBox(tab_mainPannel);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 25, 28, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 54, 28, 16));
        label_5->setFont(font);
        doubleSpinBox_i = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_i->setObjectName(QStringLiteral("doubleSpinBox_i"));
        doubleSpinBox_i->setGeometry(QRect(39, 54, 61, 20));
        doubleSpinBox_i->setDecimals(4);
        doubleSpinBox_i->setMinimum(0);
        doubleSpinBox_i->setSingleStep(0.02);
        doubleSpinBox_d = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_d->setObjectName(QStringLiteral("doubleSpinBox_d"));
        doubleSpinBox_d->setEnabled(true);
        doubleSpinBox_d->setGeometry(QRect(39, 82, 61, 21));
        doubleSpinBox_d->setDecimals(4);
        doubleSpinBox_d->setMinimum(-99);
        doubleSpinBox_d->setSingleStep(0.001);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 83, 16, 16));
        label_6->setFont(font);
        doubleSpinBox_p = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_p->setObjectName(QStringLiteral("doubleSpinBox_p"));
        doubleSpinBox_p->setGeometry(QRect(39, 25, 61, 20));
        doubleSpinBox_p->setDecimals(4);
        doubleSpinBox_p->setMinimum(0);
        doubleSpinBox_p->setSingleStep(0.001);

        gridLayout_11->addWidget(groupBox_2, 2, 3, 1, 1);

        groupBox_7 = new QGroupBox(tab_mainPannel);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 20, 54, 12));
        label_Q = new QLabel(groupBox_7);
        label_Q->setObjectName(QStringLiteral("label_Q"));
        label_Q->setGeometry(QRect(10, 40, 54, 12));
        label_P = new QLabel(groupBox_7);
        label_P->setObjectName(QStringLiteral("label_P"));
        label_P->setGeometry(QRect(10, 80, 81, 41));
        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 70, 54, 12));

        gridLayout_11->addWidget(groupBox_7, 2, 4, 1, 1);

        groupBox_4 = new QGroupBox(tab_mainPannel);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_12 = new QGridLayout(groupBox_4);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_timer_state = new QLabel(groupBox_4);
        label_timer_state->setObjectName(QStringLiteral("label_timer_state"));

        gridLayout_12->addWidget(label_timer_state, 0, 1, 1, 1);

        pushButton_timerctrl = new QPushButton(groupBox_4);
        pushButton_timerctrl->setObjectName(QStringLiteral("pushButton_timerctrl"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_timerctrl->sizePolicy().hasHeightForWidth());
        pushButton_timerctrl->setSizePolicy(sizePolicy2);

        gridLayout_12->addWidget(pushButton_timerctrl, 2, 1, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_12->addWidget(label, 1, 1, 1, 1);


        gridLayout_11->addWidget(groupBox_4, 2, 5, 1, 2);

        pushButton_confirm_all = new QPushButton(tab_mainPannel);
        pushButton_confirm_all->setObjectName(QStringLiteral("pushButton_confirm_all"));
        QFont font1;
        font1.setFamily(QStringLiteral("Aharoni"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_confirm_all->setFont(font1);
        pushButton_confirm_all->setStyleSheet(QStringLiteral("color: rgb(85, 170, 127);"));

        gridLayout_11->addWidget(pushButton_confirm_all, 3, 5, 1, 2);

        label_port = new QLabel(tab_mainPannel);
        label_port->setObjectName(QStringLiteral("label_port"));

        gridLayout_11->addWidget(label_port, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab_mainPannel);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        radioButton_5V = new QRadioButton(groupBox_3);
        radioButton_5V->setObjectName(QStringLiteral("radioButton_5V"));

        horizontalLayout_4->addWidget(radioButton_5V);

        radioButton_10V = new QRadioButton(groupBox_3);
        radioButton_10V->setObjectName(QStringLiteral("radioButton_10V"));

        horizontalLayout_4->addWidget(radioButton_10V);


        gridLayout_10->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        horizontalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setStyleSheet(QStringLiteral("color: rgb(14, 216, 21);"));
        checkBox_2->setChecked(true);

        horizontalLayout_2->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setStyleSheet(QStringLiteral("color: rgb(170, 85, 255);"));
        checkBox_3->setChecked(true);
        checkBox_3->setAutoExclusive(false);

        horizontalLayout_2->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        checkBox_4->setChecked(true);

        horizontalLayout_2->addWidget(checkBox_4);


        gridLayout_10->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_setrange_l = new QLineEdit(groupBox_3);
        lineEdit_setrange_l->setObjectName(QStringLiteral("lineEdit_setrange_l"));

        horizontalLayout_3->addWidget(lineEdit_setrange_l);

        lineEdit_setrange_h = new QLineEdit(groupBox_3);
        lineEdit_setrange_h->setObjectName(QStringLiteral("lineEdit_setrange_h"));

        horizontalLayout_3->addWidget(lineEdit_setrange_h);

        pushButton_set_range = new QPushButton(groupBox_3);
        pushButton_set_range->setObjectName(QStringLiteral("pushButton_set_range"));

        horizontalLayout_3->addWidget(pushButton_set_range);


        gridLayout_10->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_3, 2, 0, 1, 3);

        groupBox_13 = new QGroupBox(tab_mainPannel);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        gridLayout_18 = new QGridLayout(groupBox_13);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        checkBox_output = new QCheckBox(groupBox_13);
        checkBox_output->setObjectName(QStringLiteral("checkBox_output"));

        gridLayout_18->addWidget(checkBox_output, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_13, 3, 0, 1, 1);

        groupBox_Mode = new QGroupBox(tab_mainPannel);
        groupBox_Mode->setObjectName(QStringLiteral("groupBox_Mode"));
        gridLayout = new QGridLayout(groupBox_Mode);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_Manual = new QRadioButton(groupBox_Mode);
        radioButton_Manual->setObjectName(QStringLiteral("radioButton_Manual"));
        radioButton_Manual->setChecked(true);

        horizontalLayout->addWidget(radioButton_Manual);

        radioButton_Auto = new QRadioButton(groupBox_Mode);
        radioButton_Auto->setObjectName(QStringLiteral("radioButton_Auto"));

        horizontalLayout->addWidget(radioButton_Auto);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        doubleSpinBox_manualCtrl = new QDoubleSpinBox(groupBox_Mode);
        doubleSpinBox_manualCtrl->setObjectName(QStringLiteral("doubleSpinBox_manualCtrl"));
        doubleSpinBox_manualCtrl->setMaximum(300.99);

        gridLayout->addWidget(doubleSpinBox_manualCtrl, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_Mode, 3, 1, 1, 2);

        tabWidget->addTab(tab_mainPannel, QString());
        tab_sensors = new QWidget();
        tab_sensors->setObjectName(QStringLiteral("tab_sensors"));
        gridLayout_14 = new QGridLayout(tab_sensors);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_24 = new QLabel(tab_sensors);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_14->addWidget(label_24, 2, 2, 1, 1);

        groupBox_14 = new QGroupBox(tab_sensors);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        gridLayout_19 = new QGridLayout(groupBox_14);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        pushButton_chooseSavePath = new QPushButton(groupBox_14);
        pushButton_chooseSavePath->setObjectName(QStringLiteral("pushButton_chooseSavePath"));

        gridLayout_19->addWidget(pushButton_chooseSavePath, 1, 0, 1, 1);

        label_curPath = new QLabel(groupBox_14);
        label_curPath->setObjectName(QStringLiteral("label_curPath"));

        gridLayout_19->addWidget(label_curPath, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_14, 2, 0, 1, 2);

        groupBox = new QGroupBox(tab_sensors);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_15 = new QGridLayout(groupBox);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        groupBox_12 = new QGroupBox(groupBox);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        gridLayout_17 = new QGridLayout(groupBox_12);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        doubleSpinBox_save_flux_i = new QDoubleSpinBox(groupBox_12);
        doubleSpinBox_save_flux_i->setObjectName(QStringLiteral("doubleSpinBox_save_flux_i"));
        doubleSpinBox_save_flux_i->setDecimals(4);
        doubleSpinBox_save_flux_i->setSingleStep(0.1);

        gridLayout_17->addWidget(doubleSpinBox_save_flux_i, 3, 0, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(groupBox_12);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setEnabled(true);
        doubleSpinBox_6->setDecimals(4);
        doubleSpinBox_6->setSingleStep(0.1);

        gridLayout_17->addWidget(doubleSpinBox_6, 5, 0, 1, 1);

        doubleSpinBox_save_flux_p = new QDoubleSpinBox(groupBox_12);
        doubleSpinBox_save_flux_p->setObjectName(QStringLiteral("doubleSpinBox_save_flux_p"));
        doubleSpinBox_save_flux_p->setDecimals(4);
        doubleSpinBox_save_flux_p->setSingleStep(0.1);

        gridLayout_17->addWidget(doubleSpinBox_save_flux_p, 1, 0, 1, 1);

        label_21 = new QLabel(groupBox_12);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_17->addWidget(label_21, 2, 0, 1, 1);

        label_18 = new QLabel(groupBox_12);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_17->addWidget(label_18, 0, 0, 1, 1);

        label_22 = new QLabel(groupBox_12);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_17->addWidget(label_22, 4, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_12, 0, 1, 1, 1);

        groupBox_11 = new QGroupBox(groupBox);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        gridLayout_16 = new QGridLayout(groupBox_11);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        label_19 = new QLabel(groupBox_11);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_16->addWidget(label_19, 4, 0, 1, 1);

        doubleSpinBox_save_pressure_p = new QDoubleSpinBox(groupBox_11);
        doubleSpinBox_save_pressure_p->setObjectName(QStringLiteral("doubleSpinBox_save_pressure_p"));
        doubleSpinBox_save_pressure_p->setDecimals(4);
        doubleSpinBox_save_pressure_p->setSingleStep(0.1);

        gridLayout_16->addWidget(doubleSpinBox_save_pressure_p, 1, 0, 1, 1);

        doubleSpinBox_save_pressure_i = new QDoubleSpinBox(groupBox_11);
        doubleSpinBox_save_pressure_i->setObjectName(QStringLiteral("doubleSpinBox_save_pressure_i"));
        doubleSpinBox_save_pressure_i->setDecimals(4);
        doubleSpinBox_save_pressure_i->setSingleStep(0.1);

        gridLayout_16->addWidget(doubleSpinBox_save_pressure_i, 3, 0, 1, 1);

        doubleSpinBox_save_pressure_d = new QDoubleSpinBox(groupBox_11);
        doubleSpinBox_save_pressure_d->setObjectName(QStringLiteral("doubleSpinBox_save_pressure_d"));
        doubleSpinBox_save_pressure_d->setEnabled(true);
        doubleSpinBox_save_pressure_d->setDecimals(4);
        doubleSpinBox_save_pressure_d->setSingleStep(0.1);

        gridLayout_16->addWidget(doubleSpinBox_save_pressure_d, 5, 0, 1, 1);

        label_2 = new QLabel(groupBox_11);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_16->addWidget(label_2, 0, 0, 1, 1);

        label_20 = new QLabel(groupBox_11);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_16->addWidget(label_20, 2, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_11, 0, 0, 1, 1);

        pushButton_save_pid = new QPushButton(groupBox);
        pushButton_save_pid->setObjectName(QStringLiteral("pushButton_save_pid"));

        gridLayout_15->addWidget(pushButton_save_pid, 1, 1, 1, 1);


        gridLayout_14->addWidget(groupBox, 1, 0, 1, 2);

        groupBox_5 = new QGroupBox(tab_sensors);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_8 = new QGroupBox(groupBox_5);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_6 = new QGridLayout(groupBox_8);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_6->addWidget(label_10, 0, 1, 1, 1);

        doubleSpinBox_cali_P_gain = new QDoubleSpinBox(groupBox_8);
        doubleSpinBox_cali_P_gain->setObjectName(QStringLiteral("doubleSpinBox_cali_P_gain"));
        doubleSpinBox_cali_P_gain->setDecimals(3);
        doubleSpinBox_cali_P_gain->setMaximum(999.99);

        gridLayout_6->addWidget(doubleSpinBox_cali_P_gain, 1, 1, 1, 1);

        doubleSpinBox_cali_P_bias = new QDoubleSpinBox(groupBox_8);
        doubleSpinBox_cali_P_bias->setObjectName(QStringLiteral("doubleSpinBox_cali_P_bias"));
        doubleSpinBox_cali_P_bias->setDecimals(3);
        doubleSpinBox_cali_P_bias->setMaximum(999.99);

        gridLayout_6->addWidget(doubleSpinBox_cali_P_bias, 3, 1, 1, 1);

        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_6->addWidget(label_11, 2, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_8, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(groupBox_5);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_7 = new QGridLayout(groupBox_9);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_13 = new QLabel(groupBox_9);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_7->addWidget(label_13, 2, 0, 1, 1);

        doubleSpinBox_cali_Q_bias = new QDoubleSpinBox(groupBox_9);
        doubleSpinBox_cali_Q_bias->setObjectName(QStringLiteral("doubleSpinBox_cali_Q_bias"));
        doubleSpinBox_cali_Q_bias->setDecimals(3);
        doubleSpinBox_cali_Q_bias->setMaximum(999.99);

        gridLayout_7->addWidget(doubleSpinBox_cali_Q_bias, 3, 0, 1, 1);

        label_12 = new QLabel(groupBox_9);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_7->addWidget(label_12, 0, 0, 1, 1);

        doubleSpinBox_cali_Q_gain = new QDoubleSpinBox(groupBox_9);
        doubleSpinBox_cali_Q_gain->setObjectName(QStringLiteral("doubleSpinBox_cali_Q_gain"));
        doubleSpinBox_cali_Q_gain->setDecimals(3);
        doubleSpinBox_cali_Q_gain->setMaximum(9999.99);

        gridLayout_7->addWidget(doubleSpinBox_cali_Q_gain, 1, 0, 1, 1);

        doubleSpinBox_cali_Q_gain->raise();
        doubleSpinBox_cali_Q_bias->raise();
        label_12->raise();
        label_13->raise();

        gridLayout_5->addWidget(groupBox_9, 0, 1, 1, 1);

        pushButton_save_config = new QPushButton(groupBox_5);
        pushButton_save_config->setObjectName(QStringLiteral("pushButton_save_config"));

        gridLayout_5->addWidget(pushButton_save_config, 1, 1, 1, 1);


        gridLayout_14->addWidget(groupBox_5, 0, 0, 1, 2);

        label_logo_4 = new QLabel(tab_sensors);
        label_logo_4->setObjectName(QStringLiteral("label_logo_4"));

        gridLayout_14->addWidget(label_logo_4, 4, 0, 1, 1);

        label_17 = new QLabel(tab_sensors);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_14->addWidget(label_17, 0, 2, 1, 1);

        label_23 = new QLabel(tab_sensors);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_14->addWidget(label_23, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer, 3, 0, 1, 1);

        tabWidget->addTab(tab_sensors, QString());
        tab_experiment = new QWidget();
        tab_experiment->setObjectName(QStringLiteral("tab_experiment"));
        gridLayout_13 = new QGridLayout(tab_experiment);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer, 0, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer_4, 1, 3, 1, 1);

        label_logo_2 = new QLabel(tab_experiment);
        label_logo_2->setObjectName(QStringLiteral("label_logo_2"));

        gridLayout_13->addWidget(label_logo_2, 2, 0, 1, 1);

        groupBox_10 = new QGroupBox(tab_experiment);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_8 = new QGridLayout(groupBox_10);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_14 = new QLabel(groupBox_10);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout->addWidget(label_14);

        doubleSpinBox_min = new QDoubleSpinBox(groupBox_10);
        doubleSpinBox_min->setObjectName(QStringLiteral("doubleSpinBox_min"));
        doubleSpinBox_min->setMaximum(170.99);

        verticalLayout->addWidget(doubleSpinBox_min);

        pushButton_swapValue = new QPushButton(groupBox_10);
        pushButton_swapValue->setObjectName(QStringLiteral("pushButton_swapValue"));

        verticalLayout->addWidget(pushButton_swapValue);

        label_15 = new QLabel(groupBox_10);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout->addWidget(label_15);

        doubleSpinBox_max = new QDoubleSpinBox(groupBox_10);
        doubleSpinBox_max->setObjectName(QStringLiteral("doubleSpinBox_max"));
        doubleSpinBox_max->setMaximum(170.99);

        verticalLayout->addWidget(doubleSpinBox_max);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout->addWidget(label_16);

        doubleSpinBox_length = new QDoubleSpinBox(groupBox_10);
        doubleSpinBox_length->setObjectName(QStringLiteral("doubleSpinBox_length"));

        verticalLayout->addWidget(doubleSpinBox_length);


        gridLayout_8->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBox_waveGen = new QComboBox(groupBox_10);
        comboBox_waveGen->setObjectName(QStringLiteral("comboBox_waveGen"));

        verticalLayout_2->addWidget(comboBox_waveGen);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout_8->addLayout(verticalLayout_2, 0, 0, 1, 1);

        pushButton_load_auto = new QPushButton(groupBox_10);
        pushButton_load_auto->setObjectName(QStringLiteral("pushButton_load_auto"));

        gridLayout_8->addWidget(pushButton_load_auto, 1, 0, 1, 2);


        gridLayout_13->addWidget(groupBox_10, 0, 0, 1, 1);

        groupBox_15 = new QGroupBox(tab_experiment);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        gridLayout_20 = new QGridLayout(groupBox_15);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        groupBox_16 = new QGroupBox(groupBox_15);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        gridLayout_21 = new QGridLayout(groupBox_16);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        pushButton_configAuto = new QPushButton(groupBox_16);
        pushButton_configAuto->setObjectName(QStringLiteral("pushButton_configAuto"));

        gridLayout_21->addWidget(pushButton_configAuto, 0, 0, 1, 1);


        gridLayout_20->addWidget(groupBox_16, 0, 0, 1, 1);

        groupBox_17 = new QGroupBox(groupBox_15);
        groupBox_17->setObjectName(QStringLiteral("groupBox_17"));
        gridLayout_22 = new QGridLayout(groupBox_17);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        pushButton_genAuto = new QPushButton(groupBox_17);
        pushButton_genAuto->setObjectName(QStringLiteral("pushButton_genAuto"));

        gridLayout_22->addWidget(pushButton_genAuto, 0, 0, 1, 1);


        gridLayout_20->addWidget(groupBox_17, 1, 0, 1, 1);

        groupBox_18 = new QGroupBox(groupBox_15);
        groupBox_18->setObjectName(QStringLiteral("groupBox_18"));
        gridLayout_23 = new QGridLayout(groupBox_18);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        pushButton_saveConfig = new QPushButton(groupBox_18);
        pushButton_saveConfig->setObjectName(QStringLiteral("pushButton_saveConfig"));

        gridLayout_23->addWidget(pushButton_saveConfig, 0, 0, 1, 1);


        gridLayout_20->addWidget(groupBox_18, 2, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_15, 0, 1, 1, 1);

        label_wavegen = new QLabel(tab_experiment);
        label_wavegen->setObjectName(QStringLiteral("label_wavegen"));

        gridLayout_13->addWidget(label_wavegen, 1, 0, 1, 2);

        tabWidget->addTab(tab_experiment, QString());

        gridLayout_9->addWidget(tabWidget, 0, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(48);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 8, 00);"));

        gridLayout_9->addWidget(pushButton, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_Object->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\257\271\350\261\241", Q_NULLPTR));
        radioButton_Q->setText(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        radioButton_P->setText(QApplication::translate("MainWindow", "P", Q_NULLPTR));
        checkBox_LUT->setText(QApplication::translate("MainWindow", "LUT", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\345\274\200\351\227\255\347\216\257\351\200\211\346\213\251", Q_NULLPTR));
        checkBox_closeLoop->setText(QApplication::translate("MainWindow", "\351\227\255\347\216\257", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "V", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\217\202\346\225\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "P:  ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "I:  ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "D:", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\345\275\223\345\211\215\345\200\274", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Q(L/min):", Q_NULLPTR));
        label_Q->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_P->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "P(MPa):", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\212\266\346\200\201\345\217\202\350\200\203", Q_NULLPTR));
        label_timer_state->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_timerctrl->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\274\200\345\205\263", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_confirm_all->setText(QApplication::translate("MainWindow", "\n"
"\n"
"\347\241\256\350\256\244\345\271\266\346\211\247\350\241\214\n"
"\n"
"", Q_NULLPTR));
        label_port->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\347\273\230\345\233\276", Q_NULLPTR));
        radioButton_5V->setText(QApplication::translate("MainWindow", "  -1 ~ + 5", Q_NULLPTR));
        radioButton_10V->setText(QApplication::translate("MainWindow", "  -3 ~ + 26", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "\347\272\242-\346\265\201\351\207\217\n"
"(L/min)", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "\347\273\277-SV\n"
"(P/Q)", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "\347\264\253-\345\216\213\345\212\233\n"
"(MPa)", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "\350\223\235-DA\n"
"(V)", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\347\272\265\345\235\220\346\240\207\350\214\203\345\233\264:", Q_NULLPTR));
        pushButton_set_range->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        checkBox_output->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272", Q_NULLPTR));
        groupBox_Mode->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\346\250\241\345\274\217", Q_NULLPTR));
        radioButton_Manual->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250", Q_NULLPTR));
        radioButton_Auto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_mainPannel), QApplication::translate("MainWindow", "\344\270\273\351\235\242\346\235\277", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "\351\222\251\351\200\211\344\270\273\351\235\242\346\235\277output\345\220\216,\n"
"\346\225\260\346\215\256\345\260\206\344\277\235\345\255\230\350\207\263\350\256\276\347\275\256\350\267\257\345\276\204\346\226\207\344\273\266\344\270\255.", Q_NULLPTR));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266\350\267\257\345\276\204", Q_NULLPTR));
        pushButton_chooseSavePath->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\267\257\345\276\204", Q_NULLPTR));
        label_curPath->setText(QApplication::translate("MainWindow", "-------------", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\231\250\345\217\202\346\225\260", Q_NULLPTR));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "I:", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "P:", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "D:", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "P", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "D:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "P:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "I:", Q_NULLPTR));
        pushButton_save_pid->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\346\240\241\345\207\206", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "P", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\345\242\236\347\233\212:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\201\217\347\275\256:", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\201\217\347\275\256:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\345\242\236\347\233\212:", Q_NULLPTR));
        pushButton_save_config->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
        label_logo_4->setText(QApplication::translate("MainWindow", "  DAQ - shincky\n"
" -3-  =.=   2333", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250\347\232\204\346\240\207\345\256\232\346\225\260\346\215\256:\n"
"Gain(\345\242\236\347\233\212):\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250\347\232\204\346\265\213\351\207\217\350\214\203\345\233\264\351\231\244\344\273\245\344\274\240\346\204\237\345\231\250\350\276\223\345\207\272\347\224\265\345\216\213\350\214\203\345\233\264\357\274\214\345\215\225\344\275\215:MPa/V\n"
"Bias(\345\201\217\347\275\256):0\345\216\213\345\212\233\346\227\266\347\232\204\347\224\265\345\216\213\350\276\223\345\207\272\357\274\214\345\215\225\344\275\215\357\274\232V\n"
"\n"
"\n"
"\346\265\201\351\207\217\344\274\240\346\204\237\345\231\250\347\232\204\346\240\207\345\256\232\346\225\260\346\215\256\357\274\232\n"
"Gain(\345\242\236\347\233\212):\346\265\201\351\207\217\344\274\240\346\204\237\345\231\250\346\257\217\345\215\207\347\232\204\350\204\211\345\206\262\346\225\260,\345\215\225\344\275\215:Imp/L(\344\270\252/\345\215\207)\n"
"Bias(\345\201\217"
                        "\347\275\256):0\346\265\201\351\207\217\346\227\266\347\232\204\350\204\211\345\206\262\346\225\260,\345\215\225\344\275\215:Imp(\344\270\252)", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\231\250\345\217\202\346\225\260P,Q\345\210\206\345\210\253\345\257\271\345\272\224\345\216\213\345\212\233\346\265\201\351\207\217\346\216\247\345\210\266\345\231\250\347\232\204PID\345\217\202\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_sensors), QApplication::translate("MainWindow", "\345\217\202\346\225\260", Q_NULLPTR));
        label_logo_2->setText(QApplication::translate("MainWindow", "  DAQ - shincky\n"
" -3-  =.=   2333", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\346\263\242\345\275\242\345\217\221\347\224\237\345\231\250", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213(Min):", Q_NULLPTR));
        pushButton_swapValue->setText(QApplication::translate("MainWindow", "\n"
"\344\272\244\346\215\242\350\265\267\345\247\213\345\222\214\347\273\223\346\235\237\347\232\204\346\225\260\345\200\274\n"
"", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237(Max):", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\351\225\277\345\272\246/\345\221\250\346\234\237(Length):", Q_NULLPTR));
        comboBox_waveGen->clear();
        comboBox_waveGen->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Slope", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Triangle", Q_NULLPTR)
         << QApplication::translate("MainWindow", "User Define", Q_NULLPTR)
        );
        pushButton_load_auto->setText(QApplication::translate("MainWindow", "\n"
"\345\212\240\350\275\275\350\207\252\345\212\250\350\257\225\351\252\214\346\226\207\344\273\266\n"
"", Q_NULLPTR));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "\351\205\215\347\275\256\350\207\252\345\212\250\350\257\225\351\252\214", Q_NULLPTR));
        groupBox_16->setTitle(QApplication::translate("MainWindow", "\347\254\254\344\270\200\346\255\245", Q_NULLPTR));
        pushButton_configAuto->setText(QApplication::translate("MainWindow", "\n"
"\351\205\215\347\275\256\350\207\252\345\212\250\350\257\225\351\252\214\346\226\207\344\273\266\n"
"", Q_NULLPTR));
        groupBox_17->setTitle(QApplication::translate("MainWindow", "\347\254\254\344\272\214\346\255\245", Q_NULLPTR));
        pushButton_genAuto->setText(QApplication::translate("MainWindow", "\n"
"\347\224\237\346\210\220\351\205\215\347\275\256\346\226\207\344\273\266\n"
"", Q_NULLPTR));
        groupBox_18->setTitle(QApplication::translate("MainWindow", "\347\254\254\344\270\211\346\255\245", Q_NULLPTR));
        pushButton_saveConfig->setText(QApplication::translate("MainWindow", "\n"
"\344\277\235\345\255\230\351\205\215\347\275\256\346\226\207\344\273\266\n"
"", Q_NULLPTR));
        label_wavegen->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_experiment), QApplication::translate("MainWindow", "\350\257\225\351\252\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\342\230\220\346\200\245\345\201\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
