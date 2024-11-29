#pragma once
#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <iostream>
#include <QPainter>
#include <QTimer>
#include "ui_mainWindow.h"
#include <string>
#include <QObject>
#include "res.h"

class VideoByFrame : public QObject
{
	Q_OBJECT
public:
	VideoByFrame(QWidget* tpparent);
	VideoByFrame();
	void show();
	~VideoByFrame();
	bool fileExistsInDirectory(const QString& directoryPath, const QString& fileName);
	QTimer* timer;
	QWidget* parent = nullptr;
	std::string PATH="";
	std::string path="pixmap";
	std::string strBefore = "normal_98K_attack_frame_";
	std::string strAfter = "";
	std::string type = "png";
	bool stop = false;
	int weishu = 4;
	int speed = 1;
	int index = 0;
	int frameCount = 0;
	int fps = 60;
	void updataPath();
	void updataNumOfFrame();
	void changeVideo(int player,int state);
};
