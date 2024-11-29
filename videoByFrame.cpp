#include "videoByFrame.h"

VideoByFrame::VideoByFrame(QWidget* tpparent)
{
	this->parent = tpparent;
	this->timer = new QTimer(this->parent);
	this->timer->start(1000/this->fps);
	this->updataNumOfFrame();
	connect(this->timer, &QTimer::timeout, [=]() {
		if (!this->stop)
		{
			//std::cout << "videoPath: " << this->PATH << std::endl;
			this->index++;
			if (this->index > this->frameCount)
				this->index = 1;
			this->updataPath();
			this->parent->update();
			//this->updataNumOfFrame();
		}
		});
}

VideoByFrame::VideoByFrame()
{
	int ts = 0;

	//std::cout << "videoPath: \n";
	//char tp[100];
	//std::cin.getline(tp, 100);


	std::cout << "videoNameBeforeindex: \n";
	char tp1[100];
	std::cin.getline(tp1, 100);
	this->strBefore = tp1;

	std::cout << "videoNameAfterindex: \n";
	char tp2[100];
	std::cin.getline(tp2, 100);
	this->strAfter = tp2;

	std::cout << "weishu: \n";
	int index1;
	std::cin >> index1;
	this->weishu = index1;

	std::cout << "frame: \n";
	int index2;
	std::cin >> index2;
	this->index = index2;

	//std::cout << "type: \n";
	//char tp3[100];
	//std::cin.getline(tp3, 100);
	//this->type = tp3;

	this->updataPath();
	std::cout << "videoPath: " << this->PATH << std::endl;


}

void VideoByFrame::show()
{
	QPainter painter(this->parent);
	QImage img(QString::fromStdString(this->PATH));
	painter.drawImage(-380, -390, img);
}

VideoByFrame::~VideoByFrame()
{
}

bool VideoByFrame::fileExistsInDirectory(const QString& directoryPath, const QString& fileName)
{
	// 创建 QDir 对象
	QDir dir(directoryPath);

	// 检查目录是否存在
	if (!dir.exists()) {
		qDebug() << "目录不存在:" << directoryPath;
		return false;
	}

	// 检查指定文件是否存在
	return dir.exists(fileName);
}

void VideoByFrame::updataPath()
{
	char tp[8];
	sprintf(tp, "%0*d",this->weishu, this->index);
	std::string str = this->path + "\\" + this->strBefore + tp + this->strAfter+"."+this->type;
	this->PATH = str;
}

void VideoByFrame::updataNumOfFrame()
{
	char tp[8];
	int res = 1;
	sprintf(tp, "%0*d", this->weishu, res);
	std::string str = this->strBefore + tp + this->strAfter + "." + this->type;
	while (true)
	{
		if (!this->fileExistsInDirectory(QString::fromStdString(this->path), QString::fromStdString(str)))
		{
			break;
		}
		res++;
		sprintf(tp, "%0*d", this->weishu, res);
		str = this->strBefore + tp + this->strAfter + "." + this->type;
	}
	//std::cout << "frameCount: " << res - 1 << std::endl;
	this->frameCount = res - 1;
}

void VideoByFrame::changeVideo(int player,int state)
{

	std::string str="";
	switch (player)
	{
	case zhusha:
	{	
		str += "zhusha";
		break;
	}
	case zhuanjiao:
	{
		str += "zhuanjiao";
		break;
	}
	case normal:
	{
		str += "normal";
		break;
	}
	case up:
	{
		str += "up";
		break;
	}	
	default:
	{
		std::cout << "error player:"<< player << std::endl;
		return;
	}
	}		
	str += "_98K";
	switch (state)
	{
	case attack:
	{
		str += "_attack";
		break;
	}
	case die:
	{
		str += "_die";
		break;
	}
	case pick:
	{
		str += "_pick";
		break;
	}
	case sit:
	{
		str += "_sit";
		break;
	}
	case snipe:
	{
		str += "_snipe";
		break;
	}
	case victory:
	{
		str += "_victory";
		break;
	}
	case lying:
	{
		str += "_lying";
		break;
	}
	case move:
	{
		str += "_move";
		break;
	}
	case move_room:
	{
		str += "_move(1)";
		break;
	}
	case wait:
	{
		str += "_wait";
		break;
	}
	case wait_room:
	{
		str += "_wait(1)";
		break;
	}
	default:
	{
		std::cout << "error state:" << state << std::endl;
		return;
	}
	}
	str += "_frame_";
	this->strBefore = str;
	std::cout << "strBefore: " << this->strBefore << std::endl;
	this->strAfter = "";
	this->weishu = 4;
	this->index = 1;
	this->updataNumOfFrame();
	this->type = "png";
}
