#include <bits/stdc++.h>
#define lli long long

#define MOD 4294967296

using namespace std;

const int MAX= 100000002;


bitset<MAX+1> isprime;
vector<int> primes;
vector<unsigned> prod;



void sieve()
{
   
    for (int i = 4; i <= MAX; i+=2)
        isprime[i] = 1;
    isprime[0]=isprime[1]=1;
    isprime[2]=0;

    for (int i = 3; i * i <= MAX; i+=2)
    {
        if (isprime[i] == 0)
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                if (isprime[j] == 0)
                    isprime[j] = 1;
            }
        }
    }
    unsigned now = 2;
    primes.push_back(2);
    prod.push_back(2);


    for (int i = 3; i <= MAX; i+=2)
    {
        if (isprime[i] == 0)
        {
            primes.push_back(i);
            now = (now * i);
            prod.push_back(now);
        }
    }


}

unsigned binExp(int base, unsigned exp)
{
    base %= MOD;
    unsigned res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * base % MOD);
        }
        base = (base * base % MOD);
        exp >>= 1;
    }
    return res;
}

unsigned cntmax(int n,unsigned p)
{
    unsigned sum=0;
    unsigned in=p;
    while(n>=in)
    {
        sum++;
        in*=p;

    }
    return sum;
}

int main()
{
    sieve();

    int t;
    cin >> t;
    int ff = t;

    while (t--)
    {
        int n;
        cin >> n;

        auto ind=upper_bound(primes.begin(),primes.end(),n)-primes.begin();

        ind--;

        unsigned lcm = prod[ind];

        //cout<<lcm<<"\n";
      

        for (int j = 0; j <= n; j++)
        {
            long long pro=primes[j] * primes[j]*1LL;
            
            if ( pro> n*1LL)
                break;

            int power=cntmax(n,primes[j])-1;
            
            //cout<<power<<"\n";
            if(power>0)
            lcm=lcm*(binExp(primes[j],power)%MOD);
        }

        

        cout << "Case " << ff - t << ": ";

        cout<<lcm<<"\n";
    }
}