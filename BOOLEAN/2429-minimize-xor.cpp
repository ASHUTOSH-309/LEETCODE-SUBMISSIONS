#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int A, int B) {


        int OnesInB=0;
        while(B){
            // Counter to contain the number of set bits in B
            OnesInB+=B%2;
            B=B/2;
        }

        // Now Zeroes in B == Zeroes in X;

        int X=0;;
        // Now attempt to set all the possible set bits from left to 1;

        for(int i=31;i>=0 && OnesInB;i--){

                if(A & (1<<i)){
                    // The task is to minimize X xor A, now set the first possible bits in X,
                    // as this will minimize the final Xor of X xor A
                    // i th bit is set in A
                    X|= 1<<i; 
                    OnesInB--;
                }
        }


        // Now msb bits of X are set to minimze the final rrsult, but for rest set bits we are required
        // to place them at a place value which is of minimum value

        for(int i=0;i<=31 && OnesInB;i++){

            if((X & (1<<i))==0){
                  X|= 1<<i;
                  OnesInB--; 
            }
        }

        return X;
        
    }
};