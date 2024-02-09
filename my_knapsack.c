#include <stdio.h>
#define weight 20
#define size 5


int MAX(int a, int b){
    return (a > b) ? a : b;
}

int knapSack(int weights[], int values[], int selected_bool[]){

    int WS[size + 1][weight + 1];

    for(int i = 0; i <= size; i++ ){
        for(int j = 0; j <= weight; j++){
            if((i == 0) || (j == 0)){
                WS[i][j] = 0;
            }
            else if(i == j){
                WS[i][j] = values[i-1];
            }
            else if(weights[i-1] <= j){
                WS[i][j] = MAX(values[i-1] + WS[i-1][j-weights[i-1]], WS[i-1][j]);
            }
            else{
                WS[i][j] = WS[i-1][j];
            }
        }

        int tempWeight = weight;
        for(int i = tempWeight; i > 0 && tempWeight > 0; i--){
            if(WS[i][tempWeight] != WS[i-1][tempWeight]){
                selected_bool[i-1] = 1;
            }
            else{
                tempWeight = tempWeight - weights[i-1];
            }
        }   
    }
    return WS[weight][size];
}

int main(){
 
    int selected_bool[size] = {0};
    char items[size] = {0};
    int weights[size] = {0};
    int values[size] = {0};

    for(int i = 0; i < size; i++){
        scanf("%c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    int profit = knapSack(weights, values, selected_bool);


    printf("Maximum profit: %d\n", profit);
    printf("Selected items: ");

    for(int i = 0; i < size; i++){
        if(selected_bool[i] == 1){
            printf("%c ", items[i]);
        }
    }
}

