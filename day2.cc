#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isSafe(const vector<int>& v)
{
    int n = v.size();
    bool asc = (v[1] > v[0]);

    for (int i = 1; i < n; ++i)
    {
        if ((abs(v[i] - v[i-1])) > 3 || (asc != (v[i] > v[i-1])) || v[i] == v[i-1]) return false;
    }

    return true;
}

int main()
{
    string line;
    int total = 0;
    while (getline(cin, line)){
        stringstream ss(line);
        vector<int> numbers;
        int number;
        while (ss >> number) numbers.push_back(number);

        if (isSafe(numbers)) total++;

    }

    cout << total;
}