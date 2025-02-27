#include <bits/stdc++.h>
using namespace std;

int MinStepsForAlternatingString(string str,int n){

    int arr[2];  // arr[0]-->0 occurences
    // arr[1]---> 1 count


    for(int i=0;i<n;i++) (str[i]== '0')? (arr[0]++):(arr[1]++);

    // check for alternating string
    bool flag=false;// string is alternate
    for(int i=1;i<n;i++){
        if(str[i-1]==str[i]){
            // if any adjacent character matches then the  shuffle & flip are required 
            flag=true;
            break;
        }
    }


    if(flag==false){// No shuffle or flip required, already alternating
        cout<<0;
        return 0;
    }
    


    if(abs(arr[0]-arr[1])<=1){
        // we reached here bcz flag=true that's why str is not already alternate
        // both are equal then also shuffle may be required like 00001111 not an alternating string
          cout<<1;
          return 1;
    }

    // Now count the extra trailing zeroes or ones
    int extra=n-2*min(arr[0],arr[1]);
    int extraSteps= (extra%2==0)? extra/2: extra/2+1;

    // 3 steps at max why
    // step 1--> shuffle such that extra zeroes or ones comes at end 
    // step 2--> for the trailing non-alternate subarray whose all elemeents are similar, flip the entire first half
    // step 3--> Now just shuffle the trailing non-alternate subarray to make it alternate 

    // Now it's done leading array is alternate and trailing too hence entire array is alternate now 

    /* 
        Special case when ans can  be 2
        for str=0000 or 1111  just two flips  
        or str=101010101010100   // skip shuffle and flip the last bit 
    */

    int ans=min(3,extraSteps);
    cout<<ans;
    return ans;

}



int main()
{

    int n;
    cin >> n;
    

    string str;
    cin>>str;

    cout<< MinStepsForAlternatingString(str,n);   
}