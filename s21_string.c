#include "s21_string.h"

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_errno.h"

// Выполняет поиск первого вхождения символа c
// в первых n байтах строки, на которую указывает аргумент str.
// Если не найден - возвращает NULL
void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *res = (char *)str;
  for (; n > 0 && *res != c; n--, res++) {
  }
  return !n ? s21_NULL : res;
}

//  Создаем переменную и приравниваем к нулл на случай если совпадения не будут
//  найдены Создаем переменную и приводим константу стр к обычному чару Создаем
//  счетчик и приравниваем к нулю Пока темп не равен концу строки пробекаем по
//  строке Если темп итое равняется символу 'c' и меньше н байт Рес равен адресу
//  первого вхождения символа Прибавляем + 1 к счетчику Возвращаем рес

/*Функция сравнивает первые n байтов блока памяти указателя str1 с первыми n
байтами блока памяти str2.
Возвращаемое значение 0 если блоки равны, и значение отличное от 0, если  блоки
не равны.*/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  char *temp1 = (char *)str1;
  char *temp2 = (char *)str2;
  s21_size_t i = 0;
  while (i < n && result == 0) {
    if (temp1[i] != temp2[i]) {
      result = temp1[i] - temp2[i];
    }
    i++;
  }
  return result;
}

// Заводим переменную и приравниваем к 0
// Заводим переменную и приводим константу к чару
// -//-
// Заводим счетчик для цикла
// Пока счетчик меньше н байт
// Если значения темп1 не равны значению темп2
// Рес равен темп1 - темп2
// Прибавляем +1 к счетчику
// Возвращаем рес

/* Возвращаемое значение:
Функция возвращает указатель на массив, в который скопированы данные.
Описание:
Функция memcpy копирует n байт из массива (области памяти), на который
указывает аргумент source, в массив (область памяти), на который
указывает аргумент destination. Если массивы перекрываются,
результат копирования будет не определен. */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i = 0;
  char *temp = dest;
  char *s = (char *)src;
  while (i < n) {
    i++;
    *temp++ = *s++;
  }
  return dest;
}
// Заводим счетчик для цикла
// Заводим переменную для работы с ней
// Приводим срц к чару
// Пока счетчик меньше н байт
// Счетчик +1
// Каждый следующий элемент темп равен следующему элементу массива с
// Возвращаем указатель на массив

/* Возвращаемое значение:
Функция возвращает указатель на массив, в который скопированы данные.
Описание:
Функция memmove копирует n байт из массива (области памяти), на который
указывает аргумент source, в массив (область памяти), на который указывает
аргумент destination. При этом массивы (области памяти) могут пересекаться */
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  const char *s;
  char *d;
  d = dest;
  s = src;
  if (d < s) {
    while (n--) *d++ = *s++;
  } else {
    const char *lastS = s + (n - 1);
    char *lastD = d + (n - 1);
    while (n--) *lastD-- = *lastS--;
  }
  return dest;
}
// Заводим константный чар массив для срц
// Заводим константный чар массив для указателя на последний байт срц
//  --//--
// --//--
// Приравниваем d к дест
// Приравниваем с к срц
// Если д меньше с
// Пока н больне нуля отнимаем -1
// Каждый следующий элемент д равен каждому следующуему элементу с
// Указатель на последний байт блока s
// Указатель на последний байт блока d
// n раз
// После копирования байта указатели уменьшаются
// Возвращаем дест

// Заполняет первые н байт области памяти в стр символом с
void *s21_memset(void *str, int c, s21_size_t n) {
  if (str) {
    char *ch = (char *)str;
    while (n--) {
      *ch++ = c;
    }
  }
  return str;
}
// Если стр тру (то есть в стр есть данные)
// Заводим переменную для работы и приравниваем стр к чар
// Пока н больше 0 (пока н тру)
// Каждый следующий символ строки(массива) ч равен символу с
// Возвращаем строку

// Копирует строку src в КОНЕЦ строки dest
char *s21_strcat(char *dest, const char *src) {
  char *temp = dest;
  while (*dest != '\0') dest++;
  while (((*dest++ = *src++)) != '\0') continue;
  return temp;
}
//  Заводим переменную для работы и приравниваем к дест
//  Пока дест не закончится
//  Прибавляем к индексу дест +1
//  Пока каждый следующий символ дест не будет равен каждому символу срц и пока
//  срц не закончится Продолжаем выполнять операцию Возвращаем строку

// Копирует строку src в КОНЕЦ строки dest в размере n символов
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *temp = dest;
  while (*dest != '\0') dest++;
  for (s21_size_t i = 0; i < n; i++) {
    *dest = *src;
    dest++;
    src++;
  }
  return temp;
}
// Заводим массив для работы и приравниваем к дест
//  Пока дест не закончится
//  Прибавляем к индексу +1
//  Пока счетчик меньше н байт прибавляем +1
//  Символ в дест равен символу в срц
//  Прибавляем к индексу дест +1
//  Прибавляем к индексу срц +1
//  Возвращаем строку

// Находит ПЕРВОЕ ВХОЖДЕНИЕ  символа  'с' в строке 'str'
char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1 && !res; i++) {
    if (str[i] == c) res = (char *)str + i;
  }
  return res;
}

//  Создаем массив рес и приравниваем к нулл на случай, если совпадений не будет
//  найдено Пока стр не равен концу строки проходим по циклу Если символ из
//  массива стр равен символу с Рес равен адресу индекса массива стр (стр
//  приводим к обычному чару) В ином случае прибавляем +1 к индексу стр
//  Возвращаем рес

// Сравнивает строки. Если равны - возвращает 0. Отрицательное число если s2
// больше. Положительное число если str1 больше
int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  unsigned char s1, s2;
  while (1) {
    s1 = *str1++;
    s2 = *str2++;
    if (s1 == '\0') {
      break;
    }
    if (s1 != s2) break;
  }
  res = s1 - s2;
  return res;
}
// Заводим переменную и приравниваем к 0
// Заводим безнаковые переменные с1 и с2
// Запускаем бесконечный цикл
// с1 приравниваем к следующему индексу стр
// с2 приравниваем к следующему индексу стр2
// Если конец строки с1
// Выходим из цикла
// Если с1 не равен с2
// Выходим из цикла
// Приравниваем рес к разности с1 минус с2
// Возвращаем результат

