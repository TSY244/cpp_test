#include <iostream>

bool func(int i)
{
    int a=i,sum=0;
    while(a)
    {
        sum+=(a%10)*(a%10)*(a%10);
        a/=10;
    }
    if(i==sum)
        return true;
    return false;
}

int main()
{
    for (int i = 100; i < 1000; ++i)
        if(func(i))
            std::cout<<i<<std::endl;
    return 0;
}
