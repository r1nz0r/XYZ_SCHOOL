#include <iostream>
#include <string>

/*
Что нужно сделать :

Итак, тебе предстоит дописать до готовности программу учета склада, которую мы уже начали делать в последнем уроке этого модуля.
Тебе нужно реализовать заглушки, которые мы оставили, используя все, что ты узнал в модуле.

Готовая программа должна иметь следующий функционал :

Ассортимент представлен N видами мячей.Все виды мячей пронумерованы от 0 до N - 1 (этот номер = артикул). +
Программа позволяет вносить мяч определенного артикула.
Программа позволяет выводить число мячей заданного артикула.
Программа позволяет извлекать мяч по артикулу.
Программа позволяет выводить общее число мячей.
Программа позволяет показывать артикулы тех мячей, которых нет на складе.
Программа интерактивная(завершается только тогда, когда это будет нужно пользователю).
*/

int main()
{
	std::setlocale(LC_ALL, "Russian");

	const int BALLS_ARTICLES_COUNT{ 20 };
	int balls[BALLS_ARTICLES_COUNT]{};

	const std::string MENU_ADD_BALL = "1";
	const std::string MENU_SHOW_BALLS_BY_ARTICLE = "2";
	const std::string MENU_GET_BALL = "3";
	const std::string MENU_SHOW_ALL_BALLS = "4";
	const std::string MENU_SHOW_EMPTY_BALLS = "5";

	bool isActive = true;

	while (isActive)
	{
		std::system("CLS");

		std::cout << "Добро пожаловать на склад мячей!\n\n"
			<< "Вам доступны следующие команды:\n"
			<< MENU_ADD_BALL << " - Внести мяч заданного артикула;\n"
			<< MENU_SHOW_BALLS_BY_ARTICLE << " - Вывести число мячей заданного артикула;\n"
			<< MENU_GET_BALL << " - Извлечь мяч по артикулу;\n"
			<< MENU_SHOW_ALL_BALLS << " - Вывести общее число мячей;\n"
			<< MENU_SHOW_EMPTY_BALLS << " - Показать артикулы тех мячей, которых нет на складе.\n\n";

		std::string userInput{};
		std::cout << "Введите номер команды: _\b";
		std::cin >> userInput;

		if (userInput == MENU_ADD_BALL)
		{
			int ballArticle{};
			std::cout << "Для добавления мяча укажите его артикль от 1 до "
				<< BALLS_ARTICLES_COUNT << ": __\b\b";
			std::cin >> userInput;

			if (std::cin.fail() || ballArticle < 1 || ballArticle > BALLS_ARTICLES_COUNT)
			{
				std::cout << "Неверный артикль мяча.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			else
			{
				++balls[ballArticle - 1];
				std::cout << "Добавлен мяч с артиклем " << ballArticle << "."
					<< "Текущее количество мячей данного артикля - " << balls[ballArticle - 1] << "\n";
			}
		}
		else if (userInput == MENU_SHOW_BALLS_BY_ARTICLE)
		{
			int ballArticle{};
			std::cout << "Укажите артикль мячей от 1 до " << BALLS_ARTICLES_COUNT << ": __\b\b";
			std::cin >> userInput;
						
			if (std::cin.fail() || ballArticle < 1 || ballArticle > BALLS_ARTICLES_COUNT)
			{
				std::cout << "Неверный артикль мяча.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			else
			{
				std::cout << "Всего мячей с артиклем " << ballArticle << " - " << balls[ballArticle - 1] << "\n";
			}
		}
		else if (userInput == MENU_GET_BALL)
		{
			int ballArticle{};
			std::cout << "Укажите артикль мячей от 1 до " << BALLS_ARTICLES_COUNT << ": __\b\b";
			std::cin >> userInput;

			if (std::cin.fail() || ballArticle < 1 || ballArticle > BALLS_ARTICLES_COUNT)
			{
				std::cout << "Неверный артикль мяча.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			else
			{
				if (balls[ballArticle - 1] > 0)
				{
					--balls[ballArticle - 1];
					std::cout << "Вы забрали мяч с артиклем " << ballArticle << " - "
						<< "Текущее количество мячей данного артикля - " << balls[ballArticle - 1] << "\n";
				}
				else
				{
					std::cout << "Мячи с таким артиклем отсутствуют на складе.\n";
				}
			}
		}
		else if (userInput == MENU_SHOW_ALL_BALLS)
		{
			int sum{};

			for (const auto& item : balls)
			{
				sum += item;
			}

			std::cout << "Всего мячей на складе - " << sum << std::endl;
		}
		else if (userInput == MENU_SHOW_EMPTY_BALLS)
		{
			std::cout << "Номера артиклей мячей, которых нет на складе: ";

			bool isFound = false;

			for (int i = 0; i < BALLS_ARTICLES_COUNT; ++i)
			{
				if (balls[i] == 0)
				{
					isFound = true;
					std::cout << i + 1 << " ";
				}
			}

			if (isFound == false)
			{
				std::cout << " -";
			}

			std::cout << std::endl;
		}
		else
		{
			std::cout << "Неизвестная команда.\n";
		}

		std::cout << "Желаете продолжить? (y/n): _\b";
		std::cin >> userInput;

		if (std::tolower(userInput[0]) == 'n')
		{
			std::cout << "Всего доброго!";
			isActive = false;
		}
	}

	return 0;
}
