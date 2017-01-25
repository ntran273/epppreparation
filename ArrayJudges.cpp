#include <iostream>
using namespace std;

void Input(int a[], int size){
    for(int i = 0; i < size; i++){
        cout << "Enter judges " << i + 1 << endl;
        cin >> a[i];
    }
}

void Output(int a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

int findMin(int a[], int size){
    int min = a[0];
    for(int i = 0; i < size; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}

int findMax(int a[], int size){
    int max = a[0];
    for(int i = 0; i < size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

float findAverageScore(int a[], int size){
    int sum = 0;
    int min = findMin(a,size);
    int max = findMax(a,size);
    for(int i = 0; i < size; i++){
        sum += a[i];
    }
    return (float)((sum - max - min) / (size - 2));
}

int main() {
	// your code goes here
    int a[100];
    int size;
    int contestantNum = 0;
    int highestContestant = 0;
    float topScore;

    while(true){
        cout << "Enter contestant Number: " << flush;
        cin >> contestantNum;
        if(contestantNum < 0){
            break;
        }

        do{
            cout << "Enter number of judges: " << flush;
            cin >> size;
            
            if(size < 3 || size > 10){
                cout << "Number of judges cannot be less than 3 and greater than 10" << endl;
            }
        }while(size < 3 || size > 10);
        Input(a,size);
        cout << findMin(a, size) << endl;
        Output(a,size);
        float avgScore = findAverageScore(a,size);
        cout << "Contestant " << contestantNum << "\t" << avgScore << endl;
        if(avgScore > topScore){
            topScore = avgScore;
            highestContestant = contestantNum;
        }
    }

    cout << "Contestant " << highestContestant << " had the highest score." << endl;    

	return 0;
}