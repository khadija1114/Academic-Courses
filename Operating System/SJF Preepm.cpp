#include<bits/stdc++.h>
using namespace std;

int findShortest(vector<int> &bt, vector<int> &art, int time)
{
    int p = -1, stime = 100000000;
    for (int i = 0; i < int(bt.size()); i++) {
        if (bt[i] && bt[i] < stime && art[i] <= time) {
            p = i;
            stime = bt[i];
        }
        if (bt[i] && p == -1)
            p = -2;
    }
    return p;
}


int main()
{
    int NoOfProcess;
    printf("No of processes: ");
    scanf("%d", &NoOfProcess);

    vector <int> burstTime(NoOfProcess), arrivalTime(NoOfProcess);
    vector<int> timeOfChart, granttchart;

    printf("Process:      ");
    for (int i = 1; i <= NoOfProcess; i++) printf("%d ", i);
    printf("\nArrival Time: ");
    for (auto &it: arrivalTime) {
            scanf("%d", &it);
    }
    printf("Burst Time:   ");
    for (auto &it: burstTime) {
            scanf("%d", &it);
    }


    int nowTime = 0;
    timeOfChart.push_back(nowTime);

    while (1) {
        int p = findShortest(burstTime, arrivalTime, nowTime);
      //  cout << p << endl;

        if (p == -1) break;
        nowTime++;

        if (p == -2) continue;

        granttchart.push_back(p+1);
        timeOfChart.push_back(nowTime);

        burstTime[p]--;
    }

    printf("\nGrantt chart\n");
    printf("Process  waiting time\n");
    for (int i = 0; i < granttchart.size(); i++){
        cout << granttchart[i];
        while (i+1 < granttchart.size() && granttchart[i] == granttchart[i+1])
            i++;
        cout << " " << timeOfChart[i+1] << endl;

    }
}
