#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

class SegmentedShape
{
    bool isDraw = true;
    float radius;
    const int segments;
    ImVec4 color;
    float speedX, speedY;
    float posX, posY;
    sf::CircleShape circleShape;

  public:
    std::string name;
    SegmentedShape(float r, int s, sf::Color c, float sx, float sy, float px, float py, std::string _name);
    void update();
    void ImGuiControl();
    void draw(sf::RenderWindow &window);
};