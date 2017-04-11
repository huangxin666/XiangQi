#ifndef __CHESS_H__
#define __CHESS_H__
#include "defines.h"

struct ChessInfo
{
    int8_t flex;//������ 0-100
};

class Chess
{
public:
    Chess() :type(0), info(NULL)
    {

    }

    ~Chess()
    {
        if (info)
        {
            delete info;
        }
    }

    const Chess& operator=(const Chess& other)
    {
        type = other.type;
        if (other.info)
        {
            info = new ChessInfo;
            *info = *other.info;
        }
    }

    bool isEmpty()
    {
        return type == CHESSTYPE_EMPTY;
    };

public:
    ChessInfo *info;
    uint8_t type;
    uint8_t state;
};

#endif