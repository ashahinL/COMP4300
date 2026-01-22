#ifndef COMPONENT_HPP
#define COMPONENT_HPP

struct Component
{
  public:
    bool exists = false;
};

struct PositionComponent : public Component
{
    float x = 0.0f;
    float y = 0.0f;
    PositionComponent() = default;
    PositionComponent(float xPos, float yPos);
    float getX() const;
    float getY() const;
    void setX(float xPos);
    void setY(float yPos);
};

struct VelocityComponent : public Component
{
    float vx = 0.0f;
    float vy = 0.0f;
    VelocityComponent() = default;
    VelocityComponent(float vX, float vY);
    float getVX() const;
    float getVY() const;
    void setVX(float vX);
    void setVY(float vY);
};

struct ColorComponent : public Component
{
    unsigned char r = 255;
    unsigned char g = 255;
    unsigned char b = 255;
    unsigned char a = 255;
    ColorComponent() = default;
    ColorComponent(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
    unsigned char getR() const;
    unsigned char getG() const;
    unsigned char getB() const;
    unsigned char getA() const;
    void setR(unsigned char red);
    void setG(unsigned char green);
    void setB(unsigned char blue);
    void setA(unsigned char alpha);
};

#endif   // COMPONENT_HPP