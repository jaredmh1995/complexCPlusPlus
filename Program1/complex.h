//Name: Jared Hazel
//Program 1
//Date: 10/17/2020
//Class: CSS501
//Purpose: The purpose of this program is to implement complex
//variables and allow them to be changed and compared

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class complex{
  //Allows for input from user and outputs the complex class
  friend ostream& operator<<(ostream&, const complex&);
  friend istream& operator>>(istream&, complex&);

public:
  //Establishment of complex, methods, setters and getters
  //A lot of them are public because I was having issues
  //when they were in private
  complex(double =0.0, double = 0.0);
  double getReal();
  string getImaginary();
  complex setReal(double &a);
  complex setImaginary(double &a);
  //I assume this method just shows the conjugate 
  //but doesn't actually change the complex
  complex conjugate();
  
  //Math operators 
  complex operator+(const complex &) const;
  complex operator-(const complex &) const; 
  complex operator*(const complex &) const;   
  complex operator/(const complex &) const; 

  //Comparisons
  bool operator==(const complex &) const;     
  bool operator!=(const complex &) const; 

     // assignment operators
  complex& operator+=(const complex &);
  complex& operator-=(const complex &);
  complex& operator*=(const complex &);
  complex& operator/=(const complex &);

//Intializes the two parts to complex                             
private:
  double realNum;
  double imaginaryNum;
};
#endif