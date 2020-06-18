#include "keyboardprocessor.h"
#include "qdebug.h"
#include "qabstractbutton.h"
KeyBoardProcessor::KeyBoardProcessor()
{



}

KeyBoardProcessor::~KeyBoardProcessor(){

}

void KeyBoardProcessor::loopThroughButtons(){
     qDebug() << "Loop through buttons.." ;

       while(1){

          qDebug() << "Loop through buttons.." ;

      }

       emit finished();

}
