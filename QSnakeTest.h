#include "QSnake.h"

class QSnakeTest: public QSnake
{
    public:
        QSnakeTest():QSnake(NULL){;}
        QSnakeTest(QWidget *parent, s_vec2i max={50, 50});
        void keyPressEvent(QKeyEvent *keyEvent);
    
    public slots:
        void timeOutSlot();

    private:
        bool m_bMove=true;
        int m_depType=1;
};
