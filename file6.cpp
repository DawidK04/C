#include <vector>
#include <iostream>

class Canvas {
public:
    Canvas(size_t w, size_t h) : width(w), height(h), grid(h, std::vector<bool>(w, false)) {}
    
    void set(size_t x, size_t y) {
        if (x < width && y < height)
            grid[y][x] = true;
    }

    void print() const {
        for (const auto& row : grid) {
            for (bool c : row) {
                std::cout << (c ? "\xE2\x96\x88" : " ");
            }
            std::cout << std::endl;
        }
    }

    size_t getWidth() const {
        return width;
    }

    size_t getHeight() const {
        return height;
    }

private:
    std::vector<std::vector<bool>> grid;
    size_t width, height;
};

class Painter {
protected:
    Canvas& canvas; /* Kompozycja */
public:
    Painter(Canvas& c) : canvas(c) {}
    virtual void paint() = 0;
};

class VerticalLinePainter : public Painter {
    int v;
public:
    VerticalLinePainter(Canvas& c, int x)
    : Painter(c), v(x) {}

    void paint() {
        for (size_t y = 0; y < canvas.getHeight(); y++) {
            canvas.set(v, y);
        }
    }
};

class HorizontalLinePainter : public Painter {
    int v;
public:
    HorizontalLinePainter(Canvas& c, int y)
    : Painter(c), v(y) {}

    void paint() {
        for (size_t x = 0; x < canvas.getWidth(); x++) {
            canvas.set(x, v);
        }
    }
};

class RectanglePainter : public Painter {
public:
    RectanglePainter(Canvas& c)
    : Painter(c) {}

    void paint() {
        size_t w = canvas.getWidth();
        size_t h = canvas.getHeight();

        for (size_t x = 0; x < w; x++) {
            canvas.set(x, 0);
            canvas.set(x, h - 1);
        }

        for (size_t y = 1; y + 1 < h; y++) {
            canvas.set(0, y);
            canvas.set(w - 1, y);
        }
    }
};

int main() {
    Canvas canvas(10, 5);

    VerticalLinePainter PaintV(canvas, 4);
    HorizontalLinePainter PaintH(canvas, 2);
    RectanglePainter PaintR(canvas);

    PaintV.paint();
    PaintH.paint();
    PaintR.paint();
    canvas.print();
    return 0;
}
