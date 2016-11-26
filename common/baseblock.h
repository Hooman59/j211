#ifndef BASEBLOCK_H
#define BASEBLOCK_H
#include <common/param.h>
#include <coapINC/resource.h>


class BaseBlock
{
public:
    BaseBlock(char *Name=NULL ,BlockType Btype=B_Unknown, unsigned short Bnum=0 ,unsigned short NumOfParams=0){memset(name,0,30);strcpy(name,Name); numOfparams = NumOfParams; blockType = Btype; blockNum = Bnum; params = new param*[numOfparams]; }
    param **params;
    unsigned short numOfparams;
    char name[30];

    bool first;
    BlockType blockType;
    unsigned char blockNum;

    coap_resource_t *r_Input , *r_Output, *r_Local;
    bool writeDirty;

    bool QmakeJsonString(char *buf, int *len, int bufSize, varKind queryType);
    char * QparsJsonStringSecurity(char* jsonReceivedData, varKind recivedDataType);

    bool checkDataChange();
    void setDirtyFlag(param *prm);
    void SnapInFromCoap();
    void cpyMainToTemp(){memcpy((void*)pTmpRegisters,(void*)pRegisters, sizeOfBlockStruct);}
    void cpyTempToMain(){memcpy((void*)pRegisters,(void*)pTmpRegisters, sizeOfBlockStruct);}

    void run();
    virtual void controlAlgorithm()=0;

    void clearWriteFlag();
    void *pRegisters      = NULL;
    void *pTmpRegisters   = NULL;
    void *pWriteRegisters = NULL;

    int sizeOfBlockStruct = 0;

};

#endif // BASEBLOCK_H
