## 1. Сборка и запуск

Сборка в CLion:
1. Открыть папку проекта PhysCat в CLion.
2. Выбрать конфигурацию PhysCat и нажать Build.

Сборка из командной строки (CMake):
mkdir build
cd build
cmake ..
cmake --build .

Запуск:
PhysCat.exe                  (команды вводятся вручную, выход: quit)
PhysCat.exe < input.txt      (команды из файла)

Стандарт: C++20 (см. CMakeLists.txt).

## 2. Схема наследования
EnergyConsumer (**абстрактный**)

InventoryItem (**абстрактный**)
* Transport (**абстрактный**)
* * Scooter &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;+ *EnergyCustomer*, множественное наследование
* * Bike
* * Ebike &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; + *EnergyCustomer*, мноэественное наследоание
* * NewTeslaRoadster &emsp;&emsp;&emsp;&emsp; + *EnergyConsumer*, множественное наследование
* Thing (**абстрактный**)
* * Helmet
* * Dock &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; + EnergyConsumer, множественное наследование

Ромба нет, виртуальное наследование не пригодилось.
## 3. Умные указатели

### 1) unique_ptr

ServiceCenter::Park::Add-функции

Единоличное владение новым объектом. Если прилетает исключение (Inspector's BAN или переполнение accIds), 
объект удаляется, парк остается нетронутым. Иначе владение переходит в парк.

### 2) shared_ptr

ServiceCenter::Park::service_

Парк хранит shared_ptr'ы, чтобы focus мог за ними следить.

### 3) weak_ptr

ServiceCenter::Park::focus_

focus - витрина. Он смотрит, но не хранит. Если объект был удален, focus вернет пустышку.

## 4. Исключения

FleetError - общий базис. InspectionError - транспорт сломан, бан от инспектора. CommandError - любой запрос не по формату.


Бросаются в:

1) Registry::Registry::add() (если accIds переполнен)
2) ServiceCenter::Park функции проверки: ispect() (если транспорт сломан), checkID() (если ID пуст), checkScore() (если score < 1 или > 10), checkEnergy() (если energy < 0)
3) Main (любой запрос не по формату)

Ловятся ТОЛЬКО в main.


## 5. Шаблон 
Registry::Registry<typename T, int Cap>

ServiceCenter::Park::accIds_ - журнал ID транспортных средств, прошедших проверку Инспектора, длины не больше 1000. Если при добавлении исправного средства журнал переполнен - средство отклоняется. Тут accIds это Registry<string, 1000>.

## 6. Креативная часть 
Добавлено новое транспортное средство NewTeslaRoadster. Является аналаогом Scooter и Ebike с фиксированным уровнем простоты 1.
Новая команда: add NewTeslaRoadster id name energy.

Добавлена новая команда count_novice, которая выводит количество свободных транспортных средств, доступных для новичков.

## 7. ИИ

Использовал Claude Sonnet 5.5 Medium

Что взял у ИИ:
1) Объяснение тем: виртуальные функции, множественное и виртуальное наследование, перегрузка опреторов, шаблоны, исключения, умные указатели.
2) Разбор моего кода: ИИ указывал на ошибки (например, забытый &, const, explicit, выход за границы вектора в main)
3) Сборка и запуск (см. пункт 1 текущего файла)

Что напис сам:
1) Иерархию классов: InventoryItem, EnergyConsumer, Transport, Thing и их наследники.
2) Класс ServiceCenter::Park : хранение, добавление, поиск, list, novice, energy, focus, remove.
3) Шаблон Registry, иерархию исключений, main.cpp, креативную часть.
 




