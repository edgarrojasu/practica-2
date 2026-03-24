#include "menu.h"
#include <iostream>
using namespace std;

int selec_eje ()
{
    int selected;
    while (true)
    {
        cout << "Cual problema va a probar?" << endl;
        if (cin >> selected)
        {
            return selected;
        }
        else
        {
            cout << "Ingrese un numero de ejercicio valido." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

bool funcont ()
{
    char yes;

    while (true)
    {
        cout<<endl<<"quiere continuar con otro ejercicio? y/n"<<endl;
        cin>>yes;

        if (yes=='y' ||yes=='Y')
        {
            return true;
        }
        else if (yes == 'n' || yes == 'N')
        {
            return false;
        }
        else
        {
            cout<<"ese caracter no esta en las opciones, seleccione y o n"<<endl;
        }
    }
}
