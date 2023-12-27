#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <chrono>
using namespace std;

int width = 19, height = 19;
int current_user = 0;
int win = -1;
// 0 => O
// 1 => X

// int spacing = width/3;
vector<vector<int>> data = {
    {-1,-1,-1},
    {-1,-1,-1},
    {-1,-1,-1}
};

vector<vector<string>> layout(height,vector<string> (width,"x "));

vector<vector<pair<int,int>>> index = {
    {{1,1},{1,7},{1,13}},
    {{7,1},{7,7},{7,13}},
    {{13,1},{13,7},{13,13}}
}; 

vector<vector<pair<int,int>>> game_win = {
    {{0,0},{0,1},{0,2}},
    {{0,0},{1,0},{2,0}},
    {{1,0},{1,1},{1,2}},
    {{0,1},{1,1},{2,1}},
    {{2,0},{2,1},{2,2}},
    {{0,2},{1,2},{2,2}},
    {{0,0},{1,1},{2,2}},
    {{0,2},{1,1},{2,0}},
};

vector<int> key_map = {
    0,
    7,8,9,
    4,5,6,
    1,2,3
};

// 0 => O
// 1 => X
// 9*9

void set_x(int starty, int startx){
    for(int i = starty ; i < 5 + starty ; i++){
        for(int j = startx ; j < 5 + startx ; j++){
            if((i+startx == j+starty) || (i+j == (4 + startx + starty))){
                layout[i][j]="* ";
            }else{
                layout[i][j]="  ";
            }
        };
    }
}

void set_O(int starty, int startx){
    for(int i = starty ; i < 5 + starty ; i++){
        for(int j = startx ; j < 5 + startx ; j++){
            if((abs(i-j) == abs(starty-startx-2) || abs(i-j) == abs(starty-startx+2)) || (i+startx == j+starty && (i == 1+starty || i == 3+starty))){
                layout[i][j]="O ";
            }else{
                layout[i][j]="  ";
            }
        };
    }
}

void set_space(int starty,int startx){
    for(int i = starty ; i < 5 + starty ; i++){
        for(int j = startx ; j < 5 + startx ; j++){
            layout[i][j] = "  ";
        };
    }
}

void setup(){
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3 ; j++){
            pair<int,int> pr = index[i][j];
            if(data[i][j] == 0){
                set_O(pr.first,pr.second);
            }else if(data[i][j] == 1){
                set_x(pr.first,pr.second);
            }else{
                set_space(pr.first,pr.second);
            }
        }
    }
}

void print_layout(){
    system("cls");
    cout<<"New Game Tik Tak Toe"<<endl;

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            cout<<layout[i][j];
        };
        cout<<endl;
    }
}

void game_logic(){
    cout<<current_user<<endl;
    if(current_user == 0){
        for(int i = 0; i < game_win.size(); i++){
            if(win != -1){
                return;
            }
            bool current_win = true;
            for(int j = 0; j < game_win[i].size(); j++){
                if(data[game_win[i][j].first][game_win[i][j].second] != 0){
                    current_win = false;
                }
            };
            if(current_win){
                win = 0;
            }
        }
    }else if(current_user == 1){
        for(int i = 0; i < game_win.size(); i++){
            if(win != -1){
                return;
            }
            bool current_win = true;
            for(int j = 0; j < game_win[i].size(); j++){
                if(data[game_win[i][j].first][game_win[i][j].second] != 1){
                    current_win = false;
                }
            };
            if(current_win){
                win = 1;
            }
        }
    }
}

void key_input(){
    while (!kbhit())
    {    
    // if(kbhit()){
        char key = getch();
        int ky = key-'0';
        // cout<<key_map[ky]<<endl;
        if(ky>=1 && ky<= 9){
            int row = (key_map[ky]-1)/3;
            int col = (key_map[ky]-1)%3;
            // cout<<row<<" "<<col<<endl;
            if(current_user == 0){
                set_O(index[row][col].first,index[row][col].second);
                data[row][col] = 0;
                print_layout();
                game_logic();
                current_user = 1;
            }else if(current_user == 1){
                set_x(index[row][col].first,index[row][col].second);
                data[row][col] = 1;
                print_layout();
                game_logic();
                current_user = 0;
            }
        }
    // }
        break;
    }
}

void game_end(){
    if(win != -1){
        if(win == 0){
            cout<<"Game ended successfully"<<endl;
            cout<<"Winner is O"<<endl;
        }else if(win == 1){
            cout<<"Game ended successfully"<<endl;
            cout<<"Winner is X"<<endl;
        }
    }
}

int main(){

    setup();
    while (1)
    {
        cout<<"winner is : "<<win<<endl;
        print_layout();
        key_input();
        // game_logic();
        game_end();
        if(win != -1){
            for(int i = 0 ; i < 3000000000;i++){}
            break;
        }
    }
    
    return 0;
}
