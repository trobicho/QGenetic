#include "QPVC.h"
#include <iostream>

QPVC::QPVC(QWidget *parent, int nbCitys, s_vec2i min, s_vec2i max):\
WinGL(60, parent, "teste"), PVC(nbCitys, min, max)
{
}

void QPVC::paintGL()
{
    int *path=NULL;
    if(m_bestGene)
        path=m_bestGene;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(0, m_max.x, 0, m_max.y, -1, 100);
    glBegin(GL_LINE_STRIP);
    glColor3ub(0xFF, 0xFF, 0xFF);
    for(int i=0; i<=m_nbCitys; i++)
    {
        if(!path)
            glVertex2i(m_city[i].x, m_city[i%m_nbCitys].y);
        else
            glVertex2i(m_city[path[i]].x, m_city[path[i%m_nbCitys]].y);
    }
    glEnd();
    
    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3ub(0xF0, 0, 0);
    for(int i=0; i<m_nbCitys; i++)
    {
        glVertex2i(m_city[i].x, m_city[i%m_nbCitys].y);
    }
    glEnd();
}
