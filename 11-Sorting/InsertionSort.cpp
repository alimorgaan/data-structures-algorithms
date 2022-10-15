#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &myVector)
{
    for (int i = 1; i < myVector.size(); i++)
    {
        int temp = myVector[i];
        int holeIndex = i; 
        while (myVector[holeIndex - 1] > temp && holeIndex > 0)
        {
            myVector[holeIndex] = myVector[holeIndex - 1]; 
            holeIndex--; 
        }
        myVector[holeIndex] = temp; 
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {6, 1, 2, 3, 10, 2, 18 , 20 , 15};
    insertionSort(test);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }

    return 0;
}
