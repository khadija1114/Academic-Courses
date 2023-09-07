#include<bits/stdc++.h>
using namespace std;
map<int, char> lw, up;


string Caesar_cipher(string s, int k)
{
	k %= 26;
	for (auto &it: s) {
		if (it >= 'a' && it <= 'z') it = lw[(it - 'a'  + k + 26) % 26];
		else if (it >= 'A' && it <= 'Z') it = up[(it - 'A'  + k + 26) % 26];
	}

	return s;
}



int main()
{
	for (int i = 0; i < 26; i++) {
		lw[i] = 'a'+i;
		up[i] = 'A'+i;
	}

	for (auto it: lw) {
		cout << it.first << " " << it.second << endl;
	}
	for (auto it: up) {
		cout << it.first << " " << it.second << endl;
	}



	int k; cout << "key: "; cin >> k;cin.ignore();
	string s; cout << "message: ";getline(cin, s);

	string cipher_text = Caesar_cipher(s, k);
	string  plain_text = Caesar_cipher(cipher_text, -k);

	cout << "Caeser cipher-text: " << cipher_text << endl;
	cout << "plain-text: " << plain_text << endl;
}
