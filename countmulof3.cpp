#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define plli pair<lli, lli>
#define MAX 505
#define MOD 10000007

// lazy propagation
// update adds new value
struct DataSet
{
    lli zero,one,two,howmany;
};

const lli N = 1e5 + 5;
//DataSet segtree[4 * N];
DataSet lazyTree[4 * N];



DataSet make_dataSet(lli val1,lli val2,lli val3,lli val4)
{
    DataSet res;
    res.zero = val1;
    res.one=val2;
    res.two=val3;
    res.howmany=val4;
    return res;
}

DataSet combine(DataSet l, DataSet r)
{
    DataSet res;
    res.howmany=0;
    res.zero=l.zero+r.zero;
    res.one=l.one+r.one;
    res.two=l.two+r.two;
    return res;
}


void propagate(int root, int arrleft, int arrright)
{
    if(lazyTree[root].howmany==0)
    return;

    lli h=lazyTree[root].howmany%3;
    for(int i=0;i<h;i++)
    {
        lli temp=lazyTree[root].two;
        lazyTree[root].two=lazyTree[root].one;
        lazyTree[root].one=lazyTree[root].zero; 
        lazyTree[root].zero=temp;
    }
     
    // segtree[root].zero=lazyTree[root].zero;
    // segtree[root].one=lazyTree[root].one;
    // segtree[root].two=lazyTree[root].two;

    if (arrright != arrleft)
    {
        lazyTree[2 * root].howmany += lazyTree[root].howmany;
        lazyTree[2 * root + 1].howmany += lazyTree[root].howmany;
    }
    lazyTree[root].howmany = 0;
}

void build(vector<lli> &a, lli root, lli arrleft, lli arrright)
{
    if (arrleft == arrright)
    {
        //segtree[root] = make_dataSet(1,0,0,0);
        lazyTree[root] = make_dataSet(1,0,0,0);
    }
    else
    {
        lli arrmid = (arrleft + arrright) / 2;
        build(a, root * 2, arrleft, arrmid);
        build(a, root * 2 + 1, arrmid + 1, arrright);
        lazyTree[root] = combine(lazyTree[root * 2], lazyTree[root * 2 + 1]);
        //lazyTree[root] = make_dataSet(0);
    }
}

void range_update(lli root, lli arrleft, lli arrright, lli posleft, lli posright, lli new_val)
{
    propagate(root, arrleft, arrright);
    if ((arrleft > posright) || (arrright < posleft))
        return;
    if ((posleft <= arrleft) && (posright >= arrright))
    {
        // cout<<arrleft<<" upd "<<new_val<<"\n";
        lazyTree[root].howmany += new_val;
        propagate(root, arrleft, arrright);
    }
    else
    {
        lli arrmid = (arrleft + arrright) / 2;
        // if (pos <= arrmid)
        range_update(root * 2, arrleft, arrmid, posleft, posright, new_val);
        // else
        range_update(root * 2 + 1, arrmid + 1, arrright, posleft, posright, new_val);
        lazyTree[root] = combine(lazyTree[root * 2], lazyTree[root * 2 + 1]);
    }
}

DataSet query(lli root, lli arrleft, lli arrright, lli L, lli R)
{

    propagate(root, arrleft, arrright);
    // root has a connection to arrleft or arrright not with quL or quR

    if ((L > R) || (arrleft > arrright))
        return make_dataSet(0,0,0,0);
    if ((L <= arrleft) && (R >= arrright))
        return lazyTree[root];
    if ((L > arrright) || (R < arrleft))
        return make_dataSet(0,0,0,0);

    lli arrmid = (arrleft + arrright) / 2;
    return combine(query(root * 2, arrleft, arrmid, L, R),
                   query(root * 2 + 1, arrmid + 1, arrright, L, R));
}

// void debug(int u, int st, int en)
// {
//     cout << "--->" << u << " " << st << " " << en << " " << segtree[u].sum << " " << lazyTree[u].sum << "\n";
//     if (st == en)
//         return;
//     int mid = (st + en) / 2;
//     debug(2 * u, st, mid);
//     debug(2 * u + 1, mid + 1, en);
// }

int main()
{
    lli t;
    cin >> t;

    lli ff = t;
    while (t--)
    {
        int n, q;

        cin >> n >> q;

        vector<lli> poi(n);

        build(poi, 1, 0, n-1);

        cout << "Case " << ff - t << ":\n";

        for (int i = 1; i <= q; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;

            if (x == 0)
                range_update(1, 0, n-1, y, z, 1);

            else
                cout << query(1, 0, n-1, y, z).zero << "\n";

            //debug(1, 0, n-1);
            //cout << "\n";
        }
    }
}