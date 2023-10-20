#include "UI/UiController.h"
#include "system/InputManager.h"

namespace UI
{
	namespace Controller
	{
		FpsController::FpsController(const sf::Font& font) : fps_view(font)
		{ 
			name = "fps"; 
			std::cout << "FPS Controller created!" << std::endl;
		}

		FpsController::~FpsController()
		{
			std::cout << "FPS Controller destroyed!" << std::endl;
		}

		void FpsController::update(float dt)
		{
			fps_timer += dt;
			frame_count++;

			if (fps_timer >= 1.0f)
			{
				int fps = static_cast<int>(frame_count / fps_timer);
				fps_model.setFps(fps);
				fps_view.update(fps_model);
				frame_count = 0;
				fps_timer = 0;
			}
		}

		void FpsController::draw(sf::RenderWindow& window)
		{
			fps_view.draw(window);
		}

		void MainMenuController::update(float dt)
		{

		}

		void MainMenuController::draw(sf::RenderWindow& window)
		{
			mm_view.draw(window);
		}

		void MainMenuController::onClick()
		{
			Button& new_game = mm_view.new_game_button;
			Button& load_game = mm_view.load_game_button;
			Button& settings = mm_view.settings_button;
			Button& quit = mm_view.quit_button;

			std::shared_ptr<StoreMapCommand> store_map_cmd = std::make_shared<StoreMapCommand>([&](sf::Event& ev, const sf::Vector2f& mouse_position) {
				new_game.checkClick(mouse_position);
				load_game.checkClick(mouse_position);
				settings.checkClick(mouse_position);
				quit.checkClick(mouse_position);
				});

			ServiceLocator::getService<InputManager>().bindMouseToCmd(sf::Mouse::Left, store_map_cmd);
		}
	}
}