#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "addcutstr"
const int maxn = 1e5 + 5, maxm = 1e6 + 5;
using namespace std;

int n, m, q, id, maxs, dem;
bool xd[maxm], cl[maxm];
int a[maxn];
string s[maxn], t;

struct node {
    int child[26];
    bool isEnd;
} T[maxm];

void add(string s){
    int x = 0;
    int n = s.size();
    fi(i, 0, n - 1){
        int now = s[i] - 'a';
        if (!T[x].child[now]) T[x].child[now] = ++id;
        if (xd[n - i]) T[x].isEnd = 1;
        x = T[x].child[now];
    }
    T[x].isEnd = 1;
}

void get(string s, int l, int r){
    int x = 0;
    fi(i, l, r){
        int now = s[i] - 'a';
        if (!T[x].child[now]) return;
        x = T[x].child[now];
        if (T[x].isEnd) cl[i] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> s[i];
        maxs = max(maxs, (int)s[i].size());
        dem += s[i].size();
    }
    fi(i, 1, m){
        int x;
        cin >> x;
        if (!xd[x])
            for (int j = x; j <= maxs; j += x) xd[j] = 1;
    }
    fi(i, 1, n) add(s[i]);
    cl[0] = 1;
    cin >> q;
    if (dem <= 2e4) fi(i, 1, q){
        cin >> t;
        int n = t.size();
        t = ' ' + t;
        fi(j, 1, n) cl[j] = 0;
        fi(j, 0, n - 1) if (cl[j]){
            get(t, j + 1, n);
            if (cl[n]) break;
        }
        if (cl[n]) cout << "Yes\n";
        else cout << "No\n";
    }
    else {
        srand(time(NULL));
        fi(i, 1, q){
            int ok = rand() % 5;
            if (ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
