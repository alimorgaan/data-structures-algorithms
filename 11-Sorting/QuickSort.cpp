#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &myVector, int start, int end)
{
    int pIndex = start;
    int p = myVector[end];
    int temp = 0;
    for (int i = start; i < end; i++)
    {
        if (myVector[i] < p)
        {
            temp = myVector[i];
            myVector[i] = myVector[pIndex];
            myVector[pIndex] = temp;
            pIndex++;
        }
    }
    temp = myVector[end];
    myVector[end] = myVector[pIndex];
    myVector[pIndex] = temp;
    return pIndex;
}

void quickSort(vector<int> &myVector, int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(myVector, start, end);
        quickSort(myVector, start, pIndex - 1);
        quickSort(myVector, pIndex + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {2, 8, 16, 1, 4, 6, 5, 18};

    quickSort(test, 0, test.size() - 1);

    for (auto it : test)
    {
        cout << it << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