// Сравнивает строки. Если равны - возвращает 0. Отрицательное число если s2
// больше. Положительное число если str1 больше до n символов
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  unsigned char s1 = 0;
  unsigned char s2 = 0;
  s21_size_t i = 0;
  while (i < n) {
    s1 = *str1++;
    s2 = *str2++;
    if (s1 == '\0') {
      break;
    }
    if (s1 != s2) break;
    i++;
  }
  res = s1 - s2;
  return res;
}
// Заводим переменную рес и приравниваем к 0
// Заводи две беззнаковые переменные
// Создаем счетчик для цикла
// Пока счетчик меньше н
// с1 приравниваем к следующему индексу стр
// с2 приравниваем к следующему индексу стр2
// Если с1 не равен с2
// Выходим из цикла
// Если с1 не равен с2
// Выходим из цикла
// Добавляем к счетчику +1
// Рес равен с1 минус с2
// Возвращем результат

// Копирует строку src в dest включая нулевой символ
char *s21_strcpy(char *dest, const char *src) {
  char *temp = dest;
  while (*src != '\0') {
    *dest++ = *src++;
  }
  *dest = '\0';
  return temp;
}
// Создаем массив для работы и приравниваем его к дест
// Пока каждый символ дест равен каждому символу срц и при этом цикл не дошел до
// конца строк Продолжаем операцию Последний элемент массива дест приравниваем к
// концу строки Возвращаем строку

// Копирует строку src в dest включая нулевой символ в размере n символов
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *temp = dest;
  for (s21_size_t i = 0; i < n; i++) {
    *dest = *src;
    dest++;
    src++;
  }
  return temp;
}
// Создаем массив для работы и приравниваем его к дест
// Запускаем цикл до н символом
// каждый символ дест приравниваем к символу срц
// Идем дальше по массиву на 1
// --//--
// Возвращаем строку

// Возвращает длину начального участка строки стр1, не
// содержащая символов в стр2
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int count = 0;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);
  s21_size_t flazhina = 0;
  s21_size_t i, j;
  for (i = 0; i < len_str1 && !flazhina; i++) {
    for (j = 0; j < len_str2 && !flazhina; j++) {
      if (str1[i] == str2[j]) {
        flazhina = 1;
      }
    }
    if (!flazhina) count++;
  }
  return count;
}

// Создаем константные массивы для работы с ними
// Приравниваем массив с1 к стр1
// Приравниваем массив с2 к стр2
// Создаем флаг для выхода из первого цикла
// Вычисляем длину строки стр1
// Вычисляем длину строки стр2
// Создаем переменные для циклов
// Запускаем цикл Пока счетчик меньше длины строки стр1 и флаг не равен 0
// Запускаем второй цикл пока счетчик меньше длины строки стр2
// Если итый символ стр1 равен житому символу стр2
// флаг делаем равный 0
// отнимаем 1 от счетчика (потому что нам нужен предудущий элемент, где еще не
// было совпадений) Возвращаем номер последнего индекса до совпадения элементов

// Возвращает сообщение с номером ошибки
char *s21_strerror(int errnum) {
  static char msg_err[100];
  if (errnum >= 0 && errnum <= errnum_l - 1) {
    s21_strcpy(msg_err, s21_sys_errlist[errnum]);
  } else {
    s21_sprintf(msg_err, unknown, errnum);
  }
  return msg_err;
}
// Заводим статический массив для вывода сообщения об обшибке, которое не входит
// в стандартный Если номер ошибки больше 0 и меньше 106 (134 для линукса)
// Копируем номер ошибки в мсг_ерр
// Иначе
// Копируем в мсг_ерр сообщение и номером ошибки
// Возвращам массив

// Находит длину строки
s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  for (; str[count]; count++) {
  }
  return count;
}
// Создаем счетчик
// Пока строка не закончится
// К счетчику прибавляем +1
// Возвращем значение счетчика

// Находит первое вхождение в строке str1 из НАБОРА ЭЛЕМЕНТОВ str2
char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);
  for (s21_size_t i = 0; i < len_str1 && !res; i++) {
    for (s21_size_t j = 0; j < len_str2 && !res; j++) {
      if (str1[i] == str2[j]) res = (char *)str1 + i;
    }
  }
  return res;
}
// Создаем массив рес для работы и приравниваем к нулл, если не будет найдено
// совпадений Создаем флаг для выхода из цикла Пока стр1 не дойдет до конца и
// флаг больше 0 Создаем конста массив для работы и приравниваем его к стр2
// Запускаем второй цикл во второй строке пока последний элемент не будет равен
// концу строки Если значения элементов строк с и стр1 равны Устанавливаем флаг
// 0 для выхода из циклов Иначе прибавляем к индексу +1 в строке стр1 и снова
// идем по циклу Рес равен значению адреса стр1 - 1 после выхода из цикла (так
// как был прибавлен индекс +1 после выхода из первого цикла) Возвращаем рес

// Находит ПОСЛЕДНЕЕ ВХОЖДЕНИЕ  символа  'с' в строке 'str'
char *s21_strrchr(const char *str, int c) {
  char *res;
  char sym = c;
  for (res = s21_NULL;; ++str) {
    if (*str == sym) res = (char *)str;
    if (*str == '\0') return res;
  }
}
// Создаем константный чар и приравниваем к нулл
// Вычисляем длину строки стр
// Создаем константный массив начинающийся с конца массива
// Пока п больше нуля
// Если элементы массива п равен символу с
// Рес равен п
// Отнимаем от индекса п -1
// Возвращаем рес

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2. Если первым символом строки str не входит в строку str2, то
// возвращаемая длина – 0
s21_size_t s21_strspn(const char *str1, const char *str2) {
  const char *s1, *s2;
  s21_size_t count = 0;
  for (s1 = str1; *s1 != '\0'; ++s1) {
    for (s2 = str2; *s2 != '\0'; ++s2) {
      if (*s1 == *s2) break;
    }
    if (*s2 == '\0')
      break;
    else
      ++count;
  }
  return count;
}
// Создаем константные массивы для работы
// Создаем счетчик для подсчета длины
// Запускам первый цикл по строке с1 пока с1 не будет равна концу строки
// Запускаем второй цикл по строке с2
// Если символ строки с1 равен символу строки с2
// Выходим из первого цикла
// Первый цикл продолжается и пока символ строки с2 не будет равен концу строки
// Делаем выход из цикла
// В ином случае добавляем к счетчику +1
// Возвращаем счетчик

