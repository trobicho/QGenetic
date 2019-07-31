#include "MainWin.h"

MainWin::MainWin(): QMainWindow(), m_centralZone()
{
    setCentralWidget(&m_centralZone);
}

void MainWin::addSubWin(QWidget *win)
{
    m_centralZone.addSubWindow(win);
}
