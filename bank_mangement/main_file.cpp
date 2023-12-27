#include "bits/stdc++.h"
// #include "user_module.cpp"
// #include "authentication_module.cpp"
// #include "file_handling_module.h"
using namespace std;


// ! decoration module 

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

// ! file handling module

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
int updating_file(string filename,string newdata,int line_number){

    ifstream inputFile(filename);
    vector<string> lines;
    string line;

    if (!inputFile.is_open()){
        cout<<"Error During file loading:  "<<filename<<endl;
        return -1;
    }

    while (getline(inputFile,line)){
        lines.push_back(line);
    };
    
    inputFile.close();

    if (line_number < 1 || line_number > lines.size()){
        cout<<"Invalid Account Number: "<<line_number<<endl;
        return -1;
    };

    lines[line_number-1] = newdata;

    ofstream outputFile(to_string(line_number)+"_"+filename);

    if(!outputFile.is_open()){
        cout<<"File generated: "<<to_string(line_number)+"_"+filename<<" failed."<<endl;
        return -1;
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
            return 1;
        }else{
            cout<<"File Rename Failed"<<endl;
            return -1;
        }
    }else{
        cout<<"File Deletion and Rename Failed"<<endl;
        return -1;
    }

    return 1;
}

// open a csv file and write data to it
void csv_file_open(string filename, string data){
    ofstream outputFile(filename);

    if (!outputFile.is_open()){
        cout<<"error opening file the file "<<filename<<endl;
        return;
    };

    outputFile<<data;

    outputFile.close();
}

// ! password hashing module

string password_hashing(string &inputString){
        uint64_t hashValue = 0;
        const int multiplier = 31;  // Chosen multiplier
        const int addend = 17;      // Chosen addend

        for (char character : inputString) {
            int charValue = static_cast<int>(character);
            hashValue = hashValue * multiplier + charValue;
        }

    // Apply a bitmask to limit the hash value to 256 bits
        const uint64_t bitmask = (1ULL << 63) - 1;  // 64 bits
        hashValue &= bitmask;

        stringstream ss;
        ss << hex << setw(16) << setfill('0') << hashValue;
        return ss.str();
    }

// ! user module

string generate_sequence(int user_account_number , string name, string password , string email , string balance){
    string sequence;
    sequence = to_string(user_account_number)+";"+name+";"+password+";"+email+";"+balance+";\n";
    return sequence;
}

class User{
    private:
    // string name,password,email;
    // int current_account_num = 0000;
    // int user_account_num ;
    string protected_user_key = "pokemon";
    // email will be unique ;
    // int number = 20;
    // account_num = 4 digits;
    // userId = name+email+username+randomNumber
    public:
    
