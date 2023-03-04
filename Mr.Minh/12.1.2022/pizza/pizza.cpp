#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "pizza"
const int maxn = 1e5 + 5;
using namespace std;

struct node {
    int child[26];
    int deg, cnt;
} T[1000005];

int q, id;
int typ; string s;

void add(string s){
    int x = 0;
    for (char c : s){
        int now = c - 'a';
        if (!T[x].child[now]) T[x].child[now] = ++id;
        x = T[x].child[now];
        T[x].deg++;
    }
    T[x].cnt++;
}

int query1(string s){
    int x = 0, cnt = 0;
    for (char c : s){
        int now = c - 'a';
        if (!T[x].child[now]) break;
        x = T[x].child[now];
        cnt += T[x].cnt;
    }
    return cnt;
}

int query2(string s){
    int x = 0;
    for (char c : s){
        int now = c - 'a';
        if (!T[x].child[now]) return 0;
        x = T[x].child[now];
    }
    return T[x].deg;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >>  q;
    fi(i, 1, q){
        cin >> typ >> s;
        if (!typ) add(s);
        else if (typ == 1) cout << query1(s) << '\n';
        else cout << query2(s) << '\n';
    }
}
