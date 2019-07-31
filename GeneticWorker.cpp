#include "GeneticWorker.h"
#include <iostream>

GeneticWorker::GeneticWorker(QObject *parent, Fitness *fitness, int nbPeoples):\
QThread(parent), GeneticReal(fitness, nbPeoples)
{
}

void GeneticWorker::run(void)
{
    for(int i=0; i<(m_step==-1?i+1:m_step); i++)
    {
        nextGen();
        std::cout << "emit Finish gen("<< m_generation << "): " << get_bestScore() << std::endl;
        emit signal_genFinish(m_generation, get_bestGene());
        std::cout << "return to thread" << std::endl << std::endl;
    }
}
