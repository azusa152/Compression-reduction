#include <iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

#define ORIGINALFILENAME ".\\data\\real.txt"
#define COMPRESSFILENAME ".\\data\\real_test(2,4).txt"
float original_data_array[1000];
int original_data_quantity=0;
string compress_data_array[1000];
int compress_data_quantity=0;

const int kMeanQuantity=2;
const int kGroupQuantity=4;

float mean_array[1000];
int mean_counter=0;

string SAX_array[1000];
int SAX_counter=0;
const double kSAXRange=0.5;

void InputData();
void SAXtoFloat();

int main()
{
    InputData();
    SAXtoFloat();
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

void SAXtoFloat(){
    for(int i=1;i<=compress_data_quantity;i++){
            stringstream ss;
            ss<<compress_data_array[i];
            float v;
            ss>>v;

            cout << v<< endl;
        if(i%kGroupQuantity==0){

        }

    }


}
