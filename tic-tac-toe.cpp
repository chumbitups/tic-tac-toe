#include <iostream>
#include <string>

// Проверка по гориз. и верт.
bool checkLanes(char symb, char tables[3][3])
{
  bool cols, rows;
  for (int col = 0; col < 3; col++)
  {
    cols = true;
    rows = true;
    for (int row = 0; row < 3; row++)
    {
      cols &= tables[col][row] == symb;
      rows &= tables[row][col] == symb;
    }
    if (cols || rows)
      return true;
  }
  return false;
}

// Проверка по диаг.
bool checkDiags(char symb, char tables[3][3])
{
  bool right, left;
  right = true;
  left = true;
  for (int i = 0; i < 3; i++)
  {
    right &= tables[i][i] == symb;
    left &= tables[2 - i][i] == symb;
  }
  if (right || left)
  {
    return true;
  }
  return false;
}

char getWinner(char tables[3][3])
{
  if ((checkLanes('X', tables)) || (checkDiags('X', tables)))
  {
    return 'X';
  }
  else if ((checkLanes('O', tables)) || (checkDiags('O', tables)))
  {
    return 'O';
  }
  else
  {
    return 1;
  }
}

// Вывод поля
void drawField(char tables[3][3])
{
  std::cout << " ------------- " << std::endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cout << " | " << tables[i][j];
    }
    std::cout << " | " << std::endl
              << " ------------- " << std::endl;
  }
}

int main()
{
  bool places[3][3] = {{false, false, false},
                       {false, false, false},
                       {false, false, false}};

  char cells[3][3] = {{' ', ' ', ' '},
                      {' ', ' ', ' '},
                      {' ', ' ', ' '}};

  char gamerName = 'X';
  int j = 0;
  int k = 0;
  int freePlaces = 9;

  while (freePlaces > 0)
  {
    std::cout << "Player " << gamerName << ", input your next move: ";
    std::cin >> j >> k;
    while (j < 1 || j > 3 || k < 1 || k > 3)
    {
      std::cout << "Wrong cell, try again" << std::endl;
      std::cin >> j >> k;
    }

    if (places[j - 1][k - 1] == false)
    {
      cells[j - 1][k - 1] = gamerName;
      places[j - 1][k - 1] = true;
      freePlaces -= 1;

      drawField(cells);

      if (getWinner(cells) == gamerName)
      {
        std::cout << gamerName << " is winner";
        return 0;
      }

      if (gamerName == 'X')
      {
        gamerName = 'O';
      }
      else
      {
        gamerName = 'X';
      }
    }
    else
    {
      std::cout << "This cell is taken" << std::endl;
    }
  }
  std::cout << "Draw!";
}
