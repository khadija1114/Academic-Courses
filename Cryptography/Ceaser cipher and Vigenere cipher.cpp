#include<bits/stdc++.h>
using namespace std;

string Caesar_cipher(string s, int k)
{
	for (auto &it: s) {
		if (it >= 'a' && it <= 'z') it = (it - 'a'  + k) % 26 + 'a';
		else if (it >= 'A' && it <= 'Z') it = (it - 'A'  + k) % 26 + 'A';
	}

	return s;
}

string Vigenere(string s, string key)
{
	int i = 0, ks = key.size();
	for (auto &it: s) {
		int k;
		if (key[i] >= 'a' && key[i] <= 'z') k = key[i] -'a';
		else k = key[i] - 'A';
		i++; i %= ks;

		//cout << it << " " << k << " " << i << endl;

		if (it >= 'a' && it <= 'z') it = (it - 'a'  + k) % 26 + 'a';
		else if (it >= 'A' && it <= 'Z') it = (it - 'A'  + k) % 26 + 'A';
	}

	return s;
}

int main()
{
	string s; cout << "message: ";getline(cin, s);
	int k; cout << "key for ceaser cipher: "; cin >> k;
	string key; cout << "key for vegenere cipher: "; cin >> key;

	string caesar = Caesar_cipher(s, k);
	string vig = Vigenere(s, key);

	cout << "Caeser Cipher-text: " << caesar << endl;
	cout << "Vigenere Cipher-text: " << vig << endl;
}
