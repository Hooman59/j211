#ifndef PARAM_H
#define PARAM_H
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <common/enums.h>

/*
template <class T>
class param
{
public:
    param(varType Type,char *Name,T Value , T* paramPtr){type = Type;memset(name,0,30);strcpy(name,Name);value=Value;ptr=paramPtr;}
 //  ~param();

    T value;
    T *ptr;
    char name[30];
    varType type;
    void setvalue(){ value = *((T*)(ptr));}

};
*/

#define MY_CLASSES MYTYPE(int) MYTYPE(float) MYTYPE(double) MYTYPE(unsigned short)  MYTYPE(unsigned int) MYTYPE(short)

class param
{
public:
    param(varType Type = T_ushort,varKind Kind = CMD ,char *Name=NULL,void* TMPptr=NULL, void* WritePtr=NULL ){type = Type; kind = Kind ;memset(name,0,30);strcpy(name,Name); voidTmpPtr=TMPptr; writePtr=WritePtr;}
    virtual ~param(){memset(name,0,30); voidTmpPtr=NULL; writePtr=NULL;}
    char name[30];
    varType type;
    varKind kind;
    bool writeDirty;
    void *writePtr;
    void *voidTmpPtr;
    void *voidPtr;
    unsigned short mbAddress;
    unsigned char len;
    # define MYTYPE(T) virtual void Read(T *rValue)=0;\
                       virtual void Write(T wValue)=0;
      MY_CLASSES
    #undef MYTYPE
      virtual void CpyMain()=0;

      virtual void textRead(char* text)=0;
      virtual void textWrite(char* text)=0;




};


class ushortParam : public param
{
public:
    ushortParam(varType Type, varKind Kind,char *Name ,unsigned short Value,unsigned short *paramptr,void* TMPptr,void* WritePtr):param(Type,Kind,Name,TMPptr,WritePtr){ptr=paramptr;value=paramptr ;*value=Value;*ptr=Value;voidPtr =(void*)paramptr;*((unsigned short*)voidPtr) = Value; tmpValue = (unsigned short*)TMPptr;*((unsigned short*)TMPptr) = Value; *((unsigned short*)WritePtr) = Value; }
    ~ushortParam(){ptr=NULL;value=NULL;tmpValue=NULL;voidPtr =NULL;}
    # define MYTYPE(T)  virtual void Read(T *rValue) {/* *rValue = value;*/*rValue = *ptr; } \
                        virtual void Write(T wValue){*((unsigned short*)writePtr) = wValue; }\

        MY_CLASSES
    #undef MYTYPE
         virtual void CpyMain(){*ptr = *((unsigned short*)writePtr); }
     void textRead(char*){}
     void textWrite(char*){}

private:
     unsigned short *ptr;
     unsigned short *value;
     unsigned short *tmpValue;


};


class shortParam : public param
{
public:
    shortParam(varType Type, varKind Kind,char *Name ,short Value,short *paramptr,void* TMPptr,void* WritePtr):param(Type,Kind,Name,TMPptr,WritePtr){ptr=paramptr;value=Value;*ptr=value; voidPtr =(void*)paramptr; *((short*)voidPtr) = value;*((short*)TMPptr) = value; *((short*)WritePtr) = value;}
    ~shortParam(){ptr=NULL;value=0;voidPtr =NULL;}
    # define MYTYPE(T)  virtual void Read(T *rValue) {/* *rValue = value; */ *rValue = *ptr;} \
                        virtual void Write(T wValue){*((short*)writePtr) = wValue; }\

     MY_CLASSES
    #undef MYTYPE
     virtual void CpyMain(){*ptr = *((short*)writePtr); }
     void textRead(char*){}
     void textWrite(char*){}

private:
    short *ptr;
    short value;



};

class uintParam : public param
{
public:
    uintParam(varType Type, varKind Kind,char *Name ,unsigned int Value,unsigned int *paramptr,void* TMPptr,void* WritePtr):param(Type,Kind,Name,TMPptr,WritePtr){ptr=paramptr;value=Value;*ptr=value; voidPtr =(void*)paramptr; *((unsigned int*)voidPtr) = value;*((unsigned int*)TMPptr) = value; *((unsigned int*)WritePtr) = value;}
    ~uintParam(){ptr=NULL;value=0;voidPtr =NULL;}
    # define MYTYPE(T)  virtual void Read(T *rValue) { *rValue = *ptr;} \
                    virtual void Write(T wValue){*((unsigned int*)writePtr) = wValue; }\

     MY_CLASSES
    #undef MYTYPE

     virtual void CpyMain(){*ptr = *((unsigned int*)writePtr); }
     void textRead(char* ){}
     void textWrite(char* ){}

private:
    unsigned int *ptr;
    unsigned int value;

};


class floatParam : public param
{
public:
    floatParam(varType Type, varKind Kind,char *Name ,float Value,float *paramptr,void* TMPptr ,void* WritePtr):param(Type,Kind,Name,TMPptr,WritePtr){ptr=paramptr;value=Value;*ptr=value; voidPtr =(void*)paramptr; *((float*)voidPtr) = value;*((float*)TMPptr) = value; *((float*)WritePtr) = value; }
    ~floatParam(){ptr=NULL;value=0;voidPtr =NULL;}

    # define MYTYPE(T)  virtual void Read(T *rValue) {*rValue = *ptr; /*value;*/} \
                        virtual void Write(T wValue){*((float*)writePtr) = wValue;}\

     MY_CLASSES
    #undef MYTYPE

     virtual void CpyMain(){*ptr = *((float*)writePtr); }
     void textRead(char* ){}
     void textWrite(char* ){}

//private:
    float *ptr;
    float value;

};


class stringParam : public param
{
public:
    stringParam(varType Type, varKind Kind,char *Name ,char* Value,char *paramptr,void* TMPptr ,void* WritePtr):param(Type,Kind,Name,TMPptr,WritePtr){ptr=paramptr;memset(value,0,30);strcpy(value,Value);memcpy((void*)ptr,(void*)value,30); voidPtr = (void*)paramptr; memset(TMPptr,0,30);memcpy(TMPptr,value,30);memset(WritePtr,0,30);memcpy(WritePtr,value,30);}
    ~stringParam(){ptr=NULL;memset(value,0,30);voidPtr =NULL;}
    # define MYTYPE(T)  virtual void Read(T *) {} \
                     virtual void Write(T ){}

     MY_CLASSES
    #undef MYTYPE
     virtual void CpyMain(){}
     void textRead(char* text){memset(text,0,30);strcpy(text,ptr);/*strcpy(text,value);*/}
     void textWrite(char* text){memset(writePtr,0,30);strcpy((char*)writePtr,text);}

private:
    char *ptr;
    char value[30];



};





#endif // PARAM_H


