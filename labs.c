#include <stdio.h>

int labaone(void) {
  float v1, v2, t, V;

  v1 = 20;
  t = 100;
  V = 1000; 

  v2 = v1 - (V / t);
  
  printf("answer = %f\n", v2);

  return 0;
}

int onedop() {
    f(); 
    return 0;
}
void f() {

    int v1, v2, t, V;
    scanf("%f", &v1);
    scanf("%f", &V);
    scanf("%f", &t);

    
    v2 = v1-(V/t); 

    printf("answer = %f\n", v2);
}

int labatwo(void) { 
    int n,i; 
    double s, a, del; 
    s = 0; 
    i = 1; 
    scanf("%d",&n); 
    del = ((i+2)*(i+2)); 
 
    while (i < n){  
    
        a = (1 + i) / (del); 
        s += a; 
        i += 1; 
    } 
    printf("s = %f\n", s); 
 
    return 0; 
}

int twodop(void) 
{
    int n;
    double s, a, d;
    s = 0;
    scanf("%d", &n);
    d = 2;
 
    for (int i = 0; i < n; i++) {
        a = (1 + i) / (d * d);
        s += a;
        d += 1;
    }
    
    printf("s = %f\n", s);
 
    return 0; 
}

int labathree(void) {
    int words = 0; 
    int letters = 0;
    int flag = 0; 
    char ch; 

    printf("Введите текст, завершите ввод нажатием клавиши Enter:\n");

  
    while ((ch = getchar()) != '\n') {
        
        if (ch == ' ' || ch == '\t') {
            
            if (flag) {
                words++;
                flag = 0; 
            }
        } else {
            letters++; 
            flag = 1; 
        }
    }

    if (flag) {
        words++; 
    }

    if (words > 0) {
        float len = (float) letters / words; 
        printf("Средняя длина слова в тексте: %.2f\n", len); 
    } else {
        printf("Нет слов для подсчета.\n"); 
    }

    
}

int isVowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return 1;
        default:
            return 0;
    }
}

int threedop(void) {
    int words = 0;
    int letters = 0;
    int wordContainsVowel = 0;
    char ch;

    printf("Введите текст, завершите ввод нажатием клавиши Enter:\n");

    while ((ch = getchar()) != '\n') {
        if (ch == ' ' || ch == '\t') {
            if (!wordContainsVowel && letters > 0) {
                words++;
            }
            letters = 0;
            wordContainsVowel = 0;
        } else {
            if (!isVowel(ch)) {
                letters++;
            } else {
                wordContainsVowel = 1;
            }
        }
    }

    if (!wordContainsVowel && letters > 0) {
        words++;
    }

    if (words > 0) {
        float avgLength = (float) letters / words;
        printf("Средняя длина слова в тексте (без гласных): %.2f\n", avgLength);
    } else {
        printf("Нет слов для подсчета.\n");
    }

    return 0;
}

void removeOddLengthWords(char str[]) {
    int i = 0, j = 0, start = 0, wordSize = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            start = i;
            while (str[i] && str[i] != ' ') {
                i++;
                wordSize++;
            }
            if (wordSize % 2 == 0) {
                for (int k = start; k < i; k++) {
                    str[j++] = str[k];
                }
                if (str[i] && str[i] != ' ') {
                    str[j++] = ' '; // Добавляем пробел между словами
                }
            }
            wordSize = 0;
        } else {
            str[j++] = ' ';
            i++;
        }
    }
    str[j ? j - 1 : j] = '\0'; // Оптимизация: обрезаем лишний пробел перед завершающим нулевым символом
}

int labafour(void) {
    char str[100];
    printf("Введите строку: ");
    fgets(str, 100, stdin);

    removeOddLengthWords(str);

    printf("Строка после удаления слов c нечетным количеством букв: %s\n", str);

    return 0;
}

void analyze_string(char *str) {
  struct Stats {
    int spec_chars;
    int letters;
    int digits;
  } stats = {0};

  while (*str) {
    if (*str == ' ' || (*str < '0' || *str > '9') && (*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z')) {
      stats.spec_chars++;
    } else if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
      stats.letters++;
    } else if (*str >= '0' && *str <= '9') {
      stats.digits++;
    }
    str++;
  }

  int max_count = stats.spec_chars;
  char *max_type = "символов";
  if (stats.letters > max_count) {
    max_count = stats.letters;
    max_type = "букв";
  }
  if (stats.digits > max_count) {
    max_count = stats.digits;
    max_type = "цифр";
  }

  printf("Больше всего %s: %d\n", max_type, max_count);
}

