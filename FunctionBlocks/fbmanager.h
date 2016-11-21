#ifndef FBMANAGER_H
#define FBMANAGER_H
#include <common/enums.h>
#include <common/baseblock.h>
#include <common/coapresource.h>

class FBManager
{
public:
  //  FBManager(unsigned char* Interface);
    static BaseBlock    **Blocks;
    static unsigned short  blkIndex;
    static unsigned short  rsIndex;
    static void initialize(unsigned char* interface);
    template <class BlockTYPE,class TbTYPE>
            static void  CreateBlock(BlockTYPE **(&C_Block), TbTYPE **(&C_TBreg), TbTYPE **(&C_TBtmpReg), TbTYPE **(&C_TBwriteReg),unsigned char _numOfBlocks,int numberOfParams, char* blkNAME, BlockType BLKtype);
    static void initial_resources(BlockType blktype, unsigned char blkNum, unsigned char objNum);
    static void createBlock_RSrecord(char *blkName, char *objNumStr, unsigned char blkNum);
    static void makeRSrecord(unsigned char index,const char* interface,const char* rtype,const char *title,const char *suburi, varKind subTitle,const char* objNum,coap_method_handler_t getHdlr,coap_method_handler_t putHdlr,unsigned char blkNum);

    static unsigned char Interface[lenOfInterface];
    static CoapResourceRecord RSrecord[200];

};



#endif // FBMANAGER_H
