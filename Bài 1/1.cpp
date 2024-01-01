#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

#define MAX 1000

using namespace std;

// int solve(vector<int> &a, int k) {
//     vector<int> g(a.size());
//     int n = a.size(), max_ = INT_MIN;

//     g[0] = a[0];
//     for (int i = 1; i < n; ++i) {
//         for (int j = max(0, i - k + 1); j <= i; ++j) {
//             g[j] = gcd(g[j], a[i]);
//         }
//         if (i >= k - 1) {
//             max_ = max(max_, g[i - k + 1]);
//         }
//     }

//     return max_;
// }

struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;

    Deque(int size) {
        this->front = -1;
        this->rear = -1;
        this->size = size;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    int getSize() {
        return (rear - front + 1 + size) % size;
    }

    void insertFront(int key) {
        if (isFull())
            return;

        if (isEmpty())
            front = rear = 0;
        else if (front == 0)
            front = size - 1;
        else
            --front;
        
        arr[front] = key;
    }

    void insertRear(int key) {
        if (isFull())
            return;

        if (isEmpty())
            front = rear = 0;
        else if (rear == size - 1)
            rear = 0;
        else
            ++rear;

        arr[rear] = key;
    }

    void deleteFront() {
        if (isEmpty())
            return;

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            ++front;
    }

    void deleteRear() {
        if (isEmpty())
            return;
        
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            --rear;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }

    int& operator[](int index) {
        return arr[(front + index) % size];
    }
};

// ostream& operator<<(ostream& writer, Deque &dq) {
//     for (int i = 0; i <= dq.rear; ++i)
//         writer << dq[i] << " ";
//     writer << "\n";
//     return writer;
// }

int solve(vector<int> &a, int k) {
    int n = a.size(), res = INT_MIN;
    vector<int> g(n);
    Deque dq(n);

    g[0] = a[0];
    dq.insertRear(0);
    for (int i = 1; i < n; ++i) {
        cout << "--- i = " << i << " ---" << endl;
        int i_g, i_dq, gcd_;
        for (i_dq = dq.getSize() - 1; i_dq >= 0; --i_dq) {
            i_g = dq[i_dq];
            gcd_ = gcd(g[i_g], a[i]);
            if (gcd_ != g[i_g]) {
                g[i_g] = gcd_;
            }
            else {
                break;
            }
        }
        dq.insertRear(i);
        g[i] = a[i];

        int p, q;
        for (int i = 0; i < n; ++i) 
            cout << g[i] << " ";
        cout << endl;
        if (i_dq == -1) ++i_dq;
        for (p = i_dq + 1, q = i_dq + 1; p < dq.getSize();) {
            if (g[dq[p]] != g[dq[p - 1]])
                dq[q++] = dq[p++];
            else
                ++p;
        }
        dq.rear = (dq.front + q - 1) % dq.size;

        for (i_dq = 0; dq[i_dq + 1] <= i - k + 1;)
            dq.deleteFront();

        res = max(res, g[dq[0]]);
    }

    return res;
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    int n, k, x;
    vector<int> a;
    reader >> n >> k;
    for (int i = 0; i < n; ++i) {
        reader >> x;
        a.push_back(x);
    }

    writer << solve(a, k) << "\n";

    reader.close();
    writer.close();
    return 0;
}