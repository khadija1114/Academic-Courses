#include<bits/stdc++.h>
using namespace std;
map<int, char> lw, up;


string Monoalphabetic_cipher(string s)
{
	for (auto &it: s) {
		if (it >= 'a' && it <= 'z') it = lw[(it - 'a')];
		else if (it >= 'A' && it <= 'Z') it = up[(it - 'A' )];
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

	//for (auto it: lw) cout << it.first << " " << it.second << endl;
	//for (auto it: up) cout << it.first << " " << it.second << endl;

	string s; cout << "message: ";getline(cin, s);
	string cipher_text = Monoalphabetic_cipher(s);
	cout << "Monoalphabetic cipher-text: " << cipher_text << endl;
}

