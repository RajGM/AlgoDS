#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    //std::cout<<"Before:"<<"prev:"<<previous<<" current:"<<current<<" sum:"<<sum<<"\n";
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
       // std::cout<<"After:"<<"prev:"<<previous<<" current:"<<current<<" sum:"<<sum<<"\n";
        //std::cout<<"sum:"<<sum%10<<"\n";
    }

    return sum % 10;
}

long long int fibonacci_fast(long long int n) {
    if (n <= 1)
        return n;
    long long int a=0,b=1,c=0,sum=1;
    //std::cout<<"Before "<<" a:"<<a<<" b:"<<b<<" c:"<<c<<"sum:"<<sum<<"\n";
    long long int anspoint = n%61;
    for(long long int i=0;i<anspoint;i++){
        c=(a+b)%10;
        a=b;
        b=c;
        sum = (sum + c)%10;
        //std::cout<<"After "<<" a:"<<a<<" b:"<<b<<" c:"<<c<<"sum:"<<sum<<"\n";
    }
    return sum;
}
    
int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n)<<"\n";
    std::cout << fibonacci_fast(n)<<"\n";
}
