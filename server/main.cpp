#include <QCoreApplication>

#include "serveur.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Serveur s;
    if(s.start()) return a.exec();
    return EXIT_FAILURE;
}
