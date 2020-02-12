#pragma once
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <thread>
#include <fstream>

void GotoXY(int column, int line);
void resizeConsole(int width, int height);
void FixConsoleWindow();
void textcolor(int color);
void setcursor(bool visible);
void postionConsole();