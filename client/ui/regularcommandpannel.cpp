#include "regularcommandpannel.hpp"

#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>

UI::RegularCommandPannel::RegularCommandPannel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    QPushButton* b = new QPushButton(tr("Se d�placer"));
    layout->addWidget(b);

    b = new QPushButton(tr("Attaque au corps � corps"));
    layout->addWidget(b);

    b = new QPushButton(tr("Attaque � distance"));
    layout->addWidget(b);

    b = new QPushButton(tr("Lancer un sortil�ge"));
    layout->addWidget(b);

    b = new QPushButton(tr("Ouvrir un coffre au tr�sor"));
    layout->addWidget(b);

    b = new QPushButton(tr("Echanger des objets"));
    layout->addWidget(b);

    b = new QPushButton(tr("Tenter de d�samorcer un pi�ge"));
    layout->addWidget(b);

    b = new QPushButton(tr("Changer d'�quipement"));
    layout->addWidget(b);

    b = new QPushButton(tr("Utiliser un objet sp�cial"));
    layout->addWidget(b);

    QGroupBox* gb = new QGroupBox(tr("Rechercher..."));

    QVBoxLayout* vl = new QVBoxLayout;

    b = new QPushButton(tr("un tr�sor"));
    layout->addWidget(b);

    b = new QPushButton(tr("un pi�ge"));
    layout->addWidget(b);

    b = new QPushButton(tr("une porte secr�te"));
    layout->addWidget(b);

    b = new QPushButton(tr("un pi�ge sur un coffre"));
    layout->addWidget(b);

    b = new QPushButton(tr("de l'�quipement"));
    layout->addWidget(b);

    gb->setLayout(vl);
    layout->addWidget(gb);

    setLayout(layout);
}
