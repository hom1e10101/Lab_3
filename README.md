<<<<<<< HEAD
# Балдынов Тамир 208 3 лаба
=======
# OOP_MAI_LAB3
My third OOP lab in MAI third semester

## 📝 Описание проекта

Лабораторная работа №3 по ООП (вариант 5): реализация иерархии геометрических фигур с использованием:
- Абстрактных классов и полиморфизма
- Динамических массивов (векторов)
- Вычисления площади через формулу Гаусса
- Google Test для модульного тестирования

### Реализованные фигуры:
- **Hexagon** (Шестиугольник)
- **Rhomb** (Ромб)
- **Pentagon** (Пятиугольник)

## 🛠️ Сборка проекта

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## 🚀 Запуск

### Основная программа:
```bash
./geometry_figures
```

### Тесты:
```bash
./run_tests
```

## 📂 Структура проекта

```
OOP_MAI_LAB3/
├── include/           # Заголовочные файлы
│   ├── Figure.h
│   ├── Hexagon.h
│   ├── Point.h
│   ├── Rhomb.h
│   ├── Vector_figures.h
│   └── Pentagon.h
├── src/               # Исходные файлы
│   ├── main.cpp
│   ├── Figure.cpp
│   ├── Point.cpp
│   ├── Hexagon.cpp
│   ├── Pentagon.cpp
│   ├── Rhomb.cpp
│   └── Vector_figures.cpp
├── test/              # Тесты Google Test
│   ├── main_test.cpp
│   ├── test_Hexagon.cpp
│   ├── test_Pentagon.cpp
│   ├── test_Rhomb.cpp
│   └── test_Vector.cpp
├── CMakeLists.txt
└── README.md
```

## 🧪 Тесты

Проект включает тесты на:
- ✅ VectorFigure (полиморфный контейнер, erase)
- ✅ Hexagon, Rhomb, Pentagon (вычисление площади и центра)

### Запуск тестов:
```bash
cd build
./run_tests                          # Все тесты
./run_tests --gtest_filter=Point*    # Только тесты Point
./run_tests --gtest_filter=*Area*    # Только тесты площади
```

## 📐 Математика

Площадь многоугольника вычисляется по **формуле Гаусса** (Shoelace formula):

$$A = \frac{1}{2} \left| \sum_{i=0}^{n-1} (x_i \cdot y_{i+1} - x_{i+1} \cdot y_i) \right|$$

Работает для любых выпуклых и невыпуклых многоугольников

## 💡 Как работает программа

При запуске программы:

1. **Ввод количества фигур**
   ```
   INPUT VECTOR SIZE: 3
   ```

2. **Выбор типа фигуры и ввод координат** (повторяется для каждой фигуры)
   ```
   1 - Hexagon
   2 - Pentagon
   3 - Rhombus
   ```

3. **Удаление фигуры по индексу**
   ```
   INPUT ERASE INDEX: 1
   ```

4. **Вывод площадей оставшихся фигур**
   ```
   2
   12.00
   12.00
   ```

## 🎓 Автор

hom1e10101 МАИ, 3 семестр  
Лабораторная работа №3 по ООП
>>>>>>> 49050be (3 laba is done)
