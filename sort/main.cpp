// #include <iostream>
// #include <vector>
// #include <algorithm>
#include <bits/stdc++.h>
// #include <Windows.h>
// #include <MMSystem.h>
using namespace std;

vector<vector<string>> layout_data;
vector<int> bar_size;
int len;
int max_size = INT_MIN;
int isSort = 0;

void music_play(){
    // PlaySound(TEXT("ac_dc.mp3"),NULL,SND_SYNC);
    system(".\\ac_dc.mp3");
    system("pause");
    return;
}

void setup_layout_data(){
    layout_data.clear();
    for(int i = 0; i < max_size; i++){
        vector<string> temp;
        for(int j = 0; j < len; j++){
            if((i+bar_size[j]) >= max_size){
                temp.push_back("x ");
            }else{
                temp.push_back("  ");
            }
        };
        layout_data.push_back(temp);
    }
};

void print_layout(){
    for(int i = 0 ; i < max_size; i++){
        for(int j = 0; j < len; j++){
            cout<<layout_data[i][j];
        };
        cout<<endl;
    }
}

void print_index(){
    for(int i = 0 ; i < len; i++){
        cout<<i<<" ";
    }
};

void one_sort_func(){
    for(int i = 0 ; i < len-1; i++){
        if(bar_size[i] > bar_size[i+1]){
            swap(bar_size[i], bar_size[i+1]);
        };
    };
};

void isSorted(){
    vector<int> ans_vec = bar_size;
    sort(ans_vec.begin(), ans_vec.end());
    if(ans_vec == bar_size){
        // cout<<"Soted Array"<<endl;
        isSort = 1;
    }
};

void delayMaker(){
    for(int i = 0 ; i < 100000000 ; i++){}
}

int main(){

    music_play();
    int n;
    cout<<"Enter number of elements you want to sort ..."<<endl;
    cin>>n;
    len = n;
    for(int i=0; i<n; i++){
        cout<<"Enter "<<i+1<<"th Element"<<endl;
        int x;
        cin>>x;
        bar_size.push_back(x);
        max_size = max(max_size,x);
    };

    system("cls");

    // cout<<"Sorting games..."<<endl;

    setup_layout_data();
    print_layout();
    print_index();
    delayMaker();

    while (isSort != 1)
    {
        system("cls");
        // cout<<max_size<<endl;
        // cout<<"1"<<endl;
        one_sort_func();
        // cout<<"2"<<endl;
        setup_layout_data();
        // cout<<"3"<<endl;
        print_layout();
        // cout<<"4"<<endl;
        print_index();
        // cout<<"5"<<endl;
        delayMaker();
        // cout<<"6"<<endl;
        isSorted();
        // cout<<"7"<<endl;
    };
    
    // setup_layout_data();
    // system("cls");
    // print_layout();
    // print_index();

    return 0;
}