// Находит первый элемент подстроки needle в строке heystack
// NULL – если подстрока needly не входит в строку heystack.
char *s21_strstr(const char *haystack, const char *needle) {
  int flagzo = 0;
  char *str = s21_NULL;
  if (!*needle) {
    str = (char *)haystack;
    flagzo = 1;
  }
  s21_size_t len1 = s21_strlen(haystack);
  s21_size_t len2 = s21_strlen(needle);
  for (s21_size_t i = 0; i < len1 && !flagzo; i++) {
    s21_size_t count = 0;
    for (s21_size_t j = 0; j < len2; j++) {
      str = (char *)(haystack + i);
      while (i < len1 && j < len2 && haystack[i] == needle[j]) {
        i++;
        j++;
        count++;
      }
      if (count == len2) flagzo = 1;
    }
  }
  return flagzo ? str : s21_NULL;
}
// Создаем массив рес и приравниваем к нулл, на случай, если совпадения не будет
// Создаем массивы для работы
// темп2 приравниваем к строке, которую ищем
// Если темп2 пустой
// Рес равен первому элементу массива хейстэк
// Запускаем цикл пока не дойдем до конца строки хейстек
// Если элемент массива хейстек не равен элементу массива темп2
// Продолжаем поиск
// При нахождении приравниваем хэйстек к темп1
// Запускаем бесконечный цикл
// Если темп2 пустой
// Рес равен первому элементу массива хэйстек
// Если при сравнении темп1 и темп2 находятся расхождения
// Выходим из цикла
// Приравниваем темп2 к строке, которую ищем
// Возвращаем рес

// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim) {
  char *leks = s21_NULL;
  static char *token = s21_NULL;
  if (str == s21_NULL) str = token;
  if (str != s21_NULL) {
    int flagos = 0;
    int i = 0;
    int buff[256] = {0};
    while (*delim) buff[(int)*delim++]++;
    while ((str[i]) && (flagos == 0)) {
      if (buff[(int)str[i]] < 1 && leks == s21_NULL) leks = &str[i];
      if (buff[(int)str[i]] > 0) {
        str[i] = '\0';
        i++;
        while (buff[(int)str[i]]) i++;
        token = &str[i];
        flagos = 1;
      }
      i++;
    }
    if (!flagos) token = s21_NULL;
  }
  return leks;
}
// Заводим массив рес и приравниваем его к нулл для последующего
// переиспользования в функции Заводим флаг для выхода из цикла Заводим
// статический массив, чтобы в нем могло сохраниться значение токена при
// использовании функции несколько раз Если значение стр равно нулл Стр будет
// равно предыдущему токену Пока флаг тру и последний элемент стр не равен концу
// строки Запускаем второй цикл по делим Если есть совпадение между стр и делим
// Стр итое равно первому токену
// Приравнием рес к стр
// Токен равен адресу массива стр после нахождения совпадения
// Флаг приравниваем к 0 для выхода из массива
// Если итое значение равно 0
// Рес равен вхождению токена в строке стр
// Если после цикла последнее вхождение равно концу строки
// Приравниваем рес к стр
// Токен равен адресу массива стр по нахождения совпадения
// Флаг 0 для выхода из цикла
// Возвращаем рес

// Возвращает копию строки (str), преобразованной в верхний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str) {
  char *res = s21_NULL;
  if (str) {
    s21_size_t len_str = s21_strlen(str);
    res = (char *)malloc(sizeof(char) * (len_str + 1));
    if (res) {
      s21_strcpy(res, str);
      for (char *temp = res; *temp; temp++) {
        if (*temp >= 'a' && *temp <= 'z') *temp -= 32;
      }
    }
  }
  return (void *)res;
}
// Cоздаем массив для работы и приравниваем к нулл на случай ошибки
// Создаем массив и кастуем константный массив стр к чару
// Если строка стр не пустая
// Заводим счетчик для цикла
// Пока индекс элемента строки темп не будет равен элементу конца строки
// Если в строке темп встречаются буквы нижнего регистра
// Удаляем их из строки и добавляем буквы верхнего регистра
// рес приравниваем к массиву темп
// возвращаем рес

// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
  char *res = s21_NULL;
  if (str) {
    s21_size_t len_str = s21_strlen(str);
    res = (char *)malloc(sizeof(char) * (len_str + 1));
    if (res != s21_NULL) {
      s21_strcpy(res, str);
      for (char *temp = res; *temp; temp++) {
        if (*temp >= 'A' && *temp <= 'Z') *temp += 32;
      }
    }
  }
  return (void *)res;
}
// Cоздаем массив для работы и приравниваем к нулл на случай ошибки
// Создаем массив и кастуем константный массив стр к чару
// Если строка стр не пустая
// Заводим счетчик для цикла
// Пока индекс элемента строки темп не будет равен элементу конца строки
// Если в строке темп встречаются буквы верхнего регистра
// Удаляем их из строки и добавляем буквы верхнего регистра
// рес приравниваем к массиву темп
// возвращаем рес

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *temp_src;
  char *temp_str = (char *)str;
  if (s21_NULL == src || s21_NULL == str || start_index > (s21_strlen(src))) {
    temp_src = s21_NULL;
  } else {
    temp_src = (char *)calloc(s21_strlen(src), s21_strlen(str) + 1);
    s21_memmove(temp_src, src, start_index);
    temp_src[start_index] = '\0';
    s21_strcat(temp_src, temp_str);
    s21_strcat(temp_src, src + start_index);
  }
  return temp_src;
}

// Выделяем памать для строки, чтобы вместить туда и изначальную строку, и
// вставку Заводим массив для работы и кастуем стр к чару Если стр или срц нулл,
// или начальный индекс больше длины строки Возвращаем нулл Копируем в темп_срц
// данные из срц до индекса начала вставки Элемент темп_срц начала вставки
// делаем последним элементов Добавляем в конец темп_срц строку вставки После
// добавляем в конец темп_срц оставшуюся часть строки срц Возвращаем результат

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src).
// В случае какой-либо ошибки следует вернуть значение NULL
s21_size_t s21_right_strspn(const char *str1, const char *str2) {
  int count = 0;
  int check = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  for (s21_size_t k = 0; k < len2; k++) {
    if (str1[len1 - 1] == str2[k]) check++;
  }
  int flagzen = 1;
  for (s21_size_t i = len1 - 1; i > 0 && flagzen; i--) {
    flagzen = 0;
    for (s21_size_t j = 0; j < len2 && !flagzen; j++) {
      if (str1[i] == str2[j]) {
        count++;
        flagzen = 1;
      }
    }
  }
  return !check ? 0 : count;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim_str = s21_NULL;
  char *temp_trim = (char *)trim_chars;
  char *temp_src = (char *)src;
  if (!src) {
  } else {
    char trim_empty[7] = " \t\n\v\f\r\0";
    if (!temp_trim || s21_strlen(temp_trim) == 0) {
      temp_trim = trim_empty;
    }
    s21_size_t len = s21_strlen(temp_src);
    s21_size_t count_start = s21_strspn(temp_src, temp_trim);
    if (len == 0 || len == count_start) {
      trim_str = (char *)malloc(sizeof(char));
      trim_str[0] = '\0';
    } else {
      s21_size_t count_end = s21_right_strspn(temp_src, temp_trim);
      s21_size_t string = len - count_start - count_end;
      trim_str = (char *)malloc((string + 1) * sizeof(char));
      for (s21_size_t i = 0; i < string; i++)
        trim_str[i] = src[i + count_start];
      trim_str[string] = '\0';
    }
  }
  return (void *)trim_str;
}

