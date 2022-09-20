#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
float cpkb=1.5,cpkc=9.5,cost_bus,cost_cab, avgspd_bus=30, avgspd_cab=60;
int i,j,a,b,u,v,n=10,cost[100][100],source, destination, primsPlaces[100], primsPlacesNumber, primsCost[100][100],minimum_dist;
char states[100]="Goa Karnataka Kerala Tamil_Nadu Andra_Pradesh Telangana", yourState[100], places[100][100];
char goaPlaces[100][100]={"","Baga beach", "Aguada fort", "Basillica of bom jesus", "Cruise", "Dona paula view point", "Mangeshi temple", "Colva beach", "Sunset point" ,"Salaulim dam", "Dudhsagar falls"};
char karPlaces[100][100]={"","Coorg","Mysore","Chikmagaluru","Hampi","Gokarna","Murudeshwar","Bangalore","Badami","Bandipur National Park","Aihole"};
char kerPlaces[100][100]={"","Munnar","Alleppey","Kochi","Periyar National Park","Varkala","Wayanad","Idduki","Sabarimala","Thrissur","Thiruvananthapuram"};
char tamPlaces[100][100]={"","Rameshwaram","Kodaikanal","Ooty","Chennai","Mahabalipuram","Kanyakumari","Kanchipuram","Madurai","Coimbatore","Dhanushkodi"};
char andPlaces[100][100]={"","Vizag","Araku Valley","Borra Caves","Papikondalu","Vizayawada","Amaravati","Lepakshi","Horsley Hills","Tirupati","Srisailam"};
char telPlaces[100][100]={"","Golkonda Fort","Charminar","Vikarabad","Ananthagiri hills","Ramappa Temple","Nagarjuna Sagar","Warangal","Bhadrachalam","Ramoji Film City","Nizamabad"};
int goaDist[100][100]={{0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,10,25,999,999,999,999,999,999,999},
                       {0,10,0,24,999,999,999,999,999,999,999},
                       {0,25,24,0,12,999,11,999,999,999,999},
                       {0,999,999,12,0,6,23,999,999,999,999},
                       {0,999,999,999,6,0,999,33,999,999,999},
                       {0,999,999,11,23,999,0,30,999,52,51},
                       {0,999,999,999,999,33,30,0,50,34,999},
                       {0,999,999,999,999,999,999,50,0,53,999},
                       {0,999,999,999,999,999,52,34,53,0,42},
                       {0,999,999,999,999,999,51,999,999,42,0}};
int karDist[100][100]={{0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,118,145,999,999,999,999,999,999,999},
                       {0,118,0,999,423,999,999,143,999,73,999},
                       {0,145,999,0,999,999,307,243,342,999,999},
                       {0,999,423,999,0,341,999,999,999,999,139},
                       {0,999,999,999,341,0,78,999,313,999,999},
                       {0,999,999,307,999,78,0,999,313,999,999},
                       {0,999,143,243,999,999,999,0,999,999,999},
                       {0,999,999,342,999,313,999,999,0,999,34},
                       {0,999,73,999,999,999,999,999,999,0,999},
                       {0,999,999,999,139,999,999,999,34,999,0}};
int kerDist[100][100]={{0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,999,127,999,999,345,63,999,999,999},
                       {0,999,0,53,999,108,999,999,999,999,999},
                       {0,127,53,0,999,999,999,999,999,84,999},
                       {0,999,999,999,0,999,999,84,93,999,999},
                       {0,999,108,999,999,0,999,999,999,999,43},
                       {0,345,999,999,999,999,0,999,999,194,999},
                       {0,63,999,999,84,999,999,0,999,999,999},
                       {0,999,999,999,93,999,999,999,0,999,999},
                       {0,999,999,84,999,999,194,999,999,0,999},
                       {0,999,999,999,999,43,999,999,999,999,0}};
int tamDist[100][100]={{0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,999,999,999,999,300,999,173,999,19},
                       {0,999,0,999,999,999,999,999,115,172,999},
                       {0,999,999,0,999,999,999,501,999,86,999},
                       {0,999,999,999,0,57,999,999,999,999,999},
                       {0,999,999,999,57,0,999,69,418,999,999},
                       {0,300,999,999,999,999,0,999,245,999,999},
                       {0,999,999,501,999,69,999,0,999,999,999},
                       {0,173,115,999,999,418,245,999,0,999,999},
                       {0,999,172,86,999,999,999,999,999,0,999},
                       {0,19,999,999,999,999,999,999,999,999,0}};
