#include <iostream>
#include "Callcenter.h"
#include "Anrufer.h"
#include <thread>
#include <time.h>

using namespace std;


unsigned int anruferCount = 20;

int main() {
    srand (time(NULL));

    // Callcenter gruenden (Zahl mitarbeiter festlegen)
    Callcenter *telewerkGmbH = new Callcenter(3);


   // cout << telewerkGmbH->printInfo();


    vector<std::thread> anruferThreadListe;
    vector<Anrufer*> anruferListe;
    anruferThreadListe.reserve(anruferCount);
    anruferListe.reserve(anruferCount);

    for (unsigned int i = 0; i < anruferCount; i++){
        Anrufer* anrufer = new Anrufer(telewerkGmbH);
        anruferThreadListe.push_back(std::thread(&Anrufer::call, anrufer));
        anruferListe.push_back(anrufer);
    }

    while(true){
        for (auto& anrufer : anruferListe){
            cout << anrufer->getMyNumber() << ": " << anrufer->getStatusText() << endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
    }

    for (auto& t : anruferThreadListe){
        t.join();
    }

    return 0;
}