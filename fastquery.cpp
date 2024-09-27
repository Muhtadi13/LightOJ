#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define plli pair<lli, lli>
#define MAX 505
#define MOD 10000007

// segment tree updates precisely doesn,t add

// struct DataSet
// {
//     lli sum;
//     lli lt, rt;
// };

// const lli N = 1e5 + 5;
// DataSet segtree[4 * N];

// DataSet combine(DataSet l, DataSet r)
// {
//     DataSet res;
//     res.sum = l.sum + r.sum;
//     res.lt = min(l.lt, r.lt);
//     res.rt = max(l.rt, r.rt);
//     return res;
// }

// DataSet make_dataSet(lli s, plli val)
// {
//     DataSet res;
//     res.sum = s;
//     res.lt = val.first;
//     res.rt = val.second;
//     return res;
// }

// void build(vector<plli> &a, lli root, lli arrleft, lli arrright)
// {

//     if (arrleft == arrright)
//     {
//         segtree[root] = make_dataSet(1, a[arrleft]);
//     }
//     else
//     {
//         lli arrmid = (arrleft + arrright) / 2;
//         build(a, root * 2, arrleft, arrmid);
//         build(a, root * 2 + 1, arrmid + 1, arrright);
//         segtree[root] = combine(segtree[root * 2], segtree[root * 2 + 1]);
//     }
// }

// void point_update(lli root, lli arrleft, lli arrright, lli pos, plli new_val)
// {
//     if ((arrleft > pos) || (arrright < pos))
//         return;
//     if (arrleft == arrright)
//     {
//         // cout<<arrleft<<" upd "<<new_val<<"\n";
//         segtree[root] = make_dataSet(1, new_val);
//     }
//     else
//     {
//         lli arrmid = (arrleft + arrright) / 2;
//         // if (pos <= arrmid)
//         point_update(root * 2, arrleft, arrmid, pos, new_val);
//         // else
//         point_update(root * 2 + 1, arrmid + 1, arrright, pos, new_val);
//         segtree[root] = combine(segtree[root * 2], segtree[root * 2 + 1]);
//     }
// }

// DataSet query(lli root, lli arrleft, lli arrright, lli L, lli R)
// {

//     // root has a connection to arrleft or arrright not with quL or quR

//     if ((L > R) || (arrleft > arrright))
//         return make_dataSet(0, {100005, -1});
//     if ((L <= segtree[root].lt) && (segtree[root].rt <= R))
//         return segtree[root];
//     if ((L > segtree[root].rt) || (R < segtree[root].lt))
//         return make_dataSet(0, {100005, -1});
//     if (arrleft == arrright)
//     {
//         if ((L <= segtree[root].lt) && (segtree[root].rt <= R))
//         return segtree[root];

//         return make_dataSet(0, {100005, -1});
//     }

//     lli arrmid = (arrleft + arrright) / 2;
//     return combine(query(root * 2, arrleft, arrmid, L, R),
//                    query(root * 2 + 1, arrmid + 1, arrright, L, R));
// }

// segment tree updates precisely doesn,t add
vector<lli> prevind(100005, -1);
struct DataSet
{
    lli sum;
};
struct fastquery
{
    lli ind;
    lli lt;
    lli rt;
};


const lli N = 1e5 + 5;
DataSet segtree[4 * N];


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

// void debug(lli u, lli st, lli en) {
//     cout<<"--->"<<u<<" "<<st<<" "<<en<<" "<<segtree[u].sum<<"\n";
//     if (st==en) return;
//     lli mid = (st+en)/2;
//     debug(2*u, st, mid);
//     debug(2*u+1, mid+1, en);
// }

bool comp(fastquery p1,fastquery p2)
{
    if(p1.rt==p2.rt)
    return p1.lt<p2.lt;

    return p1.rt<p2.rt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t = 1;
    cin >> t;
    lli ff = t;
    while (t--)
    {
        lli n, q;
        cin >> n >> q;

        vector<lli> v(n+1);
        build(v,1,1,n);
        vector<fastquery> ran(q);
        
        for (lli i = 1; i <=n; i++)
        {
            cin >> v[i];
            prevind[v[i]]=-1;
        }

         for (lli i = 0; i < q; i++)
        {
            lli x, y;
            cin >> x >> y;
           ran[i].ind=i;
           ran[i].lt=x;
           ran[i].rt=y;
        }

        sort(ran.begin(), ran.end(),comp);
        cout << "Case " << ff - t << ":\n";
        lli j=1;
        vector<lli> ans(q);

        

        for (lli i = 0; i < q; i++)
        {
            
            while(j<=n)
            {
                if(j>ran[i].rt)
                {
                    break;
                }

                if(prevind[v[j]]!=-1)
                {
                    point_update(1,1,n,prevind[v[j]],0);
                    //cout<<v[j]<<" "<<prevind[v[j]]<<"\n";
                    
                }
                prevind[v[j]]=j;
                point_update(1,1,n,j,1);
                j++;

            }
            ans[ran[i].ind]=query(1,1,n,ran[i].lt,ran[i].rt).sum;
            //cout<<ran[i].lt<<" "<<ran[i].rt<<" "<<ans[ran[i].ind]<<"\n";

            //debug(1,1,n);

        }

        for(lli i=0;i<q;i++)
        {
            cout<<ans[i]<<"\n";
        }
    }
}
