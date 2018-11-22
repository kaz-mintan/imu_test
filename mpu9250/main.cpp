#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "MPU9250.h"

//to get time
#include <time.h>
#include <sys/time.h>


int main(){
	MPU9250 mog_mpu;
	printf("hello\n");
	mog_mpu.initialize();

	bool ref;

	ref=mog_mpu.testConnection();

	std::cout<<ref<<std::endl;

	//args to get imu data
	float ax,ay,az;
	float gx,gy,gz;

	//args to get time
	struct timeval stTime, nowTime;
	time_t diffsec;
	suseconds_t diffsub;
	double realsec;

	gettimeofday(&stTime,NULL);

	//void MPU9250::getMotion9(float *ax, float *ay, float *az, float *gx, float *gy, float *gz, float *mx, float *my, float *mz)
	while(1){
		//get time calc dt
		gettimeofday(&nowTime,NULL);
		diffsec = difftime(nowTime.tv_sec, stTime.tv_sec);
		diffsub = nowTime.tv_usec - stTime.tv_usec;
		realsec = diffsec + diffsub*1e-6;

		mog_mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
		printf("%f,",realsec);
		printf("%f,%f,%f,",ax,ay,az);
		printf("%f,%f,%f\n",gx,gy,gz);
	}
}
