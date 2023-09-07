#include<bits/stdc++.h>
using namespace std;
map<int, char> lw, up;


string Caesar_cipher(string s, int k)
{
	for (auto &it: s) {
		if (it >= 'a' && it <= 'z') it = lw[(it - 'a'  + k + 26) % 26];
		else if (it >= 'A' && it <= 'Z') it = up[(it - 'A'  + k + 26) % 26];
	}

	return s;
}



int main()
{
	string k1 = "KBCAFGLMNPQSTRDEHIJOVUWXZY";
	string k2 = "yzxwuvojihedrtsqpnmlgfacbk";

	for (int i = 0; i < 26; i++) {
		lw[i] = k2[i];
		up[i] = k1[i];
	}

	for (auto it: lw) {
		cout << it.first << " " << it.second << endl;
	}
	for (auto it: up) {
		cout << it.first << " " << it.second << endl;
	}

	string s; cout << "message: ";getline(cin, s);
	string cipher_text = Caesar_cipher(s, 0);
	cout << "Caeser cipher-text: " << cipher_text << endl;
}

