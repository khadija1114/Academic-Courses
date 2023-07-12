///let grammar, E -> E+E | E*E | (E) | id

#include<bits/stdc++.h>
using namespace std;
char d = 'd', add = '+', mul = '*', ob = '(', cb = ')', E = 'E', dollar = '$';


map<pair<char, char>, bool> gt;
void predefine_precedence()
{
	gt[{d, add}] = 1;  gt[{d, mul}] = 1;  gt[{d, ob}] = 1; gt[{d, cb}] = 1; gt[{d, dollar}] = 1;
	gt[{add, add}] = 1;  gt[{add, cb}] = 1; gt[{add, dollar}] = 1;
	gt[{mul, add}] = 1;  gt[{mul, mul}] = 1;  gt[{mul, cb}] = 1; gt[{mul, dollar}] = 1;
	gt[{ob, cb}] = 1;
	gt[{cb, add}] = 1;  gt[{cb, mul}] = 1;  gt[{cb, cb}] = 1; gt[{cb, dollar}] = 1;
}


bool accepted(string &s)
{
	stack<char> st;
	st.push(dollar);

	s += dollar;  int i = 0, n = s.size();
	string action = ""; int lim = 0;

	int j = 0;
	cout << endl;
	string temp = "Stack"; for (auto it: temp) {cout << it; j++;} for (; j < 10; j++) cout << " "; ;
	temp = "Input"; for (auto it: temp) {cout << it; j++;} for (; j < 20; j++) cout << " ";
	temp = "Action"; for (auto it: temp) {cout << it; j++;} for (; j < 30; j++) cout << " "; cout << endl;

	while (!st.empty()) {
		char tp = st.top();

		/// printing
		stack<char> temp = st; string sttop = "";
		int j = 0;
		while (!temp.empty()) {
			sttop += temp.top(); temp.pop();
		}
		reverse(sttop.begin(), sttop.end());

		for (j = 0; j < sttop.size(); j++) cout << sttop[j];
		for ( ; j < 10; j++) cout << " ";

		for (int k = i; k < n; k++, j++) 	cout << s[k];
		for ( ; j < 20; j++) cout << " ";


		/// action
		if (st.top() == dollar && s[i] == dollar) {
			return 1;
		}

		if (gt[{tp, s[i]}]) {
			st.pop();
			if (tp == '(') {
				cout << tp << " = " << s[i++] << endl;
			} else {
				cout << tp << " > " << s[i] << endl;
			}

		} else {
			if (s[i] != dollar) {
				cout << tp << " < " << s[i] << endl;
				st.push(s[i++]);
			} else {
				return 0;
			}

		}

	}

	return 0;
}


int main()
{
	cout << "Enter the string: " ;
	string s; getline(cin, s);

	predefine_precedence();

	if (accepted(s)) {
		puts("Accepted.");
	} else {
		puts("Not Accepted");
	}
}