int andDist[100][100]={{0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,999,90,217,999,999,999,999,999,999},
                       {0,999,0,37,999,999,999,999,999,999,999},
                       {0,90,37,0,999,999,999,999,999,999,999},
                       {0,217,999,999,0,181,999,999,999,999,999},
                       {0,999,999,999,181,0,19,999,999,415,265},
                       {0,999,999,999,999,19,0,999,999,999,999},
                       {0,999,999,999,999,999,999,0,115,999,443},
                       {0,999,999,999,999,999,999,115,0,128,999},
                       {0,999,999,999,999,415,999,999,128,0,999},
                       {0,999,999,999,999,265,999,443,999,999,0}};
int telDist[100][100]={{0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,13,35,999,999,999,999,999,999,999},
                       {0,13,0,999,999,999,999,999,999,35,178},
                       {0,35,999,0,7,999,999,999,999,999,999},
                       {0,999,999,7,0,999,999,999,999,999,999},
                       {0,999,999,999,999,0,999,67,166,999,999},
                       {0,999,999,999,999,999,0,999,322,125,999},
                       {0,999,999,999,999,67,999,0,185,151,999},
                       {0,999,999,999,999,166,999,185,0,999,999},
                       {0,999,35,999,999,999,125,151,999,0,999},
                       {0,999,178,999,999,999,999,999,999,999,0}};

int min(int a, int b)
{
    return (a<b)?a:b;
}
int search(char* pat, char* txt)
{
    int Flag=0;
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
        {
            printf("You have chosen the state, %s ", pat);
            ++Flag;
        }
    }
    return Flag;
}
int floyd(int cost[100][100], int n, int s, int d)
{
    int i, j, k, mindist=0;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                {
                 cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(i==s&&j==d)
        {
         mindist=cost[s][d];
         printf("\n\nThe minimum distance traveled from %s to %s is %d kms\n",places[s],places[d],mindist);
        }
    }
    return mindist;
}
int prims(int mat[100][100],int place[100],int n)
{
    int i, j, a, u, b, v, visited[100], ne=1, min, mindist=0;
    for(i=2;i<=n;i++)
    visited[i]=0;
    visited[1]=1;
    printf("\nThe shortest path to travel is:\n");
    printf("------------------------------------\n");
    while(ne<n)
        {
            for (i=1,min=999;i<=n;i++)
                {
                    for (j=1;j<=n;j++)
                        {
                            if(mat[i][j]<min)
                                {
                                    if(visited[i]==1)
                                        {
                                            min=mat[i][j];
                                            a=u=i;
                                            b=v=j;
                                        }
                                }
                        }
                }
            if(visited[u]==0||visited[v]==0)
                {
                    printf("%d] %s -> %s = %d kms\n",ne++,places[place[a]],places[place[b]],min);
                    mindist+=min;
                    visited[b]=1;
                }
            mat[a][b]=mat[b][a]=999;
        }
    printf("\n\nThe minimum distance to travel all the places is %d kms\n",mindist);
    return mindist;
}
void calc_time(int mindist, float sbus, float scab)
    {
        float etab, etac;
        int hourb, minb, secb, hourc, minc, secc, sb, sc;
        etab = mindist/sbus;
        etac = mindist/scab;
        sb=etab*3600;
        hourb=(sb/3600);
        minb=(sb-(3600*hourb))/60;
        secb=(sb-(3600*hourb)-(minb*60));
        sc=etac*3600;
        hourc=(sc/3600);
        minc=(sc-(3600*hourc))/60;
        secc=(sc-(3600*hourc)-(minc*60));
        printf("\nEstimated Time of Arrival for Bus : %dhrs %dmin %dsec",hourb,minb,secb);
        printf("\nEstimated Time of Arrival for Cab : %dhrs %dmin %dsec",hourc,minc,secc);
        printf("\nThank you for using RSSS travels\n");
        printf("\n**********************************************************************\n\n");
    }
