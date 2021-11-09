#include <bits/stdc++.h>
#include "Text_Preprocessor.h"

using namespace std;

int main() {
    char c[1002];
    cin >> c;
    Text_Preprocessor x(c);
    x.preprocess_text();
    int pos = x.search_word("holes");
    if(pos == -1){
        cout << "Word not found!";
    }
    else{
        cout << pos << endl;
    }
    ifstream file;
    file.open("/Users/adiletkemelkhan/CLionProjects/assignment7/Task2.txt");
    ofstream outfile1 ("Thread_1.txt");
    ofstream outfile2 ("Thread_2.txt");
    double *arr = new double[1002];
    double ave = 0;
    for(int i = 0; i < 100; ++i){
        file >> arr[i];
        ave += arr[i];
    }
    ave /= 100;
    for(int i = 0; i < 100; ++i){
        if(arr[i] - ave > 0){
            outfile1 << arr[i] << "\n";
        }
        else{
            outfile2 << arr[i] << "\n";
        }
    }
    outfile1.close();
    outfile2.close();
    return 0;
}
