#include "include/texture-material.hh"

float Material::getKd() const
{
    return kd_;
}

float Material::getKs() const
{
    return ks_;
}

float Material::getKa() const
{
    return ka_;
}

Material TextureMaterial::getMaterial(Vector3 p) const
{
    return *material_;
}