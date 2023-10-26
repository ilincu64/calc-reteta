#ifndef PRODUS_H
#define PRODUS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Produs
{
    private:
        string nume;
        vector<string> ingrediente;
        vector<float> cantitatiNecesare;
        vector<float> cantitatiDisponibile;
        vector<float> costProdus;
        float costTotal;

    public:
        Produs(string nume)
        {
            this->nume=nume;
            costTotal=0.0;
        }
        void adaugaIngredient(string ingredient, float cantitateNecesara, float cantitateDisponibila, float cost)
        {
            ingrediente.push_back(ingredient);
            cantitatiNecesare.push_back(cantitateNecesara);
            cantitatiDisponibile.push_back(cantitateDisponibila);
            costProdus.push_back(cost);
            costTotal+=(float)cost*cantitateNecesara;
        }

        float getCostTotal()
        {
            return costTotal;
        }

        void afiseazaDetalii()
        {
            cout<<'\n'<<"Nume produs: "<<nume<<'\n';
            cout<<'\n'<<"Ingrediente:"<<'\n';
            for(size_t i=0; i<ingrediente.size(); i++)
                cout<<" - "<<ingrediente[i]<<" ("<<cantitatiNecesare[i]<<" unitati necesare, "<<cantitatiDisponibile[i]<<" unitati disponibile)"<<'\n';
            cout<<"Cost total: "<<costTotal<<'\n';
        }

        void afiseazaCantitatiNecesare()
        {
            cout<<'\n'<<"Cantitati necesare pentru produsul "<<nume<<":"<<'\n';
            for(size_t i=0; i<ingrediente.size(); i++)
                cout<<" - "<<ingrediente[i]<<": "<<cantitatiNecesare[i]<<" unitati"<<'\n';
        }

        void calculeazaCantitatiRamase()
        {
            cout<<'\n'<<"Cantitati lipsa pentru produsul "<<nume<<":"<<'\n';
            for(size_t i=0; i<ingrediente.size(); i++)
            {
                float lipsa=cantitatiNecesare[i]-cantitatiDisponibile[i];
                cout<<" - "<<ingrediente[i]<<": "<<lipsa<<" unitati"<<'\n';
            }
        }
        void calculeazaCostNecesar()
        {
            cout<<'\n'<<"Costul necesar pentru produsul "<<nume<<":"<<endl;
            float CostNecesareTotal=0.0;
            for(size_t i=0; i<ingrediente.size(); i++)
            {
                if (cantitatiDisponibile[i] < cantitatiNecesare[i])
                {
                    float cantitateSuplimentara=cantitatiNecesare[i]-cantitatiDisponibile[i];
                    float costSuplimentar=cantitateSuplimentara*costProdus[i];
                    cout<<" - "<<ingrediente[i]<<": "<<costSuplimentar<<endl;
                    CostNecesareTotal+=costSuplimentar;
                }
            }
            cout<<'\n'<<"Costul necesar total pentru produsul "<<nume<<": "<<CostNecesareTotal<<endl;
        }
};

#endif // PRODUS_H
