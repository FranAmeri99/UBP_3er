#ifndef MY_QLABEL_H
#define MY_QLABEL_H
#include <QLabel>
#include <QObject>
#include <QMouseEvent>
#include <QEvent>

class my_qlabel : public QLabel  {

    Q_OBJECT
public:

    my_qlabel( QWidget * parent = nullptr );
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);
     int x,y;
signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();

};

#endif // MY_QLABEL_H
