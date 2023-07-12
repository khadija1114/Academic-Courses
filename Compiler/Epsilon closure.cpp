#include<bits/stdc++.h>
using namespace std;
const int maxState = 1000;
map<char, vector<char>> adj_closure;
map<char, set<char>> e_closure;
map<char, bool> vis;

void find_eclosure(char state)
{
	vis[state] = true;
	stack<char> st;
	st.push(state);

	//cout << "start " << endl;

	while (!st.empty()) {
		char next = st.top(); st.pop();
	//	cout << next <<  " ";

		for (auto it: adj_closure[next]) {
		//	cout << "inside loop " << " " << it << " " << vis[it]<< endl;
			if (!vis[it]) {
				vis[it] = true;
				e_closure[state].insert(it);
				st.push(it);
			}
		}

	}

//	cout << endl << endl;
}

int main()
{
	char state, next_state, input;

	cout << "Enter number of table row/entry:";
	int table_entry = 0; cin >> table_entry;

	vector<char> states;
	while (table_entry--) {
		cin >> state >> input >> next_state;
		if (input == 'e') {
			adj_closure[state].push_back(next_state);
		}

		vis[state] = vis[next_state] = false;
	}

	for (auto it: vis) states.push_back(it.first);


	for (auto state: states) {
		for (auto state: states) vis[state] = false;
		find_eclosure(state);
	}

	cout << endl;
	cout << "Number of states: " << states.size() << endl << "States are: " ;
	for (auto it: states) cout << it << " ";
	cout << endl << endl;

	cout << "state" << "  " << "E-Closure" << endl;
	for (auto state: states) {
		cout << state << "      ";
		for (auto e: e_closure[state])
			cout << e << " ";
		cout << endl;
	}
}

/*
7
a e b
a e c
b 1 d
c 1 e
d e f
e e f
f e a
*/
