#include <string>
#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"
#include <map>
using namespace std;

//Use map to rows.
namespace ariel {
            void Board :: post(uint row, uint col, Direction dir, string str){
                for(uint i=0;i<str.length();i++){
                    billboard[row][col] = str[i];
                    //Check direction
                    if(dir == Direction :: Horizontal){
                        col++;
                    }
                    else {
                        row++;
                    }
                }
            }
            string Board :: read(uint row, uint col, Direction dir, uint len){
                std :: string ans="";
                for(uint i=0;i<len;i++){
                    if(billboard.count(row)>0 && billboard[row].count(col)>0) //if value exists add it to ans.
                    {
                        ans += billboard[row][col];
                    }
                    else { //value doesn't exist don't add it.
                        ans += "_";
                    }
                    //Check direction
                    if(dir == Direction :: Horizontal){
                        col++;
                    }
                    else {
                        row++;
                    }
                }
                return ans;
                }
            void Board :: show(){
                for(uint i=min_row;i<=max_row;i++){
                    for(uint j=min_col;j<=max_col;j++){
                        cout << billboard[i][j] << " ";
                    }
                }
                cout << "\n";
            }
    
};