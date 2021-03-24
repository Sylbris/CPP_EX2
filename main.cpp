#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;
using namespace ariel;
//using ariel::Direction;

//using ANSI color codes
const string red_line = "\e[1;31m"; 
const string colors[] {"\e[1;92m", "\e[1;93m", "\e[1;94m", "\e[1;95m", "\e[1;96m"};

int main() {
    srand((unsigned)time(0));
    Board board;
    string message;

    //a - row , b - col
    unsigned int a,b,dir,len;
    for (int i=0;true;i++) {
        system("clearing");
        cout << colors[i%5];
        board.show();
        cout << red_line << "-----------------------------" << flush;
        this_thread::sleep_for(chrono::milliseconds(600));
        unsigned int choice;

        //Post or read
        cout << "\nPress 1 to post or 2 to read \n";
        cin >> choice;
        //          Post
        if (choice == 1) {
           cout << "\nEnter row col direction(1 or 2) and the message\n";
            cin >> a >> b >> dir >> message;
            if (dir == 1) {
                board.post(a,b,Direction::Vertical,message);
            }
            else {
                board.post(a,b,Direction::Horizontal,message);
            }
        }
        //         Read
        else {
            cout << "\nEnter row col direction(1 or 2) and the message\n";
            cin >> a >> b >> dir >> message;
            cout << "\nYour message :\n";
            if(dir == 1){
                cout << board.read(a,b, Direction::Vertical, len) << endl;
            }
            else{
                cout << board.read(a, b, Direction::Horizontal, len) << endl;
            }
            cout << "add more content to the board to continue:" << endl;
            cin >> a;
        }
    }
}
