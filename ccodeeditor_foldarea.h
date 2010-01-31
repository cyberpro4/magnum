#ifndef CCODEEDITOR_FOLDAREA_H
#define CCODEEDITOR_FOLDAREA_H

#include <QtGui>

class CCodeEditor_FoldArea : public QWidget {

    Q_OBJECT

public:
    CCodeEditor_FoldArea(QWidget *parent = 0);

    void paintEvent(QPaintEvent * eve );

    int	foldAreaWidth();

signals:

public slots:

    void updateFolding(int );
};

#endif // CCODEEDITOR_FOLDAREA_H
