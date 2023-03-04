#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int SQRT = 31623; // sqrt(10^9)

int m, n;
int p[SQRT + 5], dem;
vector<int> Primes;
int c[maxn];
int CntC[35], CntD[35];

void add(long long &x, long long y)
{
    x = (x + y) % mod;
}
void Eratosthenes()
{
    Primes.push_back(1);
    for (int i = 2; i < SQRT; i++) if (!p[i]) {
            Primes.push_back(i);
            for (int j = i * i; j < SQRT; j += i)
                p[j] = 1;
        }
}

int calc(int x, int i, int sign = 1)
{
    if (i == 0)
        return sign * x;
    if (i == 1)
        return sign * (x - x / 2);
    if (i == 2)
        return sign * (x - x / 2 - x / 3 + x / 6);

    long long result = 0;
    while (i > 3){
        if (i < Primes.size() && x < Primes[i + 1])
            return result + sign;
        i--;
        result += calc(x / Primes[i + 1], i, -sign);
    }
    return result + sign * (x - x / 2 - x / 3 + x / 6 - x / 5 + x / 10 + x / 15 - x / 30);
}

int count_bit_i_th(int n, int i){ // count the number of positive integer not exceeding n that its i-th bit = 1
    int n0 = n | ((1 << i) - 1);
    return ((n0 + 1) >> 1) - min((1 << (i - 1)), n0 - n);
}

void solve(int n, int CntC[])
{
    int CntN = n - 1;
    int idN = 0;
    c[0] = 1;
    for (int i = 1, _ = Primes.size(); i < _; i++)
    {
        int prime = Primes[i];
        if (1LL * prime * prime > n)
            break;
        c[i] = calc(n / prime, i - 1);
        idN = i;
        CntN -= c[i];
    }
    for (int i = 0; i <= idN; i++)
        for (int j = 0; j <= 30; j++)
            if ((i >> j) & 1)
                CntC[j] += c[i];
    for (int j = 0; j <= 30; j++)
        CntC[j] += count_bit_i_th(idN + CntN, j + 1) - count_bit_i_th(idN, j + 1);
}

long long res;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("matrix.inp", "r", stdin);
    freopen("matrix.out", "w", stdout);
    Eratosthenes();
    cin >> m >> n;
    solve(n, CntC);
    solve(m, CntD);
    for (int i = 0; i <= 30; i++){
        add(res, (1LL << i) * CntC[i] % mod * (m - CntD[i]));
        add(res, (1LL << i) * (n - CntC[i]) % mod * CntD[i]);
    }
    add(res, (long long)m * n);
    cout << res;
    return 0;
}
