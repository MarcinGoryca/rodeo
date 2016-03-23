/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\texturemanager.h"

using namespace mg::io;
using namespace mg::renderer;

namespace mg
{
namespace core
{
int TextureManager::s_texture_count_ = 0;

void TextureManager::bind(ui& tid)
{
    //glBindTexture(GL_TEXTURE_2D, tid);
}

//--------------------------------------------------------------------------------------------------
void TextureManager::clean()
{
    texture_->reset();
}

//--------------------------------------------------------------------------------------------------
void TextureManager::load(renderer::Image* img, const char* filename, ui& tid)
{
    texture_->load(img, filename, tid);

    s_texture_count_ += 1;

    bind(tid);
}

//--------------------------------------------------------------------------------------------------
void TextureManager::reset()
{
    texture_->reset();
}

//--------------------------------------------------------------------------------------------------
void TextureManager::load()
{

}

//--------------------------------------------------------------------------------------------------
ui TextureManager::loadDDS(const char* filename)
{
    texObj_.push_back(1);

    ui index = texObj_[0];

    image_data_[index] = new FileDDS;
    texture_->load(image_data_[index], filename, texture_id_[index]);

    s_texture_count_ += 1;

    delete image_data_[index];

    return texture_id_[index];
}

//--------------------------------------------------------------------------------------------------
ui TextureManager::loadTGA(const char* filename)
{
    ui index = s_texture_count_;
    image_data_[index] = new FileTGA;
    texture_->load(image_data_[index], filename, texture_id_[index]);

    s_texture_count_ += 1;

    delete image_data_[index];

    return texture_id_[index];
}
}    // end of core namespace
}    // end of mg namespace