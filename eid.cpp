#include <bits/stdc++.h>
#define lli int
#define plli pair<lli, lli>
#define MAX 10004
#define MOD 1000000007

using namespace std;

vector<lli> fac;
vector<lli> ifac;
vector<lli> smallestprimedivisor(MAX + 1);
vector<lli> derangenums(MAX);

vector<lli> getPrimeFactorization(lli x)
{
	vector<lli> ret;
	while (x > 1)
	{
		ret.push_back(smallestprimedivisor[x]);
		x = x / smallestprimedivisor[x];
	}
	return ret;
}

void sieve()
{

	for (lli i = 0; i <= MAX; i++)
		smallestprimedivisor[i] = i;

	for (lli i = 2; i * i <= MAX; i++)
	{
		if (smallestprimedivisor[i] == i)
		{
			for (lli j = i * 2; j <= MAX; j += i)
			{
				if (smallestprimedivisor[j] == j)
					smallestprimedivisor[j] = i;
			}
		}
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

void precomputeFactorial(lli n)
{
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

int main()
{
	sieve();

	lli t;
	cin >> t;
	lli ff = t;

	while (t--)
	{
		lli n;
		cin >> n;

		map<lli, lli> factorpower;

		for (lli i = 0; i < n; i++)
		{

			lli numb;

			cin >> numb;
			vector<lli> primefactor = getPrimeFactorization(numb);

			lli ind = 0;
			lli cnt = 1;

			while ((ind + 1) < primefactor.size())
			{
				if (primefactor[ind] == primefactor[ind + 1])
				{
					cnt++;
				}
				else
				{

					factorpower[primefactor[ind]] = max(factorpower[primefactor[ind]], cnt);

					cnt = 1;
				}
				ind = ind + 1;
			}

			if (ind < primefactor.size())
			{

				factorpower[primefactor[ind]] = max(factorpower[primefactor[ind]], cnt);
			}

			
		}

		string ans = "1";

		for (auto it : factorpower)
		{

			for (lli j = 0; j < it.second; j++)
			{
				ans = bigIntMultiply(ans, it.first);
			}
		}
		reverse(ans.begin(), ans.end());

		cout << "Case " << ff - t << ": ";

		cout << ans << "\n";
	}
}