#include <iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {          bool swap=false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap=true;
            }
        }
        if(swap==false){
            return;
        }
    }
  
}
void printarr(int arr[],int n){
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[5] = {5, 3, 2, 4, 1};
    int n = 5;
    bubblesort(arr,n);
    printarr(arr,n);
    return 0;
}