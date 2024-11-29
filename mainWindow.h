#pragma once

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include "ui_mainWindow.h"
#include "videoByFrame.h"

class mainWindow : public QMainWindow
{
	Q_OBJECT

public:
	VideoByFrame *videoByFrame;
	mainWindow(QWidget *parent = nullptr);
	~mainWindow();
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	Ui::mainWindowClass ui;
	bool isDragging;
	QPoint dragStartPosition;
	QPoint windowStartPosition;

};
