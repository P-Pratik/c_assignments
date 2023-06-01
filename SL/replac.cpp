#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int fifoPageReplacement(const vector<int>& pages, int frames) {
    queue<int> pageTable;
    unordered_set<int> pageSet;
    int pageFaults = 0;

    for (int page : pages) {
        if (pageSet.find(page) == pageSet.end()) {
            if (pageTable.size() == frames) {
                int victimPage = pageTable.front();
                pageTable.pop();
                pageSet.erase(victimPage);
            }

            pageTable.push(page);
            pageSet.insert(page);
            pageFaults++;
        }
    }

    return pageFaults;
}

int lruPageReplacement(const vector<int>& pages, int frames) {
    unordered_set<int> pageSet;
    vector<int> pageTable;
    int pageFaults = 0;

    for (int page : pages) {
        auto it = find(pageTable.begin(), pageTable.end(), page);

        if (it == pageTable.end()) {
            if (pageTable.size() == frames) {
                int victimPage = pageTable.front();
                pageSet.erase(victimPage);
                pageTable.erase(pageTable.begin());
            }

            pageTable.push_back(page);
            pageSet.insert(page);
            pageFaults++;
        } else {
            pageTable.erase(it);
            pageTable.push_back(page);
        }
    }

    return pageFaults;
}

int optimalPageReplacement(const vector<int>& pages, int frames) {
    unordered_set<int> pageSet;
    vector<int> pageTable;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (pageSet.find(pages[i]) == pageSet.end()) {
            if (pageTable.size() == frames) {
                int victimPage = -1;
                int farthestIndex = -1;

                for (int j = 0; j < pageTable.size(); j++) {
                    int nextPageIndex = -1;
                    for (int k = i + 1; k < pages.size(); k++) {
                        if (pageTable[j] == pages[k]) {
                            nextPageIndex = k;
                            break;
                        }
                    }
                    if (nextPageIndex == -1) {
                        victimPage = pageTable[j];
                        break;
                    }
                    if (nextPageIndex > farthestIndex) {
                        farthestIndex = nextPageIndex;
                        victimPage = pageTable[j];
                    }
                }

                pageSet.erase(victimPage);
                pageTable.erase(find(pageTable.begin(), pageTable.end(), victimPage));
            }

            pageTable.push_back(pages[i]);
            pageSet.insert(pages[i]);
            pageFaults++;
        }
    }

    return pageFaults;
}

int main() {
    int choice;
    vector<int> pages;
    int frames;

    while (true) {
        cout << "Page Replacement Strategies:" << endl;
        cout << "1. FIFO" << endl;
        cout << "2. LRU" << endl;
        cout << "3. Optimal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the number of frames: ";
                cin >> frames;

                cout << "Enter the page references (enter -1 to stop): ";
                int page;
                while (cin >> page && page !=-1) {
                        pages.push_back(page);
                    }
            int pageFaults = fifoPageReplacement(pages, frames);
            cout << "FIFO Page Replacement: " << pageFaults << endl;

            break;
        }
        case 2: {
            cout << "Enter the number of frames: ";
            cin >> frames;

            cout << "Enter the page references (enter -1 to stop): ";
            int page;
            while (cin >> page && page != -1) {
                pages.push_back(page);
            }

            int pageFaults = lruPageReplacement(pages, frames);
            cout << "LRU Page Replacement: " << pageFaults << endl;

            break;
        }
        case 3: {
            cout << "Enter the number of frames: ";
            cin >> frames;

            cout << "Enter the page references (enter -1 to stop): ";
            int page;
            while (cin >> page && page != -1) {
                pages.push_back(page);
            }

            int pageFaults = optimalPageReplacement(pages, frames);
            cout << "Optimal Page Replacement: " << pageFaults << endl;

            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }

    cout << endl;

    // Clear the page references for the next iteration
    pages.clear();
}
}
