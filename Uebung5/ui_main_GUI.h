/********************************************************************************
** Form generated from reading UI file 'main_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_GUI_H
#define UI_MAIN_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_GUI
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_file;
    QLineEdit *lineEdit_filename;
    QPushButton *btn_choose;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QLineEdit *lineEdit_dimensionsX;
    QLabel *label_5;
    QLineEdit *lineEdit_dimensionsY;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QComboBox *cb_filter;
    QStackedWidget *sw_options_stacked_widget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_6;
    QSpinBox *sb_div1;
    QSpinBox *sb_div2;
    QGridLayout *gridLayout;
    QSpinBox *sb_13;
    QSpinBox *sb_23;
    QSpinBox *sb_33;
    QSpinBox *sb_12;
    QSpinBox *sb_11;
    QSpinBox *sb_21;
    QSpinBox *sb_22;
    QSpinBox *sb_31;
    QSpinBox *sb_32;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpinBox *sb_morph_size;
    QSpacerItem *horizontalSpacer_3;
    QWidget *Pictures;
    QHBoxLayout *horizontalLayout_2;
    QWidget *LeftSIde;
    QVBoxLayout *verticalLayout_2;
    QWidget *header_left;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_loadPPM;
    QLabel *lbl_filesize_load;
    QLineEdit *lineEdit_filesize_load;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_pop;
    QVBoxLayout *left_PicFrame;
    QLabel *leftPicture;
    QWidget *RightSide;
    QVBoxLayout *verticalLayout_3;
    QWidget *header_right;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_push;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_apply;
    QVBoxLayout *right_PicFrame;
    QLabel *rightPicture;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main_GUI)
    {
        if (main_GUI->objectName().isEmpty())
            main_GUI->setObjectName(QStringLiteral("main_GUI"));
        main_GUI->resize(737, 550);
        centralWidget = new QWidget(main_GUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(200, 50));
        groupBox->setMaximumSize(QSize(16777215, 150));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbl_file = new QLabel(groupBox);
        lbl_file->setObjectName(QStringLiteral("lbl_file"));

        horizontalLayout_7->addWidget(lbl_file);

        lineEdit_filename = new QLineEdit(groupBox);
        lineEdit_filename->setObjectName(QStringLiteral("lineEdit_filename"));

        horizontalLayout_7->addWidget(lineEdit_filename);

        btn_choose = new QPushButton(groupBox);
        btn_choose->setObjectName(QStringLiteral("btn_choose"));
        btn_choose->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(btn_choose);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(label_4);

        lineEdit_dimensionsX = new QLineEdit(groupBox);
        lineEdit_dimensionsX->setObjectName(QStringLiteral("lineEdit_dimensionsX"));
        lineEdit_dimensionsX->setEnabled(false);
        lineEdit_dimensionsX->setMaximumSize(QSize(60, 16777215));
        lineEdit_dimensionsX->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_dimensionsX);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_10->addWidget(label_5);

        lineEdit_dimensionsY = new QLineEdit(groupBox);
        lineEdit_dimensionsY->setObjectName(QStringLiteral("lineEdit_dimensionsY"));
        lineEdit_dimensionsY->setEnabled(false);
        lineEdit_dimensionsY->setMaximumSize(QSize(60, 16777215));
        lineEdit_dimensionsY->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_dimensionsY);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_10);


        horizontalLayout->addLayout(verticalLayout_5);


        horizontalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 150));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_2);

        cb_filter = new QComboBox(groupBox_2);
        cb_filter->setObjectName(QStringLiteral("cb_filter"));
        cb_filter->setMinimumSize(QSize(100, 0));
        cb_filter->setMaximumSize(QSize(100, 20));

        horizontalLayout_8->addWidget(cb_filter);


        verticalLayout_7->addLayout(horizontalLayout_8);

        sw_options_stacked_widget = new QStackedWidget(groupBox_2);
        sw_options_stacked_widget->setObjectName(QStringLiteral("sw_options_stacked_widget"));
        sw_options_stacked_widget->setMaximumSize(QSize(1677721, 16777215));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_6 = new QHBoxLayout(page);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_6->setContentsMargins(0, -1, 0, 0);
        sb_div1 = new QSpinBox(page);
        sb_div1->setObjectName(QStringLiteral("sb_div1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sb_div1->sizePolicy().hasHeightForWidth());
        sb_div1->setSizePolicy(sizePolicy1);
        sb_div1->setMaximumSize(QSize(30, 16777215));
        sb_div1->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_6->addWidget(sb_div1);

        sb_div2 = new QSpinBox(page);
        sb_div2->setObjectName(QStringLiteral("sb_div2"));
        sizePolicy1.setHeightForWidth(sb_div2->sizePolicy().hasHeightForWidth());
        sb_div2->setSizePolicy(sizePolicy1);
        sb_div2->setMaximumSize(QSize(30, 16777215));
        sb_div2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_6->addWidget(sb_div2);


        horizontalLayout_9->addLayout(verticalLayout_6);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sb_13 = new QSpinBox(page);
        sb_13->setObjectName(QStringLiteral("sb_13"));
        sizePolicy1.setHeightForWidth(sb_13->sizePolicy().hasHeightForWidth());
        sb_13->setSizePolicy(sizePolicy1);
        sb_13->setMaximumSize(QSize(30, 16777215));
        sb_13->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_13->setMinimum(-99);

        gridLayout->addWidget(sb_13, 0, 2, 1, 1);

        sb_23 = new QSpinBox(page);
        sb_23->setObjectName(QStringLiteral("sb_23"));
        sizePolicy1.setHeightForWidth(sb_23->sizePolicy().hasHeightForWidth());
        sb_23->setSizePolicy(sizePolicy1);
        sb_23->setMaximumSize(QSize(30, 16777215));
        sb_23->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_23->setMinimum(-99);

        gridLayout->addWidget(sb_23, 1, 2, 1, 1);

        sb_33 = new QSpinBox(page);
        sb_33->setObjectName(QStringLiteral("sb_33"));
        sizePolicy1.setHeightForWidth(sb_33->sizePolicy().hasHeightForWidth());
        sb_33->setSizePolicy(sizePolicy1);
        sb_33->setMaximumSize(QSize(30, 16777215));
        sb_33->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_33->setMinimum(-99);

        gridLayout->addWidget(sb_33, 2, 2, 1, 1);

        sb_12 = new QSpinBox(page);
        sb_12->setObjectName(QStringLiteral("sb_12"));
        sizePolicy1.setHeightForWidth(sb_12->sizePolicy().hasHeightForWidth());
        sb_12->setSizePolicy(sizePolicy1);
        sb_12->setMaximumSize(QSize(30, 16777215));
        sb_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_12->setMinimum(-99);

        gridLayout->addWidget(sb_12, 0, 1, 1, 1);

        sb_11 = new QSpinBox(page);
        sb_11->setObjectName(QStringLiteral("sb_11"));
        sizePolicy1.setHeightForWidth(sb_11->sizePolicy().hasHeightForWidth());
        sb_11->setSizePolicy(sizePolicy1);
        sb_11->setMaximumSize(QSize(30, 16777215));
        sb_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_11->setMinimum(-99);

        gridLayout->addWidget(sb_11, 0, 0, 1, 1);

        sb_21 = new QSpinBox(page);
        sb_21->setObjectName(QStringLiteral("sb_21"));
        sizePolicy1.setHeightForWidth(sb_21->sizePolicy().hasHeightForWidth());
        sb_21->setSizePolicy(sizePolicy1);
        sb_21->setMaximumSize(QSize(30, 16777215));
        sb_21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_21->setMinimum(-99);

        gridLayout->addWidget(sb_21, 1, 0, 1, 1);

        sb_22 = new QSpinBox(page);
        sb_22->setObjectName(QStringLiteral("sb_22"));
        sizePolicy1.setHeightForWidth(sb_22->sizePolicy().hasHeightForWidth());
        sb_22->setSizePolicy(sizePolicy1);
        sb_22->setMaximumSize(QSize(30, 16777215));
        sb_22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_22->setMinimum(-99);

        gridLayout->addWidget(sb_22, 1, 1, 1, 1);

        sb_31 = new QSpinBox(page);
        sb_31->setObjectName(QStringLiteral("sb_31"));
        sizePolicy1.setHeightForWidth(sb_31->sizePolicy().hasHeightForWidth());
        sb_31->setSizePolicy(sizePolicy1);
        sb_31->setMaximumSize(QSize(30, 16777215));
        sb_31->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_31->setMinimum(-99);

        gridLayout->addWidget(sb_31, 2, 0, 1, 1);

        sb_32 = new QSpinBox(page);
        sb_32->setObjectName(QStringLiteral("sb_32"));
        sizePolicy1.setHeightForWidth(sb_32->sizePolicy().hasHeightForWidth());
        sb_32->setSizePolicy(sizePolicy1);
        sb_32->setMaximumSize(QSize(30, 16777215));
        sb_32->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_32->setMinimum(-99);

        gridLayout->addWidget(sb_32, 2, 1, 1, 1);


        horizontalLayout_9->addLayout(gridLayout);


        horizontalLayout_6->addLayout(horizontalLayout_9);

        sw_options_stacked_widget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_11 = new QHBoxLayout(page_2);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(50, 16777215));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label);

        sb_morph_size = new QSpinBox(page_2);
        sb_morph_size->setObjectName(QStringLiteral("sb_morph_size"));
        sizePolicy1.setHeightForWidth(sb_morph_size->sizePolicy().hasHeightForWidth());
        sb_morph_size->setSizePolicy(sizePolicy1);
        sb_morph_size->setMaximumSize(QSize(50, 16777215));
        sb_morph_size->setMinimum(1);
        sb_morph_size->setSingleStep(2);
        sb_morph_size->setValue(7);

        horizontalLayout_11->addWidget(sb_morph_size);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        horizontalLayout_11->setStretch(1, 1);
        horizontalLayout_11->setStretch(2, 1);
        sw_options_stacked_widget->addWidget(page_2);

        verticalLayout_7->addWidget(sw_options_stacked_widget);


        verticalLayout_4->addLayout(verticalLayout_7);


        horizontalLayout_5->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout_5);

        Pictures = new QWidget(centralWidget);
        Pictures->setObjectName(QStringLiteral("Pictures"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Pictures->sizePolicy().hasHeightForWidth());
        Pictures->setSizePolicy(sizePolicy2);
        Pictures->setMinimumSize(QSize(0, 290));
        horizontalLayout_2 = new QHBoxLayout(Pictures);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LeftSIde = new QWidget(Pictures);
        LeftSIde->setObjectName(QStringLiteral("LeftSIde"));
        sizePolicy2.setHeightForWidth(LeftSIde->sizePolicy().hasHeightForWidth());
        LeftSIde->setSizePolicy(sizePolicy2);
        LeftSIde->setMinimumSize(QSize(283, 290));
        verticalLayout_2 = new QVBoxLayout(LeftSIde);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        header_left = new QWidget(LeftSIde);
        header_left->setObjectName(QStringLiteral("header_left"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(header_left->sizePolicy().hasHeightForWidth());
        header_left->setSizePolicy(sizePolicy3);
        header_left->setMinimumSize(QSize(0, 25));
        horizontalLayout_3 = new QHBoxLayout(header_left);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 10, 0);
        btn_loadPPM = new QPushButton(header_left);
        btn_loadPPM->setObjectName(QStringLiteral("btn_loadPPM"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btn_loadPPM->sizePolicy().hasHeightForWidth());
        btn_loadPPM->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(btn_loadPPM);

        lbl_filesize_load = new QLabel(header_left);
        lbl_filesize_load->setObjectName(QStringLiteral("lbl_filesize_load"));
        lbl_filesize_load->setMinimumSize(QSize(50, 0));
        lbl_filesize_load->setMaximumSize(QSize(100, 16777215));
        lbl_filesize_load->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lbl_filesize_load);

        lineEdit_filesize_load = new QLineEdit(header_left);
        lineEdit_filesize_load->setObjectName(QStringLiteral("lineEdit_filesize_load"));
        lineEdit_filesize_load->setEnabled(false);
        lineEdit_filesize_load->setMaximumSize(QSize(70, 16777215));
        lineEdit_filesize_load->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_filesize_load);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btn_pop = new QPushButton(header_left);
        btn_pop->setObjectName(QStringLiteral("btn_pop"));
        sizePolicy4.setHeightForWidth(btn_pop->sizePolicy().hasHeightForWidth());
        btn_pop->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(btn_pop);


        verticalLayout_2->addWidget(header_left);

        left_PicFrame = new QVBoxLayout();
        left_PicFrame->setSpacing(6);
        left_PicFrame->setObjectName(QStringLiteral("left_PicFrame"));
        left_PicFrame->setSizeConstraint(QLayout::SetDefaultConstraint);
        leftPicture = new QLabel(LeftSIde);
        leftPicture->setObjectName(QStringLiteral("leftPicture"));
        leftPicture->setMinimumSize(QSize(256, 256));
        leftPicture->setAutoFillBackground(true);
        leftPicture->setScaledContents(true);

        left_PicFrame->addWidget(leftPicture);


        verticalLayout_2->addLayout(left_PicFrame);

        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_2->addWidget(LeftSIde);

        RightSide = new QWidget(Pictures);
        RightSide->setObjectName(QStringLiteral("RightSide"));
        sizePolicy2.setHeightForWidth(RightSide->sizePolicy().hasHeightForWidth());
        RightSide->setSizePolicy(sizePolicy2);
        RightSide->setMinimumSize(QSize(283, 290));
        verticalLayout_3 = new QVBoxLayout(RightSide);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        header_right = new QWidget(RightSide);
        header_right->setObjectName(QStringLiteral("header_right"));
        sizePolicy3.setHeightForWidth(header_right->sizePolicy().hasHeightForWidth());
        header_right->setSizePolicy(sizePolicy3);
        header_right->setMinimumSize(QSize(0, 25));
        horizontalLayout_4 = new QHBoxLayout(header_right);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 10, 0);
        btn_push = new QPushButton(header_right);
        btn_push->setObjectName(QStringLiteral("btn_push"));
        sizePolicy4.setHeightForWidth(btn_push->sizePolicy().hasHeightForWidth());
        btn_push->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(btn_push);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        btn_apply = new QPushButton(header_right);
        btn_apply->setObjectName(QStringLiteral("btn_apply"));
        sizePolicy4.setHeightForWidth(btn_apply->sizePolicy().hasHeightForWidth());
        btn_apply->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(btn_apply);


        verticalLayout_3->addWidget(header_right);

        right_PicFrame = new QVBoxLayout();
        right_PicFrame->setSpacing(6);
        right_PicFrame->setObjectName(QStringLiteral("right_PicFrame"));
        right_PicFrame->setSizeConstraint(QLayout::SetDefaultConstraint);
        rightPicture = new QLabel(RightSide);
        rightPicture->setObjectName(QStringLiteral("rightPicture"));
        sizePolicy2.setHeightForWidth(rightPicture->sizePolicy().hasHeightForWidth());
        rightPicture->setSizePolicy(sizePolicy2);
        rightPicture->setMinimumSize(QSize(256, 256));
        rightPicture->setAutoFillBackground(true);
        rightPicture->setScaledContents(true);

        right_PicFrame->addWidget(rightPicture);


        verticalLayout_3->addLayout(right_PicFrame);

        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addWidget(RightSide);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(Pictures);

        verticalLayout->setStretch(1, 1);
        main_GUI->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(main_GUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        main_GUI->setStatusBar(statusBar);

        retranslateUi(main_GUI);

        sw_options_stacked_widget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(main_GUI);
    } // setupUi

    void retranslateUi(QMainWindow *main_GUI)
    {
        main_GUI->setWindowTitle(QApplication::translate("main_GUI", "Qt5Test2", 0));
        groupBox->setTitle(QApplication::translate("main_GUI", "File to Load", 0));
        lbl_file->setText(QApplication::translate("main_GUI", "File:", 0));
        btn_choose->setText(QApplication::translate("main_GUI", "...", 0));
        label_4->setText(QApplication::translate("main_GUI", "Dimensions:", 0));
        label_5->setText(QApplication::translate("main_GUI", "x", 0));
        groupBox_2->setTitle(QApplication::translate("main_GUI", "Options", 0));
        label_2->setText(QApplication::translate("main_GUI", "Filter", 0));
        cb_filter->setProperty("currentText", QVariant(QString()));
        label_3->setText(QApplication::translate("main_GUI", "Values", 0));
        label->setText(QApplication::translate("main_GUI", "Size", 0));
        btn_loadPPM->setText(QApplication::translate("main_GUI", "Load", 0));
        lbl_filesize_load->setText(QApplication::translate("main_GUI", "File size:", 0));
        btn_pop->setText(QApplication::translate("main_GUI", ">> Pop ", 0));
        leftPicture->setText(QString());
        btn_push->setText(QApplication::translate("main_GUI", "<< Push", 0));
        btn_apply->setText(QApplication::translate("main_GUI", "Apply", 0));
        rightPicture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class main_GUI: public Ui_main_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_GUI_H