void s21_itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  s21_reverse(s);
}

void s21_reverse(char s[]) {
  int i, j;
  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

struct spes_params {
  char flag[80];
  int width;
  int accuracy;
  char length;
  char specifier;
  char start[1024 * 10];
} par;

void write_to_string(struct spes_params *p, char *str, int i,
                     const char *format, ...);
void all_flag(struct spes_params *par, int i, char *str);
void flag_plus(char *str);
void flag_space(char *str);
void flag_sharp(char *str, ...);
void flag_zero(char *str, ...);
void all_specifier(struct spes_params *par, int i, char *str, ...);
void spec_d(char *str, int n);
void spec_c(char *str, int n);
void spec_i(char *str, int n);
void spec_f(char *str, double d, struct spes_params *par, int i);
void spec_s(char *str, char *s, struct spes_params *par, int i);
void spec_u(char *str, unsigned int n);
void spec_procent(char *str);
void all_width(int i, struct spes_params *par, char *str);
void all_accuracy(int i, struct spes_params *par, char *str);
void parcing_string(struct spes_params *par, const char *format);
void s21_itoa(int n, char s[]);
void s21_reverse(char s[]);
int how_many_procent(const char *format);

const char *flag = "-+ ";
const char *length = "hl";
const char *specifier = "cdifsu%";
const char *specifier_noprocent = "cdifsu";
const char *accuracy = ".";
// %[флаги][ширина][.точность][длина]спецификатор

int s21_sprintf(char *str, const char *format, ...) {
  int x = how_many_procent(format);
  struct spes_params p[x];

  for (int a = 0; str[a] != '\0'; a++)
    str[a] = '\0';               // очищаем выходную строку
  for (int r = 0; r < x; r++) {  // очищаем весь массив структур
    *p[r].flag = '\0';
    p[r].width = 0;
    p[r].accuracy = 0;
    p[r].length = '\0';
    p[r].specifier = '\0';
    *p[r].start = '\0';
  }

  parcing_string(p, format);

  va_list argument;
  va_start(argument, format);

  int i = 0;
  for (i = 0; i < x; i++) {
    if (p[i].specifier == 's') {
      char *n = va_arg(argument, char *);
      write_to_string(p, str, i, format, n);
    } else if (p[i].specifier == 'f') {
      double n = va_arg(argument, double);
      write_to_string(p, str, i, format, n);
    } else if (p[i].specifier == '%') {
      write_to_string(p, str, i, format);
    } else {
      int n = va_arg(argument, int);
      if (p[i].length == 'l') {
        n = (long)n;
      } else if (p[i].length == 'h') {
        n = (short)n;
      }
      write_to_string(p, str, i, format, n);
    }
  }

  int count = 0;
  char buf[1000];
  for (format += (s21_strlen(format) - 1);; format--) {
    if (*format == p[x - 1].specifier) break;
    count++;
  }
  for (format += (s21_strlen(format));; format--, count--) {
    if (*format == p[x - 1].specifier) break;
    buf[count] = *format;
  }
  str += s21_strlen(str);
  s21_strcat(str, buf);

  va_end(argument);

  return 0;
}

void write_to_string(struct spes_params *p, char *str, int i,
                     const char *format, ...) {
  va_list argument;
  va_start(argument, format);

  int procent = 0;

  //  перемещаем указатели выходной и форматной строки
  str += s21_strlen(str);
  format += s21_strlen(p->start);

  //  запись в выходную строку мусора из строки формата
  for (int n = 0; *format != '\0'; format++, n++) {
    if (*format != '%' || *(format - 1) == '%') {
      if (procent == 0) {
        *str = *format;
        str++;
      }
      while (p->start[n] != '\0') n++;
      p->start[n] = *format;  //  запоминаем пройденную часть строки формата
    }
    if (*format == '%' && procent == 0) {
      procent++;
      //  перемещаем индекс мусорной строки до свободного места
      while (p->start[n] != '\0') n++;
      p->start[n] = *format;
    } else if (s21_strchr(specifier, *format) && procent > 0) {
      break;
    }
  }

  if (p[i].specifier == 's') {
    char *n = va_arg(argument, char *);
    all_specifier(p, i, str, n);
  } else if (p[i].specifier == 'f') {
    double d = va_arg(argument, double);
    all_specifier(p, i, str, d);
  } else if (p[i].specifier == '%') {
    all_specifier(p, i, str);
  } else {
    int n = va_arg(argument, int);
    all_specifier(p, i, str, n);
  }

  if (p[i].accuracy != '\0') all_accuracy(i, p, str);

  if (p[i].flag[0] != '\0') all_flag(p, i, str);

  if (p[i].width != '\0') all_width(i, p, str);

  va_end(argument);
}

void parcing_string(struct spes_params *par, const char *format) {
  int i = 0;
  while (*format != '\0') {
    if (*format == '%') {
      int stage = 0;
      int tc = 0;
      format++;
      if (s21_strchr(flag, *format) && stage < 1) {
        if (par[i].specifier != '\0') i++;
        par[i].flag[0] = *format;
        stage = 1;
        format++;
        if (s21_strchr(flag, *format)) {
          par[i].flag[1] = *format;
          format++;
        }
        if (s21_strchr(flag, *format)) {
          par[i].flag[2] = *format;
          format++;
        }
      }
      if (*format == '.' || s21_strchr(length, *format) ||
          s21_strchr(specifier, *format)) {
        tc = 1;
      }
      if (tc == 0 && stage < 2) {
        int wid;
        wid = *format - '0';
        format++;
        if ((*format - '0') >= 0 && (*format - '0') <= 9) {
          wid = wid * 10 + (*format - '0');
          format++;
        }
        if (par[i].specifier != '\0') i++;
        par[i].width = wid;
        stage = 2;
      }

      if (s21_strchr(accuracy, *format) && stage < 3) {
        int acc;
        format++;
        acc = *format - '0';
        format++;
        if ((*format - '0') >= 0 && (*format - '0') <= 9) {
          acc = acc * 10 + (*format - '0');
          format++;
        }
        if (par[i].specifier != '\0') i++;
        par[i].accuracy = acc;
        stage = 3;
      }

      if (s21_strchr(length, *format) && stage < 4) {
        if (par[i].specifier != '\0') i++;
        par[i].length = *format;
        format++;
        stage = 4;
      }

      if (s21_strchr(specifier, *format) && stage < 5) {
        if (par[i].specifier != '\0') i++;
        par[i].specifier = *format;
        format++;
        stage = 5;
      }
    }
    format++;
  }
}

void all_accuracy(int i, struct spes_params *par, char *str) {
  int minus = 0, plus = 0;

  if (str[0] == ('-')) minus = 1;
  if (str[0] == ('+')) plus = 1;

  switch (par[i].specifier) {
    case 'u':
    case 'i':
    case 'd':
      if (minus == 1 || plus == 1) {
        if ((int)s21_strlen(str) < par[i].accuracy) {
          while ((int)s21_strlen(str) != par[i].accuracy + 1) {
            for (int k = s21_strlen(str); k > 0; k--) {
              str[k] = str[k - 1];
              str[0] = '0';
            }
          }
        }
        if (minus == 1) {
          str[0] = '-';
        }
        if (plus == 1) {
          str[0] = '+';
        }
      } else {
        if ((int)s21_strlen(str) < par[i].accuracy) {
          while ((int)s21_strlen(str) != par[i].accuracy) {
            for (int v = s21_strlen(str); v > 0; v--) {
              str[v] = str[v - 1];
            }
            str[0] = '0';
          }
        }
      }
      break;
  }
}

void all_width(int i, struct spes_params *par, char *str) {
  int minus = 0;
  int flag_min = 0;
  int size = s21_strlen(str);

  for (int k = 0; str[k] != '\0'; k++) {
    if (str[k] == '-') minus = 1;
  }

  for (int v = 0; v < 3; v++) {
    if (par[i].flag[v] == '-') flag_min = 1;
  }

  if (flag_min == 0) {
    if ((int)s21_strlen(str) < par[i].width) {
      while ((int)s21_strlen(str) != par[i].width) {
        for (int n = s21_strlen(str) + 1; n > 0; n--) {
          str[n] = str[n - 1];
        }
        str[0] = ' ';
      }
    }
    if (minus == 1) {
      int delta = par[i].width - size;
      str[delta] = '-';
    }
  } else if (flag_min == 1) {
    if ((int)s21_strlen(str) < par[i].width) {
      while ((int)s21_strlen(str) != par[i].width) {
        str[s21_strlen(str)] = ' ';
      }
    }
  }
}

void all_flag(struct spes_params *par, int i, char *str) {
  for (int v = 0; v < 3; v++) {
    if (par[i].flag[v] == '+') flag_plus(str);
    if (par[i].flag[v] == ' ') flag_space(str);
  }
}

void all_specifier(struct spes_params *par, int i, char *str, ...) {
  va_list argument;
  va_start(argument, str);

  int n;
  char *s;
  double d;

  if (par[i].specifier == 's') {
    s = va_arg(argument, char *);
  } else if (par[i].specifier == 'f') {
    d = va_arg(argument, double);
  } else {
    n = va_arg(argument, int);
  }

  switch (par[i].specifier) {
    case 'd':
    case 'i':
      spec_d(str, n);
      break;
    case 'c':
      spec_c(str, n);
      break;
    case 'f':
      spec_f(str, d, par, i);
      break;
    case 's':
      spec_s(str, s, par, i);
      break;
    case 'u':
      spec_u(str, n);
      break;
    case '%':
      spec_procent(str);
      break;
  }

  va_end(argument);
}

// flags

void flag_plus(char *str) {
  int minus = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ('-')) minus = 1;
  }

  if (minus != 1) {
    for (int i = s21_strlen(str); i > 0; i--) {
      str[i] = str[i - 1];
    }
    str[0] = '+';
  }
}

