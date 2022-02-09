// DiskrLog.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Number.h"



int main(int argc,char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();    	
    //Number a((char*)"0011");
    //(a >> 5).V();
    
}