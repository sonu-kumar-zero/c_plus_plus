#include "iostream"
#include "fstream"
#include <vector>
// #include "file_handling_module.cpp"
using namespace std;

string data_of_line_number(string filename,int line_number){

    if (line_number <= 0){
        return "-1";
    }

    int i = 0;

    ifstream inputFile(filename);

    if(!inputFile.is_open()){
        return "Unable to open file ";
    };

    string s;
    while (i != line_number && getline(inputFile,s)){
        // cout<<s<<" "<<i<<endl;
        i++;
    }

    if (i < line_number){
        inputFile.close();
        return "-1";
    }
    
    inputFile.close();
    return s;
}



void user_authentication(string account_number){
    int num = stoi(account_number) + 1;
    string userfetched_data = data_of_line_number("user_details.csv",num);
    vector<string> user_details;
    string word = "";
    for (int i = 0; i < userfetched_data.size(); i++){
        if(userfetched_data[i] != ';'){
            word += userfetched_data[i];
        }else{
            user_details.push_back(word);
            word = "";
        }
    };

    for (int i = 0; i < user_details.size(); i++){
        cout << user_details[i] <<" ";
    };
    cout<<endl;
}

