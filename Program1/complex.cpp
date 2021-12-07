//Name: Jared Hazel
//Program 1
//Date: 10/17/2020
//Class: CSS501
//Purpose: The purpose of this program is to implement complex
//variables and allow them to be changed and compared

#include "complex.h"

//This method creates a complex variable
complex::complex(double a, double b){
  realNum=a;
  imaginaryNum=b;
}

//This method multiplies two complex's together.
//The real and imaginary numbers are put into variables 
//for easier readability.  Variables are then put into 
//complex p to return for the answer 
complex complex::operator*(const complex& s) const{
  double real=(realNum*s.realNum)+(-1*(imaginaryNum*s.imaginaryNum));
  double img = (realNum*s.imaginaryNum)+(imaginaryNum*s.realNum);
  complex p = complex(real, img);
  return p;
}

//This method divides two complex variables
//Broke down top real, top imaginary, and bottom for easier
//readability.  If bottom variable is 0, an error message appears
//and the original complex appears.  If the bottom is not zero
//then complex b is returned to print the answer
complex complex::operator/(const complex& s) const{
    complex b;
    double topReal;
    double topImaginary;
    double bottom;
    topReal=(realNum*s.realNum)+(imaginaryNum*s.imaginaryNum);
    topImaginary=(imaginaryNum*s.realNum)-(realNum*s.imaginaryNum);
    bottom=(s.realNum*s.realNum)+(s.imaginaryNum*s.imaginaryNum);
    if(bottom == 0){
      cout<<"Cannot divide by Zero!";
      return complex(realNum, imaginaryNum);
    }
    else{
      b.realNum=(topReal/bottom);
      b.imaginaryNum=(topImaginary/bottom);
      return b;
    }
}

//This method subtracts two complex numbers.  
//It is broken down between the real and imaginary numbers.
//Complex b is returned to print the answer
complex complex::operator-(const complex& s) const{
  complex b;
  b.realNum=(realNum+(-1*s.realNum));
  b.imaginaryNum=(imaginaryNum+(-1*s.imaginaryNum));
  return b;
}

//This method adds two complex numbers.  
//It is broken down between the real and imaginary numbers.
//Complex b is returned to print the answer
complex complex::operator+(const complex& a) const {
  complex b;
  b.realNum=(realNum+a.realNum);
  b.imaginaryNum=(imaginaryNum+a.imaginaryNum);
  return b;
}

//This method prints out the different complex variables
//First it sees if the real number is zero or not, if its not
//then it prints the number.  Plus sign is added if the 
//imaginary number is above 0 and the real number is not zero
//Then the imaginary number is printed.  If zero then 0 is 
//printed Tf it's 1 then i gets printed.  If it's -1 then -i
//is printed.  If it's anything else, then the number get printed
//with i
ostream& operator<<(ostream &output, const complex &a) {
  if(a.realNum != 0.0){
    output<<a.realNum;
  }
  if(a.imaginaryNum > 0 && a.realNum != 0){
    output<<"+";
  }
  if(a.imaginaryNum == 0){
    output<<"0";
  }
  else if(a.imaginaryNum == 1){
    output<<"i";
  }
  else if(a.imaginaryNum == -1){
    output<<"-i";
  }
  else {
    output<<a.imaginaryNum<<"i";
  }
   return output;
}

