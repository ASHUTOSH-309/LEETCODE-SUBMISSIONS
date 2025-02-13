#include<bits/stdc++.h>
using namespace std;


typedef long long int ll;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        ll rows = 9;
        ll cols = 9;

        for (int i = 0; i < rows; i++) {

            // FOR EACH I TH ROW GENERATE A MAP
            unordered_map<ll, ll> mpp;
            for (int j = 0; j < cols; j++) {
                if(board[i][j]!='.'){
                        mpp[board[i][j] - '0']++;
                        if (mpp[board[i][j] - '0'] > 1){
                            return false;
                        }
                }
            }
        }
        for (int i = 0; i < cols; i++) {

            // FOR EACH I TH column GENERATE A MAP
            unordered_map<ll, ll> mpp;
            for (int j = 0; j < rows; j++) {
                if(board[j][i]!='.'){
                    mpp[board[j][i] - '0']++;
                    if (mpp[board[j][i] - '0'] > 1){
                        return false;
                    }
                }
            }
        }

        // check for the 3 times  3 matrix 9 timeds

        int rowStart=0;
        int colStart=0;

        int counter=0;
        for (ll x = 0; x < 9; x++) {

            unordered_map<ll,ll> SquareMap;

            for (ll i=rowStart; i < rowStart +3 ; i++) {

                for (ll j = colStart; j < colStart+3; j++) {
                        if(board[i][j]!='.'){
                            SquareMap[board[i][j]-'0']++;
                            if( SquareMap[board[i][j]-'0']>1){
                                return false;
                            }              
                        }
                }
            }

                counter++;
                if(counter%3==0){
                    rowStart+=3;
                }
            colStart+=3;
            if(colStart>=9) colStart=0;
        }

        return true;
    }
};