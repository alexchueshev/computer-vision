#ifndef COMPUTER_VISION_KERNEL_H
#define COMPUTER_VISION_KERNEL_H

#include <borders.h>
#include <vector>

namespace pi {
namespace kernels {
    class Kernel;

    class SeparableKernel;
}}

class pi::kernels::Kernel {

public:
    typedef std::vector<float> Array1d;

protected:
    int width;
    int height;

public:
    Kernel(int width, int height);

    virtual void apply(Img& src, const borders::Function& fBorder) = 0;

    virtual ~Kernel() = default;
};


class pi::kernels::SeparableKernel : public Kernel {

private:
    Array1d mRow;
    Array1d mCol;

public:
    SeparableKernel(const Array1d& mRow, const Array1d& mCol);

    SeparableKernel(Array1d&& mRow, Array1d&& mCol);

    void apply(Img& src, const borders::Function& fBorder) override;
};

#endif //COMPUTER_VISION_KERNEL_H
