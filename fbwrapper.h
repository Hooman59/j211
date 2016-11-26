#ifndef FBWRAPPER_H
#define FBWRAPPER_H
#include "fbwrapperinterface.h"
#include <FunctionBlocks/fbmanager.h>
#include <FunctionBlocks/fb_add.h>

class FBwrapper : public FBwrapperInterface
{
public:
   // FBwrapper();
    virtual void initialize();
    virtual void run();

    FB_Add               **FB_AddBlock;
    FB_ADD_Struct        **FB_Add_Registers;
    FB_ADD_Struct        **tmp_FB_Add_Registers;
    FB_ADD_Struct        **write_FB_Add_Registers;


    unsigned char        numberOfFB_ADD;

};



extern "C" FBwrapperInterface*  createFBwrapper()
{
    return new  FBwrapper();
}

#endif // FBWRAPPER_H
