#include "include/turtle.hh"

void Turtle::execute(Scene *scene, string filename)
{
    Grammar grammar;
    string parsed = grammar.parse(filename);
    float angle = grammar.getAngle();

    auto material = new Material(0.8f, 0.7f, 0.2f);
    auto texture = new UniformTexture(new Color(0, 255, 0), material);

    for (char c : parsed)
    {
        if (c == 'F')
        {
            moveForward(0.4);
            Sphere *sphere = new Sphere(0.15, new Vector3(position_), texture);
            scene->addObject(sphere);
        }
        else if (c == 'f')
        {
            polygon_.push_back(position_);
            moveForward(0.4);
        }
        else if (c == '+')
            rotateUp(angle); // left
        else if (c == '-')
            rotateUp(-angle); // right
        else if (c == '&')
            rotateLeft(angle); // down
        else if (c == '^')
            rotateLeft(-angle); // up
        else if (c == '/')
            rotateHead(angle); // pitch right
        else if (c == '\\')
            rotateHead(-angle); // pitch left
        else if (c == '|')
            rotateUp(180); // U-turn
        else if (c == '{')
            polygon_.clear();
        else if (c == '}')
            drawPolygon(scene, texture);
        else if (c == '[')
            setState();
        else if (c == ']')
            useState();
    }
}

void Turtle::drawPolygon(Scene *scene, UniformTexture *texture)
{
    for (int i = 0; i < polygon_.size(); i += 3)
    {
        Vector3 *v0 = new Vector3(polygon_[i].X(), polygon_[i].Y(), polygon_[i].Z());
        Vector3 *v1 = new Vector3(polygon_[i + 1].X(), polygon_[i + 1].Y(), polygon_[i + 1].Z());
        Vector3 *v2 = new Vector3(polygon_[i + 2].X(), polygon_[i + 2].Y(), polygon_[i + 2].Z());

        scene->addObject(new Triangle(v0, v1, v2, texture));
    }
}

void Turtle::setState()
{
    TurtleState *state = new TurtleState{
        position_,
        head_,
        left_,
        up_};

    states_.push_back(state);
}

void Turtle::useState()
{
    auto last = states_.back();

    position_ = last->position_;
    head_ = last->head_;
    left_ = last->left_;
    up_ = last->up_;

    states_.pop_back();
}

void Turtle::rotateUp(float angle)
{
    float a = degToRad(angle);
    Vector3 head = head_ * cos(a) + left_ * -sin(a);
    Vector3 left = head_ * sin(a) + left_ * cos(a);

    head_ = head;
    left_ = left;

    head_.normalize();
    left_.normalize();
}

void Turtle::rotateLeft(float angle)
{
    float a = degToRad(angle);
    Vector3 head = head_ * cos(a) + up_ * sin(a);
    Vector3 up = head_ * -sin(a) + up_ * cos(a);

    head_ = head;
    up_ = up;

    head_.normalize();
    up_.normalize();
}

void Turtle::rotateHead(float angle)
{
    float a = degToRad(angle);
    Vector3 left = left_ * cos(a) + up_ * sin(a);
    Vector3 up = left_ * -sin(a) + up_ * cos(a);

    left_ = left;
    up_ = up;

    left_.normalize();
    up_.normalize();
}

void Turtle::moveForward(float distance)
{
    position_ += head_ * distance;
}

Vector3 &Turtle::getPosition()
{
    return position_;
}

Vector3 &Turtle::getHead()
{
    return head_;
}

Vector3 &Turtle::getLeft()
{
    return left_;
}

Vector3 &Turtle::getUp()
{
    return up_;
}