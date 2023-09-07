#include<bits/stdc++.h>
using namespace std;

long long p, q, n, phi;

long long bigmod(long long a, long long p)
{
	if (p == 0) return 1;

	long long x = bigmod(a, p/2);
	x = (x*x) % n;
	if (p&1) x = (x*a)%n;

	return x;
}

int main()
{
	p, q; cout << "Enter prime  p and q: "; cin >> p >> q;
	n = p*q; phi = (p-1)*(q-1);

	long long e;
	for (e = 2; e < phi; e++) {
		if (__gcd(e, phi) == 1) break;
	}

	long long d;
	for (d = 2; d < phi; d++) {
		long long mul = e*d;
		if (mul % phi == 1) break;
	}


	cout << "public key, (e, n) = " << e << ", " << n<< endl;
	cout << "private key, (d, n) = " << d << ", " << n << endl;

	long long m; cout << endl << "Enter message: "; cin >> m;
	long long c = bigmod(m, e);
	long long p = bigmod(c, d);
	cout << "Cipher text: " << c << endl;
	cout << "Plain text: " << p << endl;



}
