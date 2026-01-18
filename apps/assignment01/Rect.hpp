#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "vector"

class Rect
{
    bool isDraw = true;
    float width, height;
    float speedX, speedY;
    float posX, posY;
    ImVec4 color;
    sf::RectangleShape rectShape;

  public:
    std::string name;
    Rect(float w, float h, sf::Color c, float sx, float sy, float px, float py, std::string _name);
    void update();
    void ImGuiControl();
    void draw(sf::RenderWindow &window);
};