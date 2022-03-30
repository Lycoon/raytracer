#include "include/mengen_sponge.hh"

#include "include/uniform-texture.hh"

/**
 * @brief Checks whether a ray hits a sphere
 *
 * @param Ray
 * @return distance to the hit, -1 if no intersection found (float)
 */
float Sponge::doesIntersect(Ray ray)
{
    float min = INFINITY;

    for (size_t i = 0; i < boxes_.size(); i++)
    {
        Box b = boxes_[i];
        float dist = b.doesIntersect(ray);
        if (dist > 0 && dist < min)
        {
            min = dist;
            latest_hit_ = &boxes_[i];
        }
    }

    return min == INFINITY ? -1 : min;
}

Vector3 Sponge::getNormal(Point3 p)
{
    return latest_hit_->getNormal(p);
}

TextureMaterial *Sponge::getTexture(Point3 p)
{
    return texture_;
}

ostream &operator<<(ostream &out, Sponge &sphere)
{
    out << "Sponge(" << endl
        << ")";

    return out;
}

void recursion(vector<Box> &boxes, unsigned int rec, Point3 &p_min, Point3 p_max, UniformTexture *texture)
{
    if (rec <= 0)
    {
        Box b = {p_min, p_max, texture};
        boxes.push_back(b);
        return;
    }

    Vector3 diff = p_max - p_min;
    float step_x = diff.getPosition().getX() / 3.0f;
    float step_y = diff.getPosition().getY() / 3.0f;
    float step_z = diff.getPosition().getZ() / 3.0f;

    Point3 step_one = {step_x, step_y, step_z};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                if ((i == 1 && j == 1) || (j == 1 && k == 1) | (k == 1 && i == 1))
                {
                    continue;
                }

                Point3 p1 = p_min;
                p1 += {i * step_x, j * step_y, k * step_z};

                recursion(boxes, rec - 1, p1, p1 + step_one, texture);
            }
        }
    }
}