int fourdop(void) {
  char str[100];

  printf("Введите строку: ");
  fgets(str, 100, stdin);

  analyze_string(str);

  return 0;
}

int labafive(void) {
    int arr[10];
    int i, sumPositive = 0, sumNegative = 0;


    printf("Ввод:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        if (arr[i] > 0) {
            sumPositive += arr[i];
        } else if (arr[i] < 0) {
            sumNegative += (-1 * arr[i]); 
        }
    }

    if (sumNegative < sumPositive) {
        for (i = 0; i < 10; i++) {
            if (arr[i] < 0) {
                arr[i] = 0;
            }
        }
    }

    printf("после:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int fivedop(void) {
    int arr[10];
    int i, is_regression = 1; // мб регр
    printf("10 чисел:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // проверка
    for (i = 1; i < 10; i++) {
        if (arr[i] >= arr[i - 1]) {
            is_regression = 0; // нет регр
            break;
        }
    }

    // если нет - обнуляем
    if (!is_regression) {
        for (i = 0; i < 10; i++) {
            arr[i] = 0;
        }
        printf("регрессия отсутсвует\n");
    } else {
        printf("регрессия есть\n");
    }

    printf("массив: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int labasix(void) {
  int N, K;

  printf("строки N: ");
  scanf("%d", &N);

  printf("столбцы K: ");
  scanf("%d", &K);

  int arr[N][K];

  printf("элементы:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  int isProgression = 1; 
  int prevDiff = 0; 
  int currentDiff; 

  for (int i = 0; i < N; i++) {
    for (int j = 1; j < K; j++) {
      if (i > 0) { 
        currentDiff = arr[i][j] - arr[i][j - 1];

        if (j == 1 && i > 0) { 
          if (currentDiff != prevDiff) {
            isProgression = 0;
            break; 
          }
        } 
        else if (currentDiff != prevDiff) {
          isProgression = 0;
          break; 
        }
      } else { 
        if (j > 1) { 
          currentDiff = arr[i][j] - arr[i][j - 1];

          if (currentDiff != prevDiff) {
            isProgression = 0;
            break; 
          }
        }
        if (j == 1) { 
          prevDiff = arr[i][j] - arr[i][j - 1]; 
        }
      }
    }

    if (!isProgression) {
      printf("прогрессии нет\n");
      break; 
    } 
  }

  if (isProgression) {
    printf("прогрессия есть\n");
  }

  return 0;
}


#include <stdio.h>

void shakerSort(int *array, int size) {
    int left = 0, right = size - 1;
    int temp, i;
    while (left < right) {
        for (i = left; i < right; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        right--;
        for (i = right; i > left; i--) {
            if (array[i] < array[i - 1]) {
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
        }
        left++;
    }
}

int sixdop(void) {
    int N, M;

    printf("строки: ");
    scanf("%d", &N);

    printf("столбцы: ");
    scanf("%d", &M);

    int array[N][M];
    int flatArray[N * M];

    printf("ввод:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            flatArray[k++] = array[i][j];
        }
    }

    shakerSort(flatArray, N * M);

    printf("результат:\n");
    for (int i = 0; i < N * M; i++) {
        printf("%d ", flatArray[i]);
    }
    printf("\n");
}
 

int symmetria(long N) {
  if (N < 0) {
    N = -N;
  }

  long reversN = 0;
  long origN = N;

  while (N > 0) {
    reversN = (reversN << 1) | (N & 1); 
    N >>= 1; 
  }

  return reversN == origN;
}
void toBinary(long n) {
  int num_bits = sizeof(long) * 8; 
  int leading_zero = 1; 

  for (int i = num_bits - 1; i >= 0; --i) {
    int bit = (n >> i) & 1;
    if (bit) {
      leading_zero = 0; 
    }
    if (!leading_zero) {
      printf("%d", bit);
    }
  }
  
  if (leading_zero) {
    printf("0");
  }
}
int labaseven(void) {
  long N;

  printf("ввод: ");
  scanf("%X", &N);

  printf("двоич: ");
  toBinary(N);
  printf("\n");

  if (symmetria(N)) {
    printf("%ld симметрично.\n", N);
  } else {
    printf("%ld не симметрично.\n", N);
  }

  return 0;
}
