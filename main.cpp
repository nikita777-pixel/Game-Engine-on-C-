/*
This is my projects (Nikita Volodin) . SFML libriary.
*/

#include <SFML/Graphics.hpp> // Includ Libriary. (SFML).
#include <iostream>
#include "maps.h" //подключили код с картой
#include "vie.h"; // Incluse code with camera here. 

using namespace sf;

// sf:: (this is appeal to the library).

class Enemy
{
	/*
	This is class is need:
	1 . Realization Enemy here:
	*/

private:

	// Const and Variable here:



public:

	Enemy()
	{
		// Construct here:


	}
};

class Player
{

/*
This is class is need:
1. Realization Player
*/

public:
	// Const and Variable (Player) here:

	float X_POS_PLAYER;
	float Y_POS_PLAYER;
	float WIDTH_PLAYER;
	float HEIGHT_PLAYER;
	float VEL_X;
	float VEL_Y;
	int SPEED = 0;
	int DIR = 0;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Player(int x, int Y, int width, int height)
	{
		// Construct here:

		X_POS_PLAYER = x;
		Y_POS_PLAYER = Y;
		WIDTH_PLAYER = width;
		HEIGHT_PLAYER = height;

		image.loadFromFile("image/player.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, WIDTH_PLAYER, HEIGHT_PLAYER)); // Обрезаем чтобы получился 1 персонаж, а не все.
		sprite.setPosition(X_POS_PLAYER, X_POS_PLAYER);
	}

	void Draw_Hero_If_Player_Go()
	{
		// Go Realization here:

		sprite.setPosition(X_POS_PLAYER, Y_POS_PLAYER); // Draw hero if Player go here.
	}

	float GetPlayerCordinatX() 
	{
		/*
		This is method is need:
		1. get Cordinat Player X
		*/

		// Я напримую немогу обращятся к данным переменным потомучто они private и я для это делаю метод.

		return X_POS_PLAYER; // Check Cordinate Player X here.
	}

	float GetPlayerCordinateY()
	{
		/*
		This is method is need:
		1. get Cordinate Player Y
		*/

		// Я напримую немогу обращятся к данным переменным потомучто они private и я для это делаю метод.

		return Y_POS_PLAYER; // Check Cordinate Player Y here.
	}

	void Go_Left()
	{
		// Realization Go Left (player) here:

		X_POS_PLAYER = X_POS_PLAYER -= 0.5;
		sprite.setTextureRect(IntRect(31, 96, WIDTH_PLAYER, HEIGHT_PLAYER)); // Обрезаем чтобы получился 1 персонаж, а не все.
	}

	void Go_Right()
	{
		// Realization Go Right (player) here:

		X_POS_PLAYER = X_POS_PLAYER += 0.5;
		sprite.setTextureRect(IntRect(30, 30, WIDTH_PLAYER, HEIGHT_PLAYER)); // Обрезаем чтобы получился 1 персонаж, а не все.
	}

	void Go_UP()
	{
		// Hero ho UP here:

		Y_POS_PLAYER = Y_POS_PLAYER -= 0.5;
		sprite.setTextureRect(IntRect(0, 0, WIDTH_PLAYER, HEIGHT_PLAYER)); // Обрезаем чтобы получился 1 персонаж, а не все.
	}

	void Go_DOWN()
	{
		// Realization Go DOWN (player) here:

		Y_POS_PLAYER = Y_POS_PLAYER += 0.5;
		sprite.setTextureRect(IntRect(31, 64, WIDTH_PLAYER, HEIGHT_PLAYER)); // Обрезаем чтобы получился 1 персонаж, а не все.
	}
};

class My_Game
{

/*
This is class is need:
1. This is main class in this game.
*/

private:
	// Const (private) . (My_Game) here:

	const int WIDTH_DISPLAY = 900;
	const int HEIGHT_DISPLAY = 600;
	const std::string TITLE_DISPLAY = "RPG GAMING";

