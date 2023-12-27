#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;
#define height 20
#define width 40

vector<vector<string> > box(height+1,vector<string>(width+1,"*"));
char ch;

void setup(){
    
}

void print_box(){
    for (int i = 1; i < height+1; i++){
        for(int j = 1 ; j < width+1; j++){
            cout<<box[i][j];
        };
        cout<<endl;
    }
}

void keyboard_input(){
    if(kbhit()){
        ch = getch();
    }
}

int main(){


    while (1)
    {
        system("cls");
        print_box();   
        keyboard_input(); 
    }
    
    return 0;
}