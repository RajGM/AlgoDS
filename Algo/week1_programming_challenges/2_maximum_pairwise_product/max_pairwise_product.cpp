/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long int max_product = 0;
    int n = numbers.size();
    int lar=0,slar=0;
    if(numbers[0]>numbers[1]){
        lar=numbers[0];
        slar=numbers[1];
    }else{
        lar=numbers[1];
        slar=numbers[0];
    }
    //std::cout<<lar <<" :"<<slar<<"\n";
    for (int first = 0; first < n; first++) {
        //std::cout<<numbers[first]<<"\n";
        if(numbers[first]>lar){
            slar = lar;
            lar = numbers[first];
           // std::cout<<lar<<"Largest"<<"\n";
        }
        
    }
    
    //std::cout<<lar <<" :"<<slar<<" Last assignment done";
    //max_product = (long long int)lar * (long long int)slar;
    max_product = (long long int)lar * (long long int)slar;
    return max_product;
}

long long int MaxPairwiseProduct2(const std::vector<int>& numbers){
    long long int max_product = 0;
    int n = numbers.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(((long long)numbers[i])*numbers[j] > max_product){
                max_product = ((long long)numbers[i])*numbers[j];
            }
        }
    }
    
    return max_product;
}

int main() {
    /*
    while(true){
        int n = rand() % 10 + 2;
        const std::vector<int> a;
        for(int i=0;i<n;i++){
            a.push_back ( rand() % 1000000 );
        }
        for(int i=0;i<n;i++){
            std::cout<<a[i]<<"\n";
        }
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProduct2(a);
        if(res1 != res2){
            std::cout<<"Wrong Answer"<<" Ans1:"<<res1<<" Ans2:"<<res2<<"\n";
        }else{
            std::cout<<"Correct \n";
        }
    }
    
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main() {
    
    long long int n;
    cin >> n;
    vector<long long int> number(n);
    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    sort(number.begin(),number.end());

    cout<<number[n-1]*number[n-2]; 
    return 0;
}