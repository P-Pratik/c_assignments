#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
   
    int n, capacity;
    cout << "Enter the number of pages: ";
    cin >> n;
    cout << "Enter the capacity of the memory: ";
    cin >> capacity;
   
    vector<int> pages(n);
    cout << "Enter the pages: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
   
    int ch;
    cout<<"------How do you want to perform page replacement?------\n1.FIFO\n2.LRU\n3.Optimal\n";
    cin>>ch;
   

    queue<int> mem1;
    vector<int> mem2 (capacity, -1); // Initialize memory with -1
    int pageFaults = 0;
   
    switch(ch)
    {
        case 1:
       
            for (int i = 0; i < n; i++) {
                bool isPageFault = true;
                for (int j = 0; j < mem1.size(); j++) {
                    if (pages[i] == mem1.front()) {
                        isPageFault = false;
                        break;
                    }
                    mem1.push(mem1.front());
                    mem1.pop();
                }
                if (isPageFault) {
                    pageFaults++;
                    if (mem1.size() == capacity) {
                        mem1.pop();
                    }
                    mem1.push(pages[i]);
                }
            }
       
            cout << "Page faults: " << pageFaults << endl;
       
        break;
       
        case 2:
       
            for (int i = 0; i < n; i++) {
                bool isPageFault = true;
                for (int j = 0; j < mem1.size(); j++) {
                    if (pages[i] == mem1.front()) {
                        isPageFault = false;
                        break;
                    }
                    mem1.push(mem1.front());
                    mem1.pop();
                }
                if (isPageFault) {
                    pageFaults++;
                    if (mem1.size() == capacity) {
                        // Find least recently used page and remove it
                        int lru = mem1.front();
                        for (int j = 1; j < capacity; j++) {
                            if (pages[i-j] == lru) {
                                mem1.pop();
                                break;
                            }
                            mem1.push(mem1.front());
                            mem1.pop();
                        }
                    }
                    mem1.push(pages[i]);
                }
            }
       
            cout << "Page faults: " << pageFaults << endl;
       
        break;
       
        case 3:
       
            for (int i = 0; i < n; i++) {
                bool isPageFault = true;
                for (int j = 0; j < capacity; j++) {
                    if (pages[i] == mem2[j]) {
                        isPageFault = false;
                        break;
                    }
                }
                if (isPageFault) {
                    pageFaults++;
                    int replaceIndex = -1;
                    int farthestUse = -1;
                    for (int j = 0; j < capacity; j++) {
                        int k = i + 1;
                        while (k < n && mem2[j] != pages[k]) {
                            k++;
                        }
                        if (k > farthestUse) {
                            farthestUse = k;
                            replaceIndex = j;
                        }
                    }
                    mem2[replaceIndex] = pages[i];
                }
            }
       
            cout << "Page faults: " << pageFaults << endl;
       
        break;
       
        default:
            cout<<"INVALID_CHOICE_ERROR"<<endl;
        break;
    }

    return 0;
}
