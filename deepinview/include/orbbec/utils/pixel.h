#ifndef PIXEL_H_
#define PIXEL_H_

class Pixel {
public:
    Pixel();
    Pixel(int x, int y);
    ~Pixel();
    int x;
    int y;
    inline bool operator == (const Pixel &pixel) const{
        return ( (pixel.x == x) && (pixel.y == y) );
    }
private:
};

#endif // PIXEL_H_
