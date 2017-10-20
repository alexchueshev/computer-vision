#ifndef COMPUTER_VISION_IMG_H
#define COMPUTER_VISION_IMG_H

#include <memory>
#include <cassert>

namespace pi {
    class Img;
}

class pi::Img
{

protected:
    int _width;
    int _height;
    int _channels;
    int _step;
    std::unique_ptr<float[]> _data;

public:
    Img() = default;

    Img(int height, int width, int channels);

    Img(const Img& img);

    Img(Img&& img) = default;

    Img& operator=(const Img& img);

    Img& operator=(Img&& img) = default;

    const float* data() const;

    float* data();

    const float* ptr(int row) const;

    float* ptr(int row);

    const float* at(int row, int col) const;

    float* at(int row, int col);

    bool isContinuous() const;

    int width() const;

    int height() const;

    int channels() const;

    int step() const;

    int imageSize() const;

    int dataSize() const;

    Img clone() const;

    ~Img() = default;
};

#endif // COMPUTER_VISION_IMG_H
