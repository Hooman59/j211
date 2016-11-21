#include "fbwrapper.h"
#include "qdebug.h"






void FBwrapper::initialize()
{

    cb((unsigned char*)"HC12\0");
    //FBManager::initialize((unsigned char*)"HC");

    numberOfFB_ADD = 0;
    if(numberOfFB_ADD > 0)
    {
      //   FBManager::CreateBlock<FB_Add,FB_ADD_Struct> ( FB_AddBlock, FB_Add_Registers, tmp_FB_Add_Registers, write_FB_Add_Registers, numberOfFB_ADD,FB_ADD_BlockNumOfparam, (char*)"FB_Add" , B_FB_ADD);

         for(int i=0; i<numberOfFB_ADD; i++)
             FB_AddBlock[i]->initialize();
    }
    qDebug()<<"FBwrapper::initialize()";

}
void FBwrapper::run()
{
    numberOfFB_ADD = 0;
    for(int i=0; i<numberOfFB_ADD; i++)
         FB_AddBlock[i]->run();
    qDebug()<<"FBwrapper::run()";

}
