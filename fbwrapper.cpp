#include "fbwrapper.h"
#include "qdebug.h"





void FBwrapper::initialize()
{

    //FBManager  FBManagerR1;
    FBManagerR1->hnd_get = hnd_get;
    FBManagerR1->hnd_put = hnd_put;
    FBManagerR1->initialize((unsigned char*)"HC");

    numberOfFB_ADD = 2;
    if(numberOfFB_ADD > 0)
    {
         FBManagerR1->CreateBlock<FB_Add,FB_ADD_Struct> ( FB_AddBlock, FB_Add_Registers, tmp_FB_Add_Registers, write_FB_Add_Registers, numberOfFB_ADD,FB_ADD_BlockNumOfparam, (char*)"FB_MUL" , B_FB);
         for(int i=0; i<numberOfFB_ADD; i++)
             FB_AddBlock[i]->initialize();
    }
    qDebug()<<"FBwrapper::initialize()";

}
void FBwrapper::run()
{
   /* numberOfFB_ADD = 0;
    for(int i=0; i<numberOfFB_ADD; i++)
         FB_AddBlock[i]->run();
    qDebug()<<"FBwrapper::run()";
    */
}
