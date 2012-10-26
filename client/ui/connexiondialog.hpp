#ifndef CONNEXIONDIALOG_HPP
#define CONNEXIONDIALOG_HPP

#include <QDialog>
#include <QHostAddress>

class QSpinBox;

namespace UI {

class ConnexionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnexionDialog(QWidget *parent = 0);

    const QHostAddress& address() const;

    static QHostAddress promptConnexion(QWidget* parent);

private:
    QSpinBox* m_spins[4];
    QHostAddress m_address;

    QWidget* createConnexionToHostGroupBox();
    QWidget* createLocalServerGroupBox();

signals:

private slots:
    void onToHostClick();
    void onLocalClick();
};

}

#endif // CONNEXIONDIALOG_HPP
