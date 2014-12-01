#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    vector<int> v1, v2;
    for (int i = 0; i < 6; ++i)
        v1.push_back(i);
    for (int i = 4; i < 10; ++i)
        v2.push_back(i);

    vector<int> v_union;
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v_union, v_union.begin()));
    cout << "union: ";
    print_vector(v_union);

    vector<int> v_intersection;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v_intersection, v_intersection.begin()));
    cout << "intersection: ";
    print_vector(v_intersection);

    vector<int> v_diff;
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v_diff, v_diff.begin()));
    cout << "difference: ";
    print_vector(v_diff);

    vector<int> v_symmetric_diff;
    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v_symmetric_diff, v_symmetric_diff.begin()));
    cout << "symmetric_difference: ";
    print_vector(v_symmetric_diff);

    return 0;
}
