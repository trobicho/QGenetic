#pragma once
#include <QThread>
#include "../genetic/GeneticReal.h"

class GeneticWorker: public QThread, public GeneticReal
{
    Q_OBJECT
    public:
        GeneticWorker(QObject *parent, Fitness *fitness, int nbPeoples);

    signals:
        void signal_genFinish(int gen, std::vector<double> &best);

    protected:
        void run();

    private:
        int m_step=1000;
};
