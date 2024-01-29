#ifndef __SOFT_NATIVE_PAGE_H__
#define __SOFT_NATIVE_PAGE_H__

#include "soft_page.h"

class NativePage : public Page {
protected:
    NativePage(U8* nativeAddress, U32 address);

public:
    static NativePage* alloc(U8* nativeAddress, U32 address);

    virtual U8 readb(U32 address) override;
    virtual void writeb(U32 address, U8 value) override;
    virtual U16 readw(U32 address) override;
    virtual void writew(U32 address, U16 value) override;
    virtual U32 readd(U32 address) override;
    virtual void writed(U32 address, U32 value) override;
    virtual U8* getReadPtr(U32 address, bool makeReady = false) override;
    virtual U8* getWritePtr(U32 address, U32 len, bool makeReady = false) override;
    virtual Type getType() override { return Native_Page; }

    virtual bool inRam() override {return true;}
    virtual void close() override {delete this;}

    U8* nativeAddress;
    U32 address;
};

#endif