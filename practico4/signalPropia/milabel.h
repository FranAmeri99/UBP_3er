#ifndef MILABEL_H
#define MILABEL_H

#include <QLabel>

class MiLabel : public QLabel  {
    Q_OBJECT

public:
    MiLabel( QWidget * parent = nullptr );

protected:
    void mousePressEvent( QMouseEvent * e );

signals:
    void signal_clic();
};

#endif // MILABEL_H
