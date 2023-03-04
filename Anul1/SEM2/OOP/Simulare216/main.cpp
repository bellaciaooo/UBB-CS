#include "Simulare216.h"
#include <QtWidgets/QApplication>
#include "service.h"
#include "ElevGUI.h"
#include "repo.h"

void addElevi(string fileName)
{
    ofstream g(fileName);
    g << "123092 Simbotin Flavius 12 9.87\n";
    g << "720012 Salcedo Bella 12 10\n";
    g << "203900 Sarb Stefan 11 8.76\n";
    g << "720312 Antonescu Ela 8 4.67\n";
    g << "132333 Popa Camelia 12 9.99\n";
    g << "349992 Popescu Cristian 10 7.87\n";
    g << "230012 Floare Constantin 9 5.23\n";
    g << "555012 Copacescu Florian 8 7.99\n";
    g << "445012 Bucur Mihai 11 9.23\n";
    g << "124562 Andreescu Cosmin 9 3.24\n";
    g.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    addElevi("elevi.txt");
    repo rep("elevi.txt");
    service srv{ rep };

    ElevGUI gui{ srv };
    gui.show();

    return a.exec();
}
