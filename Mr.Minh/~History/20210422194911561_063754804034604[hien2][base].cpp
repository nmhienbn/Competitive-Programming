#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "base"
#define maxn 10005

using namespace std;

template<typename T1> void nhap(int n, T1 arr[]){
    fi(i, 1, n) cin >> arr[i];
}
template<typename T1> void xuat(int n, T1 arr[]){
    fi(i, 1, n) cout << arr[i] << ' ';
}

int n, m, a[maxn], sum[maxn], t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m;
    nhap(n, a);
    sort(a+1, a+n+1);
    fi(i, 1, n) sum[i] = sum[i-1] + a[i];
    fi(i, 1, m){
        cin >> t;
        int d = 0, c = n+1;
        while (d < c){
            int g = (c+d)/2;
            if (a[g] > t) c = g-1;
            else d = g+1;
        }
        cout << t*(c-1) - 2*sum[c-1] + sum[n] - t*(n-c+1) << '\n';
    }
}
