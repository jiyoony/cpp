#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>
using namespace std;
class myComplex{
public:
  //생성자
  myComplex(int real=0,int imag=0);
  //복사생성자
  myComplex(const myComplex& number);

  //접근자
  int getRealPart() const;
  int getImaginaryPart() const;

  //변경자
  void setRealPart(int real);
  void setImaginaryPart(int imag);
  void set(int real,int imag);

  //overload binary operator
  myComplex operator +(const myComplex& number) const;
  myComplex operator +(int value) const;
  myComplex operator -(const myComplex& number) const;
  myComplex operator -(int value) const;
  myComplex operator *(const myComplex& number) const;
  myComplex operator *(int value) const;

  //overload assignment operator
  myComplex& operator =(const myComplex& number);
  myComplex& operator =(int value);
  myComplex& operator +=(const myComplex& number);
  myComplex& operator +=(int value);
  myComplex& operator -=(const myComplex& number);
  myComplex& operator -=(int value);
  myComplex& operator *=(const myComplex& number);
  myComplex& operator *=(int value);

  friend myComplex operator *(int value, const myComplex & complex);
  friend myComplex operator +(int value, const myComplex & complex);
  friend myComplex operator -(int value, const myComplex & complex);

  //overload relational operator
  bool operator ==(const myComplex& number) const;
  bool operator !=(const myComplex& number) const;
  bool operator >(const myComplex& number) const;
  bool operator >=(const myComplex& number) const;
  bool operator <(const myComplex& number) const;
  bool operator <=(const myComplex& number) const;

  //overload unary operator
  myComplex operator -();
  myComplex operator ~();
  //왜 이것만 &?
  myComplex& operator ++();
  myComplex& operator --();
  myComplex operator ++(int);
  myComplex operator --(int);

  friend ostream &operator <<(ostream &outStream, const myComplex& number);
  //왜 istream만 const 안해줌?
  friend istream &operator >>(istream &inStream, myComplex& number);

private:
  int realPart;
  int imaginaryPart;
  int norm() const;

};
#endif
