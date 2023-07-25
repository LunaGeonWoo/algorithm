#include <bits/stdc++.h>
#define NN 1e7

using namespace std;

struct Point
{
    int x, y;
};

vector<Point> locations;
int gapOfLocations[50][50];
int n, k, ans = NN;

int getGapOfPoints(Point p1, Point p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void fill_gapOfLocations()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            gapOfLocations[i][j] = gapOfLocations[j][i] = getGapOfPoints(locations[i], locations[j]);
        }
    }
}

bool isContain(vector<int> v, int num)
{
    return find(v.begin(), v.end(), num) != v.end();
}

int getMaxSheltersGap(vector<int> choosen)
{
    int maxGapOfMinGap = 0;
    for (int i = 0; i < n; i++)
    {
        int minGap = NN;
        if (isContain(choosen, i))
            continue;
        for (int j = 0; j < k; j++)
        {
            minGap = min(minGap, gapOfLocations[i][choosen[j]]);
        }
        maxGapOfMinGap = max(maxGapOfMinGap, minGap);
    }
    return maxGapOfMinGap;
}

int main()
{
    cin >> n >> k;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        locations.push_back({x, y});
    }
    fill_gapOfLocations();

    vector<int> shuffle(n);
    fill_n(shuffle.begin(), k, 1);
    do
    {
        int i = 0;
        vector<int> choosen;
        for (auto p : shuffle)
        {
            if (p == 1)
            {
                choosen.push_back(i);
                if (choosen.size() == k)
                    break;
            }
            i++;
        }
        ans = min(ans, getMaxSheltersGap(choosen));
    } while (prev_permutation(shuffle.begin(), shuffle.end()));
    cout << ans << '\n';
}
