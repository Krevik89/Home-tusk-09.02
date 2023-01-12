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

void Create(int arr[]) {
    const int a = 1000;
   
    for (int i = 0; i < a; i++){
        arr[i] = rand() % 100;
    }
   /* for (int i = 0; i < a; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;*/
}
int buble(int arr[]) {
    int temp;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        count = 0;
        for (int j = 0; j < 1000 - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0) {
            sum += i;
           // cout << "Сортировка закончилась на ";
           // cout << i << " шаге\n";
           
            break;
        }
    }
   /* for (int i = 0; i < 1000; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    return sum;
}
int input(int arr[]) {
    int i, j, k;
    int temp;
    int count = 0;
    int sum1 = 0;
    for (i = 0; i < 1000; i++) {
        k = i;
        temp = arr[i];
        count = 0;
        for (j = 1 + i; j < 1000; j++) {
            if (arr[j] < temp) {
                k = j;
                temp = arr[j];
                count++;
            }
        }
        if (k != i) {
            arr[k] = arr[i];
            arr[i] = temp;
        }
        if (count == 0) {
            sum1 += i;
            //cout << "Сортировка закончилась на ";
            //cout << i << " шаге\n";
            break;
        }
    }
   /* for (int i = 0; i < 1000; i++) {
        cout << arr[i] << " ";
    }*/
    return sum1;
}



int main()
{
    setlocale(LC_ALL,"");
    srand(time(NULL));
  //Sort();
  //Buble();
  //Panc();
    
    int arr[1000];
    int count1 = 0;
    int count2 = 0;
   
    for (int i = 0; i < 10; i++){
       // cout << endl;
        Create(arr);
        count1+=buble(arr);
        Create(arr);
        count2+=input(arr);
    }
    //cout << endl;
    cout <<"Кол-во для пузырька " << count1 <<" Ср.кол= "<< count1/10<< endl;
    cout <<"Кол-во для сорт выбора " << count2<<" Ср.кол= "<<count2/10;
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
    const int size = 10;
    int arr[size];
    int temp;
    int count = 0;
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "Сортировка закончилась на ";
            cout << i << " шаге\n";
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}