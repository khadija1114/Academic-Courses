#include<bits/stdc++.h>
using namespace std;

int main()
{
    int NoOfProcess;
    printf("No of processes: ")
    scanf("%d", &NoOfProcess);
    vector <int> arrival(NoOfProcess), burstTime(NoOfProcess), granttchart(NoOfProcess);
    vector<int> timeOfChart;

    printf("Process: ");
    for (auto &it: arrival) scanf("%d", &it);
    printf("Burst Time: ");
    for (auto &it: burstTime) scanf("%d", &it);

    int startTime = 0;
    timeOfChart.push_back(startTime);

    for (int i = 0; i < NoOfProcess; i++) {
        int p = arrival[i]-1;
        int endTime = startTime + burstTime[p];
        granttchart[i] = p+1;
        timeOfChart.push_back(endTime);
        startTime = endTime;
    }

    for (auto it: granttchart) printf("    %d   ",it);
    puts("");
    for (auto it: timeOfChart) printf("%d      ", it);
}
