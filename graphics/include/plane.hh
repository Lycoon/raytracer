#include "../../core/include/scene-object.hh"

class Plane : public SceneObject
{
public:
    Plane(Point3 position, Vector3 normal, UniformTexture *texture)
        : SceneObject(texture)
        , position_(position)
    {
        normal.normalize();
        normal_ = normal;
    }

    const Point3 &getPosition() const;

    float doesIntersect(Ray ray);
    Vector3 getNormal(Point3 p);
    TextureMaterial *getTexture(Point3 p);

private:
    Point3 position_;
    Vector3 normal_;
};