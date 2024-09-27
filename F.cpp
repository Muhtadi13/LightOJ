#include <bits/stdc++.h>
using namespace std;
#define lli long

struct point
{
    lli x, y;
};

point p0;

point nextToTop(stack<point> &S)
{
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}

void swap(point &p1, point &p2)
{
    point temp = p1;
    p1 = p2;
    p2 = temp;
}

lli distSq(point p1, point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

lli orientation(point p, point q, point r)
{
    lli val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock 1 or counterclock wise 2
}

int compare(const void *vp1, const void *vp2)
{
    point *p1 = (point *)vp1;
    point *p2 = (point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

lli convexHull(vector<point> &points, int n)
{

    lli ymin = points[0].y, min = 0;
    for (lli i = 1; i < n; i++)
    {
        lli y = points[i].y;

        if ((y < ymin) || (ymin == y &&
                           points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);

    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(point), compare);

    lli m = 1;
    for (lli i = 1; i < n; i++)
    {

        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3)
        return m;
    stack<point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (lli i = 3; i < m; i++)
    {
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
        {

            S.pop();
        }
        S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    points.clear();
    while (!S.empty())
    {
        point p = S.top();
        points.push_back(p);
        // cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }

    return S.size();
}

lli cross_product(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}

lli sqOfDistance(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void leftmostpoint(vector<point> &points)
{
    lli mnx = 1e9 + 5;
    lli mxy = -1e9 - 5;
    lli minind = 0;
    for (lli i = 0; i < points.size(); i++)
    {
        if (points[i].x < mnx || (points[i].x == mnx && points[i].y > mxy))
        {
            mnx = points[i].x;
            mxy = points[i].y;
            minind = i;
        }
    }

    rotate(points.begin(), points.begin() + minind, points.end());
}

bool is_inside(lli x, lli y, vector<point> &points)
{
    point p1 = {points[points.size() - 1].x - points[0].x, points[points.size() - 1].y - points[0].y};
    point p2 = {points[1].x - points[0].x, points[1].y - points[0].y};
    point pq = {x - points[0].x, y - points[0].y};

    if (!(cross_product(p1, pq) <= 0 && cross_product(p2, pq) >= 0))
    {
        // cout << "mnmnmn";
        return false;
    }

    lli l = 0, r = points.size();
    while (r - l > 1)
    {
        lli mid = (l + r) / 2;
        point cur = {points[mid].x - points[0].x, points[mid].y - points[0].y};
        if (cross_product(cur, pq) < 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    if (l == points.size() - 1)
    {
        return sqOfDistance(points[0], {x, y}) <= sqOfDistance(points[0], points[l]);
    }
    else
    {
        point nwtmp = {points[l + 1].x - points[l].x, points[l + 1].y - points[l].y};
        point qtmp = {x - points[l].x, y - points[l].y};
        return (cross_product(nwtmp, qtmp) >= 0);
    }
}

void rightTangent(lli x, lli y, vector<point> &points, point &p)
{
    // cout << points.size() << "rtsize\n";
    point p1 = {points[points.size() - 1].x - x, points[points.size() - 1].y - y};
    point p2 = {points[0].x - x, points[0].y - y};
    // point pq = {x - points[0].x, y - points[0].y};

    // cout << x << "xyxyxy" << y << "\n";
    if (points.size() <= 2)
    {
        p = points[points.size() - 1];
        return;
    }

    lli l = 0, r = points.size();
    lli n = points.size();

    while (r - l > 1)
    {
        lli mid = (l + r) / 2;
        point cur = {points[mid].x - x, points[mid].y - y};
        point nxt = {points[(mid + 1) % n].x - x, points[(mid + 1) % n].y - y};
        point prev = {points[(mid + n - 1) % n].x - x, points[(mid + n - 1) % n].y - y};
        if (cross_product(cur, prev) >= 0 && cross_product(cur, nxt) >= 0)
        {
            p.x = cur.x + x;
            p.y = cur.y + y;
            // cout << p.x << " rarara" << p.y << "\n";
            return;
        }

        else if (cross_product(cur, prev) < 0 && cross_product(cur, nxt) > 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    p.x = points[l].x;
    p.y = points[l].y;
}

void leftTangent(lli x, lli y, vector<point> &points, point &p)
{
    // cout << points.size() << "size\n";
    point p1 = {points[points.size() - 1].x - x, points[points.size() - 1].y - y};
    point p2 = {points[0].x - x, points[0].y - y};
    // point pq = {x - points[0].x, y - points[0].y};
    // cout << x << "xyxyxy" << y << "\n";

    if (points.size() <= 2)
    {
        p = points[0];
        return;
    }

    lli l = 0, r = points.size();
    lli n = points.size();

    while (r - l > 1)
    {
        lli mid = (l + r) / 2;
        point cur = {points[mid].x - x, points[mid].y - y};
        point nxt = {points[(mid + 1) % n].x - x, points[(mid + 1) % n].y - y};
        point prev = {points[(mid + n - 1) % n].x - x, points[(mid + n - 1) % n].y - y};
        if (cross_product(cur, prev) <= 0 && cross_product(cur, nxt) <= 0)
        {
            p.x = cur.x + x;
            p.y = cur.y + y;
            // cout << p.x << " lalala" << p.y << "\n";
            return;
        }

        else if (cross_product(cur, prev) > 0 && cross_product(cur, nxt) < 0)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    p.x = points[l].x;
    p.y = points[l].y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {

        vector<point> quad(4);

        for (lli j = 0; j < 4; j++)
        {
            lli x, y;
            cin >> x >> y;

            quad[j].x = x;
            quad[j].y = y;
        }
        lli pivx, pivy;
        cin >> pivx >> pivy;

        lli w, h;
        cin >> w >> h;
        leftmostpoint(quad);

        lli left = quad[0].x;
        lli right = pivx;

        lli up = (right - left + w - 1) / w;

        lli low = 0;

        // lli k = 1;

        point p1, p2, p3, p4;
        lli area = 0;

        while (low <= up)
        {

            lli k = (low + up) / 2;

            lli r = pivx - k * w;

            p1.x = r;
            p1.y = pivy + k * h;

            p2.x = r;
            p2.y = pivy - k * h;

            p3.x = pivx + k * w;
            p3.y = pivy - k * h;

            p4.x = pivx + k * w;
            p4.y = pivy + k * h;

            if (!(is_inside(p1.x, p1.y, quad) && is_inside(p2.x, p2.y, quad) && is_inside(p3.x, p3.y, quad) && is_inside(p4.x, p4.y, quad)))
            {
                up = k-1;
            }

            else
            {
                low = k+1;
                area = max(area, 4 * k * k * w * h);
            }
            //cout<<low<<up<<k<<"\n";
        }

        cout << "Case " << cs << ": " << area << "\n";
    }
}