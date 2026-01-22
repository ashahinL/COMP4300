#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "Entity.hpp"
#include "utils.hpp"

int main()
{
    // Simple Entity/Component usage
    Entity player;
    player.setName("Player");
    player.addComponent<PositionComponent>(100.0f, 200.0f);
    player.addComponent<VelocityComponent>(1.5f, -0.5f);
    player.addComponent<ColorComponent>(255, 0, 0, 255);
    if (player.hasComponent<PositionComponent>())
    {
        auto &pos = player.getComponent<PositionComponent>();
        std::cout << player.getName() << " position: (" << pos.getX() << ", " << pos.getY() << ")\n";
    }

    // Create SFML RenderWindow
    auto window = sf::RenderWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "SFML + ImGui Example");
    window.setFramerateLimit(60);

    // Initialize ImGui-SFML
    if (!ImGui::SFML::Init(window))
    {
        return -1;   // Return error if ImGui-SFML initialization fails
    }

    auto deltaClock = sf::Clock{};

    // ImGui style and scaling
    ImGui::GetStyle().ScaleAllSizes(2.0f);
    ImGui::GetIO().FontGlobalScale = 2.0f;

    // Main loop
    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (auto *keyPressedEvent = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressedEvent->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            }
            // Process ImGui events
            ImGui::SFML::ProcessEvent(window, *event);
        }

        // ImGui Update
        ImGui::SFML::Update(window, deltaClock.restart());

        // ImGui window
        ImGui::Begin("Control Panel");
        if (ImGui::BeginTabBar("MyTabBar"))
        {
            ImGui::EndTabBar();
        }

        ImGui::End();

        // Update Shapes
        window.clear();

        // Render
        // Draw Shapes
        ImGui::SFML::Render(window);
        window.display();
    }
    // Shutdown ImGui-SFML
    ImGui::SFML::Shutdown();

    return 0;
}