#include <iostream>
#include <ctime>
#include <exception>

class FishException : public std::exception
{
	const char *what() const noexcept override
	{
		return "Congratulations!!!You fished out the fish.";
	}
};

class BootException : public std::exception
{
	const char *what() const noexcept override
	{
		return "Failure.You fished out the Sapon.";
	}
};

class EmptyException : public std::exception
{
	const char *what() const noexcept override
	{
		return "You were unlucky.You did not get anything.";
	}
};

enum CatchType
{
	EMPTY,
	FISH,
	BOOT
};

void fishing(int *field, int size, bool& exit)
{
	int sector = 0;
	std::cout << "Enter the sector from 1 to " << size << " to cast a fishing rod: ";
	std::cin >> sector;
	sector--;

	if (field[sector] == CatchType::EMPTY)
	{
		throw EmptyException();
	}

	if (field[sector] == CatchType::FISH)
	{
		exit = true;
		throw FishException();
		
	}

	if (field[sector] == CatchType::BOOT)
	{
		exit = true;
		throw BootException();
		
	}
}

int main()
{
	std::srand(std::time(nullptr));
	int size = 9;
	bool exit = false;

	int *field = new int[size];

	for (int i = 0; i < size; i++)
	{
		field[i] = 0;
	}

	field[rand() % size] = CatchType::FISH;

	for (int i = 0; i < (size / 3); i++)
	{
		field[rand() % size] = CatchType::BOOT;
	}

	while (!exit)
	{

		try
		{
			fishing(field, size, exit);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	delete[] field;
	return 0;
}
