#include "QSnakeTest.h"

QSnakeTest::QSnakeTest(QWidget *parent, s_vec2i max):QSnake(parent, max)
{
    m_dbg=true;
    m_basicLen=100;
}

void QSnakeTest::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
        case Qt::Key_Escape:
            break;
        case Qt::Key_Up:
            if(m_depType)
                m_apple.y++;
            else
                Snake_genRand::move();
            m_bMove=true;
            break;
        case Qt::Key_Down:
            m_apple.y--;
            m_bMove=true;
            break;
        case Qt::Key_Right:
            if(m_depType)
                m_apple.x++;
            else
            {
                change_dir(3);
                Snake_genRand::move();
            }
            m_bMove=true;
            break;
        case Qt::Key_Left:
            if(m_depType)
                m_apple.x--;
            else
            {
                change_dir(1);
                Snake_genRand::move();
            }
            m_bMove=true;
            break;
        case Qt::Key_D:
            m_dbg=!m_dbg;
        case Qt::Key_R:
            if(m_dead)
                snake_init();
            m_bMove=true;
            break;
        case Qt::Key_Space:
            m_depType=1-m_depType;
            break;
    }
}

void QSnakeTest::timeOutSlot()
{
    if(m_bMove)
    {
        if(!m_bFood)
            set_food(true);
        fillViewTab();
        sensorUpdate();
        if(m_dbg)
        {
            sensorDbg();
            std::cout << std::endl << std::endl;
        }
        m_bMove=false;

    }
    updateGL();
}
