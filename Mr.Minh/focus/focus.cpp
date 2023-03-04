#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "focus"
const int maxn = 4e5+5;

using namespace std;

struct query {
    char t;
    int a, b, c;
} q[maxn];

int n, bit[maxn];
vector<int> b;

void update(int x, int val){
    while (x <= n*2){
        bit[x] += val;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> q[i].t >> q[i].a;
        if (q[i].t != '?'){
            b.pb(q[i].a);
        }
        else {
            cin >> q[i].b >> q[i].c;
            b.pb(q[i].b);
            b.pb(q[i].c);
        }
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    fi(i, 1, n){
        if (q[i].t == '+'){
            q[i].a = lower_bound(b.begin(), b.end(), q[i].a) - b.begin() + 1;
            update(q[i].a, 1);
        }
        else if (q[i].t == '-'){
            q[i].a = lower_bound(b.begin(), b.end(), q[i].a) - b.begin() + 1;
            update(q[i].a, -1);
        }
        else {
            int l = lower_bound(b.begin(), b.end(), q[i].b) - b.begin() + 1;
            int r = lower_bound(b.begin(), b.end(), q[i].c) - b.begin() + 1;
            int cnt = get(l-1);
            if (get(r) - cnt < q[i].a){
                cout << 0 << '\n';
                continue;
            }
            int d = l, c = r;
            while (d <= c){
                int g = (d + c) >> 1;
                if (get(g) - cnt >= q[i].a) c = g-1;
                else d = g+1;
            }
            cout << b[d-1] << '\n';
        }
    }
}
