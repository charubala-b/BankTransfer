#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class members{
public:
	vector<int>mem;
//	members(int acc_num){
//		mem.push_back(acc_num);
//	}
	void add(int acc_num){
		mem.push_back(acc_num);
	}
//	int check(int acc_num){
//		for(int i=0;i<mem.size();i++){
//			if(mem[i]==acc_num){
//				return 1;
//			}
//		}
//		return 0;
//	}
};
class Account{
private:
//	int acc_num;
	int balance=0;
	int debited_amount=0;
	int credit_limit=10000;
public:
	int getBalance(){
		return balance;
	}
	void setBalance(int amount){
		this->balance+=amount;
		cout<<"Successfully Deposited\n";
		cout<<"Your current balance is "<<balance;
	}
	int setDebit(int amount){
		if(debited_amount<amount){
			cout<<"You have only debited"<<debited_amount;
			return 0;
		}
		else{
			debited_amount-=amount;
			cout<<"Successfully deposited";
		}
		return 1;
	}
	int setAmount(int amount){
		if(balance>=amount){
			balance-=amount;
			cout<<"successfully debitted and have a balance of "<<balance<<"\n";
			return 1;
		}
		else{
			cout<<"You don't have enough money to debit\n"<<"The balance amount is"<<balance<<"\n";
			return 0;
		}
	}
	int setWithdraw(int amount){
		if((amount+debited_amount)>credit_limit){
			cout<<"You have exceeded Your limit\n";
			cout<<"You have only limit upto "<<credit_limit\n;
			return 0;
		}
		else{
			debited_amount+=amount;
			cout<<"Successfully Withdrawn\n";
			return 1;
		}
	}
};
class Savings:public Account{
public:
	void deposit(int amount){
		setBalance(amount);
	}
	int withdraw(int amount){
		int val=setAmount(amount);
		return val;
	}
};
class Credit:public Account{
public:
	int deposit(int amount){
		int val=setDebit(amount);
		return val;
	}
	int withdraw(int amount){
		int val=setWithdraw(amount);
		return val;
	}
};
class Details{
public:

	void showDetails(string str){
		cout<<"1. View Balance.\n"<<"2. Deposit\n"<<"3. Withdraw\n"<<"0. Main Menu\n";
		int choice;
		cin>>choice;
		Savings s;
		Credit c;
		if(choice==1){
			Account b;
			int balance=b.getBalance();
			cout<<"The Current Balance "<<balance<<"\n";
		}
		else if(choice==2){
			int amount;
			cout<<"Enter the amount that need to be deposited\n";
			cin>>amount;
			if(str=="savings"){
				s.deposit(amount);
			}
			else{
				while(c.deposit(amount)==0){
					cout<<"Enter the amount again: ";
					cin>>amount;
				}
			}
		}
		else if(choice==3){
			int amount;
			cout<<"Enter the amount that need to be withdrawn:";
			cin>>amount;
//			Account a;
//			a=&
			if(str=="savings"){
//				Savings s;
				while(s.withdraw(amount)==0){
					cout<<"Enter the amount again: ";
					cin>>amount;
				}
			}
			else{
//				Credit c;
				while(c.withdraw(amount)==0){
					cout<<"Enter the amount again: ";
					cin>>amount;
				}
			}
		}
		showDetails(str);
	}
};
int main(){
	cout<<"welcome to sece bank\n";
	int acc_num;
	cout<<"Enter Account num:\n";
	cin>>acc_num;
	members m;
	m.add(acc_num);
//	int exist=m.check(acc_num);
//	if(exist==1){
//		cout<<"You have already created an account";
//		cout<<"Account type (S)avings/(C)redit";
//		char acc_type;
//		cin>>acc_type;
//		if(acc_type=='S'){
//			cout<<"Saving Account Created";
//			Details d;
//			d.showDetails("savings");
//		}
//		else{
//			cout<<"Credit Card account Created";
//			Details d;
//			d.showDetails("credit");
//		}
//	}
//	else{
		cout<<"New Account Creation:\n";
		cout<<"Account type (S)avings/(C)redit\n";
		char acc_type;
		cin>>acc_type;
		if(acc_type=='S'){
			cout<<"Saving Account Created\n";
			Details d;
			d.showDetails("savings");
		}
		else{
			cout<<"Credit Card account Created\n";
			Details d;
			d.showDetails("credit");
		}
//}
	return 0;
}
