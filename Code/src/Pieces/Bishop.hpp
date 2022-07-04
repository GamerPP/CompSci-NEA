#ifndef SRC_PIECES_BISHOP_HPP
#define SRC_PIECES_BISHOP_HPP
#include "../Piece.hpp"

class Bishop : public Piece {
public:
    Bishop(bool isWhite) {
        if (isWhite) name = "bishop_white";
        else name = "bishop_black";
    }
    ~Bishop();

    void ShowMoves(Piece* board[8][8], int x, int y) override {
        DrawRectangle(x*75, y*75, 75, 75, greenHighlight);
        for (int i = 1; i <= 8-y; i++) {
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
        for (int i = 1; i <= 8-y; i++) {
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
        if (startX == destX && startY == destY) return false;
        if (abs(startX - destX) == abs(startY - destY)) {
            if (startX - destX > 0) { // left
                if (startY - destY > 0) { // up
                    for (int i = 1; i < startX - destX; i++) {
                        if (board[startX-i][startY-i]->name.empty()) continue;
                        else return false;
                    }
                } else { // down
                    for (int i = 1; i < startX - destX; i++) {
                        if (board[startX-i][startY+i]->name.empty()) continue;
                        else return false;
                    }
                }
            } else { // right
                if (startY - destY > 0) { // up
                    for (int i = 1; i < abs(startX - destX); i++) {
                        if (board[startX+i][startY-i]->name.empty()) continue;
                        else return false;
                    }
                } else { // down
                    for (int i = 1; i < abs(startX - destX); i++) {
                        if (board[startX+i][startY+i]->name.empty()) continue;
                        else return false;
                    }
                }
            }
            if (board[destX][destY]->name.empty() || board[destX][destY]->name.back() != name.back()) return true;
        }
        return false;        
    }
};

#endif /* SRC_PIECES_BISHOP_HPP */
