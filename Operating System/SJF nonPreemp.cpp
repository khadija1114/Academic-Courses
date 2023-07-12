#include<bits/stdc++.h>
using namespace std;

int findShortest(vector<int> &bt)
{
    int p = -1, stime = 100000000;
    for (int i = 0; i < int(bt.size()); i++) {
        if (bt[i] && bt[i] < stime) {
            p = i;
            stime = bt[i];
        }
    }
    return p;
}


int main()
{
    int NoOfProcess;
    printf("No of processes: ");
    scanf("%d", &NoOfProcess);
    vector <int> burstTime(NoOfProcess);
    vector<int> timeOfChart, granttchart;

    int p = 1;
    printf("Process Burst Time\n");
    for (auto &it: burstTime) {
            printf("%d\t", p++);
            scanf("%d", &it);
    }

    int nowTime = 0;
    timeOfChart.push_back(nowTime);

    while (findShortest(burstTime) != -1) {
        p = findShortest(burstTime);
        int endTime = nowTime + burstTime[p];

        granttchart.push_back(p+1);
        timeOfChart.push_back(endTime);

        nowTime = endTime;
        burstTime[p] = 0;
    }

    printf("Grantt chart\n");
    printf("Process:    ");
    for (auto it: granttchart) printf("    %d   ",it);
    puts("");
    printf("Waiting time: ");
    for (auto it: timeOfChart) printf("%d      ", it);
}