int main()
{
    int des;
    char choice;
    printf("Welcome to RSSS travels\n");
    printf("Enter any Southern India state\n");
    scanf("%s",yourState);
    des = search(yourState,states);
    if(des==0)
    {
	printf("ERROR: Enter correct state please");
	exit(0);
    }
    printf("\nSome famous places in %s :\n",yourState);
    if(strcmp(yourState,"Goa")==0)
    {
	for(i=1;i<=n;i++)
	{
	    strcpy(places[i],goaPlaces[i]);
	    printf("%d) %s\n",i,places[i]);
	}
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
		cost[i][j]=goaDist[i][j];
    }}}
    else if(strcmp(yourState,"Karnataka")==0)
    {
	for(i=1;i<=n;i++)
	{
	    strcpy(places[i],karPlaces[i]);
	    printf("%d) %s\n",i,places[i]);
	}
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
		cost[i][j]=karDist[i][j];
    }}}
    else if(strcmp(yourState,"Kerala")==0)
    {
	for(i=1;i<=n;i++)
	{
	    strcpy(places[i],kerPlaces[i]);
	    printf("%d) %s\n",i,places[i]);
	}
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
		cost[i][j]=kerDist[i][j];
    }}}
    else if(strcmp(yourState,"Tamil_Nadu")==0)
    {
	for(i=1;i<=n;i++)
	{
	    strcpy(places[i],tamPlaces[i]);
	    printf("%d) %s\n",i,places[i]);
	}
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
		cost[i][j]=tamDist[i][j];
    }}}
    else if(strcmp(yourState,"Andra_Pradesh")==0)
    {
	for(i=1;i<=n;i++)
	{
	    strcpy(places[i],andPlaces[i]);
	    printf("%d) %s\n",i,places[i]);
	}
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
		cost[i][j]=andDist[i][j];
    }}}
    else if(strcmp(yourState,"Telangana")==0)
    {
	for(i=1;i<=n;i++)
	{
	    strcpy(places[i],telPlaces[i]);
	    printf("%d) %s\n",i,places[i]);
	}
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
		cost[i][j]=telDist[i][j];
    }}}
    else
    {
	printf("ERROR : Enter the full state with spaces to be typed as '_'\n");
	exit(0);
    }
    printf("Enter your choice\na] To travel between two places\nb] To travel all places\n");
    scanf("%s",&choice);
    switch(choice)
    {
	case 'a':printf("\nEnter your source:\n");
		 scanf("%d",&source);
		 if(source>n||source==0){
		     if(source==0){
			 printf("ERROR: There is no zeroth place...\n");
			 exit(0);
		     }
		     printf("ERROR: You can't have %dth place as your source, there are only %d places in our tour\n",source,n);
		     exit(0);
		 }
		 printf("%s is the source\n",places[source]);
		 printf("Enter the destination:\n");
		 scanf("%d",&destination);
		 if(destination>n||destination==0){
		     if(destination==0){
			 printf("ERROR: There is no zeroth place...\n");
			 exit(0);
		     }
		     printf("ERROR: You can't have %dth place as your destination, there are only %d places in our tour\n",destination,n);
		     exit(0);
		 }
		 printf("%s is the destination\n",places[destination]);
		 if(source==destination){
		     printf("ERROR: Can't have the same place as the source and the destination\n");
		     exit(0);
		 }
		 minimum_dist=floyd(cost,n,source,destination);
		 cost_bus=minimum_dist*cpkb;
		 cost_cab=minimum_dist*cpkc;
		 printf("\nThe minimum cost to travel from %s to %s by bus is Rs. %f\n",places[source],places[destination],cost_bus);
		 printf("The minimum cost to travel from %s to %s by cab is Rs. %f\n",places[source],places[destination],cost_cab);
		 calc_time(minimum_dist,avgspd_bus,avgspd_cab);
		 break;
	case 'b':printf("\nEnter the number of places you want to travel\n");
		 scanf("%d",&primsPlacesNumber);
		 if(primsPlacesNumber>n||primsPlacesNumber==0||primsPlacesNumber==1){
		    if(primsPlacesNumber==0){
			printf("ERROR: Are you serious? How can you travel 0 places?\n");
			exit(0);
            }
            if(primsPlacesNumber==1){
                printf("ERROR: You can't travel from just one place\n");
                exit(0);
            }
		    printf("ERROR: Can't travel %d places, there are only %d places in our tour.\n",primsPlacesNumber,n);
		    exit(0);
		 }
		 printf("\nEnter the places you want to travel :\n");
		 for(i=1;i<=primsPlacesNumber;i++)
		 {
		    scanf("%d",&primsPlaces[i]);
		    if(i<primsPlacesNumber){
                if(i==1){
                    printf("You have choosen %s\nThis will be your source\nEnter the next place please : ",places[primsPlaces[i]]);
                }
                else
                printf("You have choosen %s\nEnter next place please :  ",places[primsPlaces[i]]);
            }

		    else printf("You have choosen %s\n",places[primsPlaces[i]]);
		 }
		 for(i=1;i<=primsPlacesNumber;i++){
		    for(j=1;j<=primsPlacesNumber;j++){
			if(i==j){
			    primsCost[i][j]=0;
			}
			else if(i>j){
			    primsCost[i][j]=primsCost[j][i];
			}
			else if(i<j){
			    primsCost[i][j]=cost[primsPlaces[i]][primsPlaces[j]];
			}
		    }
		 }
		 minimum_dist=prims(primsCost,primsPlaces,primsPlacesNumber);
		 cost_bus=minimum_dist*cpkb;
		 cost_cab=minimum_dist*cpkc;
		 printf("The minimum cost to travel by bus is Rs. %f\n",cost_bus);
		 printf("The minimum cost to travel by cab is Rs. %f\n",cost_cab);
		 calc_time(minimum_dist,avgspd_bus,avgspd_cab);
		 break;
	default : printf("ERROR: Enter correct choice please\n");
		  exit(0);
    }
    return 0;
}
