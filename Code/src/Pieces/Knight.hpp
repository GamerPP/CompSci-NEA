#ifndef SRC_PIECES_KNIGHT_HPP
#define SRC_PIECES_KNIGHT_HPP
#include "../Piece.hpp"

class Knight : public Piece {
public:
    Knight(bool isWhite) {
        if (isWhite) name = "knight_white";
        else name = "knight_black";
    }
    ~Knight();

    void ShowMoves(Piece* board[8][8], int x, int y) override {
        DrawRectangle(x*75, y*75, 75, 75, greenHighlight);
        if (x+1<8 && y+2<8) {
            if (board[x+1][y+2]->name.empty()) DrawRectangle((x+1)*75, (y+2)*75, 75, 75, greenHighlight);
            else if (board[x+1][y+2]->name.back() != name.back()) DrawRectangle((x+1)*75, (y+2)*75, 75, 75, redHighlight);
        }

        if (x+2<8 && y+1<8) {
            if (board[x+2][y+1]->name.empty()) DrawRectangle((x+2)*75, (y+1)*75, 75, 75, greenHighlight);
            else if (board[x+2][y+1]->name.back() != name.back()) DrawRectangle((x+2)*75, (y+1)*75, 75, 75, redHighlight);
        }

        if (x+2<8 && y-1>=0) {
            if (board[x+2][y-1]->name.empty()) DrawRectangle((x+2)*75, (y-1)*75, 75, 75, greenHighlight);
            else if (board[x+2][y-1]->name.back() != name.back()) DrawRectangle((x+2)*75, (y-1)*75, 75, 75, redHighlight);
        }

        if (x+1<8 && y-2>=0) {
            if (board[x+1][y-2]->name.empty()) DrawRectangle((x+1)*75, (y-2)*75, 75, 75, greenHighlight);
            else if (board[x+1][y-2]->name.back() != name.back()) DrawRectangle((x+1)*75, (y-2)*75, 75, 75, redHighlight);
        }

        if (x-1>=0 && y-2>=0) {
            if (board[x-1][y-2]->name.empty()) DrawRectangle((x-1)*75, (y-2)*75, 75, 75, greenHighlight);
            else if (board[x-1][y-2]->name.back() != name.back()) DrawRectangle((x-1)*75, (y-2)*75, 75, 75, redHighlight);
        }

        if (x-2>=0 && y-1>=0) {
            if (board[x-2][y-1]->name.empty()) DrawRectangle((x-2)*75, (y-1)*75, 75, 75, greenHighlight);
            else if (board[x-2][y-1]->name.back() != name.back()) DrawRectangle((x-2)*75, (y-1)*75, 75, 75, redHighlight);
        }

        if (x-2>=0 && y+1<8) {
            if (board[x-2][y+1]->name.empty()) DrawRectangle((x-2)*75, (y+1)*75, 75, 75, greenHighlight);
            else if (board[x-2][y+1]->name.back() != name.back()) DrawRectangle((x-2)*75, (y+1)*75, 75, 75, redHighlight);
        }

        if (x-1>=0 && y+2<8) {
            if (board[x-1][y+2]->name.empty()) DrawRectangle((x-1)*75, (y+2)*75, 75, 75, greenHighlight);
            else if (board[x-1][y+2]->name.back() != name.back()) DrawRectangle((x-1)*75, (y+2)*75, 75, 75, redHighlight);
        }
    }

    bool isValidMove(Piece* board[8][8], int startX, int startY, int destX, int destY) override {
        if (destX == startX && destY == startY) return false;
        if (board[destX][destY]->name.empty()) {
            if (abs(destX-startX) == 2 && abs(destY-startY) == 1) return true;
            else if (abs(destX-startX) == 1 && abs(destY-startY) == 2) return true;
        }
        else if (board[destX][destY]->name.back() != name.back()) {
            if (abs(destX-startX) == 2 && abs(destY-startY) == 1) return true;
            else if (abs(destX-startX) == 1 && abs(destY-startY) == 2) return true;
        }
        return false;
    }
};

#endif /* SRC_PIECES_KNIGHT_HPP */
