#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::queue;
using std::vector;
using std::cin;
using std::cout;

struct queueDS{
  int worker;
  int nfreeTime;
};

struct CompareHeight { 
    bool operator()(queueDS p1, queueDS p2) 
    { 
        if(p1.nfreeTime > p2.nfreeTime){
            return true;   
        }else if(p1.nfreeTime < p2.nfreeTime){
            return false;
        }else if(p1.nfreeTime == p2.nfreeTime){
            return p1.worker > p2.worker;
        }
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
        for (int i = 0; i < m; ++i) {
            cin >> jobs_[i];
        }
    }

    void AssignJobs() {
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        std::priority_queue<queueDS, vector<queueDS>, CompareHeight> q;
        queueDS qds;
        for(int i=0;i<num_workers_;i++){
            qds.worker=i;
            qds.nfreeTime = 0;
            q.push(qds);
        }
               
        queueDS qd;
        for (int i = 0; i < jobs_.size(); i++) {
            int duration = jobs_[i];
            qd = q.top();
            
            int next_worker = qd.worker;
            int startTime = qd.nfreeTime;
            qd.nfreeTime = qd.nfreeTime + duration;
            
            q.pop();
            q.push(qd);
            assigned_workers_[i] = next_worker;
            start_times_[i] =  startTime;
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