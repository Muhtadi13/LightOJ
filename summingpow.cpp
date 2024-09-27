#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 1e6 + 6
lli MOD = 1000000007LL;

using namespace std;

vector<lli> fac;
vector<lli> ifac;
vector<lli> smallestprimedivisor(MAX + 1);
vector<lli> derangenums(MAX + 1);
vector<lli> primes;

vector<lli> getPrimeFactorization(lli x)
{
    // logn time, uses sieve
    vector<lli> ret;
    while (x > 1)
    {
        ret.push_back(smallestprimedivisor[x]);
        x = x / smallestprimedivisor[x];
    }
    return ret;
}

vector<lli> getPrimeFactorization2(lli n)
{

    // sqrt(n),doesn't use sieve
    vector<lli> ret;
    lli x = n;
    while (x % 2 == 0)
    {
        ret.push_back(2);
        x = x / 2;
    }

    for (lli i = 3; i * i <= x; i += 2)
    {

        while (x % i == 0)
        {
            ret.push_back(i);
            x = x / i;
        }
    }
    if (x > 2)
        ret.push_back(x);

    return ret;
}

string bigIntMultiply(string &s, lli b)
{
    string ans = "";
    int carry = 0;

    // multiplying reversely

    for (int i = 0; i < s.size(); i++)
    {
        carry = (s[i] - '0') * b + carry;
        ans += carry % 10 + '0';
        carry /= 10;
    }

    while (carry > 0)
    {
        ans += carry % 10 + '0';
        carry /= 10;
    }

    // ans is reverse
    return ans;
}

void sieve()
{

    for (lli i = 0; i <= MAX; i++)
        smallestprimedivisor[i] = i;

    for (lli i = 2; i * i <= MAX; i++)
    {
        if (smallestprimedivisor[i] == i)
        {

            for (lli j = i * i; j <= MAX; j += i)
            {
                if (smallestprimedivisor[j] == j)
                    smallestprimedivisor[j] = i;
            }
        }
    }

    for (lli i = 2; i <= MAX; i++)
    {
        if (smallestprimedivisor[i] == i)
            primes.push_back(i);
    }
}

lli binExp(lli base, lli exp)
{
    base %= MOD;
    lli res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (lli)((long long)res * base % MOD);
        }
        base = (lli)((long long)base * base % MOD);
        exp >>= 1;
    }
    return res;
}

lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

lli gcdExtended(lli a, lli b, lli *x, lli *y)
{
    // ax+by=gcd(a,b);
    // solution to linear diophantine equation ax+by=c where gcd(a,b)|c

    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    lli x1, y1;

    lli g = gcdExtended(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return g;
}

lli modInverse(lli num, lli M)
{
    lli x, y;
    lli g = gcdExtended(num, M, &x, &y);

    if (g != 1)
    {
        // no inverse exists
        return -INT_MAX;
    }
    return (x + M) % M;
}

lli InverseModuloPrime(lli num, lli M)
{
    lli g = gcd(num, M);

    if (g != 1)
    {
        // no inverse exists
        return -INT_MAX;
    }

    return binExp(num, M - 2LL);
}

void precomputeFactorial(lli n)
{
    // inverses modulo prime
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (lli i = 2; i <= n; i++)
    {
        fac[i] = (lli)((long long)i * fac[i - 1] % MOD);
    }

    ifac.resize(n + 1);
    for (lli i = 0; i < fac.size(); i++)
    {
        ifac[i] = binExp(fac[i], MOD - 2);
    }
    return;
}

lli nCr(lli n, lli r)
{
    if ((n < 0) || (r < 0) || (r > n))
    {
        return 0;
    }
    return (lli)((long long)fac[n] * ifac[r] % MOD * ifac[n - r] % MOD);
}

void derangement()
{
    derangenums[0] = 1;
    derangenums[1] = 0;
    derangenums[2] = 1;

    for (lli j = 3; j <= MAX; j++)
    {
        derangenums[j] = ((j - 1) * (derangenums[j - 1] + derangenums[j - 2]) % MOD) % MOD;
    }
}

vector<lli> segmentedSieve(lli low, lli high)
{
    // use sieve for first sqrt(n) numbers first

    vector<lli> primesinsegment;
    vector<lli> mark(high - low + 2, 1); // space optimization

    for (lli i = 0; i < primes.size(); i++)
    {
        if (primes[i] > high)
            break;

        lli lowest = ((low + primes[i] - 1) / primes[i]) * primes[i];

        for (lli j = lowest; j <= high; j += primes[i])
        {
            if (primes[i] != j)
                mark[j - low] = 0;
        }
    }

    for (lli j = max(low, 2LL); j <= high; j++)
    {
        if (mark[j - low] == 1)
            primesinsegment.push_back(j);
    }

    return primesinsegment;
}

struct matrix
{
    lli sz = 55;
    lli arr[55][55];
};

matrix matrix_multiply(matrix mat1, matrix mat2, lli sz)
{
    // multiply two square matrix of same size
    matrix tmp;

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            tmp.arr[i][j] = 0;

            for (int k = 0; k < sz; k++)
            {
                tmp.arr[i][j] += (mat1.arr[i][k] * mat2.arr[k][j]);
            }
        }
    }
    return tmp;
}
matrix matrix_pow(matrix m, lli pw, lli sz)
{
    // binary exponentiation of matrix
    if (pw == 1)
        return m;

    matrix tmp = matrix_pow(m, pw / 2, sz);
    tmp = matrix_multiply(tmp, tmp, sz);

    if (pw % 2 == 1)
    {
        tmp = matrix_multiply(tmp, m, sz);
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli t;
    cin >> t;
    lli ff = t;
    lli ncr[55][55];

    memset(ncr, 0, sizeof(ncr));
    ncr[0][0] = 1;
    for (int i = 1; i <= 54; i++)
    {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }

    while (t--)
    {
        lli n, k;
        cin >> n >> k;

        // lli B[k+2][k+2];
        matrix mat;
        // auto B=mat.arr;
        memset(mat.arr, 0, sizeof(mat.arr));

        mat.arr[0][0] = 1;

        for (int i = 1; i <= k + 1; i++)
        {
            mat.arr[0][i] = mat.arr[1][i] = ncr[k][i - 1];
        }

        for (int i = 2; i <= k + 1; i++)
        {
            for (int j = i; j <= k + 1; j++)
            {
                mat.arr[i][j] = ncr[k - i + 1][j - i];
            }
        }

        auto ans = matrix_pow(mat, n - 1, k + 2);

        // for (int i = 0; i <= k + 1; i++)
        // {
        //     for (int j = 0; j <= k + 1; j++)
        //     {
        //         cout << ans.arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        lli val = 0;

        for (int i = 0; i < k + 2; i++)
        {
            val += ans.arr[0][i];
        }
        cout << "Case " << ff - t << ": ";

        cout << val << "\n";
    }
}
