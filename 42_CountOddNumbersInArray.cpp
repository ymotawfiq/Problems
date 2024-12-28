// 42_CountOddNumbersInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int GetRandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}


int ReadNumber(string Message) {
    int x;
    do {
        cout << Message << endl;
        cin >> x;
    } while (x <= 0);
    return x;
}


bool IsOdd(int x) {
    return x % 2 != 0;
}

void FillArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = GetRandomNumber(1, 100);
    }
}

void AddArrayElement(int arr[], int& length, int element) {
    arr[length] = element;
    length++;
}

int CountOddArrayElements(int arr[], int length) {
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (IsOdd(arr[i])) {
            counter++;
        }
    }
    return counter;
}

void PrintArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "Key [" << i + 1 << "] = " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1Length = ReadNumber("Enter Number Of Elements");
    int arr1[100];

    FillArray(arr1, arr1Length);

    cout << "\nArray 1 Elements\n";
    PrintArray(arr1, arr1Length);

    int numberOfOddElements = CountOddArrayElements(arr1, arr1Length);

    cout << "\nArray 1 has " << numberOfOddElements << " odd elements\n";

}