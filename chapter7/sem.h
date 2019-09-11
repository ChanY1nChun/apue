#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef _SEM_H
#define _SEM_H

int c(int count);

void s(int id, int semnum, int val);

int g(int id, int semnum);

void d(int id);

void P(int id, int semnum);

void V(int id, int semnum);

#endif
