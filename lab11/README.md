# Языки программирования
## Лабораторная работа 11

### Задание 1 **(2)**

*Что надо дописать в приведенный пример программы, чтобы она транслировалась без ошибок?
Существующий код нельзя изменять или переставлять.*

```
int foo(int x) {
    return bar(x);
}
int bar(int x) {
    return x+1;
}
int main() {
    foo(0);
    return 0;
}
```
декларация функции

<img width="1092" height="295" alt="image" src="https://github.com/user-attachments/assets/c4753cf5-9448-4438-bffc-51184ee11f34" />

<img width="844" height="269" alt="image" src="https://github.com/user-attachments/assets/e1f9ecff-45d6-48cf-a74b-82ec02d024e0" />


### Задание 2 **(1)**

*Функция* **dswap** *должна была обменивать значения своих параметров.* 
*(На выводе должно было получиться* ```3.4 1.5```.)
*В чем ошибка при написании этой функции? Как ее исправить? 
Что передавалось в параметры у исходной функции и у исправленной?* 
```
#include <iostream>
void dswap(double x, double y) {
   double t = x;
   x = y;
   y = t;
}
int main(void) {
   double x = 1.5, y = 3.4;
   dswap(x, y);
   std::cout << x << " " << y << std::endl;
   return 0;
}
```

### Задание 3 **(3)**

*Известно, что функция* **dosome** *не изменяет значений вектора* **V**.
*Какие из способов объявления функции является правильным с точки зрения 
корректности работы программы? В чем разница между этими способами?*



```
void dosome_1(const std::vector<int> &V);
void dosome_2(std::vector<int> &V);
void dosome_3(const std::vector<int> V);
void dosome_4(std::vector<int> V);
```
*Напишите примеры для этих функций. В качестве примера можно взять нахождение суммы всех элементов
вектора.*

*Выведите адрес нулевого элемента вектора в функции. Объясните результат.*

*Проверьте в какие из этих функций можно передать константные вектора. Объясните результат.*
```
dosome({1, 2, 3});
```

<img width="1285" height="774" alt="image" src="https://github.com/user-attachments/assets/f36b61dd-75f8-4d5e-8263-bd506aff6b1e" />

```
#include <iostream>
#include <vector>
void dosome_1(const std::vector<int> &V){
    int s =0;
    for(auto x: V){
        s+=x;
    }
    std::cout<<"sum = "<<s<<std::endl;
}
void dosome_2(std::vector<int> &V){
    int s =0;
    for(auto x: V){
        s+=x;
    }
    std::cout<<"sum = "<<s<<std::endl;
}
void dosome_3(const std::vector<int> V){
    int s =0;
    for(auto x: V){
        s+=x;
    }
    std::cout<<"sum = "<<s<<std::endl;
}
void dosome_4(std::vector<int> V){
    int s =0;
    for(auto x: V){
        s+=x;
    }
    std::cout<<"sum = "<< s <<std::endl;
}
int main(){
    std::vector<int> V = {1, 2, 3, 4, 5};
    dosome_1(V);
    dosome_2(V);
    dosome_3(V);
    dosome_4(V);
    return 0;
}
```
все четыре способа работающие 

<img width="878" height="769" alt="image" src="https://github.com/user-attachments/assets/1b172bd7-96dd-44e2-91da-b550ec0c5aa7" />

ошибка в 1 и 3 векторе тк оба вектора неизменяемые это нужно чтобы по случайности не поменять (не получить доп ошибок)

<img width="571" height="753" alt="image" src="https://github.com/user-attachments/assets/81311042-0cd9-4820-be12-61350ca19141" />

передача по ссылке с const чтобы каждый раз не копировать значения и не занимать место в памяти и по времени

<img width="1820" height="758" alt="image" src="https://github.com/user-attachments/assets/552584dd-f9be-4b8d-87ee-6e8c63a4b174" />

### Задание 4 **(2)**

*Напишите программу в которой будет создаваться восемь массивов из 128 целых чисел четырьмя способами,
каждым способом по два массива.
Первые два массива должны быть глобальными, вторые — локальными статическими, третьи — локальными на стеке,
четвертые — локальными в куче. Выведите адреса первого и последнего элемента в каждом массиве.
Сравните, насколько далеко они располагаются друг от друга. Какие выводы можно из этого сделать.*

*В отчет запишите программу и скриншот ее работы.*

<img width="1416" height="486" alt="image" src="https://github.com/user-attachments/assets/b1e2deba-3346-44bf-ae9e-553e7126ff41" />
глобальную видено везде а статическую только из функции
локальные массивы размещаются на стеке
<img width="1375" height="503" alt="image" src="https://github.com/user-attachments/assets/2bbe4425-011d-4b87-b8f1-19bd7ceebb21" />

увеличиваем
статический массив создается один раз и инициализируется один раз
<img width="1503" height="619" alt="image" src="https://github.com/user-attachments/assets/1ef37b76-22cf-4235-966c-606cb00bdfd2" />

