#ifndef COAPRESOURCE_H
#define COAPRESOURCE_H
#include "coapINC/resource.h"
#include "common/enums.h"
#define lenOfInterface 20
#define lenOfrtype     20
#define lenOftitle     20
#define lenOfObjNUm     5
#define lenOfsubUri    40
#define lenOfUri       200

typedef struct coapResourceRecord
{
    unsigned char blockNum;
    unsigned char uri[lenOfUri];
    unsigned char interface[lenOfInterface];
    unsigned char rtype[lenOfrtype];
    unsigned char title[lenOftitle];
    unsigned char objNum[lenOfObjNUm];
    unsigned char subUri[lenOfsubUri];
    varKind  subtitle;
    coap_method_handler_t getHandler;
    coap_method_handler_t putHandler;
}CoapResourceRecord;
#endif // COAPRESOURCE_H

