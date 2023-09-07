#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input; int n; cout << "Enter depth and plain-text: "; cin >> n >> input;

    int sz = input.size(), temp = 2*(n-1);
    if (sz%temp) {
        cout << endl;
        for (int i = sz; i < temp *((sz+temp)/temp); i++) input += "$";
    } //cout << input << endl;

    sz = input.size();
    char ch[n][sz];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz; j++)
            ch[i][j] = '.';
    }

    int row = 0; bool flag = true;
    for (int i = 0; i < sz; i++) {
        ch[row][i] = input[i];

        if (row == 0) flag = true;
        if (row == n-1) flag = false;
        if (flag) row++;
        else row--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz; j++)
            cout <<ch[i][j];
        cout << endl;
    }

    string cipher = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz; j++)
            if (ch[i][j] != '.') cipher += ch[i][j];
    }

    cout << endl << "Cipher Text: " << cipher << endl;
}
