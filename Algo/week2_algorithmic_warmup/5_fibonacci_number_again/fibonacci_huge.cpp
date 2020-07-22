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

long long int fibonacci_fast(int m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long int correctO(long long int n,long long int m){
    /*
    long long int a=0,b=1;
    long long int c=0;
    int jIndex=0;
    long long int patternLen=1;
    
    if(n==0)
     return a;
    if(n==1)
     return b;
     
    for(int i=1;i<n;i++){
        //std::cout<<"Before "<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";
        c = (a+b)%m;
        a = b;
        b = c;
        //std::cout<<"C:"<<c<<"\n";
        //std::cout<<"After "<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";
        patternLen++;
        if(c==0 && jIndex==0){
            jIndex++;
        }
        else if(c==1 && jIndex==1){
            jIndex++;
        }
        else if(c==1 && jIndex==2){
            jIndex++;
            patternLen = patternLen-3;
            std::cout<<"N:"<<n<<"\n";
            std::cout<<"Patter length:"<<patternLen<<"\n";
            std::cout<<"n mod patternLen:"<<n%patternLen<<"\n";
            int fc = ((int)(n%patternLen));
            std::cout<<"Fc:"<<fc<<"\n";
            c = fibonacci_fast(fc);
            std::cout<<"F of c:"<<c<<"\n";
            c = c%m;
            //std::cout<<"Answer:"<<c<<"\n";
            return c;
        }
        else{
            jIndex=0;
        }
    }
    
    return c;
    */
    long long rem = n % fibonacci_fast(m);

    long long first = 0;
    long long second = 1;

    long long res = rem;

    for (int i = 1; i < rem; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << correctO(n,m)<<"\n";
    //std::cout <<"Naive Ans:"<<get_fibonacci_huge_naive(n, m) << '\n';
}