#ifndef CCODEEDITOR_FOLDAREA_H
#define CCODEEDITOR_FOLDAREA_H

#include <QtGui>

class CCodeEditor;

class CCodeEditor_FoldArea : public QWidget {

    Q_OBJECT

private:

    CCodeEditor*    editor;

    long            m_hoverLine;

public:
    CCodeEditor_FoldArea(QWidget *parent = 0);

    void paintEvent(QPaintEvent * eve );

    int	foldAreaWidth();

    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

signals:

public slots:

    void updateFolding(int );
};

#endif // CCODEEDITOR_FOLDAREA_H
