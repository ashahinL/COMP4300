#include "Component.hpp"

PositionComponent::PositionComponent(float xPos, float yPos) : x(xPos), y(yPos)
{
}

float PositionComponent::getX() const
{
	return x;
}

float PositionComponent::getY() const
{
	return y;
}

void PositionComponent::setX(float xPos)
{
	x = xPos;
}

void PositionComponent::setY(float yPos)
{
	y = yPos;
}

VelocityComponent::VelocityComponent(float vX, float vY) : vx(vX), vy(vY)
{
}

float VelocityComponent::getVX() const
{
	return vx;
}

float VelocityComponent::getVY() const
{
	return vy;
}

void VelocityComponent::setVX(float vX)
{
	vx = vX;
}

void VelocityComponent::setVY(float vY)
{
	vy = vY;
}

ColorComponent::ColorComponent(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
	: r(red), g(green), b(blue), a(alpha)
{
}

unsigned char ColorComponent::getR() const
{
	return r;
}

unsigned char ColorComponent::getG() const
{
	return g;
}

unsigned char ColorComponent::getB() const
{
	return b;
}

unsigned char ColorComponent::getA() const
{
	return a;
}

void ColorComponent::setR(unsigned char red)
{
	r = red;
}

void ColorComponent::setG(unsigned char green)
{
	g = green;
}

void ColorComponent::setB(unsigned char blue)
{
	b = blue;
}

void ColorComponent::setA(unsigned char alpha)
{
	a = alpha;
}

