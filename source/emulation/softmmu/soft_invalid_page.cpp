#include "boxedwine.h"

#include "soft_invalid_page.h"

static InvalidPage _invalidPage;
InvalidPage* invalidPage = &_invalidPage;;


U8 InvalidPage::readb(U32 address) {	
    KThread::currentThread()->seg_mapper(address);
    return 0;
}

void InvalidPage::writeb(U32 address, U8 value) {
    KThread::currentThread()->seg_mapper(address);
}

U16 InvalidPage::readw(U32 address) {
    KThread::currentThread()->seg_mapper(address);
    return 0;
}

void InvalidPage::writew(U32 address, U16 value) {
    KThread::currentThread()->seg_mapper(address);
}

U32 InvalidPage::readd(U32 address) {
    KThread::currentThread()->seg_mapper(address);
    return 0;
}

void InvalidPage::writed(U32 address, U32 value) {
    KThread::currentThread()->seg_mapper(address);
}

U8* InvalidPage::physicalAddress(U32 address) {
    return 0;
}