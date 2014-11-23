#pragma once

typedef unsigned char BYTE;
typedef unsigned int UINT;
typedef long long int LLINT;

template<class Type>
inline Type Max(Type X, Type Y) { return X < Y ? Y : X; }
template<class Type>
inline Type Min(Type X, Type Y) { return X < Y ? X : Y; }