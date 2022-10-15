#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &myVector)
{
    for (int i = 0; i < myVector.size() - 1; i++)
    {
        int tempIndex = i;
        for (int j = i + 1; j < myVector.size(); j++)
        {
            if (myVector[j] < myVector[tempIndex])
            {
                tempIndex = j;
            }
        }
        int tempData = myVector[tempIndex];
        myVector[tempIndex] = myVector[i];
        myVector[i] = tempData;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {6, 1, 2, 3, 10, 2, 18};
    selectionSort(test);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }

    return 0;
}
