#ifndef FBWRAPPERINTERFACE_H
#define FBWRAPPERINTERFACE_H
#include <common/coapresource.h>




class FBwrapperInterface
{
public:
    virtual ~FBwrapperInterface(){}
    virtual void initialize()=0;
    virtual void run()=0;
    FPTR_hnd hnd_get;
    FPTR_hnd hnd_put;

};

#endif // FBWRAPPERINTERFACE_H
