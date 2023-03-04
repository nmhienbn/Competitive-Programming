#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "factorial"
const int maxn = 10000000+5, maxp = 700000;
using namespace std;

int n, p[maxn], pr[maxp], pp, dd, a[maxn];
ll res, cnt[maxn];

void Erathosenes(){
    fi(i, 1, maxn-5) p[i] = i;
    fi(i, 2, 3162) if (p[i] == i){
        pr[++pp] = i;
        for (int j = i * i; j <= maxn-5; j += i){
            p[j] = i;
        }
    }
    fi(i, 3163, maxn-5) if (p[i] == i){
        pr[++pp] = i;
    }
}

void add(int j, int val){
    while (j > 1){
        cnt[p[j]] += val;
        j /= p[j];
    }
}

bool check(ll g){
    fi(i, 1, pp){
        ll sum = cnt[pr[i]];
        ll pw = pr[i];
        while (sum > 0){
            sum -= g/pw;
            if (pw * pr[i] > g) break;
            pw *= pr[i];
        }
        if (sum > 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> n;
    dd = n;
    fi(i, 1, n){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    fi(i, 1, n) fi(j, a[i-1]+1, a[i]){
        add(j, n-i+1);
    }
    ll d = 0, c = 1e13;
    while (d <= c){
        ll g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
