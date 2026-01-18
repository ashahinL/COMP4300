#include "SegmentedShape.hpp"
#include "utils.hpp"

SegmentedShape::SegmentedShape(float r, int s, sf::Color c, float sx, float sy, float px, float py, std::string _name)
    : radius(r), segments(s), color(c), speedX(sx), speedY(sy), posX(px), posY(py), name(_name), circleShape(radius, segments)
{
    circleShape.setFillColor(color);
    circleShape.setPosition(sf::Vector2f(px, py));
}

void SegmentedShape::update()
{
    // Update circleShape properties
    circleShape.setRadius(radius);
    circleShape.setPointCount(segments);
    circleShape.setFillColor(color);

    // Update circle properties
    sf::Vector2f pos = circleShape.getPosition();
    pos.x += speedX;
    pos.y += speedY;

    // Screen boundaries
    if (pos.x <= 0 || pos.x + 2 * radius >= WINDOW_WIDTH)
    {
        speedX = -speedX;
    }
    if (pos.y <= 0 || pos.y + 2 * radius >= WINDOW_HEIGHT)
    {
        speedY = -speedY;
    }

    circleShape.setPosition(pos);
}

void SegmentedShape::ImGuiControl()
{
    ImGui::Checkbox("Draw", &isDraw);
    ImGui::SliderFloat("Radius", &radius, 10.0f, 200.0f);
    ImGui::ColorEdit4("Color", reinterpret_cast<float *>(&color));
    ImGui::SliderFloat("Speed X", &speedX, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Y", &speedY, -5.0f, 5.0f);
    char buf[256] = {};
    strncpy(buf, name.c_str(), sizeof(buf) - 1);
    if (ImGui::InputText("Name", buf, IM_ARRAYSIZE(buf))) {
        name = std::string(buf);
    }
}

void SegmentedShape::draw(sf::RenderWindow &window)
{
    if (isDraw)
        window.draw(circleShape);
}