#include <SFML/Graphics.hpp>

#include <optional>
#include <string>

#include "Game.h"

namespace
{
    constexpr unsigned int WindowWidth  = 600;
    constexpr unsigned int WindowHeight = 700;

    constexpr float UiHeight  = 80.f;
    constexpr float BoardTop  = UiHeight;
    constexpr float BoardSize = 600.f;
    constexpr float CellSize  = BoardSize / 3.f;

    constexpr float LineThickness  = 6.f;
    constexpr float MarkThickness  = 10.f;
    constexpr float MarkMargin     = CellSize * 0.20f;

    bool cellFromPoint(sf::Vector2f p, int& row, int& col)
    {
        if (p.x < 0.f || p.x >= BoardSize || p.y < BoardTop || p.y >= BoardTop + BoardSize)
            return false;
        col = static_cast<int>((p.x)          / CellSize);
        row = static_cast<int>((p.y - BoardTop) / CellSize);
        return row >= 0 && row < 3 && col >= 0 && col < 3;
    }

    sf::Vector2f cellCenter(int row, int col)
    {
        return {col * CellSize + CellSize * 0.5f,
                BoardTop + row * CellSize + CellSize * 0.5f};
    }

    std::string statusString(const Game& game)
    {
        switch (game.result())
        {
            case Game::Result::InProgress:
                return std::string("Player: ") +
                       (game.currentPlayer() == Game::Player::X ? "X" : "O");
            case Game::Result::XWins: return "Winner: X";
            case Game::Result::OWins: return "Winner: O";
            case Game::Result::Draw:  return "Draw!";
        }
        return {};
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({WindowWidth, WindowHeight}), "TicTacToe");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("assets/OpenSans-Regular.ttf"))
        return 1;

    sf::Text statusText(font, "", 28);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition({16.f, 14.f});

    sf::Text helpText(font, "Click to place  |  R = reset  |  ESC = quit", 17);
    helpText.setFillColor(sf::Color(180, 180, 180));
    helpText.setPosition({16.f, 50.f});

    Game game;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Escape)
                    window.close();
                else if (key->code == sf::Keyboard::Key::R)
                    game.reset();
            }

            if (const auto* mb = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mb->button == sf::Mouse::Button::Left)
                {
                    const sf::Vector2f p{static_cast<float>(mb->position.x),
                                         static_cast<float>(mb->position.y)};
                    int row = -1, col = -1;
                    if (cellFromPoint(p, row, col))
                        game.makeMove(row, col);
                }
            }
        }

        statusText.setString(statusString(game));

        window.clear(sf::Color(25, 25, 30));

        sf::RectangleShape bar({static_cast<float>(WindowWidth), UiHeight});
        bar.setFillColor(sf::Color(40, 40, 50));
        bar.setPosition({0.f, 0.f});
        window.draw(bar);

        window.draw(statusText);
        window.draw(helpText);

        for (int i = 1; i <= 2; ++i)
        {
            sf::RectangleShape vl({LineThickness, BoardSize});
            vl.setFillColor(sf::Color::White);
            vl.setPosition({i * CellSize - LineThickness * 0.5f, BoardTop});
            window.draw(vl);

            sf::RectangleShape hl({BoardSize, LineThickness});
            hl.setFillColor(sf::Color::White);
            hl.setPosition({0.f, BoardTop + i * CellSize - LineThickness * 0.5f});
            window.draw(hl);
        }

        for (int r = 0; r < 3; ++r)
        {
            for (int c = 0; c < 3; ++c)
            {
                const Board::Cell cell = game.board().get(r, c);
                if (cell == Board::Cell::Empty)
                    continue;

                const sf::Vector2f center = cellCenter(r, c);
                const float len = CellSize - 2.f * MarkMargin;

                if (cell == Board::Cell::X)
                {
                    for (float angle : {45.f, -45.f})
                    {
                        sf::RectangleShape arm({len, MarkThickness});
                        arm.setFillColor(sf::Color(220, 70, 70));
                        arm.setOrigin({len * 0.5f, MarkThickness * 0.5f});
                        arm.setPosition(center);
                        arm.setRotation(sf::degrees(angle));
                        window.draw(arm);
                    }
                }
                else
                {
                    const float radius = len * 0.5f;
                    sf::CircleShape circle(radius);
                    circle.setFillColor(sf::Color::Transparent);
                    circle.setOutlineThickness(MarkThickness);
                    circle.setOutlineColor(sf::Color(70, 180, 230));
                    circle.setOrigin({radius, radius});
                    circle.setPosition(center);
                    window.draw(circle);
                }
            }
        }

        window.display();
    }
}
