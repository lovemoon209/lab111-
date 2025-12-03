/*
Варіант 14.
Дано текстовий файл t. Відомо, що в цьому файлі є по крайній мірі три крапки.
Знайти числа і (номер рядка у файлі) та j (номер позиції у рядку) – такі, що sіj
– третя за порядком крапка (оформити у вигляді функції).
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int FindThirdDot(const string &filename, int &linenom, int &pos) {
  ifstream file(filename);
  if (!file.is_open()) {
    return false;
  }

  string line;
  int dot = 0;
  int strit = 0;

  while (getline(file, line)) {
    strit++;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '.') {
        dot++;
        if (dot == 3) {
          linenom = strit;
          pos = i;
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  char choice;
  cout << "Створити тестовий файл з крапками? (y/n): ";
  cin >> choice;

  if (choice == 'y' || choice == 'Y') {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ofstream out("t.txt");
    cout << "Речення: \n";
    string input;
    getline(cin, input);
    out << input;
    out.close();
    cout << "\n Файл t.txt створено успішно.\n";
  }

  cout << "\nПошук третьої крапки...\n";
  int linen, position;

  if (FindThirdDot("t.txt", linen, position)) {
    cout << "Третя крапка знайдена:\n";
    cout << "Рядок: " << linen << ", Позиція: " << position << endl;

    ifstream in("t.txt");
    string line;
    int n = 1;
    while (getline(in, line)) {
      if (n == linen) {
        cout << "Текст рядка: " << line << endl;
        break;
      }
      n++;
    }
    in.close();
  }

  else {
    cout << "Третьої крапки не знайдено.\n";
  }

  return 0;
}
