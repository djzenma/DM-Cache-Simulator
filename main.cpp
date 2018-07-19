#include <iostream>
#include  <iomanip>
#include <math.h>
#include "Cache.h"

using namespace std;

#define		DBG				1
#define		DRAM_SIZE		(64*1024*1024)
#define		CACHE_SIZE		(64*1024)



/* The following implements a random number generator */
unsigned int m_w = 0xABABAB55;    /* must not be zero, nor 0x464fffff */
unsigned int m_z = 0x05080902;    /* must not be zero, nor 0x9068ffff */
unsigned int rand_()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;  /* 32-bit result */
}

// 0 < addresses < DRAM_SIZE= 64 MB
unsigned int memGen1()
{
    static unsigned int addr=0;
    return (addr++)%(DRAM_SIZE);
}

// random number less than 32 bytes
unsigned int memGen2()
{
    static unsigned int addr=0;
    return  rand_()%(32*1024);
}

// random address less than dram size
unsigned int memGen3()
{
    return rand_()%(DRAM_SIZE);
}

// 0 < addresses < 1 kb
unsigned int memGen4()
{
    static unsigned int addr=0;
    return (addr++)%(1024);
}

// 0 < addresses < 64 kb
unsigned int memGen5()
{
    static unsigned int addr=0;
    return (addr++)%(1024*64);
}


unsigned int memGen6()
{
    static unsigned int addr=0;
    return (addr+=64)%(128*1024);
}



char *msg[2] = {"Miss","Hit"};

#define		NO_OF_Iterations	1000000

int main()
{
    Cache cache;

    float hit = 0;
    Cache::cacheResType r;

    unsigned int addr;
    cout << "Direct Mapped Cache Simulator\n";

    for(int inst=0; inst < NO_OF_Iterations; inst++)
    {
        addr = memGen3();
        r = cache.cacheSimDM(addr);
        if(r == Cache::cacheResType::HIT) hit++;
        cout <<"0x" << setfill('0') << setw(8) << addr <<" ("<< msg[r] <<")\n";
    }
    cout << "Hit ratio = " << (100*hit/NO_OF_Iterations)<< endl;
}
