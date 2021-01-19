#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	string name;
	int NY,NM,i;
	float IY,IM,PR,P,Q,MP, interestPaid,principalPaid,newbalance,oldbalance,totalAmountPaid=0,amountPaid;
	//NY : Scheduled number of years to amortize the loan
	//NM : Scheuled  number of months for the loan
	//IY : Interest rate per year (as a percentage)
	//IM : Interest rate/ month (decimal)
	//PR : Principal( the amount of the loan)
	//P  : The value of (1+IM)^(NM)
	//Q  : The value of P/(P-1)
	//MP : Monthly payment
	cout<< "Please enter your name: " ;
	getline(cin,name);
	
	cout<<setprecision(2)<<fixed;
	cout<<"Amount of the loan (principal) : RM ";
	cin>>PR;
	
	if(PR <= 0.0)
	{
		cout << "Oops error here!" << endl << "I'm sorry but your loan value cannot be 0 or lesser. " << endl;
		return 0;
	}
	
	cout<<setprecision(1)<<fixed;
	cout<<"Interest rate/year (percent) : ";
	cin>>IY;
	
	if (IY <= 0.0)
	{
		cout << "Oops error here!" << endl << "I'm sorry but your interest rate per year cannot be 0 or lesser ";
		return 0;
	}
	
	IM = (IY/100)/12;
	cout<<setprecision(6)<<fixed;
	cout<<"Interest rate/month (decimal) : "<<IM<<endl;
	
	cout<<"Number of years : ";
	cin>>NY;
	
	if ( NY <= 0)
	{
		cout << "Oops error here! " << "I'm sorry but year cannot be 0 or lesser";
		return 0;
	}
	
	NM=NY*12;
	cout<<"Number of months : "<<NM<<endl;
	
	P= pow((1+IM), NM);
	Q=(P/(P-1));
	MP=(PR*IM*Q);
	cout<<setprecision(2)<<fixed;
	cout<<"Monthly payment: RM"<<MP<<endl;
	
	cout << "\n\tOld " << "\t\tMonthly " << "\tInterest " << "\tPrincipal " << "\tNew" << endl;
	cout << "Month " <<"\tBalance " << "\tPayment " << "\tPaid " << "\t\tPaid" << "\t\tBalance" << endl;

	oldbalance=PR;
	for(i=1;i<NM;i++)
	{
	
		interestPaid=oldbalance* IM;
		principalPaid= MP-interestPaid;
		newbalance=oldbalance-principalPaid;
		cout<<setprecision(2)<<fixed;
		cout << i <<"\t"<<oldbalance<< "\t\t"<<MP << "\t\t"<<interestPaid << "\t\t"<<principalPaid << "\t\t"<<newbalance << endl;
		oldbalance=newbalance;
		amountPaid+=interestPaid;
	}
	
	interestPaid=oldbalance* IM;
	principalPaid=oldbalance;
	MP=interestPaid+principalPaid;
	newbalance=oldbalance-principalPaid;
	cout << NM <<"\t"<<oldbalance<< "\t\t"<<MP<< "\t\t"<<interestPaid << "\t\t"<<principalPaid << "\t\t"<<newbalance<< endl;
	amountPaid+=interestPaid;
	totalAmountPaid=amountPaid+PR;
	cout<<"Total amount paid: "<<totalAmountPaid << endl;
	cout << "Thank you " << name << " for choosing our service" << endl ;
	
	return 0;
}


