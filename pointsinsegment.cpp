#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define plli pair<lli, lli>
#define MAX 505
#define MOD 10000007



//lazy propagation
//update adds new value
struct DataSet
{
    lli sum;
};

const lli N = 1e5 + 5;
DataSet segtree[4 * N];
DataSet lazyTree[4 * N];

DataSet combine(DataSet l, DataSet r)
{
    DataSet res;
    res.sum = (l.sum + r.sum);
    return res;
}

DataSet make_dataSet(lli val)
{
    DataSet res;
    res.sum = val;
    return res;
}

void propagate(int root, int arrleft, int arrright)
{
    if (lazyTree[root].sum == 0)
        return;

    segtree[root].sum += (arrright - arrleft + 1) * lazyTree[root].sum;

    if (arrright != arrleft)
    {
        lazyTree[2 * root].sum += lazyTree[root].sum;
        lazyTree[2 * root + 1].sum += lazyTree[root].sum;
    }
    lazyTree[root]=make_dataSet(0);
}

void build(vector<lli> &a, lli root, lli arrleft, lli arrright)
{
    if (arrleft == arrright)
    {
        segtree[root] = make_dataSet(a[arrleft]);
        lazyTree[root]=make_dataSet(0);
    }
    else
    {
        lli arrmid = (arrleft + arrright) / 2;
        build(a, root * 2, arrleft, arrmid);
        build(a, root * 2 + 1, arrmid + 1, arrright);
        segtree[root] = combine(segtree[root * 2], segtree[root * 2 + 1]);
        lazyTree[root]=make_dataSet(0);
    }
}

void range_update(lli root, lli arrleft, lli arrright, lli posleft,lli posright, lli new_val)
{
    propagate(root,arrleft,arrright);
    if ((arrleft > posright) || (arrright < posleft))
        return;
    if ((posleft<=arrleft) && (posright>=arrright))
    {
        // cout<<arrleft<<" upd "<<new_val<<"\n";
        lazyTree[root].sum += new_val;
        propagate(root,arrleft,arrright);
    }
    else
    {
        lli arrmid = (arrleft + arrright) / 2;
        // if (pos <= arrmid)
        range_update(root * 2, arrleft, arrmid, posleft,posright, new_val);
        // else
        range_update(root * 2 + 1, arrmid + 1, arrright, posleft,posright, new_val);
        segtree[root] = combine(segtree[root * 2], segtree[root * 2 + 1]);
    }
}

DataSet query(lli root, lli arrleft, lli arrright, lli L, lli R)
{

    propagate(root,arrleft,arrright);
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

void debug(int u, int st, int en) {
    cout<<"--->"<<u<<" "<<st<<" "<<en<<" "<<segtree[u].sum<<" "<<lazyTree[u].sum<<"\n";
    if (st==en) return;
    int mid = (st+en)/2;
    debug(2*u, st, mid);
    debug(2*u+1, mid+1, en);
}



int main()
{
    lli t;
    cin>>t;

    lli ff=t;
    while(t--)
    {
        int n,q;

        cin>>n>>q;

        vector<plli> ran;

        vector<lli> poi(q+1);
        vector<plli> var(q+1);
        build(poi,1,1,q);
        ran.push_back({0,0});
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;

            ran.push_back({x,y});
        }
        for(int i=1;i<=q;i++)
        {

            cin>>poi[i];
            var[i]={poi[i],i};
        }

        sort(poi.begin()+1,poi.end());
        sort(var.begin()+1,var.end());
        vector<lli> summer(q+1);

        //2 11 12 20

       cout << "Case " << ff - t << ":\n";

        for(int i=1;i<=n;i++)
        {
            auto l=lower_bound(poi.begin()+1,poi.end(),ran[i].first)-poi.begin();
            auto r=upper_bound(poi.begin()+1,poi.end(),ran[i].second)-poi.begin()-1;

            //cout<<l<<r<<"\n";

            if(l<=r)
            range_update(1,1,q,l,r,1);

            //debug(1,1,q);

        }

        for(int i=1;i<=q;i++)
        {
            summer[var[i].second]=query(1,1,q,i,i).sum;
        }

         for(int i=1;i<=q;i++)
        {
            cout<<summer[i]<<"\n";
        }

        


    }
}