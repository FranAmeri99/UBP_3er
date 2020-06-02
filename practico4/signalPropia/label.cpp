#include "label.h"

#include <QMouseEvent>

Label::Label( QWidget * parent ) : QLabel( parent )
{

}

void Label::mousePressEvent( QMouseEvent * e )  {
    if ( e->button() == Qt::LeftButton )  {
        emit signal_clic();
    }
}
