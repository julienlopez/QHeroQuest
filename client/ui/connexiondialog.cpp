#include "connexiondialog.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>

namespace UI {

ConnexionDialog::ConnexionDialog(QWidget *parent) :
    QDialog(parent), m_localserver(false)
{
    for(quint8 i = 0; i < 4; i++) m_spins[i] = 0;
    setModal(true);
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel* l = new QLabel(tr("Choose a connexion to the game server."));
    layout->addWidget(l);
    QHBoxLayout* hl = new QHBoxLayout;
    hl->addWidget(createConnexionToHostGroupBox());
    hl->addWidget(createLocalServerGroupBox());
    QPushButton* b = new QPushButton(tr("Cancel"));
    connect(b, SIGNAL(clicked()), this, SLOT(reject()));
    layout->addLayout(hl);
    layout->addWidget(b);
    setLayout(layout);
}

const QHostAddress& ConnexionDialog::address() const
{
    return m_address;
}

bool ConnexionDialog::localServer() const
{
    return m_localserver;
}

std::pair<QHostAddress, bool> ConnexionDialog::promptConnexion(QWidget* parent)
{
    ConnexionDialog dialog(parent);
    int res = dialog.exec();
    if(res == QDialog::Rejected) return std::make_pair(QHostAddress(), false);
    return std::make_pair(dialog.address(), dialog.localServer());
}

QWidget* ConnexionDialog::createConnexionToHostGroupBox()
{
    static int addrDefault[] = {127,0,0,1};
    QGroupBox* gb = new QGroupBox(tr("Connexion to a distant server"));
    gb->setMinimumWidth(300);
    QVBoxLayout* layout = new QVBoxLayout;

    QHBoxLayout* hl = new QHBoxLayout;
    for(quint8 i = 0; i < 4; i++) {
        m_spins[i] = new QSpinBox;
        m_spins[i]->setMinimum(0);
        m_spins[i]->setMaximum(255);
        m_spins[i]->setValue(addrDefault[i]);
        hl->addWidget(m_spins[i]);
        if(i < 3) hl->addWidget(new QLabel("."));
    }
    layout->addLayout(hl);

    QPushButton* b = new QPushButton("Connect to host");
    connect(b, SIGNAL(clicked()), this, SLOT(onToHostClick()));
    layout->addWidget(b);

    gb->setLayout(layout);
    return gb;
}

QWidget* ConnexionDialog::createLocalServerGroupBox()
{
    QGroupBox* gb = new QGroupBox(tr("Creation of a local server"));
    gb->setMinimumWidth(300);
    QVBoxLayout* layout = new QVBoxLayout;

    QPushButton* b = new QPushButton("Create server");
    connect(b, SIGNAL(clicked()), this, SLOT(onLocalClick()));
    layout->addWidget(b);

    gb->setLayout(layout);
    return gb;
}

void ConnexionDialog::onToHostClick()
{
    QString adr;
    for(quint8 i = 0; i < 4; i++) {
        adr += QString::number(m_spins[i]->value());
        if(i < 3) adr += ".";
    }
    m_address = QHostAddress(adr);
    m_localserver = false;
    accept();
}

void ConnexionDialog::onLocalClick()
{
    m_address = QHostAddress::LocalHost;
    m_localserver = true;
    accept();
}

}
