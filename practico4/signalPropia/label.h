#ifndef LABEL_H
#define LABEL_H


#include <QLabel>

class Label : public QLabel  {
    Q_OBJECT

public:
    Label( QWidget * parent = nullptr );

protected:
    void mousePressEvent( QMouseEvent * e );

signals:
    void signal_clic();
};


#endif // LABEL_H
