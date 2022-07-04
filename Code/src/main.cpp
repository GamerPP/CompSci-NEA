#include <iostream>
#include <thread>
#include <map>
#include <raylib.h>

#include "Math.hpp"
#include "Piece.hpp"
#include "Pieces/Pieces.hpp"

void LoadTextures(std::map<std::string, Texture2D>& textureCache);
void LoadBoard(Piece* board[8][8]);

int main() {
    Piece* board[8][8];
    while (true) {
        std::cout << "Welcome to chess!\n";

        InitWindow(600, 600, "Chess");

        std::map<std::string, Texture2D> textureCache;
        LoadTextures(textureCache);

        LoadBoard(board);

        Math::Vec2<int> selectedPiece(2, 0);
        int step = 75;
        while (true) {
            if (WindowShouldClose()) goto endGame;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Math::Vec2<int> newSelection = Math::Vec2<int>(GetMouseX() / step, GetMouseY() / step);
                

                if (board[selectedPiece.x][selectedPiece.y]->isValidMove(board, selectedPiece.x, selectedPiece.y, newSelection.x, newSelection.y)) {
                    board[selectedPiece.x][selectedPiece.y]->firstMove = false;
                    delete board[newSelection.x][newSelection.y];
                    board[newSelection.x][newSelection.y] = board[selectedPiece.x][selectedPiece.y];
                    board[selectedPiece.x][selectedPiece.y] = new Piece("");
                    selectedPiece = newSelection;
                } 
                else if (board[newSelection.x][newSelection.y]->name != "")
                    selectedPiece = newSelection;
            }

            BeginDrawing();
                ClearBackground(BLACK);
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if ((i + j) % 2 == 0)
                            DrawRectangle(i * step, j * step, step, step, LIGHTGRAY);
                        else
                            DrawRectangle(i * step, j * step, step, step, DARKGRAY);
                    }
                }
                if (selectedPiece.x != -1) board[selectedPiece.x][selectedPiece.y]->ShowMoves(board, selectedPiece.x, selectedPiece.y);

                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (board[i][j]->name != "") {
                            //std::cout << board[i][j]->name << " at " << i << " " << j << "\n";
                            DrawTexture(textureCache[board[i][j]->name], i * step, j * step, WHITE);
                        }
                    }
                }
            EndDrawing();

            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
endGame:
        CloseWindow();
    }

exit:
    CloseWindow();
    return 0;
}

void LoadTextures(std::map<std::string, Texture2D>& textureCache) {
    Image pawn_white = LoadImage("Resources/pawn_white.png");
    ImageResize(&pawn_white, 75, 75);
    textureCache["pawn_white"] = LoadTextureFromImage(pawn_white);
    UnloadImage(pawn_white);

    Image pawn_black = LoadImage("Resources/pawn_black.png");
    ImageResize(&pawn_black, 75, 75);
    textureCache["pawn_black"] = LoadTextureFromImage(pawn_black);
    UnloadImage(pawn_black);

    Image rook_white = LoadImage("Resources/rook_white.png");
    ImageResize(&rook_white, 75, 75);
    textureCache["rook_white"] = LoadTextureFromImage(rook_white);
    UnloadImage(rook_white);

    Image rook_black = LoadImage("Resources/rook_black.png");
    ImageResize(&rook_black, 75, 75);
    textureCache["rook_black"] = LoadTextureFromImage(rook_black);
    UnloadImage(rook_black);

    Image knight_white = LoadImage("Resources/knight_white.png");
    ImageResize(&knight_white, 75, 75);
    textureCache["knight_white"] = LoadTextureFromImage(knight_white);
    UnloadImage(knight_white);

    Image knight_black = LoadImage("Resources/knight_black.png");
    ImageResize(&knight_black, 75, 75);
    textureCache["knight_black"] = LoadTextureFromImage(knight_black);
    UnloadImage(knight_black);

    Image bishop_white = LoadImage("Resources/bishop_white.png");
    ImageResize(&bishop_white, 75, 75);
    textureCache["bishop_white"] = LoadTextureFromImage(bishop_white);
    UnloadImage(bishop_white);

    Image bishop_black = LoadImage("Resources/bishop_black.png");
    ImageResize(&bishop_black, 75, 75);
    textureCache["bishop_black"] = LoadTextureFromImage(bishop_black);
    UnloadImage(bishop_black);

    Image queen_white = LoadImage("Resources/queen_white.png");
    ImageResize(&queen_white, 75, 75);
    textureCache["queen_white"] = LoadTextureFromImage(queen_white);
    UnloadImage(queen_white);

    Image queen_black = LoadImage("Resources/queen_black.png");
    ImageResize(&queen_black, 75, 75);
    textureCache["queen_black"] = LoadTextureFromImage(queen_black);
    UnloadImage(queen_black);

    Image king_white = LoadImage("Resources/king_white.png");
    ImageResize(&king_white, 75, 75);
    textureCache["king_white"] = LoadTextureFromImage(king_white);
    UnloadImage(king_white);

    Image king_black = LoadImage("Resources/king_black.png");
    ImageResize(&king_black, 75, 75);
    textureCache["king_black"] = LoadTextureFromImage(king_black);
    UnloadImage(king_black);
}

void LoadBoard(Piece* board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 7) {
                if (i == 0) {
                    board[i][j] = new Rook(true);
                } else if (i == 1) {
                    board[i][j] = new Knight(true);
                } else if (i == 2) {
                    board[i][j] = new Bishop(true);
                } else if (i == 3) {
                    board[i][j] = new King(true);
                } else if (i == 4) {
                    board[i][j] = new Queen(true);
                } else if (i == 5) {
                    board[i][j] = new Bishop(true);
                } else if (i == 6) {
                    board[i][j] = new Knight(true);
                } else if (i == 7) {
                    board[i][j] = new Rook(true);
                }
            } else if (j == 0) {
                if (i == 0) {
                    board[i][j] = new Rook(false);
                } else if (i == 1) {
                    board[i][j] = new Knight(false);
                } else if (i == 2) {
                    board[i][j] = new Bishop(false);
                } else if (i == 3) {
                    board[i][j] = new King(false);
                } else if (i == 4) {
                    board[i][j] = new Queen(false);
                } else if (i == 5) {
                    board[i][j] = new Bishop(false);
                } else if (i == 6) {
                    board[i][j] = new Knight(false);
                } else if (i == 7) {
                    board[i][j] = new Rook(false);
                }
            } else if (j == 6) {
                board[i][j] = new Pawn(true);
            } else if (j == 1) {
                //board[i][j] = new Piece("");
                board[i][j] = new Pawn(false);
            } 
            else {
                board[i][j] = new Piece("");
            }
        }
    }
}
