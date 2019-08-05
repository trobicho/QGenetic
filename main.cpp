#include "MainWin.h"
#include "QSnake.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWin win;
    srand(time(NULL));
    s_vec2i max={50, 50};
    QSnake snake(&win);
    QGenetic genetic(&win, snake, 500);

    win.addSubWin(&snake);
    win.show();

    return app.exec();
}
