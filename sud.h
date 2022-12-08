#ifndef SUD_H
#define SUD_H

void createSolution(int solution[9][9]);
void createPuzzle();
void generateBoard(int solution[9][9], int startX, int startY);
void makeBoard(int solution[9][9]);
bool validBoard(int solution[9][9]);
void printBoard(int solution[9][9]);
void makePuzzle(int presetSolution[9][9]);
bool isFull(int solution[9][9]);

#endif
