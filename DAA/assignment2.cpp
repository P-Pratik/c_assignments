#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Node
{
public:
    int freq;
    string symbol;
    Node *left;
    Node *right;
    char huff;

    Node(int f, const string &s, Node *l = nullptr, Node *r = nullptr)
        : freq(f), symbol(s), left(l), right(r), huff(' ') {}

    bool operator<(const Node &nxt) const
    {
        return freq < nxt.freq;
    }
};

void printNodes(const Node *node, const string &val = "")
{
    string newVal = val + node->huff;
    if (node->left)
    {
        printNodes(node->left, newVal);
    }
    if (node->right)
    {
        printNodes(node->right, newVal);
    }
    if (!node->left && !node->right)
    {
        cout << node->symbol << " -> " << newVal << endl;
    }
}

int main()
{
    vector<string> chars;
    vector<int> freq;
    priority_queue<Node> nodes;

    int numChars;
    cout << "Enter the number of characters: ";
    cin >> numChars;

    chars.resize(numChars);
    freq.resize(numChars);

    cout << "Enter the characters and their frequencies:" << endl;
    for (int x = 0; x < numChars; ++x)
    {
        cin >> chars[x] >> freq[x];
        nodes.push(Node(freq[x], chars[x]));
    }

    while (nodes.size() > 1)
    {
        Node *left = new Node(nodes.top());
        nodes.pop();
        Node *right = new Node(nodes.top());
        nodes.pop();

        left->huff = '0';
        right->huff = '1';

        Node *newNode = new Node(left->freq + right->freq, left->symbol + right->symbol, left, right);
        nodes.push(*newNode);
    }

    printNodes(&nodes.top());

    return 0;
}
