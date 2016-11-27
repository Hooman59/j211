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

    FB_Add               **FB_AddBlock; //ToDo: Define Array of BlockType Instances for Each "Block Type"
    FB_ADD_Struct        **FB_Add_Registers;//ToDo: Define Array of BlockType Registers for Each "Block Type"
    FB_ADD_Struct        **SnapOutCache_FB_Add_Registers;//ToDo:Define Array of BlockType SnapOutRegisters for Each "Block Type" //OldName: tmp
    FB_ADD_Struct        **SnapInCache_FB_Add_Registers;//ToDo:Define Array of BlockType SnapInRegisters for Each "Block Type" //OldName: tmp//OldName: Write_FB..


    unsigned char        numberOfFB_ADD; //ToDo:Add  number of block type instances for Each BlockType

};



extern "C" FBwrapperInterface*  createFBwrapper()
{
    return new  FBwrapper();
}

#endif // FBWRAPPER_H
