#include <iostream>
#include <ctime>
#include<Windows.h>


using namespace std;

//задание 1
const int H = 10;
const int N = 10;
void Reinit(int arr1[], int arr2[]);
void Sort();
//Задание 2
void Buble();
//задание 3
const int Size = 10;
//массив оладий
int pancakes[Size]{ 12,6,10,23,41,1,19,26,45,37 };
int temp, counter = 0; // кол-во переворотов
// максимальный оладь и его позиция в массиве
int max_pan, max_index = 0;

void findMaxPancake(int i); // поиск максимального размера и его позиции
void sortPancake();  // для переворачивания стопки
void maxPancakeDown(int i);
void Panc();

int main()
{
    setlocale(LC_ALL,"");
  //Sort();
  //Buble();
  //Panc();
  //2задание нифига не получается как и 4(((
    
    
}
void Reinit(int arr1[], int arr2[]) {
   
    for (int i = 0; i < H; i++) {
        arr1[i] = rand() % 100001;
    }

    for (int i = 0; i < N; i++) {
        arr2[i] = rand() % 9000000 + 999999;
    }
}
void Sort() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(0));
    int arr1[H];
    int arr2[N];
    int num = 0;
    Reinit(arr1, arr2);
    for (;;) {
        cout << "№\t Номер телефона \t Номер Домашний" << endl;
        cout << "1.\t   " << arr2[0] << "\t\t    " << arr1[0] << endl;
        cout << "2.\t   " << arr2[1] << "\t\t    " << arr1[1] << endl;
        cout << "3.\t   " << arr2[2] << "\t\t    " << arr1[2] << endl;
        cout << "4.\t   " << arr2[3] << "\t\t    " << arr1[3] << endl;
        cout << "5.\t   " << arr2[4] << "\t\t    " << arr1[4] << endl;
        cout << "6.\t   " << arr2[5] << "\t\t    " << arr1[5] << endl;
        cout << "7.\t   " << arr2[6] << "\t\t    " << arr1[6] << endl;
        cout << "8.\t   " << arr2[7] << "\t\t    " << arr1[7] << endl;
        cout << "9.\t   " << arr2[8] << "\t\t    " << arr1[8] << endl;
        cout << "10.\t   " << arr2[9] << "\t\t    " << arr1[9] << endl;
        cout << "\n1.\t Отсортировать по номерам домашним" << endl;
        cout << "2.\t Отсортировать по номерам телефона" << endl;
        cout << "3.\t Выход" << endl << endl;
        cin >> num;
        switch (num){
        case 1:
            system("cls");
            for (int i = 1; i < H; ++i){
                int k = i;
                while (k > 0 && arr1[k - 1] > arr1[k]){
                    int tmp = arr1[k - 1];
                    arr1[k - 1] = arr1[k];
                    arr1[k] = tmp;
                    tmp = arr2[k - 1];
                    arr2[k - 1] = arr2[k];
                    arr2[k] = tmp;
                    k -= 1;
                }
            }
            break;
        case 2:
            system("cls");
            for (int i = 1; i < N; ++i){
                int k = i;
                while (k > 0 && arr2[k - 1] > arr2[k]){
                    int tmp = arr2[k - 1];
                    arr2[k - 1] = arr2[k];
                    arr2[k] = tmp;
                    tmp = arr1[k - 1];
                    arr1[k - 1] = arr1[k];
                    arr1[k] = tmp;
                    k -= 1;
                }
            }
            break;
        case 3:
            break;
        }
    }
}

void findMaxPancake(int i) {
    max_pan = pancakes[i];
    for (int j = i; j < Size; j++) {
        if (max_pan < pancakes[j]) {
            max_pan = pancakes[j];
            max_index = j;
        }
    }
}
void sortPancake() {
    for (int j = max_index, h = Size - 1; j < h; j++, h--) {
        temp = pancakes[j];
        pancakes[j] = pancakes[h];
        pancakes[h] = temp;
    }
    counter++;
}
void maxPancakeDown(int i) {
    for (int j = i, h = Size - 1; j < h; j++, h--) {
        temp = pancakes[j];
        pancakes[j] = pancakes[h];
        pancakes[h] = temp;
    }
    counter++;
}
void Panc() {
    for (int i = 0; i < Size; i++) {
        findMaxPancake(i);
        if (pancakes[i] == max_pan && i >= max_index) continue;
        else {
            sortPancake();
            for (int i = 0; i < Size; i++) {
                cout << pancakes[i] << " ";
            }
            cout << endl << endl;
            maxPancakeDown(i);
        }
    }
    for (int i = 0; i < Size; i++) {
        cout << pancakes[i] << " ";
    }
    cout << endl << endl;
    cout << endl << counter;
}

void Buble() {
    const int SIZE1 = 10;
    int arr[SIZE1], temp, counter;
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < SIZE1; i++) {
        cin >> arr[i];
    }
    cout << endl;
    for (int i = 1; i < SIZE1; i++) {
        counter = 0;
        for (int j = 0; j < SIZE1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                counter++;
            }
        }
        cout << i<<" "<<endl;
        if (counter == 0) {
            cout << "Cортировкa завершилась на ";
            cout << i-1 << " шаге\n";
            break;
        }
        
    }
    for (int i = 0; i < SIZE1; i++) {
        cout << arr[i] << " ";
    }
}