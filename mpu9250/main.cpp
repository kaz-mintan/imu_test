#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "MPU9250.h"

int main(){
	MPU9250 mog_mpu;
	printf("hello\n");
	mog_mpu.initialize();

	bool ref;

	ref=mog_mpu.testConnection();

	std::cout<<ref<<std::endl;


	float ax,ay,az;
	float gx,gy,gz;

	//void MPU9250::getMotion9(float *ax, float *ay, float *az, float *gx, float *gy, float *gz, float *mx, float *my, float *mz)
	while(1){
		mog_mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
		printf("hoge,%f\t%f\t%f,",ax,ay,az);
		printf("hoge,%f\t%f\t%f\n",gx,gy,gz);
	}
}
