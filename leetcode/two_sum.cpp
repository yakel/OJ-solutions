#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        sort(numbers.begin(), numbers.end());
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] < target)  i++;
            else if (numbers[i] + numbers[j] > target)  j--;
            else {
                vector<int> v;
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
        }
    }
};

int main()
{
    vector<int> v;
    int x;
    while (cin >> x && x >= 0)
        v.push_back(x);
    int target;
    cin >> target;
    Solution s;
    vector<int> res = s.twoSum(v, target);
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
