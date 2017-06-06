#ifndef _derandomized_h
#define _derandomized_h

#include <fstream>  
#include <iostream>  
#include <stdlib.h>  
#include <ctime>
#include "permutation.h"
#include "color_choice.h"
#include "update.h"

#define NUM 140
#define CLIQUE_MAX 479050
#define PERMUTATION 15329615

	struct clique_4{
		int white; //�ض�K4�б�ȾΪ��ɫ�ı���
		int black;//�ض�K4�б�ȾΪ��ɫ�ı���
		int expt;//�ض�K4�����б�ͬɫ�ĸ��ʣ���ʼֵΪ1���������Ϊ1/32
	};

#endif