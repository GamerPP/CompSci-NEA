#ifndef SRC_PIECES_QUEEN_HPP
#define SRC_PIECES_QUEEN_HPP
#include "../Piece.hpp"

class Queen : public Piece {
public:
    Queen(bool isWhite) {
        if (isWhite) name = "queen_white";
        else name = "queen_black";
    }
    ~Queen();

    void ShowMoves(Piece* board[8][8], int x, int y) override {
        DrawRectangle(x*75, y*75, 75, 75, greenHighlight);
        for (int i = 1; i < 8-y; i++) {
            if (board[x][y+i]->name.empty()) DrawRectangle(x*75, (y+i)*75, 75, 75, greenHighlight);
            else if (board[x][y+i]->name.back() != name.back()) {
                DrawRectangle(x*75, (y+i)*75, 75, 75, redHighlight);
                break;
            } else break;
        }
        for (int i = 1; i <= y; i++) {
            if (board[x][y-i]->name.empty()) DrawRectangle(x*75, (y-i)*75, 75, 75, greenHighlight);
            else if (board[x][y-i]->name.back() != name.back()) { 
                DrawRectangle(x*75, (y-i)*75, 75, 75, redHighlight);
                break;
            } else break;
        }
        for (int i = 1; i < 8-x; i++) {
            if (board[x+i][y]->name.empty()) DrawRectangle((x+i)*75, y*75, 75, 75, greenHighlight);
            else if (board[x+i][y]->name.back() != name.back()) {
                DrawRectangle((x+i)*75, y*75, 75, 75, redHighlight);
                break;
            } else break;
        }
        for (int i = 1; i <= x; i++) {
            if (board[x-i][y]->name.empty()) DrawRectangle((x-i)*75, y*75, 75, 75, greenHighlight);
            else if (board[x-i][y]->name.back() != name.back()) {
                DrawRectangle((x-i)*75, y*75, 75, 75, redHighlight);
                break;
            } else break;
        }

        for (int i = 1; i < 8-y; i++) {
            if (x+i >= 8) break;
            if (board[x+i][y+i]->name.empty()) DrawRectangle((x+i)*75, (y+i)*75, 75, 75, greenHighlight);
            else if (board[x+i][y+i]->name.back() != name.back()) {
                DrawRectangle((x+i)*75, (y+i)*75, 75, 75, redHighlight);
                break;
            } else break;
        }
        for (int i = 1; i <= y; i++) {
            if (x+i >= 8) break;
            if (board[x+i][y-i]->name.empty()) DrawRectangle((x+i)*75, (y-i)*75, 75, 75, greenHighlight);
            else if (board[x+i][y-i]->name.back() != name.back()) {
                DrawRectangle((x+i)*75, (y-i)*75, 75, 75, redHighlight);
                break;
            } else break;
        }
        for (int i = 1; i < 8-y; i++) {
            if (x-i < 0) break;
            if (board[x-i][y+i]->name.empty()) DrawRectangle((x-i)*75, (y+i)*75, 75, 75, greenHighlight);
            else if (board[x-i][y+i]->name.back() != name.back()) {
                DrawRectangle((x-i)*75, (y+i)*75, 75, 75, redHighlight);
                break;
            } else break;
        }
        for (int i = 1; i <= y; i++) {
            if (x-i < 0) break;
            if (board[x-i][y-i]->name.empty()) DrawRectangle((x-i)*75, (y-i)*75, 75, 75, greenHighlight);
            else if (board[x-i][y-i]->name.back() != name.back()) {
                DrawRectangle((x-i)*75, (y-i)*75, 75, 75, redHighlight);
                break;
            } else break;
        }
    }

    bool isValidMove(Piece* board[8][8], int startX, int startY, int destX, int destY) override {
        if (destX == startX && destY == startY) return false;
        
        if (destX == startX) {
            if (destY > startY) {
                for (int i = startY+1; i < destY; i++) {
                    if (!board[startX][i]->name.empty()) return false;
                }
            } else {
                for (int i = startY-1; i > destY; i--) {
                    if (!board[startX][i]->name.empty()) return false;
                }
            }
        } else if (destY == startY) {
            if (destX > startX) {
                for (int i = startX+1; i < destX; i++) {
                    if (!board[i][startY]->name.empty()) return false;
                }
            } else {
                for (int i = startX-1; i > destX; i--) {
                    if (!board[i][startY]->name.empty()) return false;
                }
            }
        } else if (abs(destX-startX) == abs(destY-startY)) {
            if (destX > startX && destY > startY) {
                for (int i = 1; i < abs(destX-startX); i++) {
                    if (!board[startX+i][startY+i]->name.empty()) return false;
                }
            } else if (destX > startX && destY < startY) {
                for (int i = 1; i < abs(destX-startX); i++) {
                    if (!board[startX+i][startY-i]->name.empty()) return false;
                }
            } else if (destX < startX && destY > startY) {
                for (int i = 1; i < abs(destX-startX); i++) {
                    if (!board[startX-i][startY+i]->name.empty()) return false;
                }
            } else if (destX < startX && destY < startY) {
                for (int i = 1; i < abs(destX-startX); i++) {
                    if (!board[startX-i][startY-i]->name.empty()) return false;
                }
            }
        } else return false;

        if (board[destX][destY]->name.empty() || board[destX][destY]->name.back() != name.back())
            return true;
            
        return false; 
    }
};

#endif /* SRC_PIECES_QUEEN_HPP */
