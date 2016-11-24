QT += core
QT -= gui

CONFIG += c++11

TARGET = FBs
CONFIG += console
CONFIG += shared


TEMPLATE = lib

SOURCES += \
    fbwrapper.cpp \
    FunctionBlocks/fb_add.cpp \
    FunctionBlocks/fbmanager.cpp \
    common/baseblock.cpp


target.path = /root
INSTALLS += target

HEADERS += \
    fbwrapperinterface.h \
    fbwrapper.h \
    coapINC/address.h \
    coapINC/async.h \
    coapINC/bits.h \
    coapINC/block.h \
    coapINC/coap.h \
    coapINC/coap_io.h \
    coapINC/coap_list.h \
    coapINC/coap_time.h \
    coapINC/config.h \
    coapINC/debug.h \
    coapINC/encode.h \
    coapINC/globals.h \
    coapINC/hashkey.h \
    coapINC/lwippools.h \
    coapINC/mem.h \
    coapINC/net.h \
    coapINC/option.h \
    coapINC/pdu.h \
    coapINC/prng.h \
    coapINC/resource.h \
    coapINC/resourceAPI.h \
    coapINC/str.h \
    coapINC/subscribe.h \
    coapINC/t_list.h \
    coapINC/uri.h \
    coapINC/uthash.h \
    coapINC/utlist.h \
    Common/coapINC/address.h \
    Common/coapINC/async.h \
    Common/coapINC/bits.h \
    Common/coapINC/block.h \
    Common/coapINC/coap.h \
    Common/coapINC/coap_io.h \
    Common/coapINC/coap_list.h \
    Common/coapINC/coap_time.h \
    Common/coapINC/config.h \
    Common/coapINC/debug.h \
    Common/coapINC/encode.h \
    Common/coapINC/globals.h \
    Common/coapINC/hashkey.h \
    Common/coapINC/lwippools.h \
    Common/coapINC/mem.h \
    Common/coapINC/net.h \
    Common/coapINC/option.h \
    Common/coapINC/pdu.h \
    Common/coapINC/prng.h \
    Common/coapINC/resource.h \
    Common/coapINC/resourceAPI.h \
    Common/coapINC/str.h \
    Common/coapINC/subscribe.h \
    Common/coapINC/t_list.h \
    Common/coapINC/uri.h \
    Common/coapINC/uthash.h \
    Common/coapINC/utlist.h \
    Common/baseblock.h \
    Common/enums.h \
    Common/param.h \
    common/baseblock.h \
    common/coapresource.h \
    common/enums.h \
    common/param.h \
    FunctionBlocks/fb_add.h \
    FunctionBlocks/fbmanager.h

DISTFILES +=
