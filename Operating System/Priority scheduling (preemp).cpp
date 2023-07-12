#include<bits/stdc++.h>
using namespace std;

int findProcess(vector<int> &bt, vector<int> &pr, vector<int> &art, int time)
{
    int p = -1, spr = 100000000;
    for (int i = 0; i < int(bt.size()); i++) {
        if (bt[i] && pr[i] < spr && art[i] <= time) {
            p = i;
            spr = pr[i];
        }
        if (p == -1 && bt[i])
            p = -2;
    }
    return p;
}


int main()
{
    int NoOfProcess;
    printf("No of processes: ");
    scanf("%d", &NoOfProcess);

    vector <int> burstTime(NoOfProcess), priority(NoOfProcess), arrivalTime(NoOfProcess);
    vector<int> timeOfChart, granttchart;

    printf("Process:      ");
    for (int i = 1; i <= NoOfProcess; i++) printf("%d ", i);
    printf("\npriority:     ");
    for (auto &it: priority) {
            scanf("%d", &it);
    }
    printf("Arrival Time: ");
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
        int p = findProcess(burstTime, priority, arrivalTime, nowTime);
        if (p == -1) break;

        nowTime++;
        if (p == -2) continue;

        granttchart.push_back(p+1);
        timeOfChart.push_back(nowTime);

        burstTime[p]--;
    }

    printf("Grantt chart\n");
    printf("Process:     ");
    for (auto it: granttchart) printf("    %d   ",it);
    puts("");
    printf("Waiting time: ");
    for (auto it: timeOfChart) printf("%d      ", it);
}
