#include "procedures.cpp"


int main(int argc, char const *argv[]){
    int b,size,reb;
    int *matr;
    std::list<int> *spsm;
    max:
        menu1();
        my_scan(b);
        do
        {
            switch (b)
            {
            case 1:
                printf("Выбрано заполнение матрицы смежности\n");
                printf("введите количество вершин\n");
                my_scan(size);
                matr=new int[size*size];
                inp_matr_sm(matr,size);
                spsm = new std::list<int>[size];
                matinlist(matr,size,spsm);
                delete[] matr;
                break;
            case 2:
                printf("Выбрано заполнение матрицы инцендентности\n");
                printf("введите количество вершин\n");
                my_scan(size);
                printf("введите количество рёбер\n");
                my_scan(reb);

                spsm = new std::list<int>[size];
                matr=new int[size*reb];
                inp_inc(matr,size,reb);
                incinlist(matr,size,reb,spsm);
                delete[] matr;
                sholist(size,spsm);
                break;
            case 3:
                printf("Выбрано заполнение списка смежности\n");
                printf("Введите количество вершин\n");
                my_scan(size);
                spsm = new std::list<int>[size];
                inp_list(size,spsm);
                sholist(size,spsm);
                break;
            default:
                break;
            }
        }while(b<1||b>3);
        
        do 
        {
        printf("введите:\n");
        printf("1.для вывода графа\n");
        printf("2.для освобождения памяти и редактирования данных\n");
        my_scan(b);
        }while(b<1 || b>2);
        if (b==2)
        {
            for (size_t i = 0; i < size; i++)
            {
                spsm[i].clear();
            }
            delete[] spsm;
            goto max;
        }
        else
        {
            while (b!=3)
            {
              
                menu2();
                my_scan(b);
                switch (b)
                {
                case 1:
                    matr=new int[size*size]{};
                    listinmat(matr,size,spsm);
                    out_matr_smej(matr,size);
                    delete[] matr;
                    break;
                case 2:
                    reb=numofreb(size,spsm);
                    matr=new int[size*reb]{};
                    listininc(matr,size,spsm);
                    out_inc(matr,size,reb);
                    delete[] matr;
                    break;
                case 3: 
                    sholist(size,spsm);
        
                default:
                    break;
                }
            }
        }
    do 
    {   
        printf("введите:\n");
        printf("1.для нового ввода графа\n");
        printf("2.для освобождения памяти и завершения программы\n");
        my_scan(b);
    }while(b<1 || b>2);
    for (size_t i = 0; i < size; i++)
    {
        spsm[i].clear();
    }
    delete[] spsm;
    if (b==1)
        goto max;


    return 0;
}
