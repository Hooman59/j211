#ifndef FB_ADD_H
#define FB_ADD_H




#include <common/param.h>
#include <common/baseblock.h>
#include <FunctionBlocks/fbmanager.h>

#define FB_ADD_BlockNumOfparam 3


struct __attribute__((packed)) FB_ADD_Struct
{
    unsigned short in1;
    unsigned short in2;
    unsigned short out;

};

class FB_Add : public BaseBlock
{

public:
     FB_Add(FB_ADD_Struct *registers,FB_ADD_Struct *tmpRegisters,FB_ADD_Struct *writeRegisters,char *Name,BlockType Btype, unsigned short Bnum,unsigned short NumOfParams);
    ~FB_Add();
     FB_ADD_Struct *pRegisters      = NULL;
     FB_ADD_Struct *pTmpRegisters   = NULL;
     FB_ADD_Struct *pWriteRegisters = NULL;

    //****************Input params*******************
     ushortParam pmi_in1;
     ushortParam pmi_in2;

    //**********Output params
     ushortParam   pmo_out;
    //*********Local params

    void run();
    void initialize();

};

#endif // FB_ADD_H