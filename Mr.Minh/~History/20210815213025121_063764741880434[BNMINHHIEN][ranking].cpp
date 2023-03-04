#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "ranking"
const int maxn = 2005;

using namespace std;

struct dl {
    int f, s, id;
    bool operator == (const dl& x) const {
        return f == x.f && s == x.s;
    }
    bool operator < (const dl& x) const {
        if (f != x.f) return f < x.f;
        if (s != x.s) return s < x.s;
        return 0;
    }
};

struct bit {
    int a[3];
    bit (int u, int v, int w){
        a[0] = u;
        a[1] = v;
        a[2] = w;
    }
    void sx(){
        for (int i = 0; i <= 1; i++){
            for (int j = i+1; j <= 2; j++){
                if (a[i] == a[j] && a[i] > 0) a[i]++, a[j] = 0;
            }
        }
        sort(a, a+3, greater<int>());
    }
    bool operator < (const bit & x) const {
        fi(i, 0, 2)
            if (a[i] != x.a[i]) return a[i] < x.a[i];
        return 0;
    }
};

int n, cnt, dem[maxn];
dl a[maxn];
pii res[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].f;
    fi(i, 1, n){
        cin >> a[i].s;
        if (a[i].f < a[i].s) swap(a[i].f, a[i].s);
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    fi(i, 1, n){
        int x = 2, res = 0;
        auto t = bit(a[i].f, a[i].s, 1);
        fid(j, i-1, 1){
            while (x <= n){
                bit now = bit(a[j].f, a[j].s, x);
                now.sx();
                if (t < now) break;
                x++;
            }
            //cout << x << ' ';
            if (x > n) res++;
        }
        cout << res+1 << ' ';

        x = n-1, res = 0;
        t = bit(n, a[i].f, a[i].s);
        fi(j, i+1, n){
            while (x > 0){
                bit now = bit(a[j].f, a[j].s, x);
                now.sx();
                if (now < t) break;
                x--;
            }
            if (x <= 0) res++;
        }
        cout << n-res << '\n';
    }
}
