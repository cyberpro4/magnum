/********************************************************************************
** Form generated from reading UI file 'setup_editor.ui'
**
** Created: Mon 15. Mar 14:35:28 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_EDITOR_H
#define UI_SETUP_EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setupEditor
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *uiFontGroupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *uiFontTypeLabel;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *uiFontFamily;
    QLineEdit *uiFontSize;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *setupEditor)
    {
        if (setupEditor->objectName().isEmpty())
            setupEditor->setObjectName(QString::fromUtf8("setupEditor"));
        setupEditor->resize(472, 358);
        gridLayout = new QGridLayout(setupEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        uiFontGroupBox = new QGroupBox(setupEditor);
        uiFontGroupBox->setObjectName(QString::fromUtf8("uiFontGroupBox"));
        verticalLayoutWidget_2 = new QWidget(uiFontGroupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 431, 61));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        uiFontTypeLabel = new QLabel(verticalLayoutWidget_2);
        uiFontTypeLabel->setObjectName(QString::fromUtf8("uiFontTypeLabel"));

        verticalLayout_2->addWidget(uiFontTypeLabel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        uiFontFamily = new QComboBox(verticalLayoutWidget_2);
        uiFontFamily->setObjectName(QString::fromUtf8("uiFontFamily"));

        horizontalLayout_6->addWidget(uiFontFamily);

        uiFontSize = new QLineEdit(verticalLayoutWidget_2);
        uiFontSize->setObjectName(QString::fromUtf8("uiFontSize"));
        uiFontSize->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_6->addWidget(uiFontSize);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(uiFontGroupBox);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(setupEditor);

        QMetaObject::connectSlotsByName(setupEditor);
    } // setupUi

    void retranslateUi(QWidget *setupEditor)
    {
        setupEditor->setWindowTitle(QApplication::translate("setupEditor", "Form", 0, QApplication::UnicodeUTF8));
        uiFontGroupBox->setTitle(QApplication::translate("setupEditor", "Font type", 0, QApplication::UnicodeUTF8));
        uiFontTypeLabel->setText(QApplication::translate("setupEditor", "Font family and size:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setupEditor: public Ui_setupEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_EDITOR_H
