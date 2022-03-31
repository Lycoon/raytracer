#include "include/texture-material.hh"

const float Components::getKd() const
{
    return kd_;
}

const float Components::getKs() const
{
    return ks_;
}

const float Components::getKa() const
{
    return ka_;
}

Components TextureMaterial::getComponents(Vector3 p) const
{
    return comps_;
}