#ifndef BOARD_H
#define BOARD_H

#include "Piece.CPP"
#include <iostream>

//-----------------------------------------Set Up Section:
void Default(int* rows, int* collums, piece_identifier** board );

void Default(int* rows, int* collums, piece_identifier** board, Piece piece );

void Default(int* current_row, int* collums, piece_identifier** board, char overload_char );

void Default(int* rows, int* collums, piece_identifier** board, int overload_int );

//-----------------------------------------Size Management Section:
void New_Collum(int* rows, int* collums, piece_identifier** board );

void New_Row(int* rows, int* collums, piece_identifier** board );

void Expand(int* rows, int* collums, piece_identifier** board );

void Remove_Collum(int* rows, int* collums, piece_identifier** board );

void Remove_Row(int* rows, int* collums, piece_identifier** board );

void Shrink(int* rows, int* collums, piece_identifier** board);

//-----------------------------------------Output Section:
void Output_Border(int* collums, const int* OUTPUT_LINES, char* border_parts );

void Output_Row(int* current_row, int* collums, const int* OUTPUT_LINES, char* border_parts, piece_identifier** board, Piece* Pieces );

void Output(int* rows, int* collums, const int* OUTPUT_LINES, char* border_parts, piece_identifier** board, Piece* Pieces );

//-----------------------------------------Input Handling Section:
bool Input_Sanitization(int* test_data, int* test_case );

bool Insertion_Trial(int* row, int* collum, piece_identifier** board, Piece piece );

void Insertion(int* row, int* collum, piece_identifier** board, Piece piece );


//-----------------------------------------Win Check:
void Check(int* start_row, int* start_collum, int* rows, int* collums, piece_identifier piece_type, piece_identifier** board, int** keyed_positions, int* points_so_far);


//-----------------------------------------Clean Up:
void Board_Wipe(int* rows, piece_identifier** array );

#endif