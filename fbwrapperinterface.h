#ifndef FBWRAPPERINTERFACE_H
#define FBWRAPPERINTERFACE_H

typedef void (*FPTR)(unsigned char* interface);

class FBwrapperInterface
{
public:
    virtual ~FBwrapperInterface(){}
    virtual void initialize()=0;
    virtual void run()=0;
    FPTR cb;
};

#endif // FBWRAPPERINTERFACE_H
