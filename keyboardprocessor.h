#ifndef KEYBOARDPROCESSOR_H
#define KEYBOARDPROCESSOR_H

#include "qabstractbutton.h"
#include "qobject.h"


class KeyBoardProcessor :public QObject
{
  Q_OBJECT
public:
    KeyBoardProcessor();
    ~KeyBoardProcessor();

public slots:
    void loopThroughButtons();

signals:
    void finished();
    void error(QString);


};

#endif // KEYBOARDPROCESSOR_H
