#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "kprime"
const int maxn = 1e7;
using namespace std;

int n, k;
bitset<maxn + 5> p;
ll res;
int j = 1, cnt;

void Erathosenes(){
    p.set(1);
    fi(i, 2, sqrt(n)) if (!p[i]){
        for (int j = i * i; j <= n; j += i){
            p.set(j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    Erathosenes();
    fi(i, 1, n){
        cnt += !p[i];
        while (cnt > k) cnt -= !p[j++];
        if (cnt == k){
            while (p[j]) j++;
            res += j;
        }
    }
    cout << res;
}
