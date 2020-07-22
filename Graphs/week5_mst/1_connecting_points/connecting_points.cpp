#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <math.h>       /* pow */
using std::vector;

struct disPoints{
  public: 
  double x1;
  double x2;
  double y1;
  double y2;
  double distance = 0;
};

bool myfunction (disPoints i,disPoints j) { return (i.distance<j.distance); }

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  vector<disPoints> disVector;
  disPoints dS;

  for(int i=0;i<x.size();i++){
    dS.x1 = x[i];
    dS.y1 = y[i];  
    for(int j=1;j<x.size();j++){
      if( x[i] == x[j] && y[i] == y[j] ){
        //do nothing
      }
      else{
      dS.x2 = x[j];
      dS.y2 = y[j];
      dS.distance = pow ( ((dS.x1-dS.x2)*(dS.x1-dS.x2)) + ((dS.y1-dS.y2)*(dS.y1-dS.y2)), 0.5 );
      disVector.push_back(dS);
      }
    }
  }

    std::sort(disVector.begin(),disVector.end(),myfunction);
     
     
    //comment from here if necessary
    vector<int> dPoint;
    dPoint.push_back(0);
    
    for(int i=0;i<disVector.size();i++){
        if(i>=1 && i<disVector.size()-1){
            if(disVector[i].distance != disVector[i+1].distance){
                dPoint.push_back(i);
            }
        }
    }
    
    /*
    if(disVector[disVector.size()-1].distance!=disVector[disVector.size()-2].distance){
        dPoint.push_back(disVector.size()-2);
        dPoint.push_back(disVector.size()-1);
    }
    */
    dPoint.push_back(disVector.size()-1);
    for(int i=0;i<dPoint.size();i++){
        std::cout<<dPoint[i]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"dPoint.size():"<<dPoint.size()<<"\n";
    std::cout<<"Fault point1"<<"\n";
    int PchangePoint;
    int NchangePoint;
    if(dPoint.size()>=1){
        PchangePoint=dPoint[0];
        NchangePoint=dPoint[1];
        dPoint.erase(dPoint.begin()+0);
        dPoint.erase(dPoint.begin()+0);
    }
    
    
    std::cout<<"Fault point2"<<"\n";
    std::cout<<"dPoint.size():"<<dPoint.size()<<"\n";
    std::cout<<"disVector.size():"<<disVector.size()<<"\n";
    //check from here
    
    vector<int> eraseIndex;
    
    //fault Loop in J as it is taking wired values
    /*
    Wired loop
    Wired loop
    Wired loop
    */
    for(int i=0;i<disVector.size();i++){
        std::cout<<"Fault 1 i:"<<i<<"\n";
        disPoints dpChange;
        dpChange = disVector[i];
        std::cout<<"Fault 2 i:"<<i<<"\n";
        if(dPoint.size()>=1 && i==NchangePoint){
            PchangePoint=NchangePoint;
            NchangePoint=dPoint[0];
            std::cout<<"Erase Point Fault 1"<<"\n";
            dPoint.erase(dPoint.begin()+0);
            std::cout<<"Erase Point Fault 2"<<"\n";
        }
        std::cout<<"Fault point3"<<"\n";
        for(int fiL=PchangePoint;fiL++;fiL<=NchangePoint){
            std::cout<<"PchangePoint:"<<PchangePoint<<" NchangePoint:"<<NchangePoint<<"\n";
            std::cout<<"Fault 1 fiL:"<<fiL<<"\n";
            disPoints subdpChange;
            subdpChange = disVector[fiL];
            std::cout<<"Fault 2 fiL:"<<fiL<<"\n";
            if(dpChange.x1 == subdpChange.x2 && dpChange.y1 == subdpChange.y2){
                std::cout<<"Fault caught 1"<<"\n";
                eraseIndex.push_back(fiL);
                //disVector.erase(disVector.begin()+j-1);
                std::cout<<"Fault caught 2"<<"\n";
            }else{
                std::cout<<"Else fiL first:"<<fiL<<"\n";
                std::cout<<"::dpChange::"<<"\n";
                std::cout<<"dpChange.distance:"<<dpChange.distance<<"\n";
                std::cout<<"dpChange.x1:"<<dpChange.x1<<"\n";
                std::cout<<"dpChange.y1:"<<dpChange.y1<<"\n";
                std::cout<<"dpChange.x2:"<<dpChange.x2<<"\n";
                std::cout<<"dpChange.y2:"<<dpChange.y2<<"\n";
                
                std::cout<<"Else fiL middle:"<<fiL<<"\n";
                
                std::cout<<"::subdpChange::"<<"\n";
                std::cout<<"subdpChange.distance:"<<subdpChange.distance<<"\n";
                std::cout<<"subdpChange.x1:"<<subdpChange.x1<<"\n";
                std::cout<<"subdpChange.y1:"<<subdpChange.y1<<"\n";
                std::cout<<"subdpChange.x2:"<<subdpChange.x2<<"\n";
                std::cout<<"subdpChange.y2:"<<subdpChange.y2<<"\n";
                std::cout<<"Else fiL last:"<<fiL<<"\n";
            }
        }
    }

//check to here
  std::cout<<"i  x1 y1 x2 y2 distance"<<"\n";
  for(int i=0;i<disVector.size();i++){
      std::cout<<i<<"  "<<disVector[i].x1<<"  "<<disVector[i].y1<<"  "<<disVector[i].x2<<"  "<<disVector[i].y2<<"    "<<disVector[i].distance<<"\n";
  }

  //write your code here
  vector<int> X1disJset(x.size(),-1);
  vector<int> Y1disJset(x.size(),-1);
  vector<int> X2disJset(x.size(),-1);
  vector<int> Y2disJset(x.size(),-1);
  
  for(int i=0;i<disVector.size();i++){
      disPoints dP;
      dP = disVector[i];
     // if(X1disJset(dp.x1 != ))
  }
  
  for(int i=0;i<x.size();i++){
      
  }
  
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}