    User(){
        print_box("New Account is Opening :");
        label1:
        cout<<"Please Provide The Key to initialize account."<<endl;
        string protected_key;
        cin>>protected_key;
        if(protected_key != protected_user_key){
            print_error_box("Something went wrong");
            goto label1;
        }

        string new_name,new_password,new_email,new_balance;
        cout<<"Enter the name of account holder (use underscore(_) in place of space) : ";
        cin>>new_name;
        cout<<endl;
        cout<<"Enter the password of account holder : ";
        // cin.getline(new_password,);
        cin>>new_password;
        cout<<endl;
        new_password = password_hashing(new_password); 
        cout<<"Enter the email of account holder : ";
        cin>>new_email;
        cout<<endl;

        cout<<"Enter the initial balance for account holder : ";
        cin>>new_balance;
        cout<<endl;

        cout<<"Initiating The New Account Creation"<<endl;

        int current_account_num = number_of_lines_in_file("user_details.csv");
        
        string sequence = generate_sequence(current_account_num, new_name, new_password, new_email, new_balance);

        if(append_file("user_details.csv", sequence) == 1){
            print_box("User Details\nUser Account Number : "+ to_string(current_account_num) + "\nUser Name : "+new_name+ "\n" +"User Balance : "+new_balance + "\nUser Email : "+new_email);

            current_account_num++;

            cout<<"Please Record the Details it will help you to access your account"<<endl;
            
            cout<<"Thanks for Account Opening!!!"<<endl;
        }else{
            print_error_box("Account Creation Failed.");
        }
    }

    

//     void print_box(string data){
//     for(int i = 0; i < 50 ;i++){
//         cout<<"*";
//     };
//     cout<<endl;
//     for(int i = 0; i < 50 ;i++){
//         cout<<"*";
//     };
//     cout<<endl;
//     if(data.size() < 50){
//         int dif = (50 - (data.size()))/2;
//         for(int i = 0; i < dif; i++){
//             cout<<" ";
//         };
//         cout<<data;
//         for(int i = dif+data.size(); i < 50; i++){
//             cout<<" ";
//         };
//     }else{
//         cout<<data;
//     }
//     cout<<endl;
//     // cout<<data<<endl;
//     for(int i = 0; i < 50 ;i++){
//         cout<<"*";
//     };
//     cout<<endl;
//     for(int i = 0; i < 50 ;i++){
//         cout<<"*";
//     };
//     cout<<endl;
// }

//     void print_error_box(string data){
//     for(int i = 0; i < 50 ;i++){
//         cout<<"x";
//     };
//     cout<<endl;
//     if(data.size() < 50){
//         int dif = (50 - (data.size()))/2;
//         for(int i = 0; i < dif; i++){
//             cout<<" ";
//         };
//         cout<<data;
//         for(int i = dif+data.size(); i < 50; i++){
//             cout<<" ";
//         };
//     }else{
//         cout<<data;
//     }
//     cout<<endl;
//     // cout<<data<<endl;
//     for(int i = 0; i < 50 ;i++){
//         cout<<"x";
//     };
//     cout<<endl;
// }

    

    // void print_number(){
    //     cout<<number<<endl;
    // }
};

// ! User Authentication module
pair<int,vector<string>> user_authentication(string account_number){
    int num = stoi(account_number) + 1;
    string userfetched_data = data_of_line_number("user_details.csv",num);
    vector<string> user_details;
    string word = "";

    if(userfetched_data == "-1"){
        print_error_box("Invalid Details");
        return {0,vector<string>()};
    }

    for (int i = 0; i < userfetched_data.size(); i++){
        if(userfetched_data[i] != ';'){
            word += userfetched_data[i];
        }else{
            user_details.push_back(word);
            word = "";
        }
    };

    // for (int i = 0; i < user_details.size(); i++){
    //     cout << user_details[i] <<" ";
    // };
    // cout<<endl;

    cout<<"Enter Your Password : ";
    string enter_pass;
    cin>>enter_pass;

    string hash_enter_pass = password_hashing(enter_pass);

    if(hash_enter_pass != user_details[2]){
        print_error_box("Invalid Details");
        return {0,vector<string>()};
    }else{
        system("cls");
        print_box("Banking Management System");
        print_error_box("Welcome "+user_details[1]);
        return {1,user_details};
    };

}

// ! User Options
void print_user_options(){
    cout<<"1 => User Details"<<endl;
    cout<<"2 => User Amount"<<endl;
    cout<<"9 => Exit() "<<endl;
}

