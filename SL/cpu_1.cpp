#include<iostream>
#include <vector>
#include<stdlib.h>
using namespace std;

class Process{
    int id, bt, at, ct, tat, wt;
    public:
    void input(Process*,int );
    void calc(Process *,int);
    void show(Process*,int);
    void sort(Process *, int);
		void round(int );

};

int main(){
    int n,ch;
	Process *p = new Process[n];
    Process f;
   do{ 
	cout<<"\n\t1.FCFS \n\t2.Round Robin\n\t3.Exit";
	cout<<"enter the choice ";
cin>>ch;
switch(ch){

case 1:
cout<<"\nEnter the no of processes in your system:\n";
    cin>>n;
    
    f.input(p,n);
    f.sort(p, n);
    f.calc(p,n);
    f.show(p,n);
		break;

case 2: 
		//Process *p = new Process[n];
    //Process f;
		f.round(n);

		break;
}    
}while(ch!=2);
return 0;
}



void Process::round(int n)
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



void Process::input(Process *p,int n){
    for(int i = 0;i<n;i++){
        cout<<"\nEnter arrival time for process "<<i+1<<":\n";
        cin>>p[i].at;
        cout<<"\nEnter burst time for process "<<i+1<<":\n";
        cin>>p[i].bt;
        p[i].id = i+1;
    }
}

void Process::calc(Process*p, int n){
    int sum = 0;
    sum = sum + p[0].at;
    for(int i = 0;i<n;i++){
        sum = sum + p[i].bt;
        p[i].ct = sum;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt; 
        if(sum<p[i+1].at){
            int t = p[i+1].at-sum;
            sum = sum+t;
        }
    }
}

void Process::sort(Process*p, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                int temp;

                temp = p[j].bt;
                p[j].bt = p[j+1].bt;
                p[j+1].bt = temp;

                temp = p[j].at;
                p[j].at = p[j+1].at;
                p[j+1].at = temp;

                temp = p[j].id;
                p[j].id = p[j+1].id;
                p[j+1].id = temp;
            }
        }
    }
}

void Process::show(Process*p, int n){
    cout<<"Process\tArrival\tBurst\tWaiting\tTurn Around\tCompletion\n";
    for(int i =0;i<n;i++)
	  {
        cout<<"  P["<<p[i].id<<"]\t  "<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t   "<<p[i].tat<<"\t\t"<<p[i].ct<<"\n";
    }
}
