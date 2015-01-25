#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	for (;;) // цикличность
	{
		int x, y ;
        cout << "Введите число: " ;
        cin >> x ;
        if (x==10) {
            cout << "Ответ: 01"<< endl;} else {
                if (x==20) {
                    cout << "Ответ: 02"<< endl;} else {
                        if (x==30) {
                            cout << "Ответ: 03"<< endl;} else {
                                if (x==40) {
                                    cout << "Ответ: 04"<< endl;} else {
                                        if (x==50) {
                                            cout << "Ответ: 05"<< endl;} else {
                                                if (x==60) {
                                                    cout << "Ответ: 06"<< endl;} else {
                                                        if (x==70) {
                                                            cout << "Ответ: 07"<< endl;} else {
                                                                if (x==80) {
                                                                    cout << "Ответ: 08"<< endl;} else {
                                                                        if (x==90) {
                                                                            cout << "Ответ: 09"<< endl;} else {
                                                                                
                                                                                if (x>9 && x<100) {
                                                                                    y = (x % 10)*10 + (x / 10); // преорбразуем число
                                                                                    cout << "Ответ: " << y << endl;
                                                                                }
                                                                                else { cout << "Это не двухзначное число!" << endl;
                                                                                }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
        
	}
 	return 0;
}