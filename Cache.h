//
// Created by Mazen on 13.07.18.
//

#ifndef CACHE_CACHE_H
#define CACHE_CACHE_H


#include <cmath>


#define		CACHE_SIZE		(64*1024)

class Cache {
public:
    enum cacheResType {MISS=0, HIT=1};
    struct CacheBlock {
        bool valid = false;
        bool coldStart = true;
        int tag;
    };

    static const int CACHE_LINE_SIZE = 32;
    static const int numLines = CACHE_SIZE/ CACHE_LINE_SIZE;

    CacheBlock cache[numLines];

    int numIndexBits;
    int numOffsetBits;
    int numTagBits;

    Cache();

// Direct Mapped Cache Simulator
    cacheResType cacheSimDM(unsigned int addr);

private:
};


#endif //CACHE_CACHE_H
