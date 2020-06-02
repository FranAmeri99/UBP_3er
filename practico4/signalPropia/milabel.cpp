#include "milabel.h"

#include <QMouseEvent>

MiLabel::MiLabel( QWidget * parent ) : QLabel( parent )
{

}

void MiLabel::mousePressEvent( QMouseEvent * e )  {
    if ( e->button() == Qt::LeftButton )  {
        emit signal_clic();
    }
}
