/// some assumptions:
/// used i as id, n as null or no imput,

#include<bits/stdc++.h>
using namespace std;

map<int, pair<char, string>> reduce;
map<pair<int, char>, pair<char, int>> parse_table;


bool parse()
{
	stack<int> st; st.push(0);// will contain state numbers
	string symbol = "";
	string input; cout << endl << "Enter the string to parse : "; cin >> input; input += '$';
	int i; i = 0;


	cout << endl << endl << endl ;
	int j = 0;
	string s = "Stack"; for (auto it: s) {cout << it; j++;} for (; j < 20; j++) cout << " "; ;
	s = "Symbol"; for (auto it: s) {cout << it; j++;} for (; j < 30; j++) cout << " ";
	s = "input"; for (auto it: s) {cout << it; j++;} for (; j < 40; j++) cout << " ";
	s = "Action"; for (auto it: s) {cout << it; j++;} cout << endl;

	while (!st.empty()) {
		int tp = st.top(); char in = input[i];
		char action = parse_table[{tp, in}].first;
		int state = parse_table[{tp, in}].second;


		///output the parsing
		int j = 0;

		stack<int> temp = st;
		vector<int> stcontent;
		while (!temp.empty()) {
			stcontent.push_back(temp.top());
			temp.pop();
		}
		reverse(stcontent.begin(), stcontent.end());
		for (auto it: stcontent) {
			cout << it << " ";
			j += 2;
		} for (; j < 20; j++) cout << " ";

		for (auto it: symbol) {
			cout << it;
			j++;
		} for ( ; j < 30; j++) cout << " ";

		for (int k = i; k < input.size(); k++, j++) cout << input[k];
		for ( ; j < 40; j++) cout << " ";

		/// almost end of output area (still gotta output action


		if (action == 'a') {
			cout << "accept" << endl;
			return 1;
		}

		if (action == 's') {
			st.push(state);

			if (input[i] == '$') {
				cout << "Error" << endl;
				return 0;
			}
			symbol += input[i++];

			cout << "shift" << endl;
		}

		else if (action == 'r') {
			char left; string right;
			left =  reduce[state].first;
			right = reduce[state].second;

			cout << "reduce " << left << "->" << right << endl;

			string temp = "";
			reverse(symbol.begin() ,symbol.end());
			temp += left;
			for (int k = right.size(); k < symbol.size(); k++) temp += symbol[k];
			symbol = temp;
			reverse(symbol.begin(), symbol.end());

			for (int k = 0; k < right.size(); k++) st.pop();

			//cout << st.top() << " " << left << " " << parse_table[{st.top(), left}].second << endl;
			st.push(parse_table[{st.top(), left}].second);
		}

		else {
			cout << "Error" << endl;
			return 0;
		}
	}

	return 0;

}


int main()
{
	/// taking reductions
	cout << "Enter number of reductions: ";
	int r; cin >> r; cin.ignore();

	cout << "Enter the reduction rules in format S->R (serially as assumed r value on table)" << endl;
	for (int i = 0; i < r; i++) {
		cout << i+1 << "  "; string s; getline (cin, s);
		string temp; for (auto it: s) if (it != ' ') temp += it;

		s = "";
		for (int i = 3; i < temp.size(); i++) s += temp[i];

		reduce[i+1] = {temp[0], s};

	}
	// check reductions
	//for (auto it: reduce) cout << it.second << " " << it.first << endl;


	///taking the parse table
	cout << endl << endl <<  "Enter number of states: ";
	int states; cin >> states; cout << endl;


	string term = "", nonterm = "";

	int terminal; cout << "Enter number of terminals: "; cin >> terminal;
	cout << "Enter the terminals: ";
	for (int i = 0; i < terminal; i++) {
		char ch; cin >> ch; term += ch;
	} term += '$';

	int nonterminal;  cout << endl << "Enter number of non-terminals: "; cin >> nonterminal;
	cout << "Enter the non-terminals: ";
	for (int i = 0; i < nonterminal; i++) {
		char ch; cin >> ch; nonterm += ch;
	}

	cout << endl << endl << "Enter the action for state-terminal/nonterminal list given below in form (n, sn, rn, ac, 'n'(for null)) where n is an integer: " << endl;
	for (int i = 0; i < states; i++) {
		for (auto it: term) {
			cout << i << " - " << it << " : ";
			string temp; cin >> temp;

			if (temp == "n") continue;

			char ch = temp[0];
			int n = 0;
			if (temp == "ac") {
				parse_table[{i, it}] = {ch, n};
				continue;
			}

			for (int j = 1; j < temp.size(); j++) {
				n = n*10 + (temp[j] - '0');
			}

			parse_table[{i, it}] = {ch, n};
		}

		for (auto it: nonterm) {
			cout << i << " - " << it << " : ";
			string temp; cin >> temp;

			if (temp == "n") continue;

			int n = 0; char ch = ' ';
			for (int j = 0; j < temp.size(); j++) {
				n = n*10 + (temp[j] - '0');
			}

			parse_table[{i, it}] = {ch, n};
		}
	}

	//check the parse table
	for (auto it: parse_table) cout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << endl;


	if (parse()) puts("ACCEPTED.");
	else puts("NOT ACCEPTED.");

}

/*
E->E+T
E->T
T->T*F
T->F
F->(E)
F->i

i + * ( )

E T F
*/

