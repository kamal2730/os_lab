#include <stdio.h>
#define N 4
#define Q 10
int at[4]={0,3,4,9};
int bt[4]={60,30,40,10};
int p[4]={3,2,1,4};

void fcfs(){
	int st[N], wt[N],tat[N];
	int time=0;
	printf("\n|");
	for(int i=0;i<N;i++){
		if(time<at[i]){
			time=at[i];
		}
		st[i]=time;
		wt[i]=st[i]-at[i];
		tat[i]=wt[i]+bt[i];
		time=time+bt[i];
		printf("P%i|",i+1);
	}
	int totalwt=0,totaltt=0;
	for(int i=0;i<N;i++){
		totalwt+=wt[i];
		totaltt+=tat[i];
	}
	printf("\nFCFS Average Waiting Time:%.2f Average TAT:%.2f\n",(float)totalwt/N,(float)totaltt/N);
}
void roundrobin(){
	int rt[N],ct[N],tat[N],wt[N];
	for(int i=0;i<N;i++) rt[i]=bt[i];
	int completed=0;
	int time=0;
	printf("\n|");
	while(completed<N){
		int executed=0;
		for(int i=0;i<N;i++){
			if(time>=at[i] && rt[i]>0){
				executed=1;
				if(rt[i]>Q){
					time+=Q;
					rt[i]-=Q;
				}else{
					time+=rt[i];
					rt[i]=0;
					ct[i]=time;
					tat[i]=ct[i]-at[i];
					wt[i]=tat[i]-bt[i];
					completed++;
				}
				printf("P%i|",i+1);
			}
		}
		if(!executed) time++;
	}
	int totalwt=0,totaltt=0;
	for(int i=0;i<N;i++){
		totalwt+=wt[i];
		totaltt+=tat[i];
	}
	printf("\nRR Average Waiting Time:%.2f Average TAT:%.2f\n",(float)totalwt/N,(float)totaltt/N);
}
void srtf(){
	int rt[N],ct[N],tat[N],wt[N];
	for(int i=0;i<N;i++) rt[i]=bt[i];
	int completed=0;
	int time=0;
	printf("\n|");
	while(completed<N){
		int min_i=-1;
		for(int i=0;i<N;i++){
			if(rt[i]>0 && at[i]<=time){
				if(min_i==-1){
					min_i=i;
				}else if(rt[min_i]>rt[i]){
					min_i=i;
				}
			}
		}
		if(min_i!=-1){
			if(rt[min_i]>1){
				rt[min_i]--;
			}else{
				rt[min_i]--;
				completed++;
				ct[min_i]=time+1;
				tat[min_i]=ct[min_i]-at[min_i];
				wt[min_i]=tat[min_i]-bt[min_i];
			}
			printf("P%i|",min_i+1);
			time++;
		}else{
			time++;
		}
	}
	int totalwt=0,totaltt=0;
	for(int i=0;i<N;i++){
		totalwt+=wt[i];
		totaltt+=tat[i];
	}
	printf("\nSRTF Average Waiting Time:%.2f Average TAT:%.2f\n",(float)totalwt/N,(float)totaltt/N);
}
int main(){
	//fcfs();
	// roundrobin();
	srtf();
	return 0;
}
