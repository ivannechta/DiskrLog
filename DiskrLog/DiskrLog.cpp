// DiskrLog.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Number.h"
#include "DiscrLog.h"



int main(int argc,char * argv[])
{
    //::testing::InitGoogleTest(&argc, argv);  RUN_ALL_TESTS();    	
    DiscrLog d(Number((char*)"100011"),Number((char*)"1010"));
    d.Divide();
    printf("Otvet=%d",d.GetPower());

    
}