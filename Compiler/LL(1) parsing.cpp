/*assumptions
Upper cases are non terminal
lower cases are terminal
S' = X, empty/epsilon/$ = N

grammar is:
S -> iCtSX|a
X -> eS|N
C -> b

*/
#include<bits/stdc++.h>
using namespace std;
map<pair<char, char>, string> mp; //mp[S, a] = a, for S->a
char S = 'S', X = 'X', C = 'C', a = 'a', b = 'b', i = 'i', e = 'e', t = 't', N = 'N';

void table()
{
	mp[make_pair(S, a)] = "a";
	mp[make_pair(S, i)] = "iCtSX";
	mp[make_pair(X, e)] = "eS"; // priotising else
	mp[make_pair(X, N)] = "N";
	mp[make_pair(C, b)] = "b";

}

void parse(string input)
{
	stack<char> st;
	string matched = "";
	st.push('$');
	st.push(S);
	input += '$';
	int i = 0; int k = 0;

	cout << endl << endl << "matched   stack   input  action" << endl;
	cout << matched << "          ";
			stack<char> temp = st;
			while (!temp.empty()) {
				cout << temp.top();
				temp.pop();
			} cout << "       ";
			for (int j = i; j < input.size(); j++) cout << input[j]; cout << "     ";
			cout << endl;

	while (!st.empty()){
		char cur = st.top(); st.pop();

		if (cur == N && input[i] != '$') {
			continue;
		}
		if (cur == '$' && input[i] == '$') {
			cout << "ACCEPTED!" << endl;
			return ;
		} else if (cur != '$' && input[i] == '$') {
			if (mp[{cur, N}].size() > 0) {
				string prod = mp[make_pair(cur, N)];

				cout << matched << "          ";
				stack<char> temp = st;
				while (!temp.empty()) {
					cout << temp.top() ;
					temp.pop();
				}  cout << "       ";
				for (int j = i; j < input.size(); j++) cout << input[j]; cout << "     ";
				cout << cur << " -> " << prod;
				cout << endl;
			} else {
				cout << "ERROR!!" << endl;
				return ;

			}

			continue;
		}

		if (cur == input[i]) {
			matched += input[i];
			i++;

			cout << matched << "          ";
			stack<char> temp = st;
			while (!temp.empty()) {
				cout << temp.top();
				temp.pop();
			} cout << "       ";
			for (int j = i; j < input.size(); j++) cout << input[j]; cout << "     ";
			cout << "matched " << cur;
			cout << endl;

		} else {
			string prod = mp[make_pair(cur, input[i])];
			for (int j = prod.size()-1; j >= 0; j--) st.push(prod[j]);

			cout << matched << "          ";
			stack<char> temp = st;
			while (!temp.empty()) {
				cout << temp.top() ;
				temp.pop();
			}  cout << "       ";
			for (int j = i; j < input.size(); j++) cout << input[j]; cout << "     ";
			cout << cur << " -> " << prod;
			cout << endl;

		}

	}

	cout << "NOT ACCEPTED!!" << endl;
}

int main()
{
	table();
	cout << "Enter the String to parse: ";
	string input; cin >> input;

	parse(input);
}
