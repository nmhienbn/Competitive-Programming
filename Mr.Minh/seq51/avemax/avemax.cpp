#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "avemax"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], b[maxn];
ll sum;

bool check(int g){
    fi(i, 1, n) b[i] = a[i] - g;
    sum = 0;
    int j = 1;
    fi(i, 1, n){
        sum += b[i];
        while (j <= i && sum < 0){
            sum -= b[j];
            j++;
        }
        if (j <= i && sum >= 0) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    int d = 1, c = 1e9;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g + 1;
        else c = g - 1;
    }
    cout << c;
}
