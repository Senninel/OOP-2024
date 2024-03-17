#pragma once
class canvas
{
	char** form;
	int width, height;
public:
    // contructor will call the clear method
    canvas(int lines, int columns);

    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
    int ThrowError(int x, int y);
};

