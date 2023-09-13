#include<bits/stdc++.h>
using namespace std;

int main()
{
    string key, pt; cout << "Enter plaintext and key: "; cin >> pt >> key;

    int ksz = key.size(), psz = pt.size();
    if (psz%ksz) {
        for (int i = psz; i < ksz+ksz*(psz/ksz); i++) pt += "$";
    } //cout << pt << endl;

    psz = pt.size();
    int col = ksz, row = psz/ksz;

    ///getting key val
    map<char, int> mp;
    for (auto it: key) {
        mp[it] = 1;
    }
    int t = 0;
    for (auto &it: mp) it.second = t++;
   // for (auto it: mp) cout << it.first << " " << it.second << endl;

    string keynumbering;
    for (auto it: key) {
        keynumbering += (mp[it]+'0');
    } //cout << keynumbering << endl;


    map<int, int> pos; t = 0;
    for (auto it: keynumbering) {
        pos[it-'0'] = t++;
       //cout << it << " " << t-1 << endl;
    }
    string finekey = "";

    for (int i = 0; i < key.size(); i++) {
        finekey += pos[i]+'0';
    } cout <<"key sequence : " <<  finekey << endl;

    char ch[row][col]; int p = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ch[i][j] = pt[p++];
            cout << ch[i][j];
        }
        cout << endl;
    }

    string cipher = ""; p = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cipher += ch[j][finekey[p%col]-'0'];
        }
        p++;
    }

    cout << endl << cipher << endl;

}
