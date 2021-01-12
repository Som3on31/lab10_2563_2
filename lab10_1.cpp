#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>


using namespace std;

int main(){
    int num;
    string grade[]={"A","B+","B","C+","C","D+","D","F","W"};

    srand(time(0)); 
    cout << "Press Enter 3 times to reveal your future.";
    cin.get();
    cin.get();
    cin.get();
    num = rand()%9;

    

    cout << "You will get " << grade[num] << " in this 261102.";



    return 0;
}