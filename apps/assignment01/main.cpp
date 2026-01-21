#include <iostream>
#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "SegmentedShape.hpp"
#include "Rect.hpp"
#include "utils.hpp"

void segmentedShapesImGuiControl(std::vector<SegmentedShape> &shapes);
void rectShapesImGuiControl(std::vector<Rect> &rects);

int main()
{
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

    // Start drawing my Shapes
    auto arrSegmentedShapes = std::vector<SegmentedShape>{};
    arrSegmentedShapes.push_back(SegmentedShape{20.0f, 32, sf::Color::Green, 1.1f, 1.1f, 100.0f, 100.0f, std::string("CGreen")});
    arrSegmentedShapes.push_back(SegmentedShape{30.0f, 32, sf::Color::Blue, 1.2f, 1.2f, 200.0f, 200.0f, std::string("CBlue")});
    arrSegmentedShapes.push_back(SegmentedShape{50.0f, 32, sf::Color::Cyan, 1.3f, 1.3f, 300.0f, 300.0f, std::string("CCyan")});
    arrSegmentedShapes.push_back(SegmentedShape{50.0f, 3, sf::Color::Cyan, 1.4f, 1.4f, 400.0f, 400.0f, std::string("TCyan")});   // Triangle
    arrSegmentedShapes.push_back(SegmentedShape{50.0f, 6, sf::Color::Blue, 1.5f, 1.5f, 500.0f, 500.0f, std::string("HBlue")});   // Hexangular

    auto arrRect = std::vector<Rect>{};
    arrRect.push_back(Rect{50.0f, 50.0f, sf::Color::White, 1.6f, 1.6f, 600.0f, 600.0f, std::string("RWhite")});
    arrRect.push_back(Rect{10.0f, 70.0f, sf::Color::Blue, 1.7f, 1.7f, 150.0f, 350.0f, std::string("RBlue")});

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
            segmentedShapesImGuiControl(arrSegmentedShapes);
            rectShapesImGuiControl(arrRect);
            ImGui::EndTabBar();
        }

        ImGui::End();

        // Update Shapes
        for (auto &shape : arrSegmentedShapes)
            shape.update();

        for (auto &rec : arrRect)
            rec.update();

        window.clear();

        // Render
        // Draw Shapes
        for (auto &shape : arrSegmentedShapes)
            shape.draw(window);

        for (auto &rec : arrRect)
            rec.draw(window);

        ImGui::SFML::Render(window);
        window.display();
    }
    // Shutdown ImGui-SFML
    ImGui::SFML::Shutdown();

    return 0;
}

void segmentedShapesImGuiControl(std::vector<SegmentedShape> &shapes)
{
    const char *items[5] = {""};        // is just an estimate!
    static int item_selected_idx = 0;   // Here we store our selection data as an index.

    for (int i = 0; (i < shapes.size()) && (i < IM_ARRAYSIZE(items)); i++)
    {
        items[i] = shapes.at(i).name.c_str();
    }

    // Pass in the preview value visible before opening the combo (it could technically be different contents or not pulled from items[])
    const char *combo_preview_value = items[item_selected_idx];
    if (ImGui::BeginTabItem("SegmentedShapes"))
    {
        if (ImGui::BeginCombo("SegmentedShapes", combo_preview_value))
        {

            for (int i = 0; i < shapes.size(); i++)
            {
                auto is_selected = (item_selected_idx == i);
                if (ImGui::Selectable(items[i], is_selected))
                    item_selected_idx = i;

                // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
                if (is_selected)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }
        shapes.at(item_selected_idx).ImGuiControl();
        ImGui::EndTabItem();
    }
}

void rectShapesImGuiControl(std::vector<Rect> &shapes)
{
    const char *items[2] = {""};        // is just an estimate!
    static int item_selected_idx = 0;   // Here we store our selection data as an index.

    for (size_t i = 0; (i < shapes.size()) && (i < IM_ARRAYSIZE(items)); i++)
    {
        items[i] = shapes.at(i).name.c_str();
    }

    // Pass in the preview value visible before opening the combo (it could technically be different contents or not pulled from items[])
    const char *combo_preview_value = items[item_selected_idx];
    if (ImGui::BeginTabItem("Rectangles"))
    {
        if (ImGui::BeginCombo("RectShapes", combo_preview_value))
        {
            size_t i = 0;
            for (; i < shapes.size(); i++)
            {
                const bool is_selected = (item_selected_idx == i);
                if (ImGui::Selectable(items[i], is_selected))
                    item_selected_idx = i;

                // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
                if (is_selected)
                    ImGui::SetItemDefaultFocus();
            }

            ImGui::EndCombo();
        }
        shapes.at(item_selected_idx).ImGuiControl();
        ImGui::EndTabItem();
    }
}