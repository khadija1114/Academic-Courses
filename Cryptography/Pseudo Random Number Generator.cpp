#include<bits/stdc++.h>
using namespace std;

int main()
{
	int seed, mod, increment, multiplier;
	cout << "seed, multiplier, increment, mod: "; cin >> seed >> multiplier >> increment >> mod;

	int n; cout << "n: "; cin >> n;
	int ar[n+1];
	ar[0] = seed;


	for (int i = 1; i < n; i++) {
		ar[i] = (1LL * ar[i-1] * multiplier + increment) % mod;
	}

	for (int i = 0; i < n; i++) {
		cout << i+1 << "   " << ar[i] << endl;
	}
}
