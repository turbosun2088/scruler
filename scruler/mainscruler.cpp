#include "mainscruler.h"
#include "./ui_mainscruler.h"

MainScruler::MainScruler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScruler)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowOpacity(0.7);
    this->setStyleSheet("background-color:#6163cc;");
    this->move(500,10);
}

MainScruler::~MainScruler()
{
    delete ui;
}

void MainScruler::keyPressEvent(QKeyEvent * event)
{
    switch(event->key()) {
    case Qt::Key_Escape:
        this->close();
        break;
    case Qt::Key_G:
//        (event->modifiers() == Qt::ControlModifier) &&
        if (isvertical == true) {
            this->setMinimumSize(1200,30);
            this->setMaximumSize(1200,30);
            this->move((this->pos().x() - 600) < 0 ? 0 : this->pos().x() - 600,
                       (this->pos().y() + 350) < 0 ? 0 : this->pos().y() + 350);
            isvertical = false;
        } else {
            this->setMinimumSize(30,700);
            this->setMaximumSize(30,700);
            this->move((this->pos().x() + 600) < 0 ? 0 : this->pos().x() + 600,
                       (this->pos().y() - 350) < 0 ? 0 : this->pos().y() - 350);
            isvertical = true;
        }
        break;

    }
}

void MainScruler::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton) {
        winPosition.setX(event->globalPosition().x() - frameGeometry().topLeft().x());
        winPosition.setY(event->globalPosition().y() - frameGeometry().topLeft().y());
        event->accept();

//        qDebug() << "left mouse button press." << event->globalPosition() << " - "
//                 << frameGeometry().topLeft() << " = " << winPosition;
    }
}

void MainScruler::mouseMoveEvent(QMouseEvent * event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPosition().x() - winPosition.x(),
             event->globalPosition().y() - winPosition.y());
        event->accept();
    }
}







