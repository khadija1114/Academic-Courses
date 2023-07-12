/*
some assumptions:
we won't be needing more than 9 temporary variables
there are no brackets in the given input
given variables are of length 1
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; getline(cin, s);

	/// dividing LHS and RHS
	string temp, init = "";
	int i = 0; while (s[i]  != '='){ if (s[i] != ' ') init += s[i]; i++; } i++;
	while (i < s.size()) { if (s[i] != ' ') temp += s[i]; i++; }

	int sz = temp.size(); s = temp;
	//cout << init << " " << s << endl;

	int mul = 0, div = 0, add = 0, sub = 0;
	for (auto it: s) {
		if (it == '*') mul++;
		else if (it == '/') div++;
		else if (it == '+') add++;
		else if (it == '-') sub++;
	}

	map<int, string> tac; int tac_id = 1;// three address code

	/// handle multiplication and divition
	while (mul || div) {
		temp = ""; bool found = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i < s.size()-1 && s[i+1] == '*' && !found) {
				string now = "";
				now+=s[i]; now+=s[i+1]; now+=s[i+2];
				tac[tac_id] = now;
				temp += (tac_id+'0');
			//	cout << tac[tac_id] << endl;
				mul--; tac_id++; i+=2;
				found = 1;
			} else if (i < s.size() && s[i+1] == '/' && !found) {
				string now = "";
				now+=s[i]; now+=s[i+1]; now+=s[i+2];
				tac[tac_id] = now;
				temp += (tac_id+'0');
				div--; tac_id++; i+=2;
				found = 1;
			} else {
				temp += s[i];
			}
		}

		s = temp;
		//cout << s << endl;
	}

	while (add || sub) {
		temp = ""; bool found = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i < s.size()-1 && s[i+1] == '+' && !found) {
				string now = "";
				now+=s[i]; now+=s[i+1]; now+=s[i+2];
				tac[tac_id] = now;
				temp += (tac_id+'0');
				add--; tac_id++; i+=2;
				found = 1;
			} else if (i < s.size() && s[i+1] == '-' && !found) {
				string now = "";
				now+=s[i]; now+=s[i+1]; now+=s[i+2];
				tac[tac_id] = now;
				temp += (tac_id+'0');
				sub--; tac_id++; i+=2;
				found = 1;
			} else {
				temp += s[i];
			}
		}

		s = temp;
		//cout << s << endl;
	}

	for (auto it: tac) {
		cout << "t" << it.first << " = ";
		for (auto itt: it.second) {
		//	cout << (it >= '0' && it <= '9') ? cout << "t" << it : cout << it;
			if (itt >= '0' && itt <= '9') cout << "t" << itt;
			else cout << itt;
		} cout << endl;
	} cout << init << " = t" << s;

}

