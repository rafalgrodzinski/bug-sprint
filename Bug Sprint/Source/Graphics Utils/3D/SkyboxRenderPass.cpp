//
//  SkyboxRenderPass.cpp
//  Bug Sprint
//
//  Created by Rafal Grodzinski on 10/12/2016.
//  Copyright © 2016 UnalignedByte. All rights reserved.
//

#include "SkyboxRenderPass.h"

#include "Drawable.h"

using namespace std;


void SkyboxRenderPass::begin()
{
    glViewport(0, 0, viewWidth, viewHeight);

    glDisable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);
    glDepthMask(GL_FALSE);
}


void SkyboxRenderPass::draw()
{
    shaderProgram->use();

    for(shared_ptr<Instance> instance : instances) {
        if(shared_ptr<Drawable> drawable = dynamic_pointer_cast<Drawable>(instance)) {
            drawable->draw(shaderProgram);
        }
    }
}


void SkyboxRenderPass::end()
{
    glDepthMask(GL_TRUE);
    glCullFace(GL_FRONT);
    glEnable(GL_DEPTH_TEST);
}