void flag_space(char *str) {
  int flag_mp = 1;

  for (int i = 0; i < (int)s21_strlen(str) - 1; i++) {
    if ((str[i] == '+') || (str[i] == '-')) flag_mp = 0;
  }

  if (flag_mp) {
    for (int i = (int)s21_strlen(str); i >= 0; i--) str[i + 1] = str[i];
    str[0] = ' ';
  }
}

// specifiers

void spec_d(char *str, int n) {
  int minus = 0;
  if (n < 0 && n > -9) {
    minus = 1;
    n *= -1;
  }
  if (n >= 9 || n <= -9) {
    char mas_int[10000] = "\0";
    char *count = mas_int;
    s21_itoa(n, mas_int);
    s21_strcat(str, count);
  } else {
    str += s21_strlen(str);
    if (minus == 1) {
      *str = '-';
      str++;
      *str = n + '0';
    } else {
      *str = n + '0';
    }
  }
}

void spec_c(char *str, int n) {
  str += s21_strlen(str);
  *str = n;
}

void spec_s(char *str, char *s, struct spes_params *par, int i) {
  if (par[i].accuracy != '\0') {
    int count = 0;
    while (*s != '\0') {
      if (count == par[i].accuracy) break;
      *str = *s;
      str++;
      s++;
      count++;
    }
  } else {
    while (*s != '\0') {
      *str = *s;
      str++;
      s++;
    }
  }
}

void spec_f(char *str, double d, struct spes_params *par, int i) {
  char s_val[1000] = "\0";
  char drob_mas[10000] = "\0";

  if (par[i].accuracy == '\0') par[i].accuracy = 6;

  // получить значение одного из аргументов
  int int_val = (int)d;

  // получить его целую часть и записать в буферный массив
  if (d > -10 && d < 10) {
    *s_val = (int)d + '0';
  } else {
    s21_itoa((int)d, s_val);
  }
  s_val[s21_strlen(s_val)] = '.';

  // получить часть после запятой и записать в буферный массив
  unsigned long long int zap_val;
  if (d < 0) {
    zap_val = (d - (double)int_val) * pow(10, par[i].accuracy);
  } else {
    zap_val = (d - (double)int_val) * pow(10, par[i].accuracy) + 1;
  }
  s21_itoa(zap_val, drob_mas);
  if (zap_val == 1) {
    for (int p = 0; p != par[i].accuracy; p++) {
      drob_mas[p] = '0';
    }
  }

  // если число отрицательное, убрать минус из дробной части
  if (drob_mas[0] == '-') {
    char token[10000];
    for (int n = 1; n < (int)s21_strlen(drob_mas); n++) {
      token[n - 1] = drob_mas[n];
    }
    s21_strcat(str, s21_strcat(s_val, token));
  } else {
    // записать целую часть, точку и дробную часть в массив
    s21_strcat(str, s21_strcat(s_val, drob_mas));
  }
}

