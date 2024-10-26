/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "grid.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *GeneratePushButton;
    QPushButton *pausePushButton;
    QPushButton *ResetPushButton;
    QFormLayout *formLayout;
    Grid *gridView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QLabel *gridWallLabel;
    QSpinBox *gridWallSpinBox;
    QSpinBox *gridRowsSpinBox;
    QLabel *gridColumnsLabel;
    QLabel *gridRowsLabel;
    QSpinBox *gridColumnsSpinBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QSpinBox *mazeSpeedSpinBox;
    QLabel *label_5;
    QComboBox *comboBox_3;
    QSpacerItem *verticalSpacer;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QLabel *typeLabel;
    QGridLayout *gridLayout_4;
    QCheckBox *westCheckBox;
    QLabel *empty_2;
    QCheckBox *southCheckBox;
    QCheckBox *eastCheckBox;
    QCheckBox *northCheckBox;
    QLabel *empty;
    QLabel *xPositionLabel;
    QComboBox *typeComboBox;
    QSpinBox *gCostCellSpinBox;
    QSpinBox *xPosCellSpinBox;
    QLabel *fCostLabel;
    QSpinBox *YPosCellSpinBox;
    QSpinBox *fCostCellSpinBox;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_14;
    QLabel *gCostLabel;
    QLabel *yPositionLabel;
    QWidget *tab_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1310, 872);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        GeneratePushButton = new QPushButton(centralwidget);
        GeneratePushButton->setObjectName("GeneratePushButton");
        QFont font;
        font.setPointSize(12);
        GeneratePushButton->setFont(font);

        horizontalLayout->addWidget(GeneratePushButton);

        pausePushButton = new QPushButton(centralwidget);
        pausePushButton->setObjectName("pausePushButton");
        pausePushButton->setFont(font);

        horizontalLayout->addWidget(pausePushButton);

        ResetPushButton = new QPushButton(centralwidget);
        ResetPushButton->setObjectName("ResetPushButton");
        ResetPushButton->setFont(font);

        horizontalLayout->addWidget(ResetPushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        gridView = new Grid(centralwidget);
        gridView->setObjectName("gridView");
        gridView->setMouseTracking(true);
        gridView->setFrameShadow(QFrame::Plain);

        formLayout->setWidget(0, QFormLayout::FieldRole, gridView);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setMinimumSize(QSize(400, 120));
        tabWidget->setMaximumSize(QSize(1000, 16777215));
        QFont font1;
        font1.setPointSize(10);
        tabWidget->setFont(font1);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName("gridLayout_3");
        gridWallLabel = new QLabel(tab);
        gridWallLabel->setObjectName("gridWallLabel");
        gridWallLabel->setFont(font);

        gridLayout_3->addWidget(gridWallLabel, 4, 0, 1, 1);

        gridWallSpinBox = new QSpinBox(tab);
        gridWallSpinBox->setObjectName("gridWallSpinBox");
        gridWallSpinBox->setFont(font);
        gridWallSpinBox->setMinimum(1);
        gridWallSpinBox->setMaximum(5);
        gridWallSpinBox->setValue(1);

        gridLayout_3->addWidget(gridWallSpinBox, 5, 0, 1, 1);

        gridRowsSpinBox = new QSpinBox(tab);
        gridRowsSpinBox->setObjectName("gridRowsSpinBox");
        gridRowsSpinBox->setFont(font);
        gridRowsSpinBox->setMinimum(5);
        gridRowsSpinBox->setMaximum(100);
        gridRowsSpinBox->setValue(20);

        gridLayout_3->addWidget(gridRowsSpinBox, 3, 0, 1, 1);

        gridColumnsLabel = new QLabel(tab);
        gridColumnsLabel->setObjectName("gridColumnsLabel");
        gridColumnsLabel->setFont(font);

        gridLayout_3->addWidget(gridColumnsLabel, 0, 0, 1, 1);

        gridRowsLabel = new QLabel(tab);
        gridRowsLabel->setObjectName("gridRowsLabel");
        gridRowsLabel->setFont(font);

        gridLayout_3->addWidget(gridRowsLabel, 2, 0, 1, 1);

        gridColumnsSpinBox = new QSpinBox(tab);
        gridColumnsSpinBox->setObjectName("gridColumnsSpinBox");
        gridColumnsSpinBox->setFont(font);
        gridColumnsSpinBox->setMinimum(5);
        gridColumnsSpinBox->setMaximum(100);
        gridColumnsSpinBox->setValue(20);

        gridLayout_3->addWidget(gridColumnsSpinBox, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 6, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setFont(font);

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font);

        verticalLayout->addWidget(comboBox);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(tab_2);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setFont(font);

        verticalLayout->addWidget(comboBox_2);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        mazeSpeedSpinBox = new QSpinBox(tab_2);
        mazeSpeedSpinBox->setObjectName("mazeSpeedSpinBox");
        mazeSpeedSpinBox->setFont(font);
        mazeSpeedSpinBox->setMinimum(1);
        mazeSpeedSpinBox->setMaximum(100);

        verticalLayout->addWidget(mazeSpeedSpinBox);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        comboBox_3 = new QComboBox(tab_2);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setFont(font);

        verticalLayout->addWidget(comboBox_3);

        verticalSpacer = new QSpacerItem(20, 559, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName("gridLayout_5");
        typeLabel = new QLabel(tab_3);
        typeLabel->setObjectName("typeLabel");
        typeLabel->setFont(font);

        gridLayout_5->addWidget(typeLabel, 10, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        westCheckBox = new QCheckBox(tab_3);
        westCheckBox->setObjectName("westCheckBox");

        gridLayout_4->addWidget(westCheckBox, 1, 1, 1, 1);

        empty_2 = new QLabel(tab_3);
        empty_2->setObjectName("empty_2");

        gridLayout_4->addWidget(empty_2, 1, 4, 1, 1);

        southCheckBox = new QCheckBox(tab_3);
        southCheckBox->setObjectName("southCheckBox");

        gridLayout_4->addWidget(southCheckBox, 2, 2, 1, 1);

        eastCheckBox = new QCheckBox(tab_3);
        eastCheckBox->setObjectName("eastCheckBox");

        gridLayout_4->addWidget(eastCheckBox, 1, 3, 1, 1);

        northCheckBox = new QCheckBox(tab_3);
        northCheckBox->setObjectName("northCheckBox");

        gridLayout_4->addWidget(northCheckBox, 0, 2, 1, 1);

        empty = new QLabel(tab_3);
        empty->setObjectName("empty");

        gridLayout_4->addWidget(empty, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 9, 0, 1, 2);

        xPositionLabel = new QLabel(tab_3);
        xPositionLabel->setObjectName("xPositionLabel");
        xPositionLabel->setFont(font);

        gridLayout_5->addWidget(xPositionLabel, 0, 0, 1, 2);

        typeComboBox = new QComboBox(tab_3);
        typeComboBox->setObjectName("typeComboBox");
        typeComboBox->setFont(font);

        gridLayout_5->addWidget(typeComboBox, 11, 0, 1, 2);

        gCostCellSpinBox = new QSpinBox(tab_3);
        gCostCellSpinBox->setObjectName("gCostCellSpinBox");
        gCostCellSpinBox->setEnabled(true);
        gCostCellSpinBox->setFont(font);
        gCostCellSpinBox->setCursor(QCursor(Qt::ArrowCursor));
        gCostCellSpinBox->setFocusPolicy(Qt::WheelFocus);
        gCostCellSpinBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        gCostCellSpinBox->setMinimum(10);
        gCostCellSpinBox->setMaximum(50);
        gCostCellSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        gCostCellSpinBox->setValue(20);

        gridLayout_5->addWidget(gCostCellSpinBox, 7, 0, 1, 2);

        xPosCellSpinBox = new QSpinBox(tab_3);
        xPosCellSpinBox->setObjectName("xPosCellSpinBox");
        xPosCellSpinBox->setFont(font);
        xPosCellSpinBox->setFrame(true);
        xPosCellSpinBox->setReadOnly(true);
        xPosCellSpinBox->setKeyboardTracking(true);
        xPosCellSpinBox->setMinimum(10);
        xPosCellSpinBox->setMaximum(50);
        xPosCellSpinBox->setValue(20);

        gridLayout_5->addWidget(xPosCellSpinBox, 1, 0, 1, 2);

        fCostLabel = new QLabel(tab_3);
        fCostLabel->setObjectName("fCostLabel");
        fCostLabel->setFont(font);

        gridLayout_5->addWidget(fCostLabel, 4, 0, 1, 1);

        YPosCellSpinBox = new QSpinBox(tab_3);
        YPosCellSpinBox->setObjectName("YPosCellSpinBox");
        YPosCellSpinBox->setFont(font);
        YPosCellSpinBox->setReadOnly(true);
        YPosCellSpinBox->setMinimum(10);
        YPosCellSpinBox->setMaximum(50);
        YPosCellSpinBox->setValue(20);

        gridLayout_5->addWidget(YPosCellSpinBox, 3, 0, 1, 2);

        fCostCellSpinBox = new QSpinBox(tab_3);
        fCostCellSpinBox->setObjectName("fCostCellSpinBox");
        fCostCellSpinBox->setFont(font);
        fCostCellSpinBox->setMinimum(10);
        fCostCellSpinBox->setMaximum(50);
        fCostCellSpinBox->setValue(20);

        gridLayout_5->addWidget(fCostCellSpinBox, 5, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 293, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 12, 1, 1, 1);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName("label_14");
        label_14->setFont(font);

        gridLayout_5->addWidget(label_14, 8, 0, 1, 2);

        gCostLabel = new QLabel(tab_3);
        gCostLabel->setObjectName("gCostLabel");
        gCostLabel->setFont(font);

        gridLayout_5->addWidget(gCostLabel, 6, 0, 1, 1);

        yPositionLabel = new QLabel(tab_3);
        yPositionLabel->setObjectName("yPositionLabel");
        yPositionLabel->setFont(font);

        gridLayout_5->addWidget(yPositionLabel, 2, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());

        formLayout->setWidget(0, QFormLayout::LabelRole, tabWidget);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1310, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(GeneratePushButton, SIGNAL(clicked()), MainWindow, SLOT(onGenerateClicked()));
        QObject::connect(pausePushButton, SIGNAL(clicked()), MainWindow, SLOT(onPauseClicked()));
        QObject::connect(ResetPushButton, SIGNAL(clicked()), MainWindow, SLOT(onResetClicked()));
        QObject::connect(gridRowsSpinBox, SIGNAL(editingFinished()), MainWindow, SLOT(spinBoxRowsSet()));
        QObject::connect(gridColumnsSpinBox, SIGNAL(editingFinished()), MainWindow, SLOT(spinBoxColumnsSet()));
        QObject::connect(gridWallSpinBox, SIGNAL(editingFinished()), MainWindow, SLOT(spinBoxWallSizeSet()));
        QObject::connect(mazeSpeedSpinBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(spinBoxGenSpeedSet()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        GeneratePushButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        pausePushButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        ResetPushButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        gridWallLabel->setText(QCoreApplication::translate("MainWindow", "Wall size", nullptr));
        gridColumnsLabel->setText(QCoreApplication::translate("MainWindow", "Columns", nullptr));
        gridRowsLabel->setText(QCoreApplication::translate("MainWindow", "Rows", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Grid Design", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Generator Auswahl", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Deph First", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Prim", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Solver Auswahl", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "A-Star", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Speed / Delay", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Edit Maze", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Start", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "End", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Wall", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Generator + Solver", nullptr));
        typeLabel->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        westCheckBox->setText(QCoreApplication::translate("MainWindow", "West", nullptr));
        empty_2->setText(QString());
        southCheckBox->setText(QCoreApplication::translate("MainWindow", "South", nullptr));
        eastCheckBox->setText(QCoreApplication::translate("MainWindow", "East", nullptr));
        northCheckBox->setText(QCoreApplication::translate("MainWindow", "North", nullptr));
        empty->setText(QString());
        xPositionLabel->setText(QCoreApplication::translate("MainWindow", "X Position", nullptr));
        fCostLabel->setText(QCoreApplication::translate("MainWindow", "F-Cost", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Active Walls", nullptr));
        gCostLabel->setText(QCoreApplication::translate("MainWindow", "G-Cost", nullptr));
        yPositionLabel->setText(QCoreApplication::translate("MainWindow", "Y Position", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Cell Info", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Anderes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
