#ifndef ESCENA_H
#define ESCENA_H
#include <QGraphicsScene>
class GifAnimaction;
class escena : public QGraphicsScene
{
public:
    escena(QObject * parent = nullptr);
private:
    GifAnimaction * mGifAnimaction;

};

#endif // ESCENA_H
