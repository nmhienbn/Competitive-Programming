#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "wifi"
const int maxn = 3e5 + 5;
using namespace std;

struct dl {
	dl(int _a) : a(_a), b(0) {}
	dl(int _a, int _b) : a(_a), b(_b) {}

	int a, b;
};

int n, d, t[maxn], x[maxn], h[maxn];
double s[2][maxn];
vector<dl> v;

double drop(const dl s) {
	int x1 = x[s.a], y1 = h[s.a], x2 = x[s.b], y2 = h[s.b];
	return double(1ll * y1 * x2 - 1ll * x1 * y2) / (y1 - y2);
}

void update(dl &s, int c) {
	if (drop(s) < drop(dl(s.a, c)))
		s.b = c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
	cin >> n >> d;
	++n;
	fi(i, 1, n - 1)
		cin >> t[i] >> x[i] >> h[i];

	x[n] = d;
	++n;

	fi(k, 0, 1){
        fi(i, 0, n - 2){
        	while (v.size() && h[v.back().a] <= h[i])
                v.pop_back();

        	if(v.size())
	    		for(update(v.back(), i); v.size() > 1; v.pop_back()) {
	    			update(v[v.size() - 2], i);
	    			if(drop(v.back()) < drop(v[v.size() - 2]))
	    				break;
	    		}

        	if (t[i]){
        		v.push_back(i);
        		s[k][i] = x[i];
        	}
        	else
        		if(v.size())
        			s[k][i] = min(drop(v.back()), (double)x[i + 1]);
        		else
        			s[k][i] = x[i + 1];
        }

	    if (!k){
	        reverse(t, t + n);
	        reverse(x, x + n);
	        reverse(h, h + n);
	        fi(i, 0, n-1)
	            x[i] = d - x[i];
	        v.clear();
	    }
    }
    reverse(s[1], s[1] + n);
    fi(i, 0, n-1)
        s[1][i] = d - s[1][i];
    double t = 0.;
    fi(i, 0, n-2)
        if(s[0][i] > s[1][i + 1])
            t += s[0][i] - s[1][i + 1];
    cout << fixed << setprecision(4) << d - t;
}
