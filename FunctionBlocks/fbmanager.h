#ifndef FBMANAGER_H
#define FBMANAGER_H
#include <common/enums.h>
#include <common/coapresource.h>
#include <common/baseblock.h>
#include "fb_add.h"




class FBManager
{
public:
    //FBManager(unsigned char* Interface);

    BaseBlock    **Blocks;
    unsigned short  blkIndex;
    unsigned short  rsIndex;


    void initialize(unsigned char* interface);
    template <class BlockTYPE,class TbTYPE>
            void  CreateBlock(BlockTYPE **(&C_Block), TbTYPE **(&C_TBreg), TbTYPE **(&C_TBtmpReg), TbTYPE **(&C_TBwriteReg),unsigned char _numOfBlocks,int numberOfParams, char* blkNAME, BlockType BLKtype);
    void initial_resources(BlockType blktype, unsigned char blkNum, unsigned char objNum);
    void createBlock_RSrecord(char *blkName, char *objNumStr, unsigned char blkNum);
    void makeRSrecord(unsigned char index,const char* interface,const char* rtype,const char *title,const char *suburi, varKind subTitle,const char* objNum,coap_method_handler_t getHdlr,coap_method_handler_t putHdlr,unsigned char blkNum);

    unsigned char Interface[lenOfInterface];
    CoapResourceRecord RSrecord[200];

    FPTR_hnd hnd_get;
    FPTR_hnd hnd_put;

    unsigned short numOfResource;



};


#endif // FBMANAGER_H
