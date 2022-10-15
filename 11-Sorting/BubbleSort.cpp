#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &myVector)
{
    for (int i = 0; i < myVector.size() - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < myVector.size() - 1 - i; j++)
        {
            if (myVector[j] > myVector[j + 1])
            {
                flag = 0;
                int temp = myVector[j];
                myVector[j] = myVector[j + 1];
                myVector[j + 1] = temp;
            }
        }
        if (flag)
            break;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {6, 1, 2, 3, 10, 2, 18};
    bubbleSort(test);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }

    return 0;
}
