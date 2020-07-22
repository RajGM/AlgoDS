#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>          // std::priority_queue

using std::vector;
using std::cin;
using std::cout;

struct fj{
    int indexI=0;
    int freeT=0;
};

struct DereferenceCompareNode : public std::binary_function<fj, fj, bool>
{
    bool operator()(const fj lhs, const fj rhs) const
    {
        return lhs.freeT > rhs.freeT;
    }
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    std::cout<<"Read fault"<<"\n";
    for(int l = 0; l < m; l++){
      cin >> jobs_[l];
      //cin >> jobs_.at(i);
      std::cout<<"I:"<<l<<"\n";
    }
    std::cout<<"Read fault ends"<<"\n";
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    std::cout<<"Fault point 1"<<"\n";
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    std::priority_queue<int, vector<int>, std::greater<int> > thread;
    std::priority_queue<fj, vector<fj>, DereferenceCompareNode > freeJob;
    /*
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
    */
    std::cout<<"dump point 2"<<"\n";
    for(int i=0;i<num_workers_;i++){
        thread.push(i);
    }
    std::cout<<"dump point 1"<<"\n";
    int counter = 0;
    while(jobs_.size()!=0){
        std::cout<<"jobs_.size:"<<jobs_.size()<<"\n";
        std::cout<<"freeJob.size:"<<freeJob.size()<<"\n";
        //check logic
        do{
            if(freeJob.top().freeT == counter){
                std::cout<<"freeJob.top().freeT:"<<freeJob.top().freeT<<"\n";
                std::cout<<"counter:"<<counter<<"\n";
                thread.push(freeJob.top().indexI);
                freeJob.pop();
            }else{
                break;
            }
        }
        while(freeJob.size()!=0);
        
        std::cout<<"Thread:"<<thread.size()<<"\n";
        while(thread.size()!=0){
            if(jobs_.size()!=0){
                fj currA;
                currA.indexI = thread.top();
                currA.freeT = jobs_.at(0)+counter;
                std::cout<<"currA.indexI:"<<currA.indexI<<"\n";
                std::cout<<"currA.freeT:"<<currA.freeT<<"\n";
                thread.pop();
                jobs_.erase(jobs_.begin());
                assigned_workers_.push_back(currA.indexI);
                start_times_.push_back(currA.freeT);
            }else{
                break;
            }
        }
        
        counter++;
    }
    
    
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
