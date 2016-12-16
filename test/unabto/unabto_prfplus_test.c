
#include "unabto/unabto_env_base.h"

#if NABTO_ENABLE_TEST_CODE

#include "unabto_prfplus_test.h"
#include "unabto/unabto_prf.h"

/**
 * Test the following vector.
 *
 * 120221-20:07:40.515 {041f2d80} [___DEFAULT,user1] unabto_prf.c(43):                    prfplus, key
 * 0000:  b2 aa f8 e9 f8 79 02 f5  2d 44 1e e3 ce 63 4f f0  .....y.. -D...cO.
 * 0010:  5f 8c 7d ef 3d 98 5e 65  85 5f 7d 55 ac 6d ee 20  _.}.=.^e ._}U.m. 
 * 120221-20:07:40.516 {041f2d80} [___DEFAULT,user1] unabto_prf.c(44):                    prfplus, seed
 * 0000:  2a c2 64 ae 12 b4 33 61  76 35 b0 05 ed cf 2a 50  *.d...3a v5....*P
 * 0010:  3c 0c f4 41 a0 71 a4 8b  2b 2f 30 f5 e3 32 e3 00  <..A.q.. +/0..2..
 * 0020:  51 05 78 ca 9a 4f 41 8a  2a e0 2f ab 6b 4e d9 12  Q.x..OA. *./.kN..
 * 0030:  b7 06 3e 3a 74 4c 6e a2  69 72 57 0b ba 26 43 c0  ..>:tLn. irW..&C.
 * 120221-20:07:40.517 {041f2d80} [___DEFAULT,user1] unabto_prf.c(45):                    prfplus output
 * 0000:  e5 c7 48 13 f2 b6 85 0d  f7 62 69 9c 2d ae 69 8a  ..H..... .bi.-.i.
 * 0010:  7c 58 90 15 73 28 f2 82  f9 49 37 1c 59 36 dd cb  |X..s(.. .I7.Y6..
 * 0020:  65 5d 46 72 02 5e 3e 70  73 e7 5d 21 ae 72 85 dc  e]Fr.^>p s.]!.r..
 * 0030:  67 0a bc 28 de 24 fb 8a  2a 5b 92 fe b0 80 94 b1  g..(.$.. *[......
 * 0040:  a9 3c cb c4 9c f5 d5 67  27 3d 7f 17 93 99 b7 40  .<.....g '=.....@
 * 0050:  20 b8 bb 23 59 69 ba 09  9e af 1a 78 a1 e8 c7 54   ..#Yi.. ...x...T
 */

const uint8_t key[] = {
    0xb2, 0xaa, 0xf8, 0xe9, 0xf8, 0x79, 0x02, 0xf5,  0x2d, 0x44, 0x1e, 0xe3, 0xce, 0x63, 0x4f, 0xf0,  
    0x5f, 0x8c, 0x7d, 0xef, 0x3d, 0x98, 0x5e, 0x65,  0x85, 0x5f, 0x7d, 0x55, 0xac, 0x6d, 0xee, 0x20 };

const uint8_t seed[] = {
    0x2a, 0xc2, 0x64, 0xae, 0x12, 0xb4, 0x33, 0x61, 0x76, 0x35, 0xb0, 0x05, 0xed, 0xcf, 0x2a, 0x50,
    0x3c, 0x0c, 0xf4, 0x41, 0xa0, 0x71, 0xa4, 0x8b, 0x2b, 0x2f, 0x30, 0xf5, 0xe3, 0x32, 0xe3, 0x00,
    0x51, 0x05, 0x78, 0xca, 0x9a, 0x4f, 0x41, 0x8a, 0x2a, 0xe0, 0x2f, 0xab, 0x6b, 0x4e, 0xd9, 0x12,
    0xb7, 0x06, 0x3e, 0x3a, 0x74, 0x4c, 0x6e, 0xa2, 0x69, 0x72, 0x57, 0x0b, 0xba, 0x26, 0x43, 0xc0 };

const uint8_t result[] = {
    0xe5, 0xc7, 0x48, 0x13, 0xf2, 0xb6, 0x85, 0x0d, 0xf7, 0x62, 0x69, 0x9c, 0x2d, 0xae, 0x69, 0x8a,
    0x7c, 0x58, 0x90, 0x15, 0x73, 0x28, 0xf2, 0x82, 0xf9, 0x49, 0x37, 0x1c, 0x59, 0x36, 0xdd, 0xcb,
    0x65, 0x5d, 0x46, 0x72, 0x02, 0x5e, 0x3e, 0x70, 0x73, 0xe7, 0x5d, 0x21, 0xae, 0x72, 0x85, 0xdc,
    0x67, 0x0a, 0xbc, 0x28, 0xde, 0x24, 0xfb, 0x8a, 0x2a, 0x5b, 0x92, 0xfe, 0xb0, 0x80, 0x94, 0xb1,
    0xa9, 0x3c, 0xcb, 0xc4, 0x9c, 0xf5, 0xd5, 0x67, 0x27, 0x3d, 0x7f, 0x17, 0x93, 0x99, 0xb7, 0x40,
    0x20, 0xb8, 0xbb, 0x23, 0x59, 0x69, 0xba, 0x09, 0x9e, 0xaf, 0x1a, 0x78, 0xa1, 0xe8, 0xc7, 0x54
};

#if __18CXX
#pragma udata big_mem_section
#endif
static uint8_t res[96];
#if __18CXX
#pragma udata
#endif

bool unabto_prfplus_test() {
    bool ret;
    unabto_buffer keys[1];
    unabto_buffer seeds[1];
    unabto_buffer_init(keys, (uint8_t*)key, 32);
    unabto_buffer_init(seeds, (uint8_t*)seed, 64);
    
    prfplus_sha256(keys, 1, seeds, 1, res, 96);
    ret = (
#if __18CXX
        memcmppgm2ram
#else
        memcmp
#endif 
        (res, result, 96) == 0);   
    return ret;
}

#else

static uint8_t dummy;

#endif

