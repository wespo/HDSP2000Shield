/***** ASCII character data *****

We define bit patterns for these characters
(ascii 0x20 to 0x7E = 95 characters). 

ASCII CHAR ASCII CHAR ASCII CHAR ASCII CHAR ASCII CHAR ASCII CHAR
0x20       0x30  0    0x40  @    0x50  P    0x60  `    0x70  p
0x21  !    0x31  1    0x41  A    0x51  Q    0x61  a    0x71  q
0x22  "    0x32  2    0x42  B    0x52  R    0x62  b    0x72  r
0x23  #    0x33  3    0x43  C    0x53  S    0x63  c    0x73  s
0x24  $    0x34  4    0x44  D    0x54  T    0x64  d    0x74  t
0x25  %    0x35  5    0x45  E    0x55  U    0x65  e    0x75  u
0x26  &    0x36  6    0x46  F    0x56  V    0x66  f    0x76  v
0x27  '    0x37  7    0x47  G    0x57  W    0x67  g    0x77  w
0x28  (    0x38  8    0x48  H    0x58  X    0x68  h    0x78  x
0x29  )    0x39  9    0x49  I    0x59  Y    0x69  i    0x79  y
0x2A  *    0x3A  :    0x4A  J    0x5A  Z    0x6A  j    0x7A  z
0x2B  +    0x3B  ;    0x4B  K    0x5B  [    0x6B  k    0x7B  {
0x2C  ,    0x3C  <    0x4C  L    0x5C  \    0x6C  l    0x7C  |
0x2D  -    0x3D  =    0x4D  M    0x5D  ]    0x6D  m    0x7D  }
0x2E  .    0x3E  >    0x4E  N    0x5E  ^    0x6E  n    0x7E  ~
0x2F  /    0x3F  ?    0x4F  O    0x5F  _    0x6F  o    


An "A" is defined like this (for a 5x7 array)

    x       = 00100 = 0x04
  x   x     = 01010 = 0x0A
x       x   = 10001 = 0x11
x       x   = 10001 = 0x11
x x x x x   = 11111 = 0x1F
x       x   = 10001 = 0x11
x       x   = 10001 = 0x11

so we could define A like this

unsigned char A_DATA[7] = { 0x04, 0x0A, 0x11, 0x11, 0x1F, 0x11, 0x11 } ;

or we could draw a picture and let the preprocessor do the work for us

#define __x__ 0x04    // __x__ = 00100, so there will only be 32 patterns 
#define _x_x_ 0x0A    // to define
#define x___x 0x11
#define xxxxx 0x1F

unsigned char A_DATA[7] = { __x__,
                            _x_x_,
                            x___x,
                            x___x,
                            xxxxx,
                            x___x,
                            x___x } 

now this is much easier to fiddle with if we want to 
define a slightly different look (no need to sketch it
out, find the binary, then  the hex. 

*/


#define    _____  0x00
#define    ____x  0x01
#define    ___x_  0x02
#define    ___xx  0x03
#define    __x__  0x04
#define    __x_x  0x05
#define    __xx_  0x06
#define    __xxx  0x07
#define    _x___  0x08
#define    _x__x  0x09
#define    _x_x_  0x0A
#define    _x_xx  0x0B
#define    _xx__  0x0C
#define    _xx_x  0x0D
#define    _xxx_  0x0E
#define    _xxxx  0x0F
#define    x____  0x10
#define    x___x  0x11
#define    x__x_  0x12
#define    x__xx  0x13
#define    x_x__  0x14
#define    x_x_x  0x15
#define    x_xx_  0x16
#define    x_xxx  0x17
#define    xx___  0x18
#define    xx__x  0x19
#define    xx_x_  0x1A
#define    xx_xx  0x1B
#define    xxx__  0x1C
#define    xxx_x  0x1D
#define    xxxx_  0x1E
#define    xxxxx  0x1F

