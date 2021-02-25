#ifndef SLIDE_LINE_H_
#define SLIDE_LINE_H_

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#include <stdio.h>
#include <stdbool.h>

int slide_line(int *line, size_t size, int direction);
void push_Left(int *line, int size);
void compress_Left(int *line, int size);
void push_Right(int *line, int size);
void compress_Right(int *line, int size);

#endif /* SLIDE_LINE_H_ */
