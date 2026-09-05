#include <iostream>
#include <string>
using namespace std;

// ==========================================
// BASE CLASS
// ==========================================

class Person
{
protected:
    string name;
    int age;

public:
    void getPersonData()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;
    }

    void showPersonData()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};


// ==========================================
// HIERARCHICAL INHERITANCE
// Person -> Patient
// ==========================================

class Patient : public Person
{
protected:
    int patientId;
    string disease;

public:
    void getPatientData()
    {
        getPersonData();

        cout << "Enter Patient ID: ";
        cin >> patientId;

        cout << "Enter Disease: ";
        cin >> disease;
    }

    void showPatientData()
    {
        showPersonData();

        cout << "Patient ID : " << patientId << endl;
        cout << "Disease    : " << disease << endl;
    }
};


// ==========================================
// HIERARCHICAL INHERITANCE
// Person -> Doctor
// ==========================================

class Doctor : public Person
{
private:
    int doctorId;
    string specialization;

public:
    void getDoctorData()
    {
        getPersonData();

        cout << "Enter Doctor ID: ";
        cin >> doctorId;

        cout << "Enter Specialization: ";
        cin >> specialization;
    }

    void showDoctorData()
    {
        showPersonData();

        cout << "Doctor ID      : " << doctorId << endl;
        cout << "Specialization : " << specialization << endl;
    }
};


// ==========================================
// MULTILEVEL INHERITANCE
//
// Person
//    |
// Patient
//    |
// InPatient
// ==========================================

class InPatient : public Patient
{
protected:
    int roomNo;
    int days;

public:
    void getInPatientData()
    {
        getPatientData();

        cout << "Enter Room Number: ";
        cin >> roomNo;

        cout << "Enter Number of Days: ";
        cin >> days;
    }

    void showInPatientData()
    {
        showPatientData();

        cout << "Room Number : " << roomNo << endl;
        cout << "Days        : " << days << endl;
    }
};


// ==========================================
// CLASS FOR MULTIPLE INHERITANCE
// ==========================================

class Medical
{
protected:
    string medicine;

public:
    void getMedicalData()
    {
        cout << "Enter Medicine: ";
        cin >> medicine;
    }

    void showMedicalData()
    {
        cout << "Medicine : " << medicine << endl;
    }
};


// ==========================================
// CLASS FOR MULTIPLE INHERITANCE
// ==========================================

class Billing
{
protected:
    float doctorFee;
    float roomFee;

public:
    void getBillingData()
    {
        cout << "Enter Doctor Fee: ";
        cin >> doctorFee;

        cout << "Enter Room Fee: ";
        cin >> roomFee;
    }

    void showBill()
    {
        float total = doctorFee + roomFee;

        cout << "Doctor Fee : Rs. " << doctorFee << endl;
        cout << "Room Fee   : Rs. " << roomFee << endl;
        cout << "Total Bill : Rs. " << total << endl;
    }
};


// ==========================================
// MULTIPLE + HYBRID INHERITANCE
//
// InPatient + Medical + Billing
//             |
//       PatientRecord
// ==========================================

class PatientRecord : public InPatient,
                       public Medical,
                       public Billing
{
public:

    void getRecord()
    {
        cout << "\n========== PATIENT DETAILS ==========\n";

        getInPatientData();

        getMedicalData();

        getBillingData();
    }

    void showRecord()
    {
        cout << "\n========== PATIENT RECORD ==========\n";

        showInPatientData();

        showMedicalData();

        cout << "\n========== BILL ==========\n";

        showBill();
    }
};


// ==========================================
// MAIN FUNCTION
// ==========================================

int main()
{
    PatientRecord patient;
    Doctor doctor;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "=================================\n";
        cout << "    HOSPITAL MANAGEMENT SYSTEM\n";
        cout << "=================================\n";

        cout << "1. Add Patient\n";
        cout << "2. Show Patient\n";
        cout << "3. Add Doctor\n";
        cout << "4. Show Doctor\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                patient.getRecord();
                cout << "\nPatient Added Successfully!\n";
                break;

            case 2:
                patient.showRecord();
                break;

            case 3:
                cout << "\n========== DOCTOR DETAILS ==========\n";
                doctor.getDoctorData();
                cout << "\nDoctor Added Successfully!\n";
                break;

            case 4:
                cout << "\n========== DOCTOR DETAILS ==========\n";
                doctor.showDoctorData();
                break;

            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}