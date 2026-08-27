#include <iostream>
#include <vector>
using namespace std;

int menu();
double somma(const vector<double>& numeri);
double differenza(const vector<double>& numeri);
double moltiplicazione(const vector<double>& numeri);
double divisione(const vector<double>& numeri);

int main() {

    int n;
    double risultato;

    int scelta;

    do {

        scelta = menu();
        
        if(scelta < 1 || scelta > 5){
            cout << "\nScelta non valida, per favore riprovare." << endl;
        }

    } while(scelta < 1 || scelta > 5);
    
    if(scelta == 5){
        cout << "\nGrazie per la partecipazione!" << endl;
        return 0;
    }

    cout << "\nCon quanti numeri intendi operare? ";
    cin >> n; 
    
    vector<double> numeri(n);
    
        for(int i = 0; i < n; i++) {
            cout << "\nInserisci il numero " << i+1 << ": ";
            cin >> numeri[i];
    }

    switch(scelta) {
    case 1:
        risultato = somma(numeri);
        break;
    case 2:
        risultato = differenza(numeri);
        break;
    case 3:
        risultato = moltiplicazione(numeri);
        break;
    case 4:
        risultato = divisione(numeri);
        break;
    }

    cout << "\nIl risultato dell'operazione è: " << risultato << endl;

    return 0;
}

int menu(){
    
    int scelta1;

    cout << "\nCosa desideri fare?" << endl;
    cout << "\n1. Addizone" << endl;
    cout << "2. Sottrazione" << endl;
    cout << "3. Moltiplicazione" << endl;
    cout << "4. Divisione" << endl;
    cout << "5. Esci" << endl;
    cout << "\nSi prega di selezionare l'opzione desiderata (1-5): ";

    cin >> scelta1;

    return scelta1;
}

double somma(const vector<double>& numeri) {
    
    double risultato = 0;

    for(int i = 0; i < numeri.size(); i++){
        risultato += numeri[i];
    }

    return risultato;

}

double differenza(const vector<double>& numeri) {
    
    double risultato = numeri[0];
    
    for(int i = 1; i < numeri.size(); i++){
        risultato -= numeri[i];
    }
    return risultato;
}

double moltiplicazione(const vector<double>& numeri) {
    
    double risultato = 1;
    
    for(int i = 0; i < numeri.size(); i++){
        risultato *= numeri[i];
    }
    return risultato;
}

double divisione(const vector<double>& numeri) {
   
    double risultato = numeri[0];
   
    for(int i = 1; i < numeri.size(); i++){
       
        if(numeri[i] == 0){
            cout << "\nErrore: divisione per zero!" << endl;
            exit(1);
        }
       
        risultato /= numeri[i];
   
    }
    return risultato;
}