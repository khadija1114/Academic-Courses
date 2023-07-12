//Calculation of Fletcher checksum
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int mod = 256;


int sender(string data)
{
    int dataSize = data.size();

/*   L adds data items together ,
     R adds weight to the calculation */
    int checksum = 0, L = 0, R = 0;


    int ind = 0;
    while (ind < dataSize) {
        R = (R + data[ind]) % mod;
        L = (R + L) % mod;

       // cout << L << " " << R << endl;

        ind++;
    }



    checksum = (L * 256 + R);

    return checksum;

}


bool receiver(string data, int checksum)
{
    int dataSize = data.size();

    int ReceivedDataChecksum = 0, L = 0, R = 0;

    int ind = 0;
    while (ind < dataSize) {
        R = (R + data[ind]) % mod;
        L = (R + L) % mod;

        ind++;
    }

    ReceivedDataChecksum = (L * 256 + R);

    return checksum == ReceivedDataChecksum;

}



int main()
{
    string data = "MUH1901009F";
    int checksum = sender(data);
    cout << checksum << endl;

    //check if an error occured
    //swap(data[1], data[2]);
    //data[10] = 'f';

    if (receiver(data, checksum))
        puts("There is no ERROR");
    else
        puts("There is Error");

}



