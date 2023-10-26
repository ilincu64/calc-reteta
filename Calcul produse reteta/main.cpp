#include <iostream>
#include <string>
#include <vector>
#include "Produs.h"
using namespace std;
int main()
{
    string numeProdus;
    cout << "Introduceti numele produsului: ";
    getline(cin, numeProdus);
    Produs produs(numeProdus);
    int numarIngrediente;
    cout<<"Introduceti numarul de ingrediente: ";
    cin>>numarIngrediente;
    for(int i=0; i<numarIngrediente; i++)
    {
        string ingredient;
        float cantitateNecesara, cantitateDisponibila, cost;
        cout<<"Ingredient "<<i+1<<":"<<'\n';
        cout<<"  Nume: ";
        cin>>ingredient;
        cout<<"  Cantitate necesara: ";
        cin>>cantitateNecesara;
        cout<<"  Cantitate disponibila: ";
        cin>>cantitateDisponibila;
        cout<<"  Cost: ";
        cin>>cost;
        produs.adaugaIngredient(ingredient, cantitateNecesara, cantitateDisponibila, cost);
    }
    produs.afiseazaDetalii();
    produs.afiseazaCantitatiNecesare();
    produs.calculeazaCantitatiRamase();
    produs.calculeazaCostNecesar();
    return 0;
}
