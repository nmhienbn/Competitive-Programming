#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "medquery"
const int maxn = 1e6 + 5;
using namespace std;

int q, cnt, n;

struct node{
    int child[2];
    int deg, num;
} T[32000005];

void add(int x, int val){
    int id = 0;
    fid(i, 31, 0){
        int now = gb(x, i);
        if (!T[id].child[now]) T[id].child[now] = ++cnt;
        id = T[id].child[now];
        T[id].deg += val;
    }
    T[id].num = x;
}

int query(int k){
    int x = 0;
    fi(i, 0, 31){
        cout << T[x].child[0] << ' ';
        if (T[T[x].child[0]].deg >= k){
            x = T[x].child[0];
        }
        else {
            k -= T[T[x].child[0]].deg;
            x = T[x].child[1];
        }
    }
    return T[x].num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> q;
    while (q--){
        char typ;
        int x;
        cin >> typ >> x;
        if (typ == '+') n++, add(x, 1);
        else n--, add(x, -1);
        if (n == 0) {cout << "0\n"; continue;}
        cout << query((n + 1) / 2) << '\n';
    }
}
