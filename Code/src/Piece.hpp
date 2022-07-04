#ifndef SRC_PIECE_HPP
#define SRC_PIECE_HPP
#include <string>
#include <raylib.h>

#include "Math.hpp"

class Piece {
public:
    Piece() {}
    Piece(std::string name) : name(name) {}
    ~Piece() {}

    virtual void ShowMoves(Piece* board[8][8], int x, int y) {}
    virtual bool isValidMove(Piece* board[8][8], int startX, int startY, int destX, int destY) { return false; }

    std::string name;
    bool firstMove = true;

    const Color greenHighlight = { 0, 255, 0, 128 };
    const Color redHighlight = { 255, 0, 0, 128 };
};

#endif /* SRC_PIECE_HPP */
