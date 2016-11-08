
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  #include<bits/stdc++.h>
  using namespace std;
int main()
  {
    string A="PRAVEENMADARCHOD";
    int B=4;
    int n=B;
    bool pos=true;
    string str;
    int k=1;
    int arr[A.length()]={0};
    for(int i=0;i<A.length();i++)
    {
        if(k<n && pos)
        {
            arr[i]=k;
            k++;
            continue;
        }
        if(k>1&& !pos)
        {
            arr[i]=k;
            k--;
            continue;
        }
        if(k==1 && !pos)
        {
            arr[i]=k;
            pos=true;
            k++;
            continue;
        }
        if(k==n && pos)
        {
            arr[i]=k;
            pos=false;
            k--;
            continue;
        }
        
    }
    int z=1;
    while(z<=n)
    {
    for(int i=0;i<A.length();i++)
    {
        if(arr[i]==z)
        str+=A[i];
    }
    z++;
    }
    cout<<str<<endl;;
}
