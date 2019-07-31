#include "QGenetic.h"
#include <iostream>

QGenetic::QGenetic(QWidget *parent, QFitness &qfitness, int nbPeoples):\
m_qfitness(qfitness), QWidget(parent)
{
    m_nbGenByPeople=m_qfitness.get_nbGene();
    m_bestGeneCopy.resize(m_nbGenByPeople);
    m_worker=new GeneticWorker(this, m_qfitness.create_newFitnessObject(), nbPeoples);
    connect(m_worker, SIGNAL(signal_genFinish(int, std::vector<double>&)), this, SLOT(slot_genFinish(int, std::vector<double>&)), Qt::BlockingQueuedConnection);
    connect(&m_qfitness, SIGNAL(signal_displayFinish(void)), this, SLOT(slot_displayFinish(void)));
    m_worker->start();
}

void QGenetic::slot_genFinish(int gen, std::vector<double> &best)
{
    m_generation=gen;
    for(int i=0; i<m_nbGenByPeople; i++)
    {
        m_bestGeneCopy[i]=best[i];
    }
    /*
    std::cout << "receive Finish gen: ";
    Fitness *copy=m_qfitness.create_newFitnessObject();
    std::cout << copy->evaluate(m_bestGeneCopy, m_generation) << std::endl;
    delete copy;
    */
}

void QGenetic::slot_displayFinish()
{
    /*
    Fitness *copy=m_qfitness.create_newFitnessObject();
    std::cout << "best gene: " << copy->evaluate(m_bestGeneCopy, m_generation) << std::endl;
    delete copy;
    */
    m_qfitness.geneCopy(m_bestGeneCopy, m_generation);
    std::cout << "receive display" << std::endl;
}
