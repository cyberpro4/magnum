/********************************************************************************
** Form generated from reading UI file 'setup_general.ui'
**
** Created: Fri 14. Jan 15:02:36 2011
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
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setupGeneral
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *genNewDocumentStartup;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *genNumberRecentFiles;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *setupGeneral)
    {
        if (setupGeneral->objectName().isEmpty())
            setupGeneral->setObjectName(QString::fromUtf8("setupGeneral"));
        setupGeneral->resize(400, 300);
        verticalLayoutWidget = new QWidget(setupGeneral);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 252, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        genNewDocumentStartup = new QCheckBox(verticalLayoutWidget);
        genNewDocumentStartup->setObjectName(QString::fromUtf8("genNewDocumentStartup"));

        verticalLayout->addWidget(genNewDocumentStartup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        genNumberRecentFiles = new QSpinBox(verticalLayoutWidget);
        genNumberRecentFiles->setObjectName(QString::fromUtf8("genNumberRecentFiles"));

        horizontalLayout->addWidget(genNumberRecentFiles);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(setupGeneral);

        QMetaObject::connectSlotsByName(setupGeneral);
    } // setupUi

    void retranslateUi(QWidget *setupGeneral)
    {
        setupGeneral->setWindowTitle(QApplication::translate("setupGeneral", "Form", 0, QApplication::UnicodeUTF8));
        genNewDocumentStartup->setText(QApplication::translate("setupGeneral", "Open a fresh document at startup", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setupGeneral", "Maximum number of recent files:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setupGeneral: public Ui_setupGeneral {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_GENERAL_H
