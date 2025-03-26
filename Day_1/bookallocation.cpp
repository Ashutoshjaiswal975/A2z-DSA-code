#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {
    int studentsRequired = 1;
    int pagesRead = 0;
    for (int i = 0; i < n; i++) {
        if (pagesRead + arr[i] > mid) {
            studentsRequired++;
            pagesRead = arr[i]; 
            if (studentsRequired > m) {
                return false;
            }
        } else {
            pagesRead += arr[i];
        }
    }
    return true;
}


int bookAllocation(int arr[], int n, int m)
{
    int s=0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;

    while (s<=e)
    {
        
        if (isPossible(arr, n, m, mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    
}


int main(){
    int size;
    cout<<"enter the size of an array: "<<endl;
    cin>>size;
    int arr[10];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
     int m;
    cout << "Enter the number of students: ";
    cin >> m;

    int minPages = bookAllocation(arr, size, m);
    cout << "Minimum number of pages a student has to read: " << minPages << endl;
    return 0;
}