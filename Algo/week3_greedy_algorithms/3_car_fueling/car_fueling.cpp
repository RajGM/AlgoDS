
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    if(dist<=tank){
        return 0;
        }
    int stopTaken=0;
    int currStation=0;
    /*
    for(int i=0;i<stops.size();i++){
        std::cout<<stops[i]<<" ";
    }
    std::cout<<"\n";
    */
    for(int i=0;i<stops.size()-1;i++){
        if(stops[i+1]-stops[i]>tank){
            //std::cout<<"stops[i+1]:"<<stops[i+1]<<" stops[i]:"<<stops[i]<<" tank:"<<tank<<"\n";
            //std::cout<<"Return point"<<"stops[i+1]-stops[i]>tank"<<"\n";
            return -1;
        }
       else if(i==stops.size()-2){
            if(stops[i+1]-stops[i]>tank){
            //std::cout<<"stops[i+1]:"<<stops[i+1]<<" stops[i]:"<<stops[i]<<" tank:"<<tank<<"\n";
            //std::cout<<"Return point"<<"i==stops.size()-2"<<"\n";
            return -1;
            }
            else{
                return stopTaken;
            }
       }
       else{
           //std::cout<<"Inside else"<<"\n";
           //std::cout<<"I:"<<i<<" stops[I+1]-stops[i]:"<<stops[i+1]-stops[i]<<"\n";
           int j=1;
           while(true){
            //std::cout<<"currStation value:"<<currStation<<" stops[currStation]:"<<stops[currStation]<<"\n";
            if(stops[currStation+j] == stops[stops.size()-1] && stops[currStation+j]-stops[currStation]<=tank){
                return stopTaken;
            }
            else if(stops[currStation+j]-stops[currStation]<tank){
                j++;
                //std::cout<<"stops[currStation+j]-stops[currStation]<tank hence j++:"<<j<<"\n";
            }else if(stops[currStation+j]-stops[currStation]==tank){
                currStation = currStation+j;
                stopTaken++;
                i=currStation-1;
                //std::cout<<"stops[currStation+j]-stops[currStation]==tank"<<"\n";
                //std::cout<<"currStation:"<<currStation<<" stopTaken:"<<stopTaken<<" i:"<<i<<"\n";
                break;
            } 
            else{
                j--;
                currStation = currStation+j;
                stopTaken++;
                i=currStation-1;
                //std::cout<<"stops[currStation+j]-stops[currStation]>tank"<<"\n";
                //std::cout<<"currStation:"<<currStation<<" stopTaken:"<<stopTaken<<" i:"<<i<<"\n";
                break;
            }
            
            if(j>stops.size()){
             //std::cout<<"Return point"<<"j>stops.size()"<<"\n";
                return -1;
            }
            
           }
       }
       
    }
    
    return stopTaken;
}


int main(){
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops;
    stops.resize(n+2);
    stops[0]=0;
    stops[n+1]=d;
    //std::cout<<stops.size()<<"Size"<<"\n";
    for (int i = 1; i <= n; i++){
        cin >> stops[i];
    }
    /*
    for(int i=0;i<stops.size();i++){
        std::cout<<stops[i]<<" ";
    }
    */
    //std::cout<<"\n";
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}


