#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;

private slots:
    void Mouse_current_Pos();
    void Mouse_Pressed();
    void Mouse_left();

};
#endif // VENTANA_H
