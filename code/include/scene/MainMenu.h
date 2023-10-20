#include "ServiceLocator.h"
#include "system/entity.h"
#include "UI/UiController.h"
#include "UI/UiManager.h"
#include "UI/Button.h"
#include "Overworld.h"
#include "audio/AudioManager.h"
#include "system/GameEventManager.h"
#include "system/InputManager.h"

using namespace UI::Controller;

class MainMenu : public Scene
{

public:
	MainMenu();
	~MainMenu();
	virtual void update(float dt) override;
	virtual void draw(sf::RenderWindow& window) override;
	void buttonSetup();
public:
	std::shared_ptr<MainMenuController> main_menu_ui;

private:
	std::shared_ptr<Overworld> overworld;
	sf::Sprite bg_sprite;
	sf::Texture bg_texture;
	sf::Font font;
};