#include<iostream>

using namespace std;

int main (){
    
    int m1, m2, m3, m4, m5, avg;

    cout << "enter m1 :";
    cin >> m1;

    cout << "enter m2 :";
    cin >> m2;

    cout << "enter m3 :";
    cin >> m3;

    cout << "enter m4 :";
    cin >> m4;

    cout << "enter m5 :";
    cin >> m5;

    avg = (m1+m2+m3+m4+m5) / 5;

    cout << " your avg is :" << avg << endl;

    if (avg >=95) {
        cout << "your grade is A" << endl ;
    }
    else if (avg >=80 && avg <=95) {
        cout << "your grade is B" << endl ;
    }
    else if (avg >=65 && avg <=80) {
        cout << "your grade is C" << endl ;
    }
    else if (avg >=35 && avg <=65) {
        cout << "your grade is D" << endl ;
    }
    else{
        cout << "failed" << endl ;
    }
    return 0;
}