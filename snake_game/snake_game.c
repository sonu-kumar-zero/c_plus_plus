#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int width = 25, height = 25;
int snakex = 0 , snakey = 0;
int fruitx = 0 , fruity = 0;
int score = 0 , gameover = 0;
int game_flag = 1;
int key_flag = 4;
int direction_flag = 'd';

// 0 => a => left
// 1 => d => right
// 2 => w => top
// 3 => s => bottom
// 4 => no movement

void setup_game(){
    snakex = width/2;
    snakey = height/2;

    label1:
    fruitx = rand()%width;
    if(fruitx == 0 || fruitx == 1 || fruitx%2 != 0){
        goto label1;
    }

    label2:
    fruity = rand()%height;
    if(fruity == 0 || fruity == 1){
        goto label2;
    }

    score = 0, gameover = 0;
}

void new_fruit_pos(){
    label1:
    fruitx = rand()%width;

    if(fruitx == 0 || fruitx == 1 || fruitx%2 != 0){
        goto label1;
    }

    label2:
    fruity = rand()%height;
    if(fruity == 0 || fruity == 1){
        goto label2;
    }
}

void print_box()
{
    // printf("%d %d",fruitx,fruity);
    printf("Your current score is %d",score);
    printf("\n");
    for (int i = 1; i < height+1; i++)
    {
        for (int j = 1; j < width+1; j++)
        {
            if (i == 1 || i == height || j == width || j == 1)
            {
                printf("* ");
            }else if(i == snakey && j == snakex){
                printf("S ");
            }else if(i == fruity && j == fruitx){
                printf("O ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void direction_logic(char ch){
    direction_flag = ch;
    switch (ch) {
        case 'a':
            if(snakex > 1){
                snakex -= 1;
            }
            break;
        case 'd':
            if(snakex < width)
                snakex += 1;
            break;
        case 'w':
            if (snakey > 1)
                snakey -= 1;
            break;
        case 's':
            if(snakey < height)
                snakey += 1;
            break;
        case 'x':
            gameover = 1;
            break;
        default:
            break;
    }
}

void keyboard_input(){
    if(kbhit()){
        char ch = getch();
        direction_logic(ch);
    }
}

void game_logic(){
    if(snakex == fruitx && snakey == fruity){
        score++;
        new_fruit_pos();
    }else if((snakex == 1 || snakex == width) || (snakey == 1 || snakey == height)){
        gameover = 1;
    }
}

void game_exit(){
    if(gameover == 1){
        system("cls");
        printf("Your final score was %d\n", score);
        game_flag = 0;
    }
}

void run_snake(){
    for(int i = 0; i < 100000000; i++){
    }
    direction_logic(direction_flag);
}

int main()
{
    setup_game();

    while (game_flag)
    {
        system("cls");
        print_box();
        run_snake();
        keyboard_input();
        game_logic();
        game_exit();
    }

    return 0;
}