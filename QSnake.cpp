#include "QSnake.h"
#include <iostream>

QSnake::QSnake(QWidget *parent, s_vec2i max): Snake_genRand(max), QFitness(40, parent, "teste")
{
    m_max=max;
    grabKeyboard();
    setFixedSize(m_max.x*m_pixSize, m_max.y*m_pixSize);
}

QSnake::~QSnake()
{
    if(m_fitnessObj)
        delete m_fitnessObj;
}

void QSnake::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(0, m_max.x, 0, m_max.y, -1, 100);
    paintSnake();
}

void QSnake::paintSnake()
{
    int dir=m_snake.dir, r=0;
    s_vec2i v=m_snake.head;
    glPointSize(m_pixSize);
    if(m_dead)
        glColor3ub(0x8F, 0, 0);
    else
        glColor3ub(0xFF, 0xFF, 0xFF);
    glBegin(GL_POINTS);
    for(int i=0; i<m_snake.vLen; ++i)
    {
        glVertex2i(m_snake.body[i].x, m_snake.body[i].y);
    }
    if(m_bFood)
    {
        glColor3ub(0xF0, 0x20, 0);
        glVertex2i(m_apple.x, m_apple.y);
    }
    glEnd();
	if (m_debug)
	{
		glBegin(GL_LINE_STRIP);
        glColor3ub(0x10, 0x20, 0xF0);
		int	dx, dy;
		for (int i = 0; i < m_nbOutPerDir * 2; i++)
		{
			if (m_sensor[m_nbOutPerDir + i] > 0)
			{
				int dir=((!m_snake.dir?3:m_snake.dir-1)+(i % m_nbOutPerDir))%4;
				dx = 0;
				dy = 0;
				if (dir % 2 == 0)
					dx = dir-1;
				else
					dy = dir-2;
				glColor3ub(0x10, 0x20, 0xF0);
				if (i >= m_nbOutPerDir)
					glColor3ub(0xF0, 0x20, 0x10);
				glVertex2i(m_snake.head.x, m_snake.head.y);
				glVertex2i(m_snake.head.x + dx * m_sensor[m_nbOutPerDir + i], m_snake.head.y + dy * m_sensor[m_nbOutPerDir + i]);
			}
		}
		glEnd();
	}
}

void QSnake::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
        case Qt::Key_Escape:
            break;
        case Qt::Key_Right:
            change_dir(3);
            break;
        case Qt::Key_Left:
            change_dir(1);
            break;
        case Qt::Key_S:
            m_bStep=!m_bStep;
        case Qt::Key_Space:
            if(m_dead)
                snake_init();
            else if(m_bStep)
            {
                step();
                sensorDbg();
				std::cout << std::endl;
            }
            else
                m_dead=true;
            break;
    }
}

void QSnake::timeOutSlot()
{
    /*
    if(!m_dead && !m_receiveCopy)
    {
        if(!m_bFood)
            set_food(true);
        fillViewTab();
        sensorUpdate();
        Snake::move();
        if(m_bEat)
        {
            randApple();
            m_bEat=false;
        }
    }
    */
    if(!m_dead && m_receiveCopy)
    {
        if(!m_bStep)
        {
            step();
            step();
            step();
        }
        m_emitDead=false;
    }
    else if(!m_emitDead)
    {
        std::cout << "score=" << m_score << std::endl;
        m_receiveCopy=false;
        emit signal_displayFinish();
        m_emitDead=true;
        snake_init();
        randAppleVec();
    }
    updateGL();
}
