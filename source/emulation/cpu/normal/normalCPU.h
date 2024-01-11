#ifndef __NORMAL_CPU_H__
#define __NORMAL_CPU_H__

#include "../common/cpu.h"

class NormalCPU : public CPU {
public:
    NormalCPU(KMemory* memory);

    static void clearCache();

    virtual void run();
    virtual DecodedBlock* getNextBlock();

    static OpCallback getFunctionForOp(DecodedOp* op);

    static DecodedBlock* getBlockForInspectionButNotUsed(CPU* cpu, U32 address, bool big);

    OpCallback firstOp;
};

#endif