#include <iostream>
#include <algorithm>
#include <string>
#include"rand.h"
const int n = 10'000;
using namespace std;
int LinearSearch(int* arr, int size, int key);
int SentLinearSearch(int* arr, int size, int key);
int LinearSortedSearch(int* arr, int size, int key);
int BinarySearch(int* arr, int size, int key);
template<typename T>
void PrintAnswer(T* func, int* arr, int size, int key, string msg);

int main()
{
    setlocale(LC_ALL, "rus");
    int* a = new int[n];
    randArr(a, 10, 20'000, n);
    cout << "Test LinearSearch" << endl;
    //arr[0] = 0;
    //arr[n / 2] = 1;
    //arr[n - 1] = 2;
    //PrintAnswer(LinearSearch, arr, n, 3, "Без ключа: ");
    //PrintAnswer(LinearSearch, arr, n, 0, "С ключем в начале: ");
    //PrintAnswer(LinearSearch, arr ,n, 1, "С ключем в середине: ");
    //PrintAnswer(LinearSearch, arr, n, 2, "С ключем в конце: ");
    //cout << "Test SentLinearSearch" << endl;
    //PrintAnswer(SentLinearSearch, WhithoutKey, n, 'a', "Без ключа: ");
    //PrintAnswer(SentLinearSearch, KeyInBegin, n, 'a', "С ключем в начале: ");
    //PrintAnswer(SentLinearSearch, KeyInMiddle, n, 'a', "С ключем в середине: ");
    //PrintAnswer(SentLinearSearch, KeyInEnd, n, 'a', "С ключем в конце: ");

    //cout << endl;
    //char Alph[27];
    //for (int i = 0; i < 26; i++) {
    //    Alph[i] = 'a' + i;
    //}
    //Alph[26] = char(126);
    //cout << "Test LinearSortedSearch" << endl;
    //PrintAnswer(LinearSortedSearch, Alph, 27, '{', "Без ключа: ");
    //PrintAnswer(LinearSortedSearch, Alph, 27, 'a', "С ключем в начале: ");
    //PrintAnswer(LinearSortedSearch, Alph, 27, 'l', "С ключем в середине: ");
    //PrintAnswer(LinearSortedSearch, Alph, 27, 'z', "С ключем в конце: ");
    //char alph[26];
    //for (int i = 0; i < 26; i++) {
    //    alph[i] = 'a' + i;
    //}
    //cout << endl;
    //cout << "Test BinarySearch" << endl;
    //PrintAnswer(BinarySearch, Alph, 26, '[', "Без ключа: ");
    //PrintAnswer(BinarySearch, Alph, 26, 'a', "С ключем в начале: ");
    //PrintAnswer(BinarySearch, Alph, 26, 'l', "С ключем в середине: ");
    //PrintAnswer(BinarySearch, Alph, 26, 'z', "С ключем в конце: ");
    return 0;

}

int LinearSearch(int* arr, int size, int key)
{
    int i = 0;
    int count = 0;
    while (arr[i] != key) {
        count++;

        i++;
        count++;
        if (i == size) {

            cout << "Количество вхождений: " << count;
            return -1;
        }

    }
    cout << "Количество вхождений: " << count;
    return i;
}

int SentLinearSearch(int* arr, int size, int key)
{
    int count = 0;
    char last = arr[size - 1];
    count++;
    arr[size - 1] = key;
    count++;
    int i = 0;

    while (arr[i] != key) {
        count++;
        i++;
    }
    arr[size - 1] = last;
    count++;

    if (i < size - 1 || arr[size - 1] == key) {
        count++;
        cout << "Количество вхождений: " << count;
        return i;
    }
    cout << "Количество вхождений: " << count;
    return -1;
}

int LinearSortedSearch(int* arr, int size, int key)
{
    int count = 0;
    int i = 0;
    while (arr[i] < key) {
        i++;
        count++;
    }
    count++;
    cout << "Количество вхождений: " << count;
    if (arr[i] == key) {
        return i;
    }
    return -1;
}




int BinarySearch(int* arr, int size, int key)
{
    int low = 0, hight = size - 1, mid;
    int count = 0;
    while (low <= hight) {
        count++;
        mid = (hight + low) / 2;
        count += 3;
        if (arr[mid] > key) {
            hight = mid - 1;
            count -= 2;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
            count -= 1;
        }
        else {
            cout << "Количество вхождений: " << count;
            return mid;
        }
    }
    cout << "Количество вхождений: " << count;
    return -1;
}

template<typename T>
void PrintAnswer(T* func, int* arr, int size, int key, string msg) {
    cout << msg;
    int result = func(arr, size, key);
    if (result != -1) {
        cout << "| Индекс ключа: " << result << endl;
    }
    else cout << "| NOT_FOUND" << endl;
}