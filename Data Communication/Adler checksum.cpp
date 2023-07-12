///Calculation of adler checksum
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int mod = 1e9+7;


int sender(string data)
{
    int dataSize = data.size();

    int checksum = 0, L = 0, R = 1;

    int ind = 0;
    while (ind < dataSize) {
        R = (R + data[ind]) % mod;
        L = (R + L) % mod;

        ind++;
    }

    checksum = (L * 65536 + R);

    return checksum;

}


bool receiver(string data, int checksum)
{
    int dataSize = data.size();

    int ReceivedDataChecksum = 0, L = 0, R = 1;

    int ind = 0;
    while (ind < dataSize) {
        R = (R + data[ind]) % mod;
        L = (R + L) % mod;

        ind++;
    }

    ReceivedDataChecksum = (L * 65536 + R);

    return checksum == ReceivedDataChecksum;

}



int main()
{
    string data = "MUH1901009F";
    int checksum = sender(data);

    cout << checksum << endl;

    ///check if an error occured
    //swap(data[1], data[2]);
    //data[10]--;

    if (receiver(data, checksum))
        cout << "There is no ERROR";
    else
        cout << "There is Error";

    cout << endl;
}



