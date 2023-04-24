#include<iostream>
#include<queue>
using namespace std;

class Process{
    int id, bt, at, ct, tat, wt;
    public:
    void input(Process*,int );
    void calc_fcfs(Process *,int);
    void calc_rr(Process *,int, int);
    void show(Process*,int);
    void sort(Process *, int);
};

void Process::input(Process *p,int n){
    for(int i = 0;i<n;i++){
        cout<<"\nEnter arrival time for process "<<i+1<<":\n";
        cin>>p[i].at;
        cout<<"\nEnter burst time for process "<<i+1<<":\n";
        cin>>p[i].bt;
        p[i].id = i+1;
    }
}

void Process::calc_fcfs(Process*p, int n){
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

void Process::calc_rr(Process *p, int n, int quantum){
    queue<Process> q;
    int time = 0;
    int remaining_burst_time[n];
    for(int i=0;i<n;i++){
        remaining_burst_time[i] = p[i].bt;
    }
    q.push(p[0]);
    int i = 1;
    while(!q.empty()){
        Process current_process = q.front();
        q.pop();
        if(remaining_burst_time[current_process.id-1]<=quantum){
            time = time + remaining_burst_time[current_process.id-1];
            remaining_burst_time[current_process.id-1] = 0;
            p[current_process.id-1].ct = time;
            p[current_process.id-1].tat = p[current_process.id-1].ct - p[current_process.id-1].at;
            p[current_process.id-1].wt = p[current_process.id-1].tat - p[current_process.id-1].bt;
        }else{
            time = time + quantum;
            remaining_burst_time[current_process.id-1] = remaining_burst_time[current_process.id-1] - quantum;
        }
        while(i<n && p[i].at<=time){
            q.push(p[i]);
            i++;
        }
        if(remaining_burst_time[current_process.id-1]>0){
            q.push(current_process);
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
    cout<<"Process\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for(int i = 0;i<n;i++){
cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<"\t"<<p[i].ct<<"\n";
}
}

int main(){
int n, ch, quantum;
cout<<"\nEnter the number of processes:\n";
cin>>n;
Process p[n];
p[0].input(p,n);
p[0].sort(p,n);

/*cout<<"\nEnter time quantum for Round Robin scheduling:\n";
cin>>quantum;
p[0].calc_rr(p,n,quantum);
cout<<"\nResults of Round Robin scheduling:\n";
p[0].show(p,n);
p[0].calc_fcfs(p,n);
cout<<"\nResults of FCFS scheduling:\n";
p[0].show(p,n);*/

do
{
    cout<<"1.FCFS"<<endl;
    cout<<"2.Round Robin"<<endl;
    cout<<"Enter Your Choice"<<endl;
    cin>>ch;
    switch (ch)
    {
    case 1:
        p[0].calc_fcfs(p,n);
        cout<<"\nResults of FCFS scheduling:\n";
        p[0].show(p,n);
        break;
    case 2:
        cout<<"\nEnter time quantum for Round Robin scheduling:\n";
        cin>>quantum;
        p[0].calc_rr(p,n,quantum);
        cout<<"\nResults of Round Robin scheduling:\n";
        p[0].show(p,n);
        break;
 
    default:
        break;
    }
} while (ch!=0);


return 0;


}
