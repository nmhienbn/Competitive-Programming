#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "apple"
const int maxn = 1005;

using namespace std;

int n, k, cnt;
bool L[maxn*2][maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    L[n*2][0] = 1;
    L[n][1] = 1;
    L[n*2-1][1] = 1;
    fi(j, 1, k-1){
        fi(i, 1, n*2){
            if (L[i][j]){
                if (i%2 == 0){
                    L[i/2][j+1] = 1;
                }
                L[i-1][j+1] = 1;
            }
        }
    }
    fi(i, 1, n*2){
        if (L[i][k]){
            cnt++;
        }
    }
    cout << cnt << '\n';
    fi(i, 1, n*2){
        if (L[i][k]){
            double t = i;
            printf("%.1lf ", t/2);
        }
    }
}
