#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "swapb"
const int maxn = 5e5+5;

using namespace std;

int n, m, s, a[maxn], p[maxn], bit[maxn];
ll res;

void update(int x){
    while (x > 0){
        bit[x]++;
        x -= x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x <= m*n){
        ans += bit[x];
        x += x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> m >> n >> s;
    fi(i, 1, n){
        fi(j, 1, m){
            p[i*m-m+j] = j*n-n+i;
            a[j*n-n+i] = i*m-m+j;
        }
    }
    if (s == 1) {
        fi(i, 1, n*m){
            if (p[i] != i){
                int t = p[i];
                res++;
                p[i] = i;
                a[t] = a[i];
                p[a[t]] = t;
                a[i] = i;
            }
        }
    }
    else {
        fi(i, 1, n*m){
            res += get(p[i]+1);
            update(p[i]);
        }
    }
    cout << res;
}
