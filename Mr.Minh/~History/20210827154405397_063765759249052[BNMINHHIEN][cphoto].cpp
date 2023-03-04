#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cphoto"
const int maxn = 1e6+5;

using namespace std;

struct pii {
    int f, s;
    bool operator < (const pii& x) const {
        return f < x.f;
    }
};

int n, now, res = 1e9, cnt[maxn];
pii a[maxn];

bool cmp(pii a, pii b){
    return a.s == b.s ? a.f < b.f : a.s < b.s;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    //nhap
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].f >> a[i].s;
    }
    //co
    sort(a+1, a+n+1, cmp);
    int id = 0, pre = 0;
    fi(i, 1, n){
        if (a[i].s != pre){
            pre = a[i].s;
            a[i].s = ++id;
        }
        else a[i].s = id;
    }
    //xuli
    sort(a+1, a+n+1);
    int j = 1;
    fi(i, 1, n){
        cnt[a[i].s]++;
        if (cnt[a[i].s] == 1) now++;
        if (now == id){
            while (now == id){
                cnt[a[j].s]--;
                if (cnt[a[j].s] == 0) now--;
                j++;
            }
            j--;
            cnt[a[j].s]++; now++;
            res = min(res, a[i].f - a[j].f);
        }
    }
    cout << res;
}