```
#include <iostream>
#include <vector>
int G1[128] = {0}, G2[128] = {0};
void foo(){
    static int s1[128] = {0}, s2[128] = {0};
    int L1[128] = {0}, L2[128] = {0};
    int *H1 = new int[128]{0};
    int *H2 = new int[128]{0};
    std::cout <<"Global "<< &G1[0]<<' '<<G1+128<<' '<<&G2[0]<<' '<<G2+128<<std::endl;
    std::cout <<"Static "<< &s1[0]<<' '<<s1+128<<' '<<&s2[0]<<' '<<s2+128<<std::endl;
    std::cout <<"Local "<< &L1[0]<<' '<<L1+128<<' '<<&L2[0]<<' '<<L2+128<<std::endl;
    std::cout <<"Heap "<< &H1[0]<<' '<<H1+128<<' '<<&H2[0]<<' '<<H2+128<<std::endl;
    std::cout <<std::endl;
    H1[0]++;
    L1[0]++;
    s1[0]++;
    std::cout<<H1[0]<<" "<<L1[0]++<<" "<<s1[0]<<std::endl;
    delete[] H1;
    delete[] H2;
}
void bar(){
    foo();
}
int main(){
    foo();
    bar();
    foo();
    return 0;
}
```
### Задание 5 **(2)**

*Приведенная ниже программа вызывает ошибку. Почему?*

*Что будет, если перенести объявление массива выше функции* **foo**?

*Что будет, если объявить массив с использованием ключевого слова* **static**?

*Что будет, если создать массив такого же размера с использованием* **new**?
```
#include <iostream>
int foo() {
    int x[100010001];
    return x[100010000];
}
int main() {
    std::cout << foo();
    return 0;
}
```


### Задание 6 **(3)**

*Запишите следующую программу. Выполните ее трансляцию с нулевым оровнем оптимизации.
Нарисуйте схематично расположение переменных в памяти в момент вызова при \verb*|a=0|. 
Отметьте кадры стека.*

```
#include <iostream>
long long foo(long long a, long long b) {
   if (a == 0) 
      return 0;
   else {
      long long x, y;
      std::cout << "Enter a=" << a << ", b=" << b << std::endl;
      std::cout << "Ptrs " << &a << ' ' << &b <<' '<< &x<<' '<<&y << std::endl;
      x = a * b;
      y = foo(a - 1, b + 1);
      return x + y;
   }
}
int main() {
   foo(5, 5);
   return 0;
}
```

### Задание 7 **(3)**

*Рассмотрите следующую программу. Выполните ее трансляцию, используя  компилятор g++ без
оптимизации (уровень оптимизации 0). Объясните ее работу.*
```
#include <iostream>
double &choose(double &a, bool flg) {
    double pi = 3.14;
    double &r = flg ? pi : a;
    return r;
}

int main(void)
{
    double a = 2.7;
    double &pi = choose(a, true);
    std::cout << pi << std::endl;
    double &e = choose(a, false);
    std::cout << e << std::endl;
    std::cout << pi << std::endl;
    return 0;
}
```

### Задание 8 **(3)**

*Объясните работу приведенной ниже программы.
Какие ошибки в ней имеются? (Виды ошибок смотрите в лекции.)*
```
#include <iostream>
int main() {
    int *p = new int [10];
    int *q = new int [10];
    for (int i = 0; i <= 10; i++)
        p[i] = i;
    q = p;
    delete[] p;
    for (int i = 0; i <= 10; i++)
        std::cout << q[i] <<" ";
    delete[] q;
    return 0;
}
```


## Дополнительные задания

### Задание 1 **(2)**

*В чем ошибка данного примера? Будет ли он работать при замене типа* **double** на **int**
*в функции bar?*
```
#include <iostream>
int foo(int x) {return x+1;}
double bar(double x) {return x-1;}
int main () {
    decltype(foo) *pf;
    pf = bar;
    std::cout << pf(0);
    return 0;
}

```

### Задание 2 **(10)**

*С использованием стандартных функций сортировки напишите на Java, C++ и Python программу
для сортировки вещественных чисел по возрастанию целой части числа и убыванию дробной.
Например, правильный порядок чисел после сортировки будет выглядеть так:*
```1.9; 1.32; 1.0; 5.8; 5.1; 12.6; 13.2; 13.1.``` 

*При реализации требуется использовать лямбда-функции.*

### Задание 3 **(4)**
*Напишите фрагмент программы вместо многоточия, 
в котором в начало массива* **data** *будет вставляться новый элемент* **t**. *Существующие
элементы при этом должны сместиться назад. Другие исправления вносить нельзя.
Для этого потребуется выделить новый участок памяти и перенести в него все элементы.*
```
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    *data = new int [n];
    for (int i=0; i<n; i++)
        std::cin >> data[i];
     int t;
     std::cin >> t;
     ...
     for (int i=0;i<n+1;i++)
         std::cout << data[i] <<' '; 
     return 0;
}
```

### Задание 4 **(4)**
*Напишите программу, которая создаст в памяти треугольник Паскаля размера* **n**.
*Размер должен вводиться во время работы программы. 
В программе не должна выделяться память для несуществующих элементов. В программе требуется использовать 
массив указателей.* 

