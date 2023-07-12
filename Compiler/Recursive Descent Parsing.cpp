/// let Ep = E', Tp = T'

#include<bits/stdc++.h>
using namespace std;

bool E(), T(), Ep(), Tp(), F();

string s;
int ind = 0;

bool F()
{
	//cout << "F " << ind << endl;
	if (s[ind] == '(') {
		ind++;
		if (E()) {
			if (s[ind] == ')') {
				ind++;
				return 1;
			}
		} else
			return 0;
	} else if (s[ind] == 'i') {
		ind++;
		return 1;
	}
}

bool Tp()
{
	//cout << "Tp " << ind << endl;
	if (s[ind] == '*') {
		ind++;
		if (F()) {
			if (Tp())
				return 1;
			else
				return 0;
		} else
			return 0;
	} else
		return 1;
}

bool Ep()
{
	//cout << "Ep " << ind << endl;
	if (s[ind] == '+') {
		ind++;
		if (T()) {
			if (Ep())
				return 1;
			else
				return 0;
		} else
			return 0;
	} else
		return 1;
}

bool T()
{
	//cout << "T " << ind << endl;
	if (F()) {
		if (Tp()) return 1;
		else return 0;
	} else
		return 0;
}

bool E()
{
	//cout << "E " << ind << endl;
	if (T()) {
		if (Ep())
			return 1;
		else
			return 0;
	} else
		return 0;
}

void process()
{
	string temp = "", parse = "";

	for (auto it: s) {
		if (it == '+' || it == '-' || it == '|' || it == '*' || it == '/' || it == ')' || it == '(' || it == '=' || it == '>'|| it == '<') {
			if (temp.size()) {
				parse += 'i';
				parse += it;
				temp = "";
			}
			else {
				parse += it;
			}
		} else {
			temp += it;
		}
	}

	if (temp.size())
		parse += 'i';

	s = parse;
	//cout << parse << endl;
}

int main()
{
	cout << "Enter a String: ";
	while (cin >> s) {
		process();
		ind = 0;

		if (E() && ind == s.size())  cout << "accepted";
		else cout << "Not Accepted";
		cout << endl << endl;

		cout << "Enter a String: ";
	}
}

/*
E->TE'
E'->+TE|N
T->FT'
T`->*FT'| N
F->(E)|ID */
