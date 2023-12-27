void print_box(string data){
    for(int i = 0; i < 50 ;i++){
        cout<<"*";
    };
    cout<<endl;
    for(int i = 0; i < 50 ;i++){
        cout<<"*";
    };
    cout<<endl;
    if(data.size() < 50){
        int dif = (50 - (data.size()))/2;
        for(int i = 0; i < dif; i++){
            cout<<" ";
        };
        cout<<data;
        for(int i = dif+data.size(); i < 50; i++){
            cout<<" ";
        };
    }else{
        cout<<data;
    }
    cout<<endl;
    // cout<<data<<endl;
    for(int i = 0; i < 50 ;i++){
        cout<<"*";
    };
    cout<<endl;
    for(int i = 0; i < 50 ;i++){
        cout<<"*";
    };
    cout<<endl;
}

void print_error_box(string data){
    for(int i = 0; i < 50 ;i++){
        cout<<"x";
    };
    cout<<endl;
    if(data.size() < 50){
        int dif = (50 - (data.size()))/2;
        for(int i = 0; i < dif; i++){
            cout<<" ";
        };
        cout<<data;
        for(int i = dif+data.size(); i < 50; i++){
            cout<<" ";
        };
    }else{
        cout<<data;
    }
    cout<<endl;
    // cout<<data<<endl;
    for(int i = 0; i < 50 ;i++){
        cout<<"x";
    };
    cout<<endl;
}