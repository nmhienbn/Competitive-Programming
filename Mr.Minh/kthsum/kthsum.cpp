#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 100005
#define maxm 1000006
#define MOD
#define Seraphine "kthsum"

using namespace std;

struct pli {
    ll f;
    int s;
    bool operator < (const pli& x) const{
        return f < x.f;
    }
};

int n, bit[maxn];
ll k;
pli a[maxn];

void update(int x){
    while (x <= n){
        bit[x]++;
        x += x & -x;
    }
}

int get(int x){
    if (x == 0) return 0;
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

bool check(ll g){
    //cout << g << ": ";
    fi(i, 1, n) bit[i] = 0;
    int cnt = 0;
    int j = 0;
    if (g >= 0){
        fi(i, 1, n){
            while (j < i && a[j+1].f <= a[i].f - g){
                j++;
                update(a[j].s);
            }
            if (a[j].f <= a[i].f - g){
                cnt += get(a[i].s-1);
                //cout << cnt << ' ';
            }
            if (cnt >= k){
                //cout << cnt << ' ' << k << '\n';
                return 1;
            }
        }
    }
    else {
        j = n+1;
        fid(i, n, 1){
            while (j > i && a[j-1].f <= a[i].f - g){
                j--;
                update(a[j].s);
            }
            if (a[j].f <= a[i].f - g){
                cnt += get(a[i].s-1);
                //cout << cnt << ' ';
            }
            if (cnt >= k){
                //cout << cnt << ' ' << k << '\n';
                return 1;
            }
        }
    }
    //cout << cnt << ' ' << k << '\n';
    return 0;
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i].f;
        a[i].f += a[i-1].f;
        a[i].s = i+1;
    }
    a[++n] = {0, 1};
    sort(a+1, a+n+1);
    //fi(i, 1, n) cout << a[i].f << ' '; cout << endl;
    ll d = a[1].f - a[n].f, c = a[n].f - a[1].f;
    while (d <= c){
        //cout << d << ' ' << c << ' ';
        ll g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
        //cout << endl;
    }
    cout << c;
}
