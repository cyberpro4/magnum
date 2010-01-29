#ifndef CDOCUMENT_H
#define CDOCUMENT_H

#include <QObject>
#include "ccodeeditor.h"

class CDocument : public QObject {

    Q_OBJECT

private:

    CCodeEditor*    m_editor;
    QFileInfo	    m_fileInfo;
    bool            m_isModified;

public:
    CDocument(const QString& file = "" );
    ~CDocument();

    CCodeEditor*    editor();

    bool    loadFromFile(const QString& );
    bool    saveToFile(const QString& file = "" );

    const QFileInfo& fileInfo();

};

#endif // CDOCUMENT_H
