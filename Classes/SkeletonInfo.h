#ifndef __SKELETONINFO_H__
#define __SKELETONINFO_H__

#include "SkeletonInterface.h"
#include "SkeletonAbstract.h"


class SkeletonInfo : public SkeletonAbstract, public SkeletonInterface {
public:
    virtual void excecute() override;
};


#endif


