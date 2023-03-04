#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "multiset"
const int maxn = 2e5+5;

using namespace std;

struct node {
    int child[2], deg, val;
} T[maxn*32];

int n, cnt;

void Add(int x){
    int pos = 0;
    fid(i, 31, 0){
        int now = (x >> i) & 1;
        if (!T[pos].child[now]) T[pos].child[now] = ++cnt;
        pos = T[pos].child[now];
        T[pos].deg++;
    }
    T[pos].val = x;
}

void Remove(int x){
    int pos = 0;
    fid(i, 31, 0){
        int now = (x >> i) & 1;
        if (!T[pos].child[now]) T[pos].child[now] = ++cnt;
        pos = T[pos].child[now];
        T[pos].deg--;
    }
}

void Query(int x){
    int pos = 0;
    fid(i, 31, 0){
        int now = (x >> i) & 1;
        if (T[T[pos].child[1^now]].deg > 0) pos = T[pos].child[1^now];
        else pos = T[pos].child[now];
    }
    cout << (T[pos].val ^ x) << '\n';
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    while (n--){
        char oper;
        int x;
        cin >> oper >> x;
        if (oper == '+') Add(x);
        else if (oper == '-') Remove(x);
        else Query(x);
    }
}
