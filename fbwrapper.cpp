#include "fbwrapper.h"
#include "qdebug.h"





void FBwrapper::initialize()
{

    //FBManager  FBManagerR1;
    FBManagerR1->hnd_get = hnd_get; //FIX
    FBManagerR1->hnd_put = hnd_put; //FIX
    FBManagerR1->initialize((unsigned char*)"HC"); //FIX

    numberOfFB_ADD = 5; //ToDo : Fill
    if(numberOfFB_ADD > 0) //ToDo : Fill
    {
	//ToDo : add create Block Code for each of Block Type with Number of Instances
         FBManagerR1->CreateBlock<FB_Add,FB_ADD_Struct> ( FB_AddBlock, FB_Add_Registers, tmp_FB_Add_Registers, write_FB_Add_Registers, numberOfFB_ADD,FB_ADD_BlockNumOfparam, (char*)"FB_SUB" , B_FB);
         for(int i=0; i<numberOfFB_ADD; i++) //ToDo : Initialize Each Block Instance
             FB_AddBlock[i]->initialize();
    }
    qDebug()<<"FBwrapper::initialize()";

}
void FBwrapper::run()
{

    numberOfFB_ADD = 5; //ToDo : Fill (duplicate)
    for(int i=0; i<numberOfFB_ADD; i++)//ToDo: Add run for Each BlockType
         FB_AddBlock[i]->run();
    //FB_AddBlock[i]->pmi_in1.value = FB_AddBlock[3]->pmo_out.value;  // link
    //qDebug()<<"FBwrapper::run()";

}
