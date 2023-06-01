#include <iostream>
#include <vector>
using namespace std;

class process
{
    public:
    void fcfs(int n);
    void sjf(int n);
    void priority(int n);
    void rrobin(int n);
};

void process::fcfs(int n)
{
    int bt[20], wt[20], tat[20], avwt=0, avtat=0;
    cout<<"Enter the number of processes: ";
    cin>>n;

    cout<<"\nEnter the burst time for each process:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]: ";
        cin>>bt[i];
    }

    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    for(int i=0;i<n;i++)
        tat[i]=bt[i]+wt[i];

   
    for(int i=0;i<n;i++)
    {
        avwt+=wt[i];
        avtat+=tat[i];
    }
    avwt/=n;
    avtat/=n;

    // Gantt chart
    cout<<"\nGantt Chart:\n";
    cout<<"--------------------------\n";
    for(int i=0;i<n;i++)
        cout<<"|      P["<<i+1<<"]      ";
    cout<<"|\n";
    cout<<"--------------------------\n";
    cout<<"0";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<bt[i];j++)
            cout<<" ";
        cout<<wt[i]+bt[i];
    }
    cout<<"\n\nAverage Waiting Time: "<<avwt;
    cout<<"\nAverage Turnaround Time: "<<avtat;
}

void process::sjf(int n)
{
    int i, j, min_at, min_bt, t = 0, min_index;
    float avgwt = 0, avgtat = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    int at[n], bt[n], wt[n], tat[n];

    for (i = 0; i < n; i++)
    {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> at[i] >> bt[i];
    }

    // Sort processes by at
    for (i = 0; i < n; i++)
    {
        min_at = at[i];
        min_bt = bt[i];
        min_index = i;

        for (j = i + 1; j < n; j++)
        {
            if (at[j] < min_at || (at[j] == min_at && bt[j] < min_bt))
            {
                min_at = at[j];
                min_bt = bt[j];
                min_index = j;
            }
        }

        swap(at[i], at[min_index]);
        swap(bt[i], bt[min_index]);
    }

    // Calculate wt and tat average
    for (i = 0; i < n; i++)
    {
        if (t < at[i])
            t = at[i];

        wt[i] = t - at[i];
        tat[i] = wt[i] + bt[i];
        t += bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    //Gantt chart
    cout << endl << "Gantt chart:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i]; j++)
            cout << "-";
        cout << " ";
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i] - 1; j++)
            cout << " ";
        cout << "P" << i + 1;
        for (j = 0; j < bt[i] - 1; j++)
            cout << " ";
        cout << " ";
    }
    cout << endl;

    // Display avg wt and tat
    cout << endl << "Average waiting time = " << avgwt << endl;
    cout << "Average turn-around time = " << avgtat << endl;
}

void process::priority(int n)
{
    //tbd
}

void process::rrobin(int n)
{
    int quantum, total_time = 0;
    float avwt = 0, avtat = 0;
    vector<int> at, bt, wt, tat, rt;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter quantum time: ";
    cin >> quantum;

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        int a, b;
        cout << "Process " << i+1 << ": ";
        cin >> a >> b;
        at.push_back(a);
        bt.push_back(b);
        rt.push_back(b);
    }

    int currt = at[0]; //currt = current time
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = false;
                if (rt[i] > quantum) {
                    currt += quantum;
                    rt[i] -= quantum;
                }
                else {
                    currt += rt[i];
                    tat.push_back(currt - at[i]);
                    wt.push_back(currt - at[i] - bt[i]);
                    rt[i] = 0;
                }
            }
        }
        if (done) break;
    }

    cout << "Gantt Chart:\n";
    for (int i = 0; i < n; i++) {
        cout << "| P" << i+1 << " ";
    }
    cout << "|\n";

    for (int i = 0; i < n; i++) {
        cout << at[i] << "\t";
    }
    cout << total_time << endl;

    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
        avwt += wt[i];
        avtat += tat[i];
    }

    avwt /= n;
    avtat /= n;

    cout << "\nAverage Waiting Time: " << avwt << endl;
    cout << "Average Turn-Around Time: " << avtat << endl;
}

int main()
{
    process p;
    int ch, int m;
    cout<<"Total no. of processes: ";
    cin>>m;
    cout<<"Select Scheduling:-\n1.FCFS\n2.SJF\n3.Priority\n4.Round Robin\n\nEnter choice:";
    cin>>ch;
    switch(ch)
    {
        case 1:
        p.fcfs(m);
        break;
       
        case 2:
        p.sjf(m);
        break;
       
        case 3:
        //p.priority(m);
        break;
       
        case 4:
        p.rrobin(m);
        break;
       
        default:
        cout<<"ERROR_INVALID_CHOICE"<<endl;
        break;
    }
}


