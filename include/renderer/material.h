/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_MATERIAL_H_
#define MG_RENDERER_MATERIAL_H_

namespace mg
{
namespace renderer
{
class Material
{
public:
    Material();
    ~Material(){}

    inline void setSpecular(float r, float g, float b, float a)
    {
        specular_[0] = r;
        specular_[1] = g;
        specular_[2] = b;
        specular_[3] = a;
    }

    inline void setAmbient(float r, float g, float b, float a)
    {
        ambient_[0] = r;
        ambient_[1] = g;
        ambient_[2] = b;
        ambient_[3] = a;
    }

    inline void setDiffuse(float r, float g, float b, float a)
    {
        diffuse_[0] = r;
        diffuse_[1] = g;
        diffuse_[2] = b;
        diffuse_[3] = a;
    }

    inline void setShininess(float ns)
    {
        shininess_[0] = ns;
    }

    const float* getSpecular()const { return &specular_[0]; }
    const float* getAmbient()const { return &ambient_[0]; }
    const float* getDiffuse()const { return &diffuse_[0]; }
    const float* getShininess()const { return &shininess_[0]; }

private:
    float specular_[4];
    float ambient_[4];
    float diffuse_[4];
    float shininess_[1];
};
}    // end of renderer namespace
}    // end of mg namespace
#endif