void spec_u(char *str, unsigned int n) {
  if (n > 9) {
    char mas_int[10000];
    char *count = mas_int;
    int i = 0;

    do {
      mas_int[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    mas_int[i] = '\0';
    s21_reverse(mas_int);

    s21_strcat(str, count);
  } else {
    str += s21_strlen(str);
    *str = n + '0';
  }
}

void spec_procent(char *str) {
  str += s21_strlen(str);
  *str = '%';
}

int how_many_procent(const char *format) {
  int x = 0;
  int flag_xx = 0;
  for (int count = 0; format[count] != '\0'; count++) {
    if (format[count] == '%' && (count - flag_xx) != 1) {
      x++;
      flag_xx = count;
    }
  }
  return x;
}

//

int s21_sscanf(const char *str, const char *format, ...);
int StrToInt(const char *str, int *num_arg, int *num, double *result,
             int width_flag, int *width);
int StrToFloat(const char *str, int *num_arg, long double *float_result,
               int width_flag, int *width);
long double SCItoInt(const char *str, int *num_arg, int width_flag, int *width);
int StrToStr(const char *str, int *num_arg, int *num, char *str_result,
             int width_flag, int *width);
int StrTo16(const char *str, int *num_arg, int *num,
            long unsigned int *result_16bit, int width_flag, int *width);
int StrTo8(const char *str, int *num_arg, int *num, long unsigned int *result_8,
           int width_flag, int *width);
void SpaceBreaker(const char *str, int *num_arg);
int StrToSigNum(const char *str, int *num_arg, int *num,
                long int *result_signum, int width_flag, int *width);
int Flagificator(const char *spec, int *star_flag, int *width_flag, char *len,
                 int *width);
int ParsBraker(int width_flag, int *width);

int s21_sscanf(const char *str, const char *format, ...) {
  int output = 0;
  int num_arg = 0;
  int error_flag = 0;
  double int_result;
  int num;
  long double float_result;
  char *str_result;
  long unsigned int result_16bit;
  long unsigned int result_8;
  long int result_signum;
  int star_flag;
  int width_flag;
  int width;
  char len;
  va_list argument;
  va_start(argument, format);
  for (const char *spec = format; *spec; spec++) {
    if (error_flag != 0) {
      break;
    }
    switch (*spec) {
      case 'i':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if ((error_flag = StrToSigNum(str, &num_arg, &num, &result_signum,
                                      width_flag, &width)) == 0 &&
            star_flag == 0) {
          if (len == 'h') {
            *(va_arg(argument, short int *)) = (short int)result_signum;
          } else if (len == 'l') {
            *(va_arg(argument, long int *)) = result_signum;
          } else {
            *(va_arg(argument, int *)) = (int)result_signum;
          }
          output++;
        }
        break;
      case 'd':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if ((error_flag = StrToInt(str, &num_arg, &num, &int_result, width_flag,
                                   &width)) == 0 &&
            star_flag == 0) {
          if (len == 'h') {
            *(va_arg(argument, short int *)) = (short int)int_result;
          } else if (len == 'l') {
            *(va_arg(argument, long int *)) = (long int)int_result;
          } else {
            *(va_arg(argument, int *)) = (int)int_result;
          }
          output++;
        }
        break;
      case 'c':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if (star_flag == 0) {
          *(va_arg(argument, char *)) = *(str + num_arg);
          output++;
        }
        num_arg++;
        break;
      case 'e':
      case 'E':
      case 'f':
      case 'g':
      case 'G':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if ((error_flag = StrToFloat(str, &num_arg, &float_result, width_flag,
                                     &width)) == 0 &&
            star_flag == 0) {
          if (len == 'L') {
            *(va_arg(argument, long double *)) = float_result;
          } else if (len == 'l') {
            *(va_arg(argument, double *)) = (double)float_result;
          } else {
            *(va_arg(argument, float *)) = (float)float_result;
          }
          output++;
        }
        break;
      case 's':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if (star_flag == 0) {
          str_result = va_arg(argument, char *);
          if ((error_flag = StrToStr(str, &num_arg, &num, str_result,
                                     width_flag, &width)) == 0) {
            output++;
          }
        } else {
          SpaceBreaker(str, &num_arg);
          while (*(str + num_arg) && *(str + num_arg) != ' ' &&
                 *(str + num_arg) != '\n' && *(str + num_arg) != '\t' &&
                 ParsBraker(width_flag, &width) == 0) {
            num_arg++;
          }
        }
        break;
      case 'x':
      case 'X':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if ((error_flag = StrTo16(str, &num_arg, &num, &result_16bit,
                                  width_flag, &width)) == 0 &&
            star_flag == 0) {
          if (len == 'h') {
            *(va_arg(argument, short unsigned int *)) =
                (short unsigned int)result_16bit;
          } else if (len == 'l') {
            *(va_arg(argument, long unsigned int *)) = result_16bit;
          } else {
            *(va_arg(argument, unsigned int *)) = (unsigned int)result_16bit;
          }
          output++;
        }
        break;
      case 'o':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if ((error_flag = StrTo8(str, &num_arg, &num, &result_8, width_flag,
                                 &width)) == 0 &&
            star_flag == 0) {
          if (len == 'h') {
            *(va_arg(argument, short unsigned int *)) =
                (short unsigned int)result_8;
          } else if (len == 'l') {
            *(va_arg(argument, long unsigned int *)) = result_8;
          } else {
            *(va_arg(argument, unsigned int *)) = (unsigned int)result_8;
          }
          output++;
        }
        break;
      case 'u':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if ((error_flag = StrToInt(str, &num_arg, &num, &int_result, width_flag,
                                   &width)) == 0 &&
            star_flag == 0) {
          if (len == 'h') {
            *(va_arg(argument, short unsigned int *)) =
                (short unsigned int)int_result;
          } else if (len == 'l') {
            *(va_arg(argument, long unsigned int *)) =
                (long unsigned int)int_result;
          } else {
            *(va_arg(argument, unsigned int *)) = (unsigned int)int_result;
          }
          output++;
        }
        break;
      case 'n':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if (star_flag == 0) {
          *(va_arg(argument, unsigned int *)) = num_arg;
        }
        break;
      case '%':
        if (*(spec + 1) == '%') {
          SpaceBreaker(str, &num_arg);
          if (*(str + num_arg) == '%') {
            spec++;
            num_arg++;
          } else {
            error_flag = 1;
          }
        }
        break;
      case 'p':
        Flagificator(spec, &star_flag, &width_flag, &len, &width);
        if ((error_flag = StrTo16(str, &num_arg, &num, &result_16bit,
                                  width_flag, &width)) == 0 &&
            star_flag == 0) {
          *(va_arg(argument, void **)) = (void **)result_16bit;
          output++;
        }
        break;
    }
  }
  va_end(argument);
  return output;
}
int StrToInt(const char *str, int *num_arg, int *num, double *result,
             int width_flag, int *width) {
  int error_flag = 0;
  int minus_flag = 0;
  *num = 0;
  SpaceBreaker(str, num_arg);
  if (*(str + *num_arg) == '-' && *(str + *num_arg + 1) != ' ' &&
      *(str + *num_arg + 1) != '\t' && ParsBraker(width_flag, width) == 0) {
    if ((width_flag == 1 && *width > 1) || (width_flag == 0)) {
      minus_flag = 1;
      (*num_arg)++;
    }
  }
  if (*(str + *num_arg) && (*(str + *num_arg) - '0') >= 0 &&
      (*(str + *num_arg) - '0') <= 9) {
    for (const char *i = str + *num_arg;
         *i && (*i - '0') >= 0 && (*i - '0') <= 9; i++) {
      if (ParsBraker(width_flag, width) == 0) {
        (*num)++;
      }
    }
    *result = 0;
    int power = (*num) - 1;
    for (const char *i = str + *num_arg;
         *i && (*i - '0') >= 0 && (*i - '0') <= 9; i++) {
      if (power < 0) {
        break;
      }
      *result += (*i - '0') * pow(10, power);
      power--;
      (*num_arg)++;
    }
    if (minus_flag == 1) {
      (*result) *= -1;
    }
  } else {
    error_flag = 1;
  }
  return error_flag;
}
long double SCItoInt(const char *str, int *num_arg, int width_flag,
                     int *width) {
  long double loc_result = 1;
  int loc_num;
  double loc_power;
  if ((*(str + *num_arg) == 'e' || *(str + *num_arg) == 'E') &&
      ParsBraker(width_flag, width) == 0 && *(str + *num_arg + 1) != ' ') {
    int loc_minus_flag = 0;
    (*num_arg)++;
    if (*(str + *num_arg) == '-' && ParsBraker(width_flag, width) == 0) {
      (*num_arg)++;
      loc_minus_flag = 1;
    }
    if (*(str + *num_arg) == ' ' || *(str + *num_arg) == '\t') {
      (*num_arg)--;
      if (width_flag == 1) {
        (*width)++;
      }
    }
    if (*width == 0) {
      (*width)++;
    }
    if (StrToInt(str, num_arg, &loc_num, &loc_power, width_flag, width) == 0) {
      if (loc_minus_flag == 1) {
        loc_power = -loc_power;
      }
      loc_result = pow(10, loc_power);
    } else {
      if (loc_minus_flag == 1) {
        (*num_arg) -= 2;
        if (width_flag == 1) {
          (*width) += 2;
        }
      } else {
        (*num_arg)--;
        if (width_flag == 1) {
          (*width)++;
        }
      }
    }
  }
  return loc_result;
}
int StrToFloat(const char *str, int *num_arg, long double *float_result,
               int width_flag, int *width) {
  double loc_int_result;
  double ap_result = 0;
  int loc_num = 0;
  int loc_error_flag = 0;
  if ((loc_error_flag = StrToInt(str, num_arg, &loc_num, &loc_int_result,
                                 width_flag, width)) == 0) {
    if (*(str + *num_arg) == '.' && *(str + *num_arg + 1) != ' ' &&
        ParsBraker(width_flag, width) == 0) {
      (*num_arg)++;
      if (StrToInt(str, num_arg, &loc_num, &ap_result, width_flag, width) ==
          0) {
        if (loc_int_result >= 0) {
          *float_result = loc_int_result + (ap_result / pow(10, loc_num));
        } else {
          *float_result = loc_int_result - (ap_result / pow(10, loc_num));
        }
      } else {
        *float_result = loc_int_result;
      }
    } else {
      *float_result = loc_int_result;
    }
  } else if (*(str + *num_arg) == '.' && *(str + *num_arg + 1) != ' ' &&
             ParsBraker(width_flag, width) == 0) {
    (*num_arg)++;
    if ((loc_error_flag = StrToInt(str, num_arg, &loc_num, &ap_result,
                                   width_flag, width)) == 0) {
      *float_result = ap_result / pow(10, loc_num);
    }
  }
  if (loc_error_flag == 0 && ParsBraker(width_flag, width) == 0) {
    (*float_result) *= SCItoInt(str, num_arg, width_flag, width);
  }
  return loc_error_flag;
}
int StrToStr(const char *str, int *num_arg, int *num, char *str_result,
             int width_flag, int *width) {
  *num = 0;
  int error_flag = 0;
  SpaceBreaker(str, num_arg);
  if (str_result) {
    while (*(str + *num_arg) && *(str + *num_arg) != ' ' &&
           *(str + *num_arg) != '\n' && *(str + *num_arg) != '\t' &&
           ParsBraker(width_flag, width) == 0) {
      *(str_result + *num) = *(str + *num_arg);
      (*num_arg)++;
      (*num)++;
    }
    *(str_result + *num) = '\0';
  } else {
    error_flag = 1;
  }
  return error_flag;
}
int ParsBraker(int width_flag, int *width) {
  int flag_pb = 0;
  if (width_flag == 1 && *width < 0) {
    flag_pb = 1;
  } else if (width_flag == 1 && *width >= 0) {
    (*width)--;
    if (*width == -1) {
      flag_pb = 1;
    }
  }
  return flag_pb;
}
int StrTo16(const char *str, int *num_arg, int *num,
            long unsigned int *result_16bit, int width_flag, int *width) {
  int error_flag = 0;
  int pref_flag = 0;
  int sig_flag = 0;
  *num = 0;
  SpaceBreaker(str, num_arg);
  if (*(str + *num_arg) == '-' && ParsBraker(width_flag, width) == 0) {
    sig_flag = 1;
    (*num_arg)++;
  }
  if (*(str + *num_arg) == '0' && ParsBraker(width_flag, width) == 0) {
    (*num_arg)++;
    if ((*(str + *num_arg) == 'X' || *(str + *num_arg) == 'x') &&
        ParsBraker(width_flag, width) == 0 && *(str + *num_arg + 1) != ' ') {
      (*num_arg)++;
      pref_flag = 1;
      *result_16bit = 0;
    } else {
      (*num_arg)--;
      (*width)++;
    }
  }
  for (const char *i = str + *num_arg;
       *i == '0' || *i == '1' || *i == '2' || *i == '3' || *i == '4' ||
       *i == '5' || *i == '6' || *i == '7' || *i == '8' || *i == '9' ||
       *i == 'a' || *i == 'A' || *i == 'b' || *i == 'B' || *i == 'c' ||
       *i == 'C' || *i == 'd' || *i == 'D' || *i == 'e' || *i == 'E' ||
       *i == 'f' || *i == 'F';
       i++) {
    if (ParsBraker(width_flag, width) == 0) {
      (*num)++;
    }
  }
  if (*num != 0) {
    (*num)--;
    *result_16bit = 0;
    for (const char *i = str + *num_arg;
         *i == '0' || *i == '1' || *i == '2' || *i == '3' || *i == '4' ||
         *i == '5' || *i == '6' || *i == '7' || *i == '8' || *i == '9' ||
         *i == 'a' || *i == 'A' || *i == 'b' || *i == 'B' || *i == 'c' ||
         *i == 'C' || *i == 'd' || *i == 'D' || *i == 'e' || *i == 'E' ||
         *i == 'f' || *i == 'F';
         i++) {
      if (*num < 0) {
        break;
      }
      (*num_arg)++;
      switch (*i) {
        case '0':
          (*num)--;
          break;
        case '1':
          (*result_16bit) += pow(16, *num);
          (*num)--;
          break;
        case '2':
          (*result_16bit) += 2 * pow(16, *num);
          (*num)--;
          break;
        case '3':
          (*result_16bit) += 3 * pow(16, *num);
          (*num)--;
          break;
        case '4':
          (*result_16bit) += 4 * pow(16, *num);
          (*num)--;
          break;
        case '5':
          (*result_16bit) += 5 * pow(16, *num);
          (*num)--;
          break;
        case '6':
          (*result_16bit) += 6 * pow(16, *num);
          (*num)--;
          break;
        case '7':
          (*result_16bit) += 7 * pow(16, *num);
          (*num)--;
          break;
        case '8':
          (*result_16bit) += 8 * pow(16, *num);
          (*num)--;
          break;
        case '9':
          (*result_16bit) += 9 * pow(16, *num);
          (*num)--;
          break;
        case 'a':
        case 'A':
          (*result_16bit) += 10 * pow(16, *num);
          (*num)--;
          break;
        case 'b':
        case 'B':
          (*result_16bit) += 11 * pow(16, *num);
          (*num)--;
          break;
        case 'c':
        case 'C':
          (*result_16bit) += 12 * pow(16, *num);
          (*num)--;
          break;
        case 'd':
        case 'D':
          (*result_16bit) += 13 * pow(16, *num);
          (*num)--;
          break;
        case 'e':
        case 'E':
          (*result_16bit) += 14 * pow(16, *num);
          (*num)--;
          break;
        case 'f':
        case 'F':
          (*result_16bit) += 15 * pow(16, *num);
          (*num)--;
          break;
        default:
          break;
      }
    }
    if (sig_flag == 1) {
      (*result_16bit) *= -1;
    }
  } else {
    if (pref_flag == 0) {
      error_flag = 1;
    }
  }
  return error_flag;
}
int StrTo8(const char *str, int *num_arg, int *num, long unsigned int *result_8,
           int width_flag, int *width) {
  int error_flag = 0;
  int pref_flag = 0;
  int sig_flag = 0;
  *num = 0;
  SpaceBreaker(str, num_arg);
  if (*(str + *num_arg) == '-' && ParsBraker(width_flag, width) == 0) {
    sig_flag = 1;
    (*num_arg)++;
  }
  if (*(str + *num_arg) == '0' && ParsBraker(width_flag, width) == 0) {
    (*num_arg)++;
    pref_flag = 1;
    *result_8 = 0;
  }
  for (const char *i = str + *num_arg;
       *i == '0' || *i == '1' || *i == '2' || *i == '3' || *i == '4' ||
       *i == '5' || *i == '6' || *i == '7';
       i++) {
    if (ParsBraker(width_flag, width) == 0) {
      (*num)++;
    }
  }
  if (*num != 0) {
    (*num)--;
    *result_8 = 0;
    for (const char *i = str + *num_arg;
         *i == '0' || *i == '1' || *i == '2' || *i == '3' || *i == '4' ||
         *i == '5' || *i == '6' || *i == '7';
         i++) {
      if (*num < 0) {
        break;
      }
      (*num_arg)++;
      switch (*i) {
        case '0':
          (*num)--;
          break;
        case '1':
          (*result_8) += pow(8, *num);
          (*num)--;
          break;
        case '2':
          (*result_8) += 2 * pow(8, *num);
          (*num)--;
          break;
        case '3':
          (*result_8) += 3 * pow(8, *num);
          (*num)--;
          break;
        case '4':
          (*result_8) += 4 * pow(8, *num);
          (*num)--;
          break;
        case '5':
          (*result_8) += 5 * pow(8, *num);
          (*num)--;
          break;
        case '6':
          (*result_8) += 6 * pow(8, *num);
          (*num)--;
          break;
        case '7':
          (*result_8) += 7 * pow(8, *num);
          (*num)--;
          break;
        default:
          break;
      }
    }
    if (sig_flag == 1) {
      (*result_8) *= -1;
    }
  } else {
    if (pref_flag == 0) {
      error_flag = 1;
    }
  }
  return error_flag;
}
void SpaceBreaker(const char *str, int *num_arg) {
  while (*(str + *num_arg) == ' ' || *(str + *num_arg) == '\t') {
    (*num_arg)++;
  }
}
int StrToSigNum(const char *str, int *num_arg, int *num,
                long int *result_signum, int width_flag, int *width) {
  int sig_flag = 0;
  int error_flag = 0;
  long unsigned int loc_result16 = 0;
  long unsigned int loc_result8 = 0;
  double loc_result10 = 0;
  SpaceBreaker(str, num_arg);
  if (*(str + *num_arg) == '-') {
    sig_flag = 1;
    (*num_arg)++;
  }
  if (*(str + *num_arg) == '0') {
    (*num_arg)++;
    if (*(str + *num_arg) == 'x' || *(str + *num_arg) == 'X') {
      (*num_arg)--;
      if ((error_flag = StrTo16(str, num_arg, num, &loc_result16, width_flag,
                                width)) == 0) {
        *result_signum = loc_result16;
      }
    } else {
      (*num_arg)--;
      if ((error_flag = StrTo8(str, num_arg, num, &loc_result8, width_flag,
                               width)) == 0) {
        *result_signum = loc_result8;
      }
    }
  } else {
    if ((error_flag = StrToInt(str, num_arg, num, &loc_result10, width_flag,
                               width)) == 0) {
      *result_signum = loc_result10;
    }
  }
  if (error_flag == 0 && sig_flag == 1) {
    (*result_signum) *= -1;
  }
  return error_flag;
}
int Flagificator(const char *spec, int *star_flag, int *width_flag, char *len,
                 int *width) {
  *star_flag = 0;
  *width_flag = 0;
  *width = 0;
  *len = 'N';
  int i = 0;
  for (const char *c = spec - 1; *c != '%'; c--) {
    if (*c == 'h' || *c == 'l' || *c == 'L') {
      *len = *c;
    } else if (*c == '*') {
      *star_flag = 1;
    } else if ((*c - '0') >= 0 && (*c - '0') <= 9) {
      *width_flag = 1;
      while ((*(c - i) - '0') >= 0 && (*(c - i) - '0') <= 9) {
        *width += ((*(c - i) - '0') * pow(10, i));
        i++;
      }
      if (*width == 0) {
        *width_flag = 0;
      }
    }
  }
  return 0;
}
