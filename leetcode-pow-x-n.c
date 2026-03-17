double myPow(double x, int n) {
    long long abs_n  = n;
    double result = 1.0;
    if(n == 0)
    {
        return 1.0;
    }

    if(n < 0)
    {
       x = 1/x;
       abs_n = -abs_n;
    }
    
    while (abs_n > 0)
    {
       if (abs_n % 2 == 1) {
            result = result * x;
        }
        x = x * x;           
        abs_n /= 2;
    }
    return result;
}
