#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "LTPMSEQ"
const int maxn = 2e6+5;

using namespace std;

struct node {
    int child[52];
    int deg;
    string s;
    node(){
        deg = 0;
        memset(child, 0, sizeof(child));
    };
};

int n, cnt;
set<int> kt;
vector<node> T;

void Add(string s){
    int pos = 0;
    for (auto c : s){
        int now = c >= 'a' ? c - 'a' : c - 'A';
        if (!T[pos].child[now]) T[pos].child[now] = ++cnt, T.pb(node());
        pos = T[pos].child[now];
    }
    if (T[pos].deg == 0) T[pos].s = s;
    T[pos].deg++;
    if (T[pos].deg & 1) kt.insert(pos);
    else kt.erase(pos);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    T.pb(node());
    while (n--){
        string s;
        cin >> s;
        Add(s);
    }
    if (kt.empty()){
        cout << -1;
        exit(0);
    }
    cout << T[*kt.begin()].s;
}
