#include <iostream>
#include <queue>

#define ARR_SIZE 6

using namespace std;

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int middle, int high);

int main() {
    
    int unorderedArray[ARR_SIZE] = {9, 7, 8, 3, 2, 1};
    
    cout << "Unordered = [ ";
    for(int i = 0; i < ARR_SIZE; i++)
    {
        cout << unorderedArray[i] << " ";
    }
    cout << "] " << endl;
    
    mergeSort(unorderedArray, 0, ARR_SIZE - 1);
    
    cout << "Ordered = [ ";
    for(int i = 0; i < ARR_SIZE; i++)
    {
        cout << unorderedArray[i] << " ";
    }
    cout << "] " << endl;
    
}

void mergeSort(int a[], int low, int high)
{
    int middle;
    // Stop condition for unique value
    if(low < high)
    {
        middle = (low + high) / 2;
        mergeSort(a, low, middle);
        mergeSort(a, middle+1, high);
        merge(a, low, middle, high);
    }
}

void merge(int a[], int low, int middle, int high)
{
    queue<int> buffer1, buffer2;
    int i = low;
    
    for(int i=low; i <= middle; i++)
    {
        buffer1.push(a[i]);
    }
    
    for(int i = middle+1; i <= high; i++)
    {
        buffer2.push(a[i]);
    }
    
    while(!(buffer1.empty() || buffer2.empty()))
    {
        if(buffer1.front() <= buffer2.front())
        {
            a[i++] = buffer1.front();
            buffer1.pop();
        }
        else
        {
            a[i++] = buffer2.front();
            buffer2.pop();
        }
    }
    
    while(!buffer1.empty())
    {
        a[i++] = buffer1.front();
        buffer1.pop();
    }
    
    while(!buffer2.empty())
    {
        a[i++] = buffer2.front();
        buffer2.pop();
    }
}
