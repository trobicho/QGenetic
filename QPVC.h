#pragma once
#include "WinGL.h"
#include "../genetic/PVC.h"

class QPVC: public WinGL, public PVC
{
    Q_OBJECT
    public:
        QPVC(int nbCitys, s_vec2i min, s_vec2i max):QPVC(NULL, nbCitys, min, max){;}
        QPVC(QWidget *parent, int nbCitys, s_vec2i min, s_vec2i max);
        ~QPVC(){;}
        void paintGL();
};
