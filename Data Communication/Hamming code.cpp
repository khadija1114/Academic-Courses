#include<bits/stdc++.h>
using namespace std;

string hammingCodeGenerator(string data)
{
    int datasz = data.size(), rb = 1; // rb = redundant bits

    while (1) {
        if (pow(2, rb) >= rb + datasz + 1)
            break;
        rb++;
    }

    int codesz = rb+datasz;
    int code[codesz+1] = {};

    for (int i = 1, j = datasz-1; i <= codesz; i++){
        if (i & (i-1)) // not a power of 2
            code[i] = data[j--] - '0';
    }


    for (int i = 1; i <= codesz; i *= 2) {
        int cnt = 1;
       // cout << i << "    ";

        for (int j = i+1; j <= codesz; j++){
            if (cnt == i){
                j += i-1;
                cnt = 0;
            }
            else {
                cnt++;
                code[i] = code[i]^code[j];
                //cout << j << " ";
            }
        }
        //cout << endl;
    }

    string hammingCode = "";
    for (int i = codesz; i > 0; i--)
        hammingCode += (code[i]+'0');


    return hammingCode;
}

int ErrorChecker (string hammingCode)
{
    int codesz = hammingCode.size();
    int code[codesz+1] = {}, i = codesz;

    for (auto it: hammingCode)
        code[i--] = it-'0';

    code[6] ^= 1; // to make an error
    for (int i = codesz; i > 0; i--)
        cout << code[i] ;
    cout << endl;

    vector <int> errorPos;

    for (int i = 1; i <= codesz; i *= 2) {
        int cnt = 0, val = 0;
        for (int j = i; j <= codesz; j++){
            if (cnt == i){
                j += i-1;
                cnt = 0;
            }
            else {
                cnt++;
                val = val^code[j];
            }
        }
        errorPos.push_back(val);
    }

    int position = 0, temp = 1;
    for (int i = 0; i < errorPos.size(); i++) {
        if (errorPos[i])
            position += temp;
        temp *= 2;
    }

    return position;


}

int main()
{
    string data = "011010";
    string hammingCode = hammingCodeGenerator(data);
    cout << "Hamming code : " << hammingCode << endl;


    int errorPosition = ErrorChecker(hammingCode);
    if (errorPosition)
        cout << "Found ERROR at position : " << errorPosition << endl;
    else
        puts("No ERROR");

}
