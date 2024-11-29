#include "mainWindow.h"
#include "res.h"
#include <QMouseEvent>
#include <cstdlib>
#include <ctime>

mainWindow::mainWindow(QWidget* parent)
    : QMainWindow(parent), isDragging(false)
{
    this->videoByFrame = new VideoByFrame(this);
    ui.setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->start(2000);

    int tp1 = 0;
    int tp2 = 0;
    connect(timer, &QTimer::timeout, this, [=]() mutable {
        srand(time(NULL));
        tp1 = rand() % 4;
        tp2 = rand() % 11;
        std::cout << tp1 << " " << tp2 << std::endl;
        this->videoByFrame->changeVideo(tp1, tp2);
    });

    QTimer* timer2 = new QTimer(this);
    timer2->start(5000);
    connect(timer2, &QTimer::timeout, this, [=]() {
        //this->videoByFrame->changeVideo(tp1, tp2);
    });

    setFixedSize(190, 190);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    this->update();
}

mainWindow::~mainWindow()
{
}

void mainWindow::paintEvent(QPaintEvent* event)
{
    this->videoByFrame->show();
}


void mainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->isDragging = true;
        this->dragStartPosition = event->globalPosition().toPoint();
        this->windowStartPosition = this->frameGeometry().topLeft();
    }
}

void mainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (isDragging)
    {
        QPoint delta = event->globalPosition().toPoint() - dragStartPosition;
        this->move(windowStartPosition + delta);
    }
}

void mainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        isDragging = false;
    }
}
