#include <bits/stdc++.h>

using namespace std;

int no_of_coins{0};
vector<int> square_numbers(int no_of_coins){
    vector<int>x{};
    for(int i =1; i<= floor(sqrt(no_of_coins));i++){
        x.push_back((int)pow(i,2));
    }
    return x;
}
bool validate(string number,int no_of_coins){
    for(char i : number){
        if(!isdigit(i)){
            return false;
        }
    }
    vector<int>numbers = square_numbers(no_of_coins);
    for(int i=0;i<numbers.size();i++){
        if(stoi(number)==numbers[i] && stoi(number)<=no_of_coins){
            return true;
        }
    }
    return false;
}

int take_input(string msg,int no_of_coins){
    string number{};
    vector<int>validNums{};
    validNums = square_numbers(no_of_coins);
    cout<<msg;
    cin>>number;
    cout<<endl;
    while (!validate(number,no_of_coins)){
        cout<<"please enter a digit from [";
        for(int n :validNums)
            cout<<n<<" ";
        cout<<"]"<<endl;
        cout<<msg;
        cin>>number;
        cout<<endl;
    }
    return stoi(number);

}
void subtract_a_square(){
    vector<int>validNums{};
    int player1{0},player2{0};
    while (no_of_coins>0){
        validNums = square_numbers(no_of_coins);
        cout<<"[ ";
        for(int n :validNums)
            cout<<n<<" ";
        cout<<"]"<<endl;
        player1= take_input("player1: " ,no_of_coins);
        cout<<endl;
        no_of_coins -= player1;
        cout<<"Number Of Coins: " << no_of_coins<<endl;
        if(no_of_coins==0){
            cout<<"Player 1 wins"<<endl;
            break;
        }
        validNums = square_numbers(no_of_coins);
        cout<<"[ ";
        for(int n :validNums)
            cout<<n<<" ";
        cout<<"]"<<endl;
        player2= take_input("player2: ",no_of_coins);
        cout<<endl;
        no_of_coins -= player2;
        cout<<"Number Of Coins: " << no_of_coins<<endl;
        if(no_of_coins==0){
            cout<<"Player 2 wins"<<endl;
        }

    }
}
int main(){

    cout<<"enter number of coins: ";
    cin>>no_of_coins;
    cout<<endl;
    subtract_a_square();

    return 0;
}
