#ifndef CCODEEDITOR_H
#define CCODEEDITOR_H

#include <QtGui/QWidget>

class CCodeEditor : public QWidget
{
    Q_OBJECT

public:
    CCodeEditor(QWidget *parent = 0);
    ~CCodeEditor();
};

#endif // CCODEEDITOR_H
