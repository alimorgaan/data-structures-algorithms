#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v3.begin();
    while (it1 != v1.end() && it2 != v2.end())
    {
        if (*it1 < *it2)
        {
            *it3 = *it1;
            it1++;
        }
        else
        {
            *it3 = *it2;
            it2++;
        }
        it3++;
    }
    while (it1 != v1.end())
    {
        *it3 = *it1;
        it1++;
        it3++;
    }
    while (it2 != v2.end())
    {
        *it3 = *it2;
        it2++;
        it3++;
    }
}

void mergeSort(vector<int> & myVector)
{
    if (myVector.size() < 2)
        return;

    int mid = myVector.size() / 2;
    vector<int> left(mid);
    vector<int> right(myVector.size() - mid);
    auto it = myVector.begin();
    auto leftIt = left.begin();
    auto rightIt = right.begin();

    while (leftIt != left.end()){
        *leftIt = *it;
        leftIt++;
        it++;
    }

    while (rightIt != right.end()){
        *rightIt = *it;
        rightIt++;
        it++;
    }

    mergeSort(left);
    mergeSort(right);
    merge(left, right, myVector);
}

int main(int argc, char const *argv[])
{
    vector<int> test = {2, 8, 16, 1, 4, 6, 5, 18};

    mergeSort(test);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }

    return 0;
}
