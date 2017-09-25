#include "imageprocessing.h"

using namespace pi;

ImageProcessing::ImageProcessing(const Img& img)
    : _img(img) {
}

ImageProcessing::ImageProcessing(Img&& img)
    : _img(std::move(img)) {
}

ImageProcessing::ImageProcessing(const std::string& path,
                                 const LoadFunction& loadFunction)
    : _img(loadFunction(path))
{
}

ImageProcessing& ImageProcessing::load(const std::string& path,
                                       const LoadFunction& loadFunction) {
    _img = loadFunction(path);

    return *this;
}

ImageProcessing& ImageProcessing::opts(std::initializer_list<OperationFunction> opts) {
    for(const auto &opt: opts) {
        opt(_img);
    }

    return *this;
}

ImageProcessing& ImageProcessing::filters(std::initializer_list<
                                          std::pair<borders::BorderTypes,
                                          FilterFunction>> filters) {
    for(const auto &filter: filters) {
        filter.second(filter.first, _img);
    }

    return *this;
}

ImageProcessing& ImageProcessing::save(const std::string& path,
                                       const SaveFunction& saveFunction) {
    saveFunction(path, _img);

    return *this;
}

ImageProcessing& ImageProcessing::render(const std::string& windowName,
                                         const RenderFunction& renderFunction) {
    renderFunction(windowName, _img);

    return *this;
}

ImageProcessing ImageProcessing::clone() {
    ImageProcessing imageProcessing(_img.clone());

    return imageProcessing;
}

Img ImageProcessing::image() const {
    return _img;
}