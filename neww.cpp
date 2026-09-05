#include<iostream>
using namespace std;
class person {
    protected:
    string name;
    int age;
    public:
    void getpersonaldata(){
        cout<<" plese enter the name=\n"<<endl;
        cin>>name;
        cout<<"enter your age=\n"<<endl;
        cin>>age;

    }
    void showpersondata(){
        cout<<"name="<<name<<endl;
        cout<<"age="<<age<<endl;

    }
};
// hierarchical inheritance 
class patient :public person{
    protected:
    int patientid;
    string disease;
    public:
    void getpatientdata(){
        getpersonaldata();
        cout<<"enter the patient id\n";
        cin>>patientid;
        cout<<"enter type of disease:\n";
        cin>>disease;


    }
    void showpatientdata(){
        showpersondata();
        cout<<"patient id"<<patientid <<endl;
        cout<<"disease<<"<<disease<<endl;

    }

};
//hierachical inheritence
class doctor:public person{
    private:
    int doctorid;
    string speciization;
    public:
    void getdoctordata(){
        getpersonaldata();
        cout<<"enter the doctor id"<<endl;

        cin>>doctorid;
        cout<<"enter doctor specialization";
        cin>>speciization;




    }
    void showdoctordata(){
        showpersondata();
        cout<<"doctor id="<<doctorid<<endl;
        cout<<"specialization="<<endl;

    }


};
//use the multilevel
class inpatient:public patient{
    protected:
    int roomno;
    int days;
    public:
    void getinpatientdata(){
        getpatientdata();
        cout<<"enter  the room number "<<endl;
        cin>>roomno;
        cout<<"enter number of living  days";
        cin>>days;



    }
    void showinpatientdata(){
        showinpatientdata();
        cout<<"room number"<<roomno<<endl;
        cin>>roomno;
        cout<<"days "<<days<<endl;


    }

};
//multipal inheritence
class medical{
    protected:
    string medicine;
    public:
    void getmedicaldata(){
        cout<<"enter  all medicine name";
        cin>>medicine ;

    }
    void showmedicaldata(){
        cout<<"medicine="<<medicine<<endl;

    }

};
class billing {
    protected:
    int doctorfee;
    int roomfee;
    public:
    void getbilldta(){
        cout<<"enter the doctor fee";
        cin>>doctorfee;
        cout<<"enter  your room fee";
        cin>>roomfee;

    }
    void showbill(){
         int total =doctorfee+roomfee;
         cout<<"doctor fee =\n"<<doctorfee<<endl;
         cout<<"room fee =\n"<<roomfee<<endl;
         cout<<"total bill ==\n"<<total<<endl;

    }
};
class patientrecord:public patient,public medical,public billing{
    public:
    void getrecord(){
       cout<<"patient detial\n";
        getpatientdata();
        getmedicaldata();
        getbilldta();


    }
    void showrecord(){
        cout<<"record\n";
        showpatientdata();
        showmedicaldata();
        cout<<"total bill";
        showbill();

    }

};
int main(){
    patientrecord patient;
    doctor doctor;
    int choice;
    do{
        cout<<"Hospital Mangement System----\n"<<endl;
        cout<<"1>> Add new patient\n";
        cout<<"2>> Show patient\n";
        cout<<"3>> Add new doctor\n";
        cout<<"4>> Show doctor\n";
        cout<<"5>> niklo baahar\n";
        cout<<" ak number select karo=";
        cin>>choice;
        switch(choice){
            case 1:
            patient.getrecord();
            cout<<"patient add ho gya hospital me\n";
            break;
            case 2:
            patient.showrecord();
            break;
            case 3:
        
            doctor.getdoctordata();
            cout<<"doctor add in hospital\n";
            break;
            case 4:
           
            doctor.showdoctordata();
             cout<<"docotor detail\n";
            break;
            case 5:
            cout<<"thanks you padharne ke liye\n";
            break;
            default:
            cout<<"galat mat choice karo \n";
            break;
            // while(choice!=5);

        }
        // while(choice!=5);
    }
    //while(choice!=5);
     while(choice!=5);



    return 0;

}
