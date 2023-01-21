#ifndef MAINSCRULER_H
#define MAINSCRULER_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScruler; }
QT_END_NAMESPACE

class MainScruler : public QMainWindow
{
    Q_OBJECT

public:
    MainScruler(QWidget *parent = nullptr);
    ~MainScruler();

    void keyPressEvent(QKeyEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
private:
    Ui::MainScruler *ui;
    QPoint winPosition;
    bool isvertical {true};
};
#endif // MAINSCRULER_H
