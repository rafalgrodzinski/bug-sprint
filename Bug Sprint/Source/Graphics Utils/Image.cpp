//
//  Image.cpp
//  Bug Sprint
//
//  Created by Rafal Grodzinski on 07/11/2016.
//  Copyright © 2016 UnalignedByte. All rights reserved.
//

#include "Image.h"

#include "SystemUtils.h"

using namespace std;


Image::Image(const std::string &fileName)
{
    ImageData imageData = SystemUtils::imageDataForFileName(fileName);
    if(imageData.rgbaImageData == nullptr)
        throw string("Could not load image " + fileName);

    width = imageData.width;
    height = imageData.height;
    rgbaData = unique_ptr<GLubyte>(imageData.rgbaImageData);
}


Image::Image(const std::string &text, const std::string &fontFileName, GLfloat fontSize, const Color &fontColor)
{
    ImageData imageData = SystemUtils::imageDataForText(text, fontFileName, fontSize, fontColor[0], fontColor[1], fontColor[2]);
    if(imageData.rgbaImageData == nullptr)
        throw string("Could not render text" + text);

    width = imageData.width;
    height = imageData.height;
    rgbaData = unique_ptr<GLubyte>(imageData.rgbaImageData);
}


GLint Image::getWidth() const
{
    return width;
}


GLint Image::getHeight() const
{
    return height;
}


GLubyte *Image::getData() const
{
    return rgbaData.get();
}

