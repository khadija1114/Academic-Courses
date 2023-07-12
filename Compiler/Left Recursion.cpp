#include<bits/stdc++.h>
using namespace std;
map<string, vector<string>> mp;
vector<vector<string>> ans;

void eliminate_LR(string str)
{
	vector<string> with, without, p;

	for (auto it: mp[str]) {
		if (it[0] == str[0]) {
			with.push_back(it);
		} else {
			without.push_back(it);
		}
	}

	string temp = "";
	if (with.size()) {
		for (auto &it: without) {
			it += str;
			it += '\'';
		}
		for (auto &it: with) {
			temp = "";
			for (int i = str.size(); i < it.size(); i++) {
				temp += it[i];
			}
			it = temp + str + '\'';
		}

		with.push_back("$");


		temp = str +  '\'';
	}

	p.push_back(str);
	for (auto it: without) p.push_back(it);
	if (without.size())
	ans.push_back(p);
	p.clear();

	p.push_back(temp);
	for (auto it: with) p.push_back(it);
	if (with.size())
	ans.push_back(p);

}

int main()
{
	string s;
	cout << "enter number of expression: ";
	int n; cin >> n;
	cin.ignore();

	while (n--) {
		getline(cin, s);
		string temp;

		//eliminating space
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') temp += s[i];
		}

		s = temp; temp = "";
		//cout << s << endl;

		int i = 0, sz = s.size();
		while (i+1 < sz && s[i] != '-' && s[i+1] != '>') {
			temp += s[i];
			i++;
		} i += 2;

		string rhs = temp; temp = "";
		//cout << rhs << endl;

		while (i < sz) {
			if (s[i] == '|') {
				mp[rhs].push_back(temp);
				temp = "";
			} else {
				temp += s[i];
			}
			i++;
		}

		mp[rhs].push_back(temp);

		eliminate_LR(rhs);
	}


	for (auto it: ans) {
			cout << it[0] << " -> " << it[1];
			for (int i = 2; i < it.size(); i++)
				cout << " | " << it[i];
			cout << endl;
	}
}
