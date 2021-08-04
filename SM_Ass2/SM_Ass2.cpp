#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int P, Q, stock, today, dueDate, unitsDue, startDate, demand, reorderCost;
    float total_cost;

    //For different values of P and Q
    for(int i=0;i<5;i++)
    {
        cin>>P>>Q; //125 150
        //initialize random seed for constant random values
        srand(0);

        //All the initializations
        startDate = 1;
        dueDate = 0;
        today = startDate;
        unitsDue = 0;
        reorderCost = 2; //not given
        stock = 115;
        total_cost=0;

        while(today<=180)
        {
            //If due date, refill stock
            if(today==dueDate)
            {
                stock+= Q;
                unitsDue=0;
            }
            //Today's demand of orders
            demand = rand() % 100;

            //If demand less than stock, add carrying cost
            if(demand<=stock)
            {
                stock-= demand;
                total_cost+= stock*0.75;
            }
            //If demand more than stock, add lost sale cost
            else
            {
                total_cost+= (demand - stock)*18;
                stock = 0;
            }
            //If stock less than minimum level, restock order
            if(stock + unitsDue <= P)
            {
                unitsDue = Q;
                total_cost+= reorderCost*unitsDue;
                dueDate = today+3;
            }
            today++;
        }

        cout<<"Total Cost for P= "<<P<<" and Q= "<<Q<<" is "<<total_cost<<"\n";
    }
    return 0;
}
