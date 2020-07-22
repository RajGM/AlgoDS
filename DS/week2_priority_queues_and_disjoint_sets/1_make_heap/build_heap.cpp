#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
    /*
    for(int i=0;i<data_.size();i++){
      std::cout<<data_[i]<<" ";
    }
    */
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  
  void swim(int k){
        while((k>1) && less(data_[k],data_[k/2])){
            swap(data_,k,k/2);
            k=k/2;
        }
    }
    
    void sink(int k){
        while(2*k<=data_.size()){
            int min = less(data_[2*k],data_[2*k+1])?2*k:2*k+1;
            if(less(data_[k],data_[min]))
                break;
            swap(data_,k,min);
            k=min;
        }
    }
    
    void swap(vector<int> ar,int i,int j){
        int temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
    
    bool less(int x,int y){
        return x<y;
    }

        int leftValue(int i){
    return 2*i + 1;
  }

  int rightValue(int i){
    return 2*i + 2;
  }

  int parent(int i){
    return floor((i-1)/2);
  }

  void swimDown(int i){
    int minIndex = i;
    int l = leftValue(i);
    if(l <= data_.size()-1 && data_[l] < data_[minIndex])
      minIndex = l;
    int r = rightValue(i);
    if(r <= data_.size()-1 && data_[r] < data_[minIndex])
      minIndex = r;
    if(i != minIndex){
      swap(data_,data_[i], data_[minIndex]);
      swaps_.push_back(make_pair(i, minIndex));
      swimDown(minIndex);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
    */
    
    int max=0;
    int min=0;
    int lI = data_.size()-1;
    int j=0;
    for(int i=0;i<=lI;i++){
        //std::cout<<"I:"<<i<<" J:"<<j<<" lI:"<<lI<<"\n";
        if((i==j) && (j==lI) && (i==lI))
            break;
        for(;j<=lI;j++){
            if(data_[max] <= data_[j]){
                //std::cout<<"Before:"<<" data_[max]:"<<data_[max]<<" data_[j]:"<<data_[j]<<"\n";
                max = j;
                //std::cout<<"After:"<<" data_[max]:"<<data_[max]<<" data_[j]:"<<data_[j]<<"\n";
            }
            if(data_[min] >= data_[j]){
                //std::cout<<"Before:"<<" data_[min]:"<<data_[min]<<" data_[j]:"<<data_[j]<<"\n";
                min = j;
                //std::cout<<"After:"<<" data_[min]:"<<data_[min]<<" data_[j]:"<<data_[j]<<"\n";
            }
        }
        if(max == i && min == lI){
            //std::cout<<"max == i && min == lI"<<"\n";
            //std::cout<<"max:"<<max<<" i:"<<i<<" min:"<<min<<" lI:"<<lI<<"\n";
            swaps_.push_back(make_pair(max,lI));
        }
        else if(min == i && max == lI){
            //do nothing
        }
        else{
            //std::cout<<"max != i && min != lI"<<"\n";
            //std::cout<<"max:"<<max<<" i:"<<i<<" min:"<<min<<" lI:"<<lI<<"\n";
            swaps_.push_back(make_pair(min,i));
            swaps_.push_back(make_pair(max,lI));
        }
        max=i+1;
        min=j+1;
        j=i+1;
        lI--;
    }
   
  }


   
 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
