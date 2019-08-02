#pragma once
#include <vector>
#include "QFitness.h"
#include "../genetic/fitnessFunc/Snake_genRand.h"

class QSnake: public Snake_genRand, public QFitness
{
    public:
        QSnake():QSnake(NULL){;}
        QSnake(QWidget *parent, s_vec2i max={50, 50});
        ~QSnake();
        void paintGL();
        void keyPressEvent(QKeyEvent *keyEvent);
        Fitness* create_newFitnessObject(void){return (m_fitnessObj=new Snake_genRand(m_max));}
        Fitness* get_fitnessObject(void){return m_fitnessObj;}
        int get_nbGene(){return Snake_genRand::get_nbGene();}
        void geneCopy(std::vector<double> &gene){fillNet(gene); m_receiveCopy=true;}
        void geneCopy(std::vector<double> &gene, int gen){if(m_activFoodGen>=0 && gen>=m_activFoodGen){set_food(true);} geneCopy(gene);}

    public slots:
        void timeOutSlot();
    
    protected:
        void paintSnake();
        Snake_genRand *m_fitnessObj=NULL;
        bool m_debug=true;
        int m_pixSize=5;
        bool m_bStep=false;

    private:
        bool m_emitDead=false, m_receiveCopy=false;
};