unsigned char char_data[95][7] = 
{ 

    { _____,
      _____,
      _____,
      _____,
      _____,
      _____,
      _____ }, // space

    { __x__,
      __x__,
      __x__,
      __x__,
      __x__,
      _____,
      __x__ }, // !

    { _x_x_,
      _x_x_,
      _____,
      _____,
      _____,
      _____,
      _____ }, // "

    { _____,
      _x_x_,
      xxxxx,
      _x_x_,
      xxxxx,
      _x_x_,
      _____ }, // #

    { __x__,
      _xxxx,
      x_x__,
      _xxx_,
      __x_x,
      xxxx_,
      __x__ }, // $

    { xx___,
      xx__x,
      ___x_,
      __x__,
      _x___,
      x__xx,
      ___xx }, // %

    { _xxx_,
      _x_x_,
      _xx__,
      _x___,
      x_x_x,
      x__xx,
      _xxx_ }, // &

    { __x__,
      __x__,
      _____,
      _____,
      _____,
      _____,
      _____ }, // '

    { ____x,
      ___x_,
      __x__,
      __x__,
      __x__,
      ___x_,
      ____x }, // (

    { x____,
      _x___,
      __x__,
      __x__,
      __x__,
      _x___,
      x____ }, // )

    { _____,
      __x__,
      x_x_x,
      xxxxx,
      x_x_x,
      __x__,
      _____ }, // *

    { _____,
      __x__,
      __x__,
      xxxxx,
      __x__,
      __x__,
      _____ }, // +

    { _____,
      _____,
      _____, 
      _____, 
      _____, 
      ___x_,
      __x__ }, // ,

    { _____,
      _____,
      _____,
      _xxx_,
      _____,
      _____,
      _____ }, // -

    { _____,
      _____,
      _____,
      _____,
      _____,
      __xx_,
      __xx_ }, // .

    { _____,
      ____x,
      ___x_,
      __x__,
      _x___,
      x____,
      _____ }, // /

    { _xxx_,
      x___x,
      x__xx,
      x_x_x,
      xx__x,
      x___x,
      _xxx_ }, // 0

    { __x__,
      _xx__,
      __x__,
      __x__,
      __x__,
      __x__,
      xxxxx }, // 1

    { _xxx_, 
      x___x, 
      ____x,
      __xx_,
      _x___,
      x____,
      xxxxx }, // 2

    { _xxx_,
      x___x,
      ____x,
      __xx_,
      ____x,
      x___x,
      _xxx_ }, // 3

    { x____,
      x___x,
      x___x,
      xxxxx,
      ____x,
      ____x,
      ____x }, // 4

    { xxxxx,
      x____,
      x____,
      xxxx_,
      ____x,
      x___x,
      _xxx_ }, // 5

    { _xxx_,
      x___x,
      x____,
      xxxx_,
      x___x,
      x___x,
      _xxx_ }, // 6 

    { xxxxx,
      ____x,
      ____x,
      ___x_,
      __x__,
      __x__,
      __x__ }, //7

    { _xxx_,
      x___x,
      x___x,
      _xxx_,
      x___x,
      x___x,
      _xxx_ }, //8

    { _xxx_,
      x___x,
      x___x,
      _xxxx,
      ____x,
      ____x,
      ____x }, //9

    { _____,
      __x__,
      __x__,
      _____,
      __x__,
      __x__,
      _____ }, // :

    { _____,
      _____,
      __x__,
      __x__,
      _____,
      __x__,
      _x___ }, // ;

    { ____x,
      ___x_,
      __x__,
      _x___,
      __x__,
      ___x_,
      ____x }, // <

    { _____,
      _____,
      xxxxx,
      _____,
      xxxxx,
      _____,
      _____ }, // =

    { x____,
      _x___,
      __x__,
      ___x_,
      __x__,
      _x___,
      x____ }, // >

    { _xxx_,
      x___x,
      ___x_,
      __x__,
      __x__,
      _____,
      __x__ }, // ?

    { _xxx_,
      x___x,
      x_x_x,
      x_x_x,
      x_xxx,
      x____,
      _xxxx }, // @

    { __x__,
      _x_x_,
      x___x,
      x___x,
      xxxxx,
      x___x,
      x___x }, // A

    { xxxx_,
      x___x,
      x___x,
      xxxx_,
      x___x,
      x___x,
      xxxxx }, // B

    { _xxx_,
      x___x,
      x____,
      x____,
      x____,
      x___x,
      _xxx_ }, // C

    { xxxx_,
      x___x,
      x___x,
      x___x,
      x___x,
      x___x,
      xxxxx }, // D

    { xxxxx,
      x____,
      x____,
      xxx__,
      x____,
      x____,
      xxxxx }, // E

    { xxxxx,
      x____,
      x____,
      xxx__,
      x____,
      x____,
      x____ }, // F

    { _xxx_,
      x___x,
      x____,
      x_xxx,
      x___x,
      x___x,
      _xxx_ }, // G

    { x___x,
      x___x,
      x___x,
      xxxxx,
      x___x,
      x___x,
      x___x }, // H

    { xxxxx,
      __x__,
      __x__,
      __x__,
      __x__,
      __x__,
      xxxxx }, // I

    { xxxxx,
      ___x_,
      ___x_,
      ___x_,
      ___x_,
      x__x_,
      _xx__ }, // J

    { x___x,
      x__x_,
      x_x__,
      xx___,
      x_x__,
      x__x_,
      x___x }, // K

    { x____,
      x____,
      x____,
      x____,
      x____,
      x____,
      xxxxx }, // L

    { x___x,
      xx_xx,
      x_x_x,
      x___x,
      x___x,
      x___x,
      x___x }, // M

    { x___x,
      x___x,
      xx__x,
      x_x_x,
      x__xx,
      x___x,
      x___x }, // N

    { _xxx_,
      x___x,
      x___x,
      x___x,
      x___x,
      x___x,
      _xxx_ }, // O

    { xxxx_,
      x___x,
      x___x,
      xxxx_,
      x____,
      x____,
      x____ }, // P

    { _xxx_,
      x___x,
      x___x,
      x___x,
      x_x_x,
      x__x_,
      _xx_x }, // Q

    { xxxx_,
      x___x,
      x___x,
      xxxx_,
      x_x__,
      x__x_,
      x___x }, // R

    { _xxx_,
      x___x,
      x____,
      _xxx_,
      ____x,
      x___x,
      _xxx_ }, // S

    { xxxxx,
      __x__,
      __x__,
      __x__,
      __x__,
      __x__,
      __x__ }, // T

    { x___x,
      x___x,
      x___x,
      x___x,
      x___x,
      x___x,
      _xxx_ }, // U

    { x___x,
      x___x,
      x___x,
      x___x,
      x___x,
      _x_x_,
      __x__ }, // V

    { x___x,
      x___x,
      x___x,
      x___x,
      x_x_x,
      xx_xx,
      x___x }, // W
             
    { x___x,
      x___x,
      _x_x_,
      __x__,
      _x_x_,
      x___x,
      x___x }, // X


    { x___x,
      x___x,
      _x_x_,
      __x__,
      __x__,
      __x__,
      __x__ }, // Y

    { xxxxx,
      x___x,
      ___x_,
      __x__,
      _x___,
      x___x,
      xxxxx }, // Z

    { _xxx_,
      _x___,
      _x___,
      _x___,
      _x___,
      _x___,
      _xxx_ }, // [

    { _____,
      x____,
      _x___,
      __x__,
      ___x_,
      ____x,
      _____ }, // \

    { _xxx_,
      ___x_,
      ___x_,
      ___x_,
      ___x_,
      ___x_,
      _xxx_ }, // ] 

    { __x__,
      _x_x_,
      x___x,
      _____,
      _____,
      _____,
      _____ }, // ^

    { _____,
      _____,
      _____,
      _____,
      _____,
      _____,
      xxxxx }, // _

// d e f g h i j k l m n o p q r s t u v w x y z

    { _x___,
      __x__,
      _____,
      _____,
      _____,
      _____,
      _____ }, // `

    { _____,
      _____,
      _____,
      _xx__,
      x__x_,
      x__x_,
      _xx_x, }, // a

    { _____,
      x____,
      x____,
      xxxx_,
      x___x,
      x___x,
      xxxx_ }, // b

    { _____,
      _____,
      _____,
      _xxxx,
      x____,
      x____,
      _xxxx, }, // c

    { _____,
      ____x,
      ____x,
      _xxxx,
      x___x,
      x___x,
      _xxxx }, // d

    { _____,
      _____,
      _xxx_,
      x___x,
      xxxx_,
      x____,
      _xxxx, }, // e

    { __xx_,
      _x__x,
      _x___,
      xxxx_,
      _x___,
      _x___,
      _x___, }, // f

    { _____,
      _xxx_,
      x___x,
      x___x,
      _xxxx,
      ____x,
      _xxx_, }, // c

    { _____,
      x____,
      x____,
      xxxx_,
      x___x,
      x___x,
      x___x, }, // h

    { _____,
      _____,
      __x__,
      _____,
      __x__,
      __x__,
      __x__, }, // i

    { _____,
      ___x_,
      ___x_,
      ___x_,
      ___x_,
      x__x_,
      _xx__, }, // j

    { _____,
      _____,
      x__x_,
      x_x__,
      xxx__,
      x__x_,
      x___x, }, // k

    { _____,
      _x___,
      _x___,
      _x___,
      _x___,
      _x___,
      _x___ }, // l

    { _____,
      _____,
      _____,
      x___x,
      xx_xx,
      x_x_x,
      x___x }, // m

    { _____,
      _____,
      _____,
      x_xx_,
      xx__x,
      x___x,
      x___x }, // n

    { _____,
      _____,
      _____,
      _xxx_,
      x___x,
      x___x,
      _xxx_ }, // o


    { _____,
      _xxx_,
      _x__x,
      _x__x,
      _xxx_,
      _x___,
      _x___, }, // p

    { _____,
      _xxx_,
      x___x,
      _xxx_,
      ___x_,
      ___x_,
      ____x, }, // q

    { _____,
      _____,
      _x___,
      _xxx_,
      _x___,
      _x___,
      _x___ }, // r

    { _____,
      _____,
      __xxx,
      _x___,
      __xx_,
      ____x,
      _xxx_ }, // s

    { _____,
      _____,
      __x__,
      _xxx_,
      __x__,
      __x__,
      __x__ }, // t

    { _____,
      _____,
      _____,
      x___x,
      x___x,
      x___x,
      _xxx_ }, // u

    { _____,
      _____,
      _____,
      x___x,
      x___x,
      _x_x_,
      __x__ }, // v

    { _____,
      _____,
      _____,
      x___x,
      x_x_x,
      xx_xx,
      x___x }, // w
             
    { _____,
      _____,
      x___x,
      _x_x_,
      __x__,
      _x_x_,
      x___x, }, // x

    { _____,
      _____,
      x___x,
      _x_x_,
      __x__,
      __x__,
      __x__ }, // y

    { _____,
      _____,
      xxxxx,
      ___x_,
      __x__,
      _x___,
      xxxxx }, // z

    { __xx_,
      _x___,
      _x___,
      x____,
      _x___,
      _x___,
      __xx_, }, // {
 
    { __x__,
      __x__, 
      __x__, 
      __x__, 
      __x__, 
      __x__, 
      __x__, }, // |
 
    { _xx__,
      ___x_,
      ___x_,
      ____x,
      ___x_,
      ___x_,
      _xx__, }, // }

    { _____,
      _x_x_,
      x_x_x,
      _____,
      _____,
      _____,
      _____, }, // ~

};
