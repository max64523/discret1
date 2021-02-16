#pragma once
#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<cstring>
#include<cstdio>
#include <list>
#include <Windows.h>
void menu1();
void menu2();
void my_scan(int & number);
void inp_matr_sm(int* & Point,const int size);
int numunnull (int* Point,const int size, const int  index);
void matinlist ( int* & Point,const int size,std::list<int>* & Point2);
void sholist (int size,std::list <int>* & Point );
void listinmat(int* & Point,const int size,std::list<int>* & Point2);
void out_matr_smej(int* &Point,const int size);
void inp_inc(int* & Point,const int size,const int reb);
void incinlist (int* & Point,const int size,const int reb, std::list<int>* & Point2);
void listininc (int* & Point, const int size, std:: list <int>* & Point1);
int numofreb(const int size, std::list<int>* & Point1);
void out_inc(int* & Point,const int size,const int reb);
void inp_list (const int size,std:: list<int>* & Point);