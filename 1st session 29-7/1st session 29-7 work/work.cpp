#include<iostream>

using namespace std;

int main(){
    int english,maths,science,age;
    string firstname,lastname;
    float avg;

    cout << "enter your firstname :" ;
    cin >> firstname;

    cout << "enter your lastname :";
    cin >> lastname;

    cout << "enter your age :";
    cin >> age;

    cout << "your name is :" << firstname << " " << lastname << endl;
    cout << "your age :" << age << endl;

    cout << "enter your english mark :";
    cin >> english;

    cout << "enter your maths mark :";
    cin >> maths;

    cout << "enter your science mark :";
    cin >> science;

    avg = (english + maths+ science) / 3;
    
    cout << "your avg is :" << avg << endl;

    cout << "so," << endl << "your name is :" << firstname << lastname << endl << "your age :" << age << endl << "your avg is :" << avg ;

}
