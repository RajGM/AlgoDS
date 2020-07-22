#include <iostream>
#include <vector>
using std::vector;
 
 struct vwV{
   int weight;
   double vw;
 };

double get_optimal_value(int capacity, vector<vwV> vwVector) {
  double value = 0.0;
  int putItem=0;
  // write your code here
  int indexV = vwVector.size()-1;
  if(capacity==0){
            return value;
        }else{
          while(putItem<=capacity){
              std::cout<<"Current putItem:"<<putItem<<"\n";
                    if(vwVector.size()==0){
                        return value;
                    }
                    else if(vwVector[indexV].weight==0){
                        std::cout<<"Error point:"<<"\n";
                        vwVector.pop_back();
                        //vwVector.erase(vwVector.begin()+indexV-1);
                        indexV--;
                    }
                    else{
                        putItem++;
                        value=value+vwVector[indexV].vw;
                        vwVector[indexV].weight--;
                    }            
                }   
        }
     
  return value;
}

void swap(double* a, double* b) 
{ 
    double t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (vector<vwV> Vec, int low, int high) 
{ 
    double pivot = Vec[high].vw;    // pivot 
    int i = (low - 1);  // Index of smaller element 
    std::cout<<"Pivot:"<<pivot<<"\n";
    std::cout<<"i = (low - 1):"<<i<<"\n";
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (Vec[j].vw <= pivot) 
        {   
            std::cout<<"Vec[j].vw <= pivot"<<" Vec[j].vw:"<<Vec[j].vw<<" Pivot:"<<pivot<<"\n"; 
            std::cout<<"Befor I:"<<i<<"\n";
            i++;    // increment index of smaller element 
            std::cout<<"After I:"<<i<<"\n";
            std::cout<<"Before swapping:"<<" Vec[i].vw:"<<Vec[i].vw<<" Vec[j].vw:"<<Vec[j].vw<<"\n";
            swap(&Vec[i].vw, &Vec[j].vw); 
            std::cout<<"After swapping:"<<" Vec[i].vw:"<<Vec[i].vw<<" Vec[j].vw:"<<Vec[j].vw<<"\n";

        } 
    } 
    swap(&Vec[i + 1].vw, &Vec[high].vw); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(vector<vwV> Vec, int low, int high) 
{   
    std::cout<<"Low:"<<low<<" High:"<<high<<"\n";
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(Vec, low, high); 
        std::cout<<"Pi:"<<pi<<"\n";
        // Separately sort elements before 
        // partition and after partition 
        quickSort(Vec, low, pi - 1); 
        quickSort(Vec, pi + 1, high); 
    }
    std::cout<<"Low:"<<low<<" High:"<<high<<"\n";
} 

void merge(vector<vwV> arr,vector<vwV> auxA,int startI,int midpoint,int endI){ 
       for(int i=startI;i<=endI;i++){
           auxA[i].vw=arr[i].vw;
       }
    
    int i=startI,j=midpoint+1,k=startI;
    
       while(i<=midpoint && j<=endI){
        if(auxA[i].vw<auxA[j].vw){
            arr[k]=auxA[i];
            i++;
            k++;
        }
        else{
            arr[k]=auxA[j];
            j++;
            k++;
        }
    }
    
    while(i<=midpoint){
        arr[k].vw=auxA[i].vw;
        i++;
        k++;
    }
    
    while(j<=endI){
        arr[k].vw=auxA[j].vw;
        j++;
        k++;
    }
         
   }

void mergeS(vector<vwV> arr,vector<vwV> arrAux,int startI,int endI){
        if(endI-startI<=0)
            return;
        int mid = (startI+endI)/2;
        mergeS(arr,arrAux,startI,mid);
        mergeS(arr,arrAux,mid+1,endI);
        merge(arr,arrAux,startI,mid,endI);

    }

void mergeSort(vector<vwV> arr) {
		
        //vector<vwV> arrAux1 = new CompareInt[arr.size()];
        vector<vwV> arrAux1;
        arrAux1.resize(arr.size());
        mergeS(arr,arrAux1,0,arr.size()-1);     
       
	}
	
int main() {
  int n;
  int capacity;
  std::cin >> n; 
  std::cin >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  vector<vwV> vwVector;
  vwVector.resize(n);
  
  for (int i = 0; i < n; i++) {
    std::cin >> values[i];
    std::cin >> weights[i];
    vwVector[i].weight = weights[i];
    vwVector[i].vw = (double)values[i]/weights[i];
    //std::cout << vwVector[i].vw <<"\n" ;
  }
  
    //quickSort(vwVector, 0, n-1); 
    mergeSort(vwVector);

    for(int i=0;i<n;i++){
        std::cout<<vwVector[i].vw<<"\n";
    }

  double optimal_value = get_optimal_value(capacity,vwVector);

  //std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}