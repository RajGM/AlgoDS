#include <algorithm>
#include <iostream>
#include <vector>
#include <array> 
#include <algorithm>

using std::vector;

int findMajority(int arr[], int n)  
{  
    int maxCount = 0;  
    int index = -1; // sentinels  
    for(int i = 0; i < n; i++)  
    {  
        int count = 0;  
        for(int j = 0; j < n; j++)  
        {  
            if(arr[i] == arr[j])  
            count++;  
        }  
          
        // update maxCount if count of  
        // current element is greater  
        if(count > maxCount)  
        {  
            maxCount = count;  
            index = i;  
        }  
    }  
      
    // if maxCount is greater than n/2  
    // return the corresponding element  
    if (maxCount > n/2)  
        return 1;
    else
        return 0;  
}  



int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}



int get_maj(vector<int> arr,int n){
    int majority = (n/2);
    int majcount=0;
    //std::cout<<"Majority:"<<majority<<"\n";
    if(n==1)
        return 1;
    if(n == 0)
        return 0;
    
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            majcount++;
            
            if(i==n-2)
                majcount++;
            
            if(majcount>majority)
                return 1;
        }
        else if(arr[i]!=arr[i+1]){
            majcount++;
            if(majcount>majority)
                return 1;
                
            majcount=0;
            }
    }
    return 0;
}

int majE(int arr[],int n){
    int count=1;
    int maxE = -1;
    int temp = arr[0];
    int ele;
    
    if(n==1)
        return 1;
    if(n == 0)
        return 0;
    
    for(int i=1;i<n;i++){
        if(temp==arr[i])
            count++;
        else{
            count =1;
            temp=arr[i];
        }
        
        if(maxE<count){
            maxE = count;
            ele = arr[i];
            if(maxE>n/2){
                return 1;
            }
        }
    }
    
    return 0;
    
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
} 
  

int main() {
  /*
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  */
  
  int n;
  std::cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  //quickSort(a, 0, n-1); 
  //printArray(a, n); 
  //std::cout<<get_maj(a,n);
  //std::cout<<majE(a,n);
  //std::cout<<findMajority(a, n);  
  sort(a.begin(),a.end());
  std::cout<<get_maj(a,n);
  
  /*
  //stress testings start
  while(true){
  int n = rand() % 100000;
  int a[n];
  for(int i=0;i<n;i++){
      a[i] = rand() % 1000000000;
  }
  std::cout<<"Input done"<<"\n";
  quickSort(a, 0, n-1); 
  //printArray(a, n); 
  std::cout<<"Sorting done"<<"\n";
  int majERes = majE(a,n);
  int get_majRes = get_maj(a,n);
  int findMajorityRes = findMajority(a, n);
  if(majERes == get_majRes && findMajorityRes == get_majRes && majERes == findMajorityRes){
      std::cout<<"All equal"<<"\n";
  }else{
      std::cout<<"All unequal"<<"\n";
      std::cout<<"majERes:"<<majERes<<"\n";
      std::cout<<"get_majRes:"<<get_majRes<<"\n";
      std::cout<<"findMajorityRes:"<<findMajorityRes<<"\n";
  }
  //std::cout<<majE(a,n);
  //std::cout<<findMajority(a, n);  
  //std::cout<<get_maj(a,n);
  }
  std::cout<<"\n";
  //stress testing ends
  */
   /*
   std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
*/
}