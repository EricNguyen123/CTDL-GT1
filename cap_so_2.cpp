

#include <iostream>
using namespace std;
int arr[100005];
int b[100005];
int n;
int v;
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
 
 void nhap()
 {
 	v = 0;
 	cin >> n;
 	for(int i = 0; i < n; i++)
 	{
 		cin >> arr[i];
 		if(arr[i] % 2 != 0)
 		{
 			b[v] = i;
 			v++;
		}
	}
 }

int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 

int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	for(int i = 0; i < v; i++)
	{
		
	    if (right > left) {
	        
	        mid = b[i];
	 
	        
	        inv_count += _mergeSort(arr, temp, left, mid);
	        inv_count += _mergeSort(arr, temp, mid + 1, right);
	 
	        
	        inv_count += merge(arr, temp, left, mid + 1, right);
	    }
	}
    
    return inv_count;
}
 

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left; 
    j = mid;
    k = left; 
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j] && arr[i] % 2 == 0 && arr[j] % 2 == 0) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            inv_count = inv_count + (mid - i);
        }
    }
 
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
   
    while (j <= right)
        temp[k++] = arr[j++];
 
    
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 

int main()
{
    
    nhap();
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}
 

