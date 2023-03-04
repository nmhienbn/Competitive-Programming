#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "vitri"
const int maxn = 1e4+5;

using namespace std;

int n, k, a[maxn], dem;
bool check[maxn];

int calc(int g){
    int cnt = 0;
    int i = 1, j = 1;
    while (i <= n){
        while (a[j] <= a[i]+g && j <= n){
            j++;
        }
        j--;
        i = j;
        check[i] = 1, dem--;
        cnt++;
        while (a[j] <= a[i]+g && j <= n){
            j++;
        }
        i = j;
    }
    return cnt;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    int d = 0, c = a[n]-a[1];
    while (d <= c){
        int g = (d+c) >> 1;
        if (calc(g) >= k) d = g+1;
        else c = g-1;
    }
    dem = k;
    fi(i, 1, n) check[i] = 0;
    calc(c);
    if (dem){
        fi(i, 1, n){
            if (!check[i]){
                check[i] = 1;
                dem--;
                if (!dem) break;
            }
        }
    }
    fi(i, 1, n) if (check[i]) cout << i << '\n';
}
