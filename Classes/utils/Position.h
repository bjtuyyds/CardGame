#pragma once


class Position {
public:
	Position(int _x, int _y) :x(_x), y(_y) {};
	Position(): x(0), y(0) {};
	int x;
	int y;
};