# -------------------------------------------------
# Project created by QtCreator 2010-01-14T23:12:58
# -------------------------------------------------
TARGET = magnum
TEMPLATE = app
QT += xml
SOURCES += main.cpp \
    ccodeeditor.cpp \
    cfilesyntaxhighlighter.cpp \
    cproject.cpp \
    cprojectfunction.cpp \
    cprojectvariable.cpp \
    cprojectinstruction.cpp \
    cprojectitem.cpp \
    cmagnumwin.cpp \
    cdocument.cpp \
    cprojecttype.cpp \
    ccodeeditor_linenumberarea.cpp \
    ccodeeditor_foldarea.cpp \
    cprojectitemfactory.cpp \
    cprojectfile.cpp \
    cprojectprocedure.cpp \
    cprojecttypebag.cpp \
    cmagnum_textblock.cpp \
    cfindwindow.cpp \
    cprojecttreeview.cpp \
    cprojecttreeviewitem.cpp \
    cprojectwaitsec.cpp \
    cprojectwaitfor.cpp \
    cprojectinterruptdecl.cpp \
    coptions.cpp
HEADERS += ccodeeditor.h \
    cfilesyntaxhighlighter.h \
    cproject.h \
    cprojectfunction.h \
    cprojectvariable.h \
    cprojectinstruction.h \
    cprojectitem.h \
    cprojecttype.h \
    cmagnumwin.h \
    cdocument.h \
    ccodeeditor_linenumberarea.h \
    ccodeeditor_foldarea.h \
    cprojectitemfactory.h \
    cprojectfile.h \
    cprojectprocedure.h \
    cprojecttypebag.h \
    cmagnum_textblock.h \
    cfindwindow.h \
    cprojecttreeview.h \
    cprojecttreeviewitem.h \
    cprojectwaitsec.h \
    cprojectwaitfor.h \
    cprojectinterruptdecl.h \
    coptions.h
RESOURCES += magnumres.qrc
win32:RC_FILE = win_res.rc
