#include <stdio.h>

long long cal(int num)
{
    long long result = 0;
    (num == 0 || (result = cal(num-1) + num));
    return result;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",cal(n));
    return 0;
}
