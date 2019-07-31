#include "WinGL.h"
#include "GeneticWorker.h"
#include "QFitness.h"

class QGenetic: public QWidget
{
    Q_OBJECT
    public:
        explicit QGenetic(QFitness &qfitness, int nbPeoples):\
            QGenetic(NULL, qfitness, nbPeoples){;}
        explicit QGenetic(QWidget *parent, QFitness &qfitness, int nbPeoples);
        ~QGenetic(){};
        std::vector<double>& getBestGene(void){return m_bestGeneCopy;}

    public slots:
        void slot_genFinish(int gen, std::vector<double> &best);
        void slot_displayFinish();

    private:
        GeneticWorker *m_worker;
        int m_generation=1, m_nbGenByPeople;
        QFitness &m_qfitness;
        std::vector<double> m_bestGeneCopy;
};
