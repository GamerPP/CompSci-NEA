#ifndef SRC_PIECES_PAWN_HPP
#define SRC_PIECES_PAWN_HPP
#include "../Piece.hpp"

class Pawn : public Piece {
public:
    Pawn(bool isWhite) {
        if (isWhite) name = "pawn_white";
        else name = "pawn_black";
    }
    ~Pawn();

    void ShowMoves(Piece* board[8][8], int x, int y) override {
        DrawRectangle(x*75, y*75, 75, 75, greenHighlight);
        if (name.back() == 'k') {
            if (y < 7) {
                if (board[x][y+1]->name.empty()) {
                    DrawRectangle(x*75, (y+1)*75, 75, 75, greenHighlight);
                    if (y < 6 && board[x][y+2]->name.empty() && firstMove) DrawRectangle(x*75, (y+2)*75, 75, 75, greenHighlight);
                }
                if (x < 7 && board[x+1][y+1]->name.size() && board[x+1][y+1]->name.back() != name.back()) DrawRectangle((x+1)*75, (y+1)*75, 75, 75, redHighlight);
                if (x > 0 && board[x-1][y+1]->name.size() && board[x-1][y+1]->name.back() != name.back()) DrawRectangle((x-1)*75, (y+1)*75, 75, 75, redHighlight);
            }
        } else {
            if (y > 0) {
                if (board[x][y-1]->name.empty()) {
                    DrawRectangle(x*75, (y-1)*75, 75, 75, greenHighlight);
                    if (y > 1 && board[x][y-2]->name.empty() && firstMove) DrawRectangle(x*75, (y-2)*75, 75, 75, greenHighlight);
                }
                if (x < 7 && board[x+1][y-1]->name.size() && board[x+1][y-1]->name.back() != name.back()) DrawRectangle((x+1)*75, (y-1)*75, 75, 75, redHighlight);
                if (x > 0 && board[x-1][y-1]->name.size() && board[x-1][y-1]->name.back() != name.back()) DrawRectangle((x-1)*75, (y-1)*75, 75, 75, redHighlight);
            }
        }
    }

    bool isValidMove(Piece* board[8][8], int startX, int startY, int destX, int destY) override {
        if (startX == destX && startY == destY) return false;
        if (name.back() == 'k') {
            if (startY >= destY) 
                return false;

            if (startX == destX) {
                if (startY == destY - 1) {
                    if (board[destX][destY]->name.empty()) return true;
                } else if (startY == destY - 2 && firstMove) {
                    if (board[destX][destY]->name.empty() && board[destX][destY-1]->name.empty()) return true;
                }
            } else if (abs(startX - destX) == 1) {
                if (startY == destY - 1 && board[destX][destY]->name.size() && board[destX][destY]->name.back() != name.back()) return true;
            }
        } else {
            if (startY <= destY) 
                return false;

            if (startX == destX) {
                if (startY == destY + 1) {
                    if (board[destX][destY]->name.empty()) return true;
                } else if (startY == destY + 2 && firstMove) {
                    if (board[destX][destY]->name.empty() && board[destX][destY+1]->name.empty()) return true;
                }
            } else if (abs(startX - destX) == 1) {
                if (startY == destY + 1 && board[destX][destY]->name.size() && board[destX][destY]->name.back() != name.back()) return true;
            }
        }
        return false;
    }
};

#endif /* SRC_PIECES_PAWN_HPP */
