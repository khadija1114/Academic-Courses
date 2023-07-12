/// assuming X = S'

#include<bits/stdc++.h>
using namespace std;
map<char, bool> vis;
map<char, set<char>> frst, follow;
char S = 'S', C = 'C', X = 'X', N = 'N', i = 'i', t = 't', b = 'b', e = 'e';

void calculate_first( )
{
		frst[S].insert(i);
		frst[X].insert(e);
		frst[X].insert(N);
		frst[C].insert(b);
		frst[i].insert(i);
		frst[e].insert(e);
		frst[b].insert(b);
		frst[t].insert(t);
}

int main()
{
	calculate_first();

	follow[S].insert('$');

	string s = "iCtSX";
	for (int j = 0; j < s.size(); j++) {
		if (s[j] == i || s[j] == e || s[j] == b || s[j] == t) continue;


		if (j < s.size()-1) {
			for (auto it: frst[s[j+1]])
				if (it != 'N') follow[s[j]].insert(it);
				else {
					for (auto it: follow[S])
						follow[s[j]].insert(it);
				}
		} else {
			for (auto it: follow[S])
						follow[s[j]].insert(it);
		}
	}

	s = "eS";
	for (int j = 0; j < s.size(); j++) {
		if (s[j] == i || s[j] == e || s[j] == b || s[j] == t) continue;

		if (j < s.size()-1) {
			for (auto it: frst[s[j+1]])
				if (it != 'N') follow[s[j]].insert(it);
				else {
					for (auto it: follow[X])
						follow[s[j]].insert(it);
				}
		} else {
			for (auto it: follow[X])
						follow[s[j]].insert(it);
		}
	}


	cout << "First pos : " << endl;
	for (auto it: frst) {
		cout << it.first << "      ";
		for (auto itt: it.second)
			cout << itt << " ";
		cout << endl;
	}

	cout << endl << endl;

	cout << "Follow pos : " << endl;
	for (auto it: follow) {
		cout << it.first << "      ";
		for (auto itt: it.second)
			cout << itt << " ";
		cout << endl;
	}

}

