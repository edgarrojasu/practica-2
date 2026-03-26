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
void sumaCuadra(int matriz[3][3]);
void llenarMatriz(int *matriz, int n);
void imprimirMatriz(int *matriz, int n);
void rotar90(int *matriz, int n);
void rotar180(int *matriz, int n);
void rotar270(int *matriz, int n);
int calcularCaminos(int n);
void removerDigito(int *arreglo, int &tam, int pos);
int obtenerFactorial(int n);


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

int convertRomAra(char letra)
{
    switch (letra)
    {
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

void Prob12 ()
{
    int cuadrado [3][3];
    int numactu;

    cout<<"Cuadrado magico"<<endl;

    for (int i = 0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<endl<<"Ingre el numero de la posicion ["<<i+1<<"] ["<<j+1<<"]:";
            cin>>numactu;
            cuadrado [i][j] = numactu;
        }
    }

    sumaCuadra(cuadrado);
}

void sumaCuadra(int matriz[3][3])
{
    int fila1;
    int fila2;
    int fila3;
    int sumaHo = 0;
    int colum1;
    int colum2;
    int colum3;
    int sumaVe = 0;
    int sumadiago;
    int sumadiago1=0;
    int sumadiago2=0;

    for (int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sumaHo += matriz [i][j];
        }
        switch (i)
        {
            case 0:fila1=sumaHo;
                break;
            case 1:fila2=sumaHo;
                break;
            case 2:fila3=sumaHo;
                break;
        }
            sumaHo = 0;
    }

    if (fila1 == fila2 && fila2 == fila3)
    {
        sumaHo = fila1;
    }

    for (int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sumaVe += matriz [j][i];
        }
        switch (i)
        {
        case 0:colum1=sumaVe;
            break;
        case 1:colum2=sumaVe;
            break;
        case 2:colum3=sumaVe;
            break;
        }
        sumaVe = 0;
    }

    if (colum1 == colum2 && colum2 == colum3)
    {
        sumaVe = colum1;
    }
    else
    {
        sumaVe = 1;
    }

    for (int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if (i==j)
            {
                sumadiago1 += matriz [j][i];
            }
        }
    }

    int c=2;
    int i=2;
    int j=0;
    while(c>=0)
    {
        sumadiago2 += matriz [i-c][j+c];
        c--;
    }

    if (sumadiago1 == sumadiago2)
    {
        sumadiago = sumadiago1;
    }
    else
    {
        sumaVe = 2;
    }

    if (sumadiago == sumaHo && sumaHo == sumaVe)
    {
        cout<<"El cuadrado:"<<endl;
        for (int i = 0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                cout<<matriz [i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<" es magico!!"<<endl<<"Y la suma es: "<<sumadiago;
    }
    else
    {
        cout<<"El cuadrado:"<<endl;
        for (int i = 0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                cout<<matriz [i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"NO es magico<"<<endl;
    }
}

void Prob14() {
    int matriz[5][5];

    llenarMatriz(&matriz[0][0], 5);

    cout << "Matriz Original:" << endl;
    imprimirMatriz(&matriz[0][0], 5);

    cout << endl << "Matriz Rotada 90 grados:" << endl;
    rotar90(&matriz[0][0], 5);

    cout << endl << "Matriz Rotada 180 grados:" << endl;
    rotar180(&matriz[0][0], 5);

    cout << endl << "Matriz Rotada 270 grados:" << endl;
    rotar270(&matriz[0][0], 5);
}

void llenarMatriz(int *matriz, int n)
{
    int contador = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(matriz + (i * n) + j) = contador++;
        }
    }
}

void imprimirMatriz(int *matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(matriz + (i * n) + j) << "\t";
        }
        cout << endl;
    }
}

void rotar90(int *matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(matriz + ((n - 1 - j) * n) + i) << "\t";
        }
        cout << endl;
    }
}

void rotar180(int *matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(matriz + ((n - 1 - i) * n) + (n - 1 - j)) << "\t";
        }
        cout << endl;
    }
}

void rotar270(int *matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(matriz + (j * n) + (n - 1 - i)) << "\t";
        }
        cout << endl;
    }
}

void Prob16()
{
    int n;

    cout << "Ingrese el tamano n para la cuadricula nxn:" << endl;

    while (!(cin >> n) || n < 1)
    {
        cout << "Ingrese un numero de cuadricula valido (mayor a 0):" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    int caminos = calcularCaminos(n);

    cout << endl << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;
}

int calcularCaminos(int n)
{
    int puntos = n + 1;
    int malla[puntos][puntos];

    int *ptrMatriz = &malla[0][0];

    for (int i = 0; i < puntos; i++)
    {
        for (int j = 0; j < puntos; j++)
        {
            int indiceActual = (i * puntos) + j;

            if (i == 0 || j == 0)
            {
                *(ptrMatriz + indiceActual) = 1;
            }
            else
            {
                int indiceArriba = ((i - 1) * puntos) + j;
                int indiceIzquierda = (i * puntos) + (j - 1);

                *(ptrMatriz + indiceActual) = *(ptrMatriz + indiceArriba) + *(ptrMatriz + indiceIzquierda);
            }
        }
    }

    int indiceFinal = (n * puntos) + n;
    return *(ptrMatriz + indiceFinal);
}

void Prob18() {
    int n;
    cout << "Ingrese el numero n de la permutacion: ";
    cin >> n;

    int objetivo = n - 1;

    int disponibles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamano = 10;

    char resultado[11];

    for (int i = 9; i >= 0; i--) {
        int fact = obtenerFactorial(i);

        int seleccion = objetivo / fact;

        *(resultado + (9 - i)) = *(disponibles + seleccion) + 48;

        removerDigito(disponibles, tamano, seleccion);

        objetivo %= fact;
    }

    *(resultado + 10) = '\0';

    cout << "La permutacion numero " << n << " es: " << resultado << endl;
}

int obtenerFactorial(int n) {
    if (n <= 1) return 1;
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

void removerDigito(int *arreglo, int &tam, int pos) {
    for (int i = pos; i < tam - 1; i++) {
        *(arreglo + i) = *(arreglo + i + 1);
    }
    tam--;
}
