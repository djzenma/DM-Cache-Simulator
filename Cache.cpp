//
// Created by Mazen on 13.07.18.
//

#include <iostream>
#include "Cache.h"

using namespace std;




Cache::Cache() {
    numIndexBits = static_cast<int>(log2(numLines));
    numOffsetBits = static_cast<int>(log2(CACHE_LINE_SIZE));
    numTagBits = 32 - numIndexBits - numOffsetBits;
}



// Direct Mapped Cache Simulator
Cache::cacheResType Cache::cacheSimDM(unsigned int addr)
{
    //cout<< "Index bits " << numIndexBits << " Offset bits " << numOffsetBits << " Tag bits " << numTagBits<<endl;
    bitset<32> addressInBits(addr);

    addr = addr >> numOffsetBits;
    unsigned int index = addr % (int) pow(2, numIndexBits);
    unsigned int tag = addr >> numIndexBits;
    cout<<"index : "<<index<<" tag : "<<tag<<" new address "<<addressInBits.to_string()<<endl;

    if(cache[index].valid && cache[index].tag == tag)
        return HIT;
    else {
        cache[index].tag = tag;
        cache[index].valid = true;
        return MISS;
    }
}





