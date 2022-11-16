#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &myVector, int bound, int start)
{
    int largest = start;
    int left = start * 2 + 1;
    int right = start * 2 + 2;

    if (left <= bound && myVector[left] > myVector[largest])
    {
        largest = left;
    }

    if (right <= bound && myVector[right] > myVector[largest])
    {
        largest = right;
    }

    if (largest != start)
    {
        swap(myVector[largest], myVector[start]);
        heapify(myVector, bound, largest);
    }
}

void heapSort(vector<int> &myVector)
{
    int size = myVector.size();

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(myVector, size - 1, i);
    }

    for (int i = 0; i < size - 1; i++)
    {
        swap(myVector[0], myVector[size - 1 - i]);
        heapify(myVector, (size - 2 - i), 0);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {2, 8, 16, 1, 4, 6, 5, 18};

    heapSort(test);

    for (auto it : test)
    {
        cout << it << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
