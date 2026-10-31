#include <iostream>
#include <iomanip>
using namespace std;


void printState(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << right << setw(3) << arr[i];
    }
    cout << endl;
}

int main() 
{
    int arr[] = { 0, 0, 0, -1, 1, 1, 1 };
    int size = sizeof(arr) / sizeof(int);
    int move = 1;

    cout << "Initial state:" << endl;
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 3 moved to stone 4" << endl;
    swap(arr[2], arr[3]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 5 jumped to stone 3" << endl;
    swap(arr[4], arr[2]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 6 moved to stone 5" << endl;
    swap(arr[5], arr[4]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 4 jumped to stone 6" << endl;
    swap(arr[3], arr[5]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 2 jumped to stone 4" << endl;
    swap(arr[1], arr[3]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 1 moved to stone 2" << endl;
    swap(arr[0], arr[1]);
    cout << "State:  ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 3 jumped to stone 1" << endl;
    swap(arr[2], arr[0]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 5 jumped to stone 3" << endl;
    swap(arr[4], arr[2]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 7 jumped to stone 5" << endl;
    swap(arr[6], arr[4]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 6 moved to stone 7" << endl;
    swap(arr[5], arr[6]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 4 jumped to stone 6" << endl;
    swap(arr[3], arr[5]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 2 jumped to stone 4" << endl;
    swap(arr[1], arr[3]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 3 moved to stone 2" << endl;
    swap(arr[2], arr[1]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 5 jumped to stone 3" << endl;
    swap(arr[4], arr[2]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Move " << move++ << ":  Frog at stone 4 moved to stone 5" << endl;
    swap(arr[3], arr[4]);
    cout << "State:   ";
    printState(arr, size);
    cout << endl;

    cout << "Final state:" << endl;
    printState(arr, size);

    cout << endl;
    system("pause");
    return 0;
}