#pragma once
/*
   Demo Name:  Game Project 1
      Author:  Allen Sherrod
     Chapter:  Chapter 2
*/


#ifndef DEFINES_H_
#define DEFINES_H_

#include<windows.h>

// Boolean values.
constexpr auto INVALID = -1;
constexpr auto OK = 1;
constexpr auto FAIL = 0;


// Typedefs and enumerations.
typedef long VertexType;
enum class PrimType
{
    NULL_TYPE,
    POINT_LIST,
    TRIANGLE_LIST,
    TRIANGLE_STRIP,
    TRIANGLE_FAN,
    LINE_LIST,
    LINE_STRIP
};
// Color defines.
#define COLOR_ARGB(a,r,g,b) ((unsigned long)((((a)&0xff)<<24)|\
                            (((r)&0xff)<<16)|(((g)&0xff)<<8)|\
                            ((b)&0xff)))

#endif