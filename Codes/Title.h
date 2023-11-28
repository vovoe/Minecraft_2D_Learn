#pragma once

using namespace sf;

float offsetX = 0, offsetY = 0;

const int H = 16;
const int W = 132;

const int ts = 80;

String TileMap[H] = {
"X                                                                                                                                   X",
"X                                                                                                                                   X",
"X                                                                                                                                   X",
"X                                                                                                                                   X",
"X                                AAAA                                                                                               X",
"X                                BBBBA                                                                                              X",
"X                               ABCCBBA                                                                                             X",
"X                             AABBCCBBBAA    AA                                                                                     X",
"X                           AABBBCCCCCCBBAAAABBAA                                                                                   X",
"X                          ABBBBCCCCCCCBBBBBCCCCBA   A                                                                              X",
"X                        AABBCCCCCCCCCCCCCCCCCCCCBAAABAAAAA AA                 A        A                                           X",
"XEEEEEEEEEEEEEEEEDDDAAAAABBBCCCCCCCCCCCCCCCCCCCCCCCCBBBBBBBABBAAAA    AA AA   A AAAAAAAAB                AAAAAAAAAA   AAAAA     DDDDX",
"XEEEEEEEEEEEEEDDDDBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBBBBBDDBBBBBBBAAA           AAAAAAAAAAAAAAAA          AAA     AAAADDDDDX",
"XEEEEEEEEEEEDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDD  D    BB   BBBBBBBB                                        DDDDDX",
"XDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC       CCCBBBBBBBBBBBBB                 BBBBBBBBBB            BBBBBX",
"XCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBDBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBX",
};

String Rear[H] = {
"X                                                                                                                                   X",
"X                                                                                                                                   X",
"X                                AAAA                                                                                               X",
"X                               ABBBBA                                                                                              X",
"X                               BBBBBBA                                                                                             X",
"X                               BBCCBBB      AA                                                                                     X",
"X                             AABBBBBBBAAAAAABB                                                                                     X",
"X                          AAABBBCCCCBBBBBBBBBB                                                                                     X",
"X                        AABBBBCCCCCCCCBBBBBBBBBB    AAAAAA                                                AAA                      X",
"X                       ABBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBB                                   AAAAAAA     BBBB                      X",
"X                   AAAABBBBCCCCCCCCCCCCCCCCCCCBBBBBBBBBBBB BB                B         B  AAABBBBBBB    BBBBBBB                DDDDX",
"XDDDDDDDDDDDDDDDDDDDBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBA   BB BB   BBBBBBBBBBB   BBBBBBBBBB    BBBBBBBBBB   BBBBB     DDDDX",
"XDDDDDDDDDDDDDDDDDDDBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBX",
"XBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBX",
"XCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCX",
"XCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCX",
};