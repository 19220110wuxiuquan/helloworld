#include<iostream>

using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

void addToHead(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void de(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;
    init();
    while (m--)
    {
        char op;
        int x, k;
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            addToHead(x);
        }
        else if (op == 'I')
        {
            cin >> k >> x;
            add(k - 1, x);
        }
        else
        {
            cin >> k;
            if (!k) head = ne[head];
            de(k - 1);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}
