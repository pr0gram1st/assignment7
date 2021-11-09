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
    return 0;
}
