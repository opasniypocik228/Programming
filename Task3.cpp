// Поменять порядок цифр заданного натурального числа на обратный. Пример: 7283916 > 6193827. Строковые функции не использовать.
#include <iostream>
using namespace std;


int main( void)
{ setlocale(LC_ALL, "Russian");
    for (;;) {
    int n, k;
    k = 0;
    cout << "Введите порядок цифр натурального числа: \n";
    cin >> n;
        
    do{
        k = k * 10+(n%10);
        n = n/10;
    } while (n!=0);
    
    cout << "Ответ:" << k << "\n";
        
    }
}


