#include "ejercicios.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int selec_eje (){
    int selected;
    cout<<"cual problema va a probar?"<<endl;
    cin>>selected;
    return selected;
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

void Prob2()
{
    char letras[200];
    int contador[26] = {0};


    for (int i = 0; i < 200; i++)
    {
        letras[i] = 'A' + (rand() % 26);
        cout << letras[i];

        contador[letras[i] - 'A']++;
    }

    cout << "\nFrecuencias:" << endl;

    for (int i = 0; i < 26; i++)
    {
        if (contador[i] > 0)
        {
            cout << (char)('A' + i) << ": " << contador[i] << endl;
        }
    }
}

int cadenaAEntero(char *cadena)
{
    int resultado = 0;
    int i = 0;

    while (cadena[i] != '\0')
    {
        resultado = (resultado * 10) + (cadena[i] - '0');
        i++;
    }

    return resultado;
}

void Prob4()
{
    char entrada[100];
    cout << "Ingrese una cadena de numeros: ";
    cin >> entrada;

    int numeroConvertido = cadenaAEntero(entrada);

    cout << "La cadena convertida a int es: " << numeroConvertido << endl;
}

void convertirAMayusculas(char *cadena)
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
        i++;
    }
}

void Prob6()
{
    char entrada[100];
    cout << "Ingrese una cadena: ";

    cin.ignore();
    cin.getline(entrada, 100);

    cout << "Original: " << entrada << endl;

    convertirAMayusculas(entrada);

    cout << "En mayuscula: " << entrada << endl;
}

void separarTextoYNumeros(char *original, char *texto, char *numeros)
{
    int i = 0, j = 0, k = 0;

    while (original[i] != '\0')
    {
        if (original[i] >= '0' && original[i] <= '9')
        {
            numeros[j] = original[i];
            j++;
        } else
        {
            texto[k] = original[i];
            k++;
        }
        i++;
    }

    numeros[j] = '\0';
    texto[k] = '\0';
}

void Prob8()
{
    char original[100];
    char soloTexto[100];
    char soloNumeros[100];

    cout << "Ingrese la cadena: ";

    cin.ignore();
    cin.getline(original, 100);

    separarTextoYNumeros(original, soloTexto, soloNumeros);

    cout << "Original: " << original << endl;
    cout << "Texto: " << soloTexto << ". Numero: " << soloNumeros << endl;
}
