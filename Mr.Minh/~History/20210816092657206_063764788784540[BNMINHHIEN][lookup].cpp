#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lookup"
const int maxn = 3e4+5;

using namespace std;

struct node {
    int child[26], isEnd;
    vector<int> vt;
} T[maxn*30];

int n, q, cnt;

void Add(string s, int i){
    int x = 0;
    for (auto c : s){
        T[x].vt.pb(i);
        int now = c - 'a';
        if (!T[x].child[now]) T[x].child[now] = ++cnt;
        x = T[x].child[now];
    }
    T[x].isEnd = i;
}

int Calc(string s){
    int x = 0;
    for (auto c : s){
        int now = c - 'a';
        if (!T[x].child[now]) return n;
        x = T[x].child[now];
    }
    return T[x].isEnd != 0 ? T[x].isEnd : n;
}

int Kq(string s, int vt){
    int x = 0, res = 0;
    for (auto c : s){
        res += upper_bound(T[x].vt.begin(), T[x].vt.end(), vt) - T[x].vt.begin();
        int now = c - 'a';
        if (!T[x].child[now]) return res;
        x = T[x].child[now];
    }
    return res;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        string s;
        cin >> s;
        Add(s, i);
    }
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        int vt = Calc(s);
        cout << Kq(s, vt)+1 << '\n';
    }
    //for (auto vt : T[0].vt) cout << vt << ' ';
    //cout << upper_bound(T[0].vt.begin(), T[0].vt.end(), 5) - T[0].vt.begin();
}
