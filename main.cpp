#include <iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define ORIGINALFILENAME ".\\data\\real.txt"
#define COMPRESSFILENAME ".\\data\\real(2,4).txt"

float original_data_array[10000];
int original_data_quantity=0;

string compress_data_array[10000];
int compress_data_quantity=0;

float reduction_array[10000];
int reduction_data_quantity=0;

const int kMeanQuantity=2;
const int kGroupQuantity=4;

float error_rate=0;
const float kDataMissRate=0.1;


const double kSAXRange=0.5;

void InputData();
void SAXReduction();
float SymbolToFloat(char symbol,int valueStandard);
void ErrorRate();
void Reduction(float value);

int main()
{
    InputData();
    SAXReduction();
    ErrorRate();


    return 0;
}

void InputData(){

    ifstream f;
    f.open(ORIGINALFILENAME);
    while (!f.eof()){
        original_data_quantity++;
        f >> original_data_array[original_data_quantity];

    }
    f.close();
    ifstream g;
    g.open(COMPRESSFILENAME);
    while (!g.eof()){
        compress_data_quantity++;
        g >> compress_data_array[compress_data_quantity];

    }
    g.close();
}

void SAXReduction(){

    float valueStandard=0;
    int randomNumber;
    srand(time(NULL));

    for(int i=1;i<=compress_data_quantity;i++){

            randomNumber=(rand()%1000)+1;

            stringstream ss;
            ss<<compress_data_array[i];
            float v;
            ss>>v;

            if(v!=0){// ¼Æ¦r
                if (randomNumber>(((1-kDataMissRate)*(1-kDataMissRate))*1000)){
                    Reduction(0);
                    for(int j=2; j<=kGroupQuantity;j++){
                        Reduction(0);
                        i++;
                    }
                }

                else{
                    Reduction(v);
                    valueStandard=v;
                }
            }

            else{

                if (randomNumber>((1-kDataMissRate)*1000)){
                    Reduction(0);
                }
                else{
                string a=compress_data_array[i];
                const char *c=a.c_str();
                Reduction(SymbolToFloat(c[0],valueStandard));
                }



            }

    }
}
void Reduction(float value){
    for(int i=0;i<kMeanQuantity;i++){
    reduction_data_quantity++;
    reduction_array[reduction_data_quantity]=value;

    }


}

float SymbolToFloat(char symbol,int valueStandard){
    float minRange=(kSAXRange*-1)*27;
    float maxRange=kSAXRange*27;

    for(int i=1;i<=52;i++){
        if(symbol>=65&&symbol<=90){
                if(symbol==(64+i)){
                    return (valueStandard+(-1*i*(kSAXRange/2)));
                }

        }
        else if(symbol>=97&&symbol<=122){
                if(symbol==(96+i)){
                    return (valueStandard+(i*(kSAXRange/2)));
                }

        }
    }

}
void ErrorRate(){
    for(int i=1;i<=reduction_data_quantity-2;i++){
        error_rate=error_rate+abs(original_data_array[i]-reduction_array[i]);
        cout<<reduction_array[i]<<endl;

    }

    cout<<"this error:"<<error_rate<<endl;
    cout<<"this reduction_data_quantity:"<<reduction_data_quantity<<endl;
    cout<<"this original_data_quantity:"<<original_data_quantity<<endl;
}