//This method takes in information from the user and use it to create a new 
//complex variable.  Used the following forum to help verify input is numbers:
//http://www.cplusplus.com/forum/beginner/186225/
//By using a while and bool variable, the method keeps asking inputs 
//until it meets the requirment of being a real number.  Once that us met
//the bool variable comes true and exits the while loop.  The inputs are
//checked in a for loop that checks each char to make sure it's a real number
istream& operator>>(istream &input, complex &a) {
 string test1;
 string test2;
 bool confirmNumber=false;
 while(confirmNumber==false){ 
  cout<<"Please enter real number (if not using, please enter 0): "<<endl;
  input>>test1;
  cout<<"Please enter imginary number, not including the i (if not using, please enter 0): "<<endl;
  input>>test2;
  cout<<"Testing!"<<endl;
  string checkInput = test1+test2;
  for(int i=0; i<checkInput.size(); i++){
    int charCheck = tolower(checkInput[i]);
    if(charCheck < 'a' || charCheck > 'z'){
      confirmNumber=true;
    }
    else{
      confirmNumber=false;
      cout<<"Non-numbers found"<<endl;
      i=i+10;
    }
  }
 }
 cout<<"You pass!"<<endl;
 a.realNum = stod(test1);
 a.imaginaryNum = stod(test2);
 return input;
}

//This method compares two complexs and sees if they are 
//the same or not
bool complex::operator==(const complex& e) const {
   return (realNum == e.realNum && imaginaryNum == e.imaginaryNum);
}

//This method compares two complexes and checks to see if they are 
//different
bool complex::operator!=(const complex& e) const{
  return (realNum!=e.realNum || imaginaryNum != e.imaginaryNum);
}

//This method returns the real number from complex
double complex::getReal(){
  return realNum;
}

//This method sets the real number in a complex
complex complex::setReal(double &a){
  return *this=complex(a, imaginaryNum);
}

//This method sets the imaginary number in a complex
complex complex::setImaginary(double &a){
  return *this=complex(realNum, a);
}
//This method returns the imaginary number from complex
//Method is a string so the i can be printed out
string complex::getImaginary(){
  string num = to_string(imaginaryNum);
  return num+"i";
}

//This method changes the imaginary number either from 
//negative to plus, or plus to negative
complex complex::conjugate(){
  complex b;
  b.imaginaryNum=-1*imaginaryNum;
  b.realNum = realNum;
  return b;
}

//This operation adds two complexes together and then the 
//answer is put into the left side complex.  For example, 
//c1+=c3 actually reads like c1=c1+c3.
complex& complex::operator+=(const complex& a){
    realNum=realNum+a.realNum;
    imaginaryNum=a.imaginaryNum+imaginaryNum;
    return *this;
}

//This operation subtracts two complexes together and then the 
//answer is put into the left side complex.  For example, 
//c1-=c3 actually reads like c1=c1-c3.
complex& complex::operator-=(const complex& a){
    realNum=(realNum+(-1*a.realNum));
    imaginaryNum=(imaginaryNum+(-1*a.imaginaryNum));
    return *this;
}

//This operation multiplies two complexes together and then the 
//answer is put into the left side complex.  For example, 
//c1*=c3 actually reads like c1=c1*c3.  Broke down the real
//and imaginary number for easier readability
complex& complex::operator*=(const complex& a){
    realNum=(realNum*a.realNum)-(imaginaryNum*a.imaginaryNum);
    imaginaryNum=(realNum*a.imaginaryNum)+(imaginaryNum*a.realNum);
    return *this;
}

//This operation divides two complexes together and then the 
//answer is put into the left side complex.  For example, 
//c1/=c3 actually reads like c1=c1/c3.  Broke down the real,
//imaginary, and bottom number for easier readability.
//Also checked to see if the bottom is zero.  If it is, an error messahe
//appears
complex& complex::operator/=(const complex& a){
    double topReal;
    double topImaginary;
    double bottom;
    topReal=(realNum*a.realNum)+(imaginaryNum*a.imaginaryNum);
    topImaginary=(imaginaryNum*a.realNum)-(realNum*a.imaginaryNum);
    bottom=(a.realNum*a.realNum)+(a.imaginaryNum*a.imaginaryNum);

    if(bottom == 0){
      cout<<"Cannot divide by zero"<<endl;
      return *this;
    }
    else{
      realNum=(topReal/bottom);
      imaginaryNum=(topImaginary/bottom);
      return *this;
    }
}