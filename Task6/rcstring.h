#ifndef __RCSTRING_H__
#define __RCSTRING_H__
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

class rcstring
{
  struct rctext;
  rctext* data; 
  public:
    int atoi() const; 
    rcstring& toLower();
    rcstring Left(int n) const; 
    class Range{}; 
    class Cref; 
    rcstring();
    rcstring(const char*); 
    rcstring(const rcstring&); 
    ~rcstring();
    rcstring& operator=(const char*); 
    rcstring& operator=(const rcstring&);
    rcstring& operator+=(const rcstring &);
    rcstring operator+(const rcstring &) const; 
    friend ostream& operator<<(ostream&, const rcstring&); 
    void check (unsigned int i) const; 
    char read(unsigned int i) const; 
    void write(unsigned int i, char c); 
    char operator[](unsigned int i) const; 
    Cref operator[](unsigned int i);
};

struct rcstring::rctext{
  char* s; 
  unsigned int size;
  unsigned int n;

  rctext(unsigned int nsize, const char* p){ 
    n = 1; 
    size = nsize; 
    s = new char[size+1];
    strncpy(s,p,size);   
    s[size] = '\0';     
  };
  ~rctext() 
  {
    delete [] s;
  };
  rctext* detach() 
  {
    if(n==1)
      return this;
    rctext* t=new rctext(size, s);
    n--;
    return t;
  };
  void assign(unsigned int nsize, const char *p)
  {
    if(size!=nsize)
    {
      char* ns=new char[nsize+1];
      size = nsize;
      strncpy(ns,p,size);
      delete [] s;
      s = ns;
    }
    else
      strncpy(s,p,size);
    s[size]='\0';
  }
  private:
    rctext(const rctext&);             
    rctext& operator=(const rctext&); 
};

class rcstring::Cref  
{
  friend class rcstring;
  rcstring& s;
  int i;
  Cref (rcstring& ss, unsigned int ii): s(ss), i(ii) {};
  public:
    operator char() const
    {                                       
      cout << "operator char() const"<<endl;
      return s.read(i);                     
    }
    rcstring::Cref& operator = (char c)       
    {
      cout << "void operator = (char c)"<<endl;
      s.write(i,c);
      return *this;
    }
    rcstring::Cref& operator = (const Cref& ref) 
    {
      return operator= ((char)ref);
    }
};
inline rcstring::rcstring(){ 
  data = new rctext(0,"");
}
inline rcstring::rcstring(const rcstring& x){ 
  x.data->n++;
  data=x.data;
}
inline rcstring::~rcstring(){ 
  if(--data->n==0)            
    delete data;              
}
rcstring& rcstring::operator=(const rcstring & x){
  x.data->n++;                                    
  if(--data->n == 0)                              
    delete data;
  data=x.data;
  return *this;
}
rcstring::rcstring(const char* s){ 
  data=new rctext(strlen(s),s);
}
rcstring& rcstring::operator=(const char* s){ 
  if(data->n == 1)                           
    data->assign(strlen(s),s);                
  else
  {
    rctext* t = new rctext(strlen(s),s);
    data->n--;
    data= t;
  };
  return *this;
}
ostream& operator << (ostream& o, const rcstring& s){
  return o<<s.data->s;
}
rcstring& rcstring::operator+=(const rcstring & s){
  unsigned int newsize=data->size+s.data->size;
  rctext *newdata = new rctext(newsize,data->s);
  strcat(newdata->s,s.data->s);
  if(--data->n == 0)
    delete data;
  data = newdata;
  return *this;
}
int rcstring::atoi() const{ 
  return std::atoi(data->s);
}
rcstring& rcstring::toLower(){
  rctext *newdata = new rctext(data->size,data->s);
  for(int i = 0; i < data->size; newdata->s[i] = ((*this)[i] >= 'a' && (*this)[i] <= 'z') ? (*this)[i] : (*this)[i] - 'A' + 'a', ++i);
  if(--data->n == 0)
     delete data;
  data = newdata;
  return *this;
}
rcstring rcstring::Left(int n) const{
  if(n > (int)data->size || n < 0) throw Range();
  rcstring rcs;
  rcs.data->assign(n, data->s);
  return rcs;
} 
rcstring rcstring::operator+(const rcstring & s) const{
  return rcstring(*this)+=s;
}
inline void rcstring::check (unsigned int i) const{
  if(data->size<=i)
    throw Range();
}
inline char rcstring::read(unsigned int i) const{ 
  return data->s[i];
}
inline void rcstring::write(unsigned int i, char c){ 
  data = data->detach();
  data->s[i] = c;
}
char rcstring::operator[](unsigned int i) const{ 
  cout << "char rcstring::operator[](unsigned int i) const"<<endl;
  check(i);
  return data->s[i];
}
rcstring::Cref rcstring::operator[](unsigned int i){ 
  cout << "Cref rcstring::operator[](unsigned int i)"<<endl;
  check(i);
  return Cref(*this,i);
}
#endif /* __RCSTRING_H__ */