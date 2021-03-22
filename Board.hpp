#include <string>
#include <iostream>
#include "Direction.hpp"
#include <map>
using namespace std;

//Use map to rows.
namespace ariel {
    class Board {
        map<uint, map<uint, string>> billboard;

        public :
            Board(){

            }
            ~Board(){

            }
            void post(uint row, uint col, Direction dir, string str);
            string read(uint row, uint col, Direction dir, uint len);
            void show();
    };
};