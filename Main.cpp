
/* 
 * File    : main.cpp
 * Author  : Samuel Gwokuda
 * Email   : gwokudasam@gmail.com
 * Created on October 15, 2014, 11:58 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Students {
    
    string studentName; //for storing the Student name, self explanatory!
    float termFees;     //do i need to explain this too?
    float balance;      ///
    int installments[3];
public:
    //Students();    //ctor
    //~Students();   //dtor 

    //StudentName Setter Method
    void setName(string thisName) {  
        studentName = thisName;
    }
    
    //Total TermFees setter Method
    void setFees(float thisFees) {
        termFees = thisFees;
    }


    //Total TermFees getter Method
    float getFees() {
        return termFees;
    }

    string getName() {
        return studentName;
    }
    void makePayment(float payment, int count); // the meat of the program, takes a payment and an index named count, implemented 
                                                // below the Class Declaration, line 56
    void printPayments();                       // Just prints out all the payments made

    float getBalance() {                        // returns the amount owed by the Student
        return balance;
    }
    
    friend float outstandingFees();             //

};

void Students::makePayment(float payment, int count) {
    installments[count] = payment;              //store the payment at the selected index, passed in as an arguments
    balance += payment;                         //increment the balance
    
}

//makes use of the installments [array] to print the value at each index

void Students::printPayments() {
    for (int i = 0; i < 3; i++) {
        cout << "\tPayment " << i + 1 << " : " << installments[i] << endl;
    }
}

//calculates the outstanding fees (arreas) by stubtracting the balance from the total Term Fees
float outstandingFees(Students &student) {
    return student.getFees() - student.getBalance();
}

int main(int argc, char** argv) {

    Students studentObject;                     //creates the object from the class Students
    float totalFees, installment;               //create local variables to store the input from user
      
    cout << "\tEnter term fees      : ";
    cin >> totalFees;                           //get the input    
    studentObject.setFees((float)totalFees);    //set the Total Term Fees , note the casting of the input to a (float)

    for (int i = 0; i < 3; i++) {
        cout << "\tEnter installment " << i + 1 << "  : ";  
        cin >> installment;
        studentObject.makePayment((float)installment, i);       //

    }
    cout << "\n\tOutstanding fees are : " << outstandingFees(studentObject) << endl; //pass the object created on line 77 to the frined function outstandingFees
    cout << "\n\n\tTransaction History: \n\n";
    studentObject.printPayments();              //print                                        
    cout << "\n\n"; //just to make it neat


    return 0;
}

