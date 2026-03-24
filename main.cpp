#include <iostream>
#include "ejercicios.h"
#include "menu.h"

using namespace std;

int main()
{
    bool conti = true;
    do
    {
        int ejerselec = selec_eje();

        switch (ejerselec)
        {
            case 2:
                Prob2();
                break;
            case 4:
                Prob4();
                break;
            case 6:
                Prob6();
                break;
            case 8:
                Prob8();
                break;
            case 10:
                Prob10();
                break;
            case 12:
                Prob12();
                break;
        }
            conti = funcont();
    }
    while (conti == true);
    return 0;
}
