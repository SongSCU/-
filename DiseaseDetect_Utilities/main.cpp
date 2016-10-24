/**************************************************************************
File:         main.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "MainWin.h"
#include <QtWidgets/QApplication>
#include "ViewStyle.h"

//����Ӧ�ó���ȫ�ַ��
void setAppStyle(QApplication & a);
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	setAppStyle(a);
	CMainWin w;
	w.showMaximized();
	return a.exec();
}
void setAppStyle(QApplication & a) {
	CViewStyle::sSetAppStyle(a);
}