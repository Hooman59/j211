#ifndef FB_ADD_H
#define FB_ADD_H




#include <common/param.h>
#include <common/baseblock.h>
#include <FunctionBlocks/fbmanager.h>

#define FB_ADD_BlockNumOfparam 4 // Todo: Fill Number of BlockType Parameters


struct __attribute__((packed)) FB_ADD_Struct
{
    unsigned short in1;
    unsigned short in2;
    unsigned short out;
    unsigned short th;

};

class FB_Add : public BaseBlock
{

public:
//Select proper BlockClass & Structs (Structs defined in block header)

     FB_Add(FB_ADD_Struct *registers,FB_ADD_Struct *tmpRegisters,FB_ADD_Struct *writeRegisters,char *Name,BlockType Btype, unsigned short Bnum,unsigned short NumOfParams);
    ~FB_Add();

    //****************Input params*******************
     ushortParam pmi_in1;
     ushortParam pmi_in2;

    //**********Output params
     ushortParam   pmo_out;
    //*********Local params
     ushortParam   pmc_th;

   // void run();
    void initialize();
    void controlAlgorithm();

   // void SnapInFromCoap();

    void SnapOutToMainReg();

};

#endif // FB_ADD_H
