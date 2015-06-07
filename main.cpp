#include <iostream>
#include "Callcenter.h"
#include "Anrufer.h"
#include <thread>
#include <time.h>

using namespace std;


unsigned int anruferCount = 20;

int main() {
    cout << "Hello, World!" << endl;
    srand (time(NULL));

    // Callcenter gruenden (Zahl mitarbeiter festlegen)
    Callcenter *telewerkGmbH = new Callcenter(10);


    cout << telewerkGmbH->printInfo();


    vector<std::thread> anruferThreadListe;
    anruferThreadListe.reserve(anruferCount);

    for (unsigned int i = 0; i < anruferCount; i++){
        Anrufer* anrufer = new Anrufer(telewerkGmbH);
        anruferThreadListe.push_back(std::thread(&Anrufer::call, anrufer));
    }
    for (auto& t : anruferThreadListe){
        t.join();
    }


    // anrufer erstellen.
    // 10 Anrufer (Function Object)
    // Aufruf func call als thread
    // try durchkommen or sleep 0/1
    //

    // callcenter nimmt anrufer und steckt in Warteschleife

    // Mitarbeiter holt sich nächsten Anrufer aus Warteschleife

    return 0;
}