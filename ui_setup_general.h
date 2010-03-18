/********************************************************************************
** Form generated from reading UI file 'setup_general.ui'
**
** Created: Thu 18. Mar 11:46:16 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_GENERAL_H
#define UI_SETUP_GENERAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setupGeneral
{
public:
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *setupGeneral)
    {
        if (setupGeneral->objectName().isEmpty())
            setupGeneral->setObjectName(QString::fromUtf8("setupGeneral"));
        setupGeneral->resize(400, 300);
        calendarWidget = new QCalendarWidget(setupGeneral);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(30, 30, 216, 141));

        retranslateUi(setupGeneral);

        QMetaObject::connectSlotsByName(setupGeneral);
    } // setupUi

    void retranslateUi(QWidget *setupGeneral)
    {
        setupGeneral->setWindowTitle(QApplication::translate("setupGeneral", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setupGeneral: public Ui_setupGeneral {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_GENERAL_H
