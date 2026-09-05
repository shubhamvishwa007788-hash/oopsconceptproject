#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
using namespace std;
string getpassword(int length){
    string password ="";
    string charctars="abcdefghijklmnopqrstuvwxyz@1234567890";
    int charctarssize=charctars.size();
    srand (time(0));
    int randomIndex;
    for(int i=0; i<length; i++){
        randomIndex=rand()% charctarssize;
        password=password+charctars[randomIndex];
    }
    return password;



}
int main(){
     int length;
     cout<<"enter the length of the password=>>>>"<<endl;
     cin>>length;
     string password=getpassword(length);
     cout<<"genrated password==="<<password<<endl;
}