#include "iostream"
#include "vector"
#include "fstream"
using namespace std;

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

// read everything
int file_reading(string filename){
    ifstream inputFile(filename);

    if (!inputFile.is_open()){
        cout<<"Error: Couldn't open file"<<endl;
        return -1;
    };

    string s;
    while (getline(inputFile, s))
    {
        cout<<s<<endl;
    }
    
    inputFile.close();
    return 1;
}

// read number of lines and return its value
int number_of_lines_in_file(string filename){
    int number_of_lines = 0;

    ifstream inputFile(filename);

    if(!inputFile.is_open()){
        cout<<"Error: Couldn't open file"<<endl;
        return -1;
    };

    string s;
    while (getline(inputFile, s))
    {
        number_of_lines++;
    }
    
    inputFile.close();
    return number_of_lines;
}

// return data data of given line number
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

// append data in file
int append_file(string filename,string data){
    ofstream outputFile(filename,ios::app);

    if(!outputFile.is_open()){
        print_error_box("Error during file opening: " + filename);
        return -1;
    };

    outputFile<<data;
    
    outputFile.close();

    print_box("Account Creation Success!!!");
    return 1;
}

// update data of given file number in file
void updating_file(string filename,string newdata,int line_number){

    ifstream inputFile(filename);
    vector<string> lines;
    string line;

    if (!inputFile.is_open()){
        cout<<"Error During file loading:  "<<filename<<endl;
        return;
    }

    while (getline(inputFile,line)){
        lines.push_back(line);
    };
    
    inputFile.close();

    if (line_number < 1 || line_number > lines.size()){
        cout<<"Invalid Account Number: "<<line_number<<endl;
        return;
    };

    lines[line_number-1] = newdata;

    ofstream outputFile(to_string(line_number)+"_"+filename);

    if(!outputFile.is_open()){
        cout<<"File generated: "<<to_string(line_number)+"_"+filename<<" failed."<<endl;
        return;
    };

    for (const auto& lini : lines){
        outputFile<<lini<<endl;
    }
    outputFile.close();

    // const char* filenametobedeleted = ;
    const string newfilename = to_string(line_number)+"_"+filename;

    if(remove(filename.c_str()) == 0){
        if(rename(newfilename.c_str(),filename.c_str()) == 0){
            cout<<"Data Changed! Successfully"<<endl;
            return;
        }else{
            cout<<"File Rename Failed"<<endl;
            return;
        }
    }else{
        cout<<"File Deletion and Rename Failed"<<endl;
        return;
    }

    return;
}


void csv_file_open(string filename, string data){
    ofstream outputFile(filename);

    if (!outputFile.is_open()){
        cout<<"error opening file the file "<<filename<<endl;
        return;
    };

    outputFile<<data;

    outputFile.close();
}
