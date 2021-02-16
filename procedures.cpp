#include "procedures.h"

void my_scan(int & number){
    char buf[10];
    memset(buf,'\000',10);
    gets(buf);
    number=atoi(buf);
}
void menu1(){
    printf("Введите:\n");
    printf("*********************************************\n");
    printf("#| 1.для заполнения матрицы смежности      |#\n");
    printf("#| 2.для заполнения матрицы инцендентности |#\n");
    printf("#| 3.для заполнения списка смежности       |#\n");
    printf("*********************************************\n");
}
void menu2(){
    printf("Введите:\n");
    printf("*****************************************\n");
    printf("#| 1.для вывода матрицы смежности      |#\n");
    printf("#| 2.для вывода матрицы инцендентности |#\n");
    printf("#| 3.для вывода списка смежности       |#\n");
    printf("#| 4.для того чтобы продолжить         |#\n");
    printf("*****************************************\n");
}

void inp_matr_sm(int* & Point,const int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {  
            do{
                side:
                printf("x%d-",i+1); 
                printf("x%d : ",j+1);
                my_scan(Point[i*size+j]);
                if(i!=j && Point[i*size+j]==2)
                    goto side;
            }while (Point[i*size+j]<0 || Point[i*size+j]>2);
        }
        printf("\n");
    } 
}
int numunnull (int* Point,const int size,const int index){
    int num_of_el;
        for (size_t j = 0; j < size; j++)
            if(Point[index*size+j]!=0)
                num_of_el++;
    return num_of_el;
}

void matinlist ( int* & Point,const int size,std::list<int>* & Point2){
    for(size_t i=0;i<size;i++){
        for (size_t j = 0; j < size; j++)
        {
            if ( Point[i*size+j]!=0){
                Point2[i].push_back(j+1);
            }
        }
    }
}

void sholist (int size,std::list <int>* & Point ){
    for (size_t i = 0; i < size; i++)
    {   
        std::cout << i+1 << "-";
        for (auto iter = Point[i].begin(); iter != Point[i].end(); iter++)
        {
            std::cout << *iter << ",";
        }
        std::cout << std::endl;
    }
}

void listinmat(int* & Point,const int size,std::list<int>* & Point2){
    for (size_t i = 0; i < size; i++)
    {   
    
        for (auto iter = Point2[i].begin(); iter != Point2[i].end(); iter++)
        {
            if(i==*iter)
                Point[i*size+(*iter)-1] = 2;
            else
                Point[i*size+(*iter)-1] = 1;
        }
    }
}

void out_matr_smej(int* &Point,const int size){
    for (size_t i = 0;i < size;i++)
        printf("\tx%d",i+1);
    printf("\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("x%d",i+1);
        for (size_t j = 0; j <size; j++)
        {
            printf("\t%d",Point[i*size+j]);
        }
        printf("\n");
    }
}

void inp_inc(int* & Point,const int size,const int reb){
    Point=(int*)malloc(size*reb*4);
    for (size_t i = 0; i < reb; i++)
    {
        for (size_t j = 0; j < size; j++)
        {   
            do{
            printf("l%d-x%d-",i+1,j+1);
            my_scan(Point[i*size+j]);
            }while(Point[i*size+j]<-1  || Point[i*size+j]>1);
        }
    }
}

void incinlist (int* & Point,const int size,const int reb, std::list<int>* & Point2){
    for(size_t i=0;i<reb;i++)
    {   
        int nr,sopr;
        for(size_t j=0;j<size;j++){
            if (Point[i*size+j]==-1)
                nr=j;
            else if (Point[i*size+j]==1)
                sopr=j;
            else if (Point[i*size+j]==2)
            {
                sopr=j;
                nr=j;
            }
        }
        Point2[nr].push_back(sopr+1);
    }
}


void inp_list (const int size,std:: list<int>* & Point){
    for (size_t i = 0; i < size; i++)
    {   
        int col=0;
        printf("введите количество вершин смежных с %d-й:",i+1);
        my_scan(col);
        printf("Введите вершины смежные с %d-й\n",i+1);
        for (size_t j = 0; j < col; j++)
        {   
            int f=0;
            my_scan(f);
            Point[i].push_back(f);
        }  
    }
    
}

void listininc (int* & Point, const int size, std:: list <int>* & Point1){
    int l=0;
    for (size_t i = 0; i < size; i++)
    {
        for( auto iter=Point1[i].begin();iter!=Point1[i].end();iter++ )
        {   
            if(i+1==*iter)
                Point[l*size+i]=2;
            else
            {
                Point[l*size+i]=-1;
                Point[l*size+(*iter)-1]=1;
            }
            l++;
        }
    }
    
}

int numofreb(const int size, std::list<int>* & Point1){
    int numb;
    for (size_t i = 0; i < size; i++)
    {
        for( auto iter=Point1[i].begin();iter!=Point1[i].end();iter++ )
        {   
          numb++;  
        }
    }
    return numb;
}

void out_inc(int* & Point,const int size,const int reb){
    for (size_t i = 0; i < size; i++)
        printf("\tx%d",i+1);
    printf("\n");
    for (size_t i = 0; i < reb; i++)
    {   
        printf("l%d",i+1);
        for (size_t j = 0; j < size; j++)
        {
            printf("\t%d",Point[i*size+j]);
        }
        printf("\n");
    }
}