#include "fb_add.h"
#include <QDebug>

FB_Add::FB_Add(FB_ADD_Struct *registers,FB_ADD_Struct *tmpRegisters,FB_ADD_Struct *writeRegisters,char *Name,BlockType Btype, unsigned short Bnum,unsigned short NumOfParams):BaseBlock(Name,Btype,Bnum,NumOfParams)
,pmi_in1(T_ushort,Input,(char*)"in1",0, &(registers->in1),(void*)&(tmpRegisters->in1),(void*)&(writeRegisters->in1))
,pmi_in2(T_ushort,Input,(char*)"in2",0, &(registers->in2),(void*)&(tmpRegisters->in2),(void*)&(writeRegisters->in2))
,pmo_out(T_ushort,Output,(char*)"out",0, &(registers->out),(void*)&(tmpRegisters->out),(void*)&(writeRegisters->out))
,pmc_th(T_ushort,Local,(char*)"th",0, &(registers->th),(void*)&(tmpRegisters->th),(void*)&(writeRegisters->th))
{
    pRegisters       = registers;
    pTmpRegisters    = tmpRegisters;
    pWriteRegisters  = writeRegisters;

    int paramIndx=0;

    params[paramIndx++] = & pmi_in1;
    params[paramIndx++] = & pmi_in2;
    params[paramIndx++] = & pmo_out;
    params[paramIndx]  = & pmc_th;

   clearWriteFlag();



}

FB_Add::~FB_Add()
{

    clearWriteFlag();
    pRegisters       = NULL;
    pTmpRegisters    = NULL;
    pWriteRegisters  = NULL;
    delete[] params;

}


void FB_Add::initialize()
{

}



void FB_Add::controlAlgorithm()
{
    *(pmo_out.tmpValue) = *(pmi_in1.tmpValue) +  *(pmi_in2.tmpValue) ;
}



