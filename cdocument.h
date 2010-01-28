#ifndef CDOCUMENT_H
#define CDOCUMENT_H

#include <QObject>
#include "ccodeeditor.h"

class CDocument : public QObject {
    Q_OBJECT

private:

    CCodeEditor*    m_editor;
    QString	    m_fullFilename;

public:
    CDocument(const QString& file = "" );
    ~CDocument();

    CCodeEditor*    editor();

    bool    loadFromFile(const QString& );

};

#endif // CDOCUMENT_H
