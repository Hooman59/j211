#include "baseblock.h"
#include <qdebug.h>


bool BaseBlock::checkDataChange()
{

    int flag=0;
    float *a,*b;
    a = new float;
    b = new float;

    for(int i=0;i<numOfparams;i++)
    {

        switch(params[i]->type)
        {
            case T_short:
              if( *((short*)(params[i]->voidPtr)) != *((short*)(params[i]->voidTmpPtr)) )
              {
                  setDirtyFlag(params[i]);
                  flag++;
                  // return 1;
              }
            break;
            case T_ushort:
              if( *((unsigned short*)(params[i]->voidPtr)) != *((unsigned short*)(params[i]->voidTmpPtr)) )
              {
                  setDirtyFlag(params[i]);
                  flag++;
                  // return 1;
              }
            break;
            case T_uint:
               if( *((unsigned int*)(params[i]->voidPtr)) != *((unsigned int*)(params[i]->voidTmpPtr)) )
               {
                 setDirtyFlag(params[i]);
                 flag++;
                 //return 1;
               }
            break;
        case  T_float:
            memcpy(a,params[i]->voidPtr,4);
            memcpy(b,params[i]->voidTmpPtr,4);
           // qDebug()<<"params["<<i<<"]="<<((float*)(params[i]->voidPtr))  << ((float*)(params[i]->voidTmpPtr)) << *a;


//            qDebug()<<"T_float1";
             //if( *((float*)(params[i]->voidPtr)) != *((float*)(params[i]->voidTmpPtr)) )
            if( *a != *b )
            {
              qDebug()<<"T_float2";
              setDirtyFlag(params[i]);
              flag++;
             // return 1;
            }
            break;
        default:
            //return 0;
            break;
        }
    }

    delete a;
    delete b;

    if(flag>0)
        return 1;
    else
        return 0;
}



void BaseBlock::setDirtyFlag(param *prm)
{
    switch(prm->kind)
    {
    case Input:
        r_Input->dirty = 1;
        break;
    case Output:
        qDebug()<<"BaseBlock::setDirtyFlag(param *prm) Output";
        r_Output->dirty = 1;
        break;
    case Local:
        r_Local->dirty = 1;
        break;
    default:
        break;

    }

}
