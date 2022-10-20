// Link : https://www.hackerrank.com/challenges/construct-the-array/problem
#define mod 1000000007

long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
     int a=1,b=0;
     for(int i=0;i<n-1;i++){
         int ta = a, tb=b;
         a=((1LL*(k-1)*tb)%mod);
         b=(((1LL*(k-2)*tb)%mod + ta)%mod);
     }
     if(x==1)return a;
     else return b;
}
