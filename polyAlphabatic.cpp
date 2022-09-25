#include<bits/stdc++.h>
using namespace std;

char key[128][129];

void createKey(void){
    int i, j, k, x;
    bool flag;

    for(i=0 ; i<128; i++) {
        key[i][0] = (char) i;

        for(j=1 ; j<129 ; j++) {
            key[i][j] = (i+j)%128 + 1;
        }
    }
}


void encryption(char *str){
    int i, x;
    for(i=0 ; str[i] ; i++) {
        x = i%128 + 1;
        str[i] = key[(int)str[i]][x];
    }
}

void decryption(char *str){
    int i, j, x;
    for(i=0 ; str[i] ; i++) {
        x = i%128 + 1;
        for(j=1 ; j<129 ; j++) {
            if(key[j][x] == str[i]) {
                str[i] = key[j][0];
                break;
            }
        }
    }
}

int main(void){
    int i, j, k;
    char str[10000];

    createKey();
//    for(i=0 ; i<128 ; i++) {
//        cout << endl << i << "=";
//        for(j=0 ; j<129 ; j++) {
//            cout << key[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout << "Enter a string:  ";
    cin.getline (str, 10000);

    encryption(str);
    cout << "\nAfter encryption:  " << str << endl;
    decryption(str);
    cout << "\nAfter decryption:  " << str << endl;
}
