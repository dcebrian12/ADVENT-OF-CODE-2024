#include <iostream>
#include <map>

using namespace std;

bool foundInMap(map<int, int>& m, int a)
{
    map<int, int>::iterator it = m.find(a);
    return it != m.end();
}

int getDistance(map<int, int>& m1, map<int, int>& m2)
{
    map<int, int>::iterator it1;
    map<int, int>::iterator it2;
    int v = 0, n = m1.size();
    for (int i = 0; i < n; ++i)
    {
        it1 = m1.begin();
        it2 = m2.begin();
        int aux = abs(it2->first - it1->first);
        v += aux;
        (it2->second)--;
        (it1->second)--;
        if (it1->second == 0) m1.erase(it1);
        if (it2->second == 0) m2.erase(it2);

    }
    return v;
}

int main(){
    map<int, int> m1;
    map<int, int> m2;

    int a, b;
    while (cin >> a >> b)
    {
        if (!foundInMap(m1, a)) m1.insert(make_pair(a, 1));
        else m1[a]++;

        if (!foundInMap(m2, b)) m2.insert(make_pair(b, 1));
        else m2[b]++;
    }

    cout << getDistance(m1, m2) << endl;
}
