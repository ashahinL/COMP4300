#include "Rect.hpp"
#include "utils.hpp"

Rect::Rect(float w, float h, sf::Color c, float sx, float sy, float px, float py, std::string _name)
    : width(w), height(h), speedX(sx), speedY(sy), posX(px), posY(py), color(c), name(_name), rectShape(sf::Vector2f(width, height))
{
    rectShape.setFillColor(color);
    rectShape.setPosition(sf::Vector2f(px, py));
}

void Rect::update()
{
    // Update rectShape properties
    rectShape.setSize(sf::Vector2f(width, height));
    rectShape.setFillColor(color);

    // Update circle properties
    sf::Vector2f pos = rectShape.getPosition();
    pos.x += speedX;
    pos.y += speedY;

    // Screen boundaries
    if (pos.x <= 0 || pos.x + width >= WINDOW_WIDTH)
    {
        speedX = -speedX;
    }
    if (pos.y <= 0 || pos.y + height >= WINDOW_HEIGHT)
    {
        speedY = -speedY;
    }

    rectShape.setPosition(pos);
}

void Rect::ImGuiControl()
{
    ImGui::Checkbox("Draw", &isDraw);
    ImGui::SliderFloat("Width", &width, 10.0f, 200.0f);
    ImGui::SliderFloat("Height", &height, 10.0f, 200.0f);
    ImGui::ColorEdit4("Color", reinterpret_cast<float *>(&color));
    ImGui::SliderFloat("Speed X", &speedX, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Y", &speedY, -5.0f, 5.0f);
    char buf[256] = {};
    strncpy(buf, name.c_str(), sizeof(buf) - 1);
    if (ImGui::InputText("Name", buf, IM_ARRAYSIZE(buf))) {
        name = std::string(buf);
    }
}

void Rect::draw(sf::RenderWindow &window)
{
    if (isDraw)
        window.draw(rectShape);
}