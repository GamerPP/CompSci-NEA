#ifndef SRC_PIECES_KING_HPP
#define SRC_PIECES_KING_HPP
#include "../Piece.hpp"

class King : public Piece {
public:
    King(bool isWhite) {
        if (isWhite) name = "king_white";
        else name = "king_black";
    }
    ~King();

    void ShowMoves(Piece* board[8][8], int x, int y) override {
        DrawRectangle(x*75, y*75, 75, 75, greenHighlight);
        if (x + 1 < 8) {
            if (y+1 < 8 && board[x+1][y+1]->name.empty()) DrawRectangle((x+1)*75, (y+1)*75, 75, 75, greenHighlight);
            else if (board[x+1][y+1]->name.back() != name.back()) DrawRectangle((x+1)*75, (y+1)*75, 75, 75, redHighlight);
            
            if (board[x+1][y]->name.empty()) DrawRectangle((x+1)*75, y*75, 75, 75, greenHighlight);
            else if (board[x+1][y]->name.back() != name.back()) DrawRectangle((x+1)*75, y*75, 75, 75, redHighlight);
            
            if (y-1 >= 0 && board[x+1][y-1]->name.empty()) DrawRectangle((x+1)*75, (y-1)*75, 75, 75, greenHighlight);
            else if (board[x+1][y-1]->name.back() != name.back()) DrawRectangle((x+1)*75, (y-1)*75, 75, 75, redHighlight);            
        }
        
        if (board[x][y+1]->name.empty()) DrawRectangle(x*75, (y+1)*75, 75, 75, greenHighlight);
        else if (board[x][y+1]->name.back() != name.back()) DrawRectangle(x*75, (y+1)*75, 75, 75, redHighlight);
        
        if (board[x][y-1]->name.empty()) DrawRectangle(x*75, (y-1)*75, 75, 75, greenHighlight);
        else if (board[x][y-1]->name.back() != name.back()) DrawRectangle(x*75, (y-1)*75, 75, 75, redHighlight);

        if (x - 1 >= 0) {
            if (y+1 < 8 && board[x-1][y+1]->name.empty()) DrawRectangle((x-1)*75, (y+1)*75, 75, 75, greenHighlight);
            else if (board[x-1][y+1]->name.back() != name.back()) DrawRectangle((x-1)*75, (y+1)*75, 75, 75, redHighlight);
            
            if (board[x-1][y]->name.empty()) DrawRectangle((x-1)*75, y*75, 75, 75, greenHighlight);
            else if (board[x-1][y]->name.back() != name.back()) DrawRectangle((x-1)*75, y*75, 75, 75, redHighlight);
            
            if (y-1 >= 0 && board[x-1][y-1]->name.empty()) DrawRectangle((x-1)*75, (y-1)*75, 75, 75, greenHighlight);
            else if (board[x-1][y-1]->name.back() != name.back()) DrawRectangle((x-1)*75, (y-1)*75, 75, 75, redHighlight);
        }
    }

    bool isValidMove(Piece* board[8][8], int startX, int startY, int destX, int destY) override {
        if (board[destX][destY]->name.empty() || board[destX][destY]->name.back() != name.back()) {
            if (abs(destX - startX) <= 1 && abs(destY - startY) <= 1) return true;
        }   
        return false;        
    }
};

#endif /* SRC_PIECES_KING_HPP */
