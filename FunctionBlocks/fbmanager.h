#ifndef FBMANAGER_H
#define FBMANAGER_H
#include <common/enums.h>
#include <common/coapresource.h>
#include <common/baseblock.h>





class FBManager
{
public:
    //FBManager(unsigned char* Interface);
    static BaseBlock    **Blocks;
    static unsigned short  blkIndex;
    static unsigned short  rsIndex;


    void initialize(unsigned char* interface);
    template <class BlockTYPE,class TbTYPE>
            void  CreateBlock(BlockTYPE **(&C_Block), TbTYPE **(&C_TBreg), TbTYPE **(&C_TBtmpReg), TbTYPE **(&C_TBwriteReg),unsigned char _numOfBlocks,int numberOfParams, char* blkNAME, BlockType BLKtype);
    void initial_resources(BlockType blktype, unsigned char blkNum, unsigned char objNum);
    void createBlock_RSrecord(char *blkName, char *objNumStr, unsigned char blkNum);
    void makeRSrecord(unsigned char index,const char* interface,const char* rtype,const char *title,const char *suburi, varKind subTitle,const char* objNum,coap_method_handler_t getHdlr,coap_method_handler_t putHdlr,unsigned char blkNum);

    static unsigned char Interface[lenOfInterface];
    static CoapResourceRecord RSrecord[200];

    FPTR_hnd hnd_get;
    FPTR_hnd hnd_put;



};


#endif // FBMANAGER_H
