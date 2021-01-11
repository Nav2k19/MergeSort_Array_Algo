#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
using namespace std;
//Merge-array
void Merge(int arr[], int left, int midpoint, int right)
{
    int i = left;
    int j = midpoint + 1;
    int k = right;

    int Temp[5];

    while(i<=midpoint && j<=right)
    {
        if(arr[i]< arr[j])
        {
            Temp[k] = arr[i];// arr[i] is smaller than arr[j]

            i++;
            k++;
        }

        else
        {
            Temp[k] = arr[j];//arr[j] is smaller than arr[i]
            j++;
            k++;

        } 
    }

    while(i<=midpoint)
    {
        Temp[k] = arr[i]; // copying  all elements from left Subarray to Temp as it is

        i++;
        k++;
    }

    while(j<=right)
    {
        Temp[k] = arr[j]; // copying all elements from right subarray to Temp as it is
        j++;
        k++;
    }

}
//Merge Sort
void Merge_Sort(int arr[], int left, int right)
{
    if(left<right)
    {
        int midpoint = (left + right)/2;

        Merge_Sort(arr, left, right);

        Merge_Sort(arr,midpoint+1, right);

        Merge(arr,left,midpoint,right);

    }
}
void Merge_Array(int arr[],int left, int midpoint, int right)// if array is size 5. left = 0, midpoint = 2, right = 4.
{

    int i = left;//left index
    int j = midpoint + 1;//3
    int k = right;//right index

    int Temp[5];


    while(i<=midpoint && j<=right)
    {
        if(arr[i] < arr[j])
        {
            Temp[k ] = arr[i];//left array element is less than element within the midpoint
            i++;
            k++;
        }
        else
        {
            Temp[k] = arr[j];
            j++;
            k++;

        }
    }
    while(i<=midpoint)
    {
        Temp[k] = arr[i];
        i++;
        k++;

    }

    while(j<=right)
    {
        Temp[k] = arr[j];
        j++;
        k++;
    }
}
void Merging_Sortin(int arr[], int left, int right)
{

    if(left<right)
    {

        int mid = (left + right)/2;

        Merging_Sortin(arr,left,right);


        Merging_Sortin(arr, mid + 1, right);

        Merge_Array(arr, left,mid,right);
    }
}
//write a map to organize players name to a key value, which is their jersey.


int main()

{
    unordered_map <string,int> Roster;
    Roster["James Harden"]  = 13;
    Roster["John Wall"]  = 1;
    Roster["Demarcus Cousins"]  = 15;
    Roster["Danuel House"]  = 4;
    Roster["Christian Wood"]  = 35;
    int Arr[5];

    

    unordered_map <string,int> :: iterator iterate;


    for(iterate = Roster.begin(); iterate != Roster.end(); iterate++)
    {
        for(int k = 0; k <5; k++)
        {
            Arr[k] = iterate->second;
        }
        
    }


    cout<<"The starting players for tonights game are "<<endl;

    for(int i = 0; i<5; i++)
    {
        cout<<Arr[i]<<endl;

    }

    


    return 0;
}