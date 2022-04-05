#include "../../core/include/scene-object.hh"

class Plane : public SceneObject
{
public:
    Plane(Vector3 *position, Vector3 *normal, UniformTexture *texture)
        : SceneObject(texture, "plane"), position_(position)
    {
        normal->normalize();
        normal_ = normal;
    }

    const Vector3 &getPosition() const;

    float doesIntersect(Ray ray);
    Vector3 &getNormal(Vector3 p);
    TextureMaterial *getTexture(Vector3 p);

private:
    Vector3 *position_;
    Vector3 *normal_;
};