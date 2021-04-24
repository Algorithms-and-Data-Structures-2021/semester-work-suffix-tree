Suffix Tree

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

**_Измените status badge сверху для отображения статуса сборки вашего проекта._**

`Actions > CMake > ... > Create status badge`

**Описание:**
- Реализация структуры данных Suffix Tree
- Suffix Tree - дерево, в котором содержатся  все возможные окончания слова (суффиксы).
- Структура позволяет быстро реализовывать многие важные операции со строками: поиск подстроки, поиск паттернов в строке, построение суффиксного массива, поиск общей подстроки и т.д.  
- Структура позволяет построить Суффиксное Дерево, над которым можно производить поиск(обход), добавление новых символов(строк).

**Сложность функций:**
- Построние дерева происходит за **O(n)** времени и занимает **O(n)** памяти (в моей реализации), где n-длина строки(или текста). Добавление символа происходит за константное время. 
- Проверка подстроки происходит за **O(m)** времени, где m - длина самой подстроки.
- Удаление дерева происходит за константное время.

Проект выполнила команда LA FLAME (Богдан Абарихин)
| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Абарихин Б.   |   100     |  LA FLAME             |

## Структура проекта

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`main.cpp`](main.cpp) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (желательно VS).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 8 ГБ.
5. Свободное дисковое пространство объемом ~ 1 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Пример (Windows)

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):
Пропишите в корне папки, в которую копируете репозиторий следующую команду

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template.git
```

#### Генерация тестовых данных

Форат хранения данных - csv файлы со строками длины от 100 до 1000000 (с учетом того, что у вас минимум 8гб оперативной памяти).

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

1. Сначала вам нужно открыть файл **generate_csv_dataset.py** в папке dataset (с помощью любого блокнота).
2. В массиве **amount_samples** оставьте только те числа, в размере которых вам нужно сгенерировать данные для проверки функций.
3. В массиве **folders** оставьте только те элементы вида **tree_creation/data_1/**, в которые вам нужно записать данные (data_n - это n-тая папка, в которой будут храниться .csv файлы, сгенерированные скриптом, если оставить несколько папок в массиве, то получится несколько разных наборов данных на одном количестве данных).
4. Запустите python скрипт:
```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_bench_dataset.py
```

Тестовые данные представлены в CSV формате (см.
[`dataset/data/dataset-example.csv`](dataset/data/dataset-example.csv)):

```csv
dlfjLIAIDJPOIFAJFPDikfjfhosijdffPDO:SIFJiojdfhshfuykglfidhgjjJFDSJFjGLKSHFGJKLHLlfgnjlgkfdjglfdgmfdmgmfdgnn
...
```

#### Контрольные тесты (benchmarks)

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных. 

https://drive.google.com/drive/folders/1x077qM8-G67RCv5ttBIrWhTWbdTZjf-p - готовый набор данных.

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `Add`                     | Создание дерева по строке               | _время_         |
| `Search`                  | Поиск подстроки в дереве                | _время_         |
| `Delete`                  | Удаление дерева                         | _время_         |

##### Примеры запуска

1. Открыть в IDE файл **tree_creation and substring_search.cpp**, находящийся в папке **benchmark**.
2. В массиве **folders** оставить только те папки /data_n/, которые вы скачали или в которые генерировали данные, аналогично с массивом files.
3. Запустить функцию main. Все замеры будут выводиться в консоль.

## Источники
https://www.youtube.com/watch?v=qh2leThTv0Y&list=WL&index=29 - короткое видео с визуализацией построения дерева.
https://www.youtube.com/watch?v=LNBs3xZMGLc - лекция с ИТМО (не лучшая лекция, но какие то концепты понять поможет)
https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english - лучшее подробное объяснение алгоритма на чистом английском
https://www.geeksforgeeks.org/generalized-suffix-tree-1/ - различные примеры использования, теория
http://brenden.github.io/ukkonen-animation/ - хороший сайт с визуализацией