	bool IsMove = false; // Variable for mouse fasle.
	float D_X = 0; // Corect go in cursor.
	float D_Y = 0; // Corect go in cursor.
	
public:
	My_Game()
	{
		// Construct here:

		Main_Draw();
	}
private:
	void Main_Draw()
	{
		/*
		This is class is need:1
		1 . Realization Created (DISPLAY)
		2 . Created Objects (User, Enemy) OLL
		3 . Realization Oll here:
		*/

		// Write code here:
		// Created Objects (My_Game):

		sf::RenderWindow WINDOW(sf::VideoMode(WIDTH_DISPLAY, HEIGHT_DISPLAY), TITLE_DISPLAY);

		view.reset(sf::FloatRect(0, 0, 540, 480)); // Размер вида камеры.

		Player hero(200, 200, 32, 31); // Created Player (hero) and give x pos , y pos , width, height (player).

		Clock clock;

		Image map_image; //объект изображения для карты
		map_image.loadFromFile("image/map.png"); //загружаем файл для карты
		Texture map; //текстура карты
		map.loadFromImage(map_image); //заряжаем текстуру картинкой
		Sprite s_map; //создаём спрайт для карты
		s_map.setTexture(map); //заливаем текстуру спрайтом

		while (WINDOW.isOpen()) // CHECK IF WINDOW == IS OPE:
		{
			// Main While here:

			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();

			time = time / 1000; // 60 FPS to game.

			// Realization check cordinate Mouse here:

			sf::Vector2i PixelPos = sf::Mouse::getPosition(WINDOW); // Get Cord Mouse
			sf::Vector2f Pos = WINDOW.mapPixelToCoords(PixelPos); // Translate Cord mouse in Game Cord here.

			// End check Cordinate Mouse.

			sf::Event event;

			while (WINDOW.pollEvent(event)) // Check if you click EXIT (PROGRAMS) . and realization EXIT (PROGRAMS).
			{
				if (event.type == sf::Event::Closed)
				{
					// If User click close:

					WINDOW.close(); // WINDOW close.
				}

				// Realization Click on Player here:

				if (event.type == sf::Event::MouseButtonPressed) // If you click on Mouse:
				{
					// Check which key is pressed:

					if (event.key.code == Mouse::Left)
					{
						// If you click left mouse realization here:

						if (hero.sprite.getGlobalBounds().contains(Pos.x, Pos.y)) // Check if cordinate mouse == Sprite Player
						{
							// If cursor == Player cordinate realization here:

							std::cout << "Click!";
							IsMove = true; // IsMove == true: Green Player (You click).
							hero.sprite.setColor(Color::Green); // Draw Sprite (Green) Color here.
						}
					}
				}

				if (event.type == sf::Event::MouseButtonReleased)
				{
					// If You button Don't clcik realization (отпустить кнопку) here:

					if (event.key.code == Mouse::Left)
					{
						// If Don't click left button realization here (отпустить левую кноку):

						hero.sprite.setColor(Color::White); // White Color Player.
					}
				}
			}

			// END Realization Click on Player.

			

			// Realization go (Player) here:

			if (sf::Keyboard::isKeyPressed(Keyboard::A))
			{
				// If Player pressed the button A (player go left) realization here:

				hero.Go_Left();

				GetPlayerCordinate(hero.GetPlayerCordinatX(), hero.GetPlayerCordinateY()); // Передаём координаты игрока в функцию управления камеры.

				if (hero.X_POS_PLAYER < 0)
				{
					// Realization If player go from board:

					WINDOW.close();
				}
			}

			if (sf::Keyboard::isKeyPressed(Keyboard::D))
			{
				// If Player pressed the button A (player go left) realization here:

				hero.Go_Right();

				GetPlayerCordinate(hero.GetPlayerCordinatX(), hero.GetPlayerCordinateY()); // Передаём координаты игрока в функцию управления камеры.

				if (hero.X_POS_PLAYER > 2000)
				{
					// Realization If player go from board:

					WINDOW.close();
				}
			}

			if (sf::Keyboard::isKeyPressed(Keyboard::W))
			{
				// If Player pressed the button A (player go left) realization here:

				hero.Go_UP();

				GetPlayerCordinate(hero.GetPlayerCordinatX(), hero.GetPlayerCordinateY()); // Передаём координаты игрока в функцию управления камеры.

				if (hero.Y_POS_PLAYER < 0)
				{
					// Realization If player go from board:

					WINDOW.close();
				}
			}

			if (sf::Keyboard::isKeyPressed(Keyboard::S))
			{
				// If Player pressed the button A (player go left) realization here:

				hero.Y_POS_PLAYER = hero.Y_POS_PLAYER += 0.5;
				hero.sprite.setTextureRect(IntRect(31, 64, hero.WIDTH_PLAYER, hero.HEIGHT_PLAYER)); // Обрезаем чтобы получился 1 персонаж, а не все.

				GetPlayerCordinate(hero.GetPlayerCordinatX(), hero.GetPlayerCordinateY()); // Передаём координаты игрока в функцию управления камеры.

				if (hero.Y_POS_PLAYER > 1100)
				{
					// Realization If player go from board:

					WINDOW.close();
				}
			}

			if (sf::Keyboard::isKeyPressed(Keyboard::J))
			{
				// Realization Window close on keyboard here:

				WINDOW.close();
			}

			// End realization go.

			hero.Draw_Hero_If_Player_Go(); // Draw Hero in this method.

			/*
			What this do?
			1 . DISPLAY == CLEAR.
			2 . DISPLAY == DRAW(SHAPE)
			3 . DISPLAY == VISIPLE
			4 . REURN (WHILE)*/

			WINDOW.clear();//Every time game clear and draw new Objects(Таким образом игра перерисовывает каждый раз)here:

			WINDOW.setView(view); // Оживляем камеру.

			///////// DRAW CARD /////////

			for (int i = 0; i < HEIGHT_MAP; i++)// Draw HEIGHT CARD (background).
			{
				for (int j = 0; j < WIDTH_MAP; j++) // Draw WIDTH CARD (background).
				{
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
					if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
					if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
					if (TileMap[i][j] == 'x') s_map.setTextureRect(IntRect(96, 0, 32, 32));
					if (TileMap[i][j] == 'g') s_map.setTextureRect(IntRect(128, 0, 32, 32));
			
					s_map.setPosition(j * 32, i * 32); //по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
			
					WINDOW.draw(s_map);//рисуем квадратики на экран
				}
			}

			

			///////// END DRAW CARED /////////

			WINDOW.draw(hero.sprite); // Give in WINDOW (Display) . hero (object).

			WINDOW.display(); // Visible Oll in Display here.
		}
	}
};

int main()
{
	// Compiller Read Code here:

	// Created Objects (My_Game) here:

	My_Game game;
}