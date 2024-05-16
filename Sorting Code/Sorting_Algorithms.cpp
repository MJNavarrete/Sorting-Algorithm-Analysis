// This program take in an input size for an array
// after it will sort using different algorithms
// display the sorted algorithms and comparison times and comparison numbers

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>

using namespace std;
void Display(char a[],int aSize);
void SelectionSort(char a[],int aSize, int &counter);
void InsertionSort(char a[], int aSize, int &counter);
void CountSort(char charArray[], int n, int &comparisons);
void QuickSort(char a[],int left, int right, int &counter);

int main()
{
    cout << "Searching / Sorting Benchmark" << endl;
    cout << endl << endl;

    int arraySize = 0;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int counter=0;
    int occurances=0;

    if(arraySize > 4)//given size meets requirement
    {
        char array1[arraySize];
        char array2[arraySize];
        char array3[arraySize];
        char array4[arraySize];
        char t = '0';


        srand(0);

        for(int i = 0; i<arraySize; i++)
        {
            t = 'A' + rand()%(('}' +1)-'A');
            array1[i] = t;
            array2[i] = t;
            array3[i] = t;
            array4[i] = t;
        }
        //display
        cout << "Array Elements are: ";
        Display(array1,arraySize);
        cout << endl;
        time_t startTime;
        time_t endTime;
        counter =0;



        //Selection Sort
        cout << "Selection Sort :" << endl << endl;
        startTime = clock();
        SelectionSort(array1,arraySize,counter);
        endTime = clock();
        cout << "Start Time\t: " << double(startTime)/CLOCKS_PER_SEC << endl;
        cout << "End Time\t: " << double(endTime)/CLOCKS_PER_SEC << endl;
        cout << "Actual CPU Clock Time : " << double(endTime-startTime)/CLOCKS_PER_SEC << endl;
        cout << "Total Number of Swaps : " << counter << endl;
        cout << "Sorted Elements : ";
        Display(array1,arraySize);
        cout << endl << endl;
        counter =0;



        //Insertion Sort
        cout << "Insertion Sort :" << endl << endl;
        startTime = clock();
        InsertionSort(array2, arraySize, counter);
        endTime = clock();
        cout << "Start Time\t: " << double(startTime)/CLOCKS_PER_SEC << endl;
        cout << "End Time\t: " << double(endTime)/CLOCKS_PER_SEC << endl;
        cout << "Actual CPU Clock Time : " << double(endTime-startTime)/CLOCKS_PER_SEC << endl;
        cout << "Total Number of Comparisons : " << counter << endl;
        cout << "Sorted Elements : ";
        Display(array2,arraySize);
        cout << endl << endl;
        counter =0;



        //Count Sort
        cout << "Count Sort :" << endl << endl;
        startTime = clock();
        CountSort(array3, arraySize, counter);
        endTime = clock();
        cout << "Start Time\t: " << double(startTime)/CLOCKS_PER_SEC << endl;
        cout << "End Time\t: " << double(endTime)/CLOCKS_PER_SEC << endl;
        cout << "Actual CPU Clock Time : " << double(endTime-startTime)/CLOCKS_PER_SEC << endl;
        cout << "Total Number of Comparisons : " << counter << endl;
        cout << "Sorted Elements : ";
        Display(array3,arraySize);
        cout << endl << endl;
        counter =0;



        //Quick Sort
        cout << "Quick Sort :" << endl << endl;
        startTime = clock();
        QuickSort(array4,0, arraySize-1,counter);
        endTime = clock();
        cout << "Start Time\t: " << double(startTime)/CLOCKS_PER_SEC << endl;
        cout << "End Time\t: " << double(endTime)/CLOCKS_PER_SEC << endl;
        cout << "Actual CPU Clock Time : " << double(endTime-startTime)/CLOCKS_PER_SEC << endl;
        cout << "Number of Recursive calls : " << counter << endl;
        cout << "Sorted Elements : ";
        Display(array4,arraySize);
        cout << endl << endl;
        counter =0;
    }
    else//size does not meet the requirement
    {
        cout << endl << endl;
        cout << "*** Error - Invalid input - Size must be > 4 ***" << endl;
        cout << endl << endl;
    }
    return 0;
}
void Display(char a[],int aSize)
{
    for(int i = 0; i<aSize&&i<20; i++)//displays the elements up to the first 20
        {
            cout << a[i] << " ";
        }
        cout << endl;
}
void SelectionSort(char a[],int aSize, int &counter)
{
    for (int i = 0; i < aSize - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < aSize; j++)
        {
            if (a[j] < a[min]) {
            min = j;
            }
        }
        if (i != min)
        {
            counter++;
            int swap = a[i];
            a[i] = a[min];
            a[min] = swap;
        }
    }
}
void InsertionSort(char a[], int aSize, int &counter)
{
    int j=0;
    char currentChar ;
    for (int i =0; i<aSize;i++)
    {
        counter++;
        currentChar = a[i];
        j=i-1;
        while (j>= 0 && a[j] > currentChar)
        {
            counter++;
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = currentChar;
    }

}
void QuickSort(char a[],int left, int right, int &counter)
{
    int i = left, j = right;
    int tmp;
    int pivot = a[(left + right) / 2];
    while (i <= j)
    {
    counter++;
        while (a[i] < pivot)
        {
            i++;
            counter++;
        }
        while (a[j] > pivot)
        {
            j--;
            counter++;
        }
        if (i <= j)
        {
            counter++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    counter++;
    if (left < j)
        QuickSort(a, left, j,counter);
    counter++;
    if (i < right)
        QuickSort(a, i, right,counter);

}
void CountSort(char charArray[], int n, int &comparisons){
    char min = charArray[0];
    char max = charArray[0];
    for (int i = 1; i < n; ++i) {
        if (charArray[i] < min) {
            min = charArray[i];
        } else if (charArray[i] > max) {
            max = charArray[i];
        }
    }

    //Array used to store the count of each character.
    int countRange = max - min + 1;
    int countArray[countRange] = {0};

    //Count the occurrences of each character in the array.
    for (int i = 0; i < n; ++i) {
        countArray[charArray[i] - min]++;
    }

    //Update the original array based on the results of the count array.
    int index = 0;
    for (int i = 0; i < countRange; ++i) {
        while (countArray[i] > 0) {
            charArray[index++] = i + min;
            countArray[i]--;
            // Keep track of the number of comparisons here
            comparisons++;
        }
    }
}
