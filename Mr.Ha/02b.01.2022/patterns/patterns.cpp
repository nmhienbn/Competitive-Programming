#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "patterns"
const int maxn = 20005;
const int base[2] = {int(1e6) + 1, int(1e6) + 3};
const int mod[2] = {int(1e9) + 7, int(1e9) + 427};
using namespace std;

int n, a[maxn], k;
int h[2][maxn], b[2][maxn];
ll M[2];
pii c[maxn];

void hashing(int h[], int b[], int base, int mod){
    h[0] = 1;
    fi(i, 1, n) h[i] = 1ll * h[i - 1] * base % mod;
    fi(i, 1, n) b[i] = (1ll * b[i - 1] * base + a[i]) % mod;
}

int get(int l, int r, int j){
    return (b[j][r] - 1ll * b[j][l - 1] * h[j][r - l + 1] + M[j]) % mod[j];
}

bool check(int g){
    fi(i, 1, n - g + 1)
        c[i] = {get(i, i + g - 1, 0), get(i, i + g - 1, 1)};
    sort(c + 1, c + n - g + 2);
//    cout << g << endl;
//    fi(i, 1, n - g + 1) cout << c[i].first << ' '; cout << endl;
//    fi(i, 1, n - g + 1) cout << c[i].second << ' '; cout << endl;
    int cnt = 1;
    fi(i, 2, n - g + 1){
        if (c[i] == c[i - 1]){
            cnt++;
            if (cnt >= k) return true;
        }
        else cnt = 1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fi(j, 0, 1){
        M[j] = 1ll * mod[j] * mod[j];
        hashing(h[j], b[j], base[j], mod[j]);
    }
    int d = 0, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g + 1;
        else c = g - 1;
    }
    cout << c;
}
