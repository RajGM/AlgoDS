#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    std::cout<<"Naive last output:"<<current<<"\n";
    return current % 10;
}

long long int fibonacci_fast(int n) {
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
        std::cout<<"sum:"<<sum<<"\n";
    }
    return sum;
}

int correctO(int n){
    int a=0,b=1;
    int c=0;
    if(n==0)
     return a;
    if(n==1)
     return b;
    for(int i=2;i<n+1;i++){
        //std::cout<<"Before "<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";
        c = (a+b)%10;
        a = b;
        b = c;
        //std::cout<<"After "<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";
    }
    return c;
}

int main() {
    int n;
    std::cin >> n;
    //int d = get_fibonacci_last_digit_naive(n);
    //std::cout << d << '\n';
    //long long int c = 0;
    //int c = fibonacci_fast(n);
    //std::cout << c << '\n';
    int d = correctO(n);
    std::cout<<d<<"\n";
    }
