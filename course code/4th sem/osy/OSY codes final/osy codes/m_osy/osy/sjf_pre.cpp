#include<iostream>
#include <algorithm>
using namespace std;
int min(int a[],int n){
    int mi=0;
        for(int i=1;i<=n;i++){
                if(a[mi] == 0 && a[i] != 0)mi = i;
                if(a[i] < a[mi] && a[i]!=0) {
                        mi = i;
                }
        }
        return mi;
}
        
int main()
{
        int n;
        cin >> n;
        int arr[n],burst[n],awt=0;
        for(int i=0;i<n;i++){
                cin >> arr[i] >> burst[i];
        }
        if(burst[0] <= arr[1]){
                burst[0]=0;
        }else{
                burst[0]-=arr[1];
        }
        for(int i=1;;i++){
                if((int)count(burst,burst+n,0)==n){
                        break;
                }
                if(i + 1 < n){
                        int ind=min(burst,i);
                        burst[ind]=burst[ind]-arr[i+1]+arr[i];
                        if(burst[ind] < 0)burst[ind]=0;
                        awt+=(arr[i+1]-arr[i])*(i-(int)count(burst,burst+i+1,0));
                        if(burst[ind]==0){
                                awt+=1;
                        }
                }else{
                        int ind=min(burst,n-1);
                        awt+=(n-1-count(burst,burst+n,0))*burst[ind];
                        burst[ind]=0;
                }
        }
        cout << "average waiting tym =" << ((double)awt)/n << endl;
        return 0;
}
                
             