// ! password Update
void update_password_query(){

    system("cls");
    print_box("Banking Management System");
    print_error_box("Password Updation Query");


    label2:
    cout<<"Enter Your Account Number: ";
    string acc_num;
    cin>>acc_num;

    string serching = data_of_line_number("user_details.csv",stoi(acc_num)+1);
    if(serching == "-1"){
        cout<<"Account Number is Invalid"<<endl;
        cout<<"retry : Y/n ";
        string retry;
        cin>>retry;
        if(retry == "Y" || retry == "y"){
            goto label2;
        }else{
            return;
        }
    };

    string word = "";
    vector<string> user_details;

    for (int i = 0; i < serching.size(); i++){
        if(serching[i] != ';'){
            word += serching[i];
        }else{
            user_details.push_back(word);
            word = "";
        }
    };

    cout<<"Please Enter Your Email Address"<<endl;
    string enter_email;
    cin >> enter_email;
    if(enter_email != user_details[3]){
        cout<<"Invalid details"<<endl;
        return;
    }

    cout<<"Enter New Password : ";
    string enter_pass;
    cin >> enter_pass;
    string hash_enter_pass = password_hashing(enter_pass);

    string new_seq = generate_sequence(stoi(user_details[0]), user_details[1], hash_enter_pass,user_details[3],user_details[4]);

    int up_out = updating_file("user_details.csv",new_seq,stoi(user_details[0])+1);

    if(up_out == -1){
        return;
    }
    cout<<"Success !!!"<<endl;
    return ;
}


// bank_management
int main(){
    system("cls");
    print_box("Banking Management System");

    int flag = 1;

    while (flag)
    {
    cout<<"Choose Any One Option"<<endl;
    cout<<"1 => Your Account"<<endl;
    cout<<"2 => Password Updation Query"<<endl;
    cout<<"9 => Exit()"<<endl;
    int option;
    cin >> option;
    string acc_num;
    pair<int,vector<string>> out;
    int user_exit = 0;
    switch (option){
        case 1:
        system("cls");
        print_box("Banking Management System");
        cout<<"Your Account Section"<<endl;
        cout<<"Enter Your Account Number"<<endl;
        cin>>acc_num;
        out = user_authentication(acc_num);
        if(out.first == 0){
            cout<<"Please Try Again"<<endl;
        }else if(out.first == 1){
            user_exit = 1;
            while (user_exit)
            {
                // system("cls");
                // print_box("Banking Management System");
                // print_error_box("Welcome "+out.second[1]);
                print_user_options();
                int op;
                cin >> op;
                switch (op){
                    case 1:
                    cout<<"User Details"<<endl;
                    cout<<"Account Number: "<<out.second[0]<<endl;
                    cout<<"Name: "<<out.second[1]<<endl;
                    cout<<"Email: "<<out.second[3]<<endl;
                    break;

                    case 2:
                    cout<<"Current Balance is : "<<out.second[4]<<endl;
                    break;

                    case 9:
                    user_exit = 0;
                    system("cls");
                    print_box("Banking Management System");
                    break;
                    default:
                    cout<<"Invalid Operation"<<endl;
                    break;
                }
            }
            
        }
        break;

        case 2:
        update_password_query();
        break;

        case 9632:
        new User();
        break;

        case 9:
        // cout<<"Exit initialized"<<endl;
        print_error_box("Thank You for using our Banking System");
        flag = 0;
        break;

        default:
        cout<<"Invalid Option"<<endl;
        break;
    }
    }

    // User *user = new User();

    // csv_file_open("test.csv","I;am;sonu");


    // file_reading("test.txt");
    // int line =  number_of_lines_in_file("test.txt");
    // cout << line << endl;
    // string data = data_of_line_number("test.txt",0);
    // cout<<data<<endl;

    // file_reading("test.txt");
    // cout<<"---------------------------i-------"<<endl;
    // append_file("test.txt","\nMy name is sonu kumar.");
    // updating_file("test.txt","I am sonu don.",10);
    // cout<<"----------------------------------"<<endl;
    // file_reading("test.txt");
    // cout<<"----------------------------------"<<endl;
    // cout<<user->num1<<endl;
    // user->print_number();

    return 0;
}




































// int main(){

    
//     // opening a txt file
//     // string s = "This is a writing statement.";
//     // ofstream fil("test.txt");
//     // fil<<s;

//     string s,s1,s2;
//     ifstream fil("test.txt");
//     // fil>>s;
//     getline(fil, s);
//     getline(fil, s1);
//     getline(fil, s2);
//     cout<<s<<endl;
//     cout<<s1<<endl;
//     cout<<s2<<endl;

//     return 0;
// }