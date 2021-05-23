
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>       // vector
#include <sstream>      // sstream

// подключаем структуру данных
#include "gauss_jordan_method.hpp"

using namespace std;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  // пути для файлов с входными данными и файла, куда мы запишем полученный результат
  const auto input_path = string(kDatasetPath);
  const auto output_path = string(kProjectPath) + "/benchmark/benchmark_gauss_jordan_method_result.csv";

  // два массива с номером папки и количеством входных данных(по совместительству это название файлов в каждой из папок)
  vector<string> folders = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
  vector<string> files = {"100", "500", "1000", "5000", "10000", "50000", "100000", "500000", "1000000", "5000000"};

  // создаем граф и алгоритм Краскала
  gauss_jordan_method gaussJordanMethod;

  // открываем файл для записи
  auto output_file = fstream(output_path, ios::out);

  for (string file : files) {         // Проходим по всем 10 .csv файлам
    for (string folder : folders) {   // Проходим по всем 10 папкам с файлами
      for (int i = 1; i < 11; i++) {  // Запускаем замерку времени 10 раз

        string line = "1";  // сюда будут считываться данные из .csv файла
        auto input_file =
            ifstream(input_path + "/" + folder + "/" + file + ".csv");  // файл с входными данными

        vector<int> a;
        // создаем граф по данным из входного файла и закрываем его
        if (input_file) {
          while (line != "") {
            getline(input_file, line);
            if (line == "") {
              break;
            }

            // разбиваем строку на 3 числа и завписываем в вектор
            stringstream in(line);
            int temp;
            while (in >> temp){
              a.push_back(temp);
            }
          }
        }
        input_file.close();

        float inputData[5][5];
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            inputData[i][j] = a.at(i + j);
          }
        }

        // обновляем данные в алгоритме для нового графа
        line = "1";

        // здесь находится участок кода, время которого необходимо замерить
        const auto time_point_before_algorithm = chrono::steady_clock::now();
        gaussJordanMethod.gauss(inputData);
        const auto time_point_after_algorithm = chrono::steady_clock::now();

        // преобразуем время в наносекунды, очищаем дерево, закрываем входной файл
        const auto time_diff_algorithm = time_point_after_algorithm - time_point_before_algorithm;
        const auto time_elapsed_ns_remove = chrono::duration_cast<chrono::microseconds>(time_diff_algorithm).count();

        // вывод пути до файла, из которого брали данные, и времени, за которое эти данные были обработаны
        cout << (input_path + "/" + "algorithm/" + folder + "/" + file) << endl;
        cout << time_elapsed_ns_remove << endl;

        // Вносим полученные данные в файл для записи
        output_file << folder << "," << file << "," << 1 << "," << time_elapsed_ns_remove << endl;
      }
    }
  }

  //закрываем файл для записи
  output_file.close();
  return 0;
}