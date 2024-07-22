#include <iostream>
using namespace std;
 
 int main ()

 { int num1, num2;  // any two number on which we will apply operation
 
char x;    //that character who is responsibe for operation

 while (true)       // for continuity
 
 {
 
 cout<< "\nENTER FISRST NUMBER = ";
 
 cin>> num1;

 cout<< "ENTER SECOND NUMBER = ";
 
 cin>> num2;
 
 //all mathematical operation that will operate on using single key
 
 cout << "\npress a for addition ( + )" <<endl;
 cout << "press b for subtraction ( - )" <<endl;
 cout << "press c for multiplication ( * )" <<endl;
 cout << "press d for division ( / )" <<endl;
 cout << "press e for remainder ( % )\n " <<endl;
 
 cin>>x;
  
if(x=='a')
cout<<"\nthe SUM = "<<num1+ num2<<endl;


else if(x=='b')
cout<<"\nthe SUBTRACTION = "<<num1 - num2<<endl;


else if(x=='c')
cout<<"\nthe MULTIPLICATION = "<<num1 * num2<<endl;


else if(x=='d')
cout<<"\nthe DIVISION = "<<num1/ num2<<endl;


else if(x=='e')
cout<<"the REMINDER = "<<num1 % num2<<endl; 


else cout<<"invalid operation"<<endl; }

return 0;
 
 }
