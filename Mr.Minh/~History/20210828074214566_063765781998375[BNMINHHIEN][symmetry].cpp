#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "symmetry"
const int maxn = 2e5+5;

using namespace std;

int n, z[maxn], a[maxn], b[maxn], res;

void Tinh_Z(){
    int L = 0, R = 0;
    fi(i, 1, n){
        int x = 0; // z[i]
		if (i <= R){
            x = min(z[i-L+1], R-i+1);
		}
		while (i+x <= n && a[x+i] == b[x+1]){
            x++;
		}
		z[i] = x;
		if (R < i + x - 1){
			L = i;
			R = i + x - 1;
		}
		if (R >= n){
            res = max(res, z[i]);
		}
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        b[n+1-i] = a[i];
    }
    Tinh_Z();
    cout << n-res;
}
