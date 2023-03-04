#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia ""
const int maxn = 1000;
using namespace std;
string f[maxn];
string n;
string luu[maxn];


int ss ( string a, string b)
{
    while ( a.length() < b.length()) a = '0' + a;
    while ( a.length() > b.length()) b = '0' + b;
    if ( a > b) return 1;
        else if ( a == b) return 0;
            else return -1;
}
string cong(string a, string b)
{
    while ( a.length() < b.length()) a = '0' + a;
    while ( a.length() > b.length()) b = '0' + b;
    string c;
    int s, d = 0;
    fid (i, a.length() - 1, 0){
        s = a[i] + b[i] + d - 96;
        d = s/10;
        c = char( s%10 + 48) + c;
    }
    if ( d > 0) c = '1' + c;
    return c;
}

string tru( string a, string b)
{
    while ( a.length() < b.length()) a = '0' + a;
    while ( a.length() > b.length()) b = '0' + b;
    string c;
    int s, d = 0;
    fid (i, a.length() - 1, 0){
        s = a[i] - b[i] - d;
        if ( s < 0) { s += 10 ; d= 1;}
            else d = 0;
        c = char ( s + 48) + c;
    }
    while ( c.length() > 1 && c[0] == '0') c.erase(0,1);
    return c;
}

void fibo()
{
    f[1] = '1';
    f[2] = '1';
    fi (i, 3, maxn-1)
        f[i] = cong (f[i-1] , f[i-2]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n ;
    fibo();
    int dem = 0;
    fid (i, maxn - 1, 1)
    {
        if ( ss (f[i], n) <= 0) { n = tru (n, f[i]) ; luu[++dem] = f[i];}
        if (n <= "0") break;
    }
    fi ( i, 1, dem) cout << luu[i] << " ";

}
