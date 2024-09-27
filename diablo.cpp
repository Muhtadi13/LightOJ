#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 505
#define MOD 10000007

using namespace std;

struct Query
{
    lli ind = 0, type = 0, value = 0;
};

struct DataSet
{
    lli sum;
};

const lli N = 1e5 + 5;
DataSet segtree[6 * N];

DataSet combine(DataSet l, DataSet r)
{
    DataSet res;
    res.sum = l.sum + r.sum;
    return res;
}

DataSet make_dataSet(lli val)
{
    DataSet res;
    res.sum = val;
    return res;
}

void build(vector<lli> &a, lli root, lli arrleft, lli arrright)
{
    if (arrleft == arrright)
    {
        segtree[root] = make_dataSet(a[arrleft]);
    }
    else
    {
        lli arrmid = (arrleft + arrright) / 2;
        build(a, root * 2, arrleft, arrmid);
        build(a, root * 2 + 1, arrmid + 1, arrright);
        segtree[root] = combine(segtree[root * 2], segtree[root * 2 + 1]);
    }
}

void point_update(lli root, lli arrleft, lli arrright, lli pos, lli new_val)
{
    if ((arrleft > pos) || (arrright < pos))
        return;
    if (arrleft == arrright)
    {
        // cout<<arrleft<<" upd "<<new_val<<"\n";
        segtree[root] = make_dataSet(new_val);
    }
    else
    {
        lli arrmid = (arrleft + arrright) / 2;
        // if (pos <= arrmid)
        point_update(root * 2, arrleft, arrmid, pos, new_val);
        // else
        point_update(root * 2 + 1, arrmid + 1, arrright, pos, new_val);
        segtree[root] = combine(segtree[root * 2], segtree[root * 2 + 1]);
    }
}

DataSet query(lli root, lli arrleft, lli arrright, lli L, lli R)
{

    // root has a connection to arrleft or arrright not with quL or quR
    if ((L > R) || (arrleft > arrright))
        return make_dataSet(0);
    if ((L <= arrleft) && (R >= arrright))
        return segtree[root];
    if ((L > arrright) || (R < arrleft))
        return make_dataSet(0);

    lli arrmid = (arrleft + arrright) / 2;
    return combine(query(root * 2, arrleft, arrmid, L, R),
                   query(root * 2 + 1, arrmid + 1, arrright, L, R));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin >> t;

    lli ff = t;

    while (t--)
    {
        lli n, q;
        cin >> n >> q;
        vector<lli> id;
        id.push_back(0);
        vector<lli> tarr(n + q + 1);

        for (lli i = 1; i <= n; i++)
        {
            lli x;
            cin >> x;
            id.push_back(x);
            tarr[i] = 1;
        }
      
     

      
        lli proc = 1;
         cout << "Case " << ff - t << ":\n";

         build(tarr, 1, 1, tarr.size() - 1);


        for (lli i = 0; i < q; i++)
        {
            char c;
            cin >> c;

            if (c == 'c')
            {
                lli ind;
                cin>>ind;
                lli lo = 1;
                lli hi = id.size()-1;

                while (lo <= hi)
                {
                    lli mid = (lo + hi) / 2;

                    DataSet d = query(1, 1, tarr.size() - 1, 1, mid);
                    if (d.sum >= ind)
                    {
                        hi = mid - 1;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }
                point_update(1, 1, tarr.size() - 1, lo, 0);

                if(lo>=id.size())
                cout<<"none\n";

                else
                cout<<id[lo]<<"\n";
            }
            else
            {
                lli val;
                cin >> val;

                id.push_back(val);
                point_update(1, 1, tarr.size() - 1, id.size() - 1, 1);
            }
        }

       
    }
}
