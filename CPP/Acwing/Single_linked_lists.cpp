#include <iostream>
using namespace std;

const int N = 100010;

struct Node {
    int val;
    int next;
} nodes[N];

int head = -1;
int idx = 0;
int insert_idx = 0;

void init() {
    head = -1;
    idx = 0;
    insert_idx = 0;
}

void insert_head(int x) {
    nodes[idx].val = x;
    nodes[idx].next = head;
    head = idx;
    insert_idx++;
    idx++;
}

void delete_after_k(int k) {
    if (k == 0) {
        head = nodes[head].next;
    } else {
        int pos = k - 1;
        nodes[pos].next = nodes[nodes[pos].next].next;
    }
}

void insert_after_k(int k, int x) {
    int pos = k - 1;
    nodes[idx].val = x;
    nodes[idx].next = nodes[pos].next;
    nodes[pos].next = idx;
    insert_idx++;
    idx++;
}

int main() {
    init();
    int M;
    cin >> M;
    
    while (M--) {
        char op;
        cin >> op;
        
        if (op == 'H') {
            int x;
            cin >> x;
            insert_head(x);
        } else if (op == 'D') {
            int k;
            cin >> k;
            delete_after_k(k);
        } else if (op == 'I') {
            int k, x;
            cin >> k >> x;
            insert_after_k(k, x);
        }
    }
    
    for (int i = head; i != -1; i = nodes[i].next) {
        cout << nodes[i].val << " ";
    }
    
    return 0;
}