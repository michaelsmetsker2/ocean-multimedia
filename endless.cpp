#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <optional>

void changeMusic(int index, std::vector<sf::Music*>& songs) {
    for (auto& song : songs) {
        song->stop();
    }
    songs[index]->play();
}

int main() {
    sf::Font font;
    if (!font.openFromFile("ARIAL.ttf")) {
        std::cout << "ERROR: Font not working!\n";
    }
    std::vector<sf::Texture> textures(5);
    if (!textures[0].loadFromFile("C:\\Users\\IgnasKadisa\\Desktop\\C++\\multimedia endless\\endless\\out\\build\\x64-debug\\assets\\images\\image1.jpg") ||
        !textures[1].loadFromFile("C:\\Users\\IgnasKadisa\\Desktop\\C++\\multimedia endless\\endless\\out\\build\\x64-debug\\assets\\images\\image2.jpg") ||
        !textures[2].loadFromFile("C:\\Users\\IgnasKadisa\\Desktop\\C++\\multimedia endless\\endless\\out\\build\\x64-debug\\assets\\images\\image3.jpg") ||
        !textures[3].loadFromFile("C:\\Users\\IgnasKadisa\\Desktop\\C++\\multimedia endless\\endless\\out\\build\\x64-debug\\assets\\images\\image4.jpg") ||
        !textures[4].loadFromFile("C:\\Users\\IgnasKadisa\\Desktop\\C++\\multimedia endless\\endless\\out\\build\\x64-debug\\assets\\images\\image5.jpg")) {
        std::cout << "ERROR: image not loading\n";
    }

    for (int i = 0; i < textures.size(); i++) {
        if (textures[i].getSize().x == 0) { 
            std::cout << "ERROR: Texture " << i + 1 << " failed to load\n";
        }
    }
    sf::Sprite currentSprite(textures[0]);
    currentSprite.setTexture(textures[0], true);

    sf::Music music, music2, music3, music4, music5;
    if (!music.openFromFile("assets/audio/sideways.ogg") ||
        !music2.openFromFile("assets/audio/hublots.ogg") ||
        !music3.openFromFile("assets/audio/garcons.ogg") ||
        !music4.openFromFile("assets/audio/unity.ogg") ||
        !music5.openFromFile("assets/audio/rushes.ogg")) {
        std::cout << "ERROR: could not load one or more music files\n";
        return -1;
    }
    std::vector<sf::Music*> songs = { &music, &music2, &music3, &music4, &music5 };

    sf::Text text(font);
    text.setFont(font);
    text.setString("press a number to play a song");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Underlined);
    text.setPosition({ 300, 300 });

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML Music Player");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (event->is<sf::Event::KeyPressed>()) {
                if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                    switch (keyEvent->code) {
                    case sf::Keyboard::Key::Num1:
                        changeMusic(0, songs);
                        text.setString("1. sideways");
                        currentSprite.setTexture(textures[0]);
                        window.draw(currentSprite);
                        break;
                    case sf::Keyboard::Key::Num2:
                        changeMusic(1, songs);
                        text.setString("2. hublots");
                        currentSprite.setTexture(textures[1]);
                        window.draw(currentSprite);
                        break;
                    case sf::Keyboard::Key::Num3:
                        changeMusic(2, songs);
                        text.setString("3. comme des garcons");
                        currentSprite.setTexture(textures[2]);
                        window.draw(currentSprite);
                        break;
                    case sf::Keyboard::Key::Num4:
                        changeMusic(3, songs);
                        text.setString("4. U.N.I.T.Y");
                        currentSprite.setTexture(textures[3]);
                        window.draw(currentSprite);
                        break;
                    case sf::Keyboard::Key::Num5:
                        changeMusic(4, songs);
                        text.setString("5. rushes");
                        currentSprite.setTexture(textures[4]);
                        window.draw(currentSprite);
                        break;
                    default:
                        break;
                    }
                    text.setStyle(sf::Text::Bold);
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(currentSprite);
        window.draw(text);
        window.display();
    }
    return 0;
}