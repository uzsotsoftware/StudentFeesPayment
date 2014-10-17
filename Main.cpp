
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
    //int count;
    string studentName;
    float termFees;
    float balance; 
    int installments[3];
public:
    //Students();
    //~Students();

    void setName(string thisName) {
        studentName = thisName;
    }

    void setFees(float thisFees) {
        termFees = thisFees;
    }

    float getFees() {
        return termFees;
    }

    string getName() {
        return studentName;
    }
    void makePayment(float payment, int count);
    void printPayments();

    float getBalance() {
        return balance;
    }
    friend float outstandingFees();

};

void Students::makePayment(float payment, int count) {
    installments[count] = payment;
    balance += payment;
    //count++;
}

void Students::printPayments() {
    for (int i = 0; i < 3; i++) {
        cout << "\tPayment " << i + 1 << " : " << installments[i] << endl;
    }
}

float outstandingFees(Students &student) {
    return student.getFees() - student.getBalance();
}

int main(int argc, char** argv) {

    Students studentObject;
    float totalFees, installment;
      
    cout << "\tEnter term fees      : ";
    cin >> totalFees;
    studentObject.setFees((float)totalFees);

    for (int i = 0; i < 3; i++) {
        cout << "\tEnter installment " << i + 1 << "  : ";
        cin >> installment;
        studentObject.makePayment((float)installment, i);

    }
    cout << "\n\tOutstanding fees are : " << outstandingFees(studentObject) << endl;
    cout << "\n\n\tTransaction History: \n\n";
    studentObject.printPayments();
    cout << "\n\n"; //just to make it neat


    return 0;
}

