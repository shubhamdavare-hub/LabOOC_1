#include <iostream>
using namespace std;

class LibraryBook {
private:
    string Book_Title;
    string Author_Name;
    int Book_Number;
    bool Is_Issued;

public:
    LibraryBook(string title, string author, int number) {
        Book_Title=title;
        Author_Name=author;
        Book_Number=number;
        Is_Issued=false;
    }

    void issueBook() {
        if (!Is_Issued) {
            Is_Issued=true;
            cout<<"Book Issued: "<<Book_Title<<endl;
        } else {
            cout<<"Book is already issued!"<<endl;
        }
    }

    void returnBook() {
        if (Is_Issued) {
            Is_Issued=false;
            cout<<"Book Returned: "<<Book_Title<<endl;
        } else {
            cout<<"Book is already available!"<<endl;
        }
    }

    void display() {
        cout<<"\n[Library Book]"<<endl;
        cout<<"Book Title: "<<Book_Title<<endl;
        cout<<"Author: "<<Author_Name<<endl;
        cout<<"Book Number: "<<Book_Number<<endl;

        if (Is_Issued) {
            cout<<"Status: Issued"<<endl;
        } else {
            cout<<"Status: Available"<<endl;
        }
    }
};

class Patient {
private:
        int Patient_ID;
        string Patient_Name;
        int Age;
        int Consultation_Count;
        double Consultation_Fee;
public:
        Patient(int id, string name, int age, double fee, int consultations=1) {
                Patient_ID=id;
                Patient_Name=name;
                Age=age;
                Consultation_Fee=fee;
                Consultation_Count=consultations;
        }
        double calculateConsultationCharges() const {
                return Consultation_Fee * Consultation_Count;
        }
        void display() const {
                cout<<"\n[Patient Information]"<<endl;
                cout<<"Patient ID: "<<Patient_ID<<endl;
                cout<<"Patient Name: "<<Patient_Name<<endl;
                cout<<"Age: "<<Age<<endl;
                cout<<"Consultations: "<<Consultation_Count<<endl;
                cout<<"Consultation Fee: Rs. "<<Consultation_Fee<<endl;
                cout<<"Total Consultation Charges: Rs. "<<calculateConsultationCharges()<<endl;
        }
};

class Mobile_Recharge {
        private:
                string Username;
                int Mobile_Number;
                int Recharge_Amount;
                int Balance;
        public:
                Mobile_Recharge(string name,int number,int amount,int balance) {
                        Username=name;
                        Mobile_Number=number;
                        Recharge_Amount=amount;
                        Balance=balance;
                }
                int balance() {
                        Balance+=Recharge_Amount;
                        cout<<"Balance after the recharge: "<<Balance<<endl;
                        return Balance;
                }
                void display() {
                        cout<<"\n[Account Details]"<<endl;
                        cout<<"Username: "<<Username<<endl;
                        cout<<"Mobile Number: "<<Mobile_Number<<endl;
                        cout<<"Recharge Amount: "<<Recharge_Amount<<endl;
                        cout<<"Balance: "<<Balance<<endl;
                }
};

int main() {

    //Library 
    LibraryBook book("The Alchemist", "Paulo Coelho", 101);
    book.display();
    book.issueBook();
    book.display();
    book.returnBook();
    book.display();

    //Patient
    Patient patient1(101,"Sujal",20,500.0,2);
        Patient patient2(102,"Anita",35,750.0,7);
        patient1.display();
        patient2.display();

    //Mobile Recharge
    Mobile_Recharge mr("John Doe",1234567890,100,500);
        mr.display();
        mr.balance();
    return 0;
}