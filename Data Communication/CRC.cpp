#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, l;
    string s;
    vector<int> data;
    cout << "Enter data: ";  // Get data
    cin >> s;
    int datasz = s.size();
    for (auto it: s)
          data.push_back(it-'0');
    vector<int> divisor;
    cout << "Enter divisor: ";      //Get Generator
    cin >> s;
    int divSz = s.size();
    for (auto it: s)
             divisor.push_back (it-'0');

  /// SENDER SIDE
  cout << endl << "SENDER SIDE: " << endl;
    //Append 0's
    int append0 = divSz-1;
    for (i = 0; i < append0; i++)
            data.push_back(0);


    vector<int> tempData = data;
    for (auto it: tempData)  cout << it;
    cout << endl;

     ///Division
    for(i = 0; i < datasz ; i++) {
        j = 0;  k = i;
        if (tempData[k] >= divisor[j])        //checking divisibility
                for(j = 0, k = i; j < divSz; j++, k++)
                          if (tempData[k] == divisor[j] )
                                  tempData[k] = 0;
                          else
                                  tempData[k] = 1;
    }

     ///CRC
     vector<int> crc;
     for(i = 0;  i < append0;  i++)
               crc.push_back(tempData[i+datasz]);
     cout<<"CRC bits: ";
     for (auto it: crc)   cout << it;
              cout << endl;

    cout<<"Transmitted dataword: ";
    vector <int> transmittedData;
    for(i = 0; i < datasz; i++)
              transmittedData.push_back(data[i]);
    for(auto it: crc)
              transmittedData.push_back(it);
    for (auto it: transmittedData)    cout << it;
             cout << endl;


    /// RECEIVERS SIDE
    cout << endl << "RECEIVER SIDE : " << endl;
    vector<int> receivedData = transmittedData;
    cout<<"Received data: ";
    for (auto it: receivedData)    cout << it;
    cout << endl;

    tempData = receivedData;
    ///Division
    for(i = 0; i < receivedData.size(); i++) {
        j = 0;    k = i;
        if (tempData[k] >= divisor[j])
                for(j = 0, k = i; j < divSz; j++, k++)
                            if (tempData[k] == divisor[j])
                                   tempData[k] = 0;
                           else
                                  tempData[k] = 1;
    }

    cout<<"Reminder: ";
    vector<int> reminder = tempData;
    for(i = 0; i < append0; i++)
            cout << reminder[i];
    cout << endl;

    bool hasError = false;
    for(i = 0; i < append0; i++){
            if(reminder[i]){
                    hasError = 1;
                    break;
            }
     }

    if(hasError == 0)
              puts ("Remainder is 0 so there is NO ERROR");
    else
              puts ("Remainder is Not 0 so there is ERROR");
}
