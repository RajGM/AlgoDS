#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long fibo_pro(long long n, long long m) {
    if (n <= 1)
        return n;

    long long pre = 0;
    long long cur  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = pre;
        pre = cur;
        cur = (tmp_previous + cur)%m;
    }
    
    return cur;

}

long long int fibonacci_fast(long long int n) {
    // write your code here
    if (n <= 1)
        return n;
    long long int a=0,b=1,sum=0;
    for(int i=0;i<n;i++){
        //std::cout<<"Before "<<"sum:"<<sum<<" a:"<<a<<" b:"<<b<<"\n";
        sum=a+b;
        a=b;
        b=sum;        
        //std::cout<<"After "<<"sum:"<<sum<<" a:"<<a<<" b:"<<b<<"\n";
    }
    return a;
}

long long int correctO(long long int n,long long int m){
    long long int a=0,b=1;
    long long int c=0;
    int comArr[3] = {0,1,1};
    int jIndex=0;
    long long int patternLen=0;
    if(n==0)
     return a;
    if(n==1)
     return b;
    for(int i=2;i<n+1;i++){
        //std::cout<<"Before "<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";
        c = (a+b)%m;
        a = b;
        b = c;
        //std::cout<<c<<" ";
        //std::cout<<"After "<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";
        patternLen++;
        if(c==0 && jIndex==0)
            jIndex++;
        else if(c==1 && jIndex==1){
            jIndex++;
            patternLen++;
            patternLen = patternLen-3;
            c = fibonacci_fast(n%patternLen);
            std::cout<<"Patter length:"<<patternLen<<"\n";
            std::cout<<c<<"\n";
            c = c%m;
            return c;
        }
        else{
            jIndex=0;
        }
    }
    
    return c;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << correctO(n,m);
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout <<"Pro ans:"<<fibo_pro(n,m)<<"\n";
}