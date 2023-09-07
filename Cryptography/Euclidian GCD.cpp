#include<bits/stdc++.h>
using namespace std;

long long gcd(int n, int m)
{
	if (m == 0) return n;
	return gcd(m, n%m);
}

int main()
{
	int n; cout << "Enter number of inputs: "; cin >> n;
	long long ar[n], g = 0;
	for (auto &it: ar) cin >> it;

	for (auto it: ar) {
		g = gcd(g, it);
	}


	cout << g << endl;
}
