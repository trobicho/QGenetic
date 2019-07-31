#pragma once
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
//#include <QPushButton>
#include "QGenetic.h"

class MainWin: public QMainWindow
{
    Q_OBJECT
    public:
        MainWin();
        void addSubWin(QWidget *win);

    private:
        QMdiArea m_centralZone;
};
