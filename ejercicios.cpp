#include "ejercicios.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void separarTextoYNumeros(char *original, char *texto, char *numeros);
void convertirAMayusculas(char *cadena);
int cadenaAEntero(char *cadena);
int convertRomAra(char letra);
int sumaNumRom(char *numRoman);

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

void Prob4()
{
    char entrada[100];
    cout << "Ingrese una cadena de numeros: ";
    cin >> entrada;

    int numeroConvertido = cadenaAEntero(entrada);

    cout << "La cadena convertida a int es: " << numeroConvertido << endl;
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

void Prob10()
{
    char original[100];
    int numero;

    cout<<"Ingrese los numeros romanos:"<<endl;
    cin>>original;
    convertirAMayusculas(original);

    numero = sumaNumRom(original);

    cout<<endl<<"El numero en arabigo es: "<<numero<<endl;

}

int sumaNumRom(char *numRoman)
{
    int total = 0;
    int numactu;
    int nextnum;
    int numoment = 1;

    int i = 0;
    bool entro = false;

    while (numRoman[i] != '\0')
    {
        numactu = convertRomAra(numRoman[i]);
        nextnum = convertRomAra(numRoman[i+1]);

        if (numactu>=nextnum && entro == false)
        {
            total += numactu;
        }
        else if (numRoman[i+1] != '\0' && entro == false)
        {
            numoment = nextnum;
            numoment -= numactu;
            total += numoment;
            entro = true;
        }
        else
        {
            entro = false;
        }
        i++;
    }
    return total;

}

int convertRomAra(char letra) {
    switch (letra) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return 0;
    }
}
