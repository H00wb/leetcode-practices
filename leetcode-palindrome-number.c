#include <math.h>

int power(int num, int exp)
{
    int incrementor = 0,result = 1;
    while(incrementor != exp)
    {
        result*=num;
        ++incrementor;
    }
return result;
}

bool isPalindrome(long long int x) {
long long int digitCount= 0,y=0,temp=x;
bool result;
if(temp == 0)
{
    digitCount = 1;
}
while(temp !=0)
{
++digitCount;
temp/=10;
}
long long int arr[digitCount];
for(int i = 0; i<digitCount;i++)
{
    if(x == 10)
    {
        return false;
    }
    else if(x < 10 && x >= 0)
    {
        return true;
    }
    else if(x <0)
    {
        return false;
    }
    else
    {
    arr[i] = x / power(10,i) % 10;
    y+=arr[i]*power(10,digitCount-(i+1));
    }
    
    
}
if(x == y){
    result = true;
}
else if(x < 0)
{
    result = false;
}
else{
    result = false;
}

return result;
}
