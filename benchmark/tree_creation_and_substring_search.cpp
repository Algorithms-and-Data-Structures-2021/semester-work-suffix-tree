#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds


// подключаем вашу структуру данных
#include "SuffixTree.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

// Возможно стоит подумать о том что данные в таблицу будут заноситься  другом порядке и изменить порядок обработки
// папок (сначала прогнать все папки для 100, 500 и тд)
string folders[10] = {"/data_1/",
                      "/data_2/",
                      "/data_3/",
                      "/data_4/", "/data_5/", "/data_6/",
                      "/data_7/", "/data_8/", "/data_9/",
                      "/data_10/"};
string files[12] = {"100.csv", "500.csv", "1000.csv", "5000.csv", "10000.csv", "25000.csv", "50000.csv", "100000csv",
                    "250000.csv", "500000.csv", "750000.csv", "1000000.csv"};

int main() {
  // работа с набором данных
  const auto path = string(kDatasetPath);
  string line;
  string data = "";
  for (auto file : files) {
    for (auto folder : folders) {
      for (int i = 0; i < 10; ++i) { // 10 раз прогоняем один и тот же csv файл
        auto input_file = ifstream(path + folder + file);

        SuffixTree* tree = new SuffixTree; // Создание структуры, инициализация перед тестами
        tree->st_init();

        // сам бенчмарк, в данном случае создание (добавление)
        auto time_point_before = chrono::high_resolution_clock::now();
        while (getline(input_file, line)) {
          for (auto j : line) {
            tree->st_extend(j);
          }
        }
        auto time_point_after = chrono::high_resolution_clock::now();
        auto time_diff = time_point_after - time_point_before;
        long time_elapsed_ns_create = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

        // здесь мне нужно было перейти обратно в начало файла, т.к. набор данных у меня один и тот же
        input_file.clear();
        input_file.seekg(0);

        while (getline(input_file, line)) { // теперь мы снова в начале файла
          data += string(line);
        }
        auto count_to = data.length() / 2; // важно все подготовительные операции сделать ДО начала отсчета времени
        auto substr = data.substr(0, count_to);

        time_point_before = chrono::high_resolution_clock::now();
        tree->checkForSubString(substr);
        time_point_after = chrono::high_resolution_clock::now();
        time_diff = time_point_after - time_point_before;
        long time_elapsed_ns_search = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

        cout << "Time elapsed for creation in " << folder + file + " " << time_elapsed_ns_create << " " <<
            "Time for searching " << time_elapsed_ns_search << "\n";
        data = " ";

        delete tree;

      }
    }
  }


}
