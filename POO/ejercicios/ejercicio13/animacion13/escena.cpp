#include "escena.h"
#include "gifanimaction.h"
escena::escena(QObject * parent): QGraphicsScene(parent)
{
    mGifAnimaction = new GifAnimaction(this);
}
