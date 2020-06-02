#ifndef GIFANIMACION_H
#define GIFANIMACION_H

#include <QObject>
class QLabel;
class QMovie;

class GifAnimaction : public QObject
{
public:
    GifAnimaction(QObject * parent = nullptr);

    void setFileName(QString * filename){
        mFilename = filename;
    }
    QString getFilename{
        return * mFilename;
    }
private:
    QLabel * mLabel;
    QMovie * mMovie;
    QString * mFilename;


};

#endif // GIFANIMACION_H
