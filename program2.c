#include<stdio.h>
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10], q[10];  
    float avg_wt, avg_tat;  
void roundrobin()
{
printf("Enter the Time Quantum for the process: \t");  
scanf("%d", &quant);  
}
void rr()  
{  
   

printf(" Total number of process in the system: ");  
scanf("%d", &NOP);  
y = NOP;
 

for(i=0; i<NOP; i++)  
{  
printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
printf(" Arrival time is: \t");
scanf("%d", &at[i]);  
printf(" \nBurst time is: \t");  
scanf("%d", &bt[i]);  
temp[i] = bt[i];
}  



printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0)
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }    
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--;
        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;    
    }  
    if(i==NOP-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  

avg_wt = wt * 1.0/NOP;  
avg_tat = tat * 1.0/NOP;  
printf("\n Average Turn Around Time: \t%f", avg_wt);  
printf("\n Average Waiting Time: \t%f", avg_tat);  
 
}  
void non()
{
    int pn = 0;                
    int CPU = 0;            
    int allTime = 0;      
    printf("Enrer Processes Count: ");
    scanf("%d",&pn);
    int AT[pn];
    int ATt[pn];
    int NoP = pn;
    int PT[pn];            
    int PP[pn];             
    int PPt[pn];
    int waittingTime[pn];
    int turnaroundTime[pn];
    int i=0;
    for(i=0 ;i<pn ;i++){
        printf("\nProcessing time for P%d: ",i+1);
        scanf("%d",&PT[i]);
        printf("Piriorty for P%d: ",i+1);
        scanf("%d",&PP[i]);
        PPt[i] = PP[i];
        printf("Arrival Time for P%d: ",i+1);
        scanf("%d",&AT[i]);
        ATt[i] = AT[i];
    }
    int LAT = 0;       
    for(i = 0; i < pn; i++)
        if(AT[i] > LAT)
            LAT = AT[i];

    int MAX_P = 0;        
    for(i = 0; i < pn; i++)
        if(PPt[i] > MAX_P)
            MAX_P = PPt[i];
    int ATi = 0;        
    int P1 = PPt[0];   
    int P2 = PPt[0];     
    int j = -1;
    while(NoP > 0 && CPU <= 1000){
        for(i = 0; i < pn; i++){
            if((ATt[i] <= CPU) && (ATt[i] != (LAT+10))){
                if(PPt[i] != (MAX_P+1)){
                    P2 = PPt[i];
                    j= 1;

                    if(P2 < P1){
                        j= 1;
                        ATi = i;
                        P1 = PPt[i];
                        P2 = PPt[i];
                    }
                }
            }
        }

        if(j == -1){
            CPU = CPU+1;
            continue;
        }else{


            waittingTime[ATi] = CPU - ATt[ATi];
            CPU = CPU + PT[ATi];
            turnaroundTime[ATi] = CPU - ATt[ATi];
            ATt[ATi] = LAT +10;
            j = -1;
            PPt[ATi] = MAX_P + 1;
            ATi = 0;       
            P1 = MAX_P+1;     
            P2 = MAX_P+1;   
            NoP = NoP - 1;

        }
    }
    printf("\nPN\tPT\tPP\tAT\tWT\tTT\n\n");
    for(i = 0; i < pn; i++){
       printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,PT[i],PP[i],AT[i],waittingTime[i],turnaroundTime[i]);
    }

    float AvgWT = 0;
    float AVGTaT = 0;
    for(i = 0; i < pn; i++){
        AvgWT = (float)waittingTime[i] + AvgWT;
        AVGTaT = (float)turnaroundTime[i] + AVGTaT;
    }
    printf("AvgWaittingTime = %f\nAvgTurnaroundTime = %f\n",AvgWT/pn,AVGTaT/pn);
}
void main()
{
    int ch;
    printf("Enter choice 1-priority(non premetive) 2-Priority(Premetive) 3-Round Robin: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        non();
        break;
        case 3:
        rr();
        break;
        default:
        Printf("Wrong choice");
    }
}
