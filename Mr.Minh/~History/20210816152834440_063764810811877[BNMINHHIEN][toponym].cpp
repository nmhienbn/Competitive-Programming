#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "toponym"
const int maxn = 1e6+5;

using namespace std;

struct node {
    int child[54], deg;
} T[maxn*6];

int n, cnt;
ll res;

void Add(string s){
    int pos = 0, l = 0;
    for (auto c : s){
        int now = 0;
        if (c >= 'A') now = c - 'A' + 1;
        if (c >= 'a') now = c - 'a' + 27;
        if (!T[pos].child[now]) T[pos].child[now] = ++cnt;
        pos = T[pos].child[now];
        T[pos].deg++; l++;
        res = max(res, 1ll*l*T[pos].deg);
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        string s;
        getline(cin, s);
        Add(s);
    }
    cout << res;
}
