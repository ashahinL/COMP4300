#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <cstdint>
#include <optional>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "COMP4300 - ImGui + SFML");
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    bool showDemo = true;
    float clearColor[3] = {0.1f, 0.1f, 0.12f};

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                 event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("COMP4300 Controls");
        ImGui::Text("ImGui + SFML (CMake) example");
        ImGui::Checkbox("Show ImGui Demo", &showDemo);
        ImGui::ColorEdit3("Clear Color", clearColor);
        ImGui::End();

        if (showDemo)
        {
            ImGui::ShowDemoWindow(&showDemo);
        }

        window.clear(sf::Color(
            static_cast<std::uint8_t>(clearColor[0] * 255.0f),
            static_cast<std::uint8_t>(clearColor[1] * 255.0f),
            static_cast<std::uint8_t>(clearColor[2] * 255.0f)));
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}