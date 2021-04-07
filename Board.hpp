#include <string>
#include <iostream>
#include "Direction.hpp"
#include <map>
using namespace std;

//Use map to rows.
namespace ariel {
    class Board {
        map<uint, map<uint, char>> billboard; //Will store our messages.
        uint max_row, max_col, min_row, min_col; //Will store our bounds, will be used for show() func.
        public :
            //Constructor
            Board(){
                max_row = 0;
                max_col = 0;
                min_row = 0;
                min_col = 0;
            }
            //Destructor
            ~Board(){

            }
            void post(uint row, uint col, Direction dir, string str);
            string read(uint row, uint col, Direction dir, uint len);
            void show();
    };
};