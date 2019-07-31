#include "MainWin.h"
#include "QSnake.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWin win;
    srand(time(NULL));
    s_vec2i max={10, 10};
    QSnake snake(&win);
    QGenetic genetic(&win, snake, 300);

    win.addSubWin(&snake);
    win.show();

    return app.exec();
}
