#include "fbmanager.h"
#include "fb_add.h"
#include <qdebug.h>


template void FBManager::CreateBlock <FB_Add,FB_ADD_Struct> (FB_Add **(&C_Block), FB_ADD_Struct **(&C_TBreg), FB_ADD_Struct **(&C_TBtmpReg), FB_ADD_Struct **(&C_TBwriteReg),unsigned char _numOfBlocks,int numberOfParams, char* blkNAME, BlockType BLKtype);

/*unsigned short     FBManager::blkIndex;
unsigned short     FBManager::rsIndex;
unsigned char      FBManager::Interface[lenOfInterface];
CoapResourceRecord FBManager::RSrecord[200];
*/


void  FBManager::initialize(unsigned char* interface)
{

    blkIndex = 0;
    rsIndex  = 0;
    Blocks = new BaseBlock*[1];
    //QString st((const char *)interface);
    memset(Interface,0,lenOfInterface);
    memcpy(Interface,interface,lenOfInterface);

    numOfResource = 0;
    numOfBlocks = 0;


   // qDebug()<<"interface="<<st;

}



template <class BlockTYPE,class TbTYPE>
        void  FBManager::CreateBlock(BlockTYPE **(&C_Block), TbTYPE **(&C_TBreg), TbTYPE **(&C_TBtmpReg), TbTYPE **(&C_TBwriteReg),unsigned char _numOfBlocks,int numberOfParams, char* blkNAME, BlockType BLKtype)
{
            C_TBreg      = new TbTYPE*[_numOfBlocks];
            C_TBtmpReg   = new TbTYPE*[_numOfBlocks];
            C_TBwriteReg = new TbTYPE*[_numOfBlocks];
          //  qDebug()<<"sizeof(TbTYPE)=" <<sizeof(TbTYPE) << "sizeof(BlockTYPE)=" <<sizeof(BlockTYPE);

            for(int i=0;i<_numOfBlocks;i++)
            {
                C_TBreg[i]      = new TbTYPE;
                C_TBtmpReg[i]   = new TbTYPE;
                C_TBwriteReg[i] = new TbTYPE;
            }

            C_Block = new BlockTYPE*[_numOfBlocks];
            for(int i=0;i<_numOfBlocks;i++)
            {
                C_Block[i] = new BlockTYPE(C_TBreg[i],C_TBtmpReg[i],C_TBwriteReg[i] ,(char*)blkNAME,BLKtype,i,numberOfParams);
                Blocks[blkIndex] = (BaseBlock*)C_Block[i];
                memset(Blocks[blkIndex]->name,0,30);
                strcpy(Blocks[blkIndex]->name,blkNAME);
                Blocks[blkIndex]->blockNum = i;
                Blocks[blkIndex]->writeDirty = 0;
                Blocks[blkIndex]->sizeOfBlockStruct = sizeof(TbTYPE);
                initial_resources(BLKtype,blkIndex,(char*)blkNAME,i);
                blkIndex++;

            }

           // qDebug()<<"_numOfBlocks"<<_numOfBlocks;
            numOfResource = (_numOfBlocks * 3) + numOfResource;
            numOfBlocks   = _numOfBlocks + numOfBlocks;


}





void  FBManager::initial_resources(BlockType blktype, unsigned char blkNum, char* blkName ,unsigned char objNum)
{

     char objNumStr[5];
     memset(objNumStr,0,5);
     sprintf(objNumStr,"%d",objNum);
     createBlock_RSrecord(blkName, objNumStr,blkNum);



}


 void FBManager::createBlock_RSrecord(char *blkName, char *objNumStr, unsigned char blkNum)
 {
     makeRSrecord(rsIndex,(char*)Interface,"FB",blkName,"Input",Input,objNumStr,hnd_get,hnd_put,blkNum);
     rsIndex++;

     makeRSrecord(rsIndex,(char*)Interface,"FB",blkName,"Output",Output,objNumStr,hnd_get,hnd_put,blkNum);
      rsIndex++;

     makeRSrecord(rsIndex,(char*)Interface,"FB",blkName,"Local",Local,objNumStr,hnd_get,hnd_put,blkNum);
       rsIndex++;
 }

 void FBManager::makeRSrecord(unsigned char index,const char* interface,const char* rtype,const char *title,const char *suburi, varKind subTitle,const char* objNum,coap_method_handler_t getHdlr,coap_method_handler_t putHdlr,unsigned char blkNum)
 {

     memset(RSrecord[index].uri,0,lenOfUri);
     sprintf((char*)(RSrecord[index].uri),"%s/%s/%s/%s/%s",interface,rtype,title,objNum,suburi);

     memset(RSrecord[index].interface,0,lenOfInterface);
     sprintf((char*)(RSrecord[index].interface),"\"%s\"",interface);

     memset(RSrecord[index].rtype,0,lenOfrtype);
     sprintf((char*)(RSrecord[index].rtype),"\"%s\"",rtype);

     memset(RSrecord[index].title,0,lenOftitle);
     sprintf((char*)(RSrecord[index].title),"\"%s\"",title);

     memset(RSrecord[index].objNum,0,lenOfObjNUm);
     sprintf((char*)(RSrecord[index].objNum),"\"%s\"",objNum);
    // qDebug()<<(char*) (RSrecord[index].objNum) <<endl;

     memset(RSrecord[index].subUri,0,lenOfsubUri);
     sprintf((char*)(RSrecord[index].subUri),"\"%s\"",suburi);
     RSrecord[index].subtitle = subTitle;

     RSrecord[index].blockNum = blkNum;
     RSrecord[index].getHandler = getHdlr;
     RSrecord[index].putHandler = putHdlr;

 }





