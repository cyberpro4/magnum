#ifndef CABOUTWINDOW_H
#define CABOUTWINDOW_H

#include <QtGui>

class CAboutWindow:public QDialog{
    Q_OBJECT
public:
    CAboutWindow( QString iconPathName, QString text, QWidget* parent );

private:
    QLabel*	m_label;
    QPixmap*	m_icon;
    QLabel*	m_iconLabel;

};

#endif // CABOUTWINDOW_H
