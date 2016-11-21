#ifndef _COAP_RESOURCEAPI_H_
#define _COAP_RESOURCEAPI_H_

#include "config.h"
#include "resource.h"
#include "coap.h"
#include <stdbool.h>
struct coap_resource_t *SaghafiRes ;

typedef struct resourceRecord
{
    bool busyFlag;
    unsigned short indx;
    unsigned char *uri;
    unsigned char *interface;
    unsigned char *rtype;
    unsigned char *title;
}ResourceRecord;




unsigned char createResource(coap_context_t *ctx,coap_resource_t *r,ResourceRecord rc ,unsigned char* interface,unsigned char* rtype,unsigned char *title);

#endif
