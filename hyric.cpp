#include<iostream>
using namespace std;
class student {
    public:
    void studentinfo(){
        cout<<"student details"<<endl;

    }
};
class sports:public student{
    public:
    
    void sportsmarks(){
        cout<<"sport marks add"<<endl;

    }
};
class acrdimc{//create a 2 ew class
public:
void acrdimcmarks(){
    cout<<"acrdimc marks details"<<endl;
}
};
class result:public sports,public acrdimc{
   public:
   void finalresult(){
    cout<<"finalresult prepered"<<endl;

   } 
};
int main(){
    result r;

    r.acrdimcmarks();
    r.sportsmarks();
    r.studentinfo();
    r.finalresult();
}