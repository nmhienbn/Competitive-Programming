#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "fitness"
const int maxn = 5005;

using namespace std;

int n, w, h;
pii a[maxn];
int g[maxn][maxn];
int store[maxn];

bool kt(int x, int y){
    return x*x + y*y >= 2;
}

bool is_cmp(int b){
	fi(i, 1, b) {
		fi(j, i+1, b)
			if (g[store[i]][store[j]] == 0)
				return 0;
	}
	return 1;
}

int calc(int i, int l){
	int res = 0;
	fi(j, i+1, n){
		store[l] = j;
		if (is_cmp(l)) {
			res = max(res, l);
			res = max(res, calc(j, l+1));
		}
	}
	return res;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> w >> h;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+n+1);
    fi(i, 1, n-1){
        fi(j, i+1, n){
            if (kt(a[j].first-a[i].first, a[j].second-a[i].second)){
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }
	cout << calc(0, 1);
	return 0;
}
