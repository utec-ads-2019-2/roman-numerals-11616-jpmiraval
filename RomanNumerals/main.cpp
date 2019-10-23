#include <iostream>

using namespace std;

int convertir(char ch){
    switch(ch){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int main() {

    string line;

    long numeros[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    std::string Romanos[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

    while(cin >> line){
        long resultadoNumerico = 0;
        string resultadoRomano = "";

        if(isalpha(line[0])){
            for (int i = 0; i < line.size(); ++i) {
                if(convertir(line[i+1])>convertir(line[i]))
                    resultadoNumerico -= convertir(line[i]);
                else
                    resultadoNumerico += convertir(line[i]);
            }
            cout << resultadoNumerico << endl;
        }else{
            long numero = stol(line);

            int i=12;
            while(numero>0){
                long divicion = numero/numeros[i];
                numero = numero%numeros[i];
                while(divicion--){
                    resultadoRomano += Romanos[i];
                }
                --i;
            }
            cout << resultadoRomano << endl;

        }
    }

    return 0;
}