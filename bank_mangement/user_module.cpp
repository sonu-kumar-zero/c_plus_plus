#include <bits/stdc++.h>
#include <stdlib.h>
#include "file_handling_module.cpp"
using namespace std;


// user specifications
// name
// email
// username
// userId
// password



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

        string new_name,new_password,new_email;
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

        cout<<"Initiating The New Account Creation"<<endl;

        int current_account_num = number_of_lines_in_file("user_details.csv");
        
        string sequence = generate_sequence(current_account_num, new_name, new_password, new_email);

        if(append_file("user_details.csv", sequence) == 1){
            print_box("User Details\nUser Account Number : "+ to_string(current_account_num) + "\nUser Name : "+new_name+"\n" +"User Password : "+new_password+ "\nUser Email : "+new_email);

            current_account_num++;

            cout<<"Please Record the Details it will help you to access your account"<<endl;
            
            cout<<"Thanks for Account Opening!!!"<<endl;
        }else{
            print_error_box("Account Creation Failed.");
        }
    }

    string generate_sequence(int user_account_number , string name, string password , string email){
        string sequence;
        sequence = to_string(user_account_number)+";"+name+";"+password+";"+email+";\n";
        return sequence;
    }

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

    // void print_number(){
    //     cout<<number<<endl;
    // }
};

