#include "menu.h"
#include <iostream>
using namespace std;

int selec_eje (){
    while (true)
    {
        int selected;
        cout<<"cual problema va a probar?"<<endl;
        cin>>selected;

        /*while (!(cin>>selected))
        {
            cout<<"ingrese una numero de ejercicio valido"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }*/
        return selected;
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
