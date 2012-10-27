#include "regularcommandpannel.hpp"

#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>

UI::RegularCommandPannel::RegularCommandPannel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    QPushButton* b = new QPushButton(tr("Se déplacer"));
    layout->addWidget(b);

    b = new QPushButton(tr("Attaque au corps à corps"));
    layout->addWidget(b);

    b = new QPushButton(tr("Attaque à distance"));
    layout->addWidget(b);

    b = new QPushButton(tr("Lancer un sortilège"));
    layout->addWidget(b);

    b = new QPushButton(tr("Ouvrir un coffre au trésor"));
    layout->addWidget(b);

    b = new QPushButton(tr("Echanger des objets"));
    layout->addWidget(b);

    b = new QPushButton(tr("Tenter de désamorcer un piège"));
    layout->addWidget(b);

    b = new QPushButton(tr("Changer d'équipement"));
    layout->addWidget(b);

    b = new QPushButton(tr("Utiliser un objet spécial"));
    layout->addWidget(b);

    QGroupBox* gb = new QGroupBox(tr("Rechercher..."));

    QVBoxLayout* vl = new QVBoxLayout;

    b = new QPushButton(tr("un trésor"));
    layout->addWidget(b);

    b = new QPushButton(tr("un piège"));
    layout->addWidget(b);

    b = new QPushButton(tr("une porte secrète"));
    layout->addWidget(b);

    b = new QPushButton(tr("un piège sur un coffre"));
    layout->addWidget(b);

    b = new QPushButton(tr("de l'équipement"));
    layout->addWidget(b);

    gb->setLayout(vl);
    layout->addWidget(gb);

    setLayout(layout);
}
