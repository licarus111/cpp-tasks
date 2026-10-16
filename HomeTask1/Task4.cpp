#include <iostream>
///Деканат ведет учет отчисленных. Преподаватель-вальщик - часть системы.
///Хранилище: log[семестр][курс][группа] = сколько отчисленно
///
///int*** - три индекса, массив массивов массивов, память динамичсекая. Нужен int***.
///
///void* - отчетности бывают разных типов:
///1) За семестр (int*)
///2) За семестр по курсам (int**)
///3) За семестр по курсам и группам (int***)
///Типы разные, а все должны лежать в одном массиве. Нужен void*.

int main() {
  int sem;
  int crs;
  int grp;
  std::cin >> sem >> crs >> grp;

  //вводим данные
  int*** log = new int**[sem];
  for (int s = 0; s < sem; s++) {
    log[s] = new int*[crs];
    for (int c = 0; c < crs; c++) {
      log[s][c] = new int[grp];
      for (int g = 0; g < grp; g++) {
        std::cin >> log[s][c][g];
      }
    }
  }

  //создаем журнал отчетностей
  void* reports[3];

  //считаем отчисления по семестрам
  int* r0 = new int[sem];
  for (int s = 0; s < sem; s++) {
    r0[s] = 0;
    for (int c = 0; c < crs; c++) {
      for (int g = 0; g < grp; g++) {
        r0[s] += log[s][c][g];
      }
    }
  }
  reports[0] = r0;

  //считаем отчисления по семестрам и курсам
  int** r1 = new int*[sem];
  for (int s = 0; s < sem; s++) {
    r1[s] = new int[crs];
    for (int c = 0; c < crs; c++) {
      r1[s][c] = 0;
      for (int g = 0; g < grp; g++) {
        r1[s][c] += log[s][c][g];
      }
    }
  }
  reports[1] = r1;

  //считаем отчисления по семестрам, курсам и группам
  int*** r2 = new int**[sem];
  for (int s = 0; s < sem; s++) {
    r2[s] = new int*[crs];
    for (int c = 0; c < crs; c++) {
      r2[s][c] = new int[grp];
      for (int g = 0; g < grp; g++) {
        r2[s][c][g] = log[s][c][g];
      }
    }
  }
  reports[2] = r2;

  int type;
  std::cin >> type;

  if (type == 0) {
    //если просят отчетность по семестрам, разворачиваем reports как int*
    int* r_sem = static_cast<int*>(reports[0]);
    for (int s = 0; s < sem; s++) {
      std::cout << s + 1 << " " << "sem: " << r_sem[s] << '\n';
    }
  } else if (type == 1) {
    //если просят отчетность по семестрам и курсам, разворачиваем reports как int**
    int** r_crs = static_cast<int**>(reports[1]);
    for (int s = 0; s < sem; s++) {
      std::cout << s + 1 << " " << "sem: " << '\n' << "  ";
      for (int c = 0; c < crs; c++) {
        std::cout << c + 1 << " " << "crs: " << r_crs[s][c] << '\n' << "  ";
      }
      std::cout << '\n';
    }
  } else if (type == 2) {
    //если просят отчетность по семестрам, курсам и группам, разворачиваем reports как int***
    int*** r_grps = static_cast<int***>(reports[2]);
    for (int s = 0; s < sem; s++) {
      std::cout << s + 1 << " " << "sem: " << '\n' << "  ";
      for (int c = 0; c < crs; c++) {
        std::cout << c + 1 << " " << "crs: " << '\n' << "    ";
        for (int g = 0; g < grp; g++) {
          std::cout << g + 1 << " " << "grp: " << r_grps[s][c][g] << '\n' << "    ";
        }
        std::cout << '\n' << "  ";
      }
      std::cout << '\n';
    }
  }
  std::cout << '\n';

  //чистим память
  delete[] r0;
  for (int s = 0; s < sem; ++s) delete[] r1[s];
  delete[] r1;
  for (int s = 0; s < sem; ++s) {
    for (int c = 0; c < crs; ++c) delete[] r2[s][c];
    delete[] r2[s];
  }
  delete[] r2;

  for (int s = 0; s < sem; ++s) {
    for (int c = 0; c < crs; ++c) delete[] log[s][c];
    delete[] log[s];
  }
  delete[] log;

  return 0;